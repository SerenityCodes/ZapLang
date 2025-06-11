#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

namespace ast {

// === Identifiers and Types ===

using ZapIdentifier = std::string;

using LiteralInt    = int;
using LiteralFloat  = float;
using LiteralDouble = double;
using LiteralString = std::string;

enum ZapTypeKind {
    U8,
    U16,
    U32,
    U64,
    I16,
    I32,
    I64,
    F32,
    F64,
    BOOL,
    STRING,
    CUSTOM,
    ARRAY,
    REF,
    VOID
};

struct ZapType {
    ZapTypeKind kind;
    std::shared_ptr<ZapIdentifier> custom_name;  // for CUSTOM
    std::shared_ptr<ZapType> inner;              // for ARRAY or REF types
};

// === Expressionessions ===
enum class ZapExpressionKind {
    Literal,
    Identifier,
    Binary,
    Call,
    AOTBlock,
    StructInit
};

struct ZapLiteral {
    std::variant<LiteralInt, LiteralFloat, LiteralDouble, LiteralString> value;
};

struct ZapBinaryExpression {
    std::shared_ptr<struct ZapExpression> left;
    std::shared_ptr<struct ZapExpression> right;
    std::string op;
};

struct ZapCallExpression {
    ZapIdentifier function;
    std::vector<std::shared_ptr<struct ZapExpression>> args;
};

struct ZapAOTBlock {
    std::vector<struct ZapStatement> statements;
    std::shared_ptr<struct ZapExpression> yield_expr;
};

struct ZapStructFieldInit {
    ZapIdentifier field;
    std::shared_ptr<struct ZapExpression> value;
};

struct ZapStructInitExpression {
    ZapIdentifier type_name;
    std::vector<ZapStructFieldInit> fields;
};

struct ZapExpression {
    ZapExpressionKind kind;
    std::variant<ZapLiteral, ZapIdentifier, ZapBinaryExpression,
                 ZapCallExpression, ZapAOTBlock, ZapStructInitExpression>
        value;
};

// === Statements ===
enum class ZapStatementKind { Let, Assign, Expression, If, For, Return, Defer };

struct ZapLetStatement {
    ZapIdentifier name;
    ZapType type;
    std::shared_ptr<ZapExpression> value;
};

struct ZapAssignStatement {
    std::shared_ptr<ZapExpression> target;
    std::shared_ptr<ZapExpression> value;
};

struct ZapIfStatement {
    std::shared_ptr<ZapExpression> condition;
    std::vector<struct ZapStatement> then_block;
    std::vector<struct ZapStatement> else_block;
};

struct ZapForStatement {
    ZapIdentifier var;
    std::shared_ptr<ZapExpression> start;
    std::shared_ptr<ZapExpression> condition;
    std::shared_ptr<ZapExpression> step;
    std::vector<struct ZapStatement> body;
};

struct ZapReturnStatement {
    std::shared_ptr<ZapExpression> value;
};

struct ZapDeferStatement {
    std::shared_ptr<ZapExpression> expr;
};

struct ZapStatement {
    ZapStatementKind kind;
    std::variant<ZapLetStatement, ZapAssignStatement,
                 std::shared_ptr<ZapExpression>, ZapIfStatement,
                 ZapForStatement, ZapReturnStatement, ZapDeferStatement>
        value;
};

// === Functions, Structs, Components ===
struct ZapParam {
    ZapIdentifier name;
    ZapType type;
};

struct ZapAttribute {
    std::string name;
    std::unordered_map<std::string, std::string> args;
};

struct ZapFunction {
    ZapIdentifier name;
    std::vector<ZapAttribute> attributes;
    std::vector<ZapParam> params;
    ZapType return_type;
    std::unordered_map<std::string, ZapType> symbol_table;
    std::vector<ZapStatement> body;
};

struct ZapField {
    ZapIdentifier name;
    ZapType type;
};

struct ZapComponent {
    ZapIdentifier name;
    std::vector<ZapField> fields;
    bool is_readonly;
};

struct ZapStruct {
    ZapIdentifier name;
    std::vector<ZapField> fields;
};

// === Top-Level Program ===
enum class ZapDeclKind { Function, Component, Struct };

struct ZapDecl {
    ZapDeclKind kind;
    std::variant<ZapFunction, ZapComponent, ZapStruct> value;
};

using SymbolTable = std::unordered_map<std::string, ast::ZapType>;

struct ZapSymbolTable {
    std::unordered_map<std::string, ZapComponent> component_map;
    std::unordered_map<std::string, ZapStruct> struct_map;
};

struct ZapProgram {
    ZapSymbolTable class_symbol_table;
    std::vector<ZapDecl> declarations;
};

}  // namespace ast
