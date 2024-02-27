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
#include "rel.hpp"

#include <unordered_set>

using namespace std;

ResultBase<ExprSubs, Proof> GuardToolbox::propagateEqualities(const BoolExpr e, const SymbolAcceptor &allow) {
    ResultBase<ExprSubs, Proof> res;
    for (const auto &var: e->vars().get<Arith::Var>()) {
        if (!allow(var)) continue;
        const auto bounds {e->getBounds(var)};
        for (const auto &b: bounds.upperBounds) {
            if (bounds.lowerBounds.contains(b) && b->isIntegral()) {
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

ResultBase<BSubs, Proof> GuardToolbox::propagateBooleanEqualities(const BoolExpr e) {
    ResultBase<BSubs, Proof> res;
    const auto equiv {e->impliedEqualities()};
    if (!equiv.empty()) {
        res = equiv.get<BoolTheory>();
        res.append(stringstream() << "propagated equivalences: " << equiv << std::endl);
    }
    return res;
}

ResultBase<BoolExpr, Proof> GuardToolbox::eliminateByTransitiveClosure(const BoolExpr e, bool removeHalfBounds, const SymbolAcceptor &allow) {
    ResultBase<BoolExpr, Proof> res(e);
    if (!e->isConjunction()) {
        return res;
    }
    auto guard {e->lits()};
    //get all variables that appear in an inequality
    linked_hash_set<Arith::Var> tryVars;
    std::unordered_set<Arith::Var> eliminated;
    for (const auto &lit : guard) {
        if (std::holds_alternative<Rel>(lit)) {
            const auto &rel = std::get<Rel>(lit);
            if (!rel.isPoly()) continue;
            rel.collectVars(tryVars);
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

        vector<Arith::Expression> varLessThan, varGreaterThan; //var <= expr and var >= expr
        vector<Arith::Lit> guardTerms; //indices of guard terms that can be removed if successful

        size_t explosive_lower {0};
        size_t explosive_upper {0};

        for (const auto &lit: guard) {
            if (std::holds_alternative<Rel>(lit)) {
                const auto &rel = std::get<Rel>(lit);
                //check if this guard must be used for var
                if (!rel.has(var)) continue;
                const auto bounds {rel.getBoundFromIneq(var)};
                if (bounds.first) {
                    varLessThan.push_back(*bounds.first);
                    if (is_explosive(var, *bounds.first)) {
                        ++explosive_upper;
                    }
                } else if (bounds.second) {
                    varGreaterThan.push_back(*bounds.second);
                    if (is_explosive(var, *bounds.second)) {
                        ++explosive_lower;
                    }
                } else {
                    goto abort;
                }
                if (explosive_upper > 1 && explosive_lower > 1) goto abort;
                guardTerms.push_back(rel);
            }
        }

        // abort if no eliminations can be performed
        if (guardTerms.empty()) goto abort;
        if (!removeHalfBounds && (varLessThan.empty() || varGreaterThan.empty())) goto abort;

        //success: remove lower <= x and x <= upper as they will be replaced
        for (const Rel &rel: guardTerms) {
            guard.erase(rel);
        }

        //add new transitive guard terms lower <= upper
        for (const auto &upper : varLessThan) {
            for (const auto &lower : varGreaterThan) {
                guard.insert(Rel::mkLeq(lower, upper));
            }
        }
        eliminated.insert(var);
        res.appendAll("elimiminated ", var);
        changed = true;

abort:  ; //this symbol could not be eliminated, try the next one
    }
    if (changed) {
        res = BExpression::mkAndFromLits(guard);
    }
    return res;
}

ResultBase<BoolExpr, Proof> _propagateBooleanEqualities(const BoolExpr e) {
    ResultBase<BoolExpr, Proof> res {e};
    const auto subs {GuardToolbox::propagateBooleanEqualities(e)};
    if (subs) {
        res = e->subs(Subs::build<BoolTheory>(*subs));
        res.append("Propagated Equivalences");
        res.storeSubProof(subs.getProof());
    }
    return res;
}

ResultBase<BoolExpr, Proof> _propagateEqualities(const BoolExpr e, const GuardToolbox::SymbolAcceptor &allow) {
    ResultBase<BoolExpr, Proof> res {e}; const auto subs {GuardToolbox::propagateEqualities(e, allow)};
    if (subs) {
        res = e->subs(Subs::build<Arith>(*subs));
        res.append("Extracted Implied Equalities");
        res.storeSubProof(subs.getProof());
    }
    return res;
}

ResultBase<BoolExpr, Proof> GuardToolbox::simplify(BoolExpr e) {
    ResultBase<BoolExpr, Proof> res {e};
    e = e->simplify();
    if (*res != e) {
        res = e;
        res.append("Simplified Formula");
    }
    return res;
}

ResultBase<BoolExpr, Proof> GuardToolbox::eliminateTempVars(BoolExpr e, const SymbolAcceptor &allow) {
    auto res {_propagateBooleanEqualities(e)};
    if (res) {
        return res;
    }
    res = _propagateEqualities(e, allow);
    if (res) {
        return res;
    }
    res = simplify(e);
    if (res) {
        return res;
    }
    return GuardToolbox::eliminateByTransitiveClosure(e, true, allow);
}

ResultBase<BoolExpr, Proof> GuardToolbox::preprocessFormula(const BoolExpr e, const SymbolAcceptor &allow) {
    ResultBase<BoolExpr, Proof> res {e};
    auto changed {false};
    do {
        auto tmp {eliminateTempVars(*res, allow)};
        changed = bool(tmp);
        res.concat(tmp);
    } while (changed);
    return res;
}
