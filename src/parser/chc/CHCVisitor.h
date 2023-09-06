
// Generated from CHC.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "CHCParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CHCParser.
 */
class  CHCVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CHCParser.
   */
    virtual std::any visitMain(CHCParser::MainContext *context) = 0;

    virtual std::any visitFun_decl(CHCParser::Fun_declContext *context) = 0;

    virtual std::any visitChc_assert(CHCParser::Chc_assertContext *context) = 0;

    virtual std::any visitChc_assert_head(CHCParser::Chc_assert_headContext *context) = 0;

    virtual std::any visitChc_assert_body(CHCParser::Chc_assert_bodyContext *context) = 0;

    virtual std::any visitChc_tail(CHCParser::Chc_tailContext *context) = 0;

    virtual std::any visitChc_head(CHCParser::Chc_headContext *context) = 0;

    virtual std::any visitChc_query(CHCParser::Chc_queryContext *context) = 0;

    virtual std::any visitVar_decl(CHCParser::Var_declContext *context) = 0;

    virtual std::any visitVar_or_atom(CHCParser::Var_or_atomContext *context) = 0;

    virtual std::any visitU_pred_atom(CHCParser::U_pred_atomContext *context) = 0;

    virtual std::any visitLet(CHCParser::LetContext *context) = 0;

    virtual std::any visitLets(CHCParser::LetsContext *context) = 0;

    virtual std::any visitFormula_or_expr(CHCParser::Formula_or_exprContext *context) = 0;

    virtual std::any visitExpr(CHCParser::ExprContext *context) = 0;

    virtual std::any visitUnaryop(CHCParser::UnaryopContext *context) = 0;

    virtual std::any visitBinaryop(CHCParser::BinaryopContext *context) = 0;

    virtual std::any visitNaryop(CHCParser::NaryopContext *context) = 0;

    virtual std::any visitI_formula(CHCParser::I_formulaContext *context) = 0;

    virtual std::any visitBoolop(CHCParser::BoolopContext *context) = 0;

    virtual std::any visitLit(CHCParser::LitContext *context) = 0;

    virtual std::any visitRelop(CHCParser::RelopContext *context) = 0;

    virtual std::any visitSymbol(CHCParser::SymbolContext *context) = 0;

    virtual std::any visitSort(CHCParser::SortContext *context) = 0;

    virtual std::any visitVar(CHCParser::VarContext *context) = 0;


};

