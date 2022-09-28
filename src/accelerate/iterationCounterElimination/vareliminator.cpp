#include "vareliminator.hpp"
#include "rel.hpp"

VarEliminator::VarEliminator(const BoolExpr guard, const Var &N, VariableManager &varMan): varMan(varMan), N(N) {
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
        for (const Var &var: dependencies) {
            option<Var> dep;
            for (const Rel &rel: guard->lits()) {
                const Expr &ex = (rel.lhs() - rel.rhs()).expand();
                if (ex.degree(var) == 1) {
                    // we found a constraint which is linear in var, check all variables in var's coefficient
                    const Expr &coeff = ex.coeff(var, 1);
                    for (const Var &x: coeff.vars()) {
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
    } while (changed);
    dependencies.erase(N);
}

const std::set<std::pair<Subs, BoolExpr>> VarEliminator::eliminateDependency(const Subs &subs, const BoolExpr guard) const {
    VarSet vars = guard->vars();
    for (auto it = dependencies.begin(); it != dependencies.end(); ++it) {
        if (vars.find(*it) == vars.end()) {
            continue;
        }
        Bounds bounds;
        guard->getBounds(*it, bounds);
        std::set<std::pair<Subs, BoolExpr>> res;
        for (const auto &bb: {bounds.lowerBounds, bounds.upperBounds}) {
            for (const auto &b: bb) {
                if (b.expand().isGround()) {
                    Subs newSubs(*it, b);
                    res.insert({subs.compose(newSubs), newSubs(guard)});
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
        const std::pair<Subs, BoolExpr> current = todoDeps.top();
        const std::set<std::pair<Subs, BoolExpr>> &res = eliminateDependency(current.first, current.second);
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
        const Subs &subs = p.first;
        const BoolExpr guard = p.second;
        Bounds bounds;
        guard->getBounds(N, bounds);
        if (bounds.equality) {
            res.insert(subs.compose(Subs(N, *bounds.equality)));
        } else {
            for (const Expr &b: bounds.upperBounds) {
                res.insert(subs.compose(Subs(N, b)));
            }
        }
    }
}

const std::set<Subs> VarEliminator::getRes() const {
    return res;
}
