#include "CHCParseVisitor.h"
#include <variant>
#include <algorithm>

antlrcpp::Any CHCParseVisitor::visitMain(CHCParser::MainContext *ctx) {
    its.setInitialLocation(its.addNamedLocation("LoAT_init"));
    sink = its.addNamedLocation("LoAT_sink");
    its.setSink(sink);
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
        vars.emplace_back(its.addFreshVariable("x" + std::to_string(i)));
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
        const BoolExpr guard = c.guard->subs(ren);
        const option<BoolExpr> simplified = guard->simplify();
        its.addRule(Rule(c.lhs.loc, simplified ? *simplified : guard, 1, c.rhs.loc, up));
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
        Res<BoolExpr> r = visit(c);
        guards.push_back(r.t & r.refinement);
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
    const std::variant<Expr, BoolExpr> res = visit(ctx->var());
    return std::get<Expr>(res);
}

antlrcpp::Any CHCParseVisitor::visitU_pred_atom(CHCParser::U_pred_atomContext *ctx) {
    const std::string name = visit(ctx->symbol());
    const option<LocationIdx> loc = its.getLocationIdx(name);
    if (!loc) {
        throw ParseError("undeclared function symbol " + name);
    }
    std::vector<Var> args;
    for (const auto &c: ctx->var()) {
        const std::variant<Expr, BoolExpr> res = visit(c);
        args.push_back(std::get<Expr>(res).someVar());
    }
    return FunApp(*loc, args);
}

antlrcpp::Any CHCParseVisitor::visitI_formula(CHCParser::I_formulaContext *ctx) {
    std::vector<BoolExpr> args;
    Res<BoolExpr> res;
    if (ctx->lets()) {
        res.refinement = visit(ctx->lets());
        const Res<BoolExpr> r = visit(ctx->i_formula(0));
        res.refinement = res.refinement & r.refinement;
        res.t = r.t;
        context.pop_back();
        return res;
    }
    for (const auto &c: ctx->i_formula()) {
        const Res<BoolExpr> r = visit(c);
        res.refinement = res.refinement & r.refinement;
        args.push_back(r.t);
    }
    if (ctx->NOT()) {
        if (args.size() != 1) {
            throw ParseError("wrong number of arguments " + ctx->getText());
        }
        res.t = !args[0];
    } else if (ctx->boolop()) {
        const BoolOp op = visit(ctx->boolop());
        switch (op) {
        case And: res.t = buildAnd(args);
            break;
        case Or: res.t = buildOr(args);
            break;
        case Equiv: {
            std::vector<BoolExpr> negated;
            for (const auto &a: args) {
                negated.push_back(!a);
            }
            res.t = buildAnd(args) | buildAnd(negated);
            break;
        }
        default: throw ParseError("unknown operator " + ctx->boolop()->getText());
        }
    } else if (ctx->ITE()) {
        if (args.size() != 3) {
            throw ParseError("wrong number of arguments " + ctx->getText());
        }
        res.t = (args[0] & args[1]) | ((!args[0]) & args[2]);
    } else if (ctx->lit()) {
        const Res<Rel> p = visit(ctx->lit());
        res.t = buildLit(p.t);
        res.refinement = res.refinement & p.refinement;
    } else if (ctx->var()) {
        const std::variant<Expr, BoolExpr> r = visit(ctx->var());
        res.t = std::get<BoolExpr>(r);
    } else if (args.size() == 1) {
        res.t = args[0];
    } else if (ctx->TRUE()) {
        res.t = True;
    } else if (ctx->FALSE()) {
        res.t = False;
    } else {
        throw ParseError("failed to parse " + ctx->getText());
    }
    return res;
}

antlrcpp::Any CHCParseVisitor::visitLet(CHCParser::LetContext *ctx) {
    if (ctx->i_formula()) {
        const std::string name = ctx->var()->getText();
        const Res<BoolExpr> res = visit(ctx->i_formula());
        context[context.size() - 1].boolean[name] = res.t;
        return res.refinement;
    } else {
        mode = BuildContext;
        const std::variant<Expr, BoolExpr> var = visit(ctx->var());
        mode = Default;
        const Res<Expr> res = visit(ctx->expr());
        context[context.size() - 1].arith.put(std::get<Expr>(var).someVar(),  res.t);
        return res.refinement;
    }
}

