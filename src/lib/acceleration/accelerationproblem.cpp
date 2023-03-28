#include "accelerationproblem.hpp"
#include "recurrence.hpp"
#include "smtfactory.hpp"
#include "relevantvariables.hpp"
#include "literal.hpp"
#include "boolexpr.hpp"
#include "map.hpp"

AccelerationProblem::AccelerationProblem(
        const Rule &rule,
        const std::optional<Recurrence::Result> &closed,
        const Subs &samplePoint,
        VarMan &its,
        const AccelConfig &config):
    AccelerationTechnique(rule, closed, its, config),
    samplePoint(samplePoint) {
    for (const auto &l: rule.getGuard()->lits()) {
        todo.insert(l);
    }
    if (closed) {
        bound =  Rel(closed->n, Rel::geq, 1);
    }
    const auto subs {closed ? std::vector<Subs>{rule.getUpdate(), closed->update} : std::vector<Subs>{rule.getUpdate()}};
    Logic logic {Smt<IntTheory, BoolTheory>::chooseLogic<LitSet, Subs>({todo}, subs)};
    this->solver = SmtFactory::modelBuildingSolver<IntTheory, BoolTheory>(logic, its);
    this->solver->add(rule.getGuard());
}

std::optional<unsigned int> AccelerationProblem::store(const Lit &lit, const LitSet &deps, const BoolExpr formula, bool exact, bool nonterm) {
    auto it = res.find(lit);
    if (it == res.end()) {
        res[lit] = {{deps, formula, exact, nonterm}};
        return 0;
    } else {
        it->second.push_back({deps, formula, exact, nonterm});
        return it->second.size() - 1;
    }
}

bool AccelerationProblem::depsWellFounded(const Lit& lit, bool nontermOnly) const {
    std::map<Lit, const AccelerationProblem::Entry*> entryMap;
    return depsWellFounded(lit, entryMap, nontermOnly);
}

bool AccelerationProblem::depsWellFounded(const Lit& lit, std::map<Lit, const AccelerationProblem::Entry*> &entryMap, bool nontermOnly, LitSet seen) const {
    if (entryMap.find(lit) != entryMap.end()) {
        return true;
    } else if (seen.find(lit) != seen.end()) {
        return false;
    }
    seen.insert(lit);
    const auto& it = res.find(lit);
    if (it == res.end()) {
        return false;
    }
    for (const Entry& e: it->second) {
        if (nontermOnly && !e.nonterm) continue;
        bool success = true;
        for (const auto& dep: e.dependencies) {
            if (!depsWellFounded(dep, entryMap, nontermOnly, seen)) {
                success = false;
                break;
            }
        }
        if (success) {
            entryMap[it->first] = &e;
            return true;
        }
    }
    return false;
}

BoolExpr AccelerationProblem::monotonicity(const Lit &lit, Proof &proof) {
    if (!closed) {
        return BExpression::False;
    }
    if (depsWellFounded(lit, false)) {
        return BExpression::False;
    }
    const auto newGuard = literal::subs(lit, closed->update)->subs(Subs::build<IntTheory>(closed->n, *closed->n-1));
    if (!config.allowDisjunctions && !newGuard->isConjunction()) {
        return BExpression::False;
    }
    const auto updated = literal::subs(lit, rule.getUpdate());
    auto premise {todo};
    premise.erase(lit);
    if (updated->getTheoryLit()) {
        premise.erase(*updated->getTheoryLit());
    }
    BoolExprSet assumptions, deps;
    for (const auto &p: premise) {
        const auto lit = BExpression::buildTheoryLit(p);
        assumptions.insert(lit);
        deps.insert(lit);
    }
    assumptions.insert(updated);
    assumptions.insert(BExpression::buildTheoryLit(literal::negate(lit)));
    const auto &unsatCore = SmtFactory::unsatCore(assumptions, its);
    if (unsatCore.empty()) {
        return BExpression::False;
    }
    LitSet dependencies;
    for (const auto &e: unsatCore) {
        if (deps.find(e) != deps.end()) {
            const auto &lit = e->lits();
            assert(lit.size() == 1);
            dependencies.insert(*lit.begin());
        }
    }
    std::optional<unsigned int> idx = store(lit, dependencies, newGuard);
    if (!idx) {
        return BExpression::False;
    }
    std::stringstream ss;
    ss << lit << " [" << *idx << "]: montonic decrease yields " << newGuard;
    if (!dependencies.empty()) {
        ss << ", dependencies:";
        for (const auto &dep: dependencies) {
            ss << " " << dep;
        }
    }
    proof.newline();
    proof.append(ss);
    return BExpression::True;
}

