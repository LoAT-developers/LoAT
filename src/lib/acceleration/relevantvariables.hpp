#pragma once

#include "theory.hpp"

namespace util {

    class RelevantVariables {

    public:

        static CellSet find(
                const CellSet &varsOfInterest,
                const Subs &up) {
            CellSet res = varsOfInterest;
            // Compute the closure of res under all updates and the guard
            CellSet todo = res;
            while (!todo.empty()) {
                CellSet next;
                for (const auto& x : todo) {
                    theory::apply(
                        x,
                        [&](const auto& x) {
                            using T = decltype(theory::theory(x));
                            if (const auto val{x->subs(up)}; val != T::cellToExpr(x)) {
                                val->collectCells(next);
                            }
                        });
                }
                todo.clear();
                for (const auto &var : next) {
                    if (!res.contains(var)) {
                        todo.insert(var);
                    }
                }
                // collect all variables from every iteration
                res.insertAll(todo);
            }
            return res;
        }

    };

}
