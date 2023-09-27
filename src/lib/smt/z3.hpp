#pragma once

#include "smt.hpp"
#include "z3context.hpp"
#include "exprtosmt.hpp"
#include "thset.hpp"

template <ITheory... Th>
class Z3 : public Smt<Th...> {

    using TheTheory = Theory<Th...>;
    using BoolExpr = BExpr<Th...>;
    using BoolExprSet = BoolExpressionSet<Th...>;
    using Lit = typename TheTheory::Lit;

    static const bool log {false};

public:

    Z3(unsigned timeout): timeout(timeout), ctx(z3Ctx), solver(z3Ctx) {
        updateParams();
        exps.emplace_back();
    }

    void add(const BExpr<Th...> e) override {
        if (log) std::cout << "add - e: " << e << std::endl;
        const auto flat {e->map([](const auto &lit) {
            return std::visit(Overload{
                [](const Rel &lit) {
                    const auto lhs {lit.makeRhsZero().lhs()};
                    const auto [flat_lhs, repl] {lhs.flattenExp()};
                    std::vector<Rel> rels;
                    rels.emplace_back(flat_lhs, lit.relOp(), 0);
                    for (const auto &[var, e]: repl) {
                        rels.push_back(Rel::buildEq(var, e));
                    }
                    return BoolExpression<Th...>::buildAndFromLits(rels);
                },
                [](const auto &lit) {
                    return BoolExpression<Th...>::buildTheoryLit(lit);
                }
            }, lit);
        })};
        if (log) std::cout << "add - flat: " << flat << std::endl;
        const auto to_add {ExprToSmt<z3::expr, Th...>::convert(flat, ctx)};
        if (log) std::cout << "add - to_add: " << to_add.simplify() << std::endl;
        solver.add(to_add);
        const auto exps {ctx.clearExps()};
        if (!exps.empty()) {
            this->exps.back().insert(exps.begin(), exps.end());
            for (const auto &e: exps) {
                const GiNaC::numeric base {e.arg(0).to_string().c_str()};
                const auto exp {e.arg(1)};
                if (base == 0) {
                    solver.add(z3::implies(exp >= 0, e == 0));
                } else if (base == 1) {
                    solver.add(z3::implies(exp >= 0, e == 1));
                } else {
                    solver.add(e > 0);
                    solver.add(z3::implies(exp == 0, e == 1));
                    solver.add(z3::implies(exp > 0, e > exp));
                }
            }
        }
    }

    void push() override {
        if (log) std::cout << "push" << std::endl;
        solver.push();
        exps.emplace_back();
    }

    void pop() override {
        if (log) std::cout << "pop" << std::endl;
        solver.pop();
        exps.pop_back();
    }

    struct HashExpr {
        size_t operator()(const z3::expr &e) const noexcept {
            return e.hash();
        }
    };

    struct ExprEqual {
        bool operator()(const z3::expr &e1, const z3::expr &e2) const noexcept {
            return z3::eq(e1, e2);
        }
    };

