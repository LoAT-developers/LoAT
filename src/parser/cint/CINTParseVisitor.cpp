#include "CINTParseVisitor.h"

CINTParseVisitor::CINTParseVisitor() {
    const auto loc = its.addLocation();
    its.setInitialLocation(loc);
    current = loc;
}

std::any CINTParseVisitor::visitNondet(CINTParser::NondetContext *ctx) {
    return {};
}

std::any CINTParseVisitor::visitNum_atom(CINTParser::Num_atomContext *ctx) {
    if (ctx->ZERO()) {
        return Expr(0);
    } else if (ctx->POS()) {
        return Expr(std::stoi(ctx->getText()));
    } else if (ctx->nondet()) {
        const auto var = its.addFreshTemporaryVariable<IntTheory>("nondet");
        return Expr(var);
    } else if (ctx->V()) {
        return Expr(vars.at(ctx->V()->getText()));
    } else if (ctx->num_atom()) {
        const auto res = std::any_cast<Expr>(visit(ctx->num_atom()));
        return ctx->MINUS() ? -res : res;
    } else {
        throw std::invalid_argument("unknown num atom " + ctx->getText());
    }
}

std::any CINTParseVisitor::visitMult_expr(CINTParser::Mult_exprContext *ctx) {
    Expr expr = 1;
    for (const auto &a: ctx->num_atom()) {
        expr = expr * std::any_cast<Expr>(visit(a));
    }
    return expr;
}

std::any CINTParseVisitor::visitPm_mult_expr(CINTParser::Pm_mult_exprContext *ctx) {
    auto expr = std::any_cast<Expr>(visit(ctx->mult_expr()));
    if (ctx->MINUS()) {
        expr = -expr;
    }
    return expr;
}

std::any CINTParseVisitor::visitNum_expr(CINTParser::Num_exprContext *ctx) {
    auto expr = std::any_cast<Expr>(visit(ctx->mult_expr()));
    if (ctx->MINUS()) {
        expr = -expr;
    }
    for (const auto &pm: ctx->pm_mult_expr()) {
        expr = expr + std::any_cast<Expr>(visit(pm));
    }
    return expr;
}

std::any CINTParseVisitor::visitBool_atom(CINTParser::Bool_atomContext *ctx) {
    if (ctx->TRUE()) {
        return BExpression::True;
    } else if (ctx->FALSE()) {
        return BExpression::False;
    } else {
        const auto lhs = std::any_cast<Expr>(visit(ctx->num_expr(0)));
        option<Rel> rel;
        if (ctx->BO()) {
            const auto rhs = std::any_cast<Expr>(visit(ctx->num_expr(1)));
            const auto txt = ctx->BO()->getText();
            if (txt == "<=") {
                rel = Rel::buildLeq(lhs, rhs);
            } else if (txt == ">=") {
                rel = Rel::buildGeq(lhs, rhs);
            } else if (txt == "<") {
                rel = Rel::buildLt(lhs, rhs);
            } else if (txt == ">") {
                rel = Rel::buildGt(lhs, rhs);
            } else if (txt == "==") {
                rel = Rel::buildEq(lhs, rhs);
            } else if (txt == "!=") {
                rel = Rel::buildNeq(lhs, rhs);
            } else {
                throw std::invalid_argument("unknown relation " + txt);
            }
        } else {
            rel = Rel::buildNeq(lhs, 0);
        }
        return BExpression::buildTheoryLit(*rel)->simplify();
    }
}

std::any CINTParseVisitor::visitAnd_expr(CINTParser::And_exprContext *ctx) {
    std::vector<BoolExpr> lits;
    for (const auto &l: ctx->bool_atom()) {
        lits.push_back(std::any_cast<BoolExpr>(visit(l)));
    }
    return BExpression::buildAnd(lits);
}

std::any CINTParseVisitor::visitBool_expr(CINTParser::Bool_exprContext *ctx) {
    if (ctx->NOT()) {
        const auto atom = std::any_cast<BoolLit>(visit(ctx->bool_atom()));
        return BExpression::buildTheoryLit(atom)->negation()->simplify();
    } else {
        std::vector<BoolExpr> disj;
        for (const auto &a: ctx->and_expr()) {
            disj.push_back(std::any_cast<BoolExpr>(visit(a)));
        }
        return BExpression::buildOr(disj);
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

std::any CINTParseVisitor::visitCondition(CINTParser::ConditionContext *ctx) {
    const auto cond = std::any_cast<BoolExpr>(visit(ctx->bool_expr()));
    const auto pre = current;
    const auto post = its.addLocation();
    if (ctx->instructions(0)) {
        const auto loc = its.addLocation();
        its.addRule(Rule(pre, cond, 1, loc, Subs()));
        current = loc;
        visit(ctx->instructions(0));
        its.addRule(Rule(current, BExpression::True, 0, post, Subs()));
    } else {
        its.addRule(Rule(pre, cond, 1, post, Subs()));
    }
    if (ctx->instructions(1)) {
        const auto loc = its.addLocation();
        its.addRule(Rule(pre, (!cond)->simplify(), 1, loc, Subs()));
        current = loc;
        visit(ctx->instructions(1));
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
    visit(ctx->declaration());
    if (ctx->declarations()) {
        visit(ctx->declarations());
    }
    return {};
}

std::any CINTParseVisitor::visitInstructions(CINTParser::InstructionsContext *ctx) {
    visit(ctx->instruction());
    if (ctx->instructions()) {
        visit(ctx->instructions());
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
    visit(ctx->declarations());
    visit(ctx->instructions());
    return its;
}
