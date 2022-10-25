#include "CHCParseVisitor.h"
#include "boollit.hpp"

#include <variant>
#include <algorithm>

using expr_type = Res<Expr>;
using formula_type = Res<BoolExpr>;
using let_type = Res<Subs>;
using lets_type = Res<Subs>;
using relop_type = Rel::RelOp;
using unaryop_type = UnaryOp;
using binaryop_type = BinaryOp;
using naryop_type = NAryOp;
using pred_type = FunApp;
using lit_type = Res<Rel>;
using assert_type = Clause;
using query_type = Clause;
using symbol_type = std::string;
using tail_type = std::pair<FunApp, BoolExpr>;
using head_type = FunApp;
using var_or_atom_type = std::variant<BoolVar, FunApp>;
using boolop_type = BoolOp;
using sort_type = Sort;

template<class T>
Res<T>::Res(const T &t): t(t) {}

template<class T>
Res<T>::Res() {}

LocationIdx CHCParseVisitor::loc(const std::string &name) {
    auto it = locations.find(name);
    if (it == locations.end()) {
        auto idx = its.addNamedLocation(name);
        locations[name] = idx;
        return idx;
    } else {
        return it->second;
    }
}

antlrcpp::Any CHCParseVisitor::visitMain(CHCParser::MainContext *ctx) {
    its.setInitialLocation(its.addNamedLocation("LoAT_init"));
    sink = its.addNamedLocation("LoAT_sink");
    its.setSink(sink);
    for (const auto &c: ctx->fun_decl()) {
        visit(c);
    }
    std::vector<Clause> clauses;
    for (const auto &c: ctx->chc_assert()) {
        clauses.push_back(any_cast<assert_type>(visit(c)));
    }
    for (const auto &c: ctx->chc_query()) {
        clauses.push_back(any_cast<query_type>(visit(c)));
    }
    std::vector<NumVar> vars;
    std::vector<BoolVar> bvars;
    for (unsigned i = 0; i < maxArity; ++i) {
        vars.emplace_back(its.addFreshVariable<IntTheory>("x" + std::to_string(i)));
        bvars.emplace_back(its.addFreshVariable<BoolTheory>("b" + std::to_string(i)));
    }
    for (const Clause &c: clauses) {
        Subs ren;
        for (unsigned i = 0; i < c.lhs.args.size(); ++i) {
            if (std::holds_alternative<NumVar>(c.lhs.args[i])) {
                ren.put<IntTheory>(std::get<NumVar>(c.lhs.args[i]), vars[i]);
            } else {
                ren.put<BoolTheory>(std::get<BoolVar>(c.lhs.args[i]), BExpression::buildTheoryLit(bvars[i]));
            }
        }
        VarSet cVars;
        for (const auto &var: c.rhs.args) {
            cVars.insert(var);
        }
        c.guard->collectVars(cVars);
        for (const auto &x: cVars) {
            if (!ren.changes(x)) {
                if (std::holds_alternative<NumVar>(x)) {
                    const auto &var = std::get<NumVar>(x);
                    ren.put<IntTheory>(var, its.addFreshTemporaryVariable<IntTheory>(var.getName()));
                } else if (std::holds_alternative<BoolVar>(x)) {
                    const auto &var = std::get<BoolVar>(x);
                    ren.put<BoolTheory>(var, BExpression::buildTheoryLit(its.addFreshTemporaryVariable<BoolTheory>(var.getName())));
                } else {
                    throw std::logic_error("unsupporte theory in CHCParseVisitor");
                }
            }
        }
        Subs up;
        for (unsigned i = 0; i < c.rhs.args.size(); ++i) {
            if (std::holds_alternative<NumVar>(c.rhs.args[i])) {
                up.put<IntTheory>(vars[i], ren.get<IntTheory>(std::get<NumVar>(c.rhs.args[i])));
            } else if (std::holds_alternative<BoolVar>(c.rhs.args[i])) {
                up.put<BoolTheory>(bvars[i], ren.get<BoolTheory>(std::get<BoolVar>(c.rhs.args[i])));
            } else {
                throw std::logic_error("unsupporte theory in CHCParseVisitor");
            }
        }
        for (unsigned i = c.rhs.args.size(); i < maxArity; ++i) {
            up.put<IntTheory>(vars[i], its.addFreshTemporaryVariable<IntTheory>("tmp"));
            up.put<BoolTheory>(bvars[i], BExpression::buildTheoryLit(its.addFreshTemporaryVariable<BoolTheory>("tmp")));
        }
        const BoolExpr guard = c.guard->subs(ren)->simplify();
        its.addRule(Rule(c.lhs.loc, guard, 1, c.rhs.loc, up));
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
    const auto name = any_cast<symbol_type>(visit(ctx->symbol()));
    const LocationIdx idx = its.addNamedLocation(name);
    locations[name] = idx;
    return idx;
}

antlrcpp::Any CHCParseVisitor::visitChc_assert(CHCParser::Chc_assertContext *ctx) {
    visit(ctx->chc_assert_head());
    return visit(ctx->chc_assert_body());
}

antlrcpp::Any CHCParseVisitor::visitChc_assert_head(CHCParser::Chc_assert_headContext *ctx) {
    for (const auto &c: ctx->var_decl()) {
        visit(c);
    }
    return {};
}

antlrcpp::Any CHCParseVisitor::visitChc_assert_body(CHCParser::Chc_assert_bodyContext *ctx) {
    const auto lhs = any_cast<tail_type>(visit(ctx->chc_tail()));
    const auto rhs = any_cast<head_type>(visit(ctx->chc_head()));
    return Clause(lhs.first, rhs, lhs.second);
}

antlrcpp::Any CHCParseVisitor::visitChc_head(CHCParser::Chc_headContext *ctx) {
    return visit(ctx->u_pred_atom());
}

antlrcpp::Any CHCParseVisitor::visitChc_tail(CHCParser::Chc_tailContext *ctx) {
    std::vector<BoolExpr> guards;
    for (const auto &c: ctx->i_formula()) {
        const auto r = any_cast<formula_type>(visit(c));
        guards.push_back(r.t & r.refinement);
    }
    option<FunApp> lhs;
    for (const auto &c: ctx->var_or_atom()) {
        const auto v = any_cast<var_or_atom_type>(visit(c));
        if (std::holds_alternative<BoolVar>(v)) {
            guards.push_back(BExpression::buildTheoryLit(BoolLit(std::get<BoolVar>(v))));
        } else if (lhs) {
            throw std::invalid_argument("non-linear clause " + ctx->getText());
        } else {
            lhs = std::get<FunApp>(v);
        }
    }
    return std::pair(lhs.get_value_or(FunApp(its.getInitialLocation(), {})), BExpression::buildAnd(guards));
}

antlrcpp::Any CHCParseVisitor::visitChc_query(CHCParser::Chc_queryContext *ctx) {
    for (const auto &c: ctx->var_decl()) {
        visit(c);
    }
    const auto lhs = any_cast<tail_type>(visit(ctx->chc_tail()));
    return Clause(lhs.first, FunApp(sink, {}), lhs.second);
}

antlrcpp::Any CHCParseVisitor::visitVar_decl(CHCParser::Var_declContext *ctx) {
    const auto sort = any_cast<sort_type>(visit(ctx->sort()));
    const auto name = ctx->var()->getText();
    switch (sort) {
    case Bool:
        boolVar(name);
        break;
    case Int:
        var(name);
        break;
    }
    return {};
}

antlrcpp::Any CHCParseVisitor::visitU_pred_atom(CHCParser::U_pred_atomContext *ctx) {
    const auto name = any_cast<symbol_type>(visit(ctx->symbol()));
    const option<LocationIdx> loc = its.getLocationIdx(name);
    if (!loc) {
        throw std::invalid_argument("undeclared function symbol " + name);
    }
    std::vector<Var> args;
    for (const auto &c: ctx->var()) {
        args.push_back(any_cast<Var>(visit(c)));
    }
    return FunApp(*loc, args);
}

antlrcpp::Any CHCParseVisitor::visitI_formula(CHCParser::I_formulaContext *ctx) {
    std::vector<BoolExpr> args;
    Res<BoolExpr> res;
    if (ctx->lets()) {
        const auto bindings = any_cast<lets_type>(visit(ctx->lets()));
        const auto formula = any_cast<formula_type>(visit(ctx->i_formula(0)));
        res.refinement = bindings.refinement & formula.refinement;
        res.t = formula.t->subs(bindings.t);
        return res;
    }
    for (const auto &c: ctx->i_formula()) {
        const auto r = any_cast<formula_type>(visit(c));
        res.refinement = res.refinement & r.refinement;
        args.push_back(r.t);
    }
    if (ctx->NOT()) {
        if (args.size() != 1) {
            throw std::invalid_argument("wrong number of arguments " + ctx->getText());
        }
        res.t = !args[0];
    } else if (ctx->boolop()) {
        const auto op = any_cast<boolop_type>(visit(ctx->boolop()));
        switch (op) {
        case And: res.t = BExpression::buildAnd(args);
            break;
        case Or: res.t = BExpression::buildOr(args);
            break;
        case Equiv: {
            std::vector<BoolExpr> negated;
            for (const auto &a: args) {
                negated.push_back(!a);
            }
            res.t = BExpression::buildAnd(args) | BExpression::buildAnd(negated);
            break;
        }
        default: throw std::invalid_argument("unknown operator " + ctx->boolop()->getText());
        }
    } else if (ctx->ITE()) {
        if (args.size() != 3) {
            throw std::invalid_argument("wrong number of arguments " + ctx->getText());
        }
        res.t = (args[0] & args[1]) | ((!args[0]) & args[2]);
    } else if (ctx->lit()) {
        const auto p = any_cast<lit_type>(visit(ctx->lit()));
        res.t = BExpression::buildTheoryLit(p.t);
        res.refinement = res.refinement & p.refinement;
    } else if (ctx->var()) {
        const auto r = any_cast<Var>(visit(ctx->var()));
        res.t = BExpression::buildTheoryLit(BoolLit(std::get<BoolVar>(r)));
    } else if (args.size() == 1) {
        res.t = args[0];
    } else if (ctx->TRUE()) {
        res.t = True;
    } else if (ctx->FALSE()) {
        res.t = False;
    } else {
        throw std::invalid_argument("failed to parse " + ctx->getText());
    }
    return res;
}

BoolVar CHCParseVisitor::boolVar(const std::string &name) {
    const auto it = bvars.find(name);
    if (it == bvars.end()) {
        const auto var = its.getFreshUntrackedSymbol<BoolTheory>(name, Expr::Bool);
        bvars.emplace(name, var);
        return var;
    } else {
        return it->second;
    }
}

NumVar CHCParseVisitor::var(const std::string &name) {
    const auto it = vars.find(name);
    if (it == vars.end()) {
        const auto var = its.getFreshUntrackedSymbol<IntTheory>(name, Expr::Int);
        vars.emplace(name, var);
        return var;
    } else {
        return it->second;
    }
}

antlrcpp::Any CHCParseVisitor::visitLet(CHCParser::LetContext *ctx) {
    const auto name = ctx->var()->getText();
    let_type ret;
    if (ctx->i_formula()) {
        const auto res = any_cast<formula_type>(visit(ctx->i_formula()));
        ret.t.get<BoolTheory>().put(boolVar(name), res.t);
        ret.refinement = res.refinement;
    } else {
        const auto res = any_cast<expr_type>(visit(ctx->expr()));
        ret.t.get<IntTheory>().put(var(name), res.t);
        ret.refinement = res.refinement;
    }
    return ret;
}

antlrcpp::Any CHCParseVisitor::visitLets(CHCParser::LetsContext *ctx) {
    Res<Subs> res;
    for (const auto &c: ctx->let()) {
        const auto r = any_cast<let_type>(visit(c));
        res.refinement = res.refinement & r.refinement;
        res.t = res.t.compose(r.t); // TODO should be union
    }
    return res;
}

antlrcpp::Any CHCParseVisitor::visitBoolop(CHCParser::BoolopContext *ctx) {
    if (ctx->AND()) {
        return And;
    } else if (ctx->OR()) {
        return Or;
    } else if (ctx->EQ()) {
        return Equiv;
    } else {
        throw std::invalid_argument("failed to parse " + ctx->getText());
    }
}

antlrcpp::Any CHCParseVisitor::visitLit(CHCParser::LitContext *ctx) {
    if (ctx->expr().size() != 2) {
        throw std::invalid_argument("wrong number of arguments: " + ctx->getText());
    }
    const auto p1 = any_cast<expr_type>(visit(ctx->expr(0)));
    const auto p2 = any_cast<expr_type>(visit(ctx->expr(1)));
    const auto op = any_cast<relop_type>(visit(ctx->relop()));
    Res<Rel> res {Rel(p1.t, op, p2.t)};
    res.refinement = p1.refinement & p2.refinement;
    return res;
}

antlrcpp::Any CHCParseVisitor::visitRelop(CHCParser::RelopContext *ctx) {
    if (ctx->EQ()) return Rel::eq;
    if (ctx->GEQ()) return Rel::geq;
    if (ctx->GT()) return Rel::gt;
    if (ctx->LEQ()) return Rel::leq;
    if (ctx->LT()) return Rel::lt;
    if (ctx->NEQ()) return Rel::neq;
    throw std::invalid_argument("failed to parse operator " + ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitExpr(CHCParser::ExprContext *ctx) {
    Res<Expr> res;
    std::vector<Expr> args;
    if (ctx->lets()) {
        const auto bindings = any_cast<lets_type>(visit(ctx->lets()));
        const auto expr = any_cast<expr_type>(visit(ctx->expr(0)));
        res.refinement = bindings.refinement & expr.refinement;
        res.t = expr.t.subs(bindings.t.get<IntTheory>());
        return res;
    }
    for (const auto &c: ctx->expr()) {
        const auto p = any_cast<expr_type>(visit(c));
        args.push_back(p.t);
        res.refinement = res.refinement & p.refinement;
    }
    if (ctx->unaryop()) {
        if (args.size() != 1) throw std::invalid_argument("wrong number of arguments: " + ctx->getText());
        const auto op = any_cast<unaryop_type>(visit(ctx->unaryop()));
        switch (op) {
        case UnaryMinus: res.t = -args[0];
            break;
        default: throw std::invalid_argument("unknown operator " + ctx->getText());
        }
    } else if (ctx->binaryop()) {
        if (args.size() != 2) throw std::invalid_argument("wrong number of arguments: " + ctx->getText());
        const auto op = any_cast<binaryop_type>(visit(ctx->binaryop()));
        switch (op) {
        case Minus: res.t = args[0] - args[1];
            break;
        case Mod:
//            res = its.addFreshTemporaryVariable("mod");
//            const Var div = its.addFreshTemporaryVariable("div");
//            refinement = refinement & Rel::buildEq(args[0] - res, args[1] * div) & (0 <= res) & (res < args[1]) & Rel::buildNeq(args[1], 0);
            throw new std::invalid_argument("mod is not yet supported");
            break;
        case Div:
            throw new std::invalid_argument("div is not yet supported");
            break;
        }
    } else if (ctx->naryop()) {
        const auto op = any_cast<naryop_type>(visit(ctx->naryop()));
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
        default: throw std::invalid_argument("unknown operator " + ctx->binaryop()->getText());
        }
    } else if (ctx->ITE()) {
        const auto r = any_cast<formula_type>(visit(ctx->i_formula()));
        const BoolExpr cond = r.t & r.refinement;
        res.t = its.getFreshUntrackedSymbol<IntTheory>("ite", Expr::Int);
        res.refinement = res.refinement & ((cond & Rel::buildEq(res.t, args[0])) | ((!cond) & Rel::buildEq(res.t, args[1])));
    } else if (ctx->var()) {
        const auto x = any_cast<Var>(visit(ctx->var()));
        res.t = std::get<NumVar>(x);
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
    throw std::invalid_argument("failed to parse operator " + ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitBinaryop(CHCParser::BinaryopContext *ctx) {
    if (ctx->MINUS()) return Minus;
    if (ctx->MOD()) return Mod;
    if (ctx->DIV()) return Div;
    throw std::invalid_argument("failed to parse operator " + ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitNaryop(CHCParser::NaryopContext *ctx) {
    if (ctx->PLUS()) return Plus;
    if (ctx->TIMES()) return Times;
    throw std::invalid_argument("failed to parse operator " + ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitSymbol(CHCParser::SymbolContext *ctx) {
    return unescape(ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitSort(CHCParser::SortContext *ctx) {
    if (ctx->BOOL_SORT()) {
        return Bool;
    } else if (ctx->INT_SORT()) {
        return Int;
    } else {
        throw std::invalid_argument("unsupported sort: " + ctx->getText());
    }
}

antlrcpp::Any CHCParseVisitor::visitVar_or_atom(CHCParser::Var_or_atomContext *ctx) {
    if (ctx->var()) {
        const option<LocationIdx> loc = its.getLocationIdx(ctx->getText());
        if (loc) {
            return std::variant<BoolVar, FunApp>(FunApp(*loc, {}));
        } else {
            return std::variant<BoolVar, FunApp>(std::get<BoolVar>(any_cast<Var>(visit(ctx->var()))));
        }
    } else {
        const auto f = any_cast<pred_type>(visit(ctx->u_pred_atom()));
        return std::variant<BoolVar, FunApp>(f);
    }
}

antlrcpp::Any CHCParseVisitor::visitVar(CHCParser::VarContext *ctx) {
    const std::string name = unescape(ctx->getText());
    const auto theoryRes = vars.find(name);
    if (theoryRes != vars.end()) {
        return Var(theoryRes->second);
    }
    const auto boolRes = bvars.find(name);
    if (boolRes != bvars.end()) {
        return Var(boolRes->second);
    }
    throw std::invalid_argument("unknown variable " + name);
}
