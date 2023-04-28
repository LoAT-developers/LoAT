#include "KoatParseVisitor.h"
#include "boolexpression.hpp"
#include "variable.hpp"
#include "config.hpp"

using fs_type = LocationIdx;
using lhs_type = LocationIdx;
using to_type = Expr;
using com_type = std::vector<Subs>;
using cond_type = BoolExpr;
using rhs_type = Subs;
using expr_type = Expr;
using var_type = NumVar;
using lit_type = Rel;
using formula_type = BoolExpr;
using relop_type = Rel::RelOp;

antlrcpp::Any KoatParseVisitor::visitMain(KoatParser::MainContext *ctx) {
    visitChildren(ctx);
    return its;
}

antlrcpp::Any KoatParseVisitor::visitGoal(KoatParser::GoalContext *ctx) {
    return {};
}

antlrcpp::Any KoatParseVisitor::visitStart(KoatParser::StartContext *ctx) {
    its.setInitialLocation(any_cast<fs_type>(visit(ctx->fs())));
    return {};
}

antlrcpp::Any KoatParseVisitor::visitVardecl(KoatParser::VardeclContext *ctx) {
    return {};
}

antlrcpp::Any KoatParseVisitor::visitTranss(KoatParser::TranssContext *ctx) {
    visitChildren(ctx);
    return {};
}

antlrcpp::Any KoatParseVisitor::visitVar(KoatParser::VarContext *ctx) {
    std::string name = ctx->getText();
    auto it = vars.find(name);
    if (it == vars.end()) {
        const NumVar var {NumVar::next()};
        vars.emplace(name, var);
        return var;
    } else {
        return it->second;
    }
}

antlrcpp::Any KoatParseVisitor::visitFs(KoatParser::FsContext *ctx) {
    return loc(ctx->getText());
}

antlrcpp::Any KoatParseVisitor::visitTrans(KoatParser::TransContext *ctx) {
    const auto lhsLoc = any_cast<lhs_type>(visit(ctx->lhs()));
    const auto cost = any_cast<to_type>(visit(ctx->to()));
    const auto rhss = any_cast<com_type>(visit(ctx->com()));
    if (rhss.size() > 1) {
        throw std::invalid_argument("Com-symbols are not supported");
    }
    BoolExpr cond = True;
    if (ctx->cond()) {
        cond = any_cast<cond_type>(visit(ctx->cond()));
    }
    cond = cond & Rel::buildEq(its.getLocVar(), lhsLoc);
    auto up = rhss.at(0);
    if (Config::Analysis::complexity()) {
        up.put<IntTheory>(its.getCostVar(), its.getCostVar() + cost);
    }
    Rule rule(cond, up);
    auto vars = rule.vars();
    Subs varRenaming;
    for (const auto &x: vars) {
        const auto var {std::get<NumVar>(x)};
        if (var.isTempVar()) {
            varRenaming.put<IntTheory>(var, NumVar::next());
        }
    }
    rule = rule.subs(varRenaming);
    its.addRule(rule, lhsLoc);
    return {};
}

antlrcpp::Any KoatParseVisitor::visitLhs(KoatParser::LhsContext *ctx) {
    static bool initVars = true;
    if (initVars) {
        for (const auto& c: ctx->var()) {
            const NumVar var {NumVar::nextProgVar()};
            programVars.push_back(var);
            vars.emplace(c->getText(), var);
        }
        initVars = false;
    } else {
        unsigned sz = programVars.size();
        if (sz != ctx->var().size()) {
            throw std::invalid_argument("wrong arity: " + ctx->getText());
        }
        for (unsigned i = 0; i < sz; ++i) {
            if (programVars[i].getName() != vars.at(ctx->var(i)->getText()).getName()) {
                throw std::invalid_argument("invalid arguments: expected " + variable::getName(programVars[i]) + ", got " + ctx->var(i)->getText());
            }
        }
    }
    return visit(ctx->fs());
}

antlrcpp::Any KoatParseVisitor::visitCom(KoatParser::ComContext *ctx) {
    com_type rhss;
    for (const auto &rhs: ctx->rhs()) {
        rhss.push_back(any_cast<rhs_type>(visit(rhs)));
    }
    return rhss;
}

