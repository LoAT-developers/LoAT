#include "vareliminator.hpp"
#include "rel.hpp"

#include <assert.h>

VarEliminator::VarEliminator(const BoolExpr guard, const NumVar &N, const std::function<bool(NumVar)> &keep): N(N), keep(keep) {
    assert(!keep(N));
    todoDeps.push({{}, guard});
    findDependencies(guard);
    eliminate();
}

void VarEliminator::findDependencies(const BoolExpr guard) {
    dependencies.insert(N);
    bool changed;
    do {
        changed = false;
        // compute dependencies of var
        for (const NumVar &var: dependencies) {
            std::optional<NumVar> dep;
            for (const Lit &lit: guard->lits()) {
                if (std::holds_alternative<Rel>(lit)) {
                    const Rel &rel = std::get<Rel>(lit);
                    const Expr &ex = (rel.lhs() - rel.rhs()).expand();
                    if (ex.degree(var) == 1) {
                        // we found a constraint which is linear in var, check all variables in var's coefficient
                        const Expr &coeff = ex.coeff(var, 1);
                        for (const NumVar &x: coeff.vars()) {
                            if (!keep(x)) {
                                if (!dependencies.contains(x)) {
                                    // we found a tmp variable in coeff which has not yet been marked as dependency
                                    dep = x;
                                }
                            } else {
                                // coeff also contains non-tmp variables, ignore the current constraint
                                dep = {};
                                break;
                            }
                        }
                        if (dep) {
                            dependencies.insert(*dep);
                            changed = true;
                        }
                    }
                }
            }
        }
    } while (changed);
    dependencies.erase(N);
}

const std::vector<std::pair<ExprSubs, BoolExpr>> VarEliminator::eliminateDependency(const ExprSubs &subs, const BoolExpr guard) const {
    VarSet vars = guard->vars();
    for (auto it = dependencies.begin(); it != dependencies.end(); ++it) {
        if (!vars.contains(*it)) {
            continue;
        }
        Bounds bounds;
        guard->getBounds(*it, bounds);
        std::vector<std::pair<ExprSubs, BoolExpr>> res;
        for (const auto &bb: {bounds.lowerBounds, bounds.upperBounds}) {
            for (const auto &b: bb) {
                if (b.expand().isGround()) {
                    Subs newSubs = Subs::build<IntTheory>(*it, b);
                    res.push_back({subs.compose(newSubs.get<IntTheory>()), guard->subs(newSubs)});
                }
            }
        }
        if (!res.empty()) {
            return res;
        }
    }
    return {};
}

void VarEliminator::eliminateDependencies() {
    while (!todoDeps.empty()) {
        const std::pair<ExprSubs, BoolExpr> current = todoDeps.top();
        const std::vector<std::pair<ExprSubs, BoolExpr>> &res = eliminateDependency(current.first, current.second);
        if (res.empty()) {
            todoN.push_back(current);
        }
        todoDeps.pop();
        for (const auto &p: res) {
            todoDeps.push(p);
        }
    }
}

void VarEliminator::eliminate() {
    eliminateDependencies();
    for (const auto &p: todoN) {
        const ExprSubs &subs = p.first;
        const BoolExpr guard = p.second;
        Bounds bounds;
        guard->getBounds(N, bounds);
        if (bounds.equality) {
            ExprSubs p{{N, *bounds.equality}};
            res.insert(subs.compose(p));
        } else {
            for (auto it = bounds.upperBounds.begin(); it != bounds.upperBounds.end();) {
                bool removed = false;
                for (auto it2 = std::next(it); it2 != bounds.upperBounds.end();) {
                    const auto diff = (*it - *it2).expand();
                    if (diff.isRationalConstant()) {
                        if (diff.toNum().is_positive()) {
                            it = bounds.upperBounds.erase(it);
                            removed = true;
                            break;
                        } else {
                            it2 = bounds.upperBounds.erase(it2);
                        }
                    } else {
                        ++it2;
                    }
                }
                if (!removed) {
                    ++it;
                }
            }
            for (const Expr &b: bounds.upperBounds) {
                ExprSubs p{{N, b}};
                res.insert(subs.compose(p));
            }
        }
    }
}

const linked_hash_set<ExprSubs> VarEliminator::getRes() const {
    return res;
}
