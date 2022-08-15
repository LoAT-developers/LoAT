#include "CHCParseVisitor.h"
#include <variant>
#include <algorithm>

antlrcpp::Any CHCParseVisitor::visitMain(CHCParser::MainContext *ctx) {
    its.setInitialLocation(its.addNamedLocation("LoAT_init"));
    sink = its.addNamedLocation("LoAT_sink");
    for (const auto &c: ctx->fun_decl()) {
        visit(c);
    }
    std::vector<Clause> clauses;
    for (const auto &c: ctx->chc_assert()) {
        clauses.push_back(visit(c));
    }
    for (const auto &c: ctx->chc_query()) {
        clauses.push_back(visit(c));
    }
    std::vector<Var> vars;
    for (unsigned i = 0; i < maxArity; ++i) {
        vars.emplace_back("x" + std::to_string(i));
    }
    for (const Clause &c: clauses) {
        Subs ren;
        for (unsigned i = 0; i < c.lhs.args.size(); ++i) {
            ren.put(c.lhs.args[i], vars[i]);
        }
        VarSet cVars{c.rhs.args.begin(), c.rhs.args.end()};
        c.guard->collectVars(cVars);
        for (const Var &x: cVars) {
            if (ren.find(x) == ren.end()) {
                ren.put(x, its.addFreshTemporaryVariable(x.get_name()));
            }
        }
        Subs up;
        for (unsigned i = 0; i < c.rhs.args.size(); ++i) {
            up.put(vars[i], Expr(c.rhs.args[i]).subs(ren));
        }
        for (unsigned i = c.rhs.args.size(); i < maxArity; ++i) {
            up.put(vars[i], its.addFreshTemporaryVariable("tmp"));
        }
        const Expr cost = c.rhs.loc == sink ? Expr::NontermSymbol : Expr(1);
        const BoolExpr guard = c.guard->subs(ren);
        const option<BoolExpr> simplified = guard->simplify();
        std::cout << "guard: " << (simplified ? *simplified : guard) << std::endl;
        its.addRule(Rule(c.lhs.loc, simplified ? *simplified : guard, cost, c.rhs.loc, up));
    }
    return its;
}

std::string unescape(std::string name) {
    unsigned length = name.length();
    if (name[0] == '|' && name[length - 1] == '|') {
        name = name.substr(1, length - 2);
    }
    return name;
}

antlrcpp::Any CHCParseVisitor::visitFun_decl(CHCParser::Fun_declContext *ctx) {
    for (const auto &s: ctx->sort()) {
        visit(s);
    }
    maxArity = std::max(maxArity, ctx->sort().size());
    const std::string name = visit(ctx->symbol());
    const LocationIdx idx = its.addNamedLocation(name);
    locations[name] = idx;
    return idx;
}

antlrcpp::Any CHCParseVisitor::visitChc_assert(CHCParser::Chc_assertContext *ctx) {
    return visit(ctx->chc_assert_body());
}

antlrcpp::Any CHCParseVisitor::visitChc_assert_head(CHCParser::Chc_assert_headContext *ctx) {
    return {};
}

antlrcpp::Any CHCParseVisitor::visitChc_assert_body(CHCParser::Chc_assert_bodyContext *ctx) {
    const std::pair<FunApp, BoolExpr> lhs = visit(ctx->chc_tail());
    const FunApp rhs = visit(ctx->chc_head());
    return Clause(lhs.first, rhs, lhs.second);
}

antlrcpp::Any CHCParseVisitor::visitChc_head(CHCParser::Chc_headContext *ctx) {
    return visit(ctx->u_pred_atom());
}

antlrcpp::Any CHCParseVisitor::visitChc_tail(CHCParser::Chc_tailContext *ctx) {
    std::vector<BoolExpr> guards;
    for (const auto &c: ctx->i_formula()) {
        guards.push_back(visit(c));
    }
    const BoolExpr guard = buildAnd(guards);
    switch (ctx->u_pred_atom().size()) {
    case 0: {
        return std::pair(FunApp(its.getInitialLocation(), {}), guard);
    }
    case 1: {
        const FunApp lhs = visit(ctx->u_pred_atom(0));
        return std::pair(lhs, guard);
    }
    default:
        throw ParseError("non-linear clause " + ctx->getText());
    }
}

