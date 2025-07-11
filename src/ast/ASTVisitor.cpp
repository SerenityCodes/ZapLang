#include "ASTVisitor.h"
#include <any>
#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include "antlr/zapParser.h"
#include "ast/ast.h"
#include "common.h"

std::any ASTVisitor::visitProgram(zapParser::ProgramContext* ctx) {
    ast::ZapProgram program{.class_symbol_table = {}, .declarations = {}};
    for (zapParser::DeclarationContext* dec : ctx->declaration()) {
        ast::ZapDecl result =
            std::any_cast<ast::ZapDecl>(visitDeclaration(dec));
        program.declarations.push_back(result);

        // Populate symbol table with structs and components
        if (result.kind == ast::ZapDeclKind::Struct) {
            ast::ZapStruct struct_decl = std::get<ast::ZapStruct>(result.value);
            program.class_symbol_table.struct_map[struct_decl.name] =
                struct_decl;
        } else if (result.kind == ast::ZapDeclKind::Component) {
            ast::ZapComponent component_decl =
                std::get<ast::ZapComponent>(result.value);
            program.class_symbol_table.component_map[component_decl.name] =
                component_decl;
        }
    }
    return program;
}

std::any ASTVisitor::visitFunctionDecl(zapParser::FunctionDeclContext* ctx) {
    std::vector<ast::ZapStatement> function_body =
        std::any_cast<std::vector<ast::ZapStatement>>(visitBlock(ctx->block()));
    return ast::ZapFunction{
        .name       = ctx->IDENTIFIER()->getText(),
        .attributes = ctx->attributeBlock()
                          ? std::any_cast<std::vector<ast::ZapAttribute>>(
                                visitAttributeList(
                                    ctx->attributeBlock()->attributeList()))
                          : std::vector<ast::ZapAttribute>{},
        .params     = std::any_cast<std::vector<ast::ZapParam>>(
            visitParameterList(ctx->parameterList())),
        .return_type =
            std::any_cast<ast::ZapType>(visitReturnType(ctx->returnType())),
        .symbol_table = std::unordered_map<std::string, ast::ZapType>{},
        .body         = function_body,
    };
}

std::any ASTVisitor::visitStructField(zapParser::StructFieldContext* ctx) {
    return ast::ZapField{
        .name = ctx->IDENTIFIER()->getText(),
        .type = std::any_cast<ast::ZapType>(visitType(ctx->type()))};
}

std::any ASTVisitor::visitStructDecl(zapParser::StructDeclContext* ctx) {
    std::vector<ast::ZapField> zap_fields;
    for (zapParser::StructFieldContext* field_ctx : ctx->structField()) {
        zap_fields.push_back(
            std::any_cast<ast::ZapField>(visitStructField(field_ctx)));
    }
    return ast::ZapStruct{.name   = ctx->IDENTIFIER()->getText(),
                          .fields = zap_fields};
}

std::any ASTVisitor::visitComponentDecl(zapParser::ComponentDeclContext* ctx) {
    std::vector<ast::ZapField> zap_fields;
    for (zapParser::StructFieldContext* field_ctx : ctx->structField()) {
        zap_fields.push_back(
            std::any_cast<ast::ZapField>(visitStructField(field_ctx)));
    }
    return ast::ZapComponent{.name        = ctx->IDENTIFIER()->getText(),
                             .fields      = zap_fields,
                             .is_readonly = static_cast<bool>(ctx->READONLY())};
}

std::any ASTVisitor::visitModuleDecl(zapParser::ModuleDeclContext* ctx) {
    // Implement this
    return visitChildren(ctx);
}

std::any ASTVisitor::visitVariableDecl(zapParser::VariableDeclContext* ctx) {
    return ast::ZapLetStatement{
        .name  = ctx->IDENTIFIER()->getText(),
        .type  = std::any_cast<ast::ZapType>(visitType(ctx->type())),
        .value = std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            ctx->expression() ? visitExpression(ctx->expression())
                              : visitAotBlock(ctx->aotBlock())),
    };
}

