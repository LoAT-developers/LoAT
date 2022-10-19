#include "qecalculus.hpp"
#include "smtfactory.hpp"

Quantifier QeProblem::getQuantifier() const {
    return formula->getPrefix()[0];
}

BExpr<IntTheory> QeProblem::boundedFormula(const NumVar &var) const {
    BExpr<IntTheory> res = formula->getMatrix();
    const Quantifier quantifier = getQuantifier();
    const auto lowerBound = quantifier.lowerBound(var);
    if (lowerBound) {
        res = res & Rel::buildLeq(lowerBound.get(), var);
    }
    const auto upperBound = quantifier.upperBound(var);
    if (upperBound) {
        res = res & Rel::buildLeq(var, upperBound.get());
    }
    return res;
}

std::set<Rel> QeProblem::findConsistentSubset(BExpr<IntTheory> e, const NumVar &var) const {
    if (formula->isConjunction()) {
        return boundedFormula(var)->lits().get<Rel>();
    }
    solver->push();
    solver->add(e);
    SmtResult sat = solver->check();
    std::set<Rel> res;
    if (sat == Sat) {
        const auto &model = solver->model().toSubs().get<IntTheory>();
        for (const auto &lit: formula->getMatrix()->lits()) {
            const auto rel = std::get<Rel>(lit);
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

option<unsigned int> QeProblem::store(const Rel &rel, const std::set<Rel> &deps, const BExpr<IntTheory> formula, bool exact) {
    if (res.count(rel) == 0) {
        res[rel] = std::vector<Entry>();
    }
    res[rel].push_back({deps, formula, exact});
    return res[rel].size() - 1;
}

bool QeProblem::monotonicity(const Rel &rel, const NumVar& n, Proof &proof) {
    const auto bound = getQuantifier().upperBound(n);
    if (bound) {
        const Rel updated = rel.subs({n,*n + 1});
        const Rel newCond = rel.subs({n, bound.get()});
        auto premise = findConsistentSubset(boundedFormula(n) & rel & updated & newCond, n);
        if (!premise.empty()) {
            BoolExpressionSet<IntTheory> assumptions;
            BoolExpressionSet<IntTheory> deps;
            premise.erase(rel);
            premise.erase(updated);
            for (const auto &p: premise) {
                const auto lit = BoolExpression<IntTheory>::buildTheoryLit(p);
                assumptions.insert(lit);
                deps.insert(lit);
            }
            assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(updated));
            assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(!rel));
            const auto unsatCore = SmtFactory::unsatCore<IntTheory>(assumptions, varMan);
            if (!unsatCore.empty()) {
                std::set<Rel> dependencies;
                for (const auto &e: unsatCore) {
                    if (deps.find(e) != deps.end()) {
                        const auto &lit = e->lits();
                        assert(lit.size() == 1);
                        dependencies.insert(std::get<Rel>(*lit.begin()));
                    }
                }
                const auto newGuard = BoolExpression<IntTheory>::buildTheoryLit(newCond);
                option<unsigned int> idx = store(rel, dependencies, newGuard);
                if (idx) {
                    std::stringstream ss;
                    ss << rel << " [" << idx.get() << "]: montonic decrease yields " << newGuard;
                    if (!dependencies.empty()) {
                        ss << ", dependencies:";
                        for (const auto &rel: dependencies) {
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

bool QeProblem::recurrence(const Rel &rel, const NumVar& n, Proof &proof) {
    const auto bound = getQuantifier().lowerBound(n);
    if (bound) {
        const Rel updated = rel.subs({n, *n + 1});
        const Rel newCond = rel.subs({n, bound.get()});
        auto premise = findConsistentSubset(boundedFormula(n) & rel & updated & newCond, n);
        if (!premise.empty()) {
            BoolExpressionSet<IntTheory> deps;
            BoolExpressionSet<IntTheory> assumptions;
            premise.erase(rel);
            premise.erase(updated);
            for (const auto &p: premise) {
                const auto b = BoolExpression<IntTheory>::buildTheoryLit(p);
                assumptions.insert(b);
                deps.insert(b);
            }
            assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(rel));
            assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(!updated));
            auto unsatCore = SmtFactory::unsatCore(assumptions, varMan);
            if (!unsatCore.empty()) {
                std::set<Rel> dependencies;
                for (const auto &e: unsatCore) {
                    if (deps.find(e) != deps.end()) {
                        const auto &lit = e->lits();
                        assert(lit.size() == 1);
                        dependencies.insert(std::get<Rel>(*lit.begin()));
                    }
                }
                dependencies.erase(rel);
                const auto newGuard = BoolExpression<IntTheory>::buildTheoryLit(newCond);
                option<unsigned int> idx = store(rel, dependencies, newGuard);
                if (idx) {
                    std::stringstream ss;
                    ss << rel << " [" << idx.get() << "]: monotonic increase yields " << newGuard;
                    if (!dependencies.empty()) {
                        ss << ", dependencies:";
                        for (const auto &rel: dependencies) {
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

bool QeProblem::eventualWeakDecrease(const Rel &rel, const NumVar& n, Proof &proof) {
    if (depsWellFounded(rel)) {
        return false;
    }
    const auto lowerBound = getQuantifier().lowerBound(n);
    const auto upperBound = getQuantifier().upperBound(n);
    if (lowerBound && upperBound) {
        const Expr updated = rel.lhs().subs({n, *n + 1});
        const Rel dec = Rel::buildGeq(rel.lhs(), updated);
        const Rel inc = Rel::buildLt(updated, updated.subs({n, *n + 1}));
        const auto newGuard = BoolExpression<IntTheory>::buildTheoryLit(rel.subs({n, lowerBound.get()})) & rel.subs({n, upperBound.get()});
        auto premise = findConsistentSubset(boundedFormula(n) & dec & !inc & newGuard, n);
        if (!premise.empty()) {
            BoolExpressionSet<IntTheory> assumptions;
            BoolExpressionSet<IntTheory> deps;
            premise.erase(rel);
            premise.erase(dec);
            premise.erase(!inc);
            for (const auto &p: premise) {
                const auto lit = BoolExpression<IntTheory>::buildTheoryLit(p);
                assumptions.insert(lit);
                deps.insert(lit);
            }
            assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(dec));
            assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(inc));
            auto unsatCore = SmtFactory::unsatCore(assumptions, varMan);
            if (!unsatCore.empty()) {
                std::set<Rel> dependencies;
                for (const auto &e: unsatCore) {
                    if (deps.find(e) != deps.end()) {
                        const auto &lit = e->lits();
                        assert(lit.size() == 1);
                        dependencies.insert(std::get<Rel>(*lit.begin()));
                    }
                }
                option<unsigned int> idx = store(rel, dependencies, newGuard);
                if (idx) {
                    std::stringstream ss;
                    ss << rel << " [" << idx.get() << "]: eventual decrease yields " << newGuard;
                    if (!dependencies.empty()) {
                        ss << ", dependencies:";
                        for (const auto &rel: dependencies) {
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

bool QeProblem::eventualWeakIncrease(const Rel &rel, const NumVar& n, Proof &proof) {
    if (depsWellFounded(rel)) {
        return false;
    }
    const auto bound = getQuantifier().lowerBound(n);
    if (bound) {
        const Expr updated = rel.lhs().subs({n, *n + 1});
        const Rel inc = Rel::buildLeq(rel.lhs(), updated);
        const Rel dec = Rel::buildGt(updated, updated.subs({n, *n + 1}));
        const Rel newCond = rel.subs({n, bound.get()});
        auto premise = findConsistentSubset(boundedFormula(n) & inc & !dec & newCond, n);
        if (!premise.empty()) {
            BoolExpressionSet<IntTheory> assumptions;
            BoolExpressionSet<IntTheory> deps;
            premise.erase(rel);
            premise.erase(inc);
            premise.erase(!dec);
            for (const auto &p: premise) {
                const auto lit = BoolExpression<IntTheory>::buildTheoryLit(p);
                assumptions.insert(lit);
                deps.insert(lit);
            }
            assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(dec));
            assumptions.insert(BoolExpression<IntTheory>::buildTheoryLit(inc));
            auto unsatCore = SmtFactory::unsatCore(assumptions, varMan);
            if (!unsatCore.empty()) {
                std::set<Rel> dependencies;
                for (const auto &e: unsatCore) {
                    if (deps.find(e) != deps.end()) {
                        const auto &lit = e->lits();
                        assert(lit.size() == 1);
                        dependencies.insert(std::get<Rel>(*lit.begin()));
                    }
                }
                const auto newGuard = BoolExpression<IntTheory>::buildTheoryLit(newCond) & inc.subs({n, bound.get()});
                if (SmtFactory::check(newGuard, varMan) == Sat) {
                    option<unsigned int> idx = store(rel, dependencies, newGuard, false);
                    if (idx) {
                        std::stringstream ss;
                        ss << rel << " [" << idx.get() << "]: eventual increase yields " << newGuard;
                        if (!dependencies.empty()) {
                            ss << ", dependencies:";
                            for (const auto &rel: dependencies) {
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

option<BExpr<IntTheory>> QeProblem::strengthen(const Rel &rel, const NumVar &n, Proof &proof) {
    if (res.find(rel) == res.end() && rel.isPoly()) {
        const auto lhs = rel.lhs().expand();
        unsigned degree = lhs.degree(n);
        for (unsigned d = degree; d > 0; --d) {
            const Expr coeff = lhs.coeff(n, d);
            if (!coeff.isGround()) {
                const auto bf = boundedFormula(n);
                if (SmtFactory::check(bf & Rel::buildLt(coeff, 0), varMan) == Sat && SmtFactory::check(bf & Rel::buildGeq(coeff, 0), varMan) == Sat) {
                    std::stringstream ss;
                    ss << rel << ": strengthend formula with " << Rel::buildGeq(coeff, 0);
                    proof.append(ss);
                    return BoolExpression<IntTheory>::buildTheoryLit(Rel::buildGeq(coeff, 0));
                } else if (SmtFactory::check(bf & Rel::buildGt(coeff, 0), varMan) == Sat && SmtFactory::check(bf & Rel::buildLeq(coeff, 0), varMan) == Sat) {
                    std::stringstream ss;
                    ss << rel << ": strengthend formula with " << Rel::buildLeq(coeff, 0);
                    proof.append(ss);
                    return BoolExpression<IntTheory>::buildTheoryLit(Rel::buildLeq(coeff, 0));
                }
            }
        }
    }
    return {};
}

bool QeProblem::fixpoint(const Rel &rel, const NumVar& n, Proof &proof) {
    if (res.find(rel) == res.end() && rel.isPoly()) {
        const auto lhs = rel.lhs().expand();
        unsigned degree = lhs.degree(n);
        BExpr<IntTheory> vanish = BoolExpression<IntTheory>::True;
        Subs subs;
        for (unsigned d = 1; d <= degree; ++d) {
            vanish = vanish & (Rel::buildEq(lhs.coeff(n, d), 0));
        }
        const auto constant = Rel::buildGt(lhs.subs({n, 0}), 0);
        if (SmtFactory::check(boundedFormula(n) & constant & vanish, varMan) == Sat) {
            auto newGuard = BoolExpression<IntTheory>::buildTheoryLit(constant) & vanish;
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
    for (const auto& lit: formula->getMatrix()->lits()) {
        const Rel &rel = std::get<Rel>(lit);
        if (depsWellFounded(rel, entryMap)) {
            res.exact &= entryMap[rel]->exact;
        } else {
            res.map[rel] = BoolExpression<IntTheory>::False;
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
                auto closure = e.second->formula;
                bool ready = true;
                for (const auto &dep: e.second->dependencies) {
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

option<Qelim::Result> QeProblem::qe(const QuantifiedFormula<IntTheory> &qf) {
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
    Logic logic = chooseLogic<theory::LitSet<IntTheory>, ExprSubs>({formula->getMatrix()->lits()}, {});
    this->solver = SmtFactory::modelBuildingSolver<IntTheory>(logic, varMan);
    const auto vars = quantifier.getVars();
    bool exact = true;
    for (const auto& var: vars) {
        Proof proof;
        proof.append("Eliminating " + var.getName());
        res = {};
        solution = {};
        todo = formula->getMatrix()->lits().get<Rel>();
        bool goOn;
        do {
            goOn = false;
            auto it = todo.begin();
            while (it != todo.end()) {
                bool res = recurrence(*it, var, proof);
                res |= monotonicity(*it, var, proof);
                res |= eventualWeakDecrease(*it, var, proof);
                res |= eventualWeakIncrease(*it, var, proof);
                if (res) {
                    it = todo.erase(it);
                } else {
                    ++it;
                }
            }
//            for (const Rel &rel: todo) {
//                const option<BoolExpr> str = strengthen(rel, var, proof);
//                if (str) {
//                    const auto lits = (*str)->lits();
//                    todo.insert(lits.begin(), lits.end());
//                    solver->add(*str);
//                    formula = (formula->getMatrix() & *str)->quantify(quantifiers);
//                    goOn = true;
//                }
//            }
            if (!goOn) {
                for (const auto &rel: todo) {
                    fixpoint(rel, var, proof);
                }
            }
        } while (goOn);
        ReplacementMap map = computeReplacementMap();
        const BExpr<IntTheory> matrix = formula->getMatrix()->replaceLits<IntTheory>(map.map);
        if (SmtFactory::check(matrix, varMan) != Sat) {
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
