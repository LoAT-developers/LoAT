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

#include "farkas.hpp"

#include "variablemanager.hpp"
#include "inttheory.hpp"

using namespace std;


BExpr<IntTheory> FarkasLemma::apply(
        const RelSet &constraints,
        const vector<NumVar> &vars,
        const vector<Expr> &coeffs,
        Expr c0,
        int delta,
        VariableManager &varMan,
        const std::set<NumVar> &params)
{
    assert(vars.size() == coeffs.size());

    // List of expressions whose conjunction will be the result
    std::vector<Theory<IntTheory>::Lit> res;

    // Create lambda variables, add the constraint "lambda >= 0"
    RelMap<NumVar> lambda;
    std::set<NumVar> varSet(vars.begin(), vars.end());
    for (const Rel &rel : constraints) {
        const Rel &normalizedRel = rel.toLeq();
        assert(normalizedRel.isLinear(varSet) && normalizedRel.isIneq());
        NumVar var = varMan.getFreshUntrackedSymbol<IntTheory>("l", Expr::Rational);
        lambda[normalizedRel] = var;
        res.push_back(var >= 0);
    }

    // Create mapping from every variable to its coefficient
    std::map<NumVar, Expr> varToCoeff;
    for (unsigned int i=0; i < vars.size(); ++i) {
        varToCoeff.emplace(vars[i], coeffs[i]);
    }

    // Search for additional variables that are not contained in vars, but appear in constraints.
    // This is neccessary, since these variables appear in the A*x part and thus also have to appear in the c*x part.
    // The coefficients of additional variables are simply set to 0 (so they won't occur in the metering function).
    std::set<NumVar> constraintSymbols;
    for (const Rel &rel : constraints) {
        rel.collectVariables(constraintSymbols);
    }
    for (const auto &sym : constraintSymbols) {
        if (varToCoeff.find(sym) == varToCoeff.end() && std::find(params.begin(), params.end(), sym) == params.end()) {
            varToCoeff.emplace(sym, 0);
        }
    }

    // Build the constraints "lambda^T * A = c^T"
    for (auto varIt : varToCoeff) {
        Expr lambdaA = 0;
        bool first = true;
        for (const auto &e: lambda) {
            Expr a = e.first.lhs().expand().coeff(varIt.first);
            Expr add = e.second * a;
            lambdaA = first ? add : lambdaA + add; // avoid superflous +0
            first = false;
        }
        res.push_back(Rel::buildEq(lambdaA, varIt.second));
    }

    // Build the constraints "lambda^T * b + c0 <= delta"
    Expr sum = c0;
    for (const auto &e: lambda) {
        sum = sum + e.second * e.first.rhs();
    }
    res.push_back(sum <= delta);
    return buildAnd<IntTheory>(res);
}

BExpr<IntTheory> FarkasLemma::apply(
        const RelSet &constraints,
        const vector<NumVar> &vars,
        const vector<NumVar> &coeffs,
        NumVar c0,
        int delta,
        VariableManager &varMan,
        const std::set<NumVar> &params)
{
    std::vector<Expr> theCoeffs;
    for (const NumVar &x: coeffs) {
        theCoeffs.push_back(x);
    }
    return apply(constraints, vars, theCoeffs, c0, delta, varMan, params);
}

const BExpr<IntTheory> FarkasLemma::apply(
        const BExpr<IntTheory> premise,
        const RelSet &conclusion,
        const std::set<NumVar> &vars,
        const std::set<NumVar> &params,
        VariableManager &varMan) {
    vector<NumVar> varList(vars.begin(), vars.end());
    RelSet splitConclusion;
    for (const Rel &c: conclusion) {
        if (c.isLinear(vars) && c.isIneq()) {
            splitConclusion.insert(c.toLeq().splitVariableAndConstantAddends(params));
        } else if (c.isLinear(vars) && c.isEq()) {
            splitConclusion.insert((c.lhs() <= c.rhs()).splitVariableAndConstantAddends(params));
            splitConclusion.insert((c.rhs() <= c.lhs()).splitVariableAndConstantAddends(params));
        } else {
            assert(false);
        }
    }
    return applyRec(premise, splitConclusion, varList, params, varMan);
}

const BExpr<IntTheory> FarkasLemma::applyRec(
        const BExpr<IntTheory> premise,
        const RelSet &conclusion,
        const std::vector<NumVar> &vars,
        const std::set<NumVar> &params,
        VariableManager &varMan) {
    std::vector<BExpr<IntTheory>> res;
    if (premise->isConjunction()) {
        for (const Rel &c: conclusion) {
            vector<Expr> coefficients;
            for (const auto &x : vars) {
                coefficients.push_back(c.lhs().coeff(x, 1));
            }
            Expr c0 = -c.rhs();
            RelSet lits;
            for (const auto &lit: premise->lits()) {
                if (std::holds_alternative<Rel>(lit)) {
                    const Rel &rel = std::get<Rel>(lit);
                    if (rel.isEq()) {
                        lits.insert((rel.lhs() <= rel.rhs()).splitVariableAndConstantAddends(params));
                        lits.insert((rel.lhs() >= rel.rhs()).splitVariableAndConstantAddends(params));
                    } else {
                        lits.insert(rel.toLeq().splitVariableAndConstantAddends(params));
                    }
                } else {
                    throw IllegalStateError("farkas only supports integer variables");
                }
            }
            res.push_back(FarkasLemma::apply(lits, vars, coefficients, c0, 0, varMan, params));
        }
        return buildAnd(res);
    } else {
        BoolExpressionSet<IntTheory> children;
        if (premise->isOr()) {
            children = premise->getChildren();
        } else {
            BoolExpressionSet<IntTheory> conj;
            for (const auto &c: premise->getChildren()) {
                if (c->isOr()) {
                    children.insert(c);
                } else {
                    conj.insert(c);
                }
            }
            if (!conj.empty()) {
                children.insert(buildAnd(conj));
            }
        }
        for (const auto &c: children) {
            res.push_back(applyRec(c, conclusion, vars, params, varMan));
        }
        return premise->isAnd() ? buildOr(res) : buildAnd(res);
    }
}
