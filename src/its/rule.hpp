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
#include "option.hpp"
#include "boolexpr.hpp"
#include "config.hpp"
#include "subs.hpp"


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
        cost.collectVars(vars);
    }

    void collectVars(BoolVarSet &vars) const {
        guard->collectVars(vars);
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
        update.collectVars(vars);
    }

    void collectVars(BoolVarSet &vars) const {
        update.collectVars(vars);
    }

    unsigned hash() const {
        unsigned hash = 7;
        hash = hash * 31 + loc;
        hash = hash * 31 + update.hash();
        return hash;
    }

};

bool operator ==(const RuleRhs &fst, const RuleRhs &snd);

class LinearRule;

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
    std::vector<RuleRhs> rhss;

public:
    Rule(RuleLhs lhs, std::vector<RuleRhs> rhss);

    // constructors for linear rules
    Rule(RuleLhs lhs, RuleRhs rhs);
    Rule(LocationIdx lhsLoc, BoolExpr guard, Expr cost, LocationIdx rhsLoc, Subs update);

    // constructs an empty rule (guard/update empty, cost 0)
    static LinearRule dummyRule(LocationIdx lhsLoc, LocationIdx rhsLoc);
    bool isDummyRule() const;

    const RuleLhs& getLhs() const { return lhs; }
    const std::vector<RuleRhs>& getRhss() const { return rhss; }

    // query lhs data
    LocationIdx getLhsLoc() const { return lhs.getLoc(); }
    const BoolExpr& getGuard() const { return lhs.getGuard(); }
    const Expr& getCost() const { return lhs.getCost(); }

    // iteration over right-hand sides
    const RuleRhs* rhsBegin() const { return &rhss.front(); }
    const RuleRhs* rhsEnd() const { return &rhss.back()+1; }
    RuleRhs* rhsBegin() { return &rhss.front(); }
    RuleRhs* rhsEnd() { return &rhss.back()+1; }
    size_t rhsCount() const { return rhss.size(); }

    // special methods for nonlinear rules (idx is an index to rhss)
    LocationIdx getRhsLoc(unsigned int idx) const { return rhss[idx].getLoc(); }
    const std::vector<Subs> getUpdates() const {
        std::vector<Subs> res;
        for (const RuleRhs &rhs: rhss) {
            res.push_back(rhs.getUpdate());
        }
        return res;
    }
    const Subs& getUpdate(unsigned int idx) const { return rhss[idx].getUpdate(); }

    // conversion to linear rule
    bool isLinear() const;
    LinearRule toLinear() const;

    // checks if lhs location coincides with _all_ rhs locations
    bool isSimpleLoop() const;

    // applies the given substitution to guard, cost, and the update's rhss (not to the update's lhss!)
    // Note: Result may be incorrect if an updated variable is updated (which is not checked!)
    // Note: It is always safe if only temporary variables are substituted.
    Rule subs(const Subs &subs) const;
    Rule subs(const ExprSubs &subs) const;

    // Creates a new rule that only leads to the given location, the updates are cleared, guard/cost are kept
    LinearRule replaceRhssBySink(LocationIdx sink) const;

    // Removes all right-hand sides that lead to the given location, returns none if all rhss would be removed
    option<Rule> stripRhsLocation(LocationIdx toRemove) const;

    Rule withGuard(const BoolExpr guard) const;
    Rule withCost(const Expr &cost) const;
    Rule withUpdate(unsigned int i, const Subs &up) const;

    VarSet vars() const;
    void collectVars(VarSet &vars) const;

    BoolVarSet bvars() const;
    void collectVars(BoolVarSet &vars) const;

    unsigned hash() const;
    bool approxEqual(const Rule &that, bool compareRhss) const;

    struct Hash {
        std::size_t operator()(const Rule& r) const {
            return r.hash();
        }
    };

    struct ApproxEqual {
        bool operator()(const Rule& fst, const Rule& snd) const {
            return fst.approxEqual(snd, true);
        }
    };

    using ApproxSet = std::unordered_set<Rule, Rule::Hash, Rule::ApproxEqual>;

    template<class T>
    using ApproxMap = std::unordered_map<Rule, T, Rule::Hash, Rule::ApproxEqual>;

};


/**
 * A linear rule is a rule with exactly one right-hand side.
 *
 * To simplify the code, linear rules are just a subclass of Rule,
 * so they use the same data representation (a vector of right-hand sides).
 * The result is that most of the code can work with the more general Rule,
 * at the cost of a minor performance loss (which is probably not critical).
 *
 * This class is only used to have more expressive function signatures.
 * If performance is critical, all uses of LinearRule can be replaced by Rule
 * together with assertions that the Rule is in fact linear.
 */
class LinearRule : public Rule {
public:
    LinearRule(RuleLhs lhs, RuleRhs rhs) : Rule(lhs, rhs) {}
    LinearRule(LocationIdx lhsLoc, BoolExpr guard, Expr cost, LocationIdx rhsLoc, Subs update)
            : Rule(lhsLoc, guard, cost, rhsLoc, update) {}

    // special shorthands for linear rules, overwriting the general ones
    LocationIdx getRhsLoc() const { return Rule::getRhsLoc(0); }
    const Subs& getUpdate() const { return Rule::getUpdate(0); }
    bool isOctagon() const;
};


/**
 * For debugging output (not very readable)
 */
std::ostream& operator<<(std::ostream &s, const Rule &rule);
