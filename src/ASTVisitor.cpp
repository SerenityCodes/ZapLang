#include "ASTVisitor.h"
#include "antlr/zapParser.h"
#include "ast/ast.h"

std::any ASTVisitor::visitFunctionDecl(zapParser::FunctionDeclContext* ctx) {
    auto [function_body, symbol_table] = std::any_cast<std::pair<std::vector<ast::ZapStatement>, ast::SymbolTable>>(visitBlock(ctx->block()));
    return ast::ZapFunction{
        .name = ctx->IDENTIFIER()->getText(),
        .attributes = std::any_cast<std::vector<ast::ZapAttribute>>(visitAttributeList(ctx->attributeBlock()->attributeList())),
        .params = std::any_cast<std::vector<ast::ZapParam>>(visitParameterList(ctx->parameterList())),
        .return_type = std::any_cast<ast::ZapType>(visitReturnType(ctx->returnType())),
        .symbol_table = symbol_table,
        .body = function_body,
    };
}

std::any ASTVisitor::visitAttributeList(zapParser::AttributeListContext* ctx) {
    std::vector<ast::ZapAttribute> attributes;
    for (zapParser::AttributeContext* attribute_ctx : ctx->attribute()) {
        ast::ZapAttribute attribute{
            .name = attribute_ctx->IDENTIFIER()->getText(),
            .args = std::any_cast<std::unordered_map<std::string, std::string>>(visitAttributeArgs(attribute_ctx->attributeArgs()))
        };
        attributes.push_back(attribute);
    }
    return attributes;
}

std::any ASTVisitor::visitAttributeArgs(zapParser::AttributeArgsContext* ctx) {
    return std::unordered_map<std::string, std::string>{};
}

std::any ASTVisitor::visitParameterList(zapParser::ParameterListContext* ctx) {
    std::vector<ast::ZapParam> params;
    if (!ctx) {
        return {};
    }
    for (zapParser::ParameterContext* parameter : ctx->parameter()) {
        ast::ZapType zap_type = std::any_cast<ast::ZapType>(visitType(parameter->type()));
        ast::ZapParam param{.name = parameter->IDENTIFIER()->getText(), .type = zap_type};
        params.push_back(param);
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
    } else if (type == "str") {
        return ast::ZapTypeKind::STRING;
    }
    return ast::ZapTypeKind::CUSTOM;
}

bool is_array(zapParser::TypeContext* ctx) {
    int amount_of_children = ctx->children.size();
    if (amount_of_children >= 2) {
        antlr4::tree::ParseTree* left_bracket = ctx->children[amount_of_children - 2];
        antlr4::tree::ParseTree* right_bracket = ctx->children[amount_of_children - 1];
        
        return left_bracket->getText() == "[" && right_bracket->getText() == "]";
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
    // Ignoring generic types for now
    ast::ZapTypeKind kind = get_type_kind(ctx);
    ast::ZapType type{
        .kind = kind,
        .custom_name = std::make_unique<ast::ZapIdentifier>(),
        .inner = std::make_unique<ast::ZapType>()
    };
    
    return type;
}

ast::SymbolTable create_symbol_table(zapParser::BlockContext* ctx) {
    return {};
}

std::vector<ast::ZapStatement> create_statements(zapParser::BlockContext* ctx) {
    return {}; 
}

std::any ASTVisitor::visitBlock(zapParser::BlockContext* ctx) {
    return std::make_pair(create_statements(ctx), create_symbol_table(ctx));
}
