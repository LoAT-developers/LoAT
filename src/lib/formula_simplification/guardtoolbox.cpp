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

#include <unordered_set>

using namespace std;

ResultBase<ArithSubs, Proof> GuardToolbox::propagateEqualities(const Bools::Expr e, const SymbolAcceptor &allow) {
    ResultBase<ArithSubs, Proof> res;
    const auto vars {e->vars().get<Arith::Var>()};
    for (const auto &var: vars) {
        if (!allow(var)) continue;
        const auto bounds {e->getBounds(var)};
        for (const auto &b: bounds.upperBounds) {
            if (bounds.lowerBounds.contains(b) && b->isIntegral()) {
                const auto vars {b->vars()};
                if (std::any_of(vars.begin(), vars.end(), [&](const auto x) {
                    return res->contains(x);
                })) continue;
                //extend the substitution, use concat in case var occurs on some rhs of varSubs
                res->put(var, b);
                res->concatInPlace(*res);
                res.succeed();
                stringstream s;
                s << "propagated equality " << var << " = " << b;
                res.append(s.str());
                res.newline();
                break;
            }
        }
    }
    return res;
}

ResultBase<BoolSubs, Proof> GuardToolbox::propagateBooleanEqualities(const Bools::Expr e) {
    ResultBase<BoolSubs, Proof> res;
    const auto equiv {impliedEqualities(e)};
    if (!equiv.empty()) {
        res = equiv.get<Bools>();
        res.append(stringstream() << "propagated equivalences: " << equiv << std::endl);
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
        if (std::holds_alternative<ArithLit>(lit)) {
            const auto &rel = std::get<ArithLit>(lit);
            if (rel.isGt()) {
                rel.collectVars(candidates);
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
        // used for heuristic for detecting cases where we get an exponential blow-up[]
        size_t explosive_lower {0};
        size_t explosive_upper {0};
        for (const auto &lit: lits) {
            if (theory::vars(lit).contains(var)) {
                if (std::holds_alternative<ArithLit>(lit)) {
                    const auto &rel {std::get<ArithLit>(lit)};
                    if (!rel.isGt()) {
                        // if the variable occurs in an equality, then it should be eliminated by equality propagation
                        // if it occurs in a negated equality, then we cannot eliminate
                        goto abort;
                    }
                    if (!rel.isLinear({{var}})) {
                        // no variable elimination for non-linear arithmetic
                        goto abort;
                    }
                    const auto term {rel.lhs()};
                    const auto coeff {*term->coeff(var)};
                    if (coeff->is(1) == 1) {
                        // we have var + p > 0, i.e., var >= -p+1
                        lower_bounds.push_back(arith::mkPlus({-term, var, arith::mkConst(1)}));
                        if (is_explosive(var, term)) {
                            ++explosive_upper;
                        }
                    } else if (coeff->is(-1)) {
                        // we have -var + p > 0, i.e., p-1 >= var
                        upper_bounds.push_back(arith::mkPlus({term, var, arith::mkConst(-1)}));
                        if (is_explosive(var, term)) {
                            ++explosive_lower;
                        }
                    } else {
                        // the coefficient is neither 1 nor -1, so we would need divisibility constraints to eliminate the variable
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
        for (const ArithLit &rel: eliminated_lits) {
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
    ResultBase<Bools::Expr, Proof> res {e}; const auto subs {GuardToolbox::propagateEqualities(e, allow)};
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
        auto tmp {eliminateTempVars(*res, allow)};
        changed = bool(tmp);
        res.concat(tmp);
    } while (changed);
    return res;
}
