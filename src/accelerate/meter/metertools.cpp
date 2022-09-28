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

#include "metertools.hpp"

#include "guardtoolbox.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "boolexpr.hpp"

using namespace std;


/* ### Helpers ### */

std::vector<ExprSubs> MeteringToolbox::applySubsToUpdates(const ExprSubs &subs, const MultiUpdate &updates) {
    MultiUpdate res;
    for (const auto &update : updates) {
        res.push_back(update.concat(subs));
    }
    return res;
}


bool MeteringToolbox::isUpdatedByAny(Var var, const MultiUpdate &updates) {
    auto updatesVar = [&](const auto &update) { return update.changes(var); };
    return std::any_of(updates.begin(), updates.end(), updatesVar);
}


/* ### Preprocessing ### */

Guard MeteringToolbox::replaceEqualities(const Guard &guard) {
    Guard newGuard;

    for (const Rel &rel : guard) {
        if (rel.isEq()) {
            newGuard.push_back(rel.lhs() <= rel.rhs());
            newGuard.push_back(rel.lhs() >= rel.rhs());
        } else {
            newGuard.push_back(rel);
        }
    }

    return newGuard;
}


/* ### Filter relevant constarints/variables ### */

Guard MeteringToolbox::reduceGuard(VarMan &varMan, const Guard &guard, const MultiUpdate &updates, Guard *irrelevantGuard)
{
    assert(!irrelevantGuard || irrelevantGuard->empty());
    Guard reducedGuard;

    // Collect all updated variables (updated by any of the updates)
    VarSet updatedVars;
    for (const auto &update : updates) {
        const auto dom = update.domain();
        updatedVars.insert(dom.begin(), dom.end());
    }
    auto isUpdated = [&](const Var &var){ return updatedVars.count(var) > 0; };

    // create Z3 solver with the guard here to use push/pop for efficiency
    unique_ptr<Smt> solver = SmtFactory::solver(Smt::chooseLogic<std::vector<Rel>>({guard}, updates), varMan);
    for (const Rel &rel : guard) {
        solver->add(rel);
    }

    for (const Rel &rel : guard) {
        // only keep constraints that contain updated variables (otherwise they still hold after the update)
        bool add = rel.hasVarWith(isUpdated);

        // and only if they are not implied after each update (so they may cause the loop to terminate)
        if (add) {
            bool implied = true;
            for (const auto &update : updates) {
                solver->push();
                solver->add(!buildTheoryLit(rel.subs(update)));
                auto smtRes = solver->check();
                solver->pop();

                // unsat means that the updated `ex` must always hold (i.e., is implied after the update)
                if (smtRes != Smt::Unsat) {
                    implied = false;
                    break;
                }
            }

            if (implied) {
                add = false;
            }
        }

        // add the constraint, or remember it as being irrelevant
        if (add) {
            reducedGuard.push_back(rel);
        } else {
            if (irrelevantGuard) irrelevantGuard->push_back(rel);
        }
    }

    return reducedGuard;
}


VarSet MeteringToolbox::findRelevantVariables(const Guard &guard, const MultiUpdate &updates) {
    VarSet res;

    // Add all variables appearing in the guard
    VarSet guardVariables;
    for (const Rel &rel : guard) {
        rel.collectVariables(guardVariables);
    }
    for (const Var &sym : guardVariables) {
        res.insert(sym);
    }

    // Compute the closure of res under ALL updates
    // so if an updated variable is in res, also add all variables of the update's rhs
    VarSet todo = res;
    while (!todo.empty()) {
        VarSet next;

        for (Var var : todo) {
            for (const auto &update: updates) {
                auto it = update.find(var);
                if (it != update.end()) {
                    VarSet rhsVars = it->second.vars();
                    next.insert(rhsVars.begin(), rhsVars.end());
                }
            }
        }

        todo.clear();
        for (const Var &var : next) {
            if (res.count(var) == 0) {
                todo.insert(var);
            }
        }

        // collect all variables from every iteration
        res.insert(todo.begin(), todo.end());
    }

    return res;
}


void MeteringToolbox::restrictUpdatesToVariables(MultiUpdate &updates, const VarSet &vars) {
    for (auto &update : updates) {
        VarSet toRemove;

        for (auto it : update) {
            if (vars.count(it.first) == 0) {
                toRemove.insert(it.first);
            }
        }

        for (Var var : toRemove) {
            update.erase(var);
        }
    }
}


