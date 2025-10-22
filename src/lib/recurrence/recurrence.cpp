#include "recurrence.hpp"
#include "arith.hpp"
#include "dependencyorder.hpp"
#include "theory.hpp"
#include "config.hpp"

#include <map>
#include <utility>

Recurrence::Recurrence(Subs equations, ArithVarPtr n) : equations(std::move(equations)), n(std::move(n)) {}

std::optional<std::tuple<Int, Int, Arith::Expr>> Recurrence::handle_exp(const ArithExpPtr &pow) const {
    Int degree{0};
    Int base{1};
    Arith::Expr coeff{arith::one};
    const auto pbase{pow->getBase()};
    const auto pexp{pow->getExponent()};
    if (const auto d{pexp->isInt()}) {
        if (!pbase->isVar()) {
            throw std::logic_error("power with non-variable base");
        }
        degree = *d;
    } else if (const auto b{pbase->isInt()}) {
        if (pexp->isLinear({{n}})) {
            if (const auto ncoeff{*pexp->coeff(n)}; ncoeff->is(1)) {
                base = *b;
                coeff = arith::mkExp(pbase, pexp - n);
            } else {
                if (Config::Analysis::log) {
                    std::cout << "exponential where the exponent is not strongly linear in n" << std::endl;
                }
                return {};
            }
        } else {
            if (Config::Analysis::log) {
                std::cout << "exponential where the exponent is not linear in n" << std::endl;
            }
            return {};
        }
    } else {
        if (Config::Analysis::log) {
            std::cout << "exponential with n where neither the base nor the exponent is constant" << std::endl;
        }
        return {};
    }
    return std::tuple{degree, base, coeff};
}

// compute_r from [CAV19]
Arith::Expr Recurrence::compute_r(const Arith::Expr& q, const Rational &c) {
    assert(q->vars().size() <= 1);
    if (const auto c0 {q->isRational()}) {
        return c == 1 ? *c0 * n : arith::mkConst(***c0 / (1 - c));
    }
    assert(q->has(n));
    const auto d {*q->maxDegree()};
    const auto cd {*q->coeff(n, d)};
    const Arith::Expr s =
        c == 1
            ? (cd * arith::mkExp(n, arith::mkConst(d + 1)))->divide(d + 1)
            : (cd * arith::mkExp(n, arith::mkConst(d)))->divide(1 - c);
    const ArraySubs<Arith> subs {{n->var(), arrays::update(n, n-arith::one)}};
    return s + compute_r(q - s + arith::mkConst(c) * s->subs(subs), c);
}

