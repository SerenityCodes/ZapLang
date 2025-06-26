#include "ir.h"
#include <string>
#include <vector>
#include "ast/ast.h"
#include <iostream>
#include <iomanip>

namespace ir {

IRProgram IRVisitor::generate(const ast::ZapProgram& ast_program) {
    IRProgram program;
    for (const ast::ZapDecl& decl : ast_program.declarations) {
        switch (decl.kind) {
            case ast::ZapDeclKind::Function:
                program.functions.push_back(
                    generate(std::get<ast::ZapFunction>(decl.value)));
                break;
            case ast::ZapDeclKind::Struct:
                program.structs.push_back(
                    generate(std::get<ast::ZapStruct>(decl.value)));
                break;
            case ast::ZapDeclKind::Component:
                program.structs.push_back(
                    generate(std::get<ast::ZapComponent>(decl.value)));
                break;
        }
    }
    return program;
}

IRFunction IRVisitor::generate(const ast::ZapFunction& func) {
    IRFunction function;
    function.name        = func.name;
    function.args        = func.params;
    function.return_type = func.return_type;
    for (const ast::ZapStatement& statement : func.body) {
        std::vector<IRBlock> blocks;
        generate(statement, blocks);
        function.blocks.insert(function.blocks.end(), blocks.begin(),
                               blocks.end());
    }
    return function;
}

IRStruct IRVisitor::generate(const ast::ZapComponent& comp) {
    return IRStruct{
        .name = comp.name, .fields = comp.fields, .is_component = true};
}

IRStruct IRVisitor::generate(const ast::ZapStruct& strct) {
    return IRStruct{
        .name = strct.name, .fields = strct.fields, .is_component = false};
}

void IRVisitor::generate(const ast::ZapStatement& statement,
                         std::vector<IRBlock>& blocks) {
    if (blocks.empty()) {
        blocks.push_back(IRBlock{.name = "entry", .statements = {}});
    }
    switch (statement.kind) {
        case ast::ZapStatementKind::If:
            generate(std::get<ast::ZapIfStatement>(statement.value), blocks);
            break;
        case ast::ZapStatementKind::Let:
            generate(std::get<ast::ZapLetStatement>(statement.value),
                     blocks.back().statements);
            break;
        case ast::ZapStatementKind::Assign:
            generate(std::get<ast::ZapAssignStatement>(statement.value),
                     blocks.back().statements);
            break;
        case ast::ZapStatementKind::Expression:
            generate(*std::get<std::shared_ptr<ast::ZapExpression>>(
                         statement.value),
                     blocks.back().statements);
            break;
        case ast::ZapStatementKind::For:
            generate(std::get<ast::ZapForStatement>(statement.value), blocks);
            break;
        case ast::ZapStatementKind::While:
            generate(std::get<ast::ZapWhileStatement>(statement.value), blocks);
            break;
        case ast::ZapStatementKind::Return:
            generate(std::get<ast::ZapReturnStatement>(statement.value),
                     blocks.back().statements);
            break;
        case ast::ZapStatementKind::Defer:
            generate(std::get<ast::ZapDeferStatement>(statement.value),
                     blocks.back().statements);
            break;
        case ast::ZapStatementKind::Block:
            const ast::ZapBlockStatement& block_stmt =
                std::get<ast::ZapBlockStatement>(statement.value);
            for (const ast::ZapStatement& stmt : block_stmt.statements) {
                generate(stmt, blocks);
            }
            break;
    }
}

OpCode get_from_binary_op(ast::BinaryOp op) {
    switch (op) {
        case ast::BinaryOp::ADD: return OpCode::ADD;
        case ast::BinaryOp::SUBTRACT: return OpCode::SUB;
        case ast::BinaryOp::MULTIPLY: return OpCode::MUL;
        case ast::BinaryOp::DIVIDE: return OpCode::DIV;
        case ast::BinaryOp::MOD: return OpCode::MOD;
        case ast::BinaryOp::EQUAL: return OpCode::EQ;
        case ast::BinaryOp::NOT_EQUAL: return OpCode::NE;
        case ast::BinaryOp::LESS_THAN: return OpCode::LT;
        case ast::BinaryOp::LESS_THAN_OR_EQUAL: return OpCode::LE;
        case ast::BinaryOp::GREATER_THAN: return OpCode::GT;
        case ast::BinaryOp::GREATER_THAN_OR_EQUAL: return OpCode::GE;
        case ast::BinaryOp::AND: return OpCode::AND;
        case ast::BinaryOp::OR: return OpCode::OR;
        case ast::BinaryOp::ASSIGNMENT: return OpCode::MOV;
        case ast::BinaryOp::NOT: return OpCode::NOT;
        case ast::BinaryOp::NEGATIVE: return OpCode::SUB; // Unary minus, handled specially
        default: return OpCode::ADD; // Fallback, should not happen
    }
}

void IRVisitor::generate(const ast::ZapExpression& expression, std::vector<IRStatement>& statements) {
    switch (expression.kind) {
        case ast::ZapExpressionKind::Literal: {
            const ast::ZapLiteral& literal = std::get<ast::ZapLiteral>(expression.value);
            if (literal.value.index() == 3) { // string
                std::string str_val = std::get<std::string>(literal.value);
                string_table.try_emplace(str_val, unique_num++);
                std::string var_name = "str_const_" + std::to_string(string_table[str_val]);
                statements.push_back(
                    IRStatement{var_name, OpCode::MOV, {str_val}});
            } else {
                std::string var_name = "lit_tmp" + std::to_string(unique_num++);
                statements.push_back(
                    IRStatement{var_name, OpCode::MOV, {std::to_string(std::get<i32>(literal.value))}});
            }
            break;
        }
        case ast::ZapExpressionKind::Identifier: {
            const ast::ZapIdentifier& ident = std::get<ast::ZapIdentifier>(expression.value);
            std::cout << "Ident: " << ident << '\n';
            statements.push_back(IRStatement{.result = ident, .op = OpCode::MOV, .arg_list = {ident}});
            // Not sure what to do here
            break;
        }
        case ast::ZapExpressionKind::Binary: {
            const ast::ZapBinaryExpression& exp = std::get<ast::ZapBinaryExpression>(expression.value);
            generate(*exp.left, statements);
            const std::string& left_name = statements.back().result;
            generate(*exp.right, statements);
            const std::string& right_name = statements.back().result;
            std::string var_name = get_temp();
            statements.push_back(IRStatement{.result = var_name, .op = get_from_binary_op(exp.op), .arg_list = {left_name, right_name}});
            break;
        }
        case ast::ZapExpressionKind::Unary: {
            const ast::ZapUnaryExpression& unary_exp = std::get<ast::ZapUnaryExpression>(expression.value);
            generate(*unary_exp.unary, statements);
            const std::string& unary_name = statements.back().result;
            if (unary_exp.op == ast::BinaryOp::NEGATIVE) {
                std::string negative_one_constant = get_temp();
                statements.push_back(IRStatement{.result = negative_one_constant, .op = OpCode::MOV, .arg_list = {"-1"}});
                statements.push_back(IRStatement{.result = get_temp(), .op = OpCode::MUL, .arg_list = {unary_name, negative_one_constant}});
            } else if (unary_exp.op == ast::BinaryOp::NOT) {
                statements.push_back(IRStatement{.result = get_temp(), .op = OpCode::NOT, .arg_list = {unary_name}});
            }
            break;
        }
        case ast::ZapExpressionKind::Call: {
            const ast::ZapCallExpression& call_exp = std::get<ast::ZapCallExpression>(expression.value);
            std::vector<std::string> arg_names;
            for (const auto& exp : call_exp.args) {
                generate(*exp, statements);
                arg_names.push_back(statements.back().result);
            }
            IRStatement call_statement{.result = get_temp(), .op = OpCode::CALL, .arg_list = {call_exp.function}};
            call_statement.arg_list.insert(call_statement.arg_list.end(), arg_names.begin(), arg_names.end());
            statements.push_back(call_statement);
            break;
        }
        case ast::ZapExpressionKind::StructInit: {
            const ast::ZapStructInitExpression& struct_init = std::get<ast::ZapStructInitExpression>(expression.value);
            std::string struct_ptr = get_temp();
            statements.push_back(IRStatement{.result = struct_ptr, .op = OpCode::ALLOCA, .arg_list = {struct_init.type_name}});
            for (const ast::ZapStructFieldInit& field : struct_init.fields) {
                generate(*field.value, statements);
                statements.push_back(IRStatement{.result = "", .op = OpCode::STRUCT_SET, .arg_list = {struct_ptr, statements.back().result, field.field}});
            }
            break;
        }
        case ast::ZapExpressionKind::StructAccess: {
            const ast::ZapStructAccessExpression& struct_access = std::get<ast::ZapStructAccessExpression>(expression.value);
            // TODO: Make a symbol table for functions so that stuff like this can be looked up    
            break;
        }
        case ast::ZapExpressionKind::AOTBlock: {
            const ast::ZapAOTBlock& block = std::get<ast::ZapAOTBlock>(expression.value);
            // TODO: Add VM so that these blocks can be evaluated at compile time
            break;
        }
    }
}

void IRVisitor::generate(const ast::ZapLetStatement& let_statement,
                         std::vector<IRStatement>& statements) {
    generate(*let_statement.value, statements);
    IRStatement statement{
        .result = let_statement.name,
        .op = OpCode::MOV,
        .arg_list = {statements.back().result}
    };
    statements.push_back(statement);
}

void IRVisitor::generate(const ast::ZapAssignStatement& assign_statement,
                         std::vector<IRStatement>& statements) {   
    generate(*assign_statement.value, statements);
    const std::string& val_name = statements.back().result;
    generate(*assign_statement.target, statements);
    const std::string& target_name = statements.back().result;
    statements.push_back(IRStatement{.result = val_name, .op = OpCode::MOV, .arg_list = {target_name}});
}

void IRVisitor::generate(const ast::ZapIfStatement& if_stmt, std::vector<IRBlock>& blocks) {
    // Generate unique names for each block
    std::string id = std::to_string(unique_num++);
    std::string then_name  = "then_block_" + id;
    std::string else_name  = "else_block_" + id;
    std::string merge_name = "merge_" + id;

    IRBlock cond_block;
    cond_block.name = "if_cond_" + id;
    generate(*if_stmt.condition, cond_block.statements);
    std::string cond_result = cond_block.statements.empty() ? "cond_tmp" + id : cond_block.statements.back().result;
    cond_block.statements.push_back(IRStatement{"", OpCode::BR, {cond_result, then_name, else_name}});
    blocks.push_back(std::move(cond_block));

    std::vector<IRBlock> then_blocks;
    for (const ast::ZapStatement& stmt : if_stmt.then_block) {
        generate(stmt, then_blocks);
    }
    if (!then_blocks.empty()) {
        then_blocks.front().name = then_name;
        then_blocks.back().statements.push_back(IRStatement{"", OpCode::JMP, {merge_name}});
        for (IRBlock& blk : then_blocks) {
            blocks.push_back(std::move(blk));
        }
    } else {
        IRBlock empty_then;
        empty_then.name = then_name;
        empty_then.statements.push_back(IRStatement{"", OpCode::JMP, {merge_name}});
        blocks.push_back(std::move(empty_then));
    }

    bool has_else = !if_stmt.else_block.empty();
    if (has_else) {
        std::vector<IRBlock> else_blocks;
        for (const ast::ZapStatement& stmt : if_stmt.else_block) {
            generate(stmt, else_blocks);
        }
        if (!else_blocks.empty()) {
            else_blocks.front().name = else_name;
            else_blocks.back().statements.push_back(IRStatement{"", OpCode::JMP, {merge_name}});
            for (auto& blk : else_blocks) {
                blocks.push_back(std::move(blk));
            }
        } else {
            IRBlock empty_else;
            empty_else.name = else_name;
            empty_else.statements.push_back(IRStatement{"", OpCode::JMP, {merge_name}});
            blocks.push_back(std::move(empty_else));
        }
    }

    IRBlock merge_block;
    merge_block.name = merge_name;
    blocks.push_back(std::move(merge_block));
}

IRLoop IRVisitor::generate(const ast::ZapForStatement& for_statement, std::vector<IRBlock>& blocks) {
    IRLoop loop{};
    std::string loop_name = get_temp();
    generate(for_statement.start, blocks.back().statements);
    const std::string& condition_var = blocks.back().statements.back().result;
    loop.condition.name = "for_condition_" + loop_name;
    generate(*for_statement.condition, loop.condition.statements);
    for (const ast::ZapStatement& ast_statement : for_statement.body) {
        generate(ast_statement, blocks);
    }
    return loop;
}

IRLoop IRVisitor::generate(const ast::ZapWhileStatement& while_statement, std::vector<IRBlock>& blocks) {
    // TODO: Implement while statement IR generation
    return IRLoop{};
}

void IRVisitor::generate(const ast::ZapReturnStatement& ret_statement,
                         std::vector<IRStatement>& statements) {
    if (ret_statement.value) {
        generate(*ret_statement.value, statements);
        statements.push_back(IRStatement{"", OpCode::RET, {statements.back().result}});
    } else {
        statements.push_back(IRStatement{"", OpCode::RET, {}});
    }
}

void IRVisitor::generate(const ast::ZapDeferStatement& defer_statement,
                         std::vector<IRStatement>& statements) {
    // TODO: Implement defer statement IR generation (in-place)
}

static std::string indent_str(int indent) {
    return std::string(indent * 2, ' ');
}

void IRPrettyPrinter::print(const IRProgram& program) const {
    for (const auto& strct : program.structs) {
        print(strct, 1);
    }
    for (const auto& func : program.functions) {
        print(func, 1);
    }
}

void IRPrettyPrinter::print(const IRStruct& strct, int indent) const {
    std::cout << indent_str(indent) << (strct.is_component ? "Component" : "Struct") << " " << strct.name << " {\n";
    for (auto& field : strct.fields) {
        std::cout << indent_str(indent + 1) << field.type.to_string() << " " << field.name << ";\n";
    }
    std::cout << indent_str(indent) << "}\n";
}

void IRPrettyPrinter::print(const IRFunction& function, int indent) const {
    std::cout << indent_str(indent) << "Function " << function.name << "(";
    for (size_t i = 0; i < function.args.size(); ++i) {
        std::cout << function.args[i].type.to_string() << " " << function.args[i].name;
        if (i + 1 < function.args.size()) std::cout << ", ";
    }
    std::cout << ") -> " << function.return_type.to_string() << " {\n";
    for (const auto& block : function.blocks) {
        print(block, indent + 1);
    }
    std::cout << indent_str(indent) << "}\n";
}

void IRPrettyPrinter::print(const IRBlock& block, int indent) const {
    std::cout << indent_str(indent) << "Block " << block.name << " {\n";
    for (const auto& stmt : block.statements) {
        print(stmt, indent + 1);
    }
    std::cout << indent_str(indent) << "}\n";
}

void IRPrettyPrinter::print(const IRStatement& stmt, int indent) const {
    std::cout << indent_str(indent) << stmt.result << " = " << static_cast<int>(stmt.op);
    if (!stmt.arg_list.empty()) {
        std::cout << " (";
        for (size_t i = 0; i < stmt.arg_list.size(); ++i) {
            std::cout << stmt.arg_list[i];
            if (i + 1 < stmt.arg_list.size()) std::cout << ", ";
        }
        std::cout << ")";
    }
    std::cout << "\n";
}

} // namespace ir
