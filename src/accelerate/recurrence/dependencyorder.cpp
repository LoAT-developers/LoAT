#include "dependencyorder.hpp"

namespace DependencyOrder {

struct PartialResult {
    std::vector<Var> ordering; // might not contain all variables (hence partial)
    VarSet ordered; // set of all variables occurring in ordering
};

/**
 * The core implementation.
 * Successively adds variables to the ordering for which all dependencies are
 * already ordered. Stops if this is no longer possible (we are either done
 * or there are conflicting variables depending on each other).
 */
static void findOrderUntilConflicting(const Subs &update, PartialResult &res) {
    bool changed = true;

    while (changed && res.ordering.size() < update.size()) {
        changed = false;

        for (const auto &up : update) {
            const auto var = substitution::first(up);
            const auto expr = substitution::second(up);
            if (res.ordered.find(var) != res.ordered.end()) continue;

            //check if all variables on update rhs are already processed
            bool ready = true;
            for (const auto &x : expression::variables(expr)) {
                if (x != var && update.contains(x) && res.ordered.find(x) == res.ordered.end()) {
                    ready = false;
                    break;
                }
            }

            if (ready) {
                res.ordered.insert(var);
                res.ordering.push_back(var);
                changed = true;
            }
        }
    }
}

std::optional<std::vector<Var>> findOrder(const Subs &update) {
    PartialResult res;
    findOrderUntilConflicting(update, res);

    if (res.ordering.size() == update.size()) {
        return res.ordering;
    }

    return {};
}

}
