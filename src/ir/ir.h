#pragma once
#include <optional>
#include <string>
#include <vector>

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

struct ZapStatement {
    std::string result;
    OpCode op;
    std::vector<std::string> arg_list;
};

using ZapBlock = std::vector<ZapStatement>;

struct ZapFunction {
    std::vector<ZapBlock> blocks;
};

struct ZapProgram {
    std::vector<>
};

}  // namespace ir
