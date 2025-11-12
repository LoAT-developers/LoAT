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
    Arith::Expr coeff{arith::one()};
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
    const ArraySubs<Arith> subs {{n->var(), arrays::update(n, n-arith::one())}};
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
    auto m_x_plus_q{rhs->subs(closed_form_n_minus_one.get<ArithVarPtr, Arith::Expr>())};
    const auto vars{m_x_plus_q->cells()};
    auto prefix{0u};
    auto closed_form{m_x_plus_q};
    for (const auto &x : vars) {
        if (const auto it{prefixes.find(x)}; it != prefixes.end()) {
            prefix = std::max(it->second, prefix);
        }
    }
    if (!vars.contains(x)) {
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
                            degree_and_base_to_coeff.emplace(Key{1, 1}, Val{}).first->second.push_back(arith::one());
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
            const ArraySubs<Arith> subs {{n->var(), arrays::update(n, arith::zero())}};
            // negated second addend of the last line from (10), which is simples, as c=-1
            const auto snd {r->subs(subs) * alpha_divided * arith::mkExp(arith::mkConst(m), n)};
            res.push_back(fst);
            res.push_back(-snd);
        }
        res.push_back(arith::mkExp(arith::mkConst(m), n) * x);
        closed_form = arith::mkPlus(std::move(res));
    }
    prefixes.emplace(x, prefix);
    result.prefix = std::max(result.prefix, prefix);
    const ArraySubs<Arith> subs {{n->var(), arrays::update(n, n - arith::one())}};
    closed_form_n_minus_one.put(std::pair{x, closed_form->subs(subs)});
    result.closed_form.put(std::pair{x, closed_form});
    if (x->dim() == 0) {
        result.closed_form_subs.put(x->var(), arrays::writeConst(closed_form));
    }
    return true;
}

bool Recurrence::solve(const Bools::Var &lhs, const Bools::Expr& rhs) {
    const auto updated{rhs->subs(closed_form_n_minus_one)};
    if (updated->lits().contains(bools::mk(lhs, true))) {
        return false;
    }
    const auto &vars{updated->cells()};
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
    closed_form_n_minus_one.put(std::pair{lhs, updated});
    result.closed_form.put(std::pair{lhs, updated});
    result.closed_form_subs.put(lhs, updated);
    return true;
}

signed char compare_lexicographically(const Recurrence::Idx& a_idx, const Recurrence::Idx& b_idx) {
    for (size_t i = 0; i < a_idx.size(); ++i) {
        const auto diff{a_idx.at(i) - b_idx.at(i)};
        if (const auto d{diff->isRational()}) {
            const auto d_val{***d};
            if (d_val > 0) {
                return 1;
            }
            if (d_val < 0) {
                return -1;
            }
        } else {
            // difference is not a rational -- incomparable
            return 0;
        }
    }
    // difference is 0 for all components -- equal
    return 0;
}

