#include "accelerationproblem.hpp"
#include "recurrence.hpp"
#include "smtfactory.hpp"
#include "expr.hpp"
#include "boolexpr.hpp"
#include "map.hpp"
#include "relevantvariables.hpp"

AccelerationProblem::AccelerationProblem(
        const Rule &r,
        const std::optional<Recurrence::Result> &closed,
        const std::optional<Subs> &samplePoint,
        const AccelConfig &config):
    closed(closed),
    update(r.getUpdate()),
    guard(r.getGuard()->toG()),
    config(config),
    samplePoint(samplePoint) {
//    if (closed) {
//        update.get<IntTheory>() = closed->refined_equations;
//        proof.append(std::stringstream() << "refined update: " << update);
//    }
    for (const auto &l: guard->lits()) {
        todo.insert(l);
    }
    if (closed) {
        bound =  Rel(closed->n, Rel::geq, 1);
    }
    const auto subs {closed ? std::vector<Subs>{update, closed->closed_form} : std::vector<Subs>{update}};
    Logic logic {Smt<IntTheory, BoolTheory>::chooseLogic<LitSet, Subs>({todo}, subs)};
    this->solver = SmtFactory::modelBuildingSolver<IntTheory, BoolTheory>(logic);
    this->solver->add(guard);
}

