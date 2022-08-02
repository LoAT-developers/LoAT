#include "nontermproblem.hpp"
#include "../accelerate/recurrence/recurrence.hpp"
#include "../smt/smtfactory.hpp"
#include "../util/relevantvariables.hpp"
#include "../qelim/redlog.hpp"

NontermProblem::NontermProblem(
        const BoolExpr guard,
        const Subs &up,
        const Expr &cost,
        VariableManager &varMan): todo(guard->lits()), up(up), cost(cost), guard(guard), varMan(varMan) {
    Smt::Logic logic = Smt::chooseLogic<RelSet, Subs>({todo}, {up});
    this->solver = SmtFactory::modelBuildingSolver(logic, varMan);
    this->solver->add(guard);
    this->isConjunction = guard->isConjunction();
    this->proof.append(std::stringstream() << "proving non-termination of " << guard << " wrt. " << up);
}

NontermProblem NontermProblem::init(const BoolExpr& guard, const Subs &up, const Expr &cost, VariableManager &varMan) {
    return NontermProblem(
                guard->toG(),
                up,
                cost,
                varMan);
}

RelSet NontermProblem::findConsistentSubset(BoolExpr e) const {
    if (isConjunction) {
        return todo;
    }
    solver->push();
    solver->add(e);
    Smt::Result sat = solver->check();
    RelSet res;
    if (sat == Smt::Sat) {
        const Subs &model = solver->model().toSubs();
        for (const Rel &rel: todo) {
            if (rel.subs(model).isTriviallyTrue()) {
                res.insert(rel);
            }
        }
    }
    solver->pop();
    return res;
}

option<unsigned int> NontermProblem::store(const Rel &rel, const RelSet &deps, const BoolExpr formula, bool exact) {
    if (res.count(rel) == 0) {
        res[rel] = std::vector<Entry>();
    }
    res[rel].push_back({deps, formula, exact});
    return res[rel].size() - 1;
}

bool NontermProblem::depsWellFounded(const Rel& rel) const {
    RelMap<const NontermProblem::Entry*> entryMap;
    return depsWellFounded(rel, entryMap);
}

