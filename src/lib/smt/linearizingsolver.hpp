#pragma once

#include "z3.hpp"
#include "itheory.hpp"

#include <iostream>
#include <fstream>

/**
 * Wrapper around Z3 that first linearizes exponentials and then instantiates their exponent with candidates
 * that are derived from the model of the linearization (if any).
 */
template <ITheory... Th>
class LinearizingSolver: public Smt<Th...> {

    using TheTheory = Theory<Th...>;
    using BoolExpr = BExpr<Th...>;
    using BoolExprSet = BoolExpressionSet<Th...>;
    using Lit = typename TheTheory::Lit;
    using LitSet = theory::LitSet<Th...>;

    Z3<Th...> z3;
    Z3<Th...> printer;

    /**
     * reverses the linearization
     */
    ExprSubs de_lin;

    /**
     * maps non-polynomial terms to their linearization (so far, just fresh variables)
     */
    std::map<Expr, NumVar> lin;

    /**
     * all fresh variables that have been created to linearize terms
     * push() adds a new element to the stack in order to support incremental solving
     */
    std::stack<std::vector<NumVar>> lin_vars;

    std::stack<unsigned> push_stack {{0}};

    /**
     * variables that occur in exponents of linearized subexpressions
     */
    std::set<NumVar> exp_vars;

    unsigned counter {0};
    std::string filename;

public:

    LinearizingSolver(unsigned timeout, const std::string &filename): z3(timeout), printer(timeout), filename(filename) {
        lin_vars.push({});
    }

    std::optional<Expr> linearize(const Expr &expr) {
        if (expr.isPoly()) {
            return {};
        } else if (expr.isAdd()) {
            Expr res(0);
            for (unsigned i = 0; i < expr.arity(); ++i) {
                const std::optional<Expr> c = linearize(expr.op(i));
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
                const std::optional<Expr> c = linearize(expr.op(i));
                if (c) {
                    res = res * *c;
                } else {
                    res = res * expr.op(i);
                }
            }
            return res;
        } else if (expr.isPow()) {
            if (!expr.op(0).isRationalConstant()) {
                // we just support exponentials with constant bases, so far
                return {};
            }
            const auto it = lin.find(expr);
            if (it != lin.end()) {
                return Expr(it->second);
            }
            const auto vars = expr.op(1).vars();
            exp_vars.insert(vars.begin(), vars.end());
            const auto res {NumVar::next()};
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
            std::optional<Expr> lin_lhs;
            if (lit.isPoly()) {
                continue;
            }
            Expr lhs = lit.isIneq() ? lit.makeRhsZero().toG().lhs() : lit.makeRhsZero().lhs();
            lin_lhs = linearize(lhs);
            if (lin_lhs) {
                std::optional<Rel> lin_lit;
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

    void z3_push() {
        z3.push();
        push_stack.top()++;
    }

    void z3_pop() {
        z3.pop();
        push_stack.top()--;
    }

    SmtResult check() override {
        if (!lin.empty()) {
            std::ofstream out;
            std::string name {"./benchmarks/" + filename + "_" + std::to_string(counter)};
            out.open(name);
            std::cout << "writing " << name << std::endl;
            ++counter;
            printer.print(out);
            out.close();
        }
        std::set<NumVar> vars = de_lin.domain();
        std::vector<NumVar> todo(vars.begin(), vars.end());
        std::map<NumVar, Num> candidates;
        const auto res = z3.check();
        if (res != Sat) {
            // if the linearization is unsat, we are done
            // if the linearization is unknown, there's nothing we can do
            return res;
        }
        // points to the variable that we try to handle in the current iteration
        auto it = todo.begin();
        while (true) {
            if (it == todo.end()) {
                // we've successfully handled all variables -- done
                return Sat;
            }
            const Expr expr = de_lin.get(*it);
            const Num base = expr.op(0).toNum();
            const Expr exp = expr.op(1);
            if (candidates.contains(*it)) {
                // we've stored a candidate for the exponent earlier --> try it
                z3_push();
                z3.add(BoolExpression<Th...>::buildTheoryLit(Rel::buildEq(*it, expr)));
                z3.add(BoolExpression<Th...>::buildTheoryLit(Rel::buildEq(exp, Expr(candidates.at(*it)))));
                candidates.erase(*it);
            } else {
                // derive new candidates from the model
                const Num val = z3.model().template get<IntTheory>(*it);
                Num high(1);
                while ((GiNaC::pow(base, high) - val).is_negative()) {
                    high = high + 1;
                }
                // now we have base^high >= val and base^(high-1) < val
                if (!(GiNaC::pow(base, high) - val).is_zero()) {
                    // if base^high > val, store high-1 as candidate for later
                    candidates.emplace(*it, high-1);
                }
                // try to set the exponent to high
                z3_push();
                z3.add(BoolExpression<Th...>::buildTheoryLit(Rel::buildEq(*it, expr)));
                z3.add(BoolExpression<Th...>::buildTheoryLit(Rel::buildEq(exp, Expr(high))));
            }
            if (z3.check() == Sat) {
                ++it;
            } else {
                // the current candidate failed, backtrack
                z3_pop();
                while (!candidates.contains(*it)) {
                    if (it == todo.begin()) {
                        // we've exhausted all candidate instantiations
                        // get a model for the linearization
                        auto res = z3.check();
                        if (res == Sat) {
                            const auto model = z3.model();
                            // add the semantics of the linearized variables
                            for (const auto &p: lin) {
                                z3.add(BoolExpression<Th...>::buildTheoryLit(Rel::buildEq(p.first, p.second)));
                            }
                            z3_push();
                            // fix the values of the variables appearing in exponents according to the model
                            for (const auto &x: exp_vars) {
                                z3.add(BoolExpression<Th...>::buildTheoryLit(Rel::buildEq(x, Expr(model.template get<IntTheory>(x)))));
                            }
                            res = z3.check();
                            if (res == Sat) {
                                return Sat;
                            }
                            z3_pop();
                            // failed, drop the values of the variables appearing in exponents
                            // last resort: apply z3 to the original problem
                            return z3.check();
                        } else {
                            return res;
                        }
                    }
                    --it;
                    z3_pop();
                }
            }
        }
    }

    void add(const BExpr<Th...> e) override {
        z3.add(linearize(e));
        printer.add(e);
    }

    void push() override {
        z3.push();
        printer.push();
        lin_vars.push({});
        push_stack.push(0);
    }

    void pop() override {
        for (unsigned i = 0; i < push_stack.top(); ++i) {
            z3.pop();
        }
        push_stack.pop();
        z3.pop();
        for (const NumVar &x: lin_vars.top()) {
            lin.erase(de_lin.get(x));
            de_lin.erase(x);
        }
        printer.pop();
        lin_vars.pop();
    }

    Model<Th...> model(const std::optional<const VarSet> &vars = {}) override {
        return z3.model(vars);
    }

    void setTimeout(unsigned int timeout) override {
        z3.setTimeout(timeout);
    }

    void enableModels() override {
        z3.enableModels();
    }

    void resetSolver() override {
        z3.resetSolver();
        printer.resetSolver();
        de_lin = ExprSubs();
        lin = {};
        lin_vars = {};
        lin_vars.push({});
    }

    ~LinearizingSolver() override {}

    std::ostream& print(std::ostream& os) const override {
        os << "Z3:" << std::endl;
        z3.print(os);
        os << "linearization:" << std::endl;
        return std::cout << de_lin << std::endl;
    }

    void setSeed(unsigned seed) override {
        z3.setSeed(seed);
    }

};
