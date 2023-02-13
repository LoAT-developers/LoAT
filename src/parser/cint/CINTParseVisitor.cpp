#include "CINTParseVisitor.h"

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
        return Expr(its.addFreshTemporaryVariable<IntTheory>("nondet"));
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
    const auto cond = std::any_cast<BoolExpr>(visit(ctx->bool_expr()));
    const auto pre = current;
    if (ctx->instructions()) {
        const auto loc = its.addLocation();
        its.addRule(Rule(pre, cond, 1, loc, Subs()));
        current = loc;
        visit(ctx->instructions());
        its.addRule(Rule(current, BExpression::True, 0, pre, Subs()));
    } else {
        its.addRule(Rule(pre, cond, 1, pre, Subs()));
    }
    const auto post = its.addLocation();
    its.addRule(Rule(pre, (!cond)->simplify(), 1, post, Subs()));
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
    if (ctx->then()) {
        const auto loc = its.addLocation();
        its.addRule(Rule(pre, cond, 1, loc, Subs()));
        current = loc;
        visit(ctx->then());
        its.addRule(Rule(current, BExpression::True, 0, post, Subs()));
    } else {
        its.addRule(Rule(pre, cond, 1, post, Subs()));
    }
    if (ctx->else_()) {
        const auto loc = its.addLocation();
        its.addRule(Rule(pre, (!cond)->simplify(), 1, loc, Subs()));
        current = loc;
        visit(ctx->else_());
        its.addRule(Rule(current, BExpression::True, 0, post, Subs()));
    } else {
        its.addRule(Rule(pre, (!cond)->simplify(), 1, post, Subs()));
    }
    current = post;
    return {};
}

std::any CINTParseVisitor::visitAssignment(CINTParser::AssignmentContext *ctx) {
    const auto &name = ctx->V()->getText();
    const auto expr = std::any_cast<Expr>(visit(ctx->num_expr()));
    const auto loc = its.addLocation();
    const Rule rule(current, BExpression::True, 1, loc, Subs::build<IntTheory>(vars.at(name), expr));
    current = loc;
    its.addRule(rule);
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
        vars.emplace(name, its.addFreshVariable<IntTheory>(name));
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