std::any ASTVisitor::visitIfStmt(zapParser::IfStmtContext* ctx) {
    return ast::ZapIfStatement{
        .condition = std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitExpression(ctx->expression())),
        .then_block = std::any_cast<std::vector<ast::ZapStatement>>(
            visitBlock(ctx->block()[0])),
        .else_block = ctx->block().size() > 1
                          ? std::any_cast<std::vector<ast::ZapStatement>>(
                                visitBlock(ctx->block()[1]))
                          : std::vector<ast::ZapStatement>{}};
}

std::any ASTVisitor::visitWhileStmt(zapParser::WhileStmtContext* ctx) {
    return ast::ZapWhileStatement{
        .condition = std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitExpression(ctx->expression())),
        .body = std::any_cast<std::vector<ast::ZapStatement>>(
            visitBlock(ctx->block()))};
}

std::any ASTVisitor::visitForStmt(zapParser::ForStmtContext* ctx) {
    return ast::ZapForStatement{
        .start = std::any_cast<ast::ZapLetStatement>(
            visitVariableDecl(ctx->variableDecl())),
        .condition = std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitExpression(ctx->expression()[0])),
        .step = std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitExpression(ctx->expression()[1])),
        .body = std::any_cast<std::vector<ast::ZapStatement>>(
            visitBlock(ctx->block()))};
}

std::any ASTVisitor::visitReturnStmt(zapParser::ReturnStmtContext* ctx) {
    return ast::ZapReturnStatement{
        .value = std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitExpression(ctx->expression()))};
}

std::any ASTVisitor::visitYieldStmt(zapParser::YieldStmtContext* ctx) {
    return ast::ZapReturnStatement{
        .value = std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitExpression(ctx->expression()))};
}

std::any ASTVisitor::visitDeferStmt(zapParser::DeferStmtContext* ctx) {
    return ast::ZapDeferStatement{
        .is_body = ctx->block() != nullptr,
        .expr    = ctx->block() == nullptr
                       ? std::any_cast<std::shared_ptr<ast::ZapExpression>>(
                          visitExpressionStmt(ctx->expressionStmt()))
                       : std::shared_ptr<ast::ZapExpression>{nullptr},
        .body    = ctx->block() == nullptr
                       ? std::vector<ast::ZapStatement>{}
                       : std::any_cast<std::vector<ast::ZapStatement>>(
                          visitBlock(ctx->block())),
    };
}

std::any ASTVisitor::visitExpressionStmt(
    zapParser::ExpressionStmtContext* ctx) {
    return visitExpression(ctx->expression());
}

std::any ASTVisitor::visitExpression(zapParser::ExpressionContext* ctx) {
    return visitAssignment(ctx->assignment());
}

std::any ASTVisitor::visitLvalue(zapParser::LvalueContext* ctx) {
    // Identifier
    if (!ctx->lvalue() && ctx->IDENTIFIER()) {
        return std::make_shared<ast::ZapExpression>(
            ast::ZapExpression{.kind  = ast::ZapExpressionKind::Identifier,
                               .value = ctx->IDENTIFIER()->getText()});
    }

    // Struct Access
    if (ctx->lvalue() && ctx->IDENTIFIER()) {
        return std::make_shared<ast::ZapExpression>(
            ast::ZapExpression{.kind  = ast::ZapExpressionKind::StructAccess,
                               .value = ast::ZapStructAccessExpression{
                                   .type  = ctx->lvalue()->getText(),
                                   .field = ctx->IDENTIFIER()->getText(),
                               }});
    }
    // Array Access
    if (ctx->lvalue() && ctx->expression()) {
        return std::make_shared<ast::ZapExpression>(ast::ZapExpression{
            .kind  = ast::ZapExpressionKind::ArrayAccess,
            .value = ast::ZapArrayAccessExpression{
                .array_name = ctx->lvalue()->getText(),
                .index = std::any_cast<std::shared_ptr<ast::ZapExpression>>(
                    visitExpression(ctx->expression()))}});
    }
    return {};
}

