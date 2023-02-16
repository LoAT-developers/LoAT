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

#pragma once

#include <map>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "types.hpp"
#include "theory.hpp"
#include "config.hpp"
#include "substitution.hpp"


class RuleLhs {
    LocationIdx loc;
    BoolExpr guard;
    Expr cost;

public:
    RuleLhs(LocationIdx loc, BoolExpr guard) : RuleLhs(loc, guard, 1) {}
    RuleLhs(LocationIdx loc, BoolExpr guard, Expr cost) :
        loc(loc),
        guard(guard),
        cost(Config::Analysis::complexity()
             ? cost
             : (Config::Analysis::nonTermination()
                ? (cost.isNontermSymbol() ? cost : 1)
                : 1)) {}

    LocationIdx getLoc() const { return loc; }
    const BoolExpr& getGuard() const { return guard; }
    const Expr& getCost() const { return cost; }

    void collectVars(VarSet &vars) const {
        guard->collectVars(vars);
        cost.collectVars(vars.get<NumVar>());
    }

    unsigned hash() const {
        unsigned hash = 7;
        hash = hash * 31 + loc;
        hash = hash * 31 + guard->hash();
        hash = hash * 31 + cost.hash();
        return hash;
    }

};


class RuleRhs {
    LocationIdx loc;
    Subs update;

public:
    RuleRhs(LocationIdx loc, Subs update) : loc(loc), update(update) {}

    LocationIdx getLoc() const { return loc; }
    const Subs& getUpdate() const { return update; }

    void collectVars(VarSet &vars) const {
        substitution::collectVars(update, vars);
    }

    size_t hash() const {
        size_t hash = 7;
        hash = hash * 31 + loc;
        hash = hash * 31 + update.hash();
        return hash;
    }

};

bool operator ==(const RuleRhs &fst, const RuleRhs &snd);

/**
 * A general rule, consisting of a left-hand side with location, guard and cost
 * and several (but at least one) right-hand sides, each with location and update.
 *
 * The lhs/rhs locations must not (and cannot) be changed, as they are tied to the graph in ITSProblem.
 * The content of the rule (guard/cost/update) may be modified (e.g. via getGuardMut()).
 */
class Rule {
private:
    RuleLhs lhs;
    RuleRhs rhs;

public:
    Rule(RuleLhs lhs, RuleRhs rhs);
    Rule(LocationIdx lhsLoc, BoolExpr guard, Expr cost, LocationIdx rhsLoc, Subs update);

    // constructs an empty rule (guard/update empty, cost 0)
    static Rule dummyRule(LocationIdx lhsLoc, LocationIdx rhsLoc);
    bool isDummyRule() const;

    const RuleLhs& getLhs() const { return lhs; }
    const RuleRhs& getRhs() const { return rhs; }

    // query lhs data
    LocationIdx getLhsLoc() const { return lhs.getLoc(); }
    const BoolExpr& getGuard() const { return lhs.getGuard(); }
    const Expr& getCost() const { return lhs.getCost(); }

    // special methods for nonlinear rules (idx is an index to rhss)
    LocationIdx getRhsLoc() const { return rhs.getLoc(); }
    const Subs& getUpdate() const { return rhs.getUpdate(); }

    // checks if lhs location coincides with _all_ rhs locations
    bool isSimpleLoop() const;

    // applies the given substitution to guard, cost, and the update's rhss (not to the update's lhss!)
    // Note: Result may be incorrect if an updated variable is updated (which is not checked!)
    // Note: It is always safe if only temporary variables are substituted.
    Rule subs(const Subs &subs) const;

    // Creates a new rule that only leads to the given location, the updates are cleared, guard/cost are kept
    Rule replaceRhsBySink(LocationIdx sink) const;

    Rule withGuard(const BoolExpr guard) const;
    Rule withCost(const Expr &cost) const;
    Rule withUpdate(const Subs &up) const;

    VarSet vars() const;
    void collectVars(VarSet &vars) const;

    unsigned hash() const;

    struct Hash {
        std::size_t operator()(const Rule& r) const {
            return r.hash();
        }
    };

};

/**
 * For debugging output (not very readable)
 */
std::ostream& operator<<(std::ostream &s, const Rule &rule);
