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

#include "recurrence.hpp"
#include "dependencyorder.hpp"
#include "inttheory.hpp"
#include "substitution.hpp"

#include <purrs.hh>

using namespace std;
namespace Purrs = Parma_Recurrence_Relation_Solver;

Recurrence::Recurrence(const Subs &equations):
    equations(equations) {}

bool Recurrence::solve(const NumVar &lhs, const Expr &rhs) {
    const auto n {Purrs::Expr(Purrs::Recurrence::n).toGiNaC()};
    const auto updated {rhs.subs(closed_form_pre.get<IntTheory>()).ex.subs(*result.n == n)};
    const auto &vars {rhs.vars()};
    unsigned prefix {0};
    GiNaC::ex closed_form;
    if (vars.find(lhs) == vars.end()) {
        prefix = 1;
        for (const auto &x: vars) {
            const auto it {prefixes.find(x)};
            if (it != prefixes.end() && it->second >= prefix) {
                prefix = it->second + 1;
            }
        }
        if (inverse) {
            const auto last {rhs.subs(*inverse)};
            result.refined_equations.put(lhs, lhs + rhs - last);
            inverse->put(lhs, lhs - rhs + last);
        }
        closed_form = updated;
    } else {
        const auto i {rhs.solveTermFor(lhs, ConstantCoeffs)};
        if (!i) {
            inverse = std::optional<ExprSubs>();
        } else {
            inverse->put(lhs, lhs + *i);
        }
        result.refined_equations.put(lhs, rhs);
        auto last {Purrs::x(Purrs::Recurrence::n - 1).toGiNaC()};
        Purrs::Recurrence rec {Purrs::Expr::fromGiNaC(updated.subs({{*lhs, last}}))};
        auto status {Purrs::Recurrence::Solver_Status::TOO_COMPLEX};
        try {
            rec.set_initial_conditions({ {0, Purrs::Expr::fromGiNaC(*lhs)} });
            status = rec.compute_exact_solution();
        } catch (...) {
            //purrs throws a runtime exception if the recurrence is too difficult
            return false;
        }
        if (status == Purrs::Recurrence::SUCCESS) {
            Purrs::Expr exact;
            rec.exact_solution(exact);
            closed_form = exact.toGiNaC();
        } else {
            return false;
        }
    }
    prefixes.emplace(lhs, prefix);
    result.prefix = std::max(result.prefix, prefix);
    closed_form_pre.put<IntTheory>(lhs, closed_form.subs(n == *result.n-1));
    result.closed_form.put<IntTheory>(lhs, closed_form.subs(n == *result.n));
    return true;
}

bool Recurrence::solve(const BoolVar &lhs, const BoolExpr &rhs) {
    const auto updated {rhs->subs(closed_form_pre)};
    const auto &vars {updated->vars()};
    if (vars.find(lhs) != vars.end() && vars.size() != vars.get<BoolVar>().size()) {
        return false;
    }
    unsigned prefix {1};
    for (const auto &x: vars) {
        const auto it {prefixes.find(x)};
        if (it != prefixes.end() && it->second >= prefix) {
            prefix = it->second + 1;
        }
    }
    prefixes.emplace(lhs, prefix);
    result.prefix = std::max(result.prefix, prefix);
    closed_form_pre.put<BoolTheory>(lhs, updated);
    result.closed_form.put<BoolTheory>(lhs, updated);
    return true;
}

Recurrence::Result::Result(): n(NumVar::next()) {}

bool Recurrence::solve() {
    const auto order {DependencyOrder::findOrder(equations)};
    if (!order) {
        return false;
    }
    for (const auto &lhs : *order) {
        const auto success {
            std::visit(
                        Overload{
                            [&](const NumVar &lhs) {
                                return solve(lhs, equations.get<IntTheory>(lhs));
                            },
                            [&](const BoolVar &lhs) {
                                return solve(lhs, equations.get<BoolTheory>(lhs));
                            }
                        }, lhs)
        };
        if (!success) {
            return false;
        }
    }
    const auto subs {Subs::build<IntTheory>(NumVar(0), result.n)};
    result.closed_form = substitution::concat(result.closed_form, subs);
    return true;
}


std::optional<Recurrence::Result> Recurrence::solve(const Subs &update) {
    Recurrence rec {update};
    if (rec.solve()) {
        return rec.result;
    } else {
        return {};
    }
}
