/*  This file is part of LoAT.
 *  Copyright (c) 2015-2016 Matthias Naaf, RWTH Aachen University, Germany
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses>.
 */

#include "guardtoolbox.hpp"
#include "theory.hpp"
#include "subs.hpp"
#include "impliedequalities.hpp"
#include "vector.hpp"
#include "smtfactory.hpp"

#include <unordered_set>

using namespace std;

ResultBase<ArithSubs, Proof> GuardToolbox::propagateEqualities(const Bools::Expr e, const SymbolAcceptor &allow) {
    ResultBase<ArithSubs, Proof> res;
    const auto subs {e->propagateEqualities(allow)};
    if (!subs.empty()) {
        res = subs;
        res.appendAll("propagated equalities: ", subs);
    }
    return res;
}

ResultBase<BoolSubs, Proof> GuardToolbox::propagateBooleanEqualities(const Bools::Expr e) {
    ResultBase<BoolSubs, Proof> res;
    const auto equiv {impliedEqualities(e)};
    if (!equiv.empty()) {
        res = equiv.get<Bools>();
        res.appendAll("propagated equivalences: ", equiv);
    }
    return res;
}

/**
 * Fourier-Motzkin, restricted to the case thatall coefficients are 1 or -1, so that it can be used for integers.
 */
ResultBase<Bools::Expr, Proof> GuardToolbox::eliminateByTransitiveClosure(const Bools::Expr e, const SymbolAcceptor &allow) {
    ResultBase<Bools::Expr, Proof> res(e);
    if (!e->isConjunction()) {
        return res;
    }
    auto lits {e->lits()};

    // get all variables that appear in an inequality
    linked_hash_set<Arith::Var> candidates;
    for (const auto &lit : lits) {
        if (std::holds_alternative<Arith::Lit>(lit)) {
            const auto &rel = std::get<Arith::Lit>(lit);
            if (rel->isGt()) {
                rel->collectVars(candidates);
            }
        }
    }

    std::unordered_set<Arith::Var> eliminated;
    const auto is_explosive = [&](const auto &var, const auto &term){
        return term->hasVarWith([&](const auto x) {
            return x != var && !eliminated.contains(x) && candidates.contains(x);
        });
    };

    bool changed = false;
    for (const auto &var: candidates) {
        if (!allow(var)) continue;
        vector<Arith::Expr> upper_bounds;
        vector<Arith::Expr> lower_bounds;
        vector<Arith::Lit> eliminated_lits;
        auto may_be_dually_bounded {true};
        auto lower_bounded {false};
        auto upper_bounded {false};
        // used for heuristic for detecting cases where we get an exponential blow-up[]
        size_t explosive_lower {0};
        size_t explosive_upper {0};
        for (const auto &lit: lits) {
            if (theory::vars(lit).contains(var)) {
                if (std::holds_alternative<Arith::Lit>(lit)) {
                    const auto &rel {std::get<Arith::Lit>(lit)};
                    if (!rel->isGt()) {
                        // if the variable occurs in an equality, then it should be eliminated by equality propagation
                        // if it occurs in a negated equality, then we cannot eliminate
                        goto abort;
                    }
                    if (!rel->isLinear({{var}})) {
                        // no variable elimination for non-linear arithmetic
                        goto abort;
                    }
                    const auto term {rel->lhs()};
                    const auto coeff {*term->coeff(var)};
                    if (coeff->is(1) == 1) {
                        // we have var + p > 0, i.e., var >= -p+1
                        lower_bounds.push_back(arith::mkPlus({-term, var, arith::mkConst(1)}));
                        lower_bounded = true;
                        if (is_explosive(var, term)) {
                            ++explosive_upper;
                        }
                    } else if (coeff->is(-1)) {
                        // we have -var + p > 0, i.e., p-1 >= var
                        upper_bounds.push_back(arith::mkPlus({term, var, arith::mkConst(-1)}));
                        upper_bounded = true;
                        if (is_explosive(var, term)) {
                            ++explosive_lower;
                        }
                    } else {
                        const auto int_coeff {coeff->isInt()};
                        if (int_coeff) {
                            // the coefficient is constant, but neither 1 nor -1
                            // if the variable bounded from both sides, then we need divisibility constraints to eliminate it
                            may_be_dually_bounded = false;
                            if (*int_coeff > 0) {
                                lower_bounded = true;
                            } else {
                                upper_bounded = true;
                            }
                        } else {
                            // non-constant coefficient
                            goto abort;
                        }
                    }
                    if (!may_be_dually_bounded && lower_bounded && upper_bounded) {
                        goto abort;
                    }
                    if (explosive_upper > 1 && explosive_lower > 1) {
                        // elimination might cause exponential blow-up
                        goto abort;
                    }
                    eliminated_lits.push_back(rel);
                } else {
                    // variable occurs in a literal from another theory
                    goto abort;
                }
            }
        }
        // perform the elimination
        for (const Arith::Lit &rel: eliminated_lits) {
            lits.erase(rel);
        }
        for (const auto &upper : upper_bounds) {
            for (const auto &lower : lower_bounds) {
                lits.insert(arith::mkLeq(lower, upper));
            }
        }
        eliminated.insert(var);
        res.appendAll("eliminated ", var, "; lower bounds: ", lower_bounds, "; upper bounds: ", upper_bounds);
        changed = true;

abort:  ; //this symbol could not be eliminated, try the next one
    }
    if (changed) {
        res = bools::mkAndFromLits(lits);
    }
    return res;
}

