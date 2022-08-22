#include "qecalculus.hpp"

#include "recurrence.hpp"
#include "smtfactory.hpp"
#include "relevantvariables.hpp"
#include "redlog.hpp"

Quantifier QeProblem::getQuantifier() const {
    return formula->getPrefix()[0];
}

BoolExpr QeProblem::boundedFormula(const Var &var) const {
    BoolExpr res = formula->getMatrix();
    const Quantifier quantifier = getQuantifier();
    const auto lowerBound = quantifier.lowerBound(var);
    if (lowerBound) {
        res = res & (lowerBound.get() <= var);
    }
    const auto upperBound = quantifier.upperBound(var);
    if (upperBound) {
        res = res & (var <= upperBound.get());
    }
    return res;
}

RelSet QeProblem::findConsistentSubset(BoolExpr e, const Var &var) const {
    if (formula->isConjunction()) {
        return boundedFormula(var)->lits();
    }
    solver->push();
    solver->add(e);
    Smt::Result sat = solver->check();
    RelSet res;
    if (sat == Smt::Sat) {
        const Subs &model = solver->model().toSubs();
        for (const Rel &rel: formula->getMatrix()->lits()) {
            if (rel.subs(model).isTriviallyTrue()) {
                res.insert(rel);
            }
        }
    }
    solver->pop();
    return res;
}

bool QeProblem::depsWellFounded(const Rel& rel) const {
    RelMap<const QeProblem::Entry*> entryMap;
    return depsWellFounded(rel, entryMap);
}

bool QeProblem::depsWellFounded(const Rel& rel, RelMap<const QeProblem::Entry*> &entryMap, RelSet seen) const {
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

option<unsigned int> QeProblem::store(const Rel &rel, const RelSet &deps, const BoolExpr formula, bool exact) {
    if (res.count(rel) == 0) {
        res[rel] = std::vector<Entry>();
    }
    res[rel].push_back({deps, formula, exact});
    return res[rel].size() - 1;
}

bool QeProblem::monotonicity(const Rel &rel, const Var& n, Proof &proof) {
    const auto bound = getQuantifier().upperBound(n);
    if (bound) {
        const Rel updated = rel.subs({n,n+1});
        const Rel newCond = rel.subs({n, bound.get()});
        RelSet premise = findConsistentSubset(boundedFormula(n) & rel & updated & newCond, n);
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
            const BoolExprSet &unsatCore = Smt::unsatCore(assumptions, varMan);
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
                    proof.append(ss);
                    return true;
                }
            }
        }
    }
    return false;
}

bool QeProblem::recurrence(const Rel &rel, const Var& n, Proof &proof) {
    const auto bound = getQuantifier().lowerBound(n);
    if (bound) {
        const Rel updated = rel.subs({n, n+1});
        const Rel newCond = rel.subs({n, bound.get()});
        RelSet premise = findConsistentSubset(boundedFormula(n) & rel & updated & newCond, n);
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
                const BoolExpr newGuard = buildLit(newCond);
                option<unsigned int> idx = store(rel, dependencies, newGuard);
                if (idx) {
                    std::stringstream ss;
                    ss << rel << " [" << idx.get() << "]: monotonic increase yields " << newGuard;
                    if (!dependencies.empty()) {
                        ss << ", dependencies:";
                        for (const Rel &rel: dependencies) {
                            ss << " " << rel;
                        }
                    }
                    proof.append(ss);
                    return true;
                }
            }
        }
    }
    return false;
}

bool QeProblem::eventualWeakDecrease(const Rel &rel, const Var& n, Proof &proof) {
    if (depsWellFounded(rel)) {
        return false;
    }
    const auto lowerBound = getQuantifier().lowerBound(n);
    const auto upperBound = getQuantifier().upperBound(n);
    if (lowerBound && upperBound) {
        const Expr updated = rel.lhs().subs({n, n+1});
        const Rel dec = rel.lhs() >= updated;
        const Rel inc = updated < updated.subs({n, n+1});
        const BoolExpr newGuard = buildLit(rel.subs({n, lowerBound.get()})) & rel.subs({n, upperBound.get()});
        RelSet premise = findConsistentSubset(boundedFormula(n) & dec & !inc & newGuard, n);
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
                    proof.append(ss);
                    return true;
                }
            }
        }
    }
    return false;
}

