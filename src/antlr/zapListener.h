
// Generated from zap.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "zapParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by zapParser.
 */
class  zapListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(zapParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(zapParser::ProgramContext *ctx) = 0;

  virtual void enterDeclaration(zapParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(zapParser::DeclarationContext *ctx) = 0;

  virtual void enterStatement(zapParser::StatementContext *ctx) = 0;
  virtual void exitStatement(zapParser::StatementContext *ctx) = 0;

  virtual void enterFunctionDecl(zapParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(zapParser::FunctionDeclContext *ctx) = 0;

  virtual void enterAttributeBlock(zapParser::AttributeBlockContext *ctx) = 0;
  virtual void exitAttributeBlock(zapParser::AttributeBlockContext *ctx) = 0;

  virtual void enterAttributeList(zapParser::AttributeListContext *ctx) = 0;
  virtual void exitAttributeList(zapParser::AttributeListContext *ctx) = 0;

  virtual void enterAttribute(zapParser::AttributeContext *ctx) = 0;
  virtual void exitAttribute(zapParser::AttributeContext *ctx) = 0;

  virtual void enterAttributeArgs(zapParser::AttributeArgsContext *ctx) = 0;
  virtual void exitAttributeArgs(zapParser::AttributeArgsContext *ctx) = 0;

  virtual void enterAttributeArg(zapParser::AttributeArgContext *ctx) = 0;
  virtual void exitAttributeArg(zapParser::AttributeArgContext *ctx) = 0;

  virtual void enterReturnType(zapParser::ReturnTypeContext *ctx) = 0;
  virtual void exitReturnType(zapParser::ReturnTypeContext *ctx) = 0;

  virtual void enterParameterList(zapParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(zapParser::ParameterListContext *ctx) = 0;

  virtual void enterParameter(zapParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(zapParser::ParameterContext *ctx) = 0;

  virtual void enterType(zapParser::TypeContext *ctx) = 0;
  virtual void exitType(zapParser::TypeContext *ctx) = 0;

  virtual void enterStructDecl(zapParser::StructDeclContext *ctx) = 0;
  virtual void exitStructDecl(zapParser::StructDeclContext *ctx) = 0;

  virtual void enterStructField(zapParser::StructFieldContext *ctx) = 0;
  virtual void exitStructField(zapParser::StructFieldContext *ctx) = 0;

  virtual void enterComponentDecl(zapParser::ComponentDeclContext *ctx) = 0;
  virtual void exitComponentDecl(zapParser::ComponentDeclContext *ctx) = 0;

  virtual void enterModuleDecl(zapParser::ModuleDeclContext *ctx) = 0;
  virtual void exitModuleDecl(zapParser::ModuleDeclContext *ctx) = 0;

  virtual void enterBlock(zapParser::BlockContext *ctx) = 0;
  virtual void exitBlock(zapParser::BlockContext *ctx) = 0;

  virtual void enterVariableDecl(zapParser::VariableDeclContext *ctx) = 0;
  virtual void exitVariableDecl(zapParser::VariableDeclContext *ctx) = 0;

  virtual void enterIfStmt(zapParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(zapParser::IfStmtContext *ctx) = 0;

  virtual void enterWhileStmt(zapParser::WhileStmtContext *ctx) = 0;
  virtual void exitWhileStmt(zapParser::WhileStmtContext *ctx) = 0;

  virtual void enterForStmt(zapParser::ForStmtContext *ctx) = 0;
  virtual void exitForStmt(zapParser::ForStmtContext *ctx) = 0;

  virtual void enterReturnStmt(zapParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(zapParser::ReturnStmtContext *ctx) = 0;

  virtual void enterYieldStmt(zapParser::YieldStmtContext *ctx) = 0;
  virtual void exitYieldStmt(zapParser::YieldStmtContext *ctx) = 0;

  virtual void enterDeferStmt(zapParser::DeferStmtContext *ctx) = 0;
  virtual void exitDeferStmt(zapParser::DeferStmtContext *ctx) = 0;

  virtual void enterExpressionStmt(zapParser::ExpressionStmtContext *ctx) = 0;
  virtual void exitExpressionStmt(zapParser::ExpressionStmtContext *ctx) = 0;

  virtual void enterExpression(zapParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(zapParser::ExpressionContext *ctx) = 0;

  virtual void enterLvalue(zapParser::LvalueContext *ctx) = 0;
  virtual void exitLvalue(zapParser::LvalueContext *ctx) = 0;

  virtual void enterAssignment(zapParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(zapParser::AssignmentContext *ctx) = 0;

  virtual void enterLogicOr(zapParser::LogicOrContext *ctx) = 0;
  virtual void exitLogicOr(zapParser::LogicOrContext *ctx) = 0;

  virtual void enterLogicAnd(zapParser::LogicAndContext *ctx) = 0;
  virtual void exitLogicAnd(zapParser::LogicAndContext *ctx) = 0;

  virtual void enterEquality(zapParser::EqualityContext *ctx) = 0;
  virtual void exitEquality(zapParser::EqualityContext *ctx) = 0;

  virtual void enterComparison(zapParser::ComparisonContext *ctx) = 0;
  virtual void exitComparison(zapParser::ComparisonContext *ctx) = 0;

  virtual void enterTerm(zapParser::TermContext *ctx) = 0;
  virtual void exitTerm(zapParser::TermContext *ctx) = 0;

  virtual void enterFactor(zapParser::FactorContext *ctx) = 0;
  virtual void exitFactor(zapParser::FactorContext *ctx) = 0;

  virtual void enterUnary(zapParser::UnaryContext *ctx) = 0;
  virtual void exitUnary(zapParser::UnaryContext *ctx) = 0;

  virtual void enterCall(zapParser::CallContext *ctx) = 0;
  virtual void exitCall(zapParser::CallContext *ctx) = 0;

  virtual void enterArgumentList(zapParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(zapParser::ArgumentListContext *ctx) = 0;

  virtual void enterPrimary(zapParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(zapParser::PrimaryContext *ctx) = 0;

  virtual void enterAotBlock(zapParser::AotBlockContext *ctx) = 0;
  virtual void exitAotBlock(zapParser::AotBlockContext *ctx) = 0;


};

