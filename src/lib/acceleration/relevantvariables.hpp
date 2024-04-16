/*  This file is part of LoAT.
 *  Copyright (c) 2019 Florian Frohn
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses>.
 */

#pragma once

#include "theory.hpp"

namespace util {

    class RelevantVariables {

    public:

        static VarSet find(
                const VarSet &varsOfInterest,
                const Subs &up) {
            VarSet res = varsOfInterest;
            // Compute the closure of res under all updates and the guard
            VarSet todo = res;
            while (!todo.empty()) {
                VarSet next;
                for (const auto &x : todo) {
                    std::visit([&up, &next](const auto &x) {
                        const auto val {up.get(x)};
                        if (val != theory::toExpr(x)) {
                            theory::collectVars(val, next);
                        }
                    }, x);
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
            VarSet symbols;
            for (const auto &x: res) {
                symbols.insert(x);
            }
            return symbols;
        }

    };

}