std::any ASTVisitor::visitAssignment(zapParser::AssignmentContext* ctx) {
    // If there's no assignment going on
    if (ctx->logicOr()) {
        return std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitLogicOr(ctx->logicOr()));
    }
    return std::make_shared<ast::ZapExpression>(ast::ZapExpression{
        .kind = ast::ZapExpressionKind::Binary,
        .value =
            ast::ZapBinaryExpression{
                .left = std::any_cast<std::shared_ptr<ast::ZapExpression>>(
                    visitLvalue(ctx->lvalue())),
                .right = std::any_cast<std::shared_ptr<ast::ZapExpression>>(
                    visitExpression(ctx->expression())),
                .op = ast::BinaryOp::ASSIGNMENT,
            },
    });
}

std::any ASTVisitor::visitLogicOr(zapParser::LogicOrContext* ctx) {
    std::shared_ptr<ast::ZapExpression> left =
        std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitLogicAnd(ctx->logicAnd()[0]));
    for (int i = 1; i < ctx->logicAnd().size(); i++) {
        std::shared_ptr<ast::ZapExpression> right =
            std::any_cast<std::shared_ptr<ast::ZapExpression>>(
                visitLogicAnd(ctx->logicAnd()[i]));
        left = std::make_shared<ast::ZapExpression>(
            ast::ZapExpression{.kind  = ast::ZapExpressionKind::Binary,
                               .value = ast::ZapBinaryExpression{
                                   .left  = left,
                                   .right = right,
                                   .op    = ast::BinaryOp::OR,
                               }});
    }
    return left;
}

std::any ASTVisitor::visitLogicAnd(zapParser::LogicAndContext* ctx) {
    std::shared_ptr<ast::ZapExpression> left =
        std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitEquality(ctx->equality()[0]));
    for (int i = 1; i < ctx->equality().size(); i++) {
        std::shared_ptr<ast::ZapExpression> right =
            std::any_cast<std::shared_ptr<ast::ZapExpression>>(
                visitEquality(ctx->equality()[i]));
        left = std::make_shared<ast::ZapExpression>(
            ast::ZapExpression{.kind  = ast::ZapExpressionKind::Binary,
                               .value = ast::ZapBinaryExpression{
                                   .left  = left,
                                   .right = right,
                                   .op    = ast::BinaryOp::AND,
                               }});
    }
    return left;
}

std::any ASTVisitor::visitEquality(zapParser::EqualityContext* ctx) {
    std::shared_ptr<ast::ZapExpression> left =
        std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitComparison(ctx->comparison()[0]));
    for (int i = 1; i < ctx->comparison().size(); i++) {
        bool is_equal = ctx->op[i - 1]->getType() == zapParser::EQ;
        std::shared_ptr<ast::ZapExpression> right =
            std::any_cast<std::shared_ptr<ast::ZapExpression>>(
                visitComparison(ctx->comparison()[i]));
        left = std::make_shared<ast::ZapExpression>(
            ast::ZapExpression{.kind  = ast::ZapExpressionKind::Binary,
                               .value = ast::ZapBinaryExpression{
                                   .left  = left,
                                   .right = right,
                                   .op    = is_equal ? ast::BinaryOp::EQUAL
                                                     : ast::BinaryOp::NOT_EQUAL,
                               }});
    }
    return left;
}

ast::BinaryOp get_comparison_op(size_t type) {
    switch (type) {
        case zapParser::LT:
            return ast::BinaryOp::LESS_THAN;
        case zapParser::LTE:
            return ast::BinaryOp::LESS_THAN_OR_EQUAL;
        case zapParser::GT:
            return ast::BinaryOp::GREATER_THAN;
        case zapParser::GTE:
            return ast::BinaryOp::GREATER_THAN_OR_EQUAL;
    }
    return ast::BinaryOp::GREATER_THAN;
}