// Compute closed form for x as described in [CAV19]:
// Termination of Triangular Integer Loops is Decidable
// F. Frohn and J. Giesl
// CAV 2019
// This implements Alg. 3 (closed_form) for one variable.
bool Recurrence::solve(const ArithVarPtr& x, const Arith::Expr& rhs) {
    if (!rhs->isLinear({{x}})) {
        return false;
    }
    auto m_x_plus_q{rhs->subs(closed_form_n_minus_one.get<Arrays<Arith>>())};
    const auto vars{m_x_plus_q->vars()};
    auto prefix{0u};
    auto closed_form{m_x_plus_q};
    for (const auto &x : vars) {
        if (const auto it{prefixes.find(x)}; it != prefixes.end()) {
            prefix = std::max(it->second, prefix);
        }
    }
    if (!vars.contains(x->var())) {
        ++prefix;
    } else {
        if (prefix > 0) {
            ++prefix;
        }
        const auto coeff_x {*m_x_plus_q->coeff(x)};
        if (!coeff_x->isInt()) {
            return false;
        }
        auto m{*coeff_x->isInt()};
        assert(m >= 1);
        const auto q {(m_x_plus_q - arith::mkConst(m) * x)};
        ArithExprSet q_addends;
        if (const auto add{q->isAdd()}) {
            q_addends = (*add)->getArgs();
        } else {
            q_addends.insert(q);
        }
        using Key = std::pair<Int, Int>;
        using Val = std::vector<Arith::Expr>;
        // compute triples correspodning to (a,b,alpha) in (10) of [CAV19]
        std::map<Key, Val> degree_and_base_to_coeff;
        for (const auto &a : q_addends) {
            if (a->has(n)) {
                const auto success{
                    a->apply<bool>(
                        [](const ArithConstPtr&) -> bool {
                            throw std::logic_error("an expression that contains n cannot be a constant");
                        },
                        [&](const ArithVarPtr&) {
                            degree_and_base_to_coeff.emplace(Key{1, 1}, Val{}).first->second.push_back(arith::one);
                            return true;
                        },
                        [](const ArithAddPtr&) -> bool {
                            throw std::logic_error("nested addition in arithmetic expresssion");
                        },
                        [&](const ArithMultPtr& mul) {
                            Int degree{0};
                            Int base{1};
                            std::vector<Arith::Expr> coeff;
                            for (const auto &arg : mul->getArgs()) {
                                if (!arg->has(n)) {
                                    coeff.push_back(arg);
                                } else if (arg->isAdd()) {
                                    throw std::logic_error("addition below multiplication in arithmetic expresssion");
                                } else if (arg->isMult()) {
                                    throw std::logic_error("nested multiplication in arithmetic expresssion");
                                } else if (const auto pow{arg->isPow()}) {
                                    if (const auto t{handle_exp(*pow)}) {
                                        const auto &[d, b, c]{*t};
                                        degree += d;
                                        base *= b;
                                        coeff.push_back(c);
                                    } else {
                                        return false;
                                    }
                                } else if (arg->isVar()) {
                                    if (arg == n) {
                                        degree += 1;
                                    } else {
                                        coeff.push_back(arg);
                                    }
                                } else {
                                    if (Config::Analysis::log) {
                                        std::cout << "subterm with n which is neither a polynomial nor an exponential: " << arg << std::endl;
                                    }
                                    return false;
                                }
                            }
                            degree_and_base_to_coeff.emplace(Key{degree, base}, Val{}).first->second.push_back(arith::mkTimes(std::move(coeff)));
                            return true;
                        },
                        [](const ArithModPtr&) {
                            if (Config::Analysis::log) {
                                std::cout << "mod-subterm with n" << std::endl;
                            }
                            return false;
                        },
                        [&](const ArithExpPtr& pow) {
                            if (const auto t{handle_exp(pow)}) {
                                const auto &[degree, base, coeff]{*t};
                                degree_and_base_to_coeff.emplace(Key{degree, base}, Val{}).first->second.push_back(coeff);
                                return true;
                            }
                            return false;
                        })};
                if (!success) {
                    return false;
                }
            } else {
                degree_and_base_to_coeff.emplace(Key{0, 1}, Val{}).first->second.push_back(a);
            }
        }
        std::vector<Arith::Expr> res;
        // compute (10) of [CAV19]
        // as we disregard characteristic functions and compute a "prefix" instead, i.e.,
        // a minimum value such that the result of the recurrence is valid, c from (10) is always -1
        for (auto [db, coeff]: degree_and_base_to_coeff) {
            const auto &[a, b] {db};
            const auto r {compute_r(arith::mkExp(n, arith::mkConst(a)), Rational(m, b))};
            const auto alpha {arith::mkPlus(std::move(coeff))};
            const auto alpha_divided {alpha->divide(b)};
            // first addend of the last line from (10)
            const auto fst {alpha_divided * r * arith::mkExp(arith::mkConst(b), n)};
            const ArraySubs<Arith> subs {{n->var(), arrays::update(n, arith::zero)}};
            // negated second addend of the last line from (10), which is simples, as c=-1
            const auto snd {r->subs(subs) * alpha_divided * arith::mkExp(arith::mkConst(m), n)};
            res.push_back(fst);
            res.push_back(-snd);
        }
        res.push_back(arith::mkExp(arith::mkConst(m), n) * x);
        closed_form = arith::mkPlus(std::move(res));
    }
    prefixes.emplace(x->var(), prefix);
    result.prefix = std::max(result.prefix, prefix);
    const ArraySubs<Arith> subs {{n->var(), arrays::update(n, n - arith::one)}};
    closed_form_n_minus_one.put(x->var(), arrays::update(x, closed_form->subs(subs)));
    result.closed_form.put(x->var(), arrays::update(x, closed_form));
    return true;
}

bool Recurrence::solve(const Bools::Var &lhs, const Bools::Expr& rhs) {
    const auto updated{rhs->subs(closed_form_n_minus_one)};
    if (updated->lits().contains(bools::mk(lhs, true))) {
        return false;
    }
    const auto &vars{updated->vars()};
    if (vars.contains(lhs) && vars.size() != vars.get<Bools::Var>().size()) {
        return false;
    }
    unsigned prefix{1};
    for (const auto &x : vars) {
        if (const auto it{prefixes.find(x)}; it != prefixes.end() && it->second >= prefix) {
            prefix = it->second + 1;
        }
    }
    prefixes.emplace(lhs, prefix);
    result.prefix = std::max(result.prefix, prefix);
    closed_form_n_minus_one.put(lhs, updated);
    result.closed_form.put(lhs, updated);
    return true;
}

bool Recurrence::solve(const Arrays<Arith>::Var& lhs, const Arrays<Arith>::Expr& rhs) {
    // TODO
    throw std::logic_error("not implemented");
}

bool Recurrence::solve() {
    const auto order{DependencyOrder::findOrder(equations)};
    if (!order) {
        return false;
    }
    for (const auto &lhs : *order) {
        const auto success{
            theory::apply(
                lhs,
                [&](const auto& lhs) {
                    const auto rhs{equations.get(lhs)};
                    if (Config::Analysis::log) {
                        std::cout << "solving recurrence " << lhs << " = " << rhs << std::endl;
                    }
                    if (solve(lhs, rhs)) {
                        if (Config::Analysis::log) {
                            std::cout << "got " << lhs << "(" << n << ") = " << result.closed_form.get(lhs) <<
                                std::endl;
                        }
                    } else {
                        if (Config::Analysis::log) {
                            std::cout << "solving recurrence failed" << std::endl;
                        }
                        return false;
                    }
                    return true;
                })
        };
        if (!success) {
            return false;
        }
    }
    return true;
}

std::optional<Recurrence::Result> Recurrence::solve(const Subs &equations, const ArithVarPtr& n) {
    if (Recurrence rec{equations, n}; rec.solve()) {
        return rec.result;
    }
    return {};
}
