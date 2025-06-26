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
    ZapIdentifier custom_name;  // for CUSTOM
    std::shared_ptr<ZapType> inner;              // for ARRAY or REF types

    std::string to_string() const {
        switch (kind) {
            case U8:
                return "u8";
            case U16:
                return "u16";
            case U32:
                return "u32";
            case U64:
                return "u64";
            case I16:
                return "i16";
            case I32:
                return "i32";
            case I64:
                return "i64";
            case F32:
                return "f32";
            case F64:
                return "f64";
            case BOOL:
                return "bool";
            case STRING:
                return "string";
            case VOID:
                return "void";
            case CUSTOM:
                    return custom_name;
                break;
            case ARRAY:
                if (inner)
                    return inner->to_string() + "[]";
                break;
            case REF:
                if (inner)
                    return "ref " + inner->to_string();
                break;
            default:
                return "unknown";
        }
        return "invalid_type";
    }
};

// === Expressionessions ===
enum class ZapExpressionKind {
    Literal,
    Identifier,
    Binary,
    Unary,
    Call,
    AOTBlock,
    StructInit,
    StructAccess
};

enum BinaryOp {
    ASSIGNMENT,
    OR,
    AND,
    EQUAL,
    NOT_EQUAL,
    LESS_THAN,
    LESS_THAN_OR_EQUAL,
    GREATER_THAN,
    GREATER_THAN_OR_EQUAL,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MOD,
    NOT,
    NEGATIVE
};

struct ZapLiteral {
    std::variant<LiteralInt, LiteralFloat, LiteralDouble, LiteralString> value;
};

struct ZapBinaryExpression {
    std::shared_ptr<struct ZapExpression> left;
    std::shared_ptr<struct ZapExpression> right;
    BinaryOp op;
};

struct ZapUnaryExpression {
    BinaryOp op;
    std::shared_ptr<struct ZapExpression> unary;
};

struct ZapCallExpression {
    ZapIdentifier function;
    std::vector<std::shared_ptr<struct ZapExpression>> args;
};

struct ZapAOTBlock {
    std::vector<struct ZapStatement> statements;
};

struct ZapStructFieldInit {
    ZapIdentifier field;
    std::shared_ptr<struct ZapExpression> value;
};

struct ZapStructAccessExpression {
    ZapIdentifier type;
    ZapIdentifier field;
};

struct ZapStructInitExpression {
    ZapIdentifier type_name;
    std::vector<ZapStructFieldInit> fields;
};

struct ZapExpression {
    ZapExpressionKind kind;
    std::variant<ZapLiteral, ZapIdentifier, ZapBinaryExpression,
                 ZapUnaryExpression, ZapCallExpression, ZapAOTBlock,
                 ZapStructInitExpression, ZapStructAccessExpression>
        value;
};

// === Statements ===
enum class ZapStatementKind {
    Let,
    Assign,
    Expression,
    If,
    For,
    While,
    Return,
    Defer,
    Block
};

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
    std::vector<ZapStatement> then_block;
    std::vector<ZapStatement> else_block;
};

struct ZapForStatement {
    ZapLetStatement start;
    std::shared_ptr<ZapExpression> condition;
    std::shared_ptr<ZapExpression> step;
    std::vector<ZapStatement> body;
};

struct ZapWhileStatement {
    std::shared_ptr<ZapExpression> condition;
    std::vector<ZapStatement> body;
};

struct ZapReturnStatement {
    std::shared_ptr<ZapExpression> value;
};

struct ZapDeferStatement {
    bool is_body;
    std::shared_ptr<ZapExpression> expr;
    std::vector<ZapStatement> body;
};

struct ZapBlockStatement {
    std::vector<ZapStatement> statements;
};

struct ZapStatement {
    ZapStatementKind kind;
    std::variant<ZapLetStatement, ZapAssignStatement,
                 std::shared_ptr<ZapExpression>, ZapIfStatement,
                 ZapForStatement, ZapWhileStatement, ZapReturnStatement,
                 ZapDeferStatement, ZapBlockStatement>
        value;
};

// === Functions, Structs, Components ===
struct ZapParam {
    ZapIdentifier name;
    ZapType type;
};

struct ZapAttribute {
    std::string name;
    std::vector<std::string> args;
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