void MeteringToolbox::restrictGuardToVariables(Guard &guard, const VarSet &vars) {
    auto isContainedInVars = [&](const Var &sym) {
        return vars.count(sym) > 0;
    };

    auto containsNoVars = [&](const Rel &rel) {
        VarSet syms = rel.vars();
        return !std::any_of(syms.begin(), syms.end(), isContainedInVars);
    };

    // remove constraints not containing relevant variables (vars)
    guard.erase(std::remove_if(guard.begin(), guard.end(), containsNoVars), guard.end());
}


/* ### Heuristics to improve metering results ### */

option<Guard> MeteringToolbox::strengthenGuard(VarMan &varMan, const Guard &guard, const MultiUpdate &updates) {
    bool changed = false;
    Guard res(guard);

    // first remove irrelevant constraints from the guard
    Guard reducedGuard = reduceGuard(varMan, res, updates);
    VarSet relevantVars = findRelevantVariables(reducedGuard, updates);

    // consider each update independently of the others
    for (const auto &update : updates) {
        // helper lambda to pass as argument
        auto isUpdated = [&](const Var &sym){ return update.changes(sym); };

        for (const auto &it : update) {
            // only consider relevant variables
            if (relevantVars.count(it.first) == 0) continue;

            // only proceed if the update's rhs contains no updated variables
            VarSet rhsVars = it.second.vars();
            if (std::any_of(rhsVars.begin(), rhsVars.end(), isUpdated)) continue;

            // for every constraint containing it.first,
            // add a new constraint with it.first replaced by the update's rhs
            // (e.g. if x := 4 and the guard is x > 0, we also add 4 > 0)
            // (this makes the guard stronger and might thus help to find a metering function)
            Var lhsVar = it.first;

            Subs subs;
            subs.put(lhsVar, it.second);

            for (const Rel &rel : reducedGuard) {
                if (rel.has(lhsVar)) {

                    // We want to make sure that all constraints with lhsVar hold after the update.
                    // E.g. if x := 4, y := y+1 and the guard is x > y, we add 4 > y+1.
                    // Note that only updating x (i.e., adding 4 > y) might not be sufficient.
                    Rel add = rel.subs(update);

                    // Adding trivial constraints does not make sense (no matter if they are true/false).
                    if (!add.isTriviallyTrue() && !add.isTriviallyFalse()) {
                        res.push_back(add);
                        changed = true;
                    }
                }
            }
        }
    }
    return changed ? option<Guard>(res) : option<Guard>();
}


stack<ExprSubs> MeteringToolbox::findInstantiationsForTempVars(const VarMan &varMan, const Guard &guard) {
    //find free variables
    const VarSet &freeVar = varMan.getTempVars();
    if (freeVar.empty()) return stack<ExprSubs>();

    //find all bounds for every free variable
    VarMap<ExprSet> freeBounds;
    for (const Rel &rel : guard) {
        for (Var free : freeVar) {
            if (!rel.has(free)) continue;
            std::pair<option<Expr>, option<Expr>> bounds = GuardToolbox::getBoundFromIneq(rel, free);
            if (bounds.first) {
                freeBounds[free].insert(bounds.first.get());
            }
            if (bounds.second) {
                freeBounds[free].insert(bounds.second.get());
            }

        }
    }

    //check if there are any bounds at all
    if (freeBounds.empty()) return stack<ExprSubs>();

    //combine all bounds in all possible ways
    stack<ExprSubs> allSubs;
    allSubs.push(ExprSubs());
    for (auto const &it : freeBounds) {
        Var sym = it.first;
        for (const Expr &bound : it.second) {
            stack<ExprSubs> next;
            while (!allSubs.empty()) {
                ExprSubs subs = allSubs.top();
                allSubs.pop();
                if (subs.contains(sym)) {
                    //keep old bound, add a new substitution for the new bound
                    ExprSubs newsubs = subs;
                    newsubs.put(sym, bound);
                    next.push(subs);
                    next.push(newsubs);
                } else {
                    subs.put(sym, bound);
                    next.push(subs);
                }
            }
            allSubs.swap(next);
        }
    }
    return allSubs;
}
