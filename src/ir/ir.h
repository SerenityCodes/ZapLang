#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include "ast/ast.h"
#include "common.h"

namespace ir {

enum OpCode {
    ADDR,
    MOV,
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
    CAST,
    PHI
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

struct IRFunction {
    std::string name;
    ast::ZapType return_type;
    std::vector<ast::ZapParam> args;
    std::vector<IRBlock> blocks;
};

struct IRStruct {
    std::string name;
    std::vector<ast::ZapField> fields;
    bool is_component;
};

struct IRProgram {
    std::vector<IRStruct> structs;
    std::vector<IRFunction> functions;
};

class IRVisitor {
   private:
    u32 unique_num = 0;
    std::unordered_map<std::string, u32> string_table;

    std::string get_temp() { return "tmp_" + std::to_string(unique_num++); }

    // Track variable definitions for PHI node generation
    struct BlockVariableState {
        std::unordered_map<std::string, std::string> var_map;
        std::string block_name;
        std::vector<std::string> predecessors;
    };

   public:
    // Generate the full IR program from an AST program
    IRProgram generate(const ast::ZapProgram& ast_program);

    // Generate IR for a function
    IRFunction generate(const ast::ZapFunction& func);

    // Generate IR for a component
    IRStruct generate(const ast::ZapComponent& comp);

    // Generate IR for a struct
    IRStruct generate(const ast::ZapStruct& strct);

    // Generate IR blocks for a statement (output parameter)
    void generate(const ast::ZapStatement& statement,
                  std::vector<IRBlock>& blocks,
                  std::unordered_map<std::string, std::string>& var_map);

    // Generate IR statements for an expression (output parameter)
    void generate(const ast::ZapExpression& expression,
                  std::vector<IRStatement>& statements);
    void generate(const ast::ZapExpression& expression,
                  std::vector<IRStatement>& statements,
                  std::unordered_map<std::string, std::string>& var_map);

    // Generate IR statements for let, assign, return, defer (output parameter)
    void generate(const ast::ZapLetStatement& let_statement,
                  std::vector<IRStatement>& statements,
                  std::unordered_map<std::string, std::string>& var_map);
    void generate(const ast::ZapAssignStatement& assign_statement,
                  std::vector<IRStatement>& statements,
                  std::unordered_map<std::string, std::string>& var_map);
    void generate(const ast::ZapIfStatement& if_statement,
                  std::vector<IRBlock>& blocks,
                  std::unordered_map<std::string, std::string>& var_map);
    void generate(const ast::ZapForStatement& for_statement,
                  std::vector<IRBlock>& blocks,
                  std::unordered_map<std::string, std::string>& var_map);
    void generate(const ast::ZapWhileStatement& while_statement,
                  std::vector<IRBlock>& blocks,
                  std::unordered_map<std::string, std::string>& var_map);
    void generate(const ast::ZapReturnStatement& ret_statement,
                  std::vector<IRStatement>& statements,
                  std::unordered_map<std::string, std::string>& var_map);
    void generate(const ast::ZapDeferStatement& defer_statement,
                  std::vector<IRBlock>& blocks,
                  std::unordered_map<std::string, std::string>& var_map);

    // Helper method for generating phi nodes
    void generate_phi_nodes(
        IRBlock& merge_block,
        const std::vector<std::pair<
            std::string, std::unordered_map<std::string, std::string>>>&
            incoming_blocks,
        std::unordered_map<std::string, std::string>& merge_var_map);
};

class IRPrettyPrinter {
   public:
    void print(const IRProgram& program) const;
    void print(const IRFunction& function, int indent = 0) const;
    void print(const IRBlock& block, int indent = 0) const;
    void print(const IRStatement& stmt, int indent = 0) const;
    void print(const IRStruct& strct, int indent = 0) const;
};

}  // namespace ir
