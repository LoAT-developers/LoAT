#include "recurrence.hpp"
#include "arith.hpp"
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
                if (Config::Analysis::logAccel) {
                    std::cout << "exponential where the exponent is not strongly linear in n" << std::endl;
                }
                return {};
            }
        } else {
            if (Config::Analysis::logAccel) {
                std::cout << "exponential where the exponent is not linear in n" << std::endl;
            }
            return {};
        }
    } else {
        if (Config::Analysis::logAccel) {
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
                                    if (Config::Analysis::logAccel) {
                                        std::cout << "subterm with n which is neither a polynomial nor an exponential: " << arg << std::endl;
                                    }
                                    return false;
                                }
                            }
                            degree_and_base_to_coeff.emplace(Key{degree, base}, Val{}).first->second.push_back(arith::mkTimes(std::move(coeff)));
                            return true;
                        },
                        [](const ArithModPtr&) {
                            if (Config::Analysis::logAccel) {
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
    // add solutions for cells where it is trivial as nothing changes
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
    // lvalues that are written by the loop
    linked_hash_map<ArithVarPtr, Arith::Expr> written;
    // vectors describing how the indices change
    linked_hash_map<ArithVarPtr, std::vector<ArithConstPtr>> shift;
    // constraints that enforce that the written indices are disjoint
    std::vector<Bools::Expr> different_indices;
    // populate data structures and check for cases that cannot be handled
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
        // for scalars, x[] := store(y, [], t) and x[] := store(x, [], t) are equivalent, but we can only handle the latter
        const auto var = t->dim() == 0 ? x : t->var();
        // needed to populate disjoint_indices
        std::vector<ArithVarPtr> lvalues;
        const auto store_shift = [&](const auto& c) {
            const auto s = compute_shift(c->indices());
            // TODO just increasing loops for now
            if (!s || std::ranges::any_of(*s, [](const auto& i) {return i->getValue() < 0;})) {
                return false;
            }
            shift.emplace(c, *s);
            return true;
        };
        // collect all index / value pairs that are written to a
        while (const auto w{write->isArrayWrite()}) {
            if (const auto idx = (*w)->indices()) {
                const auto lval = arrays::mkArrayRead(var, *idx);
                written.emplace(lval, (*w)->val());
                if (!store_shift(lval)) {
                    return false;
                }
                // for each previously written lval, at least one index must be different
                for (const auto& other_lval: lvalues) {
                    LitSet disjuncts;
                    for (size_t i = 0; i < lval->dim(); ++i) {
                        disjuncts.insert(arith::mkNeq(lval->indices().at(i), other_lval->indices().at(i)));
                    }
                    different_indices.emplace_back(bools::mkOr(disjuncts));
                }
                lvalues.emplace_back(lval);
                for (const auto cells = (*w)->val()->cells(); const auto& c: cells) {
                    // we do not support array-writes in right-hand sides
                    if (c->arr()->isArrayWrite()) {
                        return false;
                    }
                    if (!store_shift(c)) {
                        return false;
                    }
                }
                write = (*w)->arr();
            } else {
                // we do not support array-writes with complex conditions
                return false;
            }
        }
    }
    // applies the update to the given indices
    const auto update_idx = [&](const Idx& idx) {
        Idx res;
        for (const auto& i : idx) {
            res.emplace_back(i->subs(equations));
        }
        return res;
    };
    // make sure that written indices are pairwise different
    result.refinement = bools::mkAnd(different_indices);
    // map a[s] -> a[t] where a[s] is the lhs of an inductive equation and up(t) = s
    linked_hash_map<ArithVarPtr, ArithVarPtr> inductive;
    linked_hash_set<ArithVarPtr> displacing;
    std::vector<ArithVarPtr> a_work_list;
    // checks whether the given cells are inductive, and populates 'inductive' on the way
    const auto are_inductive = [&](const auto& cells) {
        return std::ranges::all_of(cells, [&](const ArithVarPtr& c) {
            const auto updated_indices = update_idx(c->indices());
            for (const auto &lval: written | std::views::keys) {
                if (lval->var() == c->var() && lval->indices() == updated_indices) {
                    inductive.put(lval, c);
                    a_work_list.emplace_back(lval);
                    return true;
                }
            }
            return false;
        });
    };
    // checks whether the given cells are displacing, and populates 'displacing' on the way
    const auto are_displacing = [&](const auto& cells) {
        return std::ranges::all_of(cells, [&](const ArithVarPtr& c) {
            const auto updated_indices = update_idx(c->indices());
            for (const auto &lval: written | std::views::keys) {
                if (lval->var() == c->var() && compare_lexicographically(lval->indices(), updated_indices) >= 0) {
                    return false;
                }
            }
            displacing.insert(c);
            return true;
        });
    };
    for (const auto& [lval,val] : written) {
        if (auto cells = val->cells(); are_inductive(cells)) {
            if (!inductive.contains(lval)) {
                // happens for assignments like a[x] = 0; in this case, we must
                // ensure that 'inductive' and the work list have entries for a[x]
                Idx indices;
                const auto& s = shift.at(lval);
                for (size_t i = 0; i < lval->dim(); ++i) {
                    indices.emplace_back(lval->indices().at(i) - s.at(i));
                }
                const auto pre = arrays::mkArrayRead(lval->var(), indices);
                inductive.put(lval, pre);
                a_work_list.emplace_back(lval);
            }
            if (Config::Analysis::logAccel) {
                std::cerr << lval << " = " << val << " is inductive" << std::endl;
            }
        } else if (are_displacing(cells)) {
            if (Config::Analysis::logAccel) {
                std::cerr << lval << " = " << val << " is displacing" << std::endl;
            }
        } else {
            return false;
        }
    }
    // checks if an arithmetic recurrence is ready for solving
    // we need closed forms for all cells occurring in indices, and for all cells occurring in the written value,
    // except for the inductive lvalue itself
    const auto a_is_ready = [&](const ArithVarPtr& lval, const Arith::Expr& val) {
        return std::ranges::all_of(lval->indices(), [&](const auto& i) {
                return std::ranges::all_of(i->cells(), [&](const auto& c) {
                    return closed_form.contains(c);
                });
            }) &&
            std::ranges::all_of(val->cells(), [&](const auto& c) {
                return lval == c || closed_form.contains(c);
            });
    };
    // solve equations for inductive lvalues
    bool changed {true};
    while (changed) {
        changed = false;
        for (auto it = a_work_list.begin(); it != a_work_list.end();) {
            const auto lval{*it};
            const auto& pre = inductive.at(lval);
            if (const auto& val{written.at(lval)}; a_is_ready(pre, val)) {
                if (!solve(pre, val)) {
                    std::cout << "failed to solve " << pre << " = " << val << std::endl;
                    // failed to compute closed form for this lval
                    return false;
                }
                changed = true;
                if (Config::Analysis::logAccel) {
                    std::cerr << "closed form for " << pre << ": " << closed_form.at(pre) << std::endl;
                }
                it = a_work_list.erase(it);
            } else {
                // this lval is not yet ready
                ++it;
            }
        }
    }
    // some lvalues did not become ready for solving, i.e., there is a cyclic dependency
    if (!a_work_list.empty()) {
        if (Config::Analysis::logAccel) {
            std::cout << "loop is not solvable" << std::endl;
        }
        return false;
    }
    // compute closed forms for displacing lvalues
    for (const auto& lval: displacing) {
        std::vector<Arith::Expr> indices;
        for (const auto& i : lval->indices()) {
            indices.emplace_back(i->subs(closed_form));
        }
        const auto updated{arrays::mkArrayRead(lval->var(), indices)};
        closed_form.put(lval, updated);
        closed_form_n_minus_one.put(std::pair(lval, updated->subs(n_to_n_minus_one)));
        if (Config::Analysis::logAccel) {
            std::cerr << "closed form for " << lval << ": " << closed_form.at(lval) << std::endl;
        }
    }
    // take care of booleans
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
    // Builds a formula whose free variables are n and the array indices idx,
    // and which is true iff the given lval was written for the last time in the n-th iteration.
    // Additionally, in the second component, it returns an instantiation for n in the closed form, that needs to
    // be applied to obtain the written value.
    const auto mk_last_write = [&](const ArithVarPtr& lval) {
        if (lval->dim() == 0) {
            return std::pair(top(), arith::zero());
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
        return std::pair(bools::mkAnd(lits) && mk_arr_not_written(lval->var(), *m + arith::one()), *m);
    };
    // build closed-form array expressions by considering the closed forms for the written lvalues one at a time
    for (const auto& [lval,r]: written) {
        if (lval->dim() == 0) {
            if (inductive.contains(lval)) {
                result.closed_form.update(lval, closed_form.at(lval));
            } else {
                result.closed_form.update(lval, r->subs(closed_form));
            }
        } else {
            const auto var = lval->var();
            // the array expression that has been constructed so far
            const auto old_val = result.closed_form.get(var);
            const auto [cond,instantiation_of_n] = mk_last_write(lval);
            const auto instantiate_n = Subs::build(n, instantiation_of_n);
            Arith::Expr new_val = arith::zero();
            if (const auto opt = inductive.get(lval)) {
                new_val = closed_form.at(*opt);
            } else {
                new_val = r->subs(closed_form);
            }
            result.closed_form.put(var, arrays::mkArrayWrite(old_val, cond, new_val->subs(instantiate_n)));
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
