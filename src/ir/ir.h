#pragma once

#include <memory>
#include <string>
#include <vector>
#include "ast/ast.h"

namespace ir {

enum OpCode {
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    EQ,
    NE,
    LT,
    LE,
    GT,
    GE,
    AND,
    OR,
    NOT,
    ALLOCA,
    LOAD,
    STORE,
    ARENA_ALLOC,
    ARENA_CLEAR,
    ARENA_DEALLOC,
    JMP,
    BR,
    RET,
    CALL,
    COMPONENT_LOAD,
    COMPONENT_STORE,
    ENTITY_GET,
    STRUCT_GET,
    STRUCT_SET,
    CAST
};

struct IRStatement {
    std::string result;
    OpCode op;
    std::vector<std::string> arg_list;
};

struct IRBlock {
    std::string name;
    std::vector<IRStatement> statements;
};

struct IRLoop {
    std::vector<IRStatement> condition;
    IRBlock block;
};

struct IRFunction {
    std::string name;
    ast::ZapType return_type;
    std::vector<ast::ZapField> args;
    std::vector<IRBlock> blocks;
};

struct IRStruct {
    std::string name;
    std::vector<ast::ZapField> fields;
    bool is_component;
};

struct IRProgram {
    std::vector<IRFunction> functions;
};


class IRVisitor {
    IRProgram generate(ast::ZapProgram& ast_program);
    IRFunction generate(const ast::ZapFunction& func);
    IRStruct generate(const ast::ZapComponent& comp);
    IRStruct generate(const ast::ZapStruct& strct);
    std::vector<IRBlock> generate(const ast::ZapStatement& statement);
    std::vector<IRBlock> generate(const ast::ZapExpression& expression);
    std::vector<IRStatement> generate(
        const ast::ZapLetStatement& let_statement);
    std::vector<IRStatement> generate(
        const ast::ZapAssignStatement& assign_statement);
    std::vector<IRBlock> generate(const ast::ZapIfStatement& if_statement);
    IRLoop generate(const ast::ZapForStatement& for_statement);
    IRLoop generate(const ast::ZapWhileStatement& while_statement);
    std::vector<IRStatement> generate(const ast::ZapReturnStatement& ret_statement);
    std::vector<IRStatement> generate(const ast::ZapDeferStatement& defer_statement);
    void generate(const ast::ZapType& type);
    void generate(ast::ZapTypeKind kind);
    void generate_binary_op(ast::BinaryOp op);
    void generate_unary_op(ast::BinaryOp op);
};

}  // namespace ir
