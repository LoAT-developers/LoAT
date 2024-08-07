#include "CHCParseVisitor.h"

#include <variant>
#include <algorithm>
#include <optional>

enum relop_type {lt, leq, gt, geq, eq, neq};

using expr_type = Res<Arith::Expr>;
using formula_type = Res<Bools::Expr>;
using formula_or_expr_type = Res<std::variant<Arith::Expr, Bools::Expr>>;
using let_type = Res<Subs>;
using lets_type = Res<Subs>;
using unaryop_type = UnaryOp;
using binaryop_type = BinaryOp;
using naryop_type = NAryOp;
using pred_type = FunApp;
using lit_type = Res<Bools::Expr>;
using assert_type = Clause;
using query_type = Clause;
using symbol_type = std::string;
using tail_type = std::pair<std::optional<FunApp>, Bools::Expr>;
using head_type = FunApp;
using var_or_atom_type = std::variant<Bools::Var, FunApp>;
using boolop_type = BoolOp;
using sort_type = Sort;

template<class T>
Res<T>::Res(const T &t): t(t) {}

antlrcpp::Any CHCParseVisitor::visitMain(CHCParser::MainContext *ctx) {
    for (const auto &c: ctx->fun_decl()) {
        visit(c);
    }
    std::vector<Clause> clauses;
    for (const auto &c: ctx->chc_assert()) {
        visit(c);
        chcs.add_clause(current_clause);
    }
    for (const auto &c: ctx->chc_query()) {
        visit(c);
        chcs.add_clause(current_clause);
    }
    return chcs;
}

std::string unescape(std::string name) {
    unsigned length = name.length();
    if (name[0] == '|' && name[length - 1] == '|') {
        name = name.substr(1, length - 2);
    }
    return name;
}

antlrcpp::Any CHCParseVisitor::visitFun_decl(CHCParser::Fun_declContext *ctx) {
    const auto name = any_cast<symbol_type>(visit(ctx->symbol()));
    return name;
}

antlrcpp::Any CHCParseVisitor::visitChc_assert(CHCParser::Chc_assertContext *ctx) {
    current_clause = Clause();
    visit(ctx->chc_assert_head());
    visit(ctx->chc_assert_body());
    return {};
}

antlrcpp::Any CHCParseVisitor::visitChc_assert_head(CHCParser::Chc_assert_headContext *ctx) {
    for (const auto &c: ctx->var_decl()) {
        visit(c);
    }
    return {};
}

antlrcpp::Any CHCParseVisitor::visitChc_assert_body(CHCParser::Chc_assert_bodyContext *ctx) {
    const auto [premise, constraint] {any_cast<tail_type>(visit(ctx->chc_tail()))};
    current_clause.set_premise(premise);
    current_clause.set_constraint(constraint);
    current_clause.set_conclusion(any_cast<head_type>(visit(ctx->chc_head())));
    return {};
}

antlrcpp::Any CHCParseVisitor::visitChc_head(CHCParser::Chc_headContext *ctx) {
    return visit(ctx->u_pred_atom());
}

antlrcpp::Any CHCParseVisitor::visitChc_tail(CHCParser::Chc_tailContext *ctx) {
    std::vector<Bools::Expr> guards;
    for (const auto &c: ctx->i_formula()) {
        const auto r = any_cast<formula_type>(visit(c));
        guards.push_back(r.t);
        guards.insert(guards.end(), r.refinement.begin(), r.refinement.end());
    }
    std::optional<FunApp> lhs;
    for (const auto &c: ctx->var_or_atom()) {
        const auto v = any_cast<var_or_atom_type>(visit(c));
        std::visit(
            Overload {
                [&](const Bools::Var x) {
                    guards.push_back(bools::mkLit(bools::mk(x)));
                },
                [&](const FunApp &v) {
                    if (lhs) {
                        throw std::invalid_argument("non-linear clause " + ctx->getText());
                    } else {
                        lhs = v;
                    }
                }
            }, v);
    }
    return std::pair(lhs, bools::mkAnd(guards));
}

