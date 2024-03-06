#include "CHCParseVisitor.h"
#include "boollit.hpp"
#include "expr.hpp"

#include <variant>
#include <algorithm>
#include <optional>

using expr_type = Res<Expr>;
using formula_type = Res<BoolExpr>;
using formula_or_expr_type = Res<std::variant<Expr, BoolExpr>>;
using let_type = Res<Subs>;
using lets_type = Res<Subs>;
using relop_type = Rel::RelOp;
using unaryop_type = UnaryOp;
using binaryop_type = BinaryOp;
using naryop_type = NAryOp;
using pred_type = FunApp;
using lit_type = Res<BoolExpr>;
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
        auto idx = its->addNamedLocation(name);
        locations[name] = idx;
        return idx;
    } else {
        return it->second;
    }
}

antlrcpp::Any CHCParseVisitor::visitMain(CHCParser::MainContext *ctx) {
    its->setInitialLocation(its->addNamedLocation("LoAT_init"));
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
    for (unsigned i = 0; i < max_int_arity; ++i) {
        vars.emplace_back(NumVar::nextProgVar());
    }
    for (unsigned i = 0; i < max_bool_arity; ++i) {
        bvars.emplace_back(BoolVar::nextProgVar());
    }
    for (const Clause &c: clauses) {
        Subs ren;
        // replace the arguments of the body predicate with the corresponding program variables
        unsigned bool_arg {0};
        unsigned int_arg {0};
        for (unsigned i = 0; i < c.lhs.args.size(); ++i) {
            if (std::holds_alternative<NumVar>(c.lhs.args[i])) {
                ren.put<IntTheory>(std::get<NumVar>(c.lhs.args[i]), vars[int_arg]);
                ++int_arg;
            } else {
                ren.put<BoolTheory>(std::get<BoolVar>(c.lhs.args[i]), BExpression::buildTheoryLit(BoolLit(bvars[bool_arg])));
                ++bool_arg;
            }
        }
        VarSet cVars;
        for (const auto &var: c.rhs.args) {
            cVars.insert(var);
        }
        c.guard->collectVars(cVars);
        // replace all other variables from the clause with temporary variables
        for (const auto &x: cVars) {
            if (!ren.contains(x)) {
                if (std::holds_alternative<NumVar>(x)) {
                    const auto &var = std::get<NumVar>(x);
                    ren.put<IntTheory>(var, NumVar::next());
                } else if (std::holds_alternative<BoolVar>(x)) {
                    const auto &var = std::get<BoolVar>(x);
                    ren.put<BoolTheory>(var, BExpression::buildTheoryLit(BoolLit(BoolVar::next())));
                } else {
                    throw std::logic_error("unsupported theory in CHCParseVisitor");
                }
            }
        }
        bool_arg = 0;
        int_arg = 0;
        Subs up;
        for (unsigned i = 0; i < c.rhs.args.size(); ++i) {
            if (std::holds_alternative<NumVar>(c.rhs.args[i])) {
                up.put<IntTheory>(vars[int_arg], ren.get<IntTheory>(std::get<NumVar>(c.rhs.args[i])));
                ++int_arg;
            } else if (std::holds_alternative<BoolVar>(c.rhs.args[i])) {
                up.put<BoolTheory>(bvars[bool_arg], ren.get<BoolTheory>(std::get<BoolVar>(c.rhs.args[i])));
                ++bool_arg;
            } else {
                throw std::logic_error("unsupported theory in CHCParseVisitor");
            }
        }
        for (unsigned i = int_arg; i < max_int_arity; ++i) {
            up.put<IntTheory>(vars[i], NumVar::next());
        }
        for (unsigned i = bool_arg; i < max_bool_arity; ++i) {
            up.put<BoolTheory>(bvars[i], BExpression::buildTheoryLit(BoolLit(BoolVar::next())));
        }
        up.put(NumVar::loc_var, c.rhs.loc);
        const BoolExpr guard = c.guard->subs(ren)->simplify() & Rel::buildEq(NumVar::loc_var, c.lhs.loc);
        its->addRule(Rule(guard, up), c.lhs.loc);
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
    unsigned long int_arity {0};
    unsigned long bool_arity {0};
    for (const auto &s: ctx->sort()) {
        switch (std::any_cast<sort_type>(visit(s))) {
        case Int:
            ++int_arity;
            break;
        case Bool:
            ++bool_arity;
            break;
        }
    }
    max_int_arity = std::max(max_int_arity, int_arity);
    max_bool_arity = std::max(max_bool_arity, bool_arity);
    const auto name = any_cast<symbol_type>(visit(ctx->symbol()));
    const LocationIdx idx = its->addNamedLocation(name);
    locations[name] = idx;
    return idx;
}

antlrcpp::Any CHCParseVisitor::visitChc_assert(CHCParser::Chc_assertContext *ctx) {
    visit(ctx->chc_assert_head());
    const auto res = visit(ctx->chc_assert_body());
    vars.clear();
    return res;
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
        guards.push_back(r.t);
        guards.insert(guards.end(), r.refinement.begin(), r.refinement.end());
    }
    std::optional<FunApp> lhs;
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
    return std::pair(lhs.value_or(FunApp(its->getInitialLocation(), {})), BExpression::buildAnd(guards));
}

