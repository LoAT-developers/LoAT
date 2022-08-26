
// Generated from CHC.g4 by ANTLR 4.7.2

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
    virtual antlrcpp::Any visitMain(CHCParser::MainContext *context) = 0;

    virtual antlrcpp::Any visitFun_decl(CHCParser::Fun_declContext *context) = 0;

    virtual antlrcpp::Any visitChc_assert(CHCParser::Chc_assertContext *context) = 0;

    virtual antlrcpp::Any visitChc_assert_head(CHCParser::Chc_assert_headContext *context) = 0;

    virtual antlrcpp::Any visitChc_assert_body(CHCParser::Chc_assert_bodyContext *context) = 0;

    virtual antlrcpp::Any visitChc_tail(CHCParser::Chc_tailContext *context) = 0;

    virtual antlrcpp::Any visitChc_head(CHCParser::Chc_headContext *context) = 0;

    virtual antlrcpp::Any visitChc_query(CHCParser::Chc_queryContext *context) = 0;

    virtual antlrcpp::Any visitVar_decl(CHCParser::Var_declContext *context) = 0;

    virtual antlrcpp::Any visitU_pred_atom(CHCParser::U_pred_atomContext *context) = 0;

    virtual antlrcpp::Any visitLet(CHCParser::LetContext *context) = 0;

    virtual antlrcpp::Any visitLets(CHCParser::LetsContext *context) = 0;

    virtual antlrcpp::Any visitI_formula(CHCParser::I_formulaContext *context) = 0;

    virtual antlrcpp::Any visitBoolop(CHCParser::BoolopContext *context) = 0;

    virtual antlrcpp::Any visitLit(CHCParser::LitContext *context) = 0;

    virtual antlrcpp::Any visitRelop(CHCParser::RelopContext *context) = 0;

    virtual antlrcpp::Any visitExpr(CHCParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitUnaryop(CHCParser::UnaryopContext *context) = 0;

    virtual antlrcpp::Any visitBinaryop(CHCParser::BinaryopContext *context) = 0;

    virtual antlrcpp::Any visitNaryop(CHCParser::NaryopContext *context) = 0;

    virtual antlrcpp::Any visitSymbol(CHCParser::SymbolContext *context) = 0;

    virtual antlrcpp::Any visitSort(CHCParser::SortContext *context) = 0;

    virtual antlrcpp::Any visitVar(CHCParser::VarContext *context) = 0;


};

