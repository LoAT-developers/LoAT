#pragma once

#include "itsproblem.hpp"
#include "CHCVisitor.h"

template<class T>
struct Res {
    T t;
    BoolExpr refinement = True;
    Res(const T &t);
    Res();
};

enum UnaryOp {
    UnaryMinus
};

enum BinaryOp {
    Minus, Mod, Div
};

enum NAryOp {
    Plus, Times
};

enum BoolOp {
    And, Or, Equiv
};

enum Sort {
    Int, Bool
};

struct FunApp {

    LocationIdx loc;
    std::vector<Var> args;

    FunApp(const LocationIdx loc, const std::vector<Var> args): loc(loc), args(args) {}

};

struct Clause {
    const FunApp lhs;
    const FunApp rhs;
    const BoolExpr guard;

    Clause(const FunApp &lhs, const FunApp &rhs, const BoolExpr &guard): lhs(lhs), rhs(rhs), guard(guard) {}

};

/**
 * This class provides an empty implementation of CHCVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CHCParseVisitor : public CHCVisitor {

    ITSProblem its;
    std::map<std::string, LocationIdx> locations;
    std::map<std::string, Var> vars;
    unsigned long maxArity = 0;

    LocationIdx loc(const std::string &name);
    Var var(const std::string &name, Expr::Type type);

public:

    virtual antlrcpp::Any visitMain(CHCParser::MainContext *ctx) override;

    virtual antlrcpp::Any visitFun_decl(CHCParser::Fun_declContext *ctx) override;

    virtual antlrcpp::Any visitChc_assert(CHCParser::Chc_assertContext *ctx) override;

    virtual antlrcpp::Any visitChc_assert_head(CHCParser::Chc_assert_headContext *ctx) override;

    virtual antlrcpp::Any visitChc_assert_body(CHCParser::Chc_assert_bodyContext *ctx) override;

    virtual antlrcpp::Any visitChc_tail(CHCParser::Chc_tailContext *ctx) override;

    virtual antlrcpp::Any visitChc_head(CHCParser::Chc_headContext *ctx) override;

    virtual antlrcpp::Any visitChc_query(CHCParser::Chc_queryContext *ctx) override;

    virtual antlrcpp::Any visitVar_decl(CHCParser::Var_declContext *ctx) override;

    virtual antlrcpp::Any visitU_pred_atom(CHCParser::U_pred_atomContext *ctx) override;

    virtual antlrcpp::Any visitI_formula(CHCParser::I_formulaContext *ctx) override;

    virtual antlrcpp::Any visitLets(CHCParser::LetsContext *ctx) override;

    virtual antlrcpp::Any visitLet(CHCParser::LetContext *ctx) override;

    virtual antlrcpp::Any visitBoolop(CHCParser::BoolopContext *ctx) override;

    virtual antlrcpp::Any visitLit(CHCParser::LitContext *ctx) override;

    virtual antlrcpp::Any visitRelop(CHCParser::RelopContext *ctx) override;

    virtual antlrcpp::Any visitExpr(CHCParser::ExprContext *ctx) override;

    virtual antlrcpp::Any visitUnaryop(CHCParser::UnaryopContext *ctx) override;

    virtual antlrcpp::Any visitBinaryop(CHCParser::BinaryopContext *ctx) override;

    virtual antlrcpp::Any visitNaryop(CHCParser::NaryopContext *ctx) override;

    virtual antlrcpp::Any visitSymbol(CHCParser::SymbolContext *ctx) override;

    virtual antlrcpp::Any visitSort(CHCParser::SortContext *ctx) override;

    virtual antlrcpp::Any visitVar_or_atom(CHCParser::Var_or_atomContext *context) override;

    virtual antlrcpp::Any visitVar(CHCParser::VarContext *ctx) override;

};

