#include "CINTParseVisitor.h"
#include "config.hpp"

CINTParseVisitor::CINTParseVisitor() {
    const auto loc = its.addLocation();
    its.setInitialLocation(loc);
    current = loc;
}

std::any CINTParseVisitor::visitNondet(CINTParser::NondetContext *ctx) {
    return {};
}

std::any CINTParseVisitor::visitNum_expr(CINTParser::Num_exprContext *ctx) {
    if (ctx->num_expr().size() > 0) {
        const auto lhs = std::any_cast<Expr>(visit(ctx->num_expr(0)));
        if (ctx->num_expr().size() == 2) {
            const auto rhs = std::any_cast<Expr>(visit(ctx->num_expr(1)));
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
        return Expr(vars.at(ctx->getText()));
    } else if (ctx->ZERO()) {
        return Expr(0);
    } else if (ctx->POS()) {
        return Expr(std::stoi(ctx->getText()));
    } else if (ctx->nondet()) {
        return Expr(NumVar::next());
    }
    throw std::invalid_argument("unknown expression " + ctx->getText());
}

std::any CINTParseVisitor::visitBool_expr(CINTParser::Bool_exprContext *ctx) {
    if (ctx->lit()) {
        return BExpression::buildTheoryLit(std::any_cast<Rel>(visit(ctx->lit())))->simplify();
    } else if (ctx->TRUE()) {
        return BExpression::True;
    } else if (ctx->FALSE()) {
        return BExpression::False;
    } else {
        const auto lhs = std::any_cast<BoolExpr>(visit(ctx->bool_expr(0)));
        if (ctx->bool_expr().size() == 2) {
            const auto rhs = std::any_cast<BoolExpr>(visit(ctx->bool_expr(1)));
            if (ctx->AND()) {
                return lhs & rhs;
            } else if (ctx->OR()) {
                return lhs | rhs;
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
    const auto lhs = std::any_cast<Expr>(visit(ctx->num_expr(0)));
    const auto op = std::any_cast<Rel::RelOp>(visit(ctx->relop()));
    const auto rhs = std::any_cast<Expr>(visit(ctx->num_expr(1)));
    return Rel(lhs, op, rhs);
}

std::any CINTParseVisitor::visitRelop(CINTParser::RelopContext *ctx) {
    const auto op = ctx->getText();
    if (op == "==") {
        return Rel::eq;
    } else if (op == "!=") {
        return Rel::neq;
    } else if (op == ">") {
        return Rel::gt;
    } else if (op == ">=") {
        return Rel::geq;
    } else if (op == "<") {
        return Rel::lt;
    } else if (op == "<=") {
        return Rel::leq;
    } else {
        throw std::invalid_argument("unknown comparison " + ctx->getText());
    }
}

std::any CINTParseVisitor::visitLoop(CINTParser::LoopContext *ctx) {
    auto cond = std::any_cast<BoolExpr>(visit(ctx->bool_expr()));
    const auto pre = current;
    const auto loc_var = its.getLocVar();
    const auto cost_var = its.getCostVar();
    if (ctx->instructions()) {
        const auto loc = its.addLocation();
        auto continue_cond = cond & Rel::buildEq(loc_var, pre);
        auto body = Subs::build<IntTheory>(loc_var, loc);
        if (Config::Analysis::complexity()) {
            body.put<IntTheory>(cost_var, Expr(cost_var) + 1);
        }
        its.addRule(Rule(continue_cond, body), pre);
        current = loc;
        visit(ctx->instructions());
        const auto backjump_cond = BExpression::buildTheoryLit(Rel::buildEq(loc_var, current));
        const auto backjump = Subs::build<IntTheory>(loc_var, pre);
        its.addRule(Rule(backjump_cond, backjump), current);
    } else {
        const auto nonterm_cond = BExpression::buildTheoryLit(Rel::buildEq(loc_var, pre));
        Subs nonterm;
        if (Config::Analysis::complexity()) {
            nonterm.put<IntTheory>(cost_var, Expr(cost_var) + 1);
        }
        its.addRule(Rule(nonterm_cond, nonterm), pre);
    }
    const auto post = its.addLocation();
    const auto exit_cond = (!cond)->simplify() & Rel::buildEq(loc_var, pre);
    auto exit = Subs::build<IntTheory>(loc_var, post);
    if (Config::Analysis::complexity()) {
        exit.put<IntTheory>(cost_var, Expr(cost_var) + 1);
    }
    its.addRule(Rule(exit_cond, exit), pre);
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
    const auto post = its.addLocation();
    const auto loc_var = its.getLocVar();
    const auto cost_var = its.getCostVar();
    if (ctx->then()) {
        const auto loc = its.addLocation();
        const auto consequence_cond = cond & Rel::buildEq(loc_var, pre);
        auto consequence = Subs::build<IntTheory>(loc_var, loc);
        if (Config::Analysis::complexity()) {
            consequence.put<IntTheory>(cost_var, Expr(cost_var) + 1);
        }
        its.addRule(Rule(consequence_cond, consequence), pre);
        current = loc;
        visit(ctx->then());
        const auto exit_cond = cond & Rel::buildEq(loc_var, current);
        auto exit = Subs::build<IntTheory>(loc_var, post);
        its.addRule(Rule(exit_cond, exit), current);
    } else {
        const auto exit_cond = cond & Rel::buildEq(loc_var, pre);
        auto exit = Subs::build<IntTheory>(loc_var, post);
        if (Config::Analysis::complexity()) {
            exit.put<IntTheory>(cost_var, Expr(cost_var) + 1);
        }
        its.addRule(Rule(exit_cond, exit), pre);
    }
    if (ctx->else_()) {
        const auto loc = its.addLocation();
        const auto alternative_cond = (!cond)->simplify() & Rel::buildEq(loc_var, pre);
        auto alternative = Subs::build<IntTheory>(loc_var, loc);
        if (Config::Analysis::complexity()) {
            alternative.put<IntTheory>(cost_var, Expr(cost_var) + 1);
        }
        its.addRule(Rule(alternative_cond, alternative), pre);
        current = loc;
        visit(ctx->else_());
        const auto exit_cond = cond & Rel::buildEq(loc_var, current);
        auto exit = Subs::build<IntTheory>(loc_var, post);
        its.addRule(Rule(exit_cond, exit), current);
    } else {
        const auto exit_cond = (!cond)->simplify() & Rel::buildEq(loc_var, pre);
        auto exit = Subs::build<IntTheory>(loc_var, post);
        if (Config::Analysis::complexity()) {
            exit.put<IntTheory>(cost_var, Expr(cost_var) + 1);
        }
        its.addRule(Rule(exit_cond, exit), pre);
    }
    current = post;
    return {};
}

std::any CINTParseVisitor::visitAssignment(CINTParser::AssignmentContext *ctx) {
    const auto &name = ctx->V()->getText();
    const auto expr = std::any_cast<Expr>(visit(ctx->num_expr()));
    const auto loc = its.addLocation();
    const auto loc_var = its.getLocVar();
    const auto cond = BExpression::buildTheoryLit(Rel::buildEq(loc_var, current));
    auto up = Subs::build<IntTheory>(vars.at(name), expr);
    up.put<IntTheory>(loc_var, loc);
    if (Config::Analysis::complexity()) {
        const auto cost_var = its.getCostVar();
        up.put<IntTheory>(cost_var, Expr(cost_var) + 1);
    }
    const Rule rule{cond, up};
    current = loc;
    its.addRule(rule, current);
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
        vars.emplace(name, NumVar::nextProgVar());
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
