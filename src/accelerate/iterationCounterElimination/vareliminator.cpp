#include "vareliminator.hpp"
#include "rel.hpp"

VarEliminator::VarEliminator(const BoolExpr guard, const NumVar &N, VariableManager &varMan): varMan(varMan), N(N) {
    assert(varMan.isTempVar(N));
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
            option<NumVar> dep;
            for (const Lit &lit: guard->lits()) {
                if (std::holds_alternative<Rel>(lit)) {
                    const Rel &rel = std::get<Rel>(lit);
                    const Expr &ex = (rel.lhs() - rel.rhs()).expand();
                    if (ex.degree(var) == 1) {
                        // we found a constraint which is linear in var, check all variables in var's coefficient
                        const Expr &coeff = ex.coeff(var, 1);
                        for (const NumVar &x: coeff.vars()) {
                            if (varMan.isTempVar(x)) {
                                if (dependencies.find(x) == dependencies.end()) {
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
                            dependencies.insert(dep.get());
                            changed = true;
                        }
                    }
                }
            }
        }
    } while (changed);
    dependencies.erase(N);
}

const std::set<std::pair<VarEliminator::IntSubs, BoolExpr>> VarEliminator::eliminateDependency(const IntSubs &subs, const BoolExpr guard) const {
    VarSet vars = guard->vars();
    for (auto it = dependencies.begin(); it != dependencies.end(); ++it) {
        if (vars.find(*it) == vars.end()) {
            continue;
        }
        Bounds bounds;
        guard->getBounds(*it, bounds);
        std::set<std::pair<IntSubs, BoolExpr>> res;
        for (const auto &bb: {bounds.lowerBounds, bounds.upperBounds}) {
            for (const auto &b: bb) {
                if (b.expand().isGround()) {
                    IntSubs::Pair p = std::pair<NumVar, Expr>(*it, b);
                    IntSubs newSubs(p);
                    res.insert({subs.compose(newSubs), newSubs.subs(guard)});
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
        const std::pair<IntSubs, BoolExpr> current = todoDeps.top();
        const std::set<std::pair<IntSubs, BoolExpr>> &res = eliminateDependency(current.first, current.second);
        if (res.empty()) {
            todoN.insert(current);
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
        const IntSubs &subs = p.first;
        const BoolExpr guard = p.second;
        Bounds bounds;
        guard->getBounds(N, bounds);
        if (bounds.equality) {
            IntSubs::Pair p = std::pair<NumVar, Expr>(N, *bounds.equality);
            res.insert(subs.compose(IntSubs(p)));
        } else {
            for (const Expr &b: bounds.upperBounds) {
                IntSubs::Pair p = std::pair<NumVar, Expr>(N, b);
                res.insert(subs.compose(IntSubs(p)));
            }
        }
    }
}

const std::set<VarEliminator::IntSubs> VarEliminator::getRes() const {
    return res;
}