std::any ASTVisitor::visitComparison(zapParser::ComparisonContext* ctx) {
    std::shared_ptr<ast::ZapExpression> left =
        std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitTerm(ctx->term()[0]));
    for (int i = 1; i < ctx->term().size(); i++) {
        std::shared_ptr<ast::ZapExpression> right =
            std::any_cast<std::shared_ptr<ast::ZapExpression>>(
                visitTerm(ctx->term()[i]));
        left = std::make_shared<ast::ZapExpression>(ast::ZapExpression{
            .kind  = ast::ZapExpressionKind::Binary,
            .value = ast::ZapBinaryExpression{
                .left  = left,
                .right = right,
                .op    = get_comparison_op(ctx->op[i - 1]->getType())}});
    }
    return left;
}

ast::BinaryOp get_term_op(size_t type) {
    return type == zapParser::ADD ? ast::BinaryOp::ADD
                                  : ast::BinaryOp::SUBTRACT;
}

std::any ASTVisitor::visitTerm(zapParser::TermContext* ctx) {
    std::shared_ptr<ast::ZapExpression> left =
        std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitFactor(ctx->factor()[0]));
    for (int i = 1; i < ctx->factor().size(); i++) {
        std::shared_ptr<ast::ZapExpression> right =
            std::any_cast<std::shared_ptr<ast::ZapExpression>>(
                visitFactor(ctx->factor()[i]));
        left = std::make_shared<ast::ZapExpression>(ast::ZapExpression{
            .kind  = ast::ZapExpressionKind::Binary,
            .value = ast::ZapBinaryExpression{
                .left  = left,
                .right = right,
                .op    = get_term_op(ctx->op[i - 1]->getType())}});
    }
    return left;
}

ast::BinaryOp get_factory_op(size_t type) {
    switch (type) {
        case zapParser::MUL:
            return ast::BinaryOp::MULTIPLY;
        case zapParser::DIV:
            return ast::BinaryOp::DIVIDE;
        case zapParser::MOD:
            return ast::BinaryOp::MOD;
    }
    return ast::BinaryOp::GREATER_THAN;
}

std::any ASTVisitor::visitFactor(zapParser::FactorContext* ctx) {
    std::shared_ptr<ast::ZapExpression> left =
        std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitUnary(ctx->unary()[0]));
    for (int i = 1; i < ctx->unary().size(); i++) {
        std::shared_ptr<ast::ZapExpression> right =
            std::any_cast<std::shared_ptr<ast::ZapExpression>>(
                visitUnary(ctx->unary()[i]));
        left = std::make_shared<ast::ZapExpression>(ast::ZapExpression{
            .kind  = ast::ZapExpressionKind::Binary,
            .value = ast::ZapBinaryExpression{
                .left  = left,
                .right = right,
                .op    = get_factory_op(ctx->op[i - 1]->getType())}});
    }
    return left;
}

std::any ASTVisitor::visitUnary(zapParser::UnaryContext* ctx) {
    if (ctx->call()) {
        return visitCall(ctx->call());
    }
    if (ctx->unary()) {
        std::shared_ptr<ast::ZapExpression> unary =
            std::any_cast<std::shared_ptr<ast::ZapExpression>>(
                visitUnary(ctx->unary()));
        return std::make_shared<ast::ZapExpression>(
            ast::ZapExpression{.kind  = ast::ZapExpressionKind::Unary,
                               .value = ast::ZapUnaryExpression{
                                   .op    = ctx->op->getType() == zapParser::NOT
                                                ? ast::BinaryOp::NOT
                                                : ast::BinaryOp::NEGATIVE,
                                   .unary = unary,
                               }});
    }
    return std::make_shared<ast::ZapExpression>();
}