unsigned AccelerationProblem::store(const Lit &lit, const LitSet &deps, const BoolExpr formula, bool nonterm) {
    auto it = res.find(lit);
    if (it == res.end()) {
        res[lit] = {{deps, formula, nonterm}};
        return 0;
    } else {
        it->second.push_back({deps, formula, nonterm});
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

bool AccelerationProblem::trivial(const Lit &lit) {
    if (expr::subs(lit, update)->isTriviallyTrue()) {
        auto idx {store(lit, {}, BExpression::buildTheoryLit(lit), true)};
        proof.newline();
        proof.append(std::stringstream() << lit << " [" << idx << "]: trivial");
        return true;
    }
    return false;
}

bool AccelerationProblem::unchanged(const Lit &lit) {
    if (BExpression::buildTheoryLit(lit) == expr::subs(lit, update)) {
        auto idx {store(lit, {}, BExpression::buildTheoryLit(lit), true)};
        proof.newline();
        proof.append(std::stringstream() << lit << " [" << idx << "]: unchanged");
        return true;
    }
    return false;
}

bool AccelerationProblem::polynomial(const Lit &lit) {
    if (!closed || !std::holds_alternative<Rel>(lit)) {
        return false;
    }
    const auto &rel {std::get<Rel>(lit)};
    const auto nfold {rel.lhs().subs(closed->closed_form.get<IntTheory>()).expand()};
    if (!nfold.isPoly(closed->n)) {
        return false;
    }
    const auto &up {update.get<IntTheory>()};
    const ExprSubs but_last {closed->closed_form.get<IntTheory>().compose({{closed->n, Expr(closed->n) - 1}})};
    bool low_degree {false};
    RelSet guard;
    switch (nfold.degree(closed->n)) {
    case 0: return false;
    case 1: {
        const auto coeff {nfold.coeff(closed->n, 1)};
        if (coeff.isGround()) {
            if (coeff.toNum().is_positive()) {
                guard.insert(rel);
            } else {
                guard.insert(rel.subs(but_last));
            }
        } else {
            guard.insert(rel);
            guard.insert(rel.subs(but_last));
        }
        low_degree = true;
        break;
    }
    case 2: {
        const auto coeff {nfold.coeff(closed->n, 2)};
        if (coeff.isGround()) {
            if (coeff.toNum().is_negative()) {
                guard.insert(rel);
                guard.insert(rel.subs(but_last));
                low_degree = true;
            }
        }
        break;
    }
    default: {}
    }
    if (!low_degree && samplePoint) {
        if (nfold.isGround() || !nfold.isPoly(closed->n)) {
            return false;
        }
        auto sample_point {samplePoint->get<IntTheory>()};
        std::vector<Expr> derivatives {rel.lhs()};
        std::vector<GiNaC::numeric> signs {rel.lhs().subs(sample_point).toNum()};
        Expr diff;
        do {
            const auto &last {derivatives.back()};
            diff = (last.subs(up) - last).expand();
            derivatives.push_back(diff);
            signs.push_back(diff.subs(sample_point).toNum());
        } while (!diff.isGround());
        for (unsigned i = 1; i < signs.size() - 1; ++i) {
            if (signs.at(i).is_zero()) {
                for (unsigned j = i + 1; j < signs.size(); ++j) {
                    if (!signs.at(j).is_zero()) {
                        signs[i] = signs[j];
                        break;
                    }
                }
            }
        }
        if (signs.at(1).is_positive()) {
            guard.insert(rel);
        } else {
            guard.insert(rel.subs(but_last));
        }
        for (unsigned i = 1; i < derivatives.size() - 1; ++i) {
            if (signs.at(i).is_positive()) {
                const auto r {Rel::buildGeq(derivatives.at(i), 0)};
                guard.insert(r);
            } else {
                const auto r {Rel::buildLeq(derivatives.at(i), 0)};
                guard.insert(r);
            }
            if (signs.at(i+1).is_positive()) {
                // the i-th derivative is monotonically increasing at the sampling point
                if (signs.at(i).is_positive()) {
                    guard.insert(Rel::buildGeq(derivatives.at(i), 0));
                } else {
                    guard.insert(Rel::buildLeq(derivatives.at(i).subs(but_last), 0));
                }
            } else {
                if (signs.at(i).is_positive()) {
                    guard.insert(Rel::buildGeq(derivatives.at(i).subs(but_last), 0));
                } else {
                    guard.insert(Rel::buildLeq(derivatives.at(i), 0));
                }
            }
        }
    }
    const auto res {BExpression::buildAndFromLits(guard)};
    auto idx {store(lit, {}, res)};
    proof.newline();
    proof.append(std::stringstream() << lit << " [" << idx << "]: polynomial acceleration yields " << res);
    return true;
}

bool AccelerationProblem::monotonicity(const Lit &lit) {
    if (!closed) {
        return false;
    }
    if (depsWellFounded(lit, false)) {
        return false;
    }
    auto newGuard = expr::subs(lit, closed->closed_form)->subs(Subs::build<IntTheory>(closed->n, *closed->n-1));
    if (closed->prefix > 0) {
        newGuard = newGuard & lit;
    }
    if (!config.allowDisjunctions && !newGuard->isConjunction()) {
        return false;
    }
    const auto updated = expr::subs(lit, update);
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
    assumptions.insert(BExpression::buildTheoryLit(expr::negate(lit)));
    const auto &unsatCore = SmtFactory::unsatCore(assumptions);
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
    auto idx {store(lit, dependencies, newGuard)};
    std::stringstream ss;
    ss << lit << " [" << idx << "]: montonic decrease yields " << newGuard;
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

bool AccelerationProblem::recurrence(const Lit &lit) {
    const auto updated = expr::subs(lit, update);
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
    const auto unsatCore = SmtFactory::unsatCore(assumptions);
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
    auto idx {store(lit, dependencies, newGuard, true)};
    std::stringstream ss;
    ss << lit << " [" << idx << "]: monotonic increase yields " << newGuard;
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

bool AccelerationProblem::eventualWeakDecrease(const Lit &lit) {
    if (!closed) {
        return false;
    }
    if (!std::holds_alternative<Rel>(lit)) {
        return false;
    }
    const Rel &rel {std::get<Rel>(lit)};
    if (depsWellFounded(rel, false)) {
        return false;
    }
    const auto newCond {rel.subs(closed->closed_form.get<IntTheory>()).subs({{closed->n, *closed->n-1}})};
    const auto newGuard {BExpression::buildTheoryLit(rel) & newCond};
    const auto updated {rel.lhs().subs(update.get<IntTheory>())};
    const auto dec {Rel::buildGeq(rel.lhs(), updated)};
    const auto inc {Rel::buildLt(updated, updated.subs(update.get<IntTheory>()))};
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
    const auto unsatCore = SmtFactory::unsatCore(assumptions);
    if (unsatCore.empty()) {
        return false;
    }
    LitSet dependencies;
    for (const auto &e: unsatCore) {
        if (deps.count(e) > 0) {
            const auto &lit {e->lits()};
            assert(lit.size() == 1);
            dependencies.insert(*lit.begin());
        }
    }
    auto idx {store(rel, dependencies, newGuard)};
    std::stringstream ss;
    ss << rel << " [" << idx << "]: eventual decrease yields " << newGuard;
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

bool AccelerationProblem::eventualIncrease(const Lit &lit, const bool strict) {
    if (!std::holds_alternative<Rel>(lit)) {
        return false;
    }
    if (depsWellFounded(lit, config.tryNonterm)) {
        return false;
    }
    const auto &rel {std::get<Rel>(lit)};
    const auto &updated {rel.lhs().subs(update.get<IntTheory>())};
    const auto &inc = strict ? Rel::buildLt(rel.lhs(), updated) : Rel::buildLeq(rel.lhs(), updated);
    if (samplePoint && inc.subs(samplePoint->get<IntTheory>()).isTriviallyFalse()) {
        return false;
    }
    const auto &dec = strict ? Rel::buildGeq(updated, updated.subs(update.get<IntTheory>())) : Rel::buildGt(updated, updated.subs(update.get<IntTheory>()));
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
    assumptions.insert(BExpression::buildTheoryLit(inc));
    if (SmtFactory::check(BExpression::buildAnd(assumptions)) != Sat) {
        return false;
    }
    assumptions.insert(BExpression::buildTheoryLit(dec));
    const auto unsatCore {SmtFactory::unsatCore(assumptions)};
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
    const auto newGuard {BExpression::buildTheoryLit(rel) & inc};
    auto idx {store(rel, dependencies, newGuard, true)};
    std::stringstream ss;
    ss << rel << " [" << idx << "]: eventual increase yields " << newGuard;
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

bool AccelerationProblem::fixpoint(const Lit &lit) {
    if (res.find(lit) != res.end()) {
        return false;
    }
    std::vector<BoolExpr> eqs;
    const auto vars {util::RelevantVariables::find(expr::variables(lit), update)};
    for (const auto& v: vars) {
        if (!config.allowDisjunctions && std::holds_alternative<BoolVar>(v)) {
            // encoding equality for booleans introduces a disjunction
            return false;
        }
        eqs.push_back(expr::mkEq(TheTheory::varToExpr(v), update.get(v)));
    }
    const auto allEq = BExpression::buildAnd(eqs);
    if (samplePoint && !allEq->subs(*samplePoint)->isTriviallyTrue()) {
        return false;
    }
    BoolExpr newGuard = allEq & lit;
    auto idx {store(lit, {}, newGuard, true)};
    std::stringstream ss;
    ss << lit << " [" << idx << "]: fixpoint yields " << newGuard;
    proof.newline();
    proof.append(ss);
    return true;
}

std::optional<AccelerationProblem::ReplacementMap> AccelerationProblem::computeReplacementMap(bool nontermOnly) const {
    ReplacementMap res;
    res.nonterm = true;
    std::map<Lit, const Entry*> entryMap;
    for (const auto& lit: todo) {
        if (depsWellFounded(lit, entryMap, nontermOnly)) {
            res.nonterm &= entryMap[lit]->nonterm;
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
    for (const auto& lit: todo) {
        if (trivial(lit)) continue;
        if (unchanged(lit)) continue;
//        if (polynomial(lit)) continue;
        auto res {recurrence(lit)};
        res |= monotonicity(lit);
        res |= eventualWeakDecrease(lit);
        if (config.approx == UnderApprox) {
            auto evInc {eventualIncrease(lit, false)};
            evInc = evInc || eventualIncrease(lit, true);
            res = res || evInc;
            res = res || fixpoint(lit);
        }
        if (!res) return ret;
    }
    auto map {computeReplacementMap(false)};
    if (!map) {
        return ret;
    }
    auto newGuard {guard->replaceLits(map->map)};
    if (closed) {
        newGuard = newGuard & *bound;
    }
    if (SmtFactory::check(newGuard) == Sat) {
        ret.term.emplace(newGuard, proof);
        ret.term->proof.newline();
        ret.term->proof.append(std::stringstream() << "Replacement map: " << map->map);
        if (map->nonterm) {
            ret.nonterm = ret.term;
        }
    }
    if (config.tryNonterm && closed && !map->nonterm) {
        map = computeReplacementMap(true);
        if (map) {
            newGuard = guard->replaceLits(map->map);
            if (SmtFactory::check(newGuard) == Sat) {
                ret.nonterm.emplace(newGuard, proof);
                ret.nonterm->proof.newline();
                ret.nonterm->proof.append(std::stringstream() << "Replacement map: " << map->map);
            }
        }
    }
    return ret;
}
