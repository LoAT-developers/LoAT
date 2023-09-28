#pragma once

#include "z3.hpp"
#include "z3inclincontext.hpp"

template <ITheory... Th>
class Z3IncLin: public Z3Base<Z3IncLinContext, Th...> {

    std::unordered_map<unsigned, std::vector<z3::expr>> exps;
    static const bool log {false};
    unsigned level;

public:

    Z3IncLin(): Z3Base<Z3IncLinContext, Th...>(smt::default_timeout) {}

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
        const auto to_add {ExprToSmt<z3::expr, Th...>::convert(flat, this->ctx)};
        if (log) std::cout << "add - to_add: " << to_add.simplify() << std::endl;
        this->solver.add(to_add);
        const auto exps {this->ctx.clearExps()};
        if (!exps.empty()) {
            auto &vec {this->exps.emplace(level, std::vector<z3::expr>()).first->second};
            vec.insert(vec.end(), exps.begin(), exps.end());
            for (const auto &e: exps) {
                const GiNaC::numeric base {e.arg(0).to_string().c_str()};
                const auto exp {e.arg(1)};
                if (base == 0) {
                    this->solver.add(z3::implies(exp >= 0, e == 0));
                } else if (base == 1) {
                    this->solver.add(z3::implies(exp >= 0, e == 1));
                } else {
                    this->solver.add(z3::implies(exp >= 0, e > 0));
                    this->solver.add(z3::implies(exp == 0, e == 1));
                    this->solver.add(z3::implies(exp > 0, e > exp));
                }
            }
        }
    }

    void push() override {
        if (log) std::cout << "push" << std::endl;
        this->solver.push();
        ++level;
    }

    void pop() override {
        if (log) std::cout << "pop" << std::endl;
        this->solver.pop();
        exps.erase(level);
        --level;
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
        const auto exp {this->ctx.getExp()};
        std::unordered_map<z3::expr, std::vector<std::pair<GiNaC::numeric, z3::expr>>, HashExpr, ExprEqual> secant_points;
        z3::model model {this->z3Ctx};
        while (true) {
            switch (this->solver.check()) {
            case z3::unsat:
                if (log) std::cout << "unsat" << std::endl;
                return Unsat;
            case z3::unknown: return Unknown;
            case z3::sat: {
                model = this->solver.get_model();
                bool sat {true};
                // check if the model can be lifted, add refinement lemmas otherwise
                for (const auto &[_,es]: exps) {
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
                                this->solver.add(z3::implies(exp >= 0, e >= tangent));
                                if (ginac_actual > 1) {
                                    // as the actual result is greater than one, prev is an integer
                                    const auto prev {expected / base};
                                    auto diff {expected - prev};
                                    // a line through the current value and its predecessor
                                    auto tangent {prev + diff * (exp - exp_val - 1)};
                                    if (log) std::cout << (e >= tangent).simplify() << std::endl;
                                    this->solver.add(z3::implies(exp >= 0, e >= tangent));
                                }
                                sat = false;
                            } else if (ginac_actual > ginac_expected) {
                                if (log) std::cout << "secant refinement" << std::endl;
                                // the actual value is too large --> add secant refinement lemmas
                                GiNaC::numeric ginac_prev {-1};
                                GiNaC::numeric ginac_next {-1};
                                z3::expr prev {this->z3Ctx};
                                z3::expr next {this->z3Ctx};
                                // look for the closest existing secant points
                                auto it {secant_points.emplace(e, std::vector<std::pair<GiNaC::numeric, z3::expr>>()).first};
                                for (const auto &[ginac_other,other]: it->second) {
                                    if (ginac_other < ginac_exp_val) {
                                        if (ginac_other > ginac_prev) {
                                            ginac_prev = ginac_other;
                                            prev = other;
                                        }
                                    } else if (ginac_next < 0 || ginac_other < ginac_next) {
                                        ginac_next = ginac_other;
                                        next = other;
                                    }
                                }
                                // if there are none, use the neighbours
                                if (ginac_prev < 0) {
                                    prev = exp_val - 1;
                                }
                                if (ginac_next < 0) {
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
                                this->solver.add(z3::implies(exp >= prev && exp <= exp_val, e <= prev_secant));
                                this->solver.add(z3::implies(exp >= exp_val && exp <= next, e <= next_secant));
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
                        auto inner_it1 {outer_it1->second.begin()};
                        while (inner_it1 != outer_it1->second.end()) {
                            const auto e1 {*inner_it1};
                            const auto base1 {e1.arg(0)};
                            const GiNaC::numeric ginac_base1 {base1.to_string().c_str()};
                            if (ginac_base1 > 1) {
                                const auto exp1 {e1.arg(1)};
                                auto outer_it2 = outer_it1;
                                while (outer_it2 != exps.end()) {
                                    auto inner_it2 {outer_it2->second.begin()};
                                    if (outer_it1 == outer_it2) {
                                        inner_it2 = inner_it1;
                                        ++inner_it2;
                                    }
                                    while (inner_it2 != outer_it2->second.end()) {
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
                                                this->solver.add(z3::implies(0 <= exp1 && exp1 < exp2, e1 < e2));
                                            } else if (ginac_exp2 < ginac_exp1 && ginac_e2 >= ginac_e1) {
                                                if (log) std::cout << "extra refinement 2" << std::endl;
                                                this->solver.add(z3::implies(0 <= exp2 && exp2 < exp1, e2 < e1));
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

};