std::any ASTVisitor::visitCall(zapParser::CallContext* ctx) {
    std::shared_ptr<ast::ZapExpression> primary =
        std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitPrimary(ctx->primary()));

    // Check if this is a function call by looking for parentheses in the parse tree
    bool has_parentheses = false;
    for (auto child : ctx->children) {
        if (child->getText() == "(") {
            has_parentheses = true;
            break;
        }
    }

    // Handle member access (with or without function call)
    if (!ctx->IDENTIFIER().empty()) {
        ast::LiteralString f_name =
            std::get<ast::LiteralString>(primary->value);

        if (has_parentheses) {
            // Member access + function call: obj.method()
            std::vector<std::shared_ptr<ast::ZapExpression>> args;
            if (!ctx->argumentList().empty()) {
                args = std::any_cast<
                    std::vector<std::shared_ptr<ast::ZapExpression>>>(
                    visitArgumentList(ctx->argumentList()[0]));
            }

            return std::make_shared<ast::ZapExpression>(ast::ZapExpression{
                .kind  = ast::ZapExpressionKind::Call,
                .value = ast::ZapCallExpression{
                    .function = f_name + "." + ctx->IDENTIFIER(0)->getText(),
                    .args     = args}});
        } else {
            // Just member access: obj.property
            return std::make_shared<ast::ZapExpression>(ast::ZapExpression{
                .kind  = ast::ZapExpressionKind::StructAccess,
                .value = ast::ZapStructAccessExpression{
                    .type = f_name, .field = ctx->IDENTIFIER(0)->getText()}});
        }
    }

    if (has_parentheses) {
        // Simple function call: func()
        ast::LiteralString f_name =
            std::get<ast::LiteralString>(primary->value);
        std::vector<std::shared_ptr<ast::ZapExpression>> args;
        if (!ctx->argumentList().empty()) {
            args =
                std::any_cast<std::vector<std::shared_ptr<ast::ZapExpression>>>(
                    visitArgumentList(ctx->argumentList()[0]));
        }

        return std::make_shared<ast::ZapExpression>(ast::ZapExpression{
            .kind  = ast::ZapExpressionKind::Call,
            .value = ast::ZapCallExpression{.function = f_name, .args = args}});
    }

    // No parentheses, no member access - return bare identifier
    return primary;
}

std::any ASTVisitor::visitArgumentList(zapParser::ArgumentListContext* ctx) {
    std::vector<std::shared_ptr<ast::ZapExpression>> args;
    for (zapParser::ExpressionContext* expression_ctx : ctx->expression()) {
        args.push_back(std::any_cast<std::shared_ptr<ast::ZapExpression>>(
            visitExpression(expression_ctx)));
    }
    return args;
}

std::any ASTVisitor::visitPrimary(zapParser::PrimaryContext* ctx) {
    if (ctx->expression()) {
        return visitExpression(ctx->expression());
    }
    if (ctx->lvalue()) {
        return visitLvalue(ctx->lvalue());
    }
    if (ctx->IDENTIFIER()) {
        return std::make_shared<ast::ZapExpression>(
            ast::ZapExpression{.kind  = ast::ZapExpressionKind::Identifier,
                               .value = ctx->IDENTIFIER()->getText()});
    }
    if (ctx->INT()) {
        return std::make_shared<ast::ZapExpression>(ast::ZapExpression{
            .kind  = ast::ZapExpressionKind::Literal,
            .value = ast::ZapLiteral{
                .value = ast::LiteralInt{std::stoi(ctx->INT()->getText())}}});
    }
    if (ctx->FLOAT()) {
        return std::make_shared<ast::ZapExpression>(ast::ZapExpression{
            .kind  = ast::ZapExpressionKind::Literal,
            .value = ast::ZapLiteral{.value = ast::LiteralDouble{
                                         std::stod(ctx->FLOAT()->getText())}}});
    }
    if (ctx->BOOL()) {
        return std::make_shared<ast::ZapExpression>(ast::ZapExpression{
            .kind  = ast::ZapExpressionKind::Literal,
            .value = ast::ZapLiteral{
                .value = ast::LiteralBool(ctx->BOOL()->getText() == "true")}});
    }
    if (ctx->STRING()) {
        return std::make_shared<ast::ZapExpression>(ast::ZapExpression{
            .kind  = ast::ZapExpressionKind::Literal,
            .value = ast::ZapLiteral{
                .value = ast::LiteralString{ctx->STRING()->getText()}}});
    }
    return std::make_shared<ast::ZapExpression>();
}

