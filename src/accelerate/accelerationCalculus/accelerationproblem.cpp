#include "accelerationproblem.hpp"
#include "recurrence.hpp"
#include "smtfactory.hpp"
#include "relevantvariables.hpp"
#include "literal.hpp"
#include "boolexpr.hpp"
#include "map.hpp"

AccelerationProblem::AccelerationProblem(
        const BoolExpr guard,
        const Subs &up,
        const option<Recurrence::Result> &closed,
        const Expr &cost,
        ITSProblem &its,
        const AccelConfig &config):
    up(up),
    closed(closed),
    cost(cost),
    guard(guard),
    its(its),
    config(config) {
    for (const auto &l: guard->lits()) {
        todo.insert(l);
    }
    if (closed) {
        bound =  Rel(closed->n, Rel::geq, 1);
    }
    const auto subs = closed.map([&up](auto const &closed){
        return std::vector<Subs>{up, closed.update};
    }).get_value_or({up});
    Logic logic = Smt<IntTheory, BoolTheory>::chooseLogic<LitSet, Subs>({guard->lits()}, subs);
    this->solver = SmtFactory::modelBuildingSolver<IntTheory, BoolTheory>(logic, its);
    this->solver->add(guard);
    this->isConjunction = guard->isConjunction();
}

AccelerationProblem AccelerationProblem::init(
        const Rule &rule,
        const option<Recurrence::Result> &closed,
        ITSProblem &its,
        const AccelConfig &config) {
    return AccelerationProblem(rule.getGuard()->toG(), rule.getUpdate(), closed, rule.getCost(), its, config);
}

LitSet AccelerationProblem::findConsistentSubset(BoolExpr e) const {
    if (isConjunction) {
        return todo;
    }
    solver->push();
    solver->add(e);
    SmtResult sat = solver->check();
    LitSet res;
    if (sat == Sat) {
        const auto model = solver->model().toSubs();
        for (const auto &lit: todo) {
            if (literal::subs(lit, model)->isTriviallyTrue()) {
                res.insert(lit);
            }
        }
    }
    solver->pop();
    return res;
}

option<unsigned int> AccelerationProblem::store(const Lit &lit, const LitSet &deps, const BoolExpr formula, bool exact, bool nonterm) {
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

bool AccelerationProblem::monotonicity(const Lit &lit, Proof &proof) {
    if (!closed) {
        return false;
    }
    if (depsWellFounded(lit, false)) {
        return false;
    }
    const auto newGuard = literal::subs(lit, closed->update)->subs(Subs::build<IntTheory>(closed->n, *closed->n-1));
    if (!config.allowDisjunctions && !newGuard->isConjunction()) {
        return false;
    }
    const auto updated = literal::subs(lit, up);
    auto premise = findConsistentSubset(guard & lit & updated & newGuard & *bound);
    if (premise.empty()) {
        return false;
    }
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
        return false;
    }
    LitSet dependencies;
    for (const auto &e: unsatCore) {
        if (deps.find(e) != deps.end()) {
            const auto &lit = e->lits();
            assert(lit.size() == 1);
            dependencies.insert(*lit.begin());
        }
    }
    option<unsigned int> idx = store(lit, dependencies, newGuard);
    if (!idx) {
        return false;
    }
    std::stringstream ss;
    ss << lit << " [" << idx.get() << "]: montonic decrease yields " << newGuard;
    if (!dependencies.empty()) {
        ss << ", dependencies:";
        for (const auto &dep: dependencies) {
            ss << " " << dep;
        }
    }
    proof.newline();
    proof.append(ss);
    return true;
}

