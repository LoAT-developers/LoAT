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

#include "metering.hpp"

#include "farkas.hpp"
#include "metertools.hpp"

#include "guardtoolbox.hpp"
#include "expression.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "boolexpr.hpp"

#include <boost/integer/common_factor.hpp> // for lcm

using namespace std;
namespace MT = MeteringToolbox;


MeteringFinder::MeteringFinder(VarMan &varMan, const Guard &guard, const vector<ExprSubs> &updates)
    : varMan(varMan),
      updates(updates),
      guard(guard),
      absCoeff(varMan.getFreshUntrackedSymbol("c", Expr::Rational))
{}


/* ### Helpers ### */

vector<ExprSubs> MeteringFinder::getUpdateList(const Rule &rule) {
    vector<ExprSubs> res;
    res.reserve(rule.rhsCount());
    for (auto rhs = rule.rhsBegin(); rhs != rule.rhsEnd(); ++rhs) {
        res.push_back(rhs->getUpdate().getExprSubs());
    }
    return res;
}


/* ### Step 1: Pre-processing, filter relevant constraints/variables ### */

void MeteringFinder::simplifyAndFindVariables() {
    irrelevantGuard.clear(); // clear in case this method is called twice
    reducedGuard = MT::reduceGuard(varMan, guard, updates, &irrelevantGuard);
    relevantVars = MT::findRelevantVariables(reducedGuard, updates);

    // Note that reducedGuard is already restricted by definition of relevantVars
    MT::restrictGuardToVariables(guard, relevantVars);
    MT::restrictGuardToVariables(irrelevantGuard, relevantVars);
    MT::restrictUpdatesToVariables(updates, relevantVars);
}

void MeteringFinder::preprocess() {
    // simplify guard/update
    guard = MT::replaceEqualities(guard);
    simplifyAndFindVariables();
}


/* ### Step 2: Construction of linear constraints and metering function template ### */

void MeteringFinder::buildMeteringVariables() {
    // clear generated fields in case this method is called twice
    meterVars.symbols.clear();
    meterVars.coeffs.clear();
    meterVars.primedSymbols.clear();

    for (const Var &var : relevantVars) {
        meterVars.symbols.push_back(var);
        meterVars.coeffs.push_back(varMan.getFreshUntrackedSymbol("c", Expr::Rational));
    }

    for (const ExprSubs &update : updates) {
        for (const auto &it : update) {
            assert(relevantVars.count(it.first) > 0); // update should have been restricted to relevant variables

            if (meterVars.primedSymbols.count(it.first) == 0) {
                string primedName = it.first.get_name() + "'";
                Var primed = varMan.getFreshUntrackedSymbol(primedName, Expr::Int);
                meterVars.primedSymbols.emplace(it.first, primed);
            }
        }
    }
}

void MeteringFinder::buildLinearConstraints() {
    // clear generated fields in case this method is called twice
    linearConstraints.guard.clear();
    linearConstraints.guardUpdate.clear();
    linearConstraints.reducedGuard.clear();
    linearConstraints.reducedGuard.clear();

    // guardUpdate will consist of as many constraint lists as there are updates
    linearConstraints.guardUpdate.resize(updates.size());

    // helper lambda to transform the given inequality into the required form
    auto makeConstraint = [&](const Rel &rel, RelSet &s) {
        assert(rel.isLinear() && rel.isIneq());

        Rel res = rel.toLeq().splitVariableAndConstantAddends();
        if (!res.isTriviallyTrue()) {
            s.insert(res);
        }
    };

    for (Rel rel : reducedGuard) {
        makeConstraint(rel, linearConstraints.reducedGuard);
    }

    for (Rel rel : irrelevantGuard) {
        makeConstraint(rel, linearConstraints.irrelevantGuard);
    }

    for (Rel rel : guard) {
        makeConstraint(rel, linearConstraints.guard);

        // all of the guardUpdate constraints need to include the guard
        for (RelSet &s : linearConstraints.guardUpdate) {
            makeConstraint(rel, s);
        }
    }

    for (unsigned int i=0; i < updates.size(); ++i) {
        for (const auto &it : updates[i]) {
            assert(meterVars.primedSymbols.count(it.first) > 0);
            Var primed = meterVars.primedSymbols.at(it.first);

            makeConstraint(primed <= it.second, linearConstraints.guardUpdate[i]);
            makeConstraint(primed >= it.second, linearConstraints.guardUpdate[i]);
        }
    }

}


/* ### Step 3: Construction of the final constraints for the metering function using Farkas lemma ### */