bool NontermProblem::depsWellFounded(const Rel& rel, RelMap<const NontermProblem::Entry*> &entryMap, RelSet seen) const {
    if (entryMap.find(rel) != entryMap.end()) {
        return true;
    } else if (seen.find(rel) != seen.end()) {
        return false;
    }
    seen.insert(rel);
    const auto& it = res.find(rel);
    if (it == res.end()) {
        return false;
    }
    for (const Entry& e: it->second) {
        bool success = true;
        for (const auto& dep: e.dependencies) {
            if (!depsWellFounded(dep, entryMap, seen)) {
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

bool NontermProblem::recurrence(const Rel &rel) {
    const Rel updated = rel.subs(up);
    RelSet premise = findConsistentSubset(guard & rel & updated);
    if (!premise.empty()) {
        BoolExprSet deps;
        BoolExprSet assumptions;
        premise.erase(rel);
        premise.erase(updated);
        for (const Rel &p: premise) {
            const BoolExpr b = buildLit(p);
            assumptions.insert(b);
            deps.insert(b);
        }
        assumptions.insert(buildLit(rel));
        assumptions.insert(buildLit(!updated));
        BoolExprSet unsatCore = Smt::unsatCore(assumptions, varMan);
        if (!unsatCore.empty()) {
            RelSet dependencies;
            for (const BoolExpr &e: unsatCore) {
                if (deps.count(e) > 0) {
                    const RelSet &lit = e->lits();
                    assert(lit.size() == 1);
                    dependencies.insert(*lit.begin());
                }
            }
            dependencies.erase(rel);
            const BoolExpr newGuard = buildLit(rel);
            option<unsigned int> idx = store(rel, dependencies, newGuard, true);
            if (idx) {
                std::stringstream ss;
                ss << rel << " [" << idx.get() << "]: monotonic increase yields " << newGuard;
                if (!dependencies.empty()) {
                    ss << ", dependencies:";
                    for (const Rel &rel: dependencies) {
                        ss << " " << rel;
                    }
                }
                proof.newline();
                proof.append(ss);
                return true;
            }
        }
    }
    return false;
}

bool NontermProblem::eventualWeakIncrease(const Rel &rel) {
    if (depsWellFounded(rel)) {
        return false;
    }
    const Expr &updated = rel.lhs().subs(up);
    const Rel &inc = rel.lhs() <= updated;
    const Rel &dec = updated > updated.subs(up);
    RelSet premise = findConsistentSubset(guard & inc & !dec & rel);
    if (!premise.empty()) {
        BoolExprSet assumptions;
        BoolExprSet deps;
        premise.erase(rel);
        premise.erase(inc);
        premise.erase(!dec);
        for (const Rel &p: premise) {
            const BoolExpr lit = buildLit(p);
            assumptions.insert(lit);
            deps.insert(lit);
        }
        assumptions.insert(buildLit(dec));
        assumptions.insert(buildLit(inc));
        BoolExprSet unsatCore = Smt::unsatCore(assumptions, varMan);
        if (!unsatCore.empty()) {
            RelSet dependencies;
            for (const BoolExpr &e: unsatCore) {
                if (deps.count(e) > 0) {
                    const RelSet &lit = e->lits();
                    assert(lit.size() == 1);
                    dependencies.insert(*lit.begin());
                }
            }
            const BoolExpr newGuard = buildLit(rel) & inc;
            if (Smt::check(newGuard, varMan) == Smt::Sat) {
                option<unsigned int> idx = store(rel, dependencies, newGuard, false);
                if (idx) {
                    std::stringstream ss;
                    ss << rel << " [" << idx.get() << "]: eventual increase yields " << newGuard;
                    if (!dependencies.empty()) {
                        ss << ", dependencies:";
                        for (const Rel &rel: dependencies) {
                            ss << " " << rel;
                        }
                    }
                    proof.newline();
                    proof.append(ss);
                    return true;
                }
            }
        }
    }
    return false;
}

bool NontermProblem::fixpoint(const Rel &rel) {
    if (res.find(rel) == res.end()) {
        RelSet eqs;
        VarSet vars = util::RelevantVariables::find(rel.vars(), {up}, True);
        for (const Var& var: vars) {
            eqs.insert(Rel::buildEq(var, Expr(var).subs(up)));
        }
        BoolExpr allEq = buildAnd(eqs);
        if (Smt::check(guard & rel & allEq, varMan) == Smt::Sat) {
            BoolExpr newGuard = allEq & rel;
            option<unsigned int> idx = store(rel, {}, newGuard, false);
            if (idx) {
                std::stringstream ss;
                ss << rel << " [" << idx.get() << "]: fixpoint yields " << newGuard;
                proof.newline();
                proof.append(ss);
                return true;
            }
        }
    }
    return false;
}

NontermProblem::ReplacementMap NontermProblem::computeReplacementMap() const {
    ReplacementMap res;
    res.exact = guard->isConjunction();
    RelMap<const Entry*> entryMap;
    for (const Rel& rel: todo) {
        if (depsWellFounded(rel, entryMap)) {
            res.exact &= entryMap[rel]->exact;
        } else {
            res.map[rel] = False;
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
                BoolExpr closure = e.second->formula;
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

option<NontermProblem::Result> NontermProblem::computeRes() {
    bool positiveCost = Config::Analysis::mode != Config::Analysis::Mode::Complexity || Smt::isImplication(guard, buildLit(cost > 0), varMan);
    if (!positiveCost) return {};
    for (const Rel& rel: todo) {
        bool res = recurrence(rel);
        res |= eventualWeakIncrease(rel);
        res |= fixpoint(rel);
        if (!res && isConjunction) return {};
    }
    ReplacementMap map = computeReplacementMap();
    std::stringstream s;
    proof.newline();
    s << "replacement map: " << map.map;
    proof.append(s.str());
    proof.newline();
    BoolExpr newGuard = guard->replaceRels(map.map);
    if (Smt::check(newGuard, varMan) == Smt::Sat) {
        return Result(newGuard, map.exact);
    } else {
        return {};
    }
}

Proof NontermProblem::getProof() const {
    return proof;
}
