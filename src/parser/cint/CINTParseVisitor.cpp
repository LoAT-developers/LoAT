#include "CINTParseVisitor.h"
#include "config.hpp"
#include "theory.hpp"

enum relop_type {lt, leq, gt, geq, eq, neq};

CINTParseVisitor::CINTParseVisitor() {
    const auto loc = its->addLocation();
    its->setInitialLocation(loc);
    current = loc;
}

std::any CINTParseVisitor::visitNondet(CINTParser::NondetContext *ctx) {
    return {};
}

std::any CINTParseVisitor::visitNum_expr(CINTParser::Num_exprContext *ctx) {
    if (ctx->num_expr().size() > 0) {
        const auto lhs = std::any_cast<Arith::Expr>(visit(ctx->num_expr(0)));
        if (ctx->num_expr().size() == 2) {
            const auto rhs = std::any_cast<Arith::Expr>(visit(ctx->num_expr(1)));
            if (ctx->MINUS()) {
                return lhs - rhs;
            } else if (ctx->PLUS()) {
                return lhs + rhs;
            } else if (ctx->MULT()) {
                return lhs * rhs;
            }
        } else {
            assert(ctx->num_expr().size() == 1);
            if (ctx->MINUS()) {
                return -lhs;
            } else {
                return lhs;
            }
        }
    } else if (ctx->V()) {
        return vars.at(ctx->getText())->toExpr();
    } else if (ctx->ZERO()) {
        return arith::mkConst(0);
    } else if (ctx->POS()) {
        return arith::mkConst(Int(ctx->getText()));
    } else if (ctx->nondet()) {
        return ArithVar::next()->toExpr();
    }
    throw std::invalid_argument("unknown expression " + ctx->getText());
}

std::any CINTParseVisitor::visitBool_expr(CINTParser::Bool_exprContext *ctx) {
    if (ctx->lit()) {
        return bools::mkLit(std::any_cast<ArithLit>(visit(ctx->lit())))->simplify();
    } else if (ctx->TRUE()) {
        return top();
    } else if (ctx->FALSE()) {
        return bot();
    } else {
        const auto lhs = std::any_cast<BoolExpr>(visit(ctx->bool_expr(0)));
        if (ctx->bool_expr().size() == 2) {
            const auto rhs = std::any_cast<BoolExpr>(visit(ctx->bool_expr(1)));
            if (ctx->AND()) {
                return lhs && rhs;
            } else if (ctx->OR()) {
                return lhs || rhs;
            }
        } else {
            assert(ctx->bool_expr().size() == 1);
            if (ctx->NOT()) {
                return (!lhs)->simplify();
            } else {
                return lhs;
            }
        }
    }
    throw std::invalid_argument("unknown Boolean expression " + ctx->getText());
}

std::any CINTParseVisitor::visitLit(CINTParser::LitContext *ctx) {
    const auto arg1 = std::any_cast<Arith::Expr>(visit(ctx->num_expr(0)));
    const auto op = std::any_cast<relop_type>(visit(ctx->relop()));
    const auto arg2 = std::any_cast<Arith::Expr>(visit(ctx->num_expr(1)));
    switch (op) {
    case lt: return bools::mkLit(arith::mkLt(arg1, arg2));
    case leq: return bools::mkLit(arith::mkLeq(arg1, arg2));
    case gt: return bools::mkLit(arith::mkGt(arg1, arg2));
    case geq: return bools::mkLit(arith::mkGeq(arg1, arg2));
    case eq: return theory::mkEq(arg1, arg2);
    case neq: return theory::mkNeq(arg1, arg2);
    }
    throw std::invalid_argument("unknown relation");
}

