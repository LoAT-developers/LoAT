#pragma once


#include "KoatVisitor.h"
#include "itsproblem.hpp"

/**
 * This class provides an empty implementation of KoatVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  KoatParseVisitor : public KoatVisitor {

    ITSProblem its;
    std::map<std::string, LocationIdx> locations;
    std::map<std::string, NumVar> vars;
    std::vector<NumVar> programVars;

    enum ArithOp {
        Plus, Minus, Times, Exp
    };

    LocationIdx loc(const std::string &name) {
        auto it = locations.find(name);
        if (it == locations.end()) {
            auto idx = its.addNamedLocation(name);
            locations[name] = idx;
            return idx;
        } else {
            return it->second;
        }
    }

public:

    virtual antlrcpp::Any visitMain(KoatParser::MainContext *ctx) override;
    virtual antlrcpp::Any visitGoal(KoatParser::GoalContext *ctx) override;
    virtual antlrcpp::Any visitStart(KoatParser::StartContext *ctx) override;
    virtual antlrcpp::Any visitVardecl(KoatParser::VardeclContext *ctx) override;
    virtual antlrcpp::Any visitTranss(KoatParser::TranssContext *ctx) override;
    virtual antlrcpp::Any visitVar(KoatParser::VarContext *ctx) override;
    virtual antlrcpp::Any visitFs(KoatParser::FsContext *ctx) override;
    virtual antlrcpp::Any visitTrans(KoatParser::TransContext *ctx) override;
    virtual antlrcpp::Any visitLhs(KoatParser::LhsContext *ctx) override;
    virtual antlrcpp::Any visitCom(KoatParser::ComContext *ctx) override;
    virtual antlrcpp::Any visitRhs(KoatParser::RhsContext *ctx) override;
    virtual antlrcpp::Any visitTo(KoatParser::ToContext *ctx) override;
    virtual antlrcpp::Any visitLb(KoatParser::LbContext *ctx) override;
    virtual antlrcpp::Any visitUb(KoatParser::UbContext *ctx) override;
    virtual antlrcpp::Any visitCond(KoatParser::CondContext *ctx) override;
    virtual antlrcpp::Any visitExpr(KoatParser::ExprContext *ctx) override;
    virtual antlrcpp::Any visitFormula(KoatParser::FormulaContext *ctx) override;
    virtual antlrcpp::Any visitLit(KoatParser::LitContext *ctx) override;
    virtual antlrcpp::Any visitRelop(KoatParser::RelopContext *ctx) override;

};

