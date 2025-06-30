#pragma once

#include <any>
#include "antlr/zapParser.h"
#include "antlr/zapVisitor.h"
#include "antlr/zapBaseVisitor.h"

/**
 * This class provides an empty implementation of zapVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class ASTVisitor : public zapBaseVisitor {
   public:
    virtual std::any visitProgram(zapParser::ProgramContext *ctx) override;

    virtual std::any visitStatement(zapParser::StatementContext *ctx) override;

    virtual std::any visitDeclaration(
        zapParser::DeclarationContext *ctx) override;

    virtual std::any visitFunctionDecl(
        zapParser::FunctionDeclContext *ctx) override;

    virtual std::any visitAttributeBlock(
        zapParser::AttributeBlockContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitAttributeList(
        zapParser::AttributeListContext *ctx) override;

    virtual std::any visitAttributeArgs(
        zapParser::AttributeArgsContext *ctx) override;

    virtual std::any visitAttributeArg(
        zapParser::AttributeArgContext *ctx) override;

    virtual std::any visitAttribute(zapParser::AttributeContext *ctx) override;

    virtual std::any visitReturnType(
        zapParser::ReturnTypeContext *ctx) override;

    virtual std::any visitParameterList(
        zapParser::ParameterListContext *ctx) override;

    virtual std::any visitParameter(zapParser::ParameterContext *ctx) override;

    virtual std::any visitType(zapParser::TypeContext *ctx) override;

    virtual std::any visitStructDecl(
        zapParser::StructDeclContext *ctx) override;

    virtual std::any visitStructField(
        zapParser::StructFieldContext *ctx) override;

    virtual std::any visitComponentDecl(
        zapParser::ComponentDeclContext *ctx) override;

    virtual std::any visitModuleDecl(
        zapParser::ModuleDeclContext *ctx) override;

    virtual std::any visitBlock(zapParser::BlockContext *ctx) override;

    virtual std::any visitVariableDecl(
        zapParser::VariableDeclContext *ctx) override;

    virtual std::any visitIfStmt(zapParser::IfStmtContext *ctx) override;

    virtual std::any visitWhileStmt(zapParser::WhileStmtContext *ctx) override;

    virtual std::any visitForStmt(zapParser::ForStmtContext *ctx) override;

    virtual std::any visitReturnStmt(
        zapParser::ReturnStmtContext *ctx) override;

    virtual std::any visitYieldStmt(zapParser::YieldStmtContext *ctx) override;

    virtual std::any visitDeferStmt(zapParser::DeferStmtContext *ctx) override;

    virtual std::any visitExpressionStmt(
        zapParser::ExpressionStmtContext *ctx) override;

    virtual std::any visitExpression(
        zapParser::ExpressionContext *ctx) override;

    virtual std::any visitLvalue(zapParser::LvalueContext* ctx) override;

    virtual std::any visitAssignment(
        zapParser::AssignmentContext *ctx) override;

    virtual std::any visitLogicOr(zapParser::LogicOrContext *ctx) override;

    virtual std::any visitLogicAnd(zapParser::LogicAndContext *ctx) override;

    virtual std::any visitEquality(zapParser::EqualityContext *ctx) override;

    virtual std::any visitComparison(
        zapParser::ComparisonContext *ctx) override;

    virtual std::any visitTerm(zapParser::TermContext *ctx) override;

    virtual std::any visitFactor(zapParser::FactorContext *ctx) override;

    virtual std::any visitUnary(zapParser::UnaryContext *ctx) override;

    virtual std::any visitCall(zapParser::CallContext *ctx) override;

    virtual std::any visitArgumentList(
        zapParser::ArgumentListContext *ctx) override;

    virtual std::any visitPrimary(zapParser::PrimaryContext *ctx) override;

    virtual std::any visitAotBlock(zapParser::AotBlockContext *ctx) override;
};