std::any CINTParseVisitor::visitRelop(CINTParser::RelopContext *ctx) {
    const auto op = ctx->getText();
    if (op == "==") {
        return relop_type::eq;
    } else if (op == "!=") {
        return relop_type::neq;
    } else if (op == ">") {
        return relop_type::gt;
    } else if (op == ">=") {
        return relop_type::geq;
    } else if (op == "<") {
        return relop_type::lt;
    } else if (op == "<=") {
        return relop_type::leq;
    } else {
        throw std::invalid_argument("unknown comparison " + ctx->getText());
    }
}

std::any CINTParseVisitor::visitLoop(CINTParser::LoopContext *ctx) {
    auto cond = std::any_cast<BoolExpr>(visit(ctx->bool_expr()));
    const auto pre = current;
    const auto cost_var = its->getCostVar();
    if (ctx->instructions()) {
        const auto loc = its->addLocation();
        auto continue_cond = cond && theory::mkEq(ArithVar::loc_var, arith::mkConst(pre));
        auto body = Subs::build<Arith>(ArithVar::loc_var, arith::mkConst(loc));
        if (Config::Analysis::complexity()) {
            body.put<Arith>(cost_var, cost_var->toExpr() + arith::mkConst(1));
        }
        its->addRule(Rule(continue_cond, body), pre);
        current = loc;
        visit(ctx->instructions());
        const auto backjump_cond = theory::mkEq(ArithVar::loc_var, arith::mkConst(current));
        const auto backjump = Subs::build<Arith>(ArithVar::loc_var, arith::mkConst(pre));
        its->addRule(Rule(backjump_cond, backjump), current);
    } else {
        const auto nonterm_cond = theory::mkEq(ArithVar::loc_var, arith::mkConst(pre));
        Subs nonterm;
        if (Config::Analysis::complexity()) {
            nonterm.put<Arith>(cost_var, cost_var->toExpr() + arith::mkConst(1));
        }
        its->addRule(Rule(nonterm_cond, nonterm), pre);
    }
    const auto post = its->addLocation();
    const auto exit_cond = (!cond)->simplify() && theory::mkEq(ArithVar::loc_var, arith::mkConst(pre));
    auto exit = Subs::build<Arith>(ArithVar::loc_var, arith::mkConst(post));
    if (Config::Analysis::complexity()) {
        exit.put<Arith>(cost_var, cost_var->toExpr() + arith::mkConst(1));
    }
    its->addRule(Rule(exit_cond, exit), pre);
    current = post;
    return {};
}

std::any CINTParseVisitor::visitThen(CINTParser::ThenContext *ctx) {
    if (ctx->instructions()) {
        visit(ctx->instructions());
    }
    return {};
}

std::any CINTParseVisitor::visitElse(CINTParser::ElseContext *ctx) {
    if (ctx->instructions()) {
        visit(ctx->instructions());
    }
    return {};
}