std::any ASTVisitor::visitAotBlock(zapParser::AotBlockContext* ctx) {
    return std::make_shared<ast::ZapExpression>(ast::ZapExpression{
        .kind  = ast::ZapExpressionKind::AOTBlock,
        .value = ast::ZapAOTBlock{
            .statements = std::any_cast<std::vector<ast::ZapStatement>>(
                visitBlock(ctx->block()))}});
}

std::any ASTVisitor::visitAttributeList(zapParser::AttributeListContext* ctx) {
    std::vector<ast::ZapAttribute> attributes;
    if (!ctx) {
        std::cerr << "Context is null" << std::endl;
        return attributes;
    }
    for (zapParser::AttributeContext* attribute_ctx : ctx->attribute()) {
        attributes.push_back(
            std::any_cast<ast::ZapAttribute>(visitAttribute(attribute_ctx)));
    }
    return attributes;
}

std::any ASTVisitor::visitAttribute(zapParser::AttributeContext* ctx) {
    return ast::ZapAttribute{.name = ctx->IDENTIFIER()->getText(),
                             .args = std::any_cast<std::vector<std::string>>(
                                 visitAttributeArgs(ctx->attributeArgs()))};
}

std::any ASTVisitor::visitAttributeArg(zapParser::AttributeArgContext* ctx) {
    if (ctx->IDENTIFIER()) {
        return ctx->IDENTIFIER()->getText();
    } else if (ctx->STRING()) {
        return ctx->STRING()->getText();
    } else if (ctx->INT()) {
        return ctx->INT()->getText();
    }
    // Return non sense value that is not a string so that a runtime error is thrown
    return 0;
}

std::any ASTVisitor::visitAttributeArgs(zapParser::AttributeArgsContext* ctx) {
    if (!ctx) {
        return std::vector<std::string>{};
    }
    std::vector<std::string> args;
    for (zapParser::AttributeArgContext* arg : ctx->attributeArg()) {
        args.push_back(std::any_cast<std::string>(visitAttributeArg(arg)));
    }
    return args;
}

std::any ASTVisitor::visitParameter(zapParser::ParameterContext* ctx) {
    ast::ZapType base_type =
        std::any_cast<ast::ZapType>(visitType(ctx->type()));

    // Check if this is a REF type
    if (ctx->REF()) {
        ast::ZapType ref_type{
            .kind        = ast::ZapTypeKind::REF,
            .custom_name = "",
            .inner       = std::make_shared<ast::ZapType>(base_type)};
        return ast::ZapParam{.name = ctx->IDENTIFIER()->getText(),
                             .type = ref_type};
    }

    return ast::ZapParam{.name = ctx->IDENTIFIER()->getText(),
                         .type = base_type};
}

std::any ASTVisitor::visitParameterList(zapParser::ParameterListContext* ctx) {
    if (!ctx) {
        return std::vector<ast::ZapParam>{};
    }
    std::vector<ast::ZapParam> params;
    for (zapParser::ParameterContext* parameter : ctx->parameter()) {
        params.push_back(
            std::any_cast<ast::ZapParam>(visitParameter(parameter)));
    }
    return params;
}

std::any ASTVisitor::visitReturnType(zapParser::ReturnTypeContext* ctx) {
    return visitType(ctx->type());
}

