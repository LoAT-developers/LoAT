#pragma once

#include "z3.hpp"
#include "itheory.hpp"

template <ITheory... Th>
class LinearizingSolver: public Smt<Th...> {

    using TheTheory = Theory<Th...>;
    using BoolExpr = BExpr<Th...>;
    using BoolExprSet = BoolExpressionSet<Th...>;
    using Lit = typename TheTheory::Lit;
    using LitSet = theory::LitSet<Th...>;

    VarMan &varMan;
    Z3<Th...> z3;
    ExprSubs de_lin;
    std::map<Expr, NumVar> lin;
    std::stack<std::vector<NumVar>> lin_vars;

public:

    LinearizingSolver(VariableManager &varMan): varMan(varMan), z3(varMan) {
        lin_vars.push({});
    }

    option<Expr> linearize(const Expr &expr) {
        if (expr.isPoly()) {
            return {};
        } else if (expr.isAdd()) {
            Expr res(0);
            for (unsigned i = 0; i < expr.arity(); ++i) {
                const option<Expr> c = linearize(expr.op(i));
                if (c) {
                    res = res + *c;
                } else {
                    res = res + expr.op(i);
                }
            }
            return res;
        } else if (expr.isMul()) {
            Expr res(1);
            for (unsigned i = 0; i < expr.arity(); ++i) {
                const option<Expr> c = linearize(expr.op(i));
                if (c) {
                    res = res * *c;
                } else {
                    res = res * expr.op(i);
                }
            }
            return res;
        } else if (expr.isPow()) {
            if (!expr.op(0).isInt()) {
                return {};
            }
            const auto it = lin.find(expr);
            if (it != lin.end()) {
                return Expr(it->second);
            }
            const NumVar res = varMan.getFreshUntrackedSymbol<IntTheory>("exp", Expr::Int);
            lin.emplace(expr, res);
            de_lin.put(res, expr);
            lin_vars.top().push_back(res);
            return Expr(res);
        } else {
            throw std::invalid_argument("unknown arithmetic operator");
        }
    }

    BExpr<Th...> linearize(const BExpr<Th...> e) {
        const LitSet lits = e->lits();
        std::map<Lit, BExpr<Th...>> map;
        for (const Rel &lit: lits.template get<Rel>()) {
            option<Expr> lin_lhs;
            if (lit.isPoly()) {
                continue;
            }
            Expr lhs = lit.isIneq() ? lit.makeRhsZero().toGt().lhs() : lit.makeRhsZero().lhs();
            lin_lhs = linearize(lhs);
            if (lin_lhs) {
                option<Rel> lin_lit;
                if (lit.isEq()) {
                    lin_lit = Rel::buildEq(*lin_lhs, 0);
                } else if (lit.isNeq()) {
                    lin_lit = Rel::buildNeq(*lin_lhs, 0);
                } else {
                    lin_lit = Rel::buildGt(*lin_lhs, 0);
                }
                map.emplace(Lit(lit), BoolExpression<Th...>::buildTheoryLit(*lin_lit));
            }
        }
        if (map.empty()) {
            return e;
        } else {
            return e->replaceLits(map);
        }
    }

    SmtResult check() override {
        std::set<NumVar> vars = de_lin.domain();
        std::vector<NumVar> todo(vars.begin(), vars.end());
        std::map<NumVar, Num> candidates;
        auto res = z3.check();
        if (res != Sat) {
            return res;
        }
        auto it = todo.begin();
        while (true) {
            if (it == todo.end()) {
                return Sat;
            }
            const Expr expr = de_lin.get(*it);
            const Num base = expr.op(0).toNum();
            const Expr exp = expr.op(1);
            z3.push();
            z3.add(BoolExpression<Th...>::buildTheoryLit(Rel::buildEq(*it, expr)));
            if (candidates.contains(*it)) {
                z3.add(BoolExpression<Th...>::buildTheoryLit(Rel::buildEq(exp, candidates.at(*it))));
                candidates.erase(*it);
            } else {
                const Num val = z3.model().template get<IntTheory>(*it);
                Num high(1);
                while ((GiNaC::pow(base, high) - val).is_negative()) {
                    high = high + 1;
                }
                if (!(GiNaC::pow(base, high) - val).is_zero()) {
                    candidates.emplace(*it, high-1);
                }
                z3.add(BoolExpression<Th...>::buildTheoryLit(Rel::buildEq(exp, high)));
            }
            if (z3.check() == Sat) {
                ++it;
            } else {
                z3.pop();
                while (!candidates.contains(*it)) {
                    if (it == todo.begin()) {
                        for (const auto &p: lin) {
                            z3.add(BoolExpression<Th...>::buildTheoryLit(Rel::buildEq(p.first, p.second)));
                        }
                        return z3.check();
                    }
                    --it;
                    z3.pop();
                }
            }
        }
    }

    void add(const BExpr<Th...> e) override {
        z3.add(linearize(e));
    }

    void push() override {
        z3.push();
        lin_vars.push({});
    }

    void pop() override {
        z3.pop();
        for (const NumVar &x: lin_vars.top()) {
            lin.erase(de_lin.get(x));
            de_lin.erase(x);
        }
        lin_vars.pop();
    }

    Model<Th...> model() override {
        return z3.model();
    }

    void setTimeout(unsigned int timeout) override {
        z3.setTimeout(timeout);
    }

    void enableModels() override {
        z3.enableModels();
    }

    void resetSolver() override {
        z3.resetSolver();
        de_lin = ExprSubs();
        lin = {};
        lin_vars = {};
        lin_vars.push({});
    }

    ~LinearizingSolver() override {}

protected:

    std::pair<SmtResult, BoolExpressionSet<Th...>> _unsatCore(const BoolExpressionSet<Th...> &assumptions) override {
        throw std::logic_error("not supported");
    }

};
