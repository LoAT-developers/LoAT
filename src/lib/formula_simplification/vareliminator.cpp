#include "vareliminator.hpp"
#include "subs.hpp"

#include <assert.h>

VarEliminator::VarEliminator(const Bools::Expr guard, const Arith::Var N, const std::function<bool(Arith::Var)> &keep): N(N), keep(keep) {
    assert(!keep(N));
    todoDeps.push({{}, guard});
    findDependencies(guard);
    eliminate();
}

void VarEliminator::findDependencies(const Bools::Expr guard) {
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

const std::vector<std::pair<ArithSubs, Bools::Expr>> VarEliminator::eliminateDependency(const ArithSubs &subs, const Bools::Expr guard) const {
    VarSet vars = guard->vars();
    for (auto it = dependencies.begin(); it != dependencies.end(); ++it) {
        if (!vars.contains(*it)) {
            continue;
        }
        const auto bounds {guard->getBounds(*it)};
        std::vector<std::pair<ArithSubs, Bools::Expr>> res;
        for (const auto &b : bounds) {
            if (b.bound->isInt()) {
                const auto newSubs{Subs::build<Arith>(*it, b.bound)};
                res.push_back({subs.compose(newSubs.get<Arith>()), newSubs(guard)});
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
        const std::pair<ArithSubs, Bools::Expr> current = todoDeps.top();
        const std::vector<std::pair<ArithSubs, Bools::Expr>> &res = eliminateDependency(current.first, current.second);
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
        auto bounds {guard->getBounds(N)};
        // if there's an equality, use it for instantiation
        const auto it {std::find_if(bounds.begin(), bounds.end(), [](const auto &b) {
            return b.kind == BoundKind::Equality && b.bound->isIntegral();
        })};
        if (it != bounds.end()) {
            res.insert(subs.compose(ArithSubs{{N, it->bound}}));
        } else {
            for (const auto &b : bounds) {
                if (b.kind == BoundKind::Upper && b.bound->isIntegral()) {
                    ArithSubs p{{N, b.bound}};
                    res.insert(subs.compose(p));
                }
            }
        }
    }
}

const linked_hash_set<ArithSubs> VarEliminator::getRes() const {
    return res;
}
