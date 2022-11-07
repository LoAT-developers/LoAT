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
#include "rule.hpp"
#include "rel.hpp"
#include "relevantvariables.hpp"
#include "farkas.hpp"
#include "templates.hpp"
#include "smtfactory.hpp"

using namespace std;


bool GuardToolbox::isTrivialImplication(const Rel &a, const Rel &b) {

    // an equality can only be implied by an equality
    if (b.isEq()) {
        if (!a.isEq()) return false;

        Expr aDiff = a.rhs() - a.lhs();
        Expr bDiff = b.rhs() - b.lhs();
        return (aDiff - bDiff).expand().isZero();
    } else if (a.isIneq()) {
        if (a.isStrict() == b.isStrict()) {
            if (Rel::buildLeq(a.toG().makeRhsZero().lhs(), b.toG().makeRhsZero().lhs()).isTriviallyTrue()) {
                return true;
            }
        } else if (!a.isStrict() && a.isPoly()) {
            if (Rel::buildLeq(a.toGt().makeRhsZero().lhs(), b.toG().makeRhsZero().lhs()).isTriviallyTrue()) {
                return true;
            }
        } else if (b.isPoly()) {
            if (Rel::buildLeq(a.toG().makeRhsZero().lhs(), b.toGt().makeRhsZero().lhs()).isTriviallyTrue()) {
                return true;
            }
        }
    } else if (a.isEq()) {
        Expr aDiff = a.rhs() - a.lhs();
        Expr bLhs = b.toG().lhs() - b.toG().rhs();
        if (b.isStrict()) {
            return Rel::buildLt(aDiff, bLhs).isTriviallyTrue() || Rel::buildLt(-aDiff, bLhs).isTriviallyTrue();
        } else {
            return Rel::buildLeq(aDiff, bLhs).isTriviallyTrue() || Rel::buildLeq(-aDiff, bLhs).isTriviallyTrue();
        }
    }
    return false;
}

Result<Rule> GuardToolbox::propagateEqualities(const ITSProblem &its, const Rule &rule, SolvingLevel maxlevel, SymbolAcceptor allow) {
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
                    Expr solved = optSolved.get();

                    //disallow replacing non-free vars by a term containing free vars
                    //could be unsound, as free vars can lead to unbounded complexity
                    if (!its.isTempVar(var) && containsTempVar(its, solved)) continue;

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
        res.ruleTransformationProof(rule, "propagated equalities", res.get(), its);
        res.storeSubProof(proof.getProof());
    }
    return res;
}


Result<Rule> GuardToolbox::propagateBooleanEqualities(const ITSProblem &its, const Rule &rule) {
    auto hasTempVars = [&](const auto e) {
        const auto boolVars = expression::variables(e).template get<BoolVar>();
        for (const auto &x: boolVars) {
            if (its.isTempVar(x)) {
                return true;
            }
        }
        return false;
    };
    auto bvars = rule.getGuard()->vars().get<BoolVar>();
    Result<Rule> res(rule);
    Proof subproof;
    bool changed;
    do {
        changed = false;
        for (auto it = bvars.begin(); it != bvars.end();) {
            const auto var = *it;
            if (its.isTempVar(var)) {
                BoolExprSet consequences = rule.getGuard()->findConsequences(var);
                const auto lit = BExpression::buildTheoryLit(var);
                for (const BoolExpr &c: consequences) {
                    if (!hasTempVars(c)) {
                        if (SmtFactory::isImplication(rule.getGuard() & c, lit, its)) {
                            res = res->subs(Subs::build<BoolTheory>(var, c));
                            it = bvars.erase(it);
                            changed = true;
                            subproof.append(stringstream() << "replaced " << var << " with " << c);
                            res.storeSubProof(subproof);
                        }
                    }
                }
            }
            if (changed) {
                break;
            } else {
                ++it;
            }
        }
    } while (changed);
    if (res) {
        res.ruleTransformationProof(rule, "propagated boolean equalities", res.get(), its);
        res.storeSubProof(subproof);
    }
    return res;
}


Result<Rule> GuardToolbox::eliminateByTransitiveClosure(const Rule &rule, bool removeHalfBounds, SymbolAcceptor allow, const ITSProblem &its) {
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
                if (c.compare(1) != 0 && c.compare(-1) != 0) goto abort;
                if (c.compare(1) == 0) {
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
        res.ruleTransformationProof(rule, "eliminated temporary variables via transitive closure", *res, its);
    }
    return res;
}


Result<Rule> GuardToolbox::makeEqualities(const Rule &rule, const ITSProblem &its) {
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
            Expr term = rel.toLeq().makeRhsZero().lhs();
            for (const auto &prev : terms) {
                if ((prev.second + term).isZero()) {
                    matches.emplace(prev.first, make_pair(rel,prev.second));
                }
            }
            terms.push_back(make_pair(rel,term));
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
        res.ruleTransformationProof(rule, "made implied equalities explicit", *res, its);
    }
    return res;
}

Result<Rule> GuardToolbox::propagateEqualitiesBySmt(const Rule &rule, ITSProblem &its) {
    Result<Rule> res(rule);
    if (!rule.getGuard()->isLinear() || !rule.getGuard()->forall([](const Lit &x){return std::holds_alternative<Rel>(x);})) {
        return res;
    }
    const BExpr<IntTheory> guard = rule.getGuard()->transform<IntTheory>();
    auto tempVars = guard->vars().get<NumVar>();
    for (auto it = tempVars.begin(); it != tempVars.end();) {
        if (its.isTempVar(*it)) {
            ++it;
        } else {
            it = tempVars.erase(it);
        }
    }
    if (tempVars.size() > 10) {
        return res;
    }

    Templates templates;
    auto solver = SmtFactory::modelBuildingSolver<IntTheory>(QF_NA, its, Config::Smt::SimpTimeout);
    for (const auto &x: tempVars) {
        solver->resetSolver();
        theory::VarSet<IntTheory> varsOfInterest;
        varsOfInterest.get<NumVar>().insert(x);
        auto relevantVars = util::RelevantVariables<IntTheory>::find(varsOfInterest, {}, guard).get<NumVar>();
        relevantVars.erase(x);
        Templates::Template t = templates.buildTemplate(relevantVars, its);
        relevantVars.insert(x);
        const BExpr<IntTheory> e = FarkasLemma::apply(guard, {Rel::buildEq(t.t, x)}, relevantVars, t.params, its);
        solver->add(e);
        if (solver->check() == Sat) {
            const ExprSubs &m = solver->model().toSubs().get<IntTheory>().project(t.params);
            Subs subs;
            subs.get<IntTheory>().put(x, t.t.subs(m));
            const Rule newRule = res->subs(subs);
            std::stringstream s;
            s << "propagated equalities via SMT: " << m;
            Proof subProof;
            subProof.append(s.str());
            res.ruleTransformationProof(res.get(), "propagated equalities via SMT", newRule, its);
            res.storeSubProof(subProof);
            res.set(newRule);
        }
    }
    return res;
}
