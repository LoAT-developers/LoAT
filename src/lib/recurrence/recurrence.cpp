#include "recurrence.hpp"
#include "arith.hpp"
#include "dependencyorder.hpp"
#include "theory.hpp"
#include "config.hpp"

#include <map>
#include <utility>

Recurrence::Recurrence(Subs equations, ArithVarPtr n) :
    equations(std::move(equations)),
    n(std::move(n)),
    n_to_n_minus_one(Subs::build(this->n->var(), arrays::writeConst(this->n - arith::one()))) {}

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
    const Subs subs = Subs::build(n->var(), arrays::update(n, n-arith::one()));
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
    auto cf{m_x_plus_q};
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
            const auto subs = Subs::build(n->var(), arrays::update(n, arith::zero()));
            // negated second addend of the last line from (10), which is simples, as c=-1
            const auto snd {r->subs(subs) * alpha_divided * arith::mkExp(arith::mkConst(m), n)};
            res.push_back(fst);
            res.push_back(-snd);
        }
        res.push_back(arith::mkExp(arith::mkConst(m), n) * x);
        cf = arith::mkPlus(std::move(res));
    }
    prefixes.emplace(x, prefix);
    result.prefix = std::max(result.prefix, prefix);
    closed_form_n_minus_one.put(std::pair{x, cf->subs(n_to_n_minus_one)});
    closed_form.put(x, cf);
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

std::optional<std::vector<ArithConstPtr>> Recurrence::compute_shift(const Idx& idx) const {
    std::vector<ArithConstPtr> shift;
    for (const auto & i : idx) {
        const auto diff{i->subs(equations) - i};
        if (const auto d{diff->isRational()}) {
            shift.emplace_back(*d);
        } else {
            // difference is not a rational -- give up
            return std::nullopt;
        }
    }
    return shift;
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
                    closed_form.put(c, c);
                }
            },
            [&](const Bools::Var& c) {
                if (!equations.contains(c)) {
                    result.closed_form.put(c, bools::mkLit(bools::mk(c)));
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
    linked_hash_map<ArithVarPtr, std::vector<ArithConstPtr>> shift;
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
                const auto s = compute_shift(*idx);
                if (!s || std::ranges::any_of(*s, [](const auto& i) {return i->getValue() < 0;})) {
                    return false;
                }
                const auto key {arrays::mkArrayRead(var, *idx)};
                shift.emplace(key, *s);
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
    linked_hash_set<ArithVarPtr> displacing;
    const auto is_inductive = [&](const ArithVarPtr& lval, const Arith::Expr& val) {
        return std::ranges::all_of(val->cells(), [&](const ArithVarPtr& c) {
            return lval->var() != c->var() || written.contains(arrays::mkArrayRead(c->var(), update_idx(c->indices())));
        });
    };
    const auto is_displacing = [&](const ArithVarPtr& lval, const Arith::Expr& val) {
        return std::ranges::all_of(val->cells(), [&](const auto& c) {
            return lval->var() != c->var() || compare_lexicographically(update_idx(c->indices()), lval->indices()) > 0;
        });
    };
    for (const auto& [lval, val] : written) {
        if (is_displacing(lval, val)) {
            displacing.emplace(lval);
        } else if (is_inductive(lval, val)) {
            inductive.emplace(lval);
        } else {
            return false;
        }
    }
    // checks if an arithmetic recurrence is ready for solving
    const auto a_is_ready = [&](const ArithVarPtr& lval, const Arith::Expr& val) {
        return std::ranges::all_of(val->cells(), [&](const auto& c) {
            const auto other_lval = arrays::mkArrayRead(c->var(), c->indices());
            const auto updated = arrays::mkArrayRead(c->var(), update_idx(c->indices()));
            return lval == updated || closed_form.contains(other_lval);
        });
    };
    bool changed {true};
    while (changed) {
        changed = false;
        for (auto it = a_work_list.begin(); it != a_work_list.end();) {
            const auto lval {*it};
            if (const auto& val {written.at(lval)}; a_is_ready(lval, val)) {
                if (inductive.contains(lval)) {
                    if (solve(lval, val)) {
                        changed = true;
                    } else {
                        // failed to compute closed form for this lval
                        return false;
                    }
                } else {
                    std::vector<Arith::Expr> indices;
                    for (const auto& i: lval->indices()) {
                        indices.emplace_back(i->subs(closed_form));
                    }
                    const auto updated {arrays::mkArrayRead(lval->var(), indices)};
                    closed_form.put(lval, updated);
                    closed_form_n_minus_one.put(std::pair(lval, updated->subs(n_to_n_minus_one)));
                }
                it = a_work_list.erase(it);
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
                    return closed_form.contains(arrays::mkArrayRead(c->var(), c->indices()));
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
    if (!b_work_list.empty()) {
        return false;
    }
    const auto mk_cell_not_written = [&](const ArithVarPtr& lval, const Arith::Expr& m) {
        size_t i = 0;
        const auto& s = shift.at(lval);
        LitSet lits;
        for (const auto& e: lval->indices()) {
            if (const auto& d = s.at(i); d->getValue() != 0) {
                const auto c = arrays::array_idx(i);
                lits.insert(arith::mkLt(c, e + d * m));
                lits.insert(arith::mkLeq(e + d * n, c));
                if (d->getValue() != 1) {
                    lits.insert(arith::mkNeq(arith::mkMod(c - e, d), arith::zero()));
                }
            }
            ++i;
        }
        return bools::mkOr(lits);
    };
    const auto mk_arr_not_written = [&](const Arrays<Arith>::Var& var, const Arith::Expr& m) {
        BoolExprSet conjuncts;
        for (const auto& lval: written | std::views::keys) {
            if (lval->var() == var) {
                conjuncts.emplace(mk_cell_not_written(lval, m));
            }
        }
        return bools::mkAnd(conjuncts);
    };
    const auto mk_last_write = [&](const ArithVarPtr& lval) {
        if (lval->dim() == 0) {
            return top();
        }
        size_t i = 0;
        const auto& s = shift.at(lval);
        LitSet lits;
        std::optional<Arith::Expr> m;
        for (const auto& e: lval->indices()) {
            if (const auto& d = s.at(i); d->getValue() != 0) {
                const auto c = arrays::array_idx(i);
                lits.insert(arith::mkLeq(arith::zero(), c - e));
                lits.insert(arith::mkLt(c - e, n * d));
                if (d->getValue() != 1) {
                    lits.insert(arith::mkEq(arith::mkMod(c - e, d), arith::zero()));
                }
                if (m) {
                    lits.insert(arith::mkEq(*m, (c - e)->divide(d->getValue())));
                } else {
                    m = (c - e)->divide(d->getValue());
                }
            }
            ++i;
        }
        return bools::mkAnd(lits) && mk_arr_not_written(lval->var(), *m + arith::one());
    };
    for (const auto& [lval,r]: written) {
        if (lval->dim() == 0) {
            result.closed_form.update(lval, closed_form.at(lval));
        } else {
            const auto var = lval->var();
            const auto old_val = result.closed_form.get(var);
            const auto cond = mk_last_write(lval);
            if (inductive.contains(lval)) {
                const auto new_val = closed_form.at(lval);
                result.closed_form.put(var, arrays::mkArrayWrite(old_val, cond, new_val));
            } else {
                const auto new_val = r->subs(closed_form_n_minus_one.get<ArithVarPtr, Arith::Expr>());
                result.closed_form.put(var, arrays::mkArrayWrite(old_val, cond, new_val));
            }
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