antlrcpp::Any CHCParseVisitor::visitChc_query(CHCParser::Chc_queryContext *ctx) {
    for (const auto &c: ctx->var_decl()) {
        visit(c);
    }
    const auto lhs = any_cast<tail_type>(visit(ctx->chc_tail()));
    vars.clear();
    return Clause(lhs.first, FunApp(its->getSink(), {}), lhs.second);
}

antlrcpp::Any CHCParseVisitor::visitVar_decl(CHCParser::Var_declContext *ctx) {
    const auto sort = any_cast<sort_type>(visit(ctx->sort()));
    const auto name = unescape(ctx->var()->getText());
    var(name, sort);
    return {};
}

antlrcpp::Any CHCParseVisitor::visitU_pred_atom(CHCParser::U_pred_atomContext *ctx) {
    const auto name = any_cast<symbol_type>(visit(ctx->symbol()));
    const std::optional<LocationIdx> loc = its->getLocationIdx(name);
    if (!loc) {
        throw std::invalid_argument("undeclared function symbol " + name);
    }
    std::vector<Var> args;
    std::unordered_set<Var> arg_set;
    for (const auto &c: ctx->var()) {
        const auto arg {any_cast<Var>(visit(c))};
        args.push_back(arg);
        if (!arg_set.insert(arg).second) {
            throw std::invalid_argument("arguments of predicate are not distinct");
        }
    }
    return FunApp(*loc, args);
}

antlrcpp::Any CHCParseVisitor::visitI_formula(CHCParser::I_formulaContext *ctx) {
    std::vector<BoolExpr> args;
    Res<BoolExpr> res;
    if (ctx->lets()) {
        const auto bindings = any_cast<lets_type>(visit(ctx->lets()));
        const auto formula = any_cast<formula_type>(visit(ctx->i_formula(0)));
        res.conjoin(bindings);
        res.conjoin(formula);
        res.t = formula.t->subs(bindings.t);
        res.subsRefinement(bindings.t);
        return res;
    }
    for (const auto &c: ctx->i_formula()) {
        const auto r = any_cast<formula_type>(visit(c));
        res.conjoin(r);
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
        res = any_cast<lit_type>(visit(ctx->lit()));
    } else if (ctx->var()) {
        const auto r = any_cast<Var>(visit(ctx->var()));
        res.t = BExpression::buildTheoryLit(BoolLit(std::get<BoolVar>(r)));
    } else if (args.size() == 1) {
        res.t = args[0];
    } else if (ctx->TRUE()) {
        res.t = top();
    } else if (ctx->FALSE()) {
        res.t = bot();
    } else {
        throw std::invalid_argument("failed to parse " + ctx->getText());
    }
    return res;
}

Var CHCParseVisitor::var(const std::string &name, Sort sort) {
    const auto it = vars.find(name);
    if (it == vars.end()) {
        std::optional<Var> var;
        switch (sort) {
        case Int: {
            var = NumVar::next();
            break;
        }
        case Bool: {
            var = BoolVar::next();
            break;
        }
        default: throw std::invalid_argument("unsupported type");
        }
        vars.emplace(name, *var);
        return *var;
    } else {
        return it->second;
    }
}