antlrcpp::Any CHCParseVisitor::visitChc_query(CHCParser::Chc_queryContext *ctx) {
    current_clause = Clause();
    for (const auto &c: ctx->var_decl()) {
        visit(c);
    }
    const auto [premise, constraint] {any_cast<tail_type>(visit(ctx->chc_tail()))};
    current_clause.set_premise(premise);
    current_clause.set_constraint(constraint);
    return {};
}

antlrcpp::Any CHCParseVisitor::visitVar_decl(CHCParser::Var_declContext *ctx) {
    const auto sort = any_cast<sort_type>(visit(ctx->sort()));
    const auto name = unescape(ctx->var()->getText());
    var(name, sort);
    return {};
}

antlrcpp::Any CHCParseVisitor::visitU_pred_atom(CHCParser::U_pred_atomContext *ctx) {
    const auto pred {any_cast<symbol_type>(visit(ctx->symbol()))};
    std::vector<Var> args;
    for (const auto &c: ctx->var()) {
        const auto arg {any_cast<Var>(visit(c))};
        args.push_back(arg);
    }
    return FunApp(pred, args);
}

antlrcpp::Any CHCParseVisitor::visitI_formula(CHCParser::I_formulaContext *ctx) {
    std::vector<Bools::Expr> args;
    Res<Bools::Expr> res {bot()};
    if (ctx->lets()) {
        const auto bindings = any_cast<lets_type>(visit(ctx->lets()));
        const auto formula = any_cast<formula_type>(visit(ctx->i_formula(0)));
        res.conjoin(bindings);
        res.conjoin(formula);
        res.t = bindings.t(formula.t);
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
        case And: res.t = bools::mkAnd(args);
            break;
        case Or: res.t = bools::mkOr(args);
            break;
        case Equiv: {
            std::vector<Bools::Expr> negated;
            for (const auto &a: args) {
                negated.push_back(!a);
            }
            res.t = bools::mkAnd(args) || bools::mkAnd(negated);
            break;
        }
        default: throw std::invalid_argument("unknown operator " + ctx->boolop()->getText());
        }
    } else if (ctx->ITE()) {
        if (args.size() != 3) {
            throw std::invalid_argument("wrong number of arguments " + ctx->getText());
        }
        res.t = (args[0] && args[1]) || ((!args[0]) && args[2]);
    } else if (ctx->lit()) {
        const auto lit {visit(ctx->lit())};
        res = any_cast<lit_type>(lit);
    } else if (ctx->var()) {
        const auto r = any_cast<Var>(visit(ctx->var()));
        res.t = bools::mkLit(bools::mk(std::get<Bools::Var>(r)));
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
    const auto it = current_clause.get_vars().left.find(name);
    if (it == current_clause.get_vars().left.end()) {
        std::optional<Var> var;
        switch (sort) {
        case IntType: {
            var = ArithVar::next();
            break;
        }
        case BoolType: {
            var = BoolVar::next();
            break;
        }
        default: throw std::invalid_argument("unsupported type");
        }
        current_clause.add_var(name, *var);
        return *var;
    } else {
        return it->second;
    }
}

antlrcpp::Any CHCParseVisitor::visitLet(CHCParser::LetContext *ctx) {
    const auto name = unescape(ctx->var()->getText());
    let_type ret {Subs()};
    if (ctx->formula_or_expr()) {
        const auto res = any_cast<formula_or_expr_type>(visit(ctx->formula_or_expr()));
        ret.conjoin(res);
        std::visit(
            Overload {
                [&](const Arith::Expr e) {
                    ret.t.get<Arith>().put(std::get<Arith::Var>(var(name, IntType)), e);
                },
                [&](const Bools::Expr e) {
                    ret.t.get<Bools>().put(std::get<Bools::Var>(var(name, BoolType)), e);
                }
            }, res.t);
    } else if (ctx->i_formula()) {
        const auto res = any_cast<formula_type>(visit(ctx->i_formula()));
        ret.conjoin(res);
        ret.t.get<Bools>().put(std::get<Bools::Var>(var(name, BoolType)), res.t);
    } else {
        const auto res = any_cast<expr_type>(visit(ctx->expr()));
        ret.conjoin(res);
        ret.t.get<Arith>().put(std::get<Arith::Var>(var(name, IntType)), res.t);
    }
    return ret;
}