ResultBase<Bools::Expr, Proof> _propagateBooleanEqualities(const Bools::Expr e) {
    ResultBase<Bools::Expr, Proof> res {e};
    const auto subs {GuardToolbox::propagateBooleanEqualities(e)};
    if (subs) {
        res = Subs::build<Bools>(*subs)(e);
        res.append("Propagated Equivalences");
        res.storeSubProof(subs.getProof());
    }
    return res;
}

ResultBase<Bools::Expr, Proof> _propagateEqualities(const Bools::Expr e, const GuardToolbox::SymbolAcceptor &allow) {
    ResultBase<Bools::Expr, Proof> res {e};
    const auto subs {GuardToolbox::propagateEqualities(e, allow)};
    if (subs) {
        res = Subs::build<Arith>(*subs)(e);
        res.append("Extracted Implied Equalities");
        res.storeSubProof(subs.getProof());
    }
    return res;
}

ResultBase<Bools::Expr, Proof> GuardToolbox::eliminateTempVars(Bools::Expr e, const SymbolAcceptor &allow) {
    auto res {_propagateBooleanEqualities(e)};
    if (res) {
        return res;
    }
    res = _propagateEqualities(e, allow);
    if (res) {
        return res;
    }
    return GuardToolbox::eliminateByTransitiveClosure(e, allow);
}

ResultBase<Bools::Expr, Proof> GuardToolbox::preprocessFormula(const Bools::Expr e, const SymbolAcceptor &allow) {
    ResultBase<Bools::Expr, Proof> res {e};
    auto changed {false};
    do {
        const auto tmp {_propagateBooleanEqualities(*res)};
        changed = bool(tmp);
        res.concat(tmp);
    } while (changed);
    do {
        auto tmp {_propagateEqualities(*res, allow)};
        changed = bool(tmp);
        res.concat(tmp);
        tmp = GuardToolbox::eliminateByTransitiveClosure(*res, allow);
        changed |= bool(tmp);
        res.concat(tmp);
    } while (changed);
    return res;
}

Bools::Expr GuardToolbox::removeRedundantInequations(const Bools::Expr e) {
    if (!e->isConjunction()) {
        return e;
    }
    // collect linear bounds of the form b >= 0
    auto lits {e->lits()};
    auto &arith_lits {lits.get<Arith::Lit>()};
    ArithExprVec bounded;
    for (auto it = arith_lits.begin(); it != arith_lits.end();) {
        const auto lit {*it};
        const auto lhs {lit->lhs()};
        if (lhs->isLinear()) {
            if (lit->isGt()) {
                bounded.push_back(lhs - arith::mkConst(1));
                it = arith_lits.erase(it);
            } else if (lit->isEq()) {
                bounded.push_back(lhs);
                bounded.push_back(-lhs);
                it = arith_lits.erase(it);
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }
    // set up one non-negative multiplier for each bound
    auto solver {SmtFactory::modelBuildingSolver(QF_LA)};
    std::vector<Arith::Var> factors;
    for (const auto &b: bounded) {
        const auto f {Arith::next()};
        factors.push_back(f);
        solver->add(arith::mkGeq(f, arith::mkConst(0)));
    }
    const auto arith_vars {e->vars().get<Arith::Var>()};
    for (auto it = bounded.begin(); it != bounded.end();) {
        solver->push();
        // set up one equation for each variable
        for (const auto &x: arith_vars) {
            ArithExprVec addends;
            for (unsigned idx = 0; idx < bounded.size(); ++idx) {
                if (*it != bounded[idx] && bounded[idx]->has(x)) {
                    addends.push_back(*bounded[idx]->coeff(x) * factors[idx]);
                }
            }
            solver->add(arith::mkEq(*(*it)->coeff(x), arith::mkPlus(std::move(addends))));
        }
        // and one equation for the constant part
        ArithExprVec addends;
        for (unsigned idx = 0; idx < bounded.size(); ++idx) {
            if (*it != bounded[idx]) {
                addends.push_back(arith::mkConst(bounded[idx]->getConstantAddend()) * factors[idx]);
            }
        }
        solver->add(arith::mkGeq(arith::mkConst((*it)->getConstantAddend()), arith::mkPlus(std::move(addends))));
        if (solver->check() == SmtResult::Sat) {
            it = bounded.erase(it);
        } else {
            arith_lits.insert(arith::mkGeq(*it, arith::mkConst(0)));
            ++it;
        }
        solver->pop();
    }
    return bools::mkAndFromLits(lits);
}
