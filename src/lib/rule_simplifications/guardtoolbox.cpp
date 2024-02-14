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

ResultBase<ExprSubs, Proof> GuardToolbox::propagateEqualities(const BoolExpr e, SolvingLevel maxlevel, const SymbolAcceptor &allow) {
    ResultBase<ExprSubs, Proof> res;
    auto guard = e->universallyValidLits();

    for (const auto &r: guard) {
        if (std::holds_alternative<Rel>(r)) {
            const auto rel {std::get<Rel>(r).subs(*res)};
            if (!rel.isEq()) {
                continue;
            }

            const auto target {rel.rhs() - rel.lhs()};
            if (!target.isPoly()) {
                continue;
            }

            // Check if equation can be solved for any single variable.
            // We prefer to solve for variables where this is easy,
            // e.g. in x+2*y = 0 we prefer x since x has only the trivial coefficient 1.
            for (int level=TrivialCoeffs; level <= (int)maxlevel; ++level) {
                for (const auto &var : target.vars()) {
                    if (!allow(var)) continue;

                    //solve target for var (result is in target)
                    auto optSolved = target.solveTermFor(var, (SolvingLevel)level);
                    if (!optSolved) continue;
                    const auto solved {*optSolved};

                    //disallow replacing non-free vars by a term containing free vars
                    //could be unsound, as free vars can lead to unbounded complexity
                    if (!var.isTempVar() && containsTempVar(solved)) continue;

                    //extend the substitution, use concat in case var occurs on some rhs of varSubs
                    res->put(var, solved);
                    res->concatInPlace(*res);
                    res.succeed();
                    stringstream s;
                    s << "propagated equality " << var << " = " << solved;
                    res.append(s.str());
                    res.newline();
                    goto next;
                }
            }
        }
        next:;
    }
    return res;
}


ResultBase<BoolSubs<IntTheory, BoolTheory>, Proof> GuardToolbox::propagateBooleanEqualities(const BoolExpr e) {
    ResultBase<BoolSubs<IntTheory, BoolTheory>, Proof> res;
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
    linked_hash_set<NumVar> tryVars;
    std::unordered_set<NumVar> eliminated;
    for (const auto &lit : guard) {
        if (std::holds_alternative<Rel>(lit)) {
            const auto &rel = std::get<Rel>(lit);
            if (!rel.isIneq() || !rel.isPoly()) continue;
            rel.collectVars(tryVars);
        }
    }

    const auto is_explosive = [&](const auto &var, const auto &target){
        return target.hasVarWith([&](const auto &x) {
            return x != var && !eliminated.contains(x) && tryVars.contains(x);
        });
    };

    //for each variable, try if we can eliminate every occurrence. Otherwise do nothing.
    bool changed = false;
    for (const auto &var : tryVars) {
        if (!allow(var)) continue;

        vector<Expr> varLessThan, varGreaterThan; //var <= expr and var >= expr
        vector<Rel> guardTerms; //indices of guard terms that can be removed if successful

        size_t explosive_lower {0};
        size_t explosive_upper {0};

        for (const auto &lit: guard) {
            if (std::holds_alternative<Rel>(lit)) {
                const auto &rel = std::get<Rel>(lit);
                //check if this guard must be used for var
                if (!rel.has(var)) continue;
                if (!rel.isIneq() || !rel.isPoly()) goto abort; // contains var, but cannot be handled

                const auto target {rel.toLeq().makeRhsZero().lhs()};
                if (!target.has(var)) continue; // might have changed, e.g. x <= x

                //check coefficient and direction
                const auto c {target.expand().coeff(var)};
                if (c != 1 && c != -1) goto abort;
                if (c == 1) {
                    varLessThan.push_back( -(target-var) );
                    if (is_explosive(var, target)) {
                        ++explosive_upper;
                    }
                } else {
                    varGreaterThan.push_back( target+var );
                    if (is_explosive(var, target)) {
                        ++explosive_lower;
                    }
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
        for (const Expr &upper : varLessThan) {
            for (const Expr &lower : varGreaterThan) {
                guard.insert(Rel::buildLeq(lower, upper));
            }
        }
        eliminated.insert(var);
        res.appendAll("elimiminated ", var);
        changed = true;

abort:  ; //this symbol could not be eliminated, try the next one
    }
    if (changed) {
        res = BExpression::buildAndFromLits(guard);
    }
    return res;
}


ResultBase<Guard, Proof> GuardToolbox::makeEqualities(const BoolExpr e) {
    ResultBase<Guard, Proof> res;
    const auto guard {e->universallyValidLits()};
    vector<pair<Rel,Expr>> terms; //inequalities from the guard, with the associated index in guard
    map<Rel,pair<Rel,Expr>> matches; //maps index in guard to a second index in guard, which can be replaced by Expression

    // Find matching constraints "t1 <= 0" and "t2 <= 0" such that t1+t2 is zero
    for (const auto &lit: guard) {
        if (std::holds_alternative<Rel>(lit)) {
            const auto &rel = std::get<Rel>(lit);
            if (rel.isEq()) continue;
            if (!rel.isPoly() && rel.isStrict()) continue;
//            Expr term = rel.toLeq().makeRhsZero().lhs().normalizeCoefficients();
//            if (term.isGround()) {
//                continue;
//            }
//            for (const auto &prev : terms) {
//                const auto div {(prev.second / term).expand()};
//                if (div.isRationalConstant() && div.toNum().is_negative()) {
//                    matches.emplace(prev.first, make_pair(rel, prev.second));
//                }
//            }
            const auto term {rel.toLeq().makeRhsZero().lhs()};
            for (const auto &prev : terms) {
                if ((prev.second + term).isZero()) {
                    matches.emplace(prev.first, make_pair(rel,prev.second));
                }
            }
            terms.emplace_back(rel, term);
        }
    }

    if (matches.empty()) return res;

    // Construct the new guard by keeping unmatched constraint
    // and replacing matched pairs by an equality constraint.
    // This code below mostly retains the order of the constraints.
    set<Rel> ignore;
    for (const auto &lit: guard) {
        if (std::holds_alternative<Rel>(lit)) {
            const auto &rel = std::get<Rel>(lit);
            //ignore multiple equalities as well as the original second inequality
            if (ignore.contains(rel)) continue;

            auto it = matches.find(rel);
            if (it != matches.end()) {
                res.succeed();
                res->push_back(Rel::buildEq(it->second.second, 0));
                res.appendAll("extracted ", it->second.second, " = 0");
                ignore.insert(it->second.first);
            }
        }
    }
    return res;
}
