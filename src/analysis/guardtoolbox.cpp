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
#include "expr.hpp"
#include "rule.hpp"
#include "rel.hpp"

using namespace std;

Result<Rule> GuardToolbox::propagateEqualities(const Rule &rule, SolvingLevel maxlevel, SymbolAcceptor allow) {
    ExprSubs varSubs;
    ResultViaSideEffects proof;
    auto guard = rule.getGuard()->universallyValidLits();

    for (const auto &r: guard) {
        if (std::holds_alternative<Rel>(r)) {
            Rel rel = std::get<Rel>(r).subs(varSubs);
            if (!rel.isEq()) {
                continue;
            }

            Expr target = rel.rhs() - rel.lhs();
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
                    Expr solved = *optSolved;

                    //disallow replacing non-free vars by a term containing free vars
                    //could be unsound, as free vars can lead to unbounded complexity
                    if (!var.isTempVar() && containsTempVar(solved)) continue;

                    //extend the substitution, use compose in case var occurs on some rhs of varSubs
                    varSubs.put(var, solved);
                    varSubs = varSubs.compose(varSubs);
                    stringstream s;
                    s << "propagated equality " << var << " = " << solved;
                    proof.append(s.str());
                    proof.newline();
                    proof.succeed();
                    goto next;
                }
            }
        }
        next:;
    }

    //apply substitution to the entire rule
    Result<Rule> res(rule);
    if (proof) {
        Subs subs;
        subs.get<IntTheory>() = varSubs;
        res = rule.subs(subs);
        res.ruleTransformationProof(rule, "Propagated Equalities", res.get());
        res.newline();
        res.storeSubProof(proof.getProof());
    }
    return res;
}


Result<Rule> GuardToolbox::propagateBooleanEqualities(const Rule &rule) {
    Result<Rule> res(rule);
    Proof subproof;
    Subs equiv;

    // If the value of program variables is implied by the guard, 
    // we remove them during propagating, which looses information.
    // Thus we collect implied program variable equalities and re-add 
    // them to the guard at the end.
    std::vector<BoolExpr> program_var_equalities;
    do {
        equiv = res->getGuard()->impliedEqualities();

        // collect implied program variable equalities:
        for (const auto &var: equiv.domain()) {
            if (expr::isProgVar(var)) {
                // if (res->getGuard()->countOccuranceOf(var) == 1) {
                //     // when the program variable occurs only once in the expression,
                //     // there is no need to substitute it. This also prevents an 
                //     // infinite loop, because when we re-add the program variables to the 
                //     // guard using `buildAnd`, we trigger `propagateBooleanEqualities`
                //     // again.
                //     equiv.erase(var);
                // } else {
                program_var_equalities.push_back(
                    expr::mkEq(expr::toExpr(var), equiv.get(var))->simplify()
                );
                // }
            }
        }

        if (!equiv.empty()) {
            res = res->subs(equiv);
            subproof.append(stringstream() << "propagated equivalences: " << equiv << std::endl);
        }
    } while (!equiv.empty());
    if (res) {
        // re-add program variable equalities to guard:
        program_var_equalities.push_back(res->getGuard());
        const auto new_guard = BExpression::buildAnd(program_var_equalities);

        if (rule.getGuard() == new_guard) {
            return Result(rule);
        } 

        res = res->withGuard(new_guard);
        res.ruleTransformationProof(rule, "Propagated Equivalences", *res);
        res.storeSubProof(subproof);
    }
    return res;
}


Result<Rule> GuardToolbox::eliminateByTransitiveClosure(const Rule &rule, bool removeHalfBounds, SymbolAcceptor allow) {
    Result<Rule> res(rule);
    if (!rule.getGuard()->isConjunction()) {
        return res;
    }
    auto guard = rule.getGuard()->lits();
    //get all variables that appear in an inequality
    std::set<NumVar> tryVars;
    for (const auto &lit : guard) {
        if (std::holds_alternative<Rel>(lit)) {
            const auto &rel = std::get<Rel>(lit);
            if (!rel.isIneq() || !rel.isPoly()) continue;
            rel.collectVars(tryVars);
        }
    }

    //for each variable, try if we can eliminate every occurrence. Otherwise do nothing.
    bool changed = false;
    for (const auto &var : tryVars) {
        if (!allow(var)) continue;

        vector<Expr> varLessThan, varGreaterThan; //var <= expr and var >= expr
        vector<Rel> guardTerms; //indices of guard terms that can be removed if successful

        for (const auto &lit: guard) {
            if (std::holds_alternative<Rel>(lit)) {
                const auto &rel = std::get<Rel>(lit);
                //check if this guard must be used for var
                if (!rel.has(var)) continue;
                if (!rel.isIneq() || !rel.isPoly()) goto abort; // contains var, but cannot be handled

                Expr target = rel.toLeq().makeRhsZero().lhs();
                if (!target.has(var)) continue; // might have changed, e.h. x <= x

                //check coefficient and direction
                Expr c = target.expand().coeff(var);
                if (c != 1 && c != -1) goto abort;
                if (c == 1) {
                    varLessThan.push_back( -(target-var) );
                } else {
                    varGreaterThan.push_back( target+var );
                }
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
        changed = true;

abort:  ; //this symbol could not be eliminated, try the next one
    }
    if (changed) {
        res = rule.withGuard(BExpression::buildAndFromLits(guard));
        res.ruleTransformationProof(rule, "Eliminated Temporary Variables", *res);
    }
    return res;
}


Result<Rule> GuardToolbox::makeEqualities(const Rule &rule) {
    Result<Rule> res(rule);
    const auto &guard = rule.getGuard()->universallyValidLits();
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
            Expr term = rel.toLeq().makeRhsZero().lhs();
            for (const auto &prev : terms) {
                if ((prev.second + term).isZero()) {
                    matches.emplace(prev.first, make_pair(rel,prev.second));
                }
            }
            terms.push_back(make_pair(rel,term));
            terms.push_back(make_pair(rel, term));
        }
    }

    if (matches.empty()) return res;

    // Construct the new guard by keeping unmatched constraint
    // and replacing matched pairs by an equality constraint.
    // This code below mostly retains the order of the constraints.
    Guard equalities;
    set<Rel> ignore;
    for (const auto &lit: guard) {
        if (std::holds_alternative<Rel>(lit)) {
            const auto &rel = std::get<Rel>(lit);
            //ignore multiple equalities as well as the original second inequality
            if (ignore.count(rel) > 0) continue;

            auto it = matches.find(rel);
            if (it != matches.end()) {
                equalities.push_back(Rel::buildEq(it->second.second, 0));
                ignore.insert(it->second.first);
            }
        }
    }
    if (!equalities.empty()) {
        res.set(rule.withGuard(rule.getGuard() & BExpression::buildAndFromLits(equalities)));
        res.ruleTransformationProof(rule, "Extracted Implied Equalities", *res);
    }
    return res;
}
