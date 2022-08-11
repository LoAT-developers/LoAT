
// Generated from CHC.g4 by ANTLR 4.7.2


#include "CHCParseVisitor.h"
#include <variant>

antlrcpp::Any CHCParseVisitor::visitMain(CHCParser::MainContext *ctx) {
    its.setInitialLocation(its.addNamedLocation("LoAT_init"));
    its.setSink(its.addNamedLocation("LoAT_sink"));
    for (const auto &c: ctx->fun_decl()) {
        visit(c);
    }
    for (const auto &c: ctx->chc_assert()) {
        visit(c);
    }
    for (const auto &c: ctx->chc_query()) {
        visit(c);
    }
    return visitChildren(ctx);
}

void checkType(CHCParser::SortContext *ctx) {
    const std::string txt = ctx->getText();
    if (txt != "Int") {
        throw CHCParseVisitor::ParseError("unknown type " + ctx->getText());
    }
}

antlrcpp::Any CHCParseVisitor::visitFun_decl(CHCParser::Fun_declContext *ctx) {
    for (unsigned long i = programVars.size(); i < ctx->sort().size(); ++i) {
        programVars.push_back(its.addFreshVariable("x" + std::to_string(i)));
    }
    for (const auto &s: ctx->sort()) {
        checkType(s);
    }
    const std::string name = ctx->symbol()->getText();
    const LocationIdx idx = its.addNamedLocation(name);
    locations[name] = idx;
    return idx;
}

antlrcpp::Any CHCParseVisitor::visitChc_assert(CHCParser::Chc_assertContext *ctx) {
    const Rule rule = visit(ctx->chc_assert_body());
    its.addRule(rule);
    return {};
}

antlrcpp::Any CHCParseVisitor::visitChc_assert_head(CHCParser::Chc_assert_headContext *ctx) {
    return {};
}

antlrcpp::Any CHCParseVisitor::visitChc_assert_body(CHCParser::Chc_assert_bodyContext *ctx) {
    mode = BuildSigma;
    const std::pair<RuleLhs, Subs> lhs = visit(ctx->chc_tail());
    sigma = lhs.second;
    mode = ApplySigma;
    const RuleRhs rhs = visit(ctx->chc_head());
    mode = Default;
    return Rule(lhs.first, rhs);
}

antlrcpp::Any CHCParseVisitor::visitChc_head(CHCParser::Chc_headContext *ctx) {
    const std::pair<LocationIdx, Subs> p = visit(ctx->u_pred_atom());
    return RuleRhs(p.first, p.second);
}

antlrcpp::Any CHCParseVisitor::visitChc_tail(CHCParser::Chc_tailContext *ctx) {
    std::vector<BoolExpr> guards;
    for (const auto &c: ctx->i_formula()) {
        guards.push_back(visit(c));
    }
    const BoolExpr guard = buildAnd(guards);
    switch (ctx->u_pred_atom().size()) {
    case 0: {
        return std::pair(RuleLhs(its.getInitialLocation(), guard), Subs());
    }
    case 1: {
        const std::pair<LocationIdx, Subs> rhs = visit(ctx->u_pred_atom(0));
        return std::pair(RuleLhs(rhs.first, guard), rhs.second);
    }
    default:
        throw ParseError("non-linear clause " + ctx->getText());
    }
}

antlrcpp::Any CHCParseVisitor::visitChc_query(CHCParser::Chc_queryContext *ctx) {
    const std::pair<RuleLhs, Subs> p = visit(ctx->chc_tail());
    its.addRule(Rule(p.first, RuleRhs(*its.getSink(), p.second)));
    return {};
}

antlrcpp::Any CHCParseVisitor::visitVar_decl(CHCParser::Var_declContext *ctx) {
    checkType(ctx->sort());
    const std::string name = ctx->symbol()->getText();
    switch (mode) {
    case ApplySigma: {
        const Var x(name);
        const auto it = sigma.find(x);
        if (it != sigma.end()) {
            return it->second;
        }
    }
    // fall-through intended
    default:
        const option<Var> opt = its.getVar(name);
        if (opt) {
            return *opt;
        }
        return its.addFreshTemporaryVariable(name);
    }
}

antlrcpp::Any CHCParseVisitor::visitU_pred_atom(CHCParser::U_pred_atomContext *ctx) {
    const LocationIdx loc = visit(ctx->symbol());
    Subs subs;
    for (unsigned i = 0; i < ctx->var().size(); ++i) {
        switch (mode) {
        case BuildSigma: {
            subs.put(visit(ctx->var(i)), programVars[i]);
            break;
        }
        default:
            subs.put(programVars[i], visit(ctx->var(i)));
            break;
        }
    }
    return std::pair(loc, subs);
}

