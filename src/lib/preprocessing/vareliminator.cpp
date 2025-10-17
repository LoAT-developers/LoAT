#include "vareliminator.hpp"
#include "subs.hpp"

#include <cassert>

VarEliminator::VarEliminator(const Bools::Expr& guard, const Arith::Var& N, const std::function<bool(Arith::Var)> &keep): N(N), keep(keep) {
    assert(!keep(N));
    todoDeps.push({{}, guard});
    findDependencies(guard);
    eliminate();
}

void VarEliminator::findDependencies(const Bools::Expr& guard) {
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
                    if (const auto ex {rel->lhs()}; ex->isPoly(var) == 1) {
                        // we found a constraint which is linear in var, check all variables in var's coefficient
                        for (const auto coeff {*ex->coeff(var)}; const auto &x: coeff->vars()) {
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

std::vector<std::pair<ArithSubs, Bools::Expr>> VarEliminator::eliminateDependency(
    const ArithSubs& subs, const Bools::Expr& guard) const {
    VarSet vars = guard->vars();
    for (const auto & dependencie : dependencies) {
        if (!vars.contains(dependencie)) {
            continue;
        }
        const auto bounds {guard->getBounds(dependencie)};
        std::vector<std::pair<ArithSubs, Bools::Expr>> res;
        for (const auto & [bound, kind] : bounds) {
            if (bound->isInt()) {
                const auto newSubs{Subs::build<Arith>(dependencie, bound)};
                res.emplace_back(subs.compose(newSubs.get<Arith>()), guard->subs(newSubs));
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
    for (const auto & [subs, guard]: todoN) {
        auto bounds {guard->getBounds(N)};
        // if there's an equality, use it for instantiation
        const auto it {std::ranges::find_if(bounds, [](const auto &b) {
            return b.kind == BoundKind::Equality && b.bound->isIntegral();
        })};
        if (it != bounds.end()) {
            res.insert(subs.compose(ArithSubs{{N, it->bound}}));
        } else {
            for (const auto & [bound, kind] : bounds) {
                if (kind == BoundKind::Upper && bound->isIntegral()) {
                    ArithSubs p{{N, bound}};
                    res.insert(subs.compose(p));
                }
            }
        }
    }
}

linked_hash_set<ArithSubs> VarEliminator::getRes() const {
    return res;
}