    SmtResult check() override {
        const auto exp {ctx.getExp()};
        std::unordered_map<z3::expr, std::vector<std::pair<GiNaC::numeric, z3::expr>>, HashExpr, ExprEqual> secant_points;
        z3::model model {z3Ctx};
        while (true) {
            switch (solver.check()) {
            case z3::unsat:
                if (log) std::cout << "unsat" << std::endl;
                return Unsat;
            case z3::unknown: return Unknown;
            case z3::sat: {
                model = solver.get_model();
                bool sat {true};
                // check if the model can be lifted, add refinement lemmas otherwise
                for (const auto &es: exps) {
                    for (const auto &e: es) {
                        const auto base {e.arg(0)};
                        const GiNaC::numeric ginac_base {base.to_string().c_str()};
                        const auto exp {e.arg(1)};
                        const auto exp_val {model.eval(exp, true)};
                        const GiNaC::numeric ginac_exp_val {exp_val.to_string().c_str()};
                        // if the exponent is negative, integer exponentiation is undefined
                        // in smtlib, this means that the result can be arbitrary
                        if (ginac_exp_val >= 0) {
                            const GiNaC::numeric ginac_actual {model.eval(e, true).to_string().c_str()};
                            const auto expected {z3::pw(base, exp_val)};
                            const GiNaC::numeric ginac_expected {GiNaC::pow(ginac_base, ginac_exp_val)};
                            if (ginac_actual < ginac_expected) {
                                if (log) std::cout << "tangent refinement" << std::endl;
                                // the actual value is too small --> add "tangent" refinement lemmas
                                const auto next {expected * base};
                                const auto diff {next - expected};
                                // a line through the current and its successor
                                const auto tangent {expected + diff * (exp - exp_val)};
                                if (log) std::cout << (e >= tangent).simplify() << std::endl;
                                solver.add(z3::implies(exp >= 0, e >= tangent));
                                if (ginac_actual > 1) {
                                    // as the actual result is greater than one, prev is an integer
                                    const auto prev {expected / base};
                                    auto diff {expected - prev};
                                    // a line through the current value and its predecessor
                                    auto tangent {prev + diff * (exp - exp_val - 1)};
                                    if (log) std::cout << (e >= tangent).simplify() << std::endl;
                                    solver.add(z3::implies(exp >= 0, e >= tangent));
                                }
                                sat = false;
                            } else if (ginac_actual > ginac_expected) {
                                if (log) std::cout << "secant refinement" << std::endl;
                                // the actual value is too large --> add secant refinement lemmas
                                GiNaC::numeric ginac_prev {-1};
                                GiNaC::numeric ginac_next {-1};
                                z3::expr prev {z3Ctx};
                                z3::expr next {z3Ctx};
                                // look for the closest existing secant points
                                auto it {secant_points.emplace(e, std::vector<std::pair<GiNaC::numeric, z3::expr>>()).first};
                                for (const auto &[ginac_other,other]: it->second) {
                                    if (ginac_other < ginac_exp_val) {
                                        if (ginac_other > ginac_prev) {
                                            prev = other;
                                        }
                                    } else if (ginac_next < 0 || ginac_other < ginac_next) {
                                        next = other;
                                    }
                                }
                                // if there are none, use the neighbours
                                if (prev < 0) {
                                    prev = exp_val - 1;
                                }
                                if (next < 0) {
                                    next = exp_val + 1;
                                }
                                // store the current secant point
                                it->second.emplace_back(ginac_exp_val, exp_val);
                                const auto prev_val {z3::pw(base, prev)};
                                const auto next_val {z3::pw(base, next)};
                                const auto prev_secant {((prev_val - expected) / (prev - exp_val)) * (exp - prev) + prev_val};
                                const auto next_secant {((next_val - expected) / (next - exp_val)) * (exp - next) + next_val};
                                if (log) std::cout << z3::implies(exp >= prev && exp <= exp_val, e <= prev_secant).simplify() << std::endl;
                                if (log) std::cout << z3::implies(exp >= exp_val && exp <= next, e <= next_secant).simplify() << std::endl;
                                solver.add(z3::implies(exp >= prev && exp <= exp_val, e <= prev_secant));
                                solver.add(z3::implies(exp >= exp_val && exp <= next, e <= next_secant));
                                sat = false;
                            }
                        }
                    }
                }
                if (sat) {
                    if (log) std::cout << "sat" << std::endl;
                    return Sat;
                } else {
                    // search for pairs exp(b,e1), exp(b,e2) whose models violate monotonicity of exp
                    auto outer_it1 {exps.begin()};
                    while (outer_it1 != exps.end()) {
                        auto inner_it1 {outer_it1->begin()};
                        while (inner_it1 != outer_it1->end()) {
                            const auto e1 {*inner_it1};
                            const auto base1 {e1.arg(0)};
                            const GiNaC::numeric ginac_base1 {base1.to_string().c_str()};
                            if (ginac_base1 > 1) {
                                const auto exp1 {e1.arg(1)};
                                auto outer_it2 = outer_it1;
                                while (outer_it2 != exps.end()) {
                                    auto inner_it2 {outer_it2->begin()};
                                    if (outer_it1 == outer_it2) {
                                        inner_it2 = inner_it1;
                                        ++inner_it2;
                                    }
                                    while (inner_it2 != outer_it2->end()) {
                                        const auto e2 {*inner_it2};
                                        const auto base2 {e2.arg(0)};
                                        const GiNaC::numeric ginac_base2 {base2.to_string().c_str()};
                                        if (ginac_base1 == ginac_base2) {
                                            const auto exp2 {e2.arg(1)};
                                            const GiNaC::numeric ginac_exp1 {model.eval(exp1, true).to_string().c_str()};
                                            const GiNaC::numeric ginac_exp2 {model.eval(exp2, true).to_string().c_str()};
                                            const GiNaC::numeric ginac_e1 {model.eval(e1, true).to_string().c_str()};
                                            const GiNaC::numeric ginac_e2 {model.eval(e2, true).to_string().c_str()};
                                            if (ginac_exp1 < ginac_exp2 && ginac_e1 >= ginac_e2) {
                                                if (log) std::cout << "extra refinement 1" << std::endl;
                                                solver.add(z3::implies(0 <= exp1 && exp1 < exp2, e1 < e2));
                                            } else if (ginac_exp2 < ginac_exp1 && ginac_e2 >= ginac_e1) {
                                                if (log) std::cout << "extra refinement 2" << std::endl;
                                                solver.add(z3::implies(0 <= exp2 && exp2 < exp1, e2 < e1));
                                            }
                                        }
                                        ++inner_it2;
                                    }
                                    ++outer_it2;
                                }
                            }
                            ++inner_it1;
                        }
                        ++outer_it1;
                    }
                }
            }
            }
        }
    }