antlrcpp::Any CHCParseVisitor::visitLets(CHCParser::LetsContext *ctx) {
    Res<Subs> res {Subs()};
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
    Res<Bools::Expr> res {bot()};
    if (ctx->formula_or_expr().size() == 2) {
        const auto p1 = any_cast<formula_or_expr_type>(visit(ctx->formula_or_expr(0)));
        res.conjoin(p1);
        const auto p2 = any_cast<formula_or_expr_type>(visit(ctx->formula_or_expr(1)));
        res.conjoin(p2);
        if (ctx->EQ()) {
            res.t = theory::mkEq(p1.t, p2.t);
        } else if (ctx->NEQ()) {
            res.t = !theory::mkEq(p1.t, p2.t);
        } else {
            throw std::invalid_argument("unknown operator");
        }
    } else if (ctx->i_formula().size() == 2) {
        const auto p1 {any_cast<formula_type>(visit(ctx->i_formula(0)))};
        res.conjoin(p1);
        const auto p2 {any_cast<formula_type>(visit(ctx->i_formula(1)))};
        res.conjoin(p2);
        if (ctx->EQ()) {
            res.t = theory::mkEq(p1.t, p2.t);
        } else if (ctx->NEQ()) {
            res.t = !theory::mkEq(p1.t, p2.t);
        } else {
            throw std::invalid_argument("unknown operator");
        }
    } else if (ctx->expr().size() == 2) {
        const auto p1 = any_cast<expr_type>(visit(ctx->expr(0)));
        res.conjoin(p1);
        const auto p2 = any_cast<expr_type>(visit(ctx->expr(1)));
        res.conjoin(p2);
        const auto op = any_cast<relop_type>(visit(ctx->relop()));
        switch (op) {
        case eq: {
            res.t = theory::mkEq(p1.t, p2.t);
            break;
        }
        case neq: {
            res.t = theory::mkNeq(p1.t, p2.t);
            break;
        }
        case gt: {
            res.t = bools::mkLit(arith::mkGt(p1.t, p2.t));
            break;
        }
        case geq: {
            res.t = bools::mkLit(arith::mkGeq(p1.t, p2.t));
            break;
        }
        case lt: {
            res.t = bools::mkLit(arith::mkLt(p1.t, p2.t));
            break;
        }
        case leq: {
            res.t = bools::mkLit(arith::mkLeq(p1.t, p2.t));
            break;
        }
        }
        return res;
    } else {
        throw std::invalid_argument("wrong number of arguments: " + ctx->getText());
    }
    return res;
}

antlrcpp::Any CHCParseVisitor::visitRelop(CHCParser::RelopContext *ctx) {
    if (ctx->EQ()) return eq;
    if (ctx->GEQ()) return geq;
    if (ctx->GT()) return gt;
    if (ctx->LEQ()) return leq;
    if (ctx->LT()) return lt;
    if (ctx->NEQ()) return neq;
    throw std::invalid_argument("failed to parse operator " + ctx->getText());
}