bool AccelerationProblem::recurrence(const Lit &lit, Proof &proof) {
    const auto updated = literal::subs(lit, up);
    auto premise = findConsistentSubset(guard & lit & updated);
    if (premise.empty()) {
        return false;
    }
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
        return false;
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
    option<unsigned int> idx = store(lit, dependencies, newGuard, true, true);
    if (!idx) {
        return false;
    }
    std::stringstream ss;
    ss << lit << " [" << idx.get() << "]: monotonic increase yields " << newGuard;
    if (!dependencies.empty()) {
        ss << ", dependencies:";
        for (const auto &dep: dependencies) {
            ss << " " << dep;
        }
    }
    proof.newline();
    proof.append(ss);
    return true;
}

bool AccelerationProblem::eventualWeakDecrease(const Lit &lit, Proof &proof) {
    if (!closed) {
        return false;
    }
    if (!std::holds_alternative<Rel>(lit)) {
        return false;
    }
    const Rel &rel = std::get<Rel>(lit);
    if (depsWellFounded(rel, false)) {
        return false;
    }
    const Rel newCond = rel.subs(closed->update.get<IntTheory>()).subs({{closed->n, *closed->n-1}});
    const auto newGuard = BExpression::buildTheoryLit(rel) & newCond;
    const Expr updated = rel.lhs().subs(up.get<IntTheory>());
    const Rel dec = Rel::buildGeq(rel.lhs(), updated);
    const Rel inc = Rel::buildLt(updated, updated.subs(up.get<IntTheory>()));
    auto premise = findConsistentSubset(guard & dec & !inc & rel & newCond & *bound);
    if (premise.empty()) {
        return false;
    }
    premise.erase(rel);
    premise.erase(dec);
    premise.erase(!inc);
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
        return false;
    }
    LitSet dependencies;
    for (const auto &e: unsatCore) {
        if (deps.count(e) > 0) {
            const auto &lit = e->lits();
            assert(lit.size() == 1);
            dependencies.insert(*lit.begin());
        }
    }
    option<unsigned int> idx = store(rel, dependencies, newGuard);
    if (!idx) {
        return false;
    }
    std::stringstream ss;
    ss << rel << " [" << idx.get() << "]: eventual decrease yields " << newGuard;
    if (!dependencies.empty()) {
        ss << ", dependencies:";
        for (const auto &dep: dependencies) {
            ss << " " << dep;
        }
    }
    proof.newline();
    proof.append(ss);
    return true;
}

bool AccelerationProblem::eventualWeakIncrease(const Lit &lit, Proof &proof) {
    if (!std::holds_alternative<Rel>(lit)) {
        return false;
    }
    if (depsWellFounded(lit, true)) {
        return false;
    }
    const Rel &rel = std::get<Rel>(lit);
    const Expr &updated = rel.lhs().subs(up.get<IntTheory>());
    const Rel &inc = Rel::buildLeq(rel.lhs(), updated);
    const Rel &dec = Rel::buildGt(updated, updated.subs(up.get<IntTheory>()));
    auto premise = findConsistentSubset(guard & inc & !dec & rel);
    if (premise.empty()) {
        return false;
    }
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
        return false;
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
    option<unsigned int> idx = store(rel, dependencies, newGuard, false, true);
    if (!idx) {
        return false;
    }
    std::stringstream ss;
    ss << rel << " [" << idx.get() << "]: eventual increase yields " << newGuard;
    if (!dependencies.empty()) {
        ss << ", dependencies:";
        for (const auto &dep: dependencies) {
            ss << " " << dep;
        }
    }
    proof.newline();
    proof.append(ss);
    return true;
}

bool AccelerationProblem::fixpoint(const Lit &lit, Proof &proof) {
    if (res.find(lit) != res.end()) {
        return false;
    }
    std::vector<BoolExpr> eqs;
    const auto vars = util::RelevantVariables<IntTheory, BoolTheory>::find(literal::variables(lit), {up}, BExpression::True);
    for (const auto& v: vars) {
        if (!config.allowDisjunctions && std::holds_alternative<BoolVar>(v)) {
            // encoding equality for booleans introduces a disjunction
            return false;
        }
        eqs.push_back(literal::mkEq(TheTheory::varToExpr(v), up.get(v)));
    }
    const auto allEq = BExpression::buildAnd(eqs);
    if (SmtFactory::check(guard & lit & allEq, its) != Sat) {
        return false;
    }
    BoolExpr newGuard = allEq & lit;
    option<unsigned int> idx = store(lit, {}, newGuard, false, true);
    if (!idx) {
        return false;
    }
    std::stringstream ss;
    ss << lit << " [" << idx.get() << "]: fixpoint yields " << newGuard;
    proof.newline();
    proof.append(ss);
    return true;
}

