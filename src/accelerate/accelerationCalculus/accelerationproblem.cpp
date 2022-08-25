#include "accelerationproblem.hpp"
#include "recurrence.hpp"
#include "smtfactory.hpp"
#include "relevantvariables.hpp"
#include "redlog.hpp"

AccelerationProblem::AccelerationProblem(
        const BoolExpr guard,
        const Subs &up,
        const option<Recurrence::Result<Subs>> &closed,
        const Expr &cost,
        ITSProblem &its): todo(guard->lits()), up(up), closed(closed), cost(cost), guard(guard), its(its) {
    const std::vector<Subs> subs = closed.map([&up](auto const &closed){return std::vector<Subs>{up, closed.update};}).get_value_or({up});
    Smt::Logic logic = Smt::chooseLogic<RelSet, Subs>({todo}, subs);
    this->solver = SmtFactory::modelBuildingSolver(logic, its);
    this->solver->add(guard);
    this->isConjunction = guard->isConjunction();
}

AccelerationProblem AccelerationProblem::init(const LinearRule &rule, const option<Recurrence::Result<Subs>> &closed, ITSProblem &its) {
    return AccelerationProblem(rule.getGuard()->toG(), rule.getUpdate(), closed, rule.getCost(), its);
}

RelSet AccelerationProblem::findConsistentSubset(BoolExpr e) const {
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

option<unsigned int> AccelerationProblem::store(const Rel &rel, const RelSet &deps, const BoolExpr formula, bool exact, bool nonterm) {
    if (res.count(rel) == 0) {
        res[rel] = std::vector<Entry>();
    }
    res[rel].push_back({deps, formula, exact, nonterm});
    return res[rel].size() - 1;
}

bool AccelerationProblem::depsWellFounded(const Rel& rel, bool nontermOnly) const {
    RelMap<const AccelerationProblem::Entry*> entryMap;
    return depsWellFounded(rel, entryMap, nontermOnly);
}

bool AccelerationProblem::depsWellFounded(const Rel& rel, RelMap<const AccelerationProblem::Entry*> &entryMap, bool nontermOnly, RelSet seen) const {
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

bool AccelerationProblem::monotonicity(const Rel &rel, Proof &proof) {
    if (closed) {
        if (depsWellFounded(rel, false)) {
            return false;
        }
        const Rel updated = rel.subs(up);
        const Rel newCond = rel.subs(closed->update).subs(Subs(closed->n, closed->n-1));
        RelSet premise = findConsistentSubset(guard & rel & updated & newCond & (closed->n >= closed->validityBound));
        if (!premise.empty()) {
            BoolExprSet assumptions;
            BoolExprSet deps;
            premise.erase(rel);
            premise.erase(updated);
            for (const Rel &p: premise) {
                const BoolExpr lit = buildLit(p);
                assumptions.insert(lit);
                deps.insert(lit);
            }
            assumptions.insert(buildLit(updated));
            assumptions.insert(buildLit(!rel));
            const BoolExprSet &unsatCore = Smt::unsatCore(assumptions, its);
            if (!unsatCore.empty()) {
                RelSet dependencies;
                for (const BoolExpr &e: unsatCore) {
                    if (deps.count(e) > 0) {
                        const RelSet &lit = e->lits();
                        assert(lit.size() == 1);
                        dependencies.insert(*lit.begin());
                    }
                }
                const BoolExpr newGuard = buildLit(newCond);
                if (Smt::check(newGuard & (closed->n >= closed->validityBound), its) == Smt::Sat) {
                    option<unsigned int> idx = store(rel, dependencies, newGuard);
                    if (idx) {
                        std::stringstream ss;
                        ss << rel << " [" << idx.get() << "]: montonic decrease yields " << newGuard;
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
    }
    return false;
}

bool AccelerationProblem::recurrence(const Rel &rel, Proof &proof) {
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
        BoolExprSet unsatCore = Smt::unsatCore(assumptions, its);
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
            option<unsigned int> idx = store(rel, dependencies, newGuard, true, true);
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

bool AccelerationProblem::eventualWeakDecrease(const Rel &rel, Proof &proof) {
    if (closed) {
        if (depsWellFounded(rel, false)) {
             return false;
        }
        const Expr updated = rel.lhs().subs(up);
        const Rel dec = rel.lhs() >= updated;
        const Rel inc = updated < updated.subs(up);
        const Rel newCond = rel.subs(closed->update).subs(Subs(closed->n, closed->n-1));
        RelSet premise = findConsistentSubset(guard & dec & !inc & rel & newCond & (closed->n >= closed->validityBound));
        if (!premise.empty()) {
            BoolExprSet assumptions;
            BoolExprSet deps;
            premise.erase(rel);
            premise.erase(dec);
            premise.erase(!inc);
            for (const Rel &p: premise) {
                const BoolExpr lit = buildLit(p);
                assumptions.insert(lit);
                deps.insert(lit);
            }
            assumptions.insert(buildLit(dec));
            assumptions.insert(buildLit(inc));
            BoolExprSet unsatCore = Smt::unsatCore(assumptions, its);
            if (!unsatCore.empty()) {
                RelSet dependencies;
                for (const BoolExpr &e: unsatCore) {
                    if (deps.count(e) > 0) {
                        const RelSet &lit = e->lits();
                        assert(lit.size() == 1);
                        dependencies.insert(*lit.begin());
                    }
                }
                const BoolExpr newGuard = buildLit(rel) & newCond;
                if (Smt::check(newGuard & (closed->n >= closed->validityBound), its) == Smt::Sat) {
                    option<unsigned int> idx = store(rel, dependencies, newGuard);
                    if (idx) {
                        std::stringstream ss;
                        ss << rel << " [" << idx.get() << "]: eventual decrease yields " << newGuard;
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
    }
    return false;
}

bool AccelerationProblem::eventualWeakIncrease(const Rel &rel, Proof &proof) {
    if (depsWellFounded(rel, true)) {
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
        BoolExprSet unsatCore = Smt::unsatCore(assumptions, its);
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
            if (Smt::check(newGuard, its) == Smt::Sat) {
                option<unsigned int> idx = store(rel, dependencies, newGuard, false, true);
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

bool AccelerationProblem::fixpoint(const Rel &rel, Proof &proof) {
    if (res.find(rel) == res.end()) {
        RelSet eqs;
        VarSet vars = util::RelevantVariables::find(rel.vars(), {up}, True);
        for (const Var& var: vars) {
            eqs.insert(Rel::buildEq(var, Expr(var).subs(up)));
        }
        BoolExpr allEq = buildAnd(eqs);
        if (Smt::check(guard & rel & allEq, its) == Smt::Sat) {
            BoolExpr newGuard = allEq & rel;
            option<unsigned int> idx = store(rel, {}, newGuard, false, true);
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

AccelerationProblem::ReplacementMap AccelerationProblem::computeReplacementMap(bool nontermOnly) const {
    ReplacementMap res;
    res.nonterm = true;
    res.acceleratedAll = true;
    res.exact = guard->isConjunction();
    RelMap<const Entry*> entryMap;
    for (const Rel& rel: todo) {
        if (depsWellFounded(rel, entryMap, nontermOnly)) {
            res.nonterm &= entryMap[rel]->nonterm;
            res.exact &= entryMap[rel]->exact;
        } else {
            res.acceleratedAll = false;
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

std::vector<AccelerationTechnique::Accelerator> AccelerationProblem::computeRes() {
    std::vector<AccelerationTechnique::Accelerator> ret;
    Proof proof;
    for (const Rel& rel: todo) {
        bool res = recurrence(rel, proof);
        res |= monotonicity(rel, proof);
        res |= eventualWeakDecrease(rel, proof);
        res |= eventualWeakIncrease(rel, proof);
        res |= fixpoint(rel, proof);
        if (!res && isConjunction) return ret;
    }
    ReplacementMap map = computeReplacementMap(false);
    if (map.acceleratedAll || !isConjunction) {
        bool positiveCost = Config::Analysis::mode != Config::Analysis::Mode::Complexity || Smt::isImplication(guard, buildLit(cost > 0), its);
        bool nt = map.nonterm && positiveCost;
        BoolExpr newGuard = guard->replaceRels(map.map);
        if (!nt) newGuard = newGuard & (closed->n >= 0);
        if (Smt::check(newGuard, its) == Smt::Sat) {
            Proof accelProof(proof);
            accelProof.append(std::stringstream() << "Replacement map: " << map.map);
            ret.emplace_back(newGuard, accelProof, map.exact, nt);
        }
        if (closed && positiveCost && !map.nonterm) {
            ReplacementMap map = computeReplacementMap(true);
            if (map.acceleratedAll || !isConjunction) {
                BoolExpr newGuard = guard->replaceRels(map.map);
                if (Smt::check(newGuard, its) == Smt::Sat) {
                    Proof nontermProof(proof);
                    nontermProof.append(std::stringstream() << "Replacement map: " << map.map);
                    ret.emplace_back(newGuard, nontermProof, map.exact, true);
                }
            }
        }
    }
    return ret;
}