antlrcpp::Any CHCParseVisitor::visitChc_query(CHCParser::Chc_queryContext *ctx) {
    const std::pair<FunApp, BoolExpr> lhs = visit(ctx->chc_tail());
    return Clause(lhs.first, FunApp(sink, {}), lhs.second);
}

antlrcpp::Any CHCParseVisitor::visitVar_decl(CHCParser::Var_declContext *ctx) {
    visit(ctx->sort());
    return visit(ctx->var());
}

antlrcpp::Any CHCParseVisitor::visitU_pred_atom(CHCParser::U_pred_atomContext *ctx) {
    const std::string name = visit(ctx->symbol());
    const option<LocationIdx> loc = its.getLocationIdx(name);
    if (!loc) {
        throw ParseError("undeclared function symbol " + name);
    }
    std::vector<Var> args;
    for (const auto &c: ctx->var()) {
        const Var x = visit(c);
        args.push_back(x);
    }
    return FunApp(*loc, args);
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
        default: throw ParseError("unknown operator " + ctx->boolop()->getText());
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
        throw ParseError("failed to parse " + ctx->getText());
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
        throw ParseError("failed to parse " + ctx->getText());
    }
}

antlrcpp::Any CHCParseVisitor::visitLit(CHCParser::LitContext *ctx) {
    if (ctx->expr().size() != 2) {
        throw ParseError("wrong number of arguments: " + ctx->getText());
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
    default: throw ParseError("unknwon operator " + ctx->relop()->getText());
    }
}

antlrcpp::Any CHCParseVisitor::visitRelop(CHCParser::RelopContext *ctx) {
    if (ctx->EQ()) return Eq;
    if (ctx->GEQ()) return Geq;
    if (ctx->GT()) return Gt;
    if (ctx->LEQ()) return Leq;
    if (ctx->LT()) return Lt;
    if (ctx->NEQ()) return Neq;
    throw ParseError("failed to parse operator " + ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitExpr(CHCParser::ExprContext *ctx) {
    std::vector<Expr> args;
    for (const auto &c: ctx->expr()) {
        args.push_back(visit(c));
    }
    if (ctx->unaryop()) {
        if (args.size() != 1) throw ParseError("wrong number of arguments: " + ctx->getText());
        const UnaryOp op = visit(ctx->unaryop());
        switch (op) {
        case UnaryMinus: return -args[0];
        default: throw ParseError("unknown operator " + ctx->getText());
        }
    }
    if (ctx->binaryop()) {
        if (args.size() != 2) throw ParseError("wrong number of arguments: " + ctx->getText());
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
        default: throw ParseError("unknown operator " + ctx->binaryop()->getText());
        }
    }
    if (ctx->var()) {
        const Var x = visit(ctx->var());
        return Expr(x);
    }
    if (ctx->INT()) {
        long l = std::stoi(ctx->getText());
        return Expr(l);
    }
    if (args.size() == 1) {
        return args[0];
    }
    throw ParseError("failed to parse expression " + ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitUnaryop(CHCParser::UnaryopContext *ctx) {
    if (ctx->MINUS()) return UnaryMinus;
    throw ParseError("failed to parse operator " + ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitBinaryop(CHCParser::BinaryopContext *ctx) {
    if (ctx->MINUS()) return Minus;
    if (ctx->MOD()) return Mod;
    throw ParseError("failed to parse operator " + ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitNaryop(CHCParser::NaryopContext *ctx) {
    if (ctx->PLUS()) return Plus;
    if (ctx->TIMES()) return Times;
    throw ParseError("failed to parse operator " + ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitSymbol(CHCParser::SymbolContext *ctx) {
    return unescape(ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitSort(CHCParser::SortContext *ctx) {
    if (ctx->getText() != "Int") throw ParseError("unsupported sort: " + ctx->getText());
    return {};
}

antlrcpp::Any CHCParseVisitor::visitVar(CHCParser::VarContext *ctx) {
    const std::string name = unescape(ctx->getText());
    const option<Var> res = varMan.getVar(name);
    if (res) return *res;
    return varMan.addFreshVariable(name);
}