AccelerationProblem::ReplacementMap AccelerationProblem::computeReplacementMap(bool nontermOnly) const {
    ReplacementMap res;
    res.nonterm = true;
    res.acceleratedAll = true;
    res.exact = guard->isConjunction();
    std::map<Lit, const Entry*> entryMap;
    for (const auto& lit: todo) {
        if (depsWellFounded(lit, entryMap, nontermOnly)) {
            res.nonterm &= entryMap[lit]->nonterm;
            res.exact &= entryMap[lit]->exact;
        } else {
            res.acceleratedAll = false;
            res.map[lit] = BExpression::False;
            res.exact = false;
            if (isConjunction) return res;
        }
    }
    if (!isConjunction) {
        bool changed;
        do {
            changed = false;
            for (auto e: entryMap) {
                if (res.map.find(e.first) != res.map.end()) continue;
                auto closure = e.second->formula;
                bool ready = true;
                for (auto dep: e.second->dependencies) {
                    if (res.map.find(dep) == res.map.end()) {
                        ready = false;
                        break;
                    } else {
                        closure = closure & res.map[dep];
                    }
                }
                if (ready) {
                    res.map[e.first] = closure;
                    changed = true;
                }
            }
        } while (changed);
    } else {
        for (auto e: entryMap) {
            res.map[e.first] = e.second->formula;
        }
    }
    return res;
}

AccelerationProblem::AcceleratorPair AccelerationProblem::computeRes() {
    AcceleratorPair ret;
    if (!closed && !Config::Analysis::tryNonterm()) {
        return ret;
    }
    Proof proof;
    for (const auto& lit: todo) {
        bool res = recurrence(lit, proof);
        res |= monotonicity(lit, proof);
        res |= eventualWeakDecrease(lit, proof);
        res |= config.approx == UnderApprox && eventualWeakIncrease(lit, proof);
        res |= config.approx == UnderApprox && fixpoint(lit, proof);
        if (!res && isConjunction) return ret;
    }
    ReplacementMap map = computeReplacementMap(false);
    if (map.acceleratedAll || !isConjunction) {
        bool positiveCost = Config::Analysis::mode != Config::Analysis::Mode::Complexity || SmtFactory::check(guard & Rel::buildLeq(cost, 0), its) == Unsat;
        bool nt = map.nonterm && positiveCost;
        auto newGuard = guard->replaceLits(map.map);
        if (closed) {
            newGuard = newGuard & *bound;
        }
        if (SmtFactory::check(newGuard, its) == Sat) {
            ret.term.emplace(newGuard, proof, map.exact);
            ret.term->proof.newline();
            ret.term->proof.append(std::stringstream() << "Replacement map: " << map.map);
            if (nt) {
                ret.nonterm = ret.term;
            }
        }
        if (Config::Analysis::tryNonterm() && closed && positiveCost && !map.nonterm) {
            ReplacementMap map = computeReplacementMap(true);
            if (map.acceleratedAll || !isConjunction) {
                auto newGuard = guard->replaceLits(map.map);
                if (SmtFactory::check(newGuard, its) == Sat) {
                    ret.nonterm.emplace(newGuard, proof, map.exact);
                    ret.nonterm->proof.newline();
                    ret.nonterm->proof.append(std::stringstream() << "Replacement map: " << map.map);
                }
            }
        }
    }
    return ret;
}