    Model<Th...> model(const std::optional<const VarSet> &vars = {}) override {
        assert(models);
        const z3::model &m = solver.get_model();
        Model<Th...> res;
        const auto add = [&res, this, &m](const auto &p) {
            if constexpr ((std::is_same_v<IntTheory, Th> || ...)) {
                if (std::holds_alternative<NumVar>(p.first)) {
                    NumVar var = std::get<NumVar>(p.first);
                    Num val = getRealFromModel(m, p.second);
                    res.template put<IntTheory>(var, val);
                    return;
                }
            }
            if constexpr ((std::is_same_v<BoolTheory, Th> || ...)) {
                if (std::holds_alternative<BoolVar>(p.first)) {
                    BoolVar var = std::get<BoolVar>(p.first);
                    switch (m.eval(p.second).bool_value()) {
                    case Z3_L_FALSE:
                        res.template put<BoolTheory>(var, false);
                        break;
                    case Z3_L_TRUE:
                        res.template put<BoolTheory>(var, true);
                        break;
                    default: break;
                    }
                    return;
                }
            }
            throw std::logic_error("unknown variable type");
        };
        const auto map = ctx.getSymbolMap();
        if (vars) {
            for (const auto &x: *vars) {
                const auto it = map.find(x);
                if (it != map.end()) {
                    add(*it);
                }
            }
        } else {
            for (const auto &p: map) {
                add(p);
            }
        }
        return res;
    }

    void setTimeout(unsigned int timeout) override {
        this->timeout = timeout;
        updateParams();
    }

    void enableModels() override {
        this->models = true;
        updateParams();
    }

    void resetSolver() override {
        solver.reset();
        updateParams();
    }

    ~Z3() override {}

    std::ostream& print(std::ostream& os) const override {
        return os << solver;
    }

    void setSeed(unsigned seed) override {
        this->seed = seed;
        updateParams();
    }

private:
    bool models = false;
    unsigned int timeout;
    z3::context z3Ctx;
    Z3Context ctx;
    z3::solver solver;
    unsigned seed = 42u;
    std::vector<std::set<z3::expr>> exps;

    Num getRealFromModel(const z3::model &model, const z3::expr &symbol) {
        return Num(Z3_get_numeral_string(
                       model.ctx(),
                       Z3_get_numerator(
                           model.ctx(),
                           model.eval(symbol, true)))) /
                Num(Z3_get_numeral_string(
                        model.ctx(),
                        Z3_get_denominator(
                            model.ctx(),
                            model.eval(symbol, true))));
    }

    void updateParams() {
        z3::params params(z3Ctx);
        params.set(":model", models);
        if (timeout > 0) {
            params.set(":timeout", timeout);
        }
        params.set(":seed", seed);
        params.set(":random_seed", seed);
        solver.set(params);
    }

};
