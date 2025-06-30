
// Generated from zap.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "zapParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by zapParser.
 */
class  zapVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by zapParser.
   */
    virtual std::any visitProgram(zapParser::ProgramContext *context) = 0;

    virtual std::any visitDeclaration(zapParser::DeclarationContext *context) = 0;

    virtual std::any visitStatement(zapParser::StatementContext *context) = 0;

    virtual std::any visitFunctionDecl(zapParser::FunctionDeclContext *context) = 0;

    virtual std::any visitAttributeBlock(zapParser::AttributeBlockContext *context) = 0;

    virtual std::any visitAttributeList(zapParser::AttributeListContext *context) = 0;

    virtual std::any visitAttribute(zapParser::AttributeContext *context) = 0;

    virtual std::any visitAttributeArgs(zapParser::AttributeArgsContext *context) = 0;

    virtual std::any visitAttributeArg(zapParser::AttributeArgContext *context) = 0;

    virtual std::any visitReturnType(zapParser::ReturnTypeContext *context) = 0;

    virtual std::any visitParameterList(zapParser::ParameterListContext *context) = 0;

    virtual std::any visitParameter(zapParser::ParameterContext *context) = 0;

    virtual std::any visitType(zapParser::TypeContext *context) = 0;

    virtual std::any visitStructDecl(zapParser::StructDeclContext *context) = 0;

    virtual std::any visitStructField(zapParser::StructFieldContext *context) = 0;

    virtual std::any visitComponentDecl(zapParser::ComponentDeclContext *context) = 0;

    virtual std::any visitModuleDecl(zapParser::ModuleDeclContext *context) = 0;

    virtual std::any visitBlock(zapParser::BlockContext *context) = 0;

    virtual std::any visitVariableDecl(zapParser::VariableDeclContext *context) = 0;

    virtual std::any visitIfStmt(zapParser::IfStmtContext *context) = 0;

    virtual std::any visitWhileStmt(zapParser::WhileStmtContext *context) = 0;

    virtual std::any visitForStmt(zapParser::ForStmtContext *context) = 0;

    virtual std::any visitReturnStmt(zapParser::ReturnStmtContext *context) = 0;

    virtual std::any visitYieldStmt(zapParser::YieldStmtContext *context) = 0;

    virtual std::any visitDeferStmt(zapParser::DeferStmtContext *context) = 0;

    virtual std::any visitExpressionStmt(zapParser::ExpressionStmtContext *context) = 0;

    virtual std::any visitExpression(zapParser::ExpressionContext *context) = 0;

    virtual std::any visitLvalue(zapParser::LvalueContext *context) = 0;

    virtual std::any visitAssignment(zapParser::AssignmentContext *context) = 0;

    virtual std::any visitLogicOr(zapParser::LogicOrContext *context) = 0;

    virtual std::any visitLogicAnd(zapParser::LogicAndContext *context) = 0;

    virtual std::any visitEquality(zapParser::EqualityContext *context) = 0;

    virtual std::any visitComparison(zapParser::ComparisonContext *context) = 0;

    virtual std::any visitTerm(zapParser::TermContext *context) = 0;

    virtual std::any visitFactor(zapParser::FactorContext *context) = 0;

    virtual std::any visitUnary(zapParser::UnaryContext *context) = 0;

    virtual std::any visitCall(zapParser::CallContext *context) = 0;

    virtual std::any visitArgumentList(zapParser::ArgumentListContext *context) = 0;

    virtual std::any visitPrimary(zapParser::PrimaryContext *context) = 0;

    virtual std::any visitAotBlock(zapParser::AotBlockContext *context) = 0;


};

