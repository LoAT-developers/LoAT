
// Generated from Koat.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "KoatParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by KoatParser.
 */
class  KoatVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by KoatParser.
   */
    virtual std::any visitMain(KoatParser::MainContext *context) = 0;

    virtual std::any visitFs(KoatParser::FsContext *context) = 0;

    virtual std::any visitVar(KoatParser::VarContext *context) = 0;

    virtual std::any visitGoal(KoatParser::GoalContext *context) = 0;

    virtual std::any visitStart(KoatParser::StartContext *context) = 0;

    virtual std::any visitSink(KoatParser::SinkContext *context) = 0;

    virtual std::any visitVardecl(KoatParser::VardeclContext *context) = 0;

    virtual std::any visitTranss(KoatParser::TranssContext *context) = 0;

    virtual std::any visitTrans(KoatParser::TransContext *context) = 0;

    virtual std::any visitLhs(KoatParser::LhsContext *context) = 0;

    virtual std::any visitCom(KoatParser::ComContext *context) = 0;

    virtual std::any visitRhs(KoatParser::RhsContext *context) = 0;

    virtual std::any visitTo(KoatParser::ToContext *context) = 0;

    virtual std::any visitLb(KoatParser::LbContext *context) = 0;

    virtual std::any visitUb(KoatParser::UbContext *context) = 0;

    virtual std::any visitCond(KoatParser::CondContext *context) = 0;

    virtual std::any visitExpr(KoatParser::ExprContext *context) = 0;

    virtual std::any visitFormula(KoatParser::FormulaContext *context) = 0;

    virtual std::any visitLit(KoatParser::LitContext *context) = 0;

    virtual std::any visitRelop(KoatParser::RelopContext *context) = 0;


};

