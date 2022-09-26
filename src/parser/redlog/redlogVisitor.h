
// Generated from redlog.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "redlogParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by redlogParser.
 */
class  redlogVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by redlogParser.
   */
    virtual std::any visitMain(redlogParser::MainContext *context) = 0;

    virtual std::any visitExpr(redlogParser::ExprContext *context) = 0;

    virtual std::any visitCaop(redlogParser::CaopContext *context) = 0;

    virtual std::any visitBinop(redlogParser::BinopContext *context) = 0;

    virtual std::any visitFormula(redlogParser::FormulaContext *context) = 0;

    virtual std::any visitLit(redlogParser::LitContext *context) = 0;

    virtual std::any visitBoolop(redlogParser::BoolopContext *context) = 0;

    virtual std::any visitRelop(redlogParser::RelopContext *context) = 0;


};