BoolExpr MeteringFinder::genNotGuardImplication() const {
    std::vector<BoolExpr> res;
    RelSet lhs = linearConstraints.irrelevantGuard;

    // split into one implication for every guard constraint, apply Farkas for each implication
    for (const Rel &rel : linearConstraints.reducedGuard) {
        const Rel &conclusion = (!rel).toLeq().splitVariableAndConstantAddends();
        lhs.insert(conclusion);
        res.push_back(FarkasLemma::apply(lhs, meterVars.symbols, meterVars.coeffs, absCoeff, 0, varMan));
        lhs.erase(conclusion);
    }

    return buildAnd(res);
}

BoolExpr MeteringFinder::genGuardPositiveImplication(bool strict) const {
    //G ==> f(x) > 0, which is equivalent to -f(x) < 0  ==  -f(x) <= -1 (on integers)
    vector<Expr> negCoeff;
    for (const Var &coeff : meterVars.coeffs) {
        negCoeff.push_back(-coeff);
    }

    int delta = strict ? -1 : -0;
    return FarkasLemma::apply(linearConstraints.guard, meterVars.symbols, negCoeff, -absCoeff, delta, varMan);
}

BoolExpr MeteringFinder::genUpdateImplications() const {
    // For each update, build f(x)-f(x') => x-x'
    // Note that we only include the (primed) variables actually affected by the update.
    // The other variables can be left out to simplify the z3 query (since they cancel out)

    BoolExpr res = True;
    for (unsigned int updateIdx=0; updateIdx < updates.size(); ++updateIdx) {
        vector<Var> vars;
        vector<Expr> coeffs;

        for (unsigned int i=0; i < meterVars.symbols.size(); ++i) {
            Var var = meterVars.symbols[i];
            Expr coeff = meterVars.coeffs[i];

            // ignore variables not affected by the current update
            if (!updates[updateIdx].changes(var)) continue;

            // find the primed version of sym
            assert(meterVars.primedSymbols.count(var) > 0);
            Var primed = meterVars.primedSymbols.at(var);

            vars.push_back(var);      //x
            vars.push_back(primed);   //x'
            coeffs.push_back( coeff); //coeff for x
            coeffs.push_back(-coeff); //coeff for x', i.e. negative coeff for x
        }

        // the absolute coefficient also cancels out, so we set it to 0
        Expr zeroAbsCoeff = 0;
        res = res & FarkasLemma::apply(linearConstraints.guardUpdate[updateIdx], vars, coeffs, zeroAbsCoeff, 1, varMan);
    }

    return res;
}

BoolExpr MeteringFinder::genNonTrivial() const {
    std::vector<Rel> res;
    for (const Var &c : meterVars.coeffs) {
        res.push_back(Rel::buildNeq(c, 0));
    }
    return buildOr(res);
}


/* ### Step 4: Result and model interpretation ### */

Expr MeteringFinder::buildResult(const Model &model) const {
    const auto &coeffs = meterVars.coeffs;
    const auto &symbols = meterVars.symbols;

    // read off the coefficients of the metering function
    Expr result = model.get(absCoeff);
    for (unsigned int i=0; i < coeffs.size(); ++i) {
        result = result + model.get(coeffs[i]) * symbols[i];
    }
    return result;
}

void MeteringFinder::ensureIntegralMetering(Result &result, const Model &model) const {
    bool has_reals = false;
    int mult = 1;

    for (const Var &theCoeff : meterVars.coeffs) {
        Num coeff = model.get(theCoeff);
        if (coeff.denom().to_int() != 1) {
            has_reals = true;
            mult = boost::integer::lcm(mult, coeff.denom().to_int());
        }
    }

    // remove reals by multiplying metering function with "mult",
    // then add a fresh variable that corresponds to the original value of the metering function
    if (has_reals) {
        Var tempVar = varMan.addFreshTemporaryVariable("meter");

        // create a new guard constraint relating tempVar and the metering function
        result.integralConstraint = Rel::buildEq(tempVar*mult, result.metering*mult);

        // replace the metering function by tempVar
        result.metering = tempVar;
    }
}


bool MeteringFinder::isLinear() const {
    return reducedGuard.isLinear() && std::all_of(updates.begin(), updates.end(), [](const auto &up) {
       return up.isLinear();
    });
}

