#pragma once
#include <iostream>
#include "ast.h"

namespace ast {

class ZapPrettyPrinter {
public:
    explicit ZapPrettyPrinter(std::ostream& out);

    void print(const ZapProgram& program);

private:
    std::ostream& out;
    int indent_level = 0;

    void indent();
    void printIndent();
    void print(const ZapDecl& decl);
    void print(const ZapFunction& func);
    void print(const ZapComponent& comp);
    void print(const ZapStruct& strct);
    void print(const ZapStatement& stmt);
    void print(const ZapExpression& expr);
    void print(const ZapLetStatement& let);
    void print(const ZapAssignStatement& assign);
    void print(const ZapIfStatement& ifstmt);
    void print(const ZapForStatement& forstmt);
    void print(const ZapReturnStatement& retstmt);
    void print(const ZapDeferStatement& deferstmt);
    void print(const ZapType& type);
    void printTypeKind(ZapTypeKind kind);
    void printBinaryOp(BinaryOp op);
    void printUnaryOp(BinaryOp op);
};

}  // namespace ast