antlrcpp::Any CHCParseVisitor::visitFormula_or_expr(CHCParser::Formula_or_exprContext *ctx) {
    formula_or_expr_type res {bot()};
    if (ctx->var()) {
        res.t = theory::toExpr(any_cast<Var>(visitVar(ctx->var())));
    } else if (ctx->lets()) {
        const auto bindings {std::any_cast<lets_type>(visit(ctx->lets()))};
        const auto expr {std::any_cast<formula_or_expr_type>(visit(ctx->formula_or_expr()[0]))};
        res.conjoin(bindings);
        res.conjoin(expr);
        res.t = std::visit(
            Overload{
                [&](const Arith::Expr expr) {
                    return Expr{bindings.t.get<Arith>()(expr)};
                },
                [&](const Bools::Expr expr) {
                    return Expr{bindings.t(expr)};
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
        std::visit(
            Overload {
                [&](const Arith::Expr e) {
                    const auto var {ArithVar::next()};
                    res.t = var->toExpr();
                    res.refinement.push_back((r.t && theory::mkEq(var, e)) || ((!r.t) && theory::mkEq(var, std::get<Arith::Expr>(else_case.t))));
                },
                [&](const Bools::Expr e) {
                    res.t = (r.t && e) || ((!r.t) && std::get<Bools::Expr>(else_case.t));
                }
            }, then_case.t);
    }
    return res;
}

antlrcpp::Any CHCParseVisitor::visitExpr(CHCParser::ExprContext *ctx) {
    Res<Arith::Expr> res {arith::mkConst(0)};
    std::vector<Arith::Expr> args;
    if (ctx->lets()) {
        const auto bindings = any_cast<lets_type>(visit(ctx->lets()));
        const auto expr = any_cast<expr_type>(visit(ctx->expr(0)));
        res.conjoin(bindings);
        res.conjoin(expr);
        res.t = bindings.t.get<Arith>()(expr.t);
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
            const auto div {ArithVar::next()};
            const auto mod {ArithVar::next()};
            res.refinement.push_back(theory::mkEq(args[0], args[1] * div + mod));
            res.refinement.push_back(theory::mkNeq(args[1], arith::mkConst(0))); // division by zero is undefined
            bool explicit_encoding = false;
            const auto y {args[1]->isInt()};
            if (y) {
                if (*y > 0 && *y <= 100) {
                    explicit_encoding = true;
                    std::vector<Bools::Expr> refinement;
                    for (int i = 0; i < *y; i++) {
                        refinement.push_back(theory::mkEq(mod, arith::mkConst(i)));
                    }
                    res.refinement.push_back(bools::mkOr(refinement));
                }
            }
            if (!explicit_encoding) {
                res.refinement.push_back(bools::mkLit(arith::mkGeq(mod, arith::mkConst(0)))); // x mod y is non-negative
                res.refinement.push_back( // |y| > x mod y
                    bools::mkAndFromLits({arith::mkGt(args[1], arith::mkConst(0)), arith::mkGt(args[1], mod)})
                    || bools::mkAndFromLits({arith::mkLt(args[1], arith::mkConst(0)), arith::mkGt(-args[1], mod)}));
            }
            if (op == Div) {
                res.t = Arith::varToExpr(div);
            } else {
                res.t = Arith::varToExpr(mod);
            }
            break;
        }
    } else if (ctx->naryop()) {
        const auto op = any_cast<naryop_type>(visit(ctx->naryop()));
        switch (op) {
        case Plus: {
            res.t = arith::mkPlus(std::move(args));
            break;
        }
        case Times: {
            res.t = arith::mkTimes(std::move(args));
            break;
        }
        default: throw std::invalid_argument("unknown operator " + ctx->binaryop()->getText());
        }
    } else if (ctx->ITE()) {
        const auto r = any_cast<formula_type>(visit(ctx->i_formula()));
        res.conjoin(r);
        res.t = ArithVar::next();
        res.refinement.push_back((r.t && theory::mkEq(res.t, args[0])) || ((!r.t) && theory::mkEq(res.t, args[1])));
    } else if (ctx->var()) {
        const auto x = any_cast<Var>(visit(ctx->var()));
        res.t = std::get<Arith::Var>(x);
    } else if (ctx->INT()) {
        res.t = arith::mkConst(Int(ctx->getText().c_str()));
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
        return BoolType;
    } else if (ctx->INT_SORT()) {
        return IntType;
    } else {
        throw std::invalid_argument("unsupported sort: " + ctx->getText());
    }
}

antlrcpp::Any CHCParseVisitor::visitVar_or_atom(CHCParser::Var_or_atomContext *ctx) {
    if (ctx->var()) {
        const auto name {unescape(ctx->getText())};
        const auto it {current_clause.get_vars().left.find(name)};
        if (it == current_clause.get_vars().left.end()) {
            return std::variant<Bools::Var, FunApp>(FunApp(name, {}));
        } else {
            return std::variant<Bools::Var, FunApp>(std::get<Bools::Var>(it->second));
        }
    } else {
        const auto f = any_cast<pred_type>(visit(ctx->u_pred_atom()));
        return std::variant<Bools::Var, FunApp>(f);
    }
}

antlrcpp::Any CHCParseVisitor::visitVar(CHCParser::VarContext *ctx) {
    const std::string name {unescape(ctx->getText())};
    const auto res {current_clause.get_vars().left.find(name)};
    if (res != current_clause.get_vars().left.end()) {
        return res->second;
    }
    throw std::invalid_argument("unknown variable " + name);
}
