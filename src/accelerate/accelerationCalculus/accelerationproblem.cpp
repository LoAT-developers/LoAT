#include "accelerationproblem.hpp"
#include "recurrence.hpp"
#include "smtfactory.hpp"
#include "relevantvariables.hpp"

AccelerationProblem::AccelerationProblem(
        const BExpr<IntTheory> guard,
        const theory::Subs<IntTheory> &up,
        const option<Recurrence::Result> &closed,
        const Expr &cost,
        ITSProblem &its):
    up(up),
    closed(closed),
    cost(cost),
    guard(guard),
    its(its)
{
    for (const auto &l: guard->lits()) {
        todo.insert(std::get<Rel>(l));
    }
    if (closed) {
        auto op = Config::Analysis::reachability() ? Rel::gt : Rel::geq;
        bound =  Rel(closed->n, op, 0);
    }
    const auto &intUp = up.get<IntTheory>();
    const std::vector<ExprSubs> subs = closed.map([&intUp](auto const &closed){return std::vector<ExprSubs>{intUp, closed.update};}).get_value_or({intUp});
    Logic logic = Smt<IntTheory>::chooseLogic<theory::LitSet<IntTheory>, ExprSubs>({guard->lits()}, subs);
    this->solver = SmtFactory::modelBuildingSolver<IntTheory>(logic, its);
    this->solver->add(guard);
    this->isConjunction = guard->isConjunction();
}

AccelerationProblem AccelerationProblem::init(const LinearRule &rule, const option<Recurrence::Result> &closed, ITSProblem &its) {
    theory::Subs<IntTheory> up;
    for (const auto &p: rule.getUpdate()) {
        if (std::holds_alternative<std::pair<NumVar, Expr>>(p)) {
            up.put(std::get<std::pair<NumVar, Expr>>(p));
        } else {
            throw std::logic_error("unsupported theory in accelerationproblem");
        }
    }
    BExpr<IntTheory> guard = rule.getGuard()->toG()->transform<IntTheory>();
    return AccelerationProblem(guard, up, closed, rule.getCost(), its);
}

RelSet AccelerationProblem::findConsistentSubset(BExpr<IntTheory> e) const {
    if (isConjunction) {
        return todo;
    }
    solver->push();
    solver->add(e);
    SmtResult sat = solver->check();
    RelSet res;
    if (sat == Sat) {
        const ExprSubs &model = solver->model().toSubs().get<IntTheory>();
        for (const Rel &rel: todo) {
            if (rel.subs(model).isTriviallyTrue()) {
                res.insert(rel);
            }
        }
    }
    solver->pop();
    return res;
}