antlrcpp::Any CHCParseVisitor::visitLet(CHCParser::LetContext *ctx) {
    const auto name = unescape(ctx->var()->getText());
    let_type ret;
    if (ctx->formula_or_expr()) {
        const auto res = any_cast<formula_or_expr_type>(visit(ctx->formula_or_expr()));
        ret.conjoin(res);
        if (std::holds_alternative<Expr>(res.t)) {
            ret.t.get<IntTheory>().put(std::get<NumVar>(var(name, Int)), std::get<Expr>(res.t));
        } else {
            ret.t.get<BoolTheory>().put(std::get<BoolVar>(var(name, Bool)), std::get<BoolExpr>(res.t));
        }
    } else if (ctx->i_formula()) {
        const auto res = any_cast<formula_type>(visit(ctx->i_formula()));
        ret.conjoin(res);
        ret.t.get<BoolTheory>().put(std::get<BoolVar>(var(name, Bool)), res.t);
    } else {
        const auto res = any_cast<expr_type>(visit(ctx->expr()));
        ret.conjoin(res);
        ret.t.get<IntTheory>().put(std::get<NumVar>(var(name, Int)), res.t);
    }
    return ret;
}

antlrcpp::Any CHCParseVisitor::visitLets(CHCParser::LetsContext *ctx) {
    Res<Subs> res;
    for (const auto &c: ctx->let()) {
        const auto r = any_cast<let_type>(visit(c));
        res.conjoin(r);
        res.t = res.t.unite(r.t);
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
    Res<BoolExpr> res;
    if (ctx->formula_or_expr().size() == 2) {
        const auto p1 = any_cast<formula_or_expr_type>(visit(ctx->formula_or_expr(0)));
        res.conjoin(p1);
        const auto p2 = any_cast<formula_or_expr_type>(visit(ctx->formula_or_expr(1)));
        res.conjoin(p2);
        if (ctx->EQ()) {
            res.t = expr::mkEq(p1.t, p2.t);
        } else if (ctx->NEQ()) {
            res.t = !expr::mkEq(p1.t, p2.t);
        } else {
            throw std::invalid_argument("unknown operator");
        }
    } else if (ctx->i_formula().size() == 2) {
        const auto p1 {any_cast<formula_type>(visit(ctx->i_formula(0)))};
        res.conjoin(p1);
        const auto p2 {any_cast<formula_type>(visit(ctx->i_formula(1)))};
        res.conjoin(p2);
        if (ctx->EQ()) {
            res.t = expr::mkEq(p1.t, p2.t);
        } else if (ctx->NEQ()) {
            res.t = !expr::mkEq(p1.t, p2.t);
        } else {
            throw std::invalid_argument("unknown operator");
        }
    } else if (ctx->expr().size() == 2) {
        const auto p1 = any_cast<expr_type>(visit(ctx->expr(0)));
        res.conjoin(p1);
        const auto p2 = any_cast<expr_type>(visit(ctx->expr(1)));
        res.conjoin(p2);
        const auto op = any_cast<relop_type>(visit(ctx->relop()));
        res.t = BExpression::buildTheoryLit(Rel(p1.t, op, p2.t));
    } else {
        throw std::invalid_argument("wrong number of arguments: " + ctx->getText());
    }
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

antlrcpp::Any CHCParseVisitor::visitFormula_or_expr(CHCParser::Formula_or_exprContext *ctx) {
    formula_or_expr_type res;
    if (ctx->var()) {
        res.t = expr::toExpr(any_cast<Var>(visitVar(ctx->var())));
    } else if (ctx->lets()) {
        const auto bindings {std::any_cast<lets_type>(visit(ctx->lets()))};
        const auto expr {std::any_cast<formula_or_expr_type>(visit(ctx->formula_or_expr()[0]))};
        res.conjoin(bindings);
        res.conjoin(expr);
        res.t = std::visit(Overload{
                               [&bindings](const Expr &expr) {
                                   return std::variant<Expr, BoolExpr>(expr.subs(bindings.t.get<IntTheory>()));
                               },
                               [&bindings](const BoolExpr &expr) {
                                   return std::variant<Expr, BoolExpr>(expr->subs(bindings.t));
                               }
                           }, expr.t);
        res.subsRefinement(bindings.t);
    } else if (ctx->ITE()) {
        const auto r {any_cast<formula_type>(visit(ctx->i_formula()))};
        res.conjoin(r);
        const auto then_case {any_cast<formula_or_expr_type>(visit(ctx->formula_or_expr()[0]))};
        res.conjoin(then_case);
        const auto else_case {any_cast<formula_or_expr_type>(visit(ctx->formula_or_expr()[1]))};
        res.conjoin(else_case);
        if (std::holds_alternative<Expr>(then_case.t)) {
            const auto var {NumVar::next()};
            res.t = expr::toExpr(var);
            res.refinement.push_back((r.t & Rel::buildEq(var, std::get<Expr>(then_case.t))) | ((!r.t) & Rel::buildEq(var, std::get<Expr>(else_case.t))));
        } else {
            res.t = (r.t & std::get<BoolExpr>(then_case.t)) | ((!r.t) & std::get<BoolExpr>(else_case.t));
        }
    }
    return res;
}

antlrcpp::Any CHCParseVisitor::visitExpr(CHCParser::ExprContext *ctx) {
    Res<Expr> res;
    std::vector<Expr> args;
    if (ctx->lets()) {
        const auto bindings = any_cast<lets_type>(visit(ctx->lets()));
        const auto expr = any_cast<expr_type>(visit(ctx->expr(0)));
        res.conjoin(bindings);
        res.conjoin(expr);
        res.t = expr.t.subs(bindings.t.get<IntTheory>());
        res.subsRefinement(bindings.t);
        return res;
    }
    for (const auto &c: ctx->expr()) {
        const auto p = any_cast<expr_type>(visit(c));
        args.push_back(p.t);
        res.conjoin(p);
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
        case Div:
        case Mod:
            const NumVar div = NumVar::next();
            const NumVar mod = NumVar::next();
            res.refinement.push_back(BExpression::buildTheoryLit(Rel::buildEq(args[0], args[1] * div + mod)));
            res.refinement.push_back(BExpression::buildTheoryLit(Rel::buildNeq(args[1], 0))); // division by zero is undefined
            bool explicit_encoding = false;
            if (args[1].isInt()) {
                Num y = args[1].toNum();
                if (y > 0 && y <= 100) {
                    explicit_encoding = true;
                    std::vector<Rel> refinement;
                    for (int i = 0; i < y; i++) {
                        refinement.push_back(Rel::buildEq(mod, i));
                    }
                    res.refinement.push_back(BExpression::buildOrFromLits(refinement));
                }
            }
            if (!explicit_encoding) {
                res.refinement.push_back(BExpression::buildTheoryLit(Rel::buildGeq(mod, 0))); // x mod y is non-negative
                res.refinement.push_back( // |y| > x mod y
                    (BExpression::buildTheoryLit(Rel::buildGt(args[1], 0)) & Rel::buildGt(args[1], mod))
                    | (BExpression::buildTheoryLit(Rel::buildLt(args[1], 0)) & Rel::buildGt(-args[1], mod)));
            }
            if (op == Div) {
                res.t = IntTheory::varToExpr(div);
            } else {
                res.t = IntTheory::varToExpr(mod);
            }
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
        res.conjoin(r);
        res.t = NumVar::next();
        res.refinement.push_back((r.t & Rel::buildEq(res.t, args[0])) | ((!r.t) & Rel::buildEq(res.t, args[1])));
    } else if (ctx->var()) {
        const auto x = any_cast<Var>(visit(ctx->var()));
        res.t = std::get<NumVar>(x);
    } else if (ctx->INT()) {
        res.t = Expr(Num(ctx->getText().c_str()));
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
        const std::optional<LocationIdx> loc = its->getLocationIdx(unescape(ctx->getText()));
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
    const auto res = vars.find(name);
    if (res != vars.end()) {
        return res->second;
    }
    throw std::invalid_argument("unknown variable " + name);
}
