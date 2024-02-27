#include "vareliminator.hpp"
#include "arithlit.hpp"

#include <assert.h>

VarEliminator::VarEliminator(const BoolExpr guard, const Arith::Var N, const std::function<bool(Arith::Var)> &keep): N(N), keep(keep) {
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
        for (const Arith::Var &var: dependencies) {
            std::optional<Arith::Var> dep;
            for (const auto &lit: guard->lits()) {
                if (std::holds_alternative<Arith::Lit>(lit)) {
                    const auto &rel {std::get<Arith::Lit>(lit)};
                    const auto ex {rel.lhs()};
                    if (ex->isPoly(var) == 1) {
                        // we found a constraint which is linear in var, check all variables in var's coefficient
                        const auto coeff {*ex->coeff(var)};
                        for (const auto &x: coeff->vars()) {
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

const std::vector<std::pair<ArithSubs, BoolExpr>> VarEliminator::eliminateDependency(const ArithSubs &subs, const BoolExpr guard) const {
    VarSet vars = guard->vars();
    for (auto it = dependencies.begin(); it != dependencies.end(); ++it) {
        if (!vars.contains(*it)) {
            continue;
        }
        const auto bounds {guard->getBounds(*it)};
        std::vector<std::pair<ArithSubs, BoolExpr>> res;
        for (const auto &bb: {bounds.lowerBounds, bounds.upperBounds}) {
            for (const auto &b: bb) {
                if (b->isRational()) {
                    const auto newSubs {Subs::build<Arith>(*it, b)};
                    res.push_back({subs.compose(newSubs.get<Arith>()), guard->subs(newSubs)});
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
        const std::pair<ArithSubs, BoolExpr> current = todoDeps.top();
        const std::vector<std::pair<ArithSubs, BoolExpr>> &res = eliminateDependency(current.first, current.second);
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
        const auto &subs {p.first};
        const auto guard {p.second};
        auto done {false};
        auto bounds {guard->getBounds(N)};
        for (auto it = bounds.upperBounds.begin(); it != bounds.upperBounds.end();) {
            if (bounds.lowerBounds.contains(*it)) {
                res.insert(subs.compose(ArithSubs{{N, *it}}));
                done = true;
                break;
            }
            bool removed = false;
            for (auto it2 = std::next(it); it2 != bounds.upperBounds.end();) {
                const auto diff {(*it - *it2)->isRational()};
                if (diff) {
                    if (*diff > 0) {
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
        if (!done) {
            for (const auto &b: bounds.upperBounds) {
                ArithSubs p{{N, b}};
                res.insert(subs.compose(p));
            }
        }
    }
}

const linked_hash_set<ArithSubs> VarEliminator::getRes() const {
    return res;
}