BoolExpr AccelerationProblem::recurrence(const Lit &lit, Proof &proof) {
    const auto updated = literal::subs(lit, rule.getUpdate());
    auto premise {todo};
    premise.erase(lit);
    if (updated->getTheoryLit()) {
        premise.erase(*updated->getTheoryLit());
    }
    BoolExprSet deps, assumptions;
    for (const auto &p: premise) {
        const auto b = BExpression::buildTheoryLit(p);
        assumptions.insert(b);
        deps.insert(b);
    }
    assumptions.insert(BExpression::buildTheoryLit(lit));
    assumptions.insert(!updated);
    const auto unsatCore = SmtFactory::unsatCore(assumptions, its);
    if (unsatCore.empty()) {
        return BExpression::False;
    }
    LitSet dependencies;
    for (const auto &e: unsatCore) {
        if (deps.find(e) != deps.end()) {
            const auto &lit = e->lits();
            assert(lit.size() == 1);
            dependencies.insert(*lit.begin());
        }
    }
    dependencies.erase(lit);
    const auto newGuard = BExpression::buildTheoryLit(lit);
    std::optional<unsigned int> idx = store(lit, dependencies, newGuard, true, true);
    if (!idx) {
        return BExpression::False;
    }
    std::stringstream ss;
    ss << lit << " [" << *idx << "]: monotonic increase yields " << newGuard;
    if (!dependencies.empty()) {
        ss << ", dependencies:";
        for (const auto &dep: dependencies) {
            ss << " " << dep;
        }
    }
    proof.newline();
    proof.append(ss);
    return BExpression::True;
}

BoolExpr AccelerationProblem::eventualWeakDecrease(const Lit &lit, Proof &proof) {
    if (!closed) {
        return BExpression::False;
    }
    if (!std::holds_alternative<Rel>(lit)) {
        return BExpression::False;
    }
    const Rel &rel {std::get<Rel>(lit)};
    if (depsWellFounded(rel, false)) {
        return BExpression::False;
    }
    const auto newCond {rel.subs(closed->update.get<IntTheory>()).subs({{closed->n, *closed->n-1}})};
    const auto newGuard {BExpression::buildTheoryLit(rel) & newCond};
    const auto updated {rel.lhs().subs(rule.getUpdate<IntTheory>())};
    const auto dec {Rel::buildGeq(rel.lhs(), updated)};
    const auto inc {Rel::buildLt(updated, updated.subs(rule.getUpdate<IntTheory>()))};
    auto premise {todo};
    premise.erase(rel);
    premise.erase(dec);
    premise.erase(!inc);
    BoolExprSet assumptions, deps;
    for (const auto &p: premise) {
        const auto lit {BExpression::buildTheoryLit(p)};
        assumptions.insert(lit);
        deps.insert(lit);
    }
    assumptions.insert(BExpression::buildTheoryLit(dec));
    assumptions.insert(BExpression::buildTheoryLit(inc));
    const auto unsatCore = SmtFactory::unsatCore(assumptions, its);
    if (unsatCore.empty()) {
        return BExpression::False;
    }
    LitSet dependencies;
    for (const auto &e: unsatCore) {
        if (deps.count(e) > 0) {
            const auto &lit {e->lits()};
            assert(lit.size() == 1);
            dependencies.insert(*lit.begin());
        }
    }
    const auto idx {store(rel, dependencies, newGuard)};
    if (!idx) {
        return BExpression::False;
    }
    std::stringstream ss;
    ss << rel << " [" << *idx << "]: eventual decrease yields " << newGuard;
    if (!dependencies.empty()) {
        ss << ", dependencies:";
        for (const auto &dep: dependencies) {
            ss << " " << dep;
        }
    }
    proof.newline();
    proof.append(ss);
    return BExpression::True;
}

BoolExpr AccelerationProblem::eventualIncrease(const Lit &lit, const bool strict, Proof &proof) {
    if (!std::holds_alternative<Rel>(lit)) {
        return BExpression::False;
    }
    if (depsWellFounded(lit, config.tryNonterm)) {
        return BExpression::False;
    }
    const Rel &rel = std::get<Rel>(lit);
    const Expr &updated = rel.lhs().subs(rule.getUpdate<IntTheory>());
    const Rel &inc = strict ? Rel::buildLt(rel.lhs(), updated) : Rel::buildLeq(rel.lhs(), updated);
    const Rel &dec = strict ? Rel::buildGeq(updated, updated.subs(rule.getUpdate<IntTheory>())) : Rel::buildGt(updated, updated.subs(rule.getUpdate<IntTheory>()));
    auto premise {todo};
    premise.erase(rel);
    premise.erase(inc);
    premise.erase(!dec);
    BoolExprSet assumptions, deps;
    for (const auto &p: premise) {
        const auto lit = BExpression::buildTheoryLit(p);
        assumptions.insert(lit);
        deps.insert(lit);
    }
    assumptions.insert(BExpression::buildTheoryLit(dec));
    assumptions.insert(BExpression::buildTheoryLit(inc));
    const auto unsatCore = SmtFactory::unsatCore(assumptions, its);
    if (unsatCore.empty()) {
        return BExpression::False;
    }
    LitSet dependencies;
    for (const auto &e: unsatCore) {
        if (deps.count(e) > 0) {
            const auto &lit = e->lits();
            assert(lit.size() == 1);
            dependencies.insert(*lit.begin());
        }
    }
    const auto newGuard = BExpression::buildTheoryLit(rel) & inc;
    std::optional<unsigned int> idx = store(rel, dependencies, newGuard, false, true);
    if (!idx) {
        return BExpression::False;
    }
    std::stringstream ss;
    ss << rel << " [" << *idx << "]: eventual increase yields " << newGuard;
    if (!dependencies.empty()) {
        ss << ", dependencies:";
        for (const auto &dep: dependencies) {
            ss << " " << dep;
        }
    }
    proof.newline();
    proof.append(ss);
    return BExpression::buildTheoryLit(inc);
}