std::any CINTParseVisitor::visitCondition(CINTParser::ConditionContext *ctx) {
    const auto cond = std::any_cast<BoolExpr>(visit(ctx->bool_expr()));
    const auto pre = current;
    const auto post = its->addLocation();
    const auto cost_var = its->getCostVar();
    if (ctx->then()) {
        const auto loc = its->addLocation();
        const auto consequence_cond = cond && theory::mkEq(ArithVar::loc_var, arith::mkConst(pre));
        auto consequence = Subs::build<Arith>(ArithVar::loc_var, arith::mkConst(loc));
        if (Config::Analysis::complexity()) {
            consequence.put<Arith>(cost_var, cost_var->toExpr() + arith::mkConst(1));
        }
        its->addRule(Rule(consequence_cond, consequence), pre);
        current = loc;
        visit(ctx->then());
        const auto exit_cond = cond && theory::mkEq(ArithVar::loc_var, arith::mkConst(current));
        auto exit = Subs::build<Arith>(ArithVar::loc_var, arith::mkConst(post));
        its->addRule(Rule(exit_cond, exit), current);
    } else {
        const auto exit_cond = cond && theory::mkEq(ArithVar::loc_var, arith::mkConst(pre));
        auto exit = Subs::build<Arith>(ArithVar::loc_var, arith::mkConst(post));
        if (Config::Analysis::complexity()) {
            exit.put<Arith>(cost_var, cost_var->toExpr() + arith::mkConst(1));
        }
        its->addRule(Rule(exit_cond, exit), pre);
    }
    if (ctx->else_()) {
        const auto loc = its->addLocation();
        const auto alternative_cond = (!cond)->simplify() && theory::mkEq(ArithVar::loc_var, arith::mkConst(pre));
        auto alternative = Subs::build<Arith>(ArithVar::loc_var, arith::mkConst(loc));
        if (Config::Analysis::complexity()) {
            alternative.put<Arith>(cost_var, cost_var->toExpr() + arith::mkConst(1));
        }
        its->addRule(Rule(alternative_cond, alternative), pre);
        current = loc;
        visit(ctx->else_());
        const auto exit_cond = cond && theory::mkEq(ArithVar::loc_var, arith::mkConst(current));
        auto exit = Subs::build<Arith>(ArithVar::loc_var, arith::mkConst(post));
        its->addRule(Rule(exit_cond, exit), current);
    } else {
        const auto exit_cond = (!cond)->simplify() && theory::mkEq(ArithVar::loc_var, arith::mkConst(pre));
        auto exit = Subs::build<Arith>(ArithVar::loc_var, arith::mkConst(post));
        if (Config::Analysis::complexity()) {
            exit.put<Arith>(cost_var, cost_var->toExpr() + arith::mkConst(1));
        }
        its->addRule(Rule(exit_cond, exit), pre);
    }
    current = post;
    return {};
}

std::any CINTParseVisitor::visitAssignment(CINTParser::AssignmentContext *ctx) {
    const auto &name = ctx->V()->getText();
    const auto expr = std::any_cast<Arith::Expr>(visit(ctx->num_expr()));
    const auto loc = its->addLocation();
    const auto cond = theory::mkEq(ArithVar::loc_var, arith::mkConst(current));
    auto up = Subs::build<Arith>(vars.at(name), expr);
    up.put<Arith>(ArithVar::loc_var, arith::mkConst(loc));
    if (Config::Analysis::complexity()) {
        const auto cost_var = its->getCostVar();
        up.put<Arith>(cost_var, cost_var->toExpr() + arith::mkConst(1));
    }
    const Rule rule{cond, up};
    its->addRule(rule, current);
    current = loc;
    return {};
}

std::any CINTParseVisitor::visitInstruction(CINTParser::InstructionContext *ctx) {
    if (ctx->loop()) {
        visit(ctx->loop());
    } else if (ctx->condition()) {
        visit(ctx->condition());
    } else if (ctx->assignment()) {
        visit(ctx->assignment());
    }
    return {};
}

std::any CINTParseVisitor::visitDeclaration(CINTParser::DeclarationContext *ctx)  {
    for (const auto &v: ctx->V()) {
        const auto &name = v->getText();
        vars.emplace(name, ArithVar::nextProgVar());
    }
    return {};
}

std::any CINTParseVisitor::visitDeclarations(CINTParser::DeclarationsContext *ctx) {
    for (const auto &x: ctx->declaration()) {
        visit(x);
    }
    return {};
}

std::any CINTParseVisitor::visitInstructions(CINTParser::InstructionsContext *ctx) {
    for (const auto &x: ctx->instruction()) {
        visit(x);
    }
    return {};
}

std::any CINTParseVisitor::visitPre(CINTParser::PreContext *ctx) {
    return {};
}

std::any CINTParseVisitor::visitPost(CINTParser::PostContext *ctx) {
    return {};
}

std::any CINTParseVisitor::visitMain(CINTParser::MainContext *ctx) {
    if (ctx->declarations()) {
        visit(ctx->declarations());
    }
    if (ctx->instructions()) {
        visit(ctx->instructions());
    }
    return its;
}
