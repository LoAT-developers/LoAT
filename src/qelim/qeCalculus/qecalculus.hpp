#pragma once

#include "qelim.hpp"
#include "itheory.hpp"
#include "proof.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "map.hpp"
#include "rel.hpp"
#include "boollit.hpp"
#include "variant.hpp"

template <ITheory... Th>
class QeProblem : public Qelim<Th...>
{

    using TheTheory = Theory<Th...>;
    using Lit = typename TheTheory::Lit;
    using LS = theory::LitSet<Th...>;
    using BoolExpr = BExpr<Th...>;
    using BExpression = BoolExpression<Th...>;
    using QFormula = QuantifiedFormula<Th...>;
    using BoolExprSet = BoolExpressionSet<Th...>;
    using Result = typename Qelim<Th...>::Result;

    struct Entry {
        LS dependencies;
        BoolExpr formula;
        bool exact;
    };

    using Res = std::map<Lit, std::vector<Entry>>;

    Res res;
    option<std::map<Lit, Entry>> solution;
    LS todo;
    std::unique_ptr<Smt<Th...>> solver;
    option<QFormula> formula;
    VariableManager &varMan;

    bool monotonicity(const Lit &lit, const NumVar &n, Proof &proof) {
        const auto bound = getQuantifier().upperBound(n);
        if (bound) {
            const auto updated = literal::subs<Th...>(lit, theory::Subs<Th...>::template build<IntTheory>(n, *n+1));
            const auto newGuard = literal::subs<Th...>(lit, theory::Subs<Th...>::template build<IntTheory>(n, *bound));
            auto premise = findConsistentSubset(boundedFormula(n) & lit & updated & newGuard, n);
            if (!premise.empty()) {
                BoolExprSet assumptions, deps;
                premise.erase(lit);
                if (updated->getTheoryLit()) {
                    premise.erase(*updated->getTheoryLit());
                }
                for (const auto &p: premise) {
                    const auto lit = BExpression::buildTheoryLit(p);
                    assumptions.insert(lit);
                    deps.insert(lit);
                }
                assumptions.insert(updated);
                assumptions.insert(BExpression::buildTheoryLit(literal_t::negate<Th...>(lit)));
                const auto unsatCore = SmtFactory::unsatCore(assumptions, varMan);
                if (!unsatCore.empty()) {
                    LS dependencies;
                    for (const auto &e: unsatCore) {
                        if (deps.find(e) != deps.end()) {
                            const auto &lit = e->lits();
                            assert(lit.size() == 1);
                            dependencies.insert(*lit.begin());
                        }
                    }
                    option<unsigned int> idx = store(lit, dependencies, newGuard);
                    if (idx) {
                        std::stringstream ss;
                        ss << lit << " [" << idx.get() << "]: montonic decrease yields " << newGuard;
                        if (!dependencies.empty()) {
                            ss << ", dependencies:";
                            for (const auto &dep: dependencies) {
                                ss << " " << dep;
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

    bool recurrence(const Lit &lit, const NumVar &n, Proof &proof) {
        const auto bound = getQuantifier().lowerBound(n);
        if (bound) {
            const auto updated = literal::subs<Th...>(lit, theory::Subs<Th...>::template build<IntTheory>(n, *n+1));
            const auto newGuard = literal::subs<Th...>(lit, theory::Subs<Th...>::template build<IntTheory>(n, *bound));
            auto premise = findConsistentSubset(boundedFormula(n) & lit & updated & newGuard, n);
            if (!premise.empty()) {
                BoolExprSet deps, assumptions;
                premise.erase(lit);
                if (updated->getTheoryLit()) {
                    premise.erase(*updated->getTheoryLit());
                }
                for (const auto &p: premise) {
                    const auto b = BExpression::buildTheoryLit(p);
                    assumptions.insert(b);
                    deps.insert(b);
                }
                assumptions.insert(BExpression::buildTheoryLit(lit));
                assumptions.insert(!updated);
                auto unsatCore = SmtFactory::unsatCore(assumptions, varMan);
                if (!unsatCore.empty()) {
                    LS dependencies;
                    for (const auto &e: unsatCore) {
                        if (deps.find(e) != deps.end()) {
                            const auto &lit = e->lits();
                            assert(lit.size() == 1);
                            dependencies.insert(*lit.begin());
                        }
                    }
                    dependencies.erase(lit);
                    option<unsigned int> idx = store(lit, dependencies, newGuard);
                    if (idx) {
                        std::stringstream ss;
                        ss << lit << " [" << idx.get() << "]: monotonic increase yields " << newGuard;
                        if (!dependencies.empty()) {
                            ss << ", dependencies:";
                            for (const auto &dep: dependencies) {
                                ss << " " << dep;
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

    bool eventualWeakDecrease(const Lit &lit, const NumVar &n, Proof &proof) {
        if constexpr ((!std::same_as<IntTheory, Th> && ...)) {
            return false;
        }
        if (!std::holds_alternative<Rel>(lit)) {
            return false;
        }
        const Rel &rel = std::get<Rel>(lit);
        if (depsWellFounded(rel)) {
            return false;
        }
        const auto lowerBound = getQuantifier().lowerBound(n);
        const auto upperBound = getQuantifier().upperBound(n);
        if (lowerBound && upperBound) {
            const Expr updated = rel.lhs().subs({{n, *n + 1}});
            const Rel dec = Rel::buildGeq(rel.lhs(), updated);
            const Rel inc = Rel::buildLt(updated, updated.subs({{n, *n + 1}}));
            const auto newGuard = BExpression::buildTheoryLit(rel.subs({{n, lowerBound.get()}})) & rel.subs({{n, upperBound.get()}});
            auto premise = findConsistentSubset(boundedFormula(n) & dec & !inc & newGuard, n);
            if (!premise.empty()) {
                BoolExprSet assumptions, deps;
                premise.erase(rel);
                premise.erase(dec);
                premise.erase(!inc);
                for (const auto &p: premise) {
                    const auto plit = BExpression::buildTheoryLit(p);
                    assumptions.insert(plit);
                    deps.insert(plit);
                }
                assumptions.insert(BExpression::buildTheoryLit(dec));
                assumptions.insert(BExpression::buildTheoryLit(inc));
                auto unsatCore = SmtFactory::unsatCore(assumptions, varMan);
                if (!unsatCore.empty()) {
                    LS dependencies;
                    for (const auto &e: unsatCore) {
                        if (deps.find(e) != deps.end()) {
                            const auto &lit = e->lits();
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
                            for (const auto &dep: dependencies) {
                                ss << " " << dep;
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

    bool eventualWeakIncrease(const Lit &lit, const NumVar &n, Proof &proof) {
        if constexpr ((!std::same_as<IntTheory, Th> && ...)) {
            return false;
        }
        if (!std::holds_alternative<Rel>(lit)) {
            return false;
        }
        const Rel &rel = std::get<Rel>(lit);
        if (depsWellFounded(rel)) {
            return false;
        }
        const auto bound = getQuantifier().lowerBound(n);
        if (bound) {
            const Expr updated = rel.lhs().subs({{n, *n + 1}});
            const Rel inc = Rel::buildLeq(rel.lhs(), updated);
            const Rel dec = Rel::buildGt(updated, updated.subs({{n, *n + 1}}));
            const Rel newCond = rel.subs({{n, bound.get()}});
            auto premise = findConsistentSubset(boundedFormula(n) & inc & !dec & newCond, n);
            if (!premise.empty()) {
                BoolExprSet assumptions, deps;
                premise.erase(rel);
                premise.erase(inc);
                premise.erase(!dec);
                for (const auto &p: premise) {
                    const auto plit = BExpression::buildTheoryLit(p);
                    assumptions.insert(plit);
                    deps.insert(plit);
                }
                assumptions.insert(BExpression::buildTheoryLit(dec));
                assumptions.insert(BExpression::buildTheoryLit(inc));
                auto unsatCore = SmtFactory::unsatCore(assumptions, varMan);
                if (!unsatCore.empty()) {
                    LS dependencies;
                    for (const auto &e: unsatCore) {
                        if (deps.find(e) != deps.end()) {
                            const auto &lit = e->lits();
                            assert(lit.size() == 1);
                            dependencies.insert(*lit.begin());
                        }
                    }
                    const auto newGuard = BExpression::buildTheoryLit(newCond) & inc.subs({{n, bound.get()}});
                    if (SmtFactory::check(newGuard, varMan) == Sat) {
                        option<unsigned int> idx = store(rel, dependencies, newGuard, false);
                        if (idx) {
                            std::stringstream ss;
                            ss << rel << " [" << idx.get() << "]: eventual increase yields " << newGuard;
                            if (!dependencies.empty()) {
                                ss << ", dependencies:";
                                for (const auto &dep: dependencies) {
                                    ss << " " << dep;
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

//    option<BExpr<IntTheory>> strengthen(const Rel &rel, const NumVar &n, Proof &proof) {
//        if (res.find(rel) == res.end() && rel.isPoly()) {
//            const auto lhs = rel.lhs().expand();
//            unsigned degree = lhs.degree(n);
//            for (unsigned d = degree; d > 0; --d) {
//                const Expr coeff = lhs.coeff(n, d);
//                if (!coeff.isGround()) {
//                    const auto bf = boundedFormula(n);
//                    if (SmtFactory::check(bf & Rel::buildLt(coeff, 0), varMan) == Sat && SmtFactory::check(bf & Rel::buildGeq(coeff, 0), varMan) == Sat) {
//                        std::stringstream ss;
//                        ss << rel << ": strengthend formula with " << Rel::buildGeq(coeff, 0);
//                        proof.append(ss);
//                        return BExpression::buildTheoryLit(Rel::buildGeq(coeff, 0));
//                    } else if (SmtFactory::check(bf & Rel::buildGt(coeff, 0), varMan) == Sat && SmtFactory::check(bf & Rel::buildLeq(coeff, 0), varMan) == Sat) {
//                        std::stringstream ss;
//                        ss << rel << ": strengthend formula with " << Rel::buildLeq(coeff, 0);
//                        proof.append(ss);
//                        return BExpression::buildTheoryLit(Rel::buildLeq(coeff, 0));
//                    }
//                }
//            }
//        }
//        return {};
//    }

    bool fixpoint(const Lit &lit, const NumVar &n, Proof &proof) {
        if constexpr ((!std::same_as<IntTheory, Th> && ...)) {
            return false;
        }
        if (!std::holds_alternative<Rel>(lit)) {
            return false;
        }
        const Rel &rel = std::get<Rel>(lit);
        if (res.find(rel) == res.end() && rel.isPoly()) {
            const auto lhs = rel.lhs().expand();
            unsigned degree = lhs.degree(n);
            auto vanish = BExpression::True;
            Subs subs;
            for (unsigned d = 1; d <= degree; ++d) {
                vanish = vanish & (Rel::buildEq(lhs.coeff(n, d), 0));
            }
            const auto constant = Rel::buildGt(lhs.subs({{n, 0}}), 0);
            if (SmtFactory::check(boundedFormula(n) & constant & vanish, varMan) == Sat) {
                auto newGuard = BExpression::buildTheoryLit(constant) & vanish;
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

    LS findConsistentSubset(const BoolExpr e, const NumVar &var) const {
        if (formula->isConjunction()) {
            return boundedFormula(var)->lits();
        }
        solver->push();
        solver->add(e);
        SmtResult sat = solver->check();
        LS res;
        if (sat == Sat) {
            const auto &model = solver->model().toSubs();
            for (const auto &lit: formula->getMatrix()->lits()) {
                if (literal::subs<Th...>(lit, model)->isTriviallyTrue()) {
                    res.insert(lit);
                }
            }
        }
        solver->pop();
        return res;
    }

    option<unsigned int> store(const Lit &lit, const LS &deps, const BoolExpr formula, bool exact = true) {
        auto it = res.find(lit);
        if (it == res.end()) {
            res[lit] = {{deps, formula, exact}};
            return 0;
        } else {
            it->second.emplace_back(deps, formula, exact);
            return it->second.size() - 1;
        }
    }

    BoolExpr boundedFormula(const NumVar &var) const {
        auto res = formula->getMatrix();
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

    struct ReplacementMap {
        bool exact;
        std::map<Lit, BoolExpr> map;
    };

    ReplacementMap computeReplacementMap() const {
        ReplacementMap res;
        res.exact = formula->isConjunction();
        std::map<Lit, const Entry*> entryMap;
        for (const auto& lit: formula->getMatrix()->lits()) {
            if (depsWellFounded(lit, entryMap)) {
                res.exact &= entryMap[lit]->exact;
            } else {
                res.map[lit] = BExpression::False;
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

    Quantifier getQuantifier() const {
        return formula->getPrefix()[0];
    }

    bool depsWellFounded(const Lit& lit) const {
        std::map<Lit, const QeProblem::Entry*> entryMap;
        return depsWellFounded(lit, entryMap);
    }

    bool depsWellFounded(const Lit& lit, std::map<Lit, const QeProblem::Entry*> &entryMap, LS seen = {}) const {
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

public:

    QeProblem(VariableManager &varMan): varMan(varMan){}

    option<Result> qe(const QFormula &qf) override {
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
        SmtFactory::SmtConfig config(Smt<Th...>::template chooseLogic<LS, ExprSubs>({formula->getMatrix()->lits()}, {}));
        config.incremental = true;
        config.produce_models = true;
        this->solver = SmtFactory::solver<Th...>(config, varMan);
        const auto vars = quantifier.getVars();
        bool exact = true;
        for (const auto& var: vars) {
            Proof proof;
            proof.append("Eliminating " + var.getName());
            res = {};
            solution = {};
            todo = formula->getMatrix()->lits();
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
                    for (const auto &lit: todo) {
                        fixpoint(lit, var, proof);
                    }
                }
            } while (goOn);
            ReplacementMap map = computeReplacementMap();
            const BoolExpr matrix = formula->getMatrix()->replaceLits(map.map);
            if (SmtFactory::check(matrix, varMan) != Sat) {
                return {};
            }
            formula = matrix->quantify({quantifier.remove(var)});
            exact &= map.exact;
            proof.append(std::stringstream() << "Replacement map: " << map.map);
            fullProof.storeSubProof(proof);
        }
        fullProof.append(std::stringstream() << "Resulting Formula: " << formula->getMatrix());
        return Result(formula->getMatrix(), fullProof, exact);
    }

};
