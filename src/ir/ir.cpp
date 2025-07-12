#include "ir.h"
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "ast/ast.h"
#include "common.h"

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
    function.blocks      = {IRBlock{.name = "entry", .statements = {}}};
    std::unordered_map<std::string, std::string> var_map;
    for (const ast::ZapStatement& statement : func.body) {
        generate(statement, function.blocks, var_map);
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

void IRVisitor::generate(
    const ast::ZapStatement& statement, std::vector<IRBlock>& blocks,
    std::unordered_map<std::string, std::string>& var_map) {
    switch (statement.kind) {
        case ast::ZapStatementKind::If:
            generate(std::get<ast::ZapIfStatement>(statement.value), blocks,
                     var_map);
            break;
        case ast::ZapStatementKind::Let:
            generate(std::get<ast::ZapLetStatement>(statement.value),
                     blocks.back().statements, var_map);
            break;
        case ast::ZapStatementKind::Assign:
            generate(std::get<ast::ZapAssignStatement>(statement.value),
                     blocks.back().statements, var_map);
            break;
        case ast::ZapStatementKind::Expression:
            generate(
                *std::get<std::shared_ptr<ast::ZapExpression>>(statement.value),
                blocks.back().statements, var_map);
            break;
        case ast::ZapStatementKind::For:
            generate(std::get<ast::ZapForStatement>(statement.value), blocks,
                     var_map);
            break;
        case ast::ZapStatementKind::While:
            generate(std::get<ast::ZapWhileStatement>(statement.value), blocks,
                     var_map);
            break;
        case ast::ZapStatementKind::Return:
            generate(std::get<ast::ZapReturnStatement>(statement.value),
                     blocks.back().statements, var_map);
            break;
        case ast::ZapStatementKind::Defer:
            generate(std::get<ast::ZapDeferStatement>(statement.value), blocks,
                     var_map);
            break;
        case ast::ZapStatementKind::Block:
            const ast::ZapBlockStatement& block_stmt =
                std::get<ast::ZapBlockStatement>(statement.value);
            for (const ast::ZapStatement& stmt : block_stmt.statements) {
                generate(stmt, blocks, var_map);
            }
            break;
    }
}

OpCode get_from_binary_op(ast::BinaryOp op) {
    switch (op) {
        case ast::BinaryOp::ADD:
            return OpCode::ADD;
        case ast::BinaryOp::SUBTRACT:
            return OpCode::SUB;
        case ast::BinaryOp::MULTIPLY:
            return OpCode::MUL;
        case ast::BinaryOp::DIVIDE:
            return OpCode::DIV;
        case ast::BinaryOp::MOD:
            return OpCode::MOD;
        case ast::BinaryOp::EQUAL:
            return OpCode::EQ;
        case ast::BinaryOp::NOT_EQUAL:
            return OpCode::NE;
        case ast::BinaryOp::LESS_THAN:
            return OpCode::LT;
        case ast::BinaryOp::LESS_THAN_OR_EQUAL:
            return OpCode::LE;
        case ast::BinaryOp::GREATER_THAN:
            return OpCode::GT;
        case ast::BinaryOp::GREATER_THAN_OR_EQUAL:
            return OpCode::GE;
        case ast::BinaryOp::AND:
            return OpCode::AND;
        case ast::BinaryOp::OR:
            return OpCode::OR;
        case ast::BinaryOp::ASSIGNMENT:
            return OpCode::MOV;
        case ast::BinaryOp::NOT:
            return OpCode::NOT;
        case ast::BinaryOp::NEGATIVE:
            return OpCode::SUB;  // Unary minus, handled specially
        default:
            return OpCode::ADD;  // Fallback, should not happen
    }
}

void IRVisitor::generate(const ast::ZapExpression& expression,
                         std::vector<IRStatement>& statements) {
    switch (expression.kind) {
        case ast::ZapExpressionKind::Literal: {
            const ast::ZapLiteral& literal =
                std::get<ast::ZapLiteral>(expression.value);
            std::string var_name = "lit_tmp_" + std::to_string(unique_num++);
            switch (literal.value.index()) {
                case 0:  // int (of any kind right now)
                    statements.push_back(IRStatement{
                        var_name,
                        OpCode::MOV,
                        {std::to_string(
                            std::get<ast::LiteralInt>(literal.value))}});
                    break;
                case 1:  // float
                    statements.push_back(IRStatement{
                        var_name,
                        OpCode::MOV,
                        {std::to_string(
                            std::get<ast::LiteralFloat>(literal.value))}});
                    break;
                case 2:  // double
                    statements.push_back(IRStatement{
                        var_name,
                        OpCode::MOV,
                        {std::to_string(
                            std::get<ast::LiteralDouble>(literal.value))}});
                    break;
                case 3:  // string
                {
                    std::string str_val = std::get<std::string>(literal.value);
                    string_table.try_emplace(str_val, unique_num++);
                    std::string str_var =
                        "str_const_" + std::to_string(string_table[str_val]);
                    statements.push_back(
                        IRStatement{str_var, OpCode::MOV, {str_val}});
                    break;
                }
                case 4: {  // bool
                    statements.push_back(IRStatement{
                        var_name,
                        OpCode::MOV,
                        {std::get<ast::LiteralBool>(literal.value) ? "true"
                                                                   : "false"}});
                    break;
                }
                default:
                    statements.push_back(
                        IRStatement{var_name, OpCode::MOV, {"<unknown>"}});
                    break;
            }
            break;
        }
        case ast::ZapExpressionKind::Identifier: {
            ast::ZapIdentifier ident =
                std::get<ast::ZapIdentifier>(expression.value);
            std::string temp_var = get_temp();
            std::vector<std::string> arg_list{
                ident};  // Use ident directly since it's a std::string
            IRStatement statement{
                .result = temp_var, .op = OpCode::MOV, .arg_list = arg_list};
            statements.push_back(statement);
            break;
        }
        case ast::ZapExpressionKind::Binary: {
            const ast::ZapBinaryExpression& exp =
                std::get<ast::ZapBinaryExpression>(expression.value);
            size_t before_size = statements.size();
            generate(*exp.left, statements);
            ZAP_ASSERT(statements.size() != before_size,
                       "before_size is the same as the size of the statements "
                       "vector. No left side statements were created")
            std::string left_name = statements.back().result;

            before_size           = statements.size();
            generate(*exp.right, statements);
            ZAP_ASSERT(statements.size() != before_size,
                       "before_size is the same as the size of the statements "
                       "vector. No left side statements were created")
            std::string right_name = statements.back().result;

            std::string var_name   = get_temp();
            statements.push_back(
                IRStatement{.result   = var_name,
                            .op       = get_from_binary_op(exp.op),
                            .arg_list = {left_name, right_name}});
            break;
        }
        case ast::ZapExpressionKind::Unary: {
            const ast::ZapUnaryExpression& unary_exp =
                std::get<ast::ZapUnaryExpression>(expression.value);
            generate(*unary_exp.unary, statements);
            std::string unary_name = statements.back().result;
            if (unary_exp.op == ast::BinaryOp::NEGATIVE) {
                std::string negative_one_constant = get_temp();
                statements.push_back(
                    IRStatement{.result   = negative_one_constant,
                                .op       = OpCode::MOV,
                                .arg_list = {"-1"}});
                statements.push_back(IRStatement{
                    .result   = get_temp(),
                    .op       = OpCode::MUL,
                    .arg_list = {unary_name, negative_one_constant}});
            } else if (unary_exp.op == ast::BinaryOp::NOT) {
                statements.push_back(IRStatement{.result   = get_temp(),
                                                 .op       = OpCode::NOT,
                                                 .arg_list = {unary_name}});
            }
            break;
        }
        case ast::ZapExpressionKind::Call: {
            const ast::ZapCallExpression& call_exp =
                std::get<ast::ZapCallExpression>(expression.value);
            std::vector<std::string> arg_names;
            for (const std::shared_ptr<ast::ZapExpression> exp :
                 call_exp.args) {
                generate(*exp, statements);
                std::string arg_name = statements.back().result;
                arg_names.push_back(arg_name);
            }
            IRStatement call_statement{.result   = get_temp(),
                                       .op       = OpCode::CALL,
                                       .arg_list = {call_exp.function}};
            call_statement.arg_list.insert(call_statement.arg_list.end(),
                                           arg_names.begin(), arg_names.end());
            statements.push_back(call_statement);
            break;
        }
        case ast::ZapExpressionKind::StructInit: {
            const ast::ZapStructInitExpression& struct_init =
                std::get<ast::ZapStructInitExpression>(expression.value);
            std::string struct_ptr = get_temp();
            statements.push_back(
                IRStatement{.result   = struct_ptr,
                            .op       = OpCode::ALLOCA,
                            .arg_list = {struct_init.type_name}});
            for (const ast::ZapStructFieldInit& field : struct_init.fields) {
                generate(*field.value, statements);
                std::string field_val = statements.back().result;
                statements.push_back(IRStatement{
                    .result   = "",
                    .op       = OpCode::STRUCT_SET,
                    .arg_list = {struct_ptr, field_val, field.field}});
            }
            break;
        }
        case ast::ZapExpressionKind::StructAccess: {
            const ast::ZapStructAccessExpression& struct_access =
                std::get<ast::ZapStructAccessExpression>(expression.value);
            // TODO: Make a symbol table for functions so that stuff like this can be looked up
            break;
        }
        case ast::ZapExpressionKind::AOTBlock: {
            // TODO: Add VM so that these blocks can be evaluated at compile time
            break;
        }
        case ast::ZapExpressionKind::ArrayAccess: {
            const ast::ZapArrayAccessExpression& array_access =
                std::get<ast::ZapArrayAccessExpression>(expression.value);
            generate(*array_access.index, statements);
            const std::string& index_val = statements.back().result;
            std::string arr_ptr          = get_temp();
            statements.push_back(
                IRStatement{.result   = arr_ptr,
                            .op       = OpCode::ADD,
                            .arg_list = {array_access.array_name, index_val}});
            statements.push_back(IRStatement{.result   = get_temp(),
                                             .op       = OpCode::LOAD,
                                             .arg_list = {arr_ptr}});
            break;
        }
    }
}

void IRVisitor::generate(
    const ast::ZapExpression& expression, std::vector<IRStatement>& statements,
    std::unordered_map<std::string, std::string>& var_map) {
    switch (expression.kind) {
        case ast::ZapExpressionKind::Literal: {
            const ast::ZapLiteral& literal =
                std::get<ast::ZapLiteral>(expression.value);
            std::string var_name = "lit_tmp_" + std::to_string(unique_num++);
            switch (literal.value.index()) {
                case 0:  // int (of any kind right now)
                    statements.push_back(IRStatement{
                        var_name,
                        OpCode::MOV,
                        {std::to_string(
                            std::get<ast::LiteralInt>(literal.value))}});
                    break;
                case 1:  // float
                    statements.push_back(IRStatement{
                        var_name,
                        OpCode::MOV,
                        {std::to_string(
                            std::get<ast::LiteralFloat>(literal.value))}});
                    break;
                case 2:  // double
                    statements.push_back(IRStatement{
                        var_name,
                        OpCode::MOV,
                        {std::to_string(
                            std::get<ast::LiteralDouble>(literal.value))}});
                    break;
                case 3:  // string
                {
                    std::string str_val = std::get<std::string>(literal.value);
                    string_table.try_emplace(str_val, unique_num++);
                    std::string str_var =
                        "str_const_" + std::to_string(string_table[str_val]);
                    statements.push_back(
                        IRStatement{str_var, OpCode::MOV, {str_val}});
                    break;
                }
                case 4: {  // bool
                    statements.push_back(IRStatement{
                        var_name,
                        OpCode::MOV,
                        {std::to_string(
                            std::get<ast::LiteralBool>(literal.value))}});
                    break;
                }
                default:
                    statements.push_back(
                        IRStatement{var_name, OpCode::MOV, {"<unknown>"}});
                    break;
            }
            break;
        }
        case ast::ZapExpressionKind::Identifier: {
            ast::ZapIdentifier ident =
                std::get<ast::ZapIdentifier>(expression.value);
            std::string temp_var   = get_temp();
            std::string source_var = ident;

            // Check if the identifier is mapped to a temporary variable
            auto it                = var_map.find(ident);
            if (it != var_map.end()) {
                source_var = it->second;
            }

            std::vector<std::string> arg_list{source_var};
            IRStatement statement{
                .result = temp_var, .op = OpCode::MOV, .arg_list = arg_list};
            statements.push_back(statement);
            break;
        }
        case ast::ZapExpressionKind::Binary: {
            const ast::ZapBinaryExpression& exp =
                std::get<ast::ZapBinaryExpression>(expression.value);

            // Handle assignment specially (not as a regular binary operation)
            if (exp.op == ast::BinaryOp::ASSIGNMENT) {
                // Generate the right-hand side (value)
                generate(*exp.right, statements, var_map);
                const std::string val_name = statements.back().result;

                // For SSA compliance, create a new temporary variable for assignment
                std::string new_temp       = get_temp();
                statements.push_back(IRStatement{.result   = new_temp,
                                                 .op       = OpCode::MOV,
                                                 .arg_list = {val_name}});

                // Update var_map to point the target variable to the new temporary
                // The left-hand side should be an identifier
                if (exp.left->kind == ast::ZapExpressionKind::Identifier) {
                    ast::ZapIdentifier target_var =
                        std::get<ast::ZapIdentifier>(exp.left->value);
                    var_map[target_var] = new_temp;
                }
                break;
            }

            // Handle regular binary operations
            size_t before_size = statements.size();
            generate(*exp.left, statements, var_map);
            ZAP_ASSERT(statements.size() != before_size,
                       "before_size is the same as the size of the statements "
                       "vector. No left side statements were created")
            std::string left_name = statements.back().result;

            before_size           = statements.size();
            generate(*exp.right, statements, var_map);
            ZAP_ASSERT(statements.size() != before_size,
                       "before_size is the same as the size of the statements "
                       "vector. No left side statements were created")
            std::string right_name = statements.back().result;

            std::string result_var = get_temp();
            OpCode opcode          = get_from_binary_op(exp.op);
            IRStatement statement{.result   = result_var,
                                  .op       = opcode,
                                  .arg_list = {left_name, right_name}};
            statements.push_back(statement);
            break;
        }
        case ast::ZapExpressionKind::Unary: {
            const ast::ZapUnaryExpression& unary_exp =
                std::get<ast::ZapUnaryExpression>(expression.value);
            generate(*unary_exp.unary, statements, var_map);
            std::string unary_name = statements.back().result;
            if (unary_exp.op == ast::BinaryOp::NEGATIVE) {
                std::string negative_one_constant = get_temp();
                statements.push_back(
                    IRStatement{.result   = negative_one_constant,
                                .op       = OpCode::MOV,
                                .arg_list = {"-1"}});
                statements.push_back(IRStatement{
                    .result   = get_temp(),
                    .op       = OpCode::MUL,
                    .arg_list = {unary_name, negative_one_constant}});
            } else if (unary_exp.op == ast::BinaryOp::NOT) {
                statements.push_back(IRStatement{.result   = get_temp(),
                                                 .op       = OpCode::NOT,
                                                 .arg_list = {unary_name}});
            }
            break;
        }
        case ast::ZapExpressionKind::Call: {
            const ast::ZapCallExpression& call_exp =
                std::get<ast::ZapCallExpression>(expression.value);
            std::vector<std::string> arg_names;
            for (const std::shared_ptr<ast::ZapExpression> exp :
                 call_exp.args) {
                generate(*exp, statements, var_map);
                std::string arg_name = statements.back().result;
                arg_names.push_back(arg_name);
            }
            IRStatement call_statement{.result   = get_temp(),
                                       .op       = OpCode::CALL,
                                       .arg_list = {call_exp.function}};
            call_statement.arg_list.insert(call_statement.arg_list.end(),
                                           arg_names.begin(), arg_names.end());
            statements.push_back(call_statement);
            break;
        }
        case ast::ZapExpressionKind::StructInit: {
            const ast::ZapStructInitExpression& struct_init =
                std::get<ast::ZapStructInitExpression>(expression.value);
            std::string struct_ptr = get_temp();
            statements.push_back(
                IRStatement{.result   = struct_ptr,
                            .op       = OpCode::ALLOCA,
                            .arg_list = {struct_init.type_name}});
            for (const ast::ZapStructFieldInit& field : struct_init.fields) {
                generate(*field.value, statements, var_map);
                std::string field_val = statements.back().result;
                statements.push_back(IRStatement{
                    .result   = "",
                    .op       = OpCode::STRUCT_SET,
                    .arg_list = {struct_ptr, field_val, field.field}});
            }
            break;
        }
        case ast::ZapExpressionKind::StructAccess: {
            const ast::ZapStructAccessExpression& struct_access =
                std::get<ast::ZapStructAccessExpression>(expression.value);
            // TODO: Make a symbol table for functions so that stuff like this can be looked up
            break;
        }
        case ast::ZapExpressionKind::AOTBlock: {
            // TODO: Add VM so that these blocks can be evaluated at compile time
            break;
        }
        case ast::ZapExpressionKind::ArrayAccess: {
            const ast::ZapArrayAccessExpression& array_access =
                std::get<ast::ZapArrayAccessExpression>(expression.value);
            generate(*array_access.index, statements, var_map);
            const std::string& index_val = statements.back().result;
            std::string arr_ptr          = get_temp();
            statements.push_back(
                IRStatement{.result   = arr_ptr,
                            .op       = OpCode::ADD,
                            .arg_list = {array_access.array_name, index_val}});
            statements.push_back(IRStatement{.result   = get_temp(),
                                             .op       = OpCode::LOAD,
                                             .arg_list = {arr_ptr}});
            break;
        }
    }
}

void IRVisitor::generate(
    const ast::ZapLetStatement& let_statement,
    std::vector<IRStatement>& statements,
    std::unordered_map<std::string, std::string>& var_map) {
    generate(*let_statement.value, statements, var_map);
    if (statements.empty()) {
        std::cerr << "[IR ERROR] Let statement value did not generate any IR "
                     "statements!\n";
        std::abort();
    }
    std::string value_result = statements.back().result;
    var_map.try_emplace(let_statement.name, get_temp());
    IRStatement statement{.result   = var_map[let_statement.name],
                          .op       = OpCode::MOV,
                          .arg_list = {value_result}};
    statements.push_back(statement);
}

void IRVisitor::generate(
    const ast::ZapAssignStatement& assign_statement,
    std::vector<IRStatement>& statements,
    std::unordered_map<std::string, std::string>& var_map) {
    // Generate the value expression
    generate(*assign_statement.value, statements, var_map);
    const std::string val_name = statements.back().result;

    // For SSA compliance, create a new temporary variable for assignment
    std::string new_temp       = get_temp();
    statements.push_back(IRStatement{
        .result = new_temp, .op = OpCode::MOV, .arg_list = {val_name}});

    // Update var_map to point the target variable to the new temporary
    // We need to extract the variable name from the target expression
    if (assign_statement.target->kind == ast::ZapExpressionKind::Identifier) {
        ast::ZapIdentifier target_var =
            std::get<ast::ZapIdentifier>(assign_statement.target->value);
        var_map[target_var] = new_temp;
    }
}

void IRVisitor::generate(
    const ast::ZapIfStatement& if_stmt, std::vector<IRBlock>& blocks,
    std::unordered_map<std::string, std::string>& var_map) {
    // Generate unique names for each block
    std::string id         = std::to_string(unique_num++);
    std::string then_name  = "then_block_" + id;
    std::string else_name  = "else_block_" + id;
    std::string merge_name = "merge_" + id;

    // Save the current variable state (before if-statement)
    std::unordered_map<std::string, std::string> entry_var_map = var_map;

    IRBlock cond_block;
    cond_block.name = "if_cond_" + id;
    generate(*if_stmt.condition, cond_block.statements, var_map);
    if (cond_block.statements.empty()) {
        std::cerr << "[IR ERROR] Condition block for if-statement generated no "
                     "IR statements!\n";
        std::cerr << "This usually means a bug in expression IR generation."
                  << std::endl;
        std::abort();
    }
    std::string cond_result = cond_block.statements.back().result;
    bool has_else           = !if_stmt.else_block.empty();
    cond_block.statements.push_back(IRStatement{
        "",
        OpCode::BR,
        {cond_result, then_name, has_else ? else_name : merge_name}});
    blocks.push_back(std::move(cond_block));

    // Generate then block with its own variable map
    std::unordered_map<std::string, std::string> then_var_map = var_map;
    std::vector<IRBlock> then_blocks{
        {IRBlock{.name = then_name, .statements = {}}}};
    for (const ast::ZapStatement& stmt : if_stmt.then_block) {
        generate(stmt, then_blocks, then_var_map);
    }
    then_blocks.back().statements.push_back(
        IRStatement{"", OpCode::JMP, {merge_name}});

    // Record the actual last block name for then path
    std::string then_exit_block = then_blocks.back().name;

    if (!then_blocks.front().statements.empty() ||
        then_blocks.front().statements.empty()) {
        blocks.insert(blocks.end(), then_blocks.begin(), then_blocks.end());
    }

    // Generate else block with its own variable map
    std::unordered_map<std::string, std::string> else_var_map = var_map;
    std::string else_exit_block;
    if (has_else) {
        std::vector<IRBlock> else_blocks{
            {IRBlock{.name = else_name, .statements = {}}}};
        for (const ast::ZapStatement& stmt : if_stmt.else_block) {
            generate(stmt, else_blocks, else_var_map);
        }
        else_blocks.back().statements.push_back(
            IRStatement{"", OpCode::JMP, {merge_name}});

        // Record the actual last block name for else path
        else_exit_block = else_blocks.back().name;

        if (!else_blocks.front().statements.empty() ||
            else_blocks.front().statements.empty()) {
            blocks.insert(blocks.end(), else_blocks.begin(), else_blocks.end());
        }
    } else {
        // If no else block, the else path has the same variable state as entry
        else_var_map    = var_map;
        else_exit_block = "if_cond_" + id;
    }

    // Create merge block and generate phi nodes
    IRBlock merge_block;
    merge_block.name = merge_name;

    // Prepare incoming blocks for phi node generation
    std::vector<
        std::pair<std::string, std::unordered_map<std::string, std::string>>>
        incoming_blocks;
    incoming_blocks.emplace_back(then_exit_block, then_var_map);
    incoming_blocks.emplace_back(else_exit_block, else_var_map);

    // Generate phi nodes and update var_map for merge block
    generate_phi_nodes(merge_block, incoming_blocks, var_map);

    blocks.push_back(std::move(merge_block));
}

void IRVisitor::generate(
    const ast::ZapForStatement& for_statement, std::vector<IRBlock>& blocks,
    std::unordered_map<std::string, std::string>& var_map) {
    std::string unique_loop_num      = std::to_string(unique_num++);
    std::string body_block_name      = "for_body_" + unique_loop_num;
    std::string condition_block_name = "for_condition_" + unique_loop_num;
    std::string continue_block       = "for_continue_" + unique_loop_num;
    generate(for_statement.start, blocks.back().statements, var_map);
    const std::string& condition_var = blocks.back().statements.back().result;

    IRBlock condition_block{.name = condition_block_name, .statements = {}};
    generate(*for_statement.condition, condition_block.statements, var_map);
    const std::string& condition_result =
        condition_block.statements.back().result;
    condition_block.statements.push_back(IRStatement{
        .result   = "",
        .op       = OpCode::BR,
        .arg_list = {condition_result, body_block_name, continue_block}});

    std::vector<IRBlock> body{
        {IRBlock{.name = body_block_name, .statements = {}}}};
    for (const ast::ZapStatement& ast_statement : for_statement.body) {
        generate(ast_statement, body, var_map);
    }
    body.back().statements.push_back(IRStatement{
        .result = "", .op = OpCode::JMP, .arg_list = {condition_block_name}});

    blocks.push_back(condition_block);
    blocks.insert(blocks.end(), body.begin(), body.end());
    blocks.push_back(IRBlock{.name = continue_block, .statements = {}});
}

void IRVisitor::generate(
    const ast::ZapWhileStatement& while_statement, std::vector<IRBlock>& blocks,
    std::unordered_map<std::string, std::string>& var_map) {
    std::string unique_num_str       = std::to_string(unique_num++);
    std::string condition_block_name = "while_condition_" + unique_num_str;
    std::string body_block_name      = "while_body_" + unique_num_str;
    std::string continue_block_name  = "while_continue_" + unique_num_str;

    IRBlock condition_block{.name = condition_block_name, .statements = {}};
    generate(*while_statement.condition, condition_block.statements, var_map);
    std::string test_var = condition_block.statements.back().result;
    condition_block.statements.push_back(IRStatement{
        .result   = "",
        .op       = OpCode::BR,
        .arg_list = {test_var, body_block_name, continue_block_name}});
    std::vector<IRBlock> body{
        {IRBlock{.name = body_block_name, .statements = {}}}};
    for (const ast::ZapStatement& statement : while_statement.body) {
        generate(statement, body, var_map);
    }
    body.back().statements.push_back(IRStatement{
        .result = "", .op = OpCode::JMP, .arg_list = {condition_block_name}});
    blocks.push_back(condition_block);
    blocks.insert(blocks.end(), body.begin(), body.end());
    blocks.push_back(IRBlock{.name = continue_block_name, .statements = {}});
}

void IRVisitor::generate(
    const ast::ZapReturnStatement& ret_statement,
    std::vector<IRStatement>& statements,
    std::unordered_map<std::string, std::string>& var_map) {
    if (ret_statement.value) {
        generate(*ret_statement.value, statements, var_map);
        statements.push_back(
            IRStatement{"", OpCode::RET, {statements.back().result}});
    } else {
        statements.push_back(IRStatement{"", OpCode::RET, {}});
    }
}

void IRVisitor::generate_phi_nodes(
    IRBlock& merge_block,
    const std::vector<
        std::pair<std::string, std::unordered_map<std::string, std::string>>>&
        incoming_blocks,
    std::unordered_map<std::string, std::string>& merge_var_map) {
    // Find all variables that need phi nodes
    std::unordered_set<std::string> all_vars;
    for (const auto& [block_name, var_map] : incoming_blocks) {
        for (const auto& [var_name, temp_name] : var_map) {
            all_vars.insert(var_name);
        }
    }

    // For each variable, check if it has different values in different blocks
    for (const std::string& var_name : all_vars) {
        std::vector<std::string> phi_values;
        std::vector<std::string> phi_blocks;
        bool needs_phi = false;
        std::string first_temp;

        for (const auto& [block_name, var_map] : incoming_blocks) {
            auto it = var_map.find(var_name);
            if (it != var_map.end()) {
                if (first_temp.empty()) {
                    first_temp = it->second;
                } else if (first_temp != it->second) {
                    needs_phi = true;
                }
                phi_values.push_back(it->second);
                phi_blocks.push_back(block_name);
            }
        }

        if (needs_phi && phi_values.size() > 1) {
            // Generate a phi node
            std::string phi_result = get_temp();
            std::vector<std::string> phi_args;

            // Phi arguments are pairs: [value, block, value, block, ...]
            for (size_t i = 0; i < phi_values.size(); ++i) {
                phi_args.push_back(phi_values[i]);
                phi_args.push_back(phi_blocks[i]);
            }

            IRStatement phi_stmt{
                .result = phi_result, .op = OpCode::PHI, .arg_list = phi_args};

            merge_block.statements.insert(merge_block.statements.begin(),
                                          phi_stmt);
            merge_var_map[var_name] = phi_result;
        } else if (!phi_values.empty()) {
            // Variable has the same value in all blocks, no phi needed
            merge_var_map[var_name] = phi_values[0];
        }
    }
}

void IRVisitor::generate(
    const ast::ZapDeferStatement& defer_statement, std::vector<IRBlock>& blocks,
    std::unordered_map<std::string, std::string>& var_map) {
    if (defer_statement.is_body) {
        for (const ast::ZapStatement& statement : defer_statement.body) {
            generate(statement, blocks, var_map);
        }
    } else {
        generate(*defer_statement.expr, blocks.back().statements, var_map);
    }
}

static std::string indent_str(int indent) {
    return std::string(indent * 2, ' ');
}

static const char* opcode_to_string(OpCode op) {
    switch (op) {
        case OpCode::ADD:
            return "ADD";
        case OpCode::SUB:
            return "SUB";
        case OpCode::MUL:
            return "MUL";
        case OpCode::DIV:
            return "DIV";
        case OpCode::MOD:
            return "MOD";
        case OpCode::EQ:
            return "EQ";
        case OpCode::NE:
            return "NE";
        case OpCode::LT:
            return "LT";
        case OpCode::LE:
            return "LE";
        case OpCode::GT:
            return "GT";
        case OpCode::GE:
            return "GE";
        case OpCode::AND:
            return "AND";
        case OpCode::OR:
            return "OR";
        case OpCode::MOV:
            return "MOV";
        case OpCode::NOT:
            return "NOT";
        case OpCode::CALL:
            return "CALL";
        case OpCode::ALLOCA:
            return "ALLOCA";
        case OpCode::STRUCT_SET:
            return "STRUCT_SET";
        case OpCode::BR:
            return "BR";
        case OpCode::JMP:
            return "JMP";
        case OpCode::RET:
            return "RET";
        case OpCode::CAST:
            return "CAST";
        case OpCode::PHI:
            return "PHI";
        default:
            return "UNKNOWN";
    }
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
    std::cout << indent_str(indent)
              << (strct.is_component ? "component" : "struct") << " "
              << strct.name << " {\n";
    for (auto& field : strct.fields) {
        std::cout << indent_str(indent + 1) << field.type.to_string() << " "
                  << field.name << ";\n";
    }
    std::cout << indent_str(indent) << "}\n";
}

void IRPrettyPrinter::print(const IRFunction& function, int indent) const {
    std::cout << indent_str(indent) << "function " << function.name << "(";
    for (size_t i = 0; i < function.args.size(); ++i) {
        std::cout << function.args[i].type.to_string() << " "
                  << function.args[i].name;
        if (i + 1 < function.args.size())
            std::cout << ", ";
    }
    std::cout << ") -> " << function.return_type.to_string() << " {\n";
    for (const auto& block : function.blocks) {
        print(block, indent + 1);
    }
    std::cout << indent_str(indent) << "}\n";
}

void IRPrettyPrinter::print(const IRBlock& block, int indent) const {
    std::cout << indent_str(indent) << block.name << ":\n";
    for (const auto& stmt : block.statements) {
        print(stmt, indent + 1);
    }
}

void IRPrettyPrinter::print(const IRStatement& stmt, int indent) const {
    std::cout << indent_str(indent);
    if (!stmt.result.empty()) {
        std::cout << stmt.result << " = ";
    }
    std::cout << opcode_to_string(stmt.op) << ' ';
    if (!stmt.arg_list.empty()) {
        for (size_t i = 0; i < stmt.arg_list.size(); ++i) {
            std::cout << stmt.arg_list[i];
            if (i + 1 < stmt.arg_list.size())
                std::cout << ", ";
        }
    }
    std::cout << "\n";
}

}  // namespace ir