antlrcpp::Any CHCParseVisitor::visitI_formula(CHCParser::I_formulaContext *ctx) {
    std::vector<BoolExpr> args;
    for (const auto &c: ctx->i_formula()) {
        args.push_back(visit(c));
    }
    if (ctx->NOT()) {
        if (args.size() != 1) {
            throw ParseError("wrong number of arguments " + ctx->getText());
        }
        return !args[0];
    } else if (ctx->boolop()) {
        const BoolOp op = visit(ctx->boolop());
        switch (op) {
        case And: return buildAnd(args);
        case Or: return buildOr(args);
        case Equiv: {
            std::vector<BoolExpr> negated;
            for (const auto &a: args) {
                negated.push_back(!a);
            }
            return buildAnd(args) | buildAnd(negated);
        }
        default: throw ParseError("unknown operator " + ctx->boolop()->toString());
        }
    } else if (ctx->ITE()) {
        if (args.size() != 3) {
            throw ParseError("wrong number of arguments " + ctx->getText());
        }
        return (args[0] & args[1]) | ((!args[0]) & args[2]);
    } else if (ctx->lit()) {
        return buildLit(visit(ctx->lit()));
    } else if (args.size() == 1) {
        return args[0];
    } else {
        throw ParseError("failed to parse " + ctx->toString());
    }
}

antlrcpp::Any CHCParseVisitor::visitBoolop(CHCParser::BoolopContext *ctx) {
    if (ctx->AND()) {
        return And;
    } else if (ctx->OR()) {
        return Or;
    } else if (ctx->EQ()) {
        return Equiv;
    } else {
        throw ParseError("failed to parse " + ctx->toString());
    }
}

antlrcpp::Any CHCParseVisitor::visitLit(CHCParser::LitContext *ctx) {
    if (ctx->expr().size() != 2) {
        throw ParseError("wrong number of arguments: " + ctx->toString());
    }
    const Expr arg1 = visit(ctx->expr(0));
    const Expr arg2 = visit(ctx->expr(1));
    const RelOp op = visit(ctx->relop());
    switch (op) {
    case Eq: return Rel::buildEq(arg1, arg2);
    case Gt: return arg1 > arg2;
    case Geq: return arg1 >= arg2;
    case Lt: return arg1 < arg2;
    case Leq: return arg1 <= arg2;
    case Neq: return Rel::buildNeq(arg1, arg2);
    default: throw ParseError("unknwon operator " + ctx->relop()->toString());
    }
}

antlrcpp::Any CHCParseVisitor::visitRelop(CHCParser::RelopContext *ctx) {
    if (ctx->EQ()) return Eq;
    if (ctx->GEQ()) return Geq;
    if (ctx->GT()) return Gt;
    if (ctx->LEQ()) return Leq;
    if (ctx->LT()) return Lt;
    if (ctx->NEQ()) return Neq;
    throw ParseError("failed to parse operator " + ctx->toString());
}

antlrcpp::Any CHCParseVisitor::visitExpr(CHCParser::ExprContext *ctx) {
    std::vector<Expr> args;
    for (const auto &c: ctx->expr()) {
        args.push_back(visit(c));
    }
    if (ctx->unaryop()) {
        if (args.size() != 1) throw ParseError("wrong number of arguments: " + ctx->toString());
        const UnaryOp op = visit(ctx->unaryop());
        switch (op) {
        case UnaryMinus: return -args[0];
        default: throw ParseError("unknown operator " + ctx->toString());
        }
    }
    if (ctx->binaryop()) {
        if (args.size() != 2) throw ParseError("wrong number of arguments: " + ctx->toString());
        const BinaryOp op = visit(ctx->binaryop());
        switch (op) {
        case Minus: return args[0] - args[1];
        case Mod: throw new ParseError("mod is not yet supported");
        }
    }
    if (ctx->naryop()) {
        const NAryOp op = visit(ctx->naryop());
        switch (op) {
        case Plus: {
            Expr res = 0;
            for (const auto &arg: args) {
                res = res + arg;
            }
            return res;
        }
        case Times: {
            Expr res = 1;
            for (const auto &arg: args) {
                res = res * arg;
            }
            return res;
        }
        default: throw ParseError("unknown operator " + ctx->binaryop()->toString());
        }
    }
    if (ctx->var()) {
        return visit(ctx->var());
    }
    if (ctx->INT()) {
        return visit(ctx->INT());
    }
    if (args.size() == 1) {
        return args[0];
    }
    throw ParseError("failed to parse expression " + ctx->toString());
}

antlrcpp::Any CHCParseVisitor::visitUnaryop(CHCParser::UnaryopContext *ctx) {
    if (ctx->MINUS()) return UnaryMinus;
    throw ParseError("failed to parse operator " + ctx->toString());
}

antlrcpp::Any CHCParseVisitor::visitBinaryop(CHCParser::BinaryopContext *ctx) {
    if (ctx->MINUS()) return Minus;
    if (ctx->MOD()) return Mod;
    throw ParseError("failed to parse operator " + ctx->toString());
}

antlrcpp::Any CHCParseVisitor::visitNaryop(CHCParser::NaryopContext *ctx) {
    if (ctx->PLUS()) return Plus;
    if (ctx->TIMES()) return Times;
    throw ParseError("failed to parse operator " + ctx->toString());
}

antlrcpp::Any CHCParseVisitor::visitSymbol(CHCParser::SymbolContext *ctx) {
    return loc(ctx->toString());
}

antlrcpp::Any CHCParseVisitor::visitSort(CHCParser::SortContext *ctx) {
    if (ctx->getText() != "Int") throw ParseError("unsupported sort: " + ctx->getText());
    return {};
}

antlrcpp::Any CHCParseVisitor::visitVar(CHCParser::VarContext *ctx) {
    return Var(ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitId(CHCParser::IdContext *ctx) {
    return ctx->getText();
}

ITSProblem CHCParseVisitor::getRes() const {
    return its;
}
