#include "swine.hpp"
#include "exprconverter.hpp"
#include "swinemodel.hpp"

Swine::Swine(const swine::Config& config): solver(config, z3ctx), ctx(solver) {
    auto &s {solver.get_solver()};
    s.set("random_seed", 42u);
    // s.set("rlimit", 10000000u);
    // config.set_rlimit(1000);
}

using Converter = ExprConverter<z3::expr, z3::expr, z3::expr_vector, z3::expr_vector>;

void Swine::add(const Bools::Expr e) {
    const auto cells = e->cells().get<ArithVarPtr>();
    for (const auto& c: cells) {
        frames.back().indices.emplace(c->indices());
    }
    const auto abstraction = std::get<Bools::Expr>(abstract(e));
    frames.back().assertions.emplace(abstraction);
    solver.add(Converter::convert(abstraction, ctx));
}

void Swine::push() {
    frames.emplace_back();
    frames.back().concretization = frames.at(frames.size() - 2).concretization;
    solver.push();
}

void Swine::pop() {
    frames.pop_back();
    solver.pop();
}

SmtResult Swine::check() {
    do {
        switch (solver.check()) {
        case z3::unsat:
            return SmtResult::Unsat;
        case z3::unknown:
            return SmtResult::Unknown;
        case z3::sat:
            m = cpp::assume_not_null(std::make_shared<SwineModel>(ctx, solver.get_model(), Subs()));
            BoolExprSet concrete_conjuncts;
            BoolExprSet abstract_disjuncts;
            for (const auto& f : frames) {
                for (const auto& abstraction : f.assertions) {
                    const auto a = (*m)->syntacticImplicant(abstraction);
                    abstract_disjuncts.insert(std::get<Bools::Expr>(abstract(!a)));
                    concrete_conjuncts.insert(a->subs(frames.back().concretization));
                }
            }
            auto formula = bools::mkAnd(concrete_conjuncts);
            Subs subs;
            do {
                subs = formula->propagateEqualities([](const auto&) {
                    return true;
                });
                if (subs.empty()) break;
                formula = formula->subs(subs);
                m = (*m)->composeBackwards(subs);
            } while (true);
            if (formula == bot()) {
                solver.add(Converter::convert(bools::mkOr(abstract_disjuncts), ctx));
                continue;
            }
            auto sat = true;
            const auto lits = formula->lits();
            for (const auto& c : lits) {
                if (!(*m)->eval(c)) {
                    sat = false;
                    const auto refined = theory::apply(
                        c,
                        [&](const Arrays<Arith>::Lit& c) {
                            if (const auto eq = c->isArrayEq()) {
                                const auto dim = (*eq)->lhs()->dim();
                                auto refined = false;
                                for (const auto& f : frames) {
                                    for (const auto& i : f.indices) {
                                        if (i.size() == dim) {
                                            const auto lhs = arrays::mkArrayRead((*eq)->lhs(), i);
                                            const auto rhs = arrays::mkArrayRead((*eq)->rhs(), i);
                                            if (const auto eq = arith::mkEq(lhs, rhs); !(*m)->eval(eq)) {
                                                solver.add(Converter::convert(
                                                        bools::mkOr(abstract_disjuncts) || bools::mkLit(eq), ctx)
                                                );
                                                refined = true;
                                            }
                                        }
                                    }
                                }
                                return refined;
                            }
                            solver.add(Converter::convert(
                                    bools::mkOr(abstract_disjuncts) || bools::mkLit(abstract(c)), ctx)
                            );
                            return true;
                        },
                        [&](const auto&) {
                            solver.add(Converter::convert(bools::mkOr(abstract_disjuncts) || bools::mkLit(c), ctx));
                            return true;
                        });
                    if (!refined) {
                        return SmtResult::Unknown;
                    }
                }
            }
            if (sat) {
                return SmtResult::Sat;
            }
        }
    }
    while (true);
}

ModelPtr Swine::model() {
    return *m;
}

void Swine::enableModels() {}

void Swine::resetSolver() {
    solver.reset();
}

std::ostream& Swine::print(std::ostream& os) const {
    return os << solver;
}

void Swine::randomize(const unsigned seed) {
    auto &s {solver.get_solver()};
    s.set("random_seed", seed);
}

Lit Swine::abstract(const Lit& lit) {
    return theory::apply(
        lit,
        [&](const Arith::Lit& e) -> Lit {
            return e;
        },
        [&](const Arrays<Arith>::Lit& lit) -> Lit {
            if (const auto eq = lit->isArrayEq()) {
                const auto lhs = std::get<Arrays<Arith>::Expr>(abstract((*eq)->lhs()));
                const auto rhs = std::get<Arrays<Arith>::Expr>(abstract((*eq)->rhs()));
                return arrays::mkEq(lhs, rhs);
            }
            if (const auto neq = lit->isArrayNeq()) {
                std::vector<Arith::Expr> args;
                for (size_t i = 0; i < (*neq)->lhs()->dim(); ++i) {
                    args.emplace_back(arrays::nextConst<Arith>());
                }
                const auto lhs = arrays::mkArrayRead((*neq)->lhs(), args);
                const auto rhs = arrays::mkArrayRead((*neq)->rhs(), args);
                return arith::mkNeq(lhs, rhs);
            }
            throw std::invalid_argument("Swine::abstract");
        },
        [&](const Bools::Lit& lit) -> Lit {
            return lit;
        });
}

Expr Swine::abstract(const Expr& e) {
    return theory::apply(
        e,
        [&](const Bools::Expr& e) -> Expr {
            return e->map([&](const auto& lit) {
                return bools::mkLit(abstract(lit));
            });
        },
        [&](const Arith::Expr& e) -> Expr {
            return e;
        },
        [&](const Arrays<Arith>::Expr& e) -> Expr {
            if (const auto write = e->isArrayWrite()) {
                if (!(*write)->indices()) {
                    for (const auto& f : frames) {
                        if (const auto it = f.abstractions.find(*write); it != f.abstractions.end()) {
                            return it->second;
                        }
                    }
                    auto res = ArrayVar<Arith>::next(e->dim());
                    frames.back().abstractions.emplace(*write, res);
                    frames.back().concretization.put(res, *write);
                    return res;
                }
                const auto arr = std::get<Arrays<Arith>::Expr>(abstract((*write)->arr()));
                const auto cond = std::get<Bools::Expr>(abstract((*write)->cond()));
                const auto val = std::get<Arith::Expr>(abstract((*write)->val()));
                return arrays::mkArrayWrite(arr, cond, val);
            }
            return e;
        });
}

Rational Swine::getRealFromModel(const z3::model &model, const z3::expr &symbol) {
    const Rational numerator {Z3_get_numeral_string(
        model.ctx(),
        Z3_get_numerator(
            model.ctx(),
            model.eval(symbol, true)))};
    const Rational denominator {Z3_get_numeral_string(
        model.ctx(),
        Z3_get_denominator(
            model.ctx(),
            model.eval(symbol, true)))};
    return numerator / denominator;
}