antlrcpp::Any CHCParseVisitor::visitLets(CHCParser::LetsContext *ctx) {
    context.push_back(Context());
    BoolExpr refinement = True;
    for (const auto &c: ctx->let()) {
        const BoolExpr r = visit(c);
        refinement = refinement & r;
    }
    return refinement;
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
    Res<Expr> p1 = visit(ctx->expr(0));
    Res<Expr> p2 = visit(ctx->expr(1));
    const RelOp op = visit(ctx->relop());
    option<Rel> res;
    switch (op) {
    case Eq: res = Rel::buildEq(p1.t, p2.t);
        break;
    case Gt: res = p1.t > p2.t;
        break;
    case Geq: res = p1.t >= p2.t;
        break;
    case Lt: res = p1.t < p2.t;
        break;
    case Leq: res = p1.t <= p2.t;
        break;
    case Neq: res = Rel::buildNeq(p1.t, p2.t);
        break;
    default: throw ParseError("unknwon operator " + ctx->relop()->getText());
    }
    return Res<Rel>{*res, p1.refinement & p2.refinement};
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
    Res<Expr> res;
    std::vector<Expr> args;
    if (ctx->lets()) {
        res.refinement = visit(ctx->lets());
        res.t = visit(ctx->expr(0));
        context.pop_back();
        return res;
    }
    for (const auto &c: ctx->expr()) {
        const Res<Expr> p = visit(c);
        args.push_back(p.t);
        res.refinement = res.refinement & p.refinement;
    }
    if (ctx->unaryop()) {
        if (args.size() != 1) throw ParseError("wrong number of arguments: " + ctx->getText());
        const UnaryOp op = visit(ctx->unaryop());
        switch (op) {
        case UnaryMinus: res.t = -args[0];
            break;
        default: throw ParseError("unknown operator " + ctx->getText());
        }
    } else if (ctx->binaryop()) {
        if (args.size() != 2) throw ParseError("wrong number of arguments: " + ctx->getText());
        const BinaryOp op = visit(ctx->binaryop());
        switch (op) {
        case Minus: res.t = args[0] - args[1];
            break;
        case Mod:
//            res = its.addFreshTemporaryVariable("mod");
//            const Var div = its.addFreshTemporaryVariable("div");
//            refinement = refinement & Rel::buildEq(args[0] - res, args[1] * div) & (0 <= res) & (res < args[1]) & Rel::buildNeq(args[1], 0);
            throw new ParseError("mod is not yet supported");
            break;
        case Div:
            throw new ParseError("div is not yet supported");
            break;
        }
    } else if (ctx->naryop()) {
        const NAryOp op = visit(ctx->naryop());
        switch (op) {
        case Plus: {
            res.t = 0;
            for (const auto &arg: args) {
                res.t = res.t + arg;
            }
            break;
        }
        case Times: {
            res.t = 1;
            for (const auto &arg: args) {
                res.t = res.t * arg;
            }
            break;
        }
        default: throw ParseError("unknown operator " + ctx->binaryop()->getText());
        }
    } else if (ctx->ITE()) {
        const Res<BoolExpr> r = visit(ctx->i_formula());
        const BoolExpr cond = r.t & r.refinement;
        res.t = its.getFreshUntrackedSymbol("ite", Expr::Int);
        res.refinement = res.refinement & ((cond & Rel::buildEq(res.t, args[0])) | ((!cond) & Rel::buildEq(res.t, args[1])));
    } else if (ctx->var()) {
        const std::variant<Expr, BoolExpr> x = visit(ctx->var());
        res.t = std::get<Expr>(x);
    } else if (ctx->INT()) {
        long l = std::stoi(ctx->getText());
        res.t = l;
    } else if (args.size() == 1) {
        res.t = args[0];
    }
    return res;
}

antlrcpp::Any CHCParseVisitor::visitUnaryop(CHCParser::UnaryopContext *ctx) {
    if (ctx->MINUS()) return UnaryMinus;
    throw ParseError("failed to parse operator " + ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitBinaryop(CHCParser::BinaryopContext *ctx) {
    if (ctx->MINUS()) return Minus;
    if (ctx->MOD()) return Mod;
    if (ctx->DIV()) return Div;
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
    if (mode == Default) {
        for (int i = context.size() - 1; i >= 0; --i) {
            const auto it = context[i].boolean.find(name);
            if (it != context[i].boolean.end()) {
                return std::variant<Expr, BoolExpr>(it->second);
            }
        }
    }
    const option<Var> res = its.getVar(name);
    if (res) {
        if (mode == Default) {
            for (int i = context.size() - 1; i >= 0; --i) {
                const auto it = context[i].arith.find(*res);
                if (it != context[i].arith.end()) {
                    return std::variant<Expr, BoolExpr>(it->second);
                }
            }
        }
        return std::variant<Expr, BoolExpr>(*res);
    }
    return std::variant<Expr, BoolExpr>(its.getFreshUntrackedSymbol(name, Expr::Int));
}