option<unsigned int> AccelerationProblem::store(const Rel &rel, const RelSet &deps, const BExpr<IntTheory> formula, bool exact, bool nonterm) {
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
        const Rel updated = rel.subs(up.get<IntTheory>());
        const Rel newCond = rel.subs(closed->update).subs(ExprSubs(closed->n, *closed->n-1));
        RelSet premise = findConsistentSubset(guard & rel & updated & newCond & *bound);
        if (!premise.empty()) {
            BoolExpressionSet<IntTheory> assumptions;
            BoolExpressionSet<IntTheory> deps;
            premise.erase(rel);
            premise.erase(updated);
            for (const Rel &p: premise) {
                const BExpr<IntTheory> lit = BoolExpression<IntTheory>::buildTheoryLit(p);
                assumptions.insert(lit);
                deps.insert(lit);
            }
            assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(updated));
            assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(!rel));
            const auto &unsatCore = SmtFactory::unsatCore(assumptions, its);
            if (!unsatCore.empty()) {
                RelSet dependencies;
                for (const auto &e: unsatCore) {
                    if (deps.count(e) > 0) {
                        const auto &lit = e->lits();
                        assert(lit.size() == 1);
                        dependencies.insert(std::get<Rel>(*lit.begin()));
                    }
                }
                const auto newGuard = BoolExpression<IntTheory>::buildTheoryLit(newCond);
                if (SmtFactory::check(newGuard & *bound, its) == Sat) {
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
    const Rel updated = rel.subs(up.get<IntTheory>());
    RelSet premise = findConsistentSubset(guard & rel & updated);
    if (!premise.empty()) {
        BoolExpressionSet<IntTheory> deps;
        BoolExpressionSet<IntTheory> assumptions;
        premise.erase(rel);
        premise.erase(updated);
        for (const Rel &p: premise) {
            const auto b = BoolExpression<IntTheory>::buildTheoryLit(p);
            assumptions.insert(b);
            deps.insert(b);
        }
        assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(rel));
        assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(!updated));
        const auto unsatCore = SmtFactory::unsatCore(assumptions, its);
        if (!unsatCore.empty()) {
            RelSet dependencies;
            for (const auto &e: unsatCore) {
                if (deps.count(e) > 0) {
                    const auto &lit = e->lits();
                    assert(lit.size() == 1);
                    dependencies.insert(std::get<Rel>(*lit.begin()));
                }
            }
            dependencies.erase(rel);
            const auto newGuard = BoolExpression<IntTheory>::buildTheoryLit(rel);
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
        const Expr updated = rel.lhs().subs(up.get<IntTheory>());
        const Rel dec = Rel::buildGeq(rel.lhs(), updated);
        const Rel inc = Rel::buildLt(updated, updated.subs(up.get<IntTheory>()));
        const Rel newCond = rel.subs(closed->update).subs(ExprSubs(closed->n, *closed->n-1));
        RelSet premise = findConsistentSubset(guard & dec & !inc & rel & newCond & *bound);
        if (!premise.empty()) {
            BoolExpressionSet<IntTheory> assumptions;
            BoolExpressionSet<IntTheory> deps;
            premise.erase(rel);
            premise.erase(dec);
            premise.erase(!inc);
            for (const Rel &p: premise) {
                const auto lit = BoolExpression<IntTheory>::buildTheoryLit(p);
                assumptions.insert(lit);
                deps.insert(lit);
            }
            assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(dec));
            assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(inc));
            const auto unsatCore = SmtFactory::unsatCore(assumptions, its);
            if (!unsatCore.empty()) {
                RelSet dependencies;
                for (const auto &e: unsatCore) {
                    if (deps.count(e) > 0) {
                        const auto &lit = e->lits();
                        assert(lit.size() == 1);
                        dependencies.insert(std::get<Rel>(*lit.begin()));
                    }
                }
                const auto newGuard = BoolExpression<IntTheory>::buildTheoryLit(rel) & newCond;
                if (SmtFactory::check(newGuard & *bound, its) == Sat) {
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
    const Expr &updated = rel.lhs().subs(up.get<IntTheory>());
    const Rel &inc = Rel::buildLeq(rel.lhs(), updated);
    const Rel &dec = Rel::buildGt(updated, updated.subs(up.get<IntTheory>()));
    RelSet premise = findConsistentSubset(guard & inc & !dec & rel);
    if (!premise.empty()) {
        BoolExpressionSet<IntTheory> assumptions;
        BoolExpressionSet<IntTheory> deps;
        premise.erase(rel);
        premise.erase(inc);
        premise.erase(!dec);
        for (const Rel &p: premise) {
            const auto lit = BoolExpression<IntTheory>::buildTheoryLit(p);
            assumptions.insert(lit);
            deps.insert(lit);
        }
        assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(dec));
        assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(inc));
        const auto unsatCore = SmtFactory::unsatCore(assumptions, its);
        if (!unsatCore.empty()) {
            RelSet dependencies;
            for (const auto &e: unsatCore) {
                if (deps.count(e) > 0) {
                    const auto &lit = e->lits();
                    assert(lit.size() == 1);
                    dependencies.insert(std::get<Rel>(*lit.begin()));
                }
            }
            const auto newGuard = BoolExpression<IntTheory>::buildTheoryLit(rel) & inc;
            if (SmtFactory::check(newGuard, its) == Sat) {
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
        std::vector<Theory<IntTheory>::Lit> eqs;
        theory::VarSet<IntTheory> relVars;
        relVars.get<NumVar>() = rel.vars();
        const auto vars = util::RelevantVariables<IntTheory>::find(relVars, {up}, BoolExpression<IntTheory>::True);
        for (const auto& v: vars) {
            const NumVar &var = std::get<NumVar>(v);
            eqs.push_back(Rel::buildEq(var, Expr(var).subs(up.get<IntTheory>())));
        }
        const auto allEq = BoolExpression<IntTheory>::buildAndFromLits(eqs);
        if (SmtFactory::check(guard & rel & allEq, its) == Sat) {
            BExpr<IntTheory> newGuard = allEq & rel;
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
            res.map[rel] = BoolExpression<IntTheory>::False;
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
                BExpr<IntTheory> closure = e.second->formula;
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

std::vector<AccelerationTechnique<IntTheory>::Accelerator> AccelerationProblem::computeRes() {
    std::vector<AccelerationTechnique<IntTheory>::Accelerator> ret;
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
        bool positiveCost = Config::Analysis::mode != Config::Analysis::Mode::Complexity || SmtFactory::isImplication(guard, BoolExpression<IntTheory>::buildTheoryLit(Rel::buildGt(cost, 0)), its);
        bool nt = map.nonterm && positiveCost;
        BExpr<IntTheory> newGuard = guard->replaceLits<IntTheory>(map.map);
        if (!nt) newGuard = newGuard & *bound;
        if (SmtFactory::check(newGuard, its) == Sat) {
            Proof accelProof(proof);
            accelProof.append(std::stringstream() << "Replacement map: " << map.map);
            ret.emplace_back(newGuard, accelProof, map.exact, nt);
        }
        if (Config::Analysis::tryNonterm() && closed && positiveCost && !map.nonterm) {
            ReplacementMap map = computeReplacementMap(true);
            if (map.acceleratedAll || !isConjunction) {
                BExpr<IntTheory> newGuard = guard->replaceLits<IntTheory>(map.map);
                if (SmtFactory::check(newGuard, its) == Sat) {
                    Proof nontermProof(proof);
                    nontermProof.append(std::stringstream() << "Replacement map: " << map.map);
                    ret.emplace_back(newGuard, nontermProof, map.exact, true);
                }
            }
        }
    }
    return ret;
}
