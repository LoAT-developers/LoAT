
// Generated from CINT.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "CINTParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CINTParser.
 */
class  CINTListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterNondet(CINTParser::NondetContext *ctx) = 0;
  virtual void exitNondet(CINTParser::NondetContext *ctx) = 0;

  virtual void enterNum_expr(CINTParser::Num_exprContext *ctx) = 0;
  virtual void exitNum_expr(CINTParser::Num_exprContext *ctx) = 0;

  virtual void enterBool_expr(CINTParser::Bool_exprContext *ctx) = 0;
  virtual void exitBool_expr(CINTParser::Bool_exprContext *ctx) = 0;

  virtual void enterLit(CINTParser::LitContext *ctx) = 0;
  virtual void exitLit(CINTParser::LitContext *ctx) = 0;

  virtual void enterRelop(CINTParser::RelopContext *ctx) = 0;
  virtual void exitRelop(CINTParser::RelopContext *ctx) = 0;

  virtual void enterLoop(CINTParser::LoopContext *ctx) = 0;
  virtual void exitLoop(CINTParser::LoopContext *ctx) = 0;

  virtual void enterCondition(CINTParser::ConditionContext *ctx) = 0;
  virtual void exitCondition(CINTParser::ConditionContext *ctx) = 0;

  virtual void enterThen(CINTParser::ThenContext *ctx) = 0;
  virtual void exitThen(CINTParser::ThenContext *ctx) = 0;

  virtual void enterElse(CINTParser::ElseContext *ctx) = 0;
  virtual void exitElse(CINTParser::ElseContext *ctx) = 0;

  virtual void enterAssignment(CINTParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(CINTParser::AssignmentContext *ctx) = 0;

  virtual void enterInstruction(CINTParser::InstructionContext *ctx) = 0;
  virtual void exitInstruction(CINTParser::InstructionContext *ctx) = 0;

  virtual void enterDeclaration(CINTParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(CINTParser::DeclarationContext *ctx) = 0;

  virtual void enterDeclarations(CINTParser::DeclarationsContext *ctx) = 0;
  virtual void exitDeclarations(CINTParser::DeclarationsContext *ctx) = 0;

  virtual void enterInstructions(CINTParser::InstructionsContext *ctx) = 0;
  virtual void exitInstructions(CINTParser::InstructionsContext *ctx) = 0;

  virtual void enterPre(CINTParser::PreContext *ctx) = 0;
  virtual void exitPre(CINTParser::PreContext *ctx) = 0;

  virtual void enterPost(CINTParser::PostContext *ctx) = 0;
  virtual void exitPost(CINTParser::PostContext *ctx) = 0;

  virtual void enterMain(CINTParser::MainContext *ctx) = 0;
  virtual void exitMain(CINTParser::MainContext *ctx) = 0;


};

