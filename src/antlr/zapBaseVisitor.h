
// Generated from zap.g4 by ANTLR 4.13.2

#pragma once

#include "antlr4-runtime.h"
#include "zapVisitor.h"

/**
 * This class provides an empty implementation of zapVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class zapBaseVisitor : public zapVisitor {
   public:
    virtual std::any visitProgram(zapParser::ProgramContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitDeclaration(
        zapParser::DeclarationContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitStatement(zapParser::StatementContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitFunctionDecl(
        zapParser::FunctionDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitAttributeBlock(
        zapParser::AttributeBlockContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitAttributeList(
        zapParser::AttributeListContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitAttribute(zapParser::AttributeContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitAttributeArgs(
        zapParser::AttributeArgsContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitAttributeArg(
        zapParser::AttributeArgContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitReturnType(
        zapParser::ReturnTypeContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitParameterList(
        zapParser::ParameterListContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitParameter(zapParser::ParameterContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitType(zapParser::TypeContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitStructDecl(
        zapParser::StructDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitStructField(
        zapParser::StructFieldContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitComponentDecl(
        zapParser::ComponentDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitModuleDecl(
        zapParser::ModuleDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitBlock(zapParser::BlockContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitVariableDecl(
        zapParser::VariableDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitIfStmt(zapParser::IfStmtContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitWhileStmt(zapParser::WhileStmtContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitForStmt(zapParser::ForStmtContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitReturnStmt(
        zapParser::ReturnStmtContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitYieldStmt(zapParser::YieldStmtContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitDeferStmt(zapParser::DeferStmtContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitExpressionStmt(
        zapParser::ExpressionStmtContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitExpression(
        zapParser::ExpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitAssignment(
        zapParser::AssignmentContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitLogicOr(zapParser::LogicOrContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitLogicAnd(zapParser::LogicAndContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitEquality(zapParser::EqualityContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitComparison(
        zapParser::ComparisonContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitTerm(zapParser::TermContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitFactor(zapParser::FactorContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitUnary(zapParser::UnaryContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitCall(zapParser::CallContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitArgumentList(
        zapParser::ArgumentListContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitPrimary(zapParser::PrimaryContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitAotBlock(zapParser::AotBlockContext *ctx) override {
        return visitChildren(ctx);
    }
};