bool Recurrence::solve() {
    // add solutions for cells where the solution is trivial as nothing changes
    for (const auto& c : equations.coDomainCells()) {
        theory::apply(
            c,
            [&](const ArithVarPtr& c) {
                if (!equations.contains(c->var()) &&
                    std::ranges::all_of(c->indices(), [&](const auto& i) {
                        return std::ranges::all_of(i->vars(), [&](const auto& x) {
                            return !equations.contains(x);
                        });
                })) {
                    result.closed_form.put(std::pair(c, c));
                }
            },
            [&](const Bools::Var& c) {
                if (!equations.contains(c)) {
                    result.closed_form.put(std::pair(c, bools::mkLit(bools::mk(c))));
                }
            });
    }
    // applies the update to the given indices
    const auto update_idx = [&](const Idx& idx) {
        Idx res;
        for (const auto& i : idx) {
            res.emplace_back(i->subs(equations));
        }
        return res;
    };
    // collect lvalues that are written by the loop and initialize worklist
    std::vector<ArithVarPtr> a_work_list;
    linked_hash_map<ArithVarPtr, Arith::Expr> written;
    for (auto [x,t] : equations.get<Arrays<Arith>>()) {
        // we do not support a := b yet
        if (t->isVar()) {
            if (t->dim() == 0) {
                // workaround to handle a := b in the case that of scalars
                t = arrays::writeConst(arrays::readConst(t->var()));
            } else {
                return false;
            }
        }
        auto write{t};
        // collect all index / value pairs that are written to a
        const auto var = t->dim() == 0 ? x : t->var();
        while (const auto w{write->isArrayWrite()}) {
            // we do not support array writes on right-hand sides yet
            if (std::ranges::any_of((*w)->val()->cells(), [](const auto& c) {
                return c->arr()->isArrayWrite().has_value();
            })) {
                return false;
            }
            if (const auto idx = (*w)->indices()) {
                const auto key {arrays::mkArrayRead(var, *idx)};
                a_work_list.emplace_back(key);
                written.emplace(key, (*w)->val());
                write = (*w)->arr();
            } else {
                return false;
            }
        }
    }
    // group written lvalues into inducive, increasing, and decreasing ones
    linked_hash_set<ArithVarPtr> inductive;
    linked_hash_set<ArithVarPtr> increasing;
    linked_hash_set<ArithVarPtr> decreasing;
    const auto is_inductive = [&](const ArithVarPtr& lval, const Arith::Expr& val) {
        return std::ranges::all_of(val->cells(), [&](const ArithVarPtr& c) {
            return lval->var() != c->var() || written.contains(arrays::mkArrayRead(c->var(), update_idx(c->indices())));
        });
    };
    const auto is_increasing = [&](const ArithVarPtr& lval, const Arith::Expr& val) {
        return std::ranges::all_of(val->cells(), [&](const auto& c) {
            return lval->var() != c->var() || compare_lexicographically(update_idx(c->indices()), lval->indices()) > 0;
        });
    };
    const auto is_decreasing = [&](const ArithVarPtr& lval, const Arith::Expr& val) {
        return std::ranges::all_of(val->cells(), [&](const auto& c) {
            return lval->var() != c->var() || compare_lexicographically(update_idx(c->indices()), lval->indices()) < 0;
        });
    };
    for (auto t : equations.get<Arrays<Arith>>() | std::views::values) {
        // collect inductive writes
        for (const auto& [lval, val] : written) {
            if (is_inductive(lval, val)) {
                inductive.emplace(lval);
            } else if (is_increasing(lval, val)) {
                increasing.emplace(lval);
            } else if (is_decreasing(lval, val)) {
                decreasing.emplace(lval);
            } else {
                return false;
            }
        }
    }
    // checks if an arithmetic recurrence is ready for solving
    const auto a_is_ready = [&](const ArithVarPtr& lval, const Arith::Expr& val) {
        return std::ranges::all_of(val->cells(), [&](const auto& c) {
            const auto lval = arrays::mkArrayRead(c->var(), c->indices());
            const auto updated = arrays::mkArrayRead(c->var(), update_idx(c->indices()));
            return lval == updated || result.closed_form.contains(lval);
        });
    };
    bool changed {true};
    while (changed) {
        changed = false;
        for (auto it = a_work_list.begin(); it != a_work_list.end();) {
            const auto lval {*it};
            if (const auto& val {written.at(lval)}; a_is_ready(lval, val)) {
                if (solve(lval, val)) {
                    changed = true;
                    it = a_work_list.erase(it);
                } else {
                    // failed to compute closed form for this lval
                    return false;
                }
            } else {
                // this lval is not yet ready
                ++it;
            }
        }
    }
    if (!a_work_list.empty()) {
        return false;
    }
    std::vector<Bools::Var> b_work_list;
    for (const auto& x : equations.get<Bools>() | std::views::keys) {
        b_work_list.emplace_back(x);
    }
    // checks if a boolean recurrence is ready for solving
    const auto b_is_ready = [&](const Bools::Var& lval, const Bools::Expr& val) {
        return std::ranges::all_of(val->cells(), [&](const auto& c) {
            return theory::apply(
                c,
                [&](const Bools::Var& c) {
                    return c == lval || result.closed_form.contains(c);
                },
                [&](const ArithVarPtr& c) {
                    return result.closed_form.contains(arrays::mkArrayRead(c->var(), c->indices()));
                });
        });
    };
    changed = true;
    while (changed) {
        changed = false;
        for (auto it = b_work_list.begin(); it != b_work_list.end();) {
            const auto lval {*it};
            if (const auto val {equations.get(lval)}; b_is_ready(lval, val)) {
                if (solve(lval, val)) {
                    changed = true;
                    it = b_work_list.erase(it);
                } else {
                    return false;
                }
            } else {
                ++it;
            }
        }
    }
    return b_work_list.empty();
}

std::optional<Recurrence::Result> Recurrence::solve(const Subs &equations, const ArithVarPtr& n) {
    if (Recurrence rec{equations, n}; rec.solve()) {
        return rec.result;
    }
    return {};
}