bool QeProblem::eventualWeakIncrease(const Rel &rel, const Var& n, Proof &proof) {
    if (depsWellFounded(rel)) {
        return false;
    }
    const auto bound = getQuantifier().lowerBound(n);
    if (bound) {
        const Expr updated = rel.lhs().subs({n, n+1});
        const Rel inc = rel.lhs() <= updated;
        const Rel dec = updated > updated.subs({n, n+1});
        const Rel newCond = rel.subs({n, bound.get()});
        RelSet premise = findConsistentSubset(boundedFormula(n) & inc & !dec & newCond, n);
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
                const BoolExpr newGuard = buildLit(newCond) & inc.subs({n, bound.get()});
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
                        proof.append(ss);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

option<BoolExpr> QeProblem::strengthen(const Rel &rel, const Var &n, Proof &proof) {
    if (res.find(rel) == res.end() && rel.isPoly()) {
        const auto lhs = rel.lhs().expand();
        unsigned degree = lhs.degree(n);
        for (unsigned d = degree; d > 0; --d) {
            const Expr coeff = lhs.coeff(n, d);
            if (!coeff.isGround()) {
                const auto bf = boundedFormula(n);
                if (Smt::check(bf & (coeff < 0), varMan) == Smt::Sat && Smt::check(bf & (coeff >= 0), varMan) == Smt::Sat) {
                    std::stringstream ss;
                    ss << rel << ": strengthend formula with " << (coeff >= 0);
                    proof.append(ss);
                    return buildLit(coeff >= 0);
                } else if (Smt::check(bf & (coeff > 0), varMan) == Smt::Sat && Smt::check(bf & (coeff <= 0), varMan) == Smt::Sat) {
                    std::stringstream ss;
                    ss << rel << ": strengthend formula with " << (coeff <= 0);
                    proof.append(ss);
                    return buildLit(coeff <= 0);
                }
            }
        }
    }
    return {};
}

bool QeProblem::fixpoint(const Rel &rel, const Var& n, Proof &proof) {
    if (res.find(rel) == res.end() && rel.isPoly()) {
        const auto lhs = rel.lhs().expand();
        unsigned degree = lhs.degree(n);
        BoolExpr vanish = True;
        Subs subs;
        for (unsigned d = 1; d <= degree; ++d) {
            vanish = vanish & (Rel::buildEq(lhs.coeff(n, d), 0));
        }
        const auto constant = lhs.subs({n, 0}) > 0;
        if (Smt::check(boundedFormula(n) & constant & vanish, varMan) == Smt::Sat) {
            BoolExpr newGuard = buildLit(constant) & vanish;
            option<unsigned int> idx = store(rel, {}, newGuard, false);
            if (idx) {
                std::stringstream ss;
                ss << rel << " [" << idx.get() << "]: fixpoint yields " << newGuard;
                proof.append(ss);
                return true;
            }
        }
    }
    return false;
}

QeProblem::ReplacementMap QeProblem::computeReplacementMap() const {
    ReplacementMap res;
    res.exact = formula->isConjunction();
    RelMap<const Entry*> entryMap;
    for (const Rel& rel: formula->getMatrix()->lits()) {
        if (depsWellFounded(rel, entryMap)) {
            res.exact &= entryMap[rel]->exact;
        } else {
            res.map[rel] = False;
            res.exact = false;
            if (formula->isConjunction()) return res;
        }
    }
    if (!formula->isConjunction()) {
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

option<Qelim::Result> QeProblem::qe(const QuantifiedFormula &qf) {
    Proof fullProof;
    fullProof.headline("Eliminated Quantifier via QE-Calculus");
    fullProof.append(std::stringstream() << "Input Formula: " << qf);
    formula = qf;
    const auto quantifiers = formula->getPrefix();
    if (quantifiers.size() > 1) {
        return {};
    }
    const auto quantifier = getQuantifier();
    if (quantifier.getType() != Quantifier::Type::Forall) {
        return {};
    }
    Smt::Logic logic = Smt::chooseLogic<RelSet, Subs>({formula->getMatrix()->lits()}, {});
    this->solver = SmtFactory::modelBuildingSolver(logic, varMan);
    const auto vars = quantifier.getVars();
    bool exact = true;
    for (const auto& var: vars) {
        Proof proof;
        proof.append("Eliminating " + var.get_name());
        res = {};
        solution = {};
        todo = formula->getMatrix()->lits();
        bool goOn;
        do {
            goOn = false;
            auto it = todo.begin();
            while (it != todo.end()) {
                const Rel rel = *it;
                bool res = recurrence(rel, var, proof);
                res |= monotonicity(rel, var, proof);
                res |= eventualWeakDecrease(rel, var, proof);
                res |= eventualWeakIncrease(rel, var, proof);
                if (res) {
                    it = todo.erase(it);
                } else {
                    ++it;
                }
            }
            for (const Rel &rel: todo) {
                const option<BoolExpr> str = strengthen(rel, var, proof);
                if (str) {
                    const auto lits = (*str)->lits();
                    todo.insert(lits.begin(), lits.end());
                    solver->add(*str);
                    formula = (formula->getMatrix() & *str)->quantify(quantifiers);
                    goOn = true;
                }
            }
            if (!goOn) {
                for (const Rel &rel: todo) {
                    fixpoint(rel, var, proof);
                }
            }
        } while (goOn);
        ReplacementMap map = computeReplacementMap();
        const BoolExpr matrix = formula->getMatrix()->replaceRels(map.map);
        if (Smt::check(matrix, varMan) != Smt::Sat) {
            return {};
        }
        formula = matrix->quantify({quantifier.remove(var)});
        exact &= map.exact;
        proof.append(std::stringstream() << "Replacement map: " << map.map);
        fullProof.storeSubProof(proof);
    }
    fullProof.append(std::stringstream() << "Resulting Formula: " << formula->getMatrix());
    return Qelim::Result(formula->getMatrix(), fullProof, exact);
}
