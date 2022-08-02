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
#include "../its/rule.hpp"
#include "../expr/rel.hpp"
#include "../util/relevantvariables.hpp"
#include "../util/farkas.hpp"
#include "../util/templates.hpp"
#include "../smt/smtfactory.hpp"

#include <variant>

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
            if ((a.toG().makeRhsZero().lhs() <= b.toG().makeRhsZero().lhs()).isTriviallyTrue()) {
                return true;
            }
        } else if (!a.isStrict() && a.isPoly()) {
            if ((a.toGt().makeRhsZero().lhs() <= b.toG().makeRhsZero().lhs()).isTriviallyTrue()) {
                return true;
            }
        } else if (b.isPoly()) {
            if ((a.toG().makeRhsZero().lhs() <= b.toGt().makeRhsZero().lhs()).isTriviallyTrue()) {
                return true;
            }
        }
    } else if (a.isEq()) {
        Expr aDiff = a.rhs() - a.lhs();
        Expr bLhs = b.toG().lhs() - b.toG().rhs();
        if (b.isStrict()) {
            return (aDiff < bLhs).isTriviallyTrue() || ((-aDiff) < bLhs).isTriviallyTrue();
        } else {
            return (aDiff <= bLhs).isTriviallyTrue() || ((-aDiff) <= bLhs).isTriviallyTrue();
        }
    }
    return false;
}

std::pair<option<Expr>, option<Expr>> GuardToolbox::getBoundFromIneq(const Rel &rel, const Var &N) {
    Rel l = rel.isPoly() ? rel.toLeq() : rel.toL();
    Expr term = (l.lhs() - l.rhs()).expand();
    if (term.degree(N) != 1) return {};

    // compute the upper bound represented by N and check that it is integral
    auto optSolved = GuardToolbox::solveTermFor(term, N, GuardToolbox::ResultMapsToInt);
    if (optSolved) {
        const Expr &coeff = term.coeff(N, 1);
        assert(coeff.isRationalConstant());
        if (coeff.toNum().is_negative()) {
            return {{l.isStrict() ? optSolved.get() + 1 : optSolved.get()}, {}};
        } else {
            return {{}, {l.isStrict() ? optSolved.get() - 1 : optSolved.get()}};
        }
    }
    return {};
}

option<Expr> GuardToolbox::solveTermFor(Expr term, const Var &var, SolvingLevel level) {
    // expand is needed before using degree/coeff
    term = term.expand();

    // we can only solve linear expressions...
    if (term.degree(var) != 1) return {};

    // ...with rational coefficients
    Expr c = term.coeff(var);
    if (!c.isRationalConstant()) return {};

    bool trivialCoeff = (c.compare(1) == 0 || c.compare(-1) == 0);

    if (level == TrivialCoeffs && !trivialCoeff) {
        return {};
    }

    term = (term - c*var) / (-c);

    // If c is trivial, we don't have to check if the result maps to int,
    // since we assume that all constraints in the guard map to int.
    // So if c is trivial, we can also handle non-polynomial terms.
    if (level == ResultMapsToInt && !trivialCoeff) {
        if (!term.isPoly() || !term.isIntegral()) return {};
    }

    // we assume that terms in the guard map to int, make sure this is the case
    if (trivialCoeff) {
        assert(!term.isPoly() || term.isIntegral());
    }

    return {term};
}


Result<Rule> GuardToolbox::propagateEqualities(const ITSProblem &its, const Rule &rule, SolvingLevel maxlevel, SymbolAcceptor allow) {
    Subs varSubs;
    Result<std::monostate> proof{std::monostate()};
    RelSet guard = rule.getGuard()->universallyValidLits();

    for (const auto &r: guard) {
        Rel rel = r.subs(varSubs);
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
            for (const Var &var : target.vars()) {
                if (!allow(var)) continue;

                //solve target for var (result is in target)
                auto optSolved = solveTermFor(target,var,(SolvingLevel)level);
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
                goto next;
            }
        }
        next:;
    }

    //apply substitution to the entire rule
    Result<Rule> res(rule);
    if (proof) {
        res = rule.subs(varSubs);
        res.ruleTransformationProof(rule, "propagated equalities", res.get(), its);
        res.storeSubProof(proof.getProof(), "propagated equalities");
    }
    return res;
}


