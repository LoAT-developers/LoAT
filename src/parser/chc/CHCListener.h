
// Generated from CHC.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CHCParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CHCParser.
 */
class  CHCListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterMain(CHCParser::MainContext *ctx) = 0;
  virtual void exitMain(CHCParser::MainContext *ctx) = 0;

  virtual void enterFun_decl(CHCParser::Fun_declContext *ctx) = 0;
  virtual void exitFun_decl(CHCParser::Fun_declContext *ctx) = 0;

  virtual void enterChc_assert(CHCParser::Chc_assertContext *ctx) = 0;
  virtual void exitChc_assert(CHCParser::Chc_assertContext *ctx) = 0;

  virtual void enterChc_assert_head(CHCParser::Chc_assert_headContext *ctx) = 0;
  virtual void exitChc_assert_head(CHCParser::Chc_assert_headContext *ctx) = 0;

  virtual void enterChc_assert_body(CHCParser::Chc_assert_bodyContext *ctx) = 0;
  virtual void exitChc_assert_body(CHCParser::Chc_assert_bodyContext *ctx) = 0;

  virtual void enterChc_tail(CHCParser::Chc_tailContext *ctx) = 0;
  virtual void exitChc_tail(CHCParser::Chc_tailContext *ctx) = 0;

  virtual void enterChc_head(CHCParser::Chc_headContext *ctx) = 0;
  virtual void exitChc_head(CHCParser::Chc_headContext *ctx) = 0;

  virtual void enterChc_query(CHCParser::Chc_queryContext *ctx) = 0;
  virtual void exitChc_query(CHCParser::Chc_queryContext *ctx) = 0;

  virtual void enterVar_decl(CHCParser::Var_declContext *ctx) = 0;
  virtual void exitVar_decl(CHCParser::Var_declContext *ctx) = 0;

  virtual void enterU_pred_atom(CHCParser::U_pred_atomContext *ctx) = 0;
  virtual void exitU_pred_atom(CHCParser::U_pred_atomContext *ctx) = 0;

  virtual void enterI_formula(CHCParser::I_formulaContext *ctx) = 0;
  virtual void exitI_formula(CHCParser::I_formulaContext *ctx) = 0;

  virtual void enterBoolop(CHCParser::BoolopContext *ctx) = 0;
  virtual void exitBoolop(CHCParser::BoolopContext *ctx) = 0;

  virtual void enterLit(CHCParser::LitContext *ctx) = 0;
  virtual void exitLit(CHCParser::LitContext *ctx) = 0;

  virtual void enterRelop(CHCParser::RelopContext *ctx) = 0;
  virtual void exitRelop(CHCParser::RelopContext *ctx) = 0;

  virtual void enterExpr(CHCParser::ExprContext *ctx) = 0;
  virtual void exitExpr(CHCParser::ExprContext *ctx) = 0;

  virtual void enterUnaryop(CHCParser::UnaryopContext *ctx) = 0;
  virtual void exitUnaryop(CHCParser::UnaryopContext *ctx) = 0;

  virtual void enterBinaryop(CHCParser::BinaryopContext *ctx) = 0;
  virtual void exitBinaryop(CHCParser::BinaryopContext *ctx) = 0;

  virtual void enterNaryop(CHCParser::NaryopContext *ctx) = 0;
  virtual void exitNaryop(CHCParser::NaryopContext *ctx) = 0;

  virtual void enterSymbol(CHCParser::SymbolContext *ctx) = 0;
  virtual void exitSymbol(CHCParser::SymbolContext *ctx) = 0;

  virtual void enterSort(CHCParser::SortContext *ctx) = 0;
  virtual void exitSort(CHCParser::SortContext *ctx) = 0;

  virtual void enterVar(CHCParser::VarContext *ctx) = 0;
  virtual void exitVar(CHCParser::VarContext *ctx) = 0;

  virtual void enterId(CHCParser::IdContext *ctx) = 0;
  virtual void exitId(CHCParser::IdContext *ctx) = 0;


};