/* ### Main function ### */
MeteringFinder::Result MeteringFinder::generate(VarMan &varMan, const Rule &rule) {
    Result result;
    if (!rule.getGuard()->isConjunction()) {
        return result;
    }

    MeteringFinder meter(varMan, rule.getGuard()->conjunctionToGuard(), getUpdateList(rule));

    // linearize and simplify the problem
    meter.preprocess();
    if (!meter.isLinear()) {
        result.result = Nonlinear;
        return result;
    }

    // identify trivially non-terminating loops (no guard constraint is limiting the loop's execution)
    if (meter.reducedGuard.empty()) {
        result.result = Nonterm;
        return result;
    }

    // create constraints for the metering function template
    meter.buildMeteringVariables();
    meter.buildLinearConstraints();

    // solve constraints for the metering function (without the "GuardPositiveImplication" for now)
    std::unique_ptr<Smt> solver = SmtFactory::modelBuildingSolver(Smt::QF_LA, varMan, Config::Smt::MeterTimeout);
    solver->add(meter.genNotGuardImplication());
    solver->add(meter.genUpdateImplications());
    solver->add(meter.genNonTrivial());
    Smt::Result smtRes = solver->check();

    // the problem is already unsat (even without "GuardPositiveImplication")
    if (smtRes == Smt::Unsat) {
        result.result = Unsat;
        return result;
    }

    // Add the "GuardPositiveImplication" to the party (first the strict version)
    solver->push();
    solver->add(meter.genGuardPositiveImplication(true));
    smtRes = solver->check();

    // If we fail, try the relaxed version instead (f(x) >= 0 instead of f(x) > 0)
    if (smtRes != Smt::Sat) {
        solver->pop();
        solver->add(meter.genGuardPositiveImplication(false));
        smtRes = solver->check();
    }

    // If we still fail, we have to give up
    if (smtRes != Smt::Sat) {
        result.result = Unsat;
        return result;
    }

    // If we succeed, extract the metering function from the model
    Model model = solver->model();
    result.metering = meter.buildResult(model);
    result.result = Success;

    // If we allow real coefficients, we have to be careful that the metering function evaluates to an integer.
    meter.ensureIntegralMetering(result, model);

    return result;
}



/* ### Heuristics to help finding more metering functions ### */

option<Rule> MeteringFinder::strengthenGuard(VarMan &varMan, const Rule &rule) {
    if (!rule.getGuard()->isConjunction()) {
        return {};
    }
    option<Guard> guard = MT::strengthenGuard(varMan, rule.getGuard()->conjunctionToGuard(), getUpdateList(rule));
    return guard ? option<Rule>(rule.withGuard(buildAnd(guard.get()))) : option<Rule>();
}

option<pair<Rule, Proof>> MeteringFinder::instantiateTempVarsHeuristic(ITSProblem &its, const Rule &rule) {
    if (!rule.getGuard()->isConjunction()) {
        return {};
    }
    // Quick check whether there are any bounds on temp vars we can use to instantiate them.
    auto hasTempVar = [&](const Rel &rel) { return GuardToolbox::containsTempVar(its, rel); };
    const RelSet &lits = rule.getGuard()->lits();
    if (std::none_of(lits.begin(), lits.end(), hasTempVar)) {
        return {};
    }

    // We first perform the same steps as in generate()
    MeteringFinder meter(its, rule.getGuard()->conjunctionToGuard(), getUpdateList(rule));

    meter.preprocess();
    if (!meter.isLinear()) return {};
    assert(!meter.reducedGuard.empty()); // this method must only be called if generate() fails

    meter.buildMeteringVariables();
    meter.buildLinearConstraints();

    std::unique_ptr<Smt> solver = SmtFactory::solver(Smt::QF_LA, its, Config::Smt::MeterTimeout);
    Smt::Result smtRes = Smt::Result::Unsat; // this method should only be called if generate() fails

    Guard oldGuard = meter.guard;
    vector<ExprSubs> oldUpdates = meter.updates;

    // Now try all possible instantiations until the solver is satisfied

    ExprSubs successfulSubs;
    stack<ExprSubs> freeSubs = MT::findInstantiationsForTempVars(its, meter.guard);

    while (!freeSubs.empty()) {
        const ExprSubs &sub = freeSubs.top();

        //apply current substitution (and forget the previous one)
        meter.guard = oldGuard; // copy
        for (Rel &rel : meter.guard) rel.applySubs(sub);

        meter.updates = MT::applySubsToUpdates(sub, oldUpdates); // copy

        // Perform the first steps from generate() again (guard/update have changed)
        meter.simplifyAndFindVariables();
        meter.buildMeteringVariables();
        meter.buildLinearConstraints();

        solver->resetSolver();
        solver->add(meter.genNotGuardImplication());
        solver->add(meter.genUpdateImplications());
        solver->add(meter.genNonTrivial());
        solver->add(meter.genGuardPositiveImplication(false));
        smtRes = solver->check();

        if (smtRes == Smt::Sat) {
            successfulSubs = sub;
            break;
        }

        freeSubs.pop();
    }

    // If we found a successful instantiation, z3res is sat
    if (smtRes != Smt::Sat) {
        return {};
    }

    // Apply the successful instantiation to the entire rule
    Rule instantiatedRule = rule.subs(successfulSubs);

    // Proof output
    Proof proof;
    proof.ruleTransformationProof(rule, "instantiation", instantiatedRule, its);

    return {{instantiatedRule, proof}};
}