antlrcpp::Any KoatParseVisitor::visitRhs(KoatParser::RhsContext *ctx) {
    const auto expr = ctx->expr();
    unsigned sz = expr.size();
    Subs up;
    for (unsigned i = 0; i < sz; ++i) {
        Expr rhs = any_cast<expr_type>(visit(expr[i]));
        if (rhs != programVars[i]) {
            up.put<IntTheory>(programVars[i], rhs);
        }
    }
    LocationIdx loc = any_cast<fs_type>(visit(ctx->fs()));
    up.put<IntTheory>(its.getLocVar(), loc);
    return up;
}

antlrcpp::Any KoatParseVisitor::visitTo(KoatParser::ToContext *ctx) {
    if (ctx->lb()) {
        return visit(ctx->lb());
    } else {
        return Expr(1);
    }
}

antlrcpp::Any KoatParseVisitor::visitLb(KoatParser::LbContext *ctx) {
    return visit(ctx->expr());
}

antlrcpp::Any KoatParseVisitor::visitUb(KoatParser::UbContext *ctx) {
    return {};
}

antlrcpp::Any KoatParseVisitor::visitCond(KoatParser::CondContext *ctx) {
    return visit(ctx->formula());
}

antlrcpp::Any KoatParseVisitor::visitExpr(KoatParser::ExprContext *ctx) {
    if (ctx->INT()) {
        return Expr(Num(ctx->INT()->getText().c_str()));
    } else if (ctx->var()) {
        const auto var = any_cast<var_type>(visit(ctx->var()));
        return Expr(var);
    } else if (ctx->LPAR()) {
        return visit(ctx->expr(0));
    } else if (ctx->MINUS()) {
        if (ctx->expr().size() == 2) {
            const auto arg1 = any_cast<expr_type>(visit(ctx->expr(0)));
            const auto arg2 = any_cast<expr_type>(visit(ctx->expr(1)));
            return arg1 - arg2;
        } else {
            const auto res = any_cast<expr_type>(visit(ctx->expr(0)));
            return -res;
        }
    } else {
        const auto arg1 = any_cast<expr_type>(visit(ctx->expr(0)));
        const auto arg2 = any_cast<expr_type>(visit(ctx->expr(1)));
        if (ctx->EXP()) {
            return arg1 ^ arg2;
        } else if (ctx->TIMES()) {
            return arg1 * arg2;
        } else if (ctx->PLUS()) {
            return arg1 + arg2;
        }
    }
    throw std::invalid_argument("failed to parse expression " + ctx->getText());
}

antlrcpp::Any KoatParseVisitor::visitFormula(KoatParser::FormulaContext *ctx) {
    if (ctx->lit()) {
        return BExpression::buildTheoryLit(any_cast<lit_type>(visit(ctx->lit())));
    } else if (ctx->LPAR()) {
        return visit(ctx->formula(0));
    } else {
        const auto arg1 = any_cast<formula_type>(visit(ctx->formula(0)));
        const auto arg2 = any_cast<formula_type>(visit(ctx->formula(1)));
        if (ctx->AND()) {
            return arg1 & arg2;
        } else if (ctx->OR()) {
            return arg1 | arg2;
        }
    }
    throw std::invalid_argument("failed to parse formula " + ctx->getText());
}

antlrcpp::Any KoatParseVisitor::visitLit(KoatParser::LitContext *ctx) {
    const auto &children = ctx->children;
    if (children.size() != 3) {
        throw std::invalid_argument("expected relation: " + ctx->getText());
    }
    const auto arg1 = any_cast<expr_type>(visit(ctx->expr(0)));
    const auto op = any_cast<relop_type>(visit(children[1]));
    const auto arg2 = any_cast<expr_type>(visit(ctx->expr(1)));
    return Rel(arg1, op, arg2);
}

antlrcpp::Any KoatParseVisitor::visitRelop(KoatParser::RelopContext *ctx) {
    if (ctx->LT()) {
        return Rel::lt;
    } else if (ctx->LEQ()) {
        return Rel::leq;
    } else if (ctx->EQ()) {
        return Rel::eq;
    } else if (ctx->GEQ()) {
        return Rel::geq;
    } else if (ctx->GT()) {
        return Rel::gt;
    } else if (ctx->NEQ()) {
        return Rel::neq;
    } else {
        throw std::invalid_argument("unknown relation: " + ctx->getText());
    }
}