BoolExpr AccelerationProblem::fixpoint(const Lit &lit, Proof &proof) {
    if (res.find(lit) != res.end()) {
        return BExpression::False;
    }
    std::vector<BoolExpr> eqs;
    const auto vars = util::RelevantVariables<IntTheory, BoolTheory>::find(literal::variables(lit), rule.getUpdate());
    for (const auto& v: vars) {
        if (!config.allowDisjunctions && std::holds_alternative<BoolVar>(v)) {
            // encoding equality for booleans introduces a disjunction
            return BExpression::False;
        }
        eqs.push_back(literal::mkEq(TheTheory::varToExpr(v), rule.getUpdate().get(v)));
    }
    const auto allEq = BExpression::buildAnd(eqs);
    if (SmtFactory::check(rule.getGuard() & lit & allEq, its) != Sat) {
        return BExpression::False;
    }
    BoolExpr newGuard = allEq & lit;
    std::optional<unsigned int> idx = store(lit, {}, newGuard, false, true);
    if (!idx) {
        return BExpression::False;
    }
    std::stringstream ss;
    ss << lit << " [" << *idx << "]: fixpoint yields " << newGuard;
    proof.newline();
    proof.append(ss);
    return allEq;
}

std::optional<AccelerationProblem::ReplacementMap> AccelerationProblem::computeReplacementMap(bool nontermOnly) const {
    ReplacementMap res;
    res.nonterm = true;
    res.exact = rule.getGuard()->isConjunction();
    std::map<Lit, const Entry*> entryMap;
    for (const auto& lit: todo) {
        if (depsWellFounded(lit, entryMap, nontermOnly)) {
            res.nonterm &= entryMap[lit]->nonterm;
            res.exact &= entryMap[lit]->exact;
        } else {
            return {};
        }
    }
    for (auto e: entryMap) {
        res.map[e.first] = e.second->formula;
    }
    return res;
}

AccelerationProblem::AcceleratorPair AccelerationProblem::computeRes() {
    AcceleratorPair ret;
    if (!closed && !config.tryNonterm) {
        return ret;
    }
    Proof proof;
    for (const auto& lit: todo) {
        auto res {recurrence(lit, proof)};
        res = res | monotonicity(lit, proof);
        res = res | eventualWeakDecrease(lit, proof);
        if (config.approx == UnderApprox) {
            auto evInc {eventualIncrease(lit, false, proof)};
            if (evInc == BExpression::False) {
                evInc = eventualIncrease(lit, true, proof);
            }
            res = res | evInc;
            res = res->simplify();
            if (res == BExpression::False) {
                res = res | fixpoint(lit, proof);
                res = res->simplify();
            }
        }
        if (res == BExpression::False) return ret;
    }
    auto map {computeReplacementMap(false)};
    if (!map) {
        return ret;
    }
    auto newGuard {rule.getGuard()->replaceLits(map->map)};
    if (closed) {
        newGuard = newGuard & *bound;
    }
    if (SmtFactory::check(newGuard, its) == Sat) {
        ret.term.emplace(newGuard, proof, map->exact);
        ret.term->proof.newline();
        ret.term->proof.append(std::stringstream() << "Replacement map: " << map->map);
        if (map->nonterm) {
            ret.nonterm = ret.term;
        }
    }
    if (config.tryNonterm && closed && !map->nonterm) {
        map = computeReplacementMap(true);
        if (map) {
            newGuard = rule.getGuard()->replaceLits(map->map);
            if (SmtFactory::check(newGuard, its) == Sat) {
                ret.nonterm.emplace(newGuard, proof, map->exact);
                ret.nonterm->proof.newline();
                ret.nonterm->proof.append(std::stringstream() << "Replacement map: " << map->map);
            }
        }
    }
    return ret;
}
