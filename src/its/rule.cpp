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

#include "rule.hpp"
#include "rel.hpp"

using namespace std;


Rule::Rule(RuleLhs lhs, std::vector<RuleRhs> rhss) : lhs(lhs), rhss(rhss) {
    assert(!rhss.empty());
    if (getCost().isNontermSymbol()) {
        rhss = {RuleRhs(rhss[0].getLoc(), {})};
    }
}

Rule::Rule(LocationIdx lhsLoc, BoolExpr guard, Expr cost, LocationIdx rhsLoc, Subs update)
        : lhs(lhsLoc, guard, cost), rhss({RuleRhs(rhsLoc, update)}) {
    if (getCost().isNontermSymbol()) {
        rhss = {RuleRhs(rhss[0].getLoc(), {})};
    }
}

Rule::Rule(RuleLhs lhs, RuleRhs rhs)
        : lhs(lhs), rhss({rhs}) {
    if (getCost().isNontermSymbol()) {
        rhss = {RuleRhs(rhss[0].getLoc(), {})};
    }
}

void Rule::collectVars(VarSet &vars) const {
    lhs.collectVars(vars);
    for (const RuleRhs &rhs: rhss) {
        rhs.collectVars(vars);
    }
}

VarSet Rule::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

LinearRule Rule::dummyRule(LocationIdx lhsLoc, LocationIdx rhsLoc) {
    return LinearRule(lhsLoc, {}, 0, rhsLoc, {});
}

bool Rule::isDummyRule() const {
    return isLinear() && getCost().isZero() && getGuard() == True && getUpdate(0).empty();
}

bool Rule::isLinear() const {
    return rhss.size() == 1;
}

LinearRule Rule::toLinear() const {
    assert(isLinear());
    return LinearRule(lhs, rhss.front());
}

bool Rule::isSimpleLoop() const {
    return std::all_of(rhss.begin(), rhss.end(), [&](const RuleRhs &rhs){ return rhs.getLoc() == lhs.getLoc(); });
}

Rule Rule::subs(const Subs &subs) const {
    std::vector<RuleRhs> newRhss;
    for (const RuleRhs &rhs : rhss) {
        newRhss.push_back(RuleRhs(rhs.getLoc(), rhs.getUpdate().concat(subs)));
    }
    return Rule(RuleLhs(getLhsLoc(), getGuard()->subs(subs), getCost().subs(subs)), newRhss);
}

LinearRule Rule::replaceRhssBySink(LocationIdx sink) const {
    return LinearRule(getLhs(), RuleRhs(sink, {}));
}

option<Rule> Rule::stripRhsLocation(LocationIdx toRemove) const {
    vector<RuleRhs> newRhss;
    for (const RuleRhs &rhs : rhss) {
        if (rhs.getLoc() != toRemove) {
            newRhss.push_back(rhs);
        }
    }

    if (newRhss.empty()) {
        return {};
    } else {
        return Rule(lhs, newRhss);
    }
}

Rule Rule::withGuard(const BoolExpr guard) const {
    return Rule(RuleLhs(getLhsLoc(), guard, getCost()), getRhss());
}

Rule Rule::withCost(const Expr &cost) const {
    return Rule(RuleLhs(getLhsLoc(), getGuard(), cost), getRhss());
}

Rule Rule::withUpdate(unsigned int i, const Subs &up) const {
    std::vector<RuleRhs> rhss = getRhss();
    rhss[i] = RuleRhs(rhss[i].getLoc(), up);
    return Rule(RuleLhs(getLhsLoc(), getGuard(), getCost()), rhss);
}

bool Rule::approxEqual(const Rule &that, bool compareRhss) const {
    // Some trivial syntactic checks
    if (compareRhss && rhsCount() != that.rhsCount()) return false;

    // Costs have to be equal up to a numeric constant
    if (!(getCost() - that.getCost()).isRationalConstant()) return false;

    // All right-hand sides have to match exactly
    if (compareRhss) {
        for (unsigned int i=0; i < rhsCount(); ++i) {
            const Subs &updateA = getUpdate(i);
            const Subs &updateB = that.getUpdate(i);

            if (getRhsLoc(i) != that.getRhsLoc(i)) return false;
            if (updateA.size() != updateB.size()) return false;

            // update has to be fully equal (one inclusion suffices, since the size is equal)
            for (const auto &itA : updateA) {
                auto itB = updateB.find(itA.first);
                if (itB == updateB.end()) return false;
                if (!itB->second.equals(itA.second)) return false;
            }
        }
    }

    // Guard has to be fully equal (including the ordering)
    if (getGuard() != that.getGuard()) return false;
    return true;
}

unsigned Rule::hash() const {
    unsigned hash = 7;
    hash = hash * 31 + lhs.hash();
    std::vector<unsigned> rhsHashs;
    for (const auto& r: rhss) {
        rhsHashs.push_back(r.hash());
    }
    std::sort(rhsHashs.begin(), rhsHashs.end());
    for (unsigned h: rhsHashs) {
        hash = 31 * hash + h;
    }
    return hash;
}

bool operator ==(const RuleRhs &fst, const RuleRhs &snd) {
    return fst.getLoc() == snd.getLoc() && fst.getUpdate() == snd.getUpdate();
}

ostream& operator<<(ostream &s, const Rule &rule) {
    s << "Rule(";

    // lhs (loc, guard, cost)
    s << rule.getLhsLoc() << " | ";
    s << rule.getGuard();
    s << "| ";
    s << rule.getCost();

    // rhs (loc, update)*
    s << " |";

    for (auto rhs = rule.rhsBegin(); rhs != rule.rhsEnd(); ++rhs) {
        s << "| " << rhs->getLoc() << " | ";

        for (auto upit : rhs->getUpdate()) {
            s << upit.first << "=" << upit.second;
            s << ", ";
        }
    }

    s << ")";
    return s;
}
