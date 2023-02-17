
// Generated from redlog.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "redlogParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by redlogParser.
 */
class  redlogListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterMain(redlogParser::MainContext *ctx) = 0;
  virtual void exitMain(redlogParser::MainContext *ctx) = 0;

  virtual void enterExpr(redlogParser::ExprContext *ctx) = 0;
  virtual void exitExpr(redlogParser::ExprContext *ctx) = 0;

  virtual void enterCaop(redlogParser::CaopContext *ctx) = 0;
  virtual void exitCaop(redlogParser::CaopContext *ctx) = 0;

  virtual void enterBinop(redlogParser::BinopContext *ctx) = 0;
  virtual void exitBinop(redlogParser::BinopContext *ctx) = 0;

  virtual void enterFormula(redlogParser::FormulaContext *ctx) = 0;
  virtual void exitFormula(redlogParser::FormulaContext *ctx) = 0;

  virtual void enterLit(redlogParser::LitContext *ctx) = 0;
  virtual void exitLit(redlogParser::LitContext *ctx) = 0;

  virtual void enterBoolop(redlogParser::BoolopContext *ctx) = 0;
  virtual void exitBoolop(redlogParser::BoolopContext *ctx) = 0;

  virtual void enterRelop(redlogParser::RelopContext *ctx) = 0;
  virtual void exitRelop(redlogParser::RelopContext *ctx) = 0;


};