ast::ZapTypeKind from_string(const std::string& type) {
    if (type == "u8") {
        return ast::ZapTypeKind::U8;
    } else if (type == "u16") {
        return ast::ZapTypeKind::U16;
    } else if (type == "u32") {
        return ast::ZapTypeKind::U32;
    } else if (type == "u64") {
        return ast::ZapTypeKind::U64;
    } else if (type == "f32") {
        return ast::ZapTypeKind::F32;
    } else if (type == "f64") {
        return ast::ZapTypeKind::F64;
    } else if (type == "i16") {
        return ast::ZapTypeKind::I16;
    } else if (type == "i32") {
        return ast::ZapTypeKind::I32;
    } else if (type == "i64") {
        return ast::ZapTypeKind::I64;
    } else if (type == "bool") {
        return ast::ZapTypeKind::BOOL;
    } else if (type == "str") {
        return ast::ZapTypeKind::STRING;
    }
    return ast::ZapTypeKind::CUSTOM;
}

bool is_array(zapParser::TypeContext* ctx) {
    int amount_of_children = ctx->children.size();
    if (amount_of_children >= 2) {
        antlr4::tree::ParseTree* left_bracket =
            ctx->children[amount_of_children - 2];
        antlr4::tree::ParseTree* right_bracket =
            ctx->children[amount_of_children - 1];

        return left_bracket->getText() == "[" &&
               right_bracket->getText() == "]";
    }
    return false;
}

ast::ZapTypeKind get_type_kind(zapParser::TypeContext* ctx) {
    bool is_void = ctx->VOID();
    if (is_void) {
        return ast::ZapTypeKind::VOID;
    }
    if (is_array(ctx)) {
        return ast::ZapTypeKind::ARRAY;
    }
    return from_string(ctx->IDENTIFIER()->getText());
}

std::any ASTVisitor::visitType(zapParser::TypeContext* ctx) {
    ast::ZapTypeKind kind = get_type_kind(ctx);
    ast::ZapType type{.kind = kind, .custom_name = "", .inner = nullptr};

    if (kind == ast::ZapTypeKind::CUSTOM) {
        type.custom_name = ctx->IDENTIFIER()->getText();
    } else if (kind == ast::ZapTypeKind::ARRAY) {
        // For arrays, create inner type without the array brackets
        // This is a simplified implementation - we'd need to parse the inner type properly
        type.inner       = std::make_shared<ast::ZapType>();
        type.inner->kind = from_string(ctx->IDENTIFIER()->getText());
        if (type.inner->kind == ast::ZapTypeKind::CUSTOM) {
            type.inner->custom_name = ctx->IDENTIFIER()->getText();
        }
    }

    return type;
}

std::any ASTVisitor::visitBlock(zapParser::BlockContext* ctx) {
    std::vector<ast::ZapStatement> statements;
    for (zapParser::StatementContext* statement_ctx : ctx->statement()) {
        statements.push_back(
            std::any_cast<ast::ZapStatement>(visitStatement(statement_ctx)));
    }
    return statements;
}

std::any ASTVisitor::visitDeclaration(zapParser::DeclarationContext* ctx) {
    ZAP_LOG_INFO("[ASTVisitor] Enter visitDeclaration");
    if (ctx->functionDecl()) {
        ast::ZapFunction func = std::any_cast<ast::ZapFunction>(
            visitFunctionDecl(ctx->functionDecl()));
        ZAP_LOG_INFO("[ASTVisitor] Returning Function decl");
        return ast::ZapDecl{.kind = ast::ZapDeclKind::Function, .value = func};
    }
    if (ctx->structDecl()) {
        ast::ZapStruct zap_struct =
            std::any_cast<ast::ZapStruct>(visitStructDecl(ctx->structDecl()));
        ZAP_LOG_INFO("[ASTVisitor] Returning Struct decl");
        return ast::ZapDecl{.kind  = ast::ZapDeclKind::Struct,
                            .value = zap_struct};
    }
    if (ctx->componentDecl()) {
        ast::ZapComponent component = std::any_cast<ast::ZapComponent>(
            visitComponentDecl(ctx->componentDecl()));
        ZAP_LOG_INFO("[ASTVisitor] Returning Component decl");
        return ast::ZapDecl{.kind  = ast::ZapDeclKind::Component,
                            .value = component};
    }
    // Modules not implemented yet
    ZAP_LOG_INFO("[ASTVisitor] Returning empty decl (not implemented)");
    return {};
}

