
// Generated from Koat.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "KoatParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by KoatParser.
 */
class  KoatListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterMain(KoatParser::MainContext *ctx) = 0;
  virtual void exitMain(KoatParser::MainContext *ctx) = 0;

  virtual void enterFs(KoatParser::FsContext *ctx) = 0;
  virtual void exitFs(KoatParser::FsContext *ctx) = 0;

  virtual void enterVar(KoatParser::VarContext *ctx) = 0;
  virtual void exitVar(KoatParser::VarContext *ctx) = 0;

  virtual void enterGoal(KoatParser::GoalContext *ctx) = 0;
  virtual void exitGoal(KoatParser::GoalContext *ctx) = 0;

  virtual void enterStart(KoatParser::StartContext *ctx) = 0;
  virtual void exitStart(KoatParser::StartContext *ctx) = 0;

  virtual void enterSink(KoatParser::SinkContext *ctx) = 0;
  virtual void exitSink(KoatParser::SinkContext *ctx) = 0;

  virtual void enterVardecl(KoatParser::VardeclContext *ctx) = 0;
  virtual void exitVardecl(KoatParser::VardeclContext *ctx) = 0;

  virtual void enterTranss(KoatParser::TranssContext *ctx) = 0;
  virtual void exitTranss(KoatParser::TranssContext *ctx) = 0;

  virtual void enterTrans(KoatParser::TransContext *ctx) = 0;
  virtual void exitTrans(KoatParser::TransContext *ctx) = 0;

  virtual void enterLhs(KoatParser::LhsContext *ctx) = 0;
  virtual void exitLhs(KoatParser::LhsContext *ctx) = 0;

  virtual void enterCom(KoatParser::ComContext *ctx) = 0;
  virtual void exitCom(KoatParser::ComContext *ctx) = 0;

  virtual void enterRhs(KoatParser::RhsContext *ctx) = 0;
  virtual void exitRhs(KoatParser::RhsContext *ctx) = 0;

  virtual void enterTo(KoatParser::ToContext *ctx) = 0;
  virtual void exitTo(KoatParser::ToContext *ctx) = 0;

  virtual void enterLb(KoatParser::LbContext *ctx) = 0;
  virtual void exitLb(KoatParser::LbContext *ctx) = 0;

  virtual void enterUb(KoatParser::UbContext *ctx) = 0;
  virtual void exitUb(KoatParser::UbContext *ctx) = 0;

  virtual void enterCond(KoatParser::CondContext *ctx) = 0;
  virtual void exitCond(KoatParser::CondContext *ctx) = 0;

  virtual void enterExpr(KoatParser::ExprContext *ctx) = 0;
  virtual void exitExpr(KoatParser::ExprContext *ctx) = 0;

  virtual void enterFormula(KoatParser::FormulaContext *ctx) = 0;
  virtual void exitFormula(KoatParser::FormulaContext *ctx) = 0;

  virtual void enterLit(KoatParser::LitContext *ctx) = 0;
  virtual void exitLit(KoatParser::LitContext *ctx) = 0;

  virtual void enterRelop(KoatParser::RelopContext *ctx) = 0;
  virtual void exitRelop(KoatParser::RelopContext *ctx) = 0;


};