Result<Rule> GuardToolbox::eliminateByTransitiveClosure(const Rule &rule, bool removeHalfBounds, SymbolAcceptor allow, const ITSProblem &its) {
    Result<Rule> res(rule);
    if (!rule.getGuard()->isConjunction()) {
        return res;
    }
    RelSet guard = rule.getGuard()->lits();
    //get all variables that appear in an inequality
    VarSet tryVars;
    for (const Rel &rel : guard) {
        if (!rel.isIneq() || !rel.isPoly()) continue;
        rel.collectVariables(tryVars);
    }

    //for each variable, try if we can eliminate every occurrence. Otherwise do nothing.
    bool changed = false;
    for (const Var &var : tryVars) {
        if (!allow(var)) continue;

        vector<Expr> varLessThan, varGreaterThan; //var <= expr and var >= expr
        vector<Rel> guardTerms; //indices of guard terms that can be removed if successful

        for (const Rel &rel: guard) {
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
                guard.insert(lower <= upper);
            }
        }
        changed = true;

abort:  ; //this symbol could not be eliminated, try the next one
    }
    if (changed) {
        res = rule.withGuard(buildAnd(guard));
        res.ruleTransformationProof(rule, "eliminated temporary variables via transitive closure", *res, its);
    }
    return res;
}


Result<Rule> GuardToolbox::makeEqualities(const Rule &rule, const ITSProblem &its) {
    Result<Rule> res(rule);
    const RelSet &guard = rule.getGuard()->universallyValidLits();
    vector<pair<Rel,Expr>> terms; //inequalities from the guard, with the associated index in guard
    map<Rel,pair<Rel,Expr>> matches; //maps index in guard to a second index in guard, which can be replaced by Expression

    // Find matching constraints "t1 <= 0" and "t2 <= 0" such that t1+t2 is zero
    for (const Rel &rel: guard) {
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

    if (matches.empty()) return res;

    // Construct the new guard by keeping unmatched constraint
    // and replacing matched pairs by an equality constraint.
    // This code below mostly retains the order of the constraints.
    Guard equalities;
    set<Rel> ignore;
    for (const Rel &rel: guard) {
        //ignore multiple equalities as well as the original second inequality
        if (ignore.count(rel) > 0) continue;

        auto it = matches.find(rel);
        if (it != matches.end()) {
            equalities.push_back(Rel::buildEq(it->second.second, 0));
            ignore.insert(it->second.first);
        }
    }
    if (!equalities.empty()) {
        const Rule newRule = rule.withGuard(rule.getGuard() & buildAnd(equalities));
        res.set(newRule);
        res.ruleTransformationProof(rule, "made implied equalities explicit", newRule, its);
    }
    return res;
}

Result<Rule> GuardToolbox::propagateEqualitiesBySmt(const Rule &rule, ITSProblem &its) {
    Result<Rule> res(rule);
    if (!rule.getGuard()->isLinear()) {
        return res;
    }
    VarSet tempVars = rule.getGuard()->vars();
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
    std::unique_ptr<Smt> solver = SmtFactory::modelBuildingSolver(Smt::QF_NA, its, Config::Smt::SimpTimeout);
    for (const Var &x: tempVars) {
        solver->resetSolver();
        VarSet relevantVars = util::RelevantVariables::find({x}, std::vector<Subs>(), rule.getGuard());
        relevantVars.erase(x);
        Templates::Template t = templates.buildTemplate(relevantVars, its);
        relevantVars.insert(x);
        const BoolExpr e = FarkasLemma::apply(rule.getGuard(), {Rel::buildEq(t.t, x)}, relevantVars, t.params, its);
        solver->add(e);
        if (solver->check() == Smt::Sat) {
            const Subs &m = solver->model().toSubs().project(t.params);
            const Rule newRule = res.get().subs({x, t.t.subs(m)});
            std::stringstream s;
            s << "propagated equalities via SMT: " << m;
            Proof subProof;
            subProof.append(s.str());
            res.ruleTransformationProof(res.get(), "propagated equalities via SMT", newRule, its);
            res.storeSubProof(subProof, "propagated equalities via SMT");
            res.set(newRule);
        }
    }
    return res;
}