std::any ASTVisitor::visitStatement(zapParser::StatementContext* ctx) {
    if (ctx->variableDecl()) {
        ast::ZapLetStatement statement = std::any_cast<ast::ZapLetStatement>(
            visitVariableDecl(ctx->variableDecl()));
        return ast::ZapStatement{.kind  = ast::ZapStatementKind::Let,
                                 .value = statement};
    }
    if (ctx->expressionStmt()) {
        std::shared_ptr<ast::ZapExpression> expression =
            std::any_cast<std::shared_ptr<ast::ZapExpression>>(
                visitExpression(ctx->expressionStmt()->expression()));
        return ast::ZapStatement{.kind  = ast::ZapStatementKind::Expression,
                                 .value = expression};
    }
    if (ctx->block()) {
        std::vector<ast::ZapStatement> block =
            std::any_cast<std::vector<ast::ZapStatement>>(
                visitBlock(ctx->block()));
        return ast::ZapStatement{
            .kind  = ast::ZapStatementKind::Block,
            .value = ast::ZapBlockStatement{.statements = block}};
    }
    if (ctx->ifStmt()) {
        ast::ZapIfStatement statement =
            std::any_cast<ast::ZapIfStatement>(visitIfStmt(ctx->ifStmt()));
        return ast::ZapStatement{.kind  = ast::ZapStatementKind::If,
                                 .value = statement};
    }
    if (ctx->whileStmt()) {
        ast::ZapWhileStatement statement =
            std::any_cast<ast::ZapWhileStatement>(
                visitWhileStmt(ctx->whileStmt()));
        return ast::ZapStatement{.kind  = ast::ZapStatementKind::While,
                                 .value = statement};
    }
    if (ctx->forStmt()) {
        ast::ZapForStatement statement =
            std::any_cast<ast::ZapForStatement>(visitForStmt(ctx->forStmt()));
        return ast::ZapStatement{.kind  = ast::ZapStatementKind::For,
                                 .value = statement};
    }
    if (ctx->returnStmt()) {
        ast::ZapReturnStatement statement =
            std::any_cast<ast::ZapReturnStatement>(
                visitReturnStmt(ctx->returnStmt()));
        return ast::ZapStatement{.kind  = ast::ZapStatementKind::Return,
                                 .value = statement};
    }
    if (ctx->yieldStmt()) {
        ast::ZapReturnStatement statement =
            std::any_cast<ast::ZapReturnStatement>(
                visitYieldStmt(ctx->yieldStmt()));
        return ast::ZapStatement{.kind  = ast::ZapStatementKind::Return,
                                 .value = statement};
    }
    if (ctx->deferStmt()) {
        ast::ZapDeferStatement statement =
            std::any_cast<ast::ZapDeferStatement>(
                visitDeferStmt(ctx->deferStmt()));
        return ast::ZapStatement{.kind  = ast::ZapStatementKind::Defer,
                                 .value = statement};
    }
    return ast::ZapStatement{
        .kind  = ast::ZapStatementKind::Expression,
        .value = std::make_shared<ast::ZapExpression>(ast::ZapExpression{
            .kind  = ast::ZapExpressionKind::Literal,
            .value = ast::ZapLiteral{.value = ast::LiteralInt(0)}})};
}
