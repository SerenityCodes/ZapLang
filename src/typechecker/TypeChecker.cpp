#include "TypeChecker.h"
#include <variant>
#include "logger/Logger.h"

namespace typechecker {

bool TypeChecker::check(const ast::ZapProgram& program) {
    global_symbols_ = &program.class_symbol_table;
    bool success    = true;

    // Check all declarations
    for (const auto& decl : program.declarations) {
        if (!check_declaration(decl)) {
            success = false;
        }
    }

    return success;
}

bool TypeChecker::check_declaration(const ast::ZapDecl& decl) {
    switch (decl.kind) {
        case ast::ZapDeclKind::Function:
            return check_function(std::get<ast::ZapFunction>(decl.value));
        case ast::ZapDeclKind::Struct:
            return check_struct(std::get<ast::ZapStruct>(decl.value));
        case ast::ZapDeclKind::Component:
            return check_component(std::get<ast::ZapComponent>(decl.value));
        default:
            report_error("Unknown declaration kind");
            return false;
    }
}

bool TypeChecker::check_function(const ast::ZapFunction& func) {
    // Set function context for return type checking
    current_function_                                        = &func;

    // Create new scope for function parameters
    std::unordered_map<std::string, ast::ZapType> prev_scope = current_scope_;

    bool success                                             = true;

    // Validate and add parameters to scope
    for (const auto& param : func.params) {
        // Check if parameter type is valid
        ast::ZapType param_type = param.type;

        // Handle reference types by checking the inner type
        if (param_type.kind == ast::ZapTypeKind::REF && param_type.inner) {
            param_type = *param_type.inner;
        }

        // Validate custom types
        if (param_type.kind == ast::ZapTypeKind::CUSTOM) {
            ast::ZapType resolved_type;
            if (!resolve_custom_type(param_type.custom_name, resolved_type)) {
                report_error("Unknown type '" + param_type.custom_name +
                             "' in parameter '" + param.name +
                             "' of function '" + func.name + "'");
                success = false;
                continue;
            }
        }

        current_scope_[param.name] = param.type;
    }

    // Check all statements in function body
    for (const auto& stmt : func.body) {
        if (!check_statement(stmt)) {
            success = false;
        }
    }

    // Restore previous scope
    current_scope_    = prev_scope;
    current_function_ = nullptr;

    return success;
}

bool TypeChecker::check_struct(const ast::ZapStruct& struct_decl) {
    // For now, just validate that all field types are valid
    for (const auto& field : struct_decl.fields) {
        ast::ZapType resolved_type;
        if (field.type.kind == ast::ZapTypeKind::CUSTOM &&
            !resolve_custom_type(field.type.custom_name, resolved_type)) {
            report_error("Unknown type '" + field.type.custom_name +
                         "' in struct field '" + field.name + "'");
            return false;
        }
    }
    return true;
}

bool TypeChecker::check_component(const ast::ZapComponent& component) {
    // Similar to struct checking
    for (const auto& field : component.fields) {
        ast::ZapType resolved_type;
        if (field.type.kind == ast::ZapTypeKind::CUSTOM &&
            !resolve_custom_type(field.type.custom_name, resolved_type)) {
            report_error("Unknown type '" + field.type.custom_name +
                         "' in component field '" + field.name + "'");
            return false;
        }
    }
    return true;
}

bool TypeChecker::check_statement(const ast::ZapStatement& stmt) {
    switch (stmt.kind) {
        case ast::ZapStatementKind::Let:
            return check_let_statement(
                std::get<ast::ZapLetStatement>(stmt.value));
        case ast::ZapStatementKind::Assign:
            return check_assign_statement(
                std::get<ast::ZapAssignStatement>(stmt.value));
        case ast::ZapStatementKind::Expression:
            // Just infer the type to validate it
            infer_expression_type(
                *std::get<std::shared_ptr<ast::ZapExpression>>(stmt.value));
            return true;
        case ast::ZapStatementKind::If:
            return check_if_statement(
                std::get<ast::ZapIfStatement>(stmt.value));
        case ast::ZapStatementKind::While:
            return check_while_statement(
                std::get<ast::ZapWhileStatement>(stmt.value));
        case ast::ZapStatementKind::For:
            return check_for_statement(
                std::get<ast::ZapForStatement>(stmt.value));
        case ast::ZapStatementKind::Return:
            return check_return_statement(
                std::get<ast::ZapReturnStatement>(stmt.value));
        case ast::ZapStatementKind::Block:
            return check_block_statement(
                std::get<ast::ZapBlockStatement>(stmt.value));
        case ast::ZapStatementKind::Defer:
            return check_defer_statement(
                std::get<ast::ZapDeferStatement>(stmt.value));
        default:
            report_error("Unknown statement kind");
            return false;
    }
}

bool TypeChecker::check_let_statement(const ast::ZapLetStatement& stmt) {
    // Validate that custom types exist before proceeding
    if (stmt.type.kind == ast::ZapTypeKind::CUSTOM) {
        ast::ZapType resolved_type;
        if (!resolve_custom_type(stmt.type.custom_name, resolved_type)) {
            report_error("Unknown type '" + stmt.type.custom_name +
                         "' in variable declaration for '" + stmt.name + "'");
            return false;
        }
    }

    // Infer the type of the initializer expression
    ast::ZapType inferred_type = infer_expression_type(*stmt.value);

    // Add variable to current scope first (so it's available for subsequent references)
    current_scope_[stmt.name]  = stmt.type;

    // Check if the declared type matches the inferred type
    if (!types_compatible(stmt.type, inferred_type)) {
        report_type_mismatch("Variable declaration for '" + stmt.name + "'",
                             stmt.type, inferred_type);
        return false;
    }

    return true;
}

bool TypeChecker::check_assign_statement(const ast::ZapAssignStatement& stmt) {
    // Infer types of both sides
    ast::ZapType target_type = infer_expression_type(*stmt.target);
    ast::ZapType value_type  = infer_expression_type(*stmt.value);

    // Check compatibility
    if (!types_compatible(target_type, value_type)) {
        report_type_mismatch("Assignment", target_type, value_type);
        return false;
    }

    return true;
}

bool TypeChecker::check_if_statement(const ast::ZapIfStatement& stmt) {
    // Condition must be boolean
    ast::ZapType condition_type = infer_expression_type(*stmt.condition);
    ast::ZapType bool_type      = {ast::ZapTypeKind::BOOL, "", nullptr};

    if (!types_compatible(bool_type, condition_type)) {
        report_type_mismatch("If condition", bool_type, condition_type);
        return false;
    }

    // Check then and else blocks
    bool success = true;
    for (const auto& then_stmt : stmt.then_block) {
        if (!check_statement(then_stmt)) {
            success = false;
        }
    }

    for (const auto& else_stmt : stmt.else_block) {
        if (!check_statement(else_stmt)) {
            success = false;
        }
    }

    return success;
}

bool TypeChecker::check_while_statement(const ast::ZapWhileStatement& stmt) {
    // Condition must be boolean
    ast::ZapType condition_type = infer_expression_type(*stmt.condition);
    ast::ZapType bool_type      = {ast::ZapTypeKind::BOOL, "", nullptr};

    if (!types_compatible(bool_type, condition_type)) {
        report_type_mismatch("While condition", bool_type, condition_type);
        return false;
    }

    // Check body
    bool success = true;
    for (const auto& body_stmt : stmt.body) {
        if (!check_statement(body_stmt)) {
            success = false;
        }
    }

    return success;
}

bool TypeChecker::check_for_statement(const ast::ZapForStatement& stmt) {
    // Check the initialization statement
    bool success                = check_let_statement(stmt.start);

    // Condition must be boolean
    ast::ZapType condition_type = infer_expression_type(*stmt.condition);
    ast::ZapType bool_type      = {ast::ZapTypeKind::BOOL, "", nullptr};

    if (!types_compatible(bool_type, condition_type)) {
        report_type_mismatch("For loop condition", bool_type, condition_type);
        success = false;
    }

    // Check step expression (just need to infer its type)
    infer_expression_type(*stmt.step);

    // Check body
    for (const auto& body_stmt : stmt.body) {
        if (!check_statement(body_stmt)) {
            success = false;
        }
    }

    return success;
}

bool TypeChecker::check_return_statement(const ast::ZapReturnStatement& stmt) {
    if (!current_function_) {
        report_error("Return statement outside of function");
        return false;
    }

    // Check if return type matches function return type
    ast::ZapType return_type = infer_expression_type(*stmt.value);

    if (!types_compatible(current_function_->return_type, return_type)) {
        report_type_mismatch("Return statement", current_function_->return_type,
                             return_type);
        return false;
    }

    return true;
}

bool TypeChecker::check_block_statement(const ast::ZapBlockStatement& stmt) {
    bool success = true;
    for (const auto& block_stmt : stmt.statements) {
        if (!check_statement(block_stmt)) {
            success = false;
        }
    }
    return success;
}

bool TypeChecker::check_defer_statement(const ast::ZapDeferStatement& stmt) {
    if (stmt.is_body) {
        // Defer has a body of statements - check each statement
        bool success = true;
        for (const auto& defer_stmt : stmt.body) {
            if (!check_statement(defer_stmt)) {
                success = false;
            }
        }
        return success;
    } else {
        // Defer has an expression - validate the expression type
        if (stmt.expr) {
            infer_expression_type(*stmt.expr);
            return true;
        }
        return true;
    }
}

ast::ZapType TypeChecker::infer_expression_type(
    const ast::ZapExpression& expr) {
    switch (expr.kind) {
        case ast::ZapExpressionKind::Literal:
            return infer_literal_type(std::get<ast::ZapLiteral>(expr.value));
        case ast::ZapExpressionKind::Identifier: {
            const std::string& id = std::get<ast::ZapIdentifier>(expr.value);
            auto it               = current_scope_.find(id);
            if (it != current_scope_.end()) {
                return it->second;
            }
            report_error("Undefined variable '" + id + "'");
            return {ast::ZapTypeKind::VOID, "", nullptr};
        }
        case ast::ZapExpressionKind::Binary:
            return infer_binary_expression_type(
                std::get<ast::ZapBinaryExpression>(expr.value));
        case ast::ZapExpressionKind::Unary:
            return infer_unary_expression_type(
                std::get<ast::ZapUnaryExpression>(expr.value));
        case ast::ZapExpressionKind::Call:
            return infer_call_expression_type(
                std::get<ast::ZapCallExpression>(expr.value));
        case ast::ZapExpressionKind::StructAccess:
            return infer_struct_access_type(
                std::get<ast::ZapStructAccessExpression>(expr.value));
        case ast::ZapExpressionKind::StructInit:
            return infer_struct_init_type(
                std::get<ast::ZapStructInitExpression>(expr.value));
        default:
            report_error("Unknown expression kind");
            return {ast::ZapTypeKind::VOID, nullptr, nullptr};
    }
}

ast::ZapType TypeChecker::infer_literal_type(const ast::ZapLiteral& literal) {
    return std::visit(
        [](const auto& value) -> ast::ZapType {
            using T = std::decay_t<decltype(value)>;
            if constexpr (std::is_same_v<T, ast::LiteralInt>) {
                return {ast::ZapTypeKind::I32, "", nullptr};
            } else if constexpr (std::is_same_v<T, ast::LiteralFloat>) {
                return {ast::ZapTypeKind::F32, "", nullptr};
            } else if constexpr (std::is_same_v<T, ast::LiteralDouble>) {
                return {ast::ZapTypeKind::F64, "", nullptr};
            } else if constexpr (std::is_same_v<T, ast::LiteralString>) {
                return {ast::ZapTypeKind::STRING, "", nullptr};
            } else if constexpr (std::is_same_v<T, ast::LiteralBool>) {
                return {ast::ZapTypeKind::BOOL, "", nullptr};
            }
            return {ast::ZapTypeKind::VOID, "", nullptr};
        },
        literal.value);
}

ast::ZapType TypeChecker::infer_binary_expression_type(
    const ast::ZapBinaryExpression& expr) {
    ast::ZapType left_type  = infer_expression_type(*expr.left);
    ast::ZapType right_type = infer_expression_type(*expr.right);

    // For arithmetic operations
    if (expr.op == ast::BinaryOp::ADD || expr.op == ast::BinaryOp::SUBTRACT ||
        expr.op == ast::BinaryOp::MULTIPLY ||
        expr.op == ast::BinaryOp::DIVIDE || expr.op == ast::BinaryOp::MOD) {

        if (!is_numeric_type(left_type) || !is_numeric_type(right_type)) {
            report_error("Arithmetic operations require numeric types");
            return {ast::ZapTypeKind::VOID, "", nullptr};
        }

        // Return the "larger" type
        if (is_floating_type(left_type) || is_floating_type(right_type)) {
            return left_type.kind == ast::ZapTypeKind::F64 ||
                           right_type.kind == ast::ZapTypeKind::F64
                       ? ast::ZapType{ast::ZapTypeKind::F64, "", nullptr}
                       : ast::ZapType{ast::ZapTypeKind::F32, "", nullptr};
        }

        // Both are integers, return the larger one
        return left_type;
    }

    // For comparison operations
    if (expr.op == ast::BinaryOp::EQUAL ||
        expr.op == ast::BinaryOp::NOT_EQUAL ||
        expr.op == ast::BinaryOp::LESS_THAN ||
        expr.op == ast::BinaryOp::LESS_THAN_OR_EQUAL ||
        expr.op == ast::BinaryOp::GREATER_THAN ||
        expr.op == ast::BinaryOp::GREATER_THAN_OR_EQUAL) {

        if (!types_compatible(left_type, right_type)) {
            report_error("Comparison operations require compatible types");
        }

        return {ast::ZapTypeKind::BOOL, "", nullptr};
    }

    // For logical operations
    if (expr.op == ast::BinaryOp::AND || expr.op == ast::BinaryOp::OR) {
        ast::ZapType bool_type = {ast::ZapTypeKind::BOOL, "", nullptr};

        if (!types_compatible(bool_type, left_type) ||
            !types_compatible(bool_type, right_type)) {
            report_error("Logical operations require boolean types");
        }

        return bool_type;
    }

    report_error("Unknown binary operation");
    return {ast::ZapTypeKind::VOID, "", nullptr};
}

ast::ZapType TypeChecker::infer_unary_expression_type(
    const ast::ZapUnaryExpression& expr) {
    ast::ZapType operand_type = infer_expression_type(*expr.unary);

    if (expr.op == ast::BinaryOp::NOT) {
        ast::ZapType bool_type = {ast::ZapTypeKind::BOOL, "", nullptr};
        if (!types_compatible(bool_type, operand_type)) {
            report_error("Logical NOT requires boolean type");
        }
        return bool_type;
    } else if (expr.op == ast::BinaryOp::NEGATIVE) {
        if (!is_numeric_type(operand_type)) {
            report_error("Numeric negation requires numeric type");
        }
        return operand_type;
    }

    report_error("Unknown unary operation");
    return {ast::ZapTypeKind::VOID, "", nullptr};
}

ast::ZapType TypeChecker::infer_call_expression_type(
    const ast::ZapCallExpression& expr) {
    // For now, handle built-in functions like print
    if (expr.function == "print") {
        // Print can accept any type, returns void
        return {ast::ZapTypeKind::VOID, "", nullptr};
    }

    // TODO: Look up user-defined functions
    report_error("Unknown function '" + expr.function + "'");
    return {ast::ZapTypeKind::VOID, "", nullptr};
}

ast::ZapType TypeChecker::infer_struct_access_type(
    const ast::ZapStructAccessExpression& expr) {
    // First, get the type of the variable being accessed
    auto var_it = current_scope_.find(expr.type);
    if (var_it == current_scope_.end()) {
        report_error("Undefined variable '" + expr.type + "' in struct access");
        return {ast::ZapTypeKind::VOID, "", nullptr};
    }

    ast::ZapType var_type = var_it->second;

    // Handle reference types by unwrapping them
    if (var_type.kind == ast::ZapTypeKind::REF && var_type.inner) {
        var_type = *var_type.inner;
    }

    // The variable must have a custom type (struct or component)
    if (var_type.kind != ast::ZapTypeKind::CUSTOM) {
        report_error("Variable '" + expr.type +
                     "' is not a struct or component type");
        return {ast::ZapTypeKind::VOID, "", nullptr};
    }

    // Look up the field in the struct/component definition
    auto struct_it = global_symbols_->struct_map.find(var_type.custom_name);
    if (struct_it != global_symbols_->struct_map.end()) {
        const auto& struct_def = struct_it->second;
        for (const auto& field : struct_def.fields) {
            if (field.name == expr.field) {
                return field.type;
            }
        }
        report_error("Field '" + expr.field + "' not found in struct '" +
                     var_type.custom_name + "'");
        return {ast::ZapTypeKind::VOID, "", nullptr};
    }

    // Check if it's a component
    auto comp_it = global_symbols_->component_map.find(var_type.custom_name);
    if (comp_it != global_symbols_->component_map.end()) {
        const auto& comp_def = comp_it->second;
        for (const auto& field : comp_def.fields) {
            if (field.name == expr.field) {
                return field.type;
            }
        }
        report_error("Field '" + expr.field + "' not found in component '" +
                     var_type.custom_name + "'");
        return {ast::ZapTypeKind::VOID, "", nullptr};
    }

    report_error("Unknown custom type '" + var_type.custom_name +
                 "' in struct access");
    return {ast::ZapTypeKind::VOID, "", nullptr};
}

ast::ZapType TypeChecker::infer_struct_init_type(
    const ast::ZapStructInitExpression& expr) {
    // Return the struct type
    return {ast::ZapTypeKind::CUSTOM, expr.type_name, nullptr};
}

bool TypeChecker::types_compatible(const ast::ZapType& expected,
                                   const ast::ZapType& actual) {
    if (expected.kind == actual.kind) {
        if (expected.kind == ast::ZapTypeKind::CUSTOM) {
            return expected.custom_name == actual.custom_name;
        }
        return true;
    }

    // Allow integer literals to be compatible with any integer type
    if (is_integer_type(expected) && actual.kind == ast::ZapTypeKind::I32) {
        return true;
    }

    // Allow floating literals to be compatible with any floating type
    if (is_floating_type(expected) && (actual.kind == ast::ZapTypeKind::F32 ||
                                       actual.kind == ast::ZapTypeKind::F64)) {
        return true;
    }

    return false;
}

bool TypeChecker::is_numeric_type(const ast::ZapType& type) {
    return is_integer_type(type) || is_floating_type(type);
}

bool TypeChecker::is_integer_type(const ast::ZapType& type) {
    return type.kind == ast::ZapTypeKind::U8 ||
           type.kind == ast::ZapTypeKind::U16 ||
           type.kind == ast::ZapTypeKind::U32 ||
           type.kind == ast::ZapTypeKind::U64 ||
           type.kind == ast::ZapTypeKind::I16 ||
           type.kind == ast::ZapTypeKind::I32 ||
           type.kind == ast::ZapTypeKind::I64;
}

bool TypeChecker::is_floating_type(const ast::ZapType& type) {
    return type.kind == ast::ZapTypeKind::F32 ||
           type.kind == ast::ZapTypeKind::F64;
}

bool TypeChecker::resolve_custom_type(const std::string& type_name,
                                      ast::ZapType& resolved_type) {
    // Check if it's a struct
    auto struct_it = global_symbols_->struct_map.find(type_name);
    if (struct_it != global_symbols_->struct_map.end()) {
        resolved_type = {ast::ZapTypeKind::CUSTOM, type_name, nullptr};
        return true;
    }

    // Check if it's a component
    auto comp_it = global_symbols_->component_map.find(type_name);
    if (comp_it != global_symbols_->component_map.end()) {
        resolved_type = {ast::ZapTypeKind::CUSTOM, type_name, nullptr};
        return true;
    }

    return false;
}

std::string TypeChecker::type_to_string(const ast::ZapType& type) {
    switch (type.kind) {
        case ast::ZapTypeKind::U8:
            return "u8";
        case ast::ZapTypeKind::U16:
            return "u16";
        case ast::ZapTypeKind::U32:
            return "u32";
        case ast::ZapTypeKind::U64:
            return "u64";
        case ast::ZapTypeKind::I16:
            return "i16";
        case ast::ZapTypeKind::I32:
            return "i32";
        case ast::ZapTypeKind::I64:
            return "i64";
        case ast::ZapTypeKind::F32:
            return "f32";
        case ast::ZapTypeKind::F64:
            return "f64";
        case ast::ZapTypeKind::BOOL:
            return "bool";
        case ast::ZapTypeKind::STRING:
            return "str";
        case ast::ZapTypeKind::VOID:
            return "void";
        case ast::ZapTypeKind::CUSTOM:
            return type.custom_name;
        case ast::ZapTypeKind::ARRAY:
            return type.inner ? type_to_string(*type.inner) + "[]"
                              : "unknown[]";
        case ast::ZapTypeKind::REF:
            return "ref " +
                   (type.inner ? type_to_string(*type.inner) : "unknown");
        default:
            return "unknown";
    }
}

void TypeChecker::report_error(const std::string& message) {
    ZAP_LOG_ERROR("Type error: {}", message);
}

void TypeChecker::report_type_mismatch(const std::string& context,
                                       const ast::ZapType& expected,
                                       const ast::ZapType& actual) {
    ZAP_LOG_ERROR("Type mismatch in {}: expected '{}', got '{}'", context,
                  type_to_string(expected), type_to_string(actual));
}

}  // namespace typechecker
