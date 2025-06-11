#pragma once
#include "ast.h"
#include <iostream>

namespace ast {

class ASTPrinter {
public:
    static void print(const ZapProgram& program, std::ostream& out = std::cout);

private:
    static void indent(std::ostream& out, int level);
    static void print_type(const ZapType& type, std::ostream& out, int level);
    static void print_expr(const ZapExpression& expr, std::ostream& out, int level);
    static void print_stmt(const ZapStatement& stmt, std::ostream& out, int level);
    static void print_decl(const ZapDecl& decl, std::ostream& out, int level);
    static void print_function(const ZapFunction& func, std::ostream& out, int level);
    static void print_struct(const ZapStruct& strct, std::ostream& out, int level);
    static void print_component(const ZapComponent& comp, std::ostream& out, int level);
};

}  // namespace ast

