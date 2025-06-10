
// Generated from zap.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "antlr/zapListener.h"


/*
 * This class provides an empty implementation of zapListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class LLVMListener : public zapListener {
public:

    virtual void enterProgram(zapParser::ProgramContext * /*ctx*/) override;
    virtual void exitProgram(zapParser::ProgramContext * /*ctx*/) override;

  virtual void enterStatement(zapParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(zapParser::StatementContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(zapParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(zapParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterAttributeBlock(zapParser::AttributeBlockContext * /*ctx*/) override { }
  virtual void exitAttributeBlock(zapParser::AttributeBlockContext * /*ctx*/) override { }

  virtual void enterAttribute(zapParser::AttributeContext * /*ctx*/) override { }
  virtual void exitAttribute(zapParser::AttributeContext * /*ctx*/) override { }

  virtual void enterReturnType(zapParser::ReturnTypeContext * /*ctx*/) override { }
  virtual void exitReturnType(zapParser::ReturnTypeContext * /*ctx*/) override { }

  virtual void enterParameterList(zapParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(zapParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameter(zapParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(zapParser::ParameterContext * /*ctx*/) override { }

  virtual void enterType(zapParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(zapParser::TypeContext * /*ctx*/) override { }

  virtual void enterStructDecl(zapParser::StructDeclContext * /*ctx*/) override { }
  virtual void exitStructDecl(zapParser::StructDeclContext * /*ctx*/) override { }

  virtual void enterStructField(zapParser::StructFieldContext * /*ctx*/) override { }
  virtual void exitStructField(zapParser::StructFieldContext * /*ctx*/) override { }

  virtual void enterComponentDecl(zapParser::ComponentDeclContext * /*ctx*/) override { }
  virtual void exitComponentDecl(zapParser::ComponentDeclContext * /*ctx*/) override { }

  virtual void enterModuleDecl(zapParser::ModuleDeclContext * /*ctx*/) override { }
  virtual void exitModuleDecl(zapParser::ModuleDeclContext * /*ctx*/) override { }

  virtual void enterBlock(zapParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(zapParser::BlockContext * /*ctx*/) override { }

  virtual void enterVariableDecl(zapParser::VariableDeclContext * /*ctx*/) override { }
  virtual void exitVariableDecl(zapParser::VariableDeclContext * /*ctx*/) override { }

  virtual void enterIfStmt(zapParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(zapParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterWhileStmt(zapParser::WhileStmtContext * /*ctx*/) override { }
  virtual void exitWhileStmt(zapParser::WhileStmtContext * /*ctx*/) override { }

  virtual void enterForStmt(zapParser::ForStmtContext * /*ctx*/) override { }
  virtual void exitForStmt(zapParser::ForStmtContext * /*ctx*/) override { }

  virtual void enterReturnStmt(zapParser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(zapParser::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterYieldStmt(zapParser::YieldStmtContext * /*ctx*/) override { }
  virtual void exitYieldStmt(zapParser::YieldStmtContext * /*ctx*/) override { }

  virtual void enterDeferStmt(zapParser::DeferStmtContext * /*ctx*/) override { }
  virtual void exitDeferStmt(zapParser::DeferStmtContext * /*ctx*/) override { }

  virtual void enterExpressionStmt(zapParser::ExpressionStmtContext * /*ctx*/) override { }
  virtual void exitExpressionStmt(zapParser::ExpressionStmtContext * /*ctx*/) override { }

  virtual void enterExpression(zapParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(zapParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterAssignment(zapParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(zapParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterLogicOr(zapParser::LogicOrContext * /*ctx*/) override { }
  virtual void exitLogicOr(zapParser::LogicOrContext * /*ctx*/) override { }

  virtual void enterLogicAnd(zapParser::LogicAndContext * /*ctx*/) override { }
  virtual void exitLogicAnd(zapParser::LogicAndContext * /*ctx*/) override { }

  virtual void enterEquality(zapParser::EqualityContext * /*ctx*/) override { }
  virtual void exitEquality(zapParser::EqualityContext * /*ctx*/) override { }

  virtual void enterComparison(zapParser::ComparisonContext * /*ctx*/) override { }
  virtual void exitComparison(zapParser::ComparisonContext * /*ctx*/) override { }

  virtual void enterTerm(zapParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(zapParser::TermContext * /*ctx*/) override { }

  virtual void enterFactor(zapParser::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(zapParser::FactorContext * /*ctx*/) override { }

  virtual void enterUnary(zapParser::UnaryContext * /*ctx*/) override { }
  virtual void exitUnary(zapParser::UnaryContext * /*ctx*/) override { }

  virtual void enterCall(zapParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(zapParser::CallContext * /*ctx*/) override { }

  virtual void enterArgumentList(zapParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(zapParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterPrimary(zapParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(zapParser::PrimaryContext * /*ctx*/) override { }

  virtual void enterAotBlock(zapParser::AotBlockContext * /*ctx*/) override { }
  virtual void exitAotBlock(zapParser::AotBlockContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

