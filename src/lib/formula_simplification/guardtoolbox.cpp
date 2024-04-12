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

ResultBase<Bools::Expr, Proof> GuardToolbox::eliminateByTransitiveClosure(const Bools::Expr e, bool removeHalfBounds, const SymbolAcceptor &allow) {
    ResultBase<Bools::Expr, Proof> res(e);
    if (!e->isConjunction()) {
        return res;
    }
    auto guard {e->lits()};
    //get all variables that appear in an inequality
    linked_hash_set<Arith::Var> tryVars;
    std::unordered_set<Arith::Var> eliminated;
    for (const auto &lit : guard) {
        if (std::holds_alternative<ArithLit>(lit)) {
            const auto &rel = std::get<ArithLit>(lit);
            if (rel.isGt()) {
                rel.collectVars(tryVars);
            }
        }
    }

    const auto is_explosive = [&](const auto &var, const auto &target){
        return target->hasVarWith([&](const auto x) {
            return x != var && !eliminated.contains(x) && tryVars.contains(x);
        });
    };

    //for each variable, try if we can eliminate every occurrence. Otherwise do nothing.
    bool changed = false;
    for (const auto &var : tryVars) {
        if (!allow(var)) continue;

        vector<Arith::Expr> varLessThan, varGreaterThan; //var <= expr and var >= expr
        vector<Arith::Lit> guardTerms; //indices of guard terms that can be removed if successful

        size_t explosive_lower {0};
        size_t explosive_upper {0};

        for (const auto &lit: guard) {
            if (std::holds_alternative<ArithLit>(lit)) {
                const auto &rel {std::get<ArithLit>(lit)};
                if (rel.isGt()) {
                    const auto target {rel.lhs()};
                    // check if this inequation must be used for var
                    if (!rel.isLinear({{var}})) {
                        continue;
                    }
                    const auto c {rel.lhs()->coeff(var)};
                    // only use this inequation if the coefficient is 1 or -1, otherwise it may encode information about divisibility
                    if (!c || (!(*c)->is(1) && !(*c)->is(-1))) {
                        goto abort;
                    }
                    if ((*c)->is(1) == 1) {
                        varLessThan.push_back(-(target - var));
                        if (is_explosive(var, target)) {
                            ++explosive_upper;
                        }
                    } else {
                        varGreaterThan.push_back(target + var);
                        if (is_explosive(var, target)) {
                            ++explosive_lower;
                        }
                    }
                    // if (explosive_upper > 1 && explosive_lower > 1) goto abort;
                    guardTerms.push_back(rel);
                }
            }
        }

        // abort if no eliminations can be performed
        if (guardTerms.empty()) goto abort;
        if (!removeHalfBounds && (varLessThan.empty() || varGreaterThan.empty())) {
            goto abort;
        }

        //success: remove lower <= x and x <= upper as they will be replaced
        for (const ArithLit &rel: guardTerms) {
            guard.erase(rel);
        }

        //add new transitive guard terms lower <= upper
        for (const auto &upper : varLessThan) {
            for (const auto &lower : varGreaterThan) {
                guard.insert(arith::mkLeq(lower, upper));
            }
        }
        eliminated.insert(var);
        res.appendAll("elimiminated ", var);
        changed = true;

abort:  ; //this symbol could not be eliminated, try the next one
    }
    if (changed) {
        res = bools::mkAndFromLits(guard);
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
    return GuardToolbox::eliminateByTransitiveClosure(e, true, allow);
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
