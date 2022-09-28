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

#include "templates.hpp"

void Templates::add(const Templates::Template &t) {
    templates.push_back(t.t);
    vars_.insert(t.vars.begin(), t.vars.end());
    params_.insert(t.params.begin(), t.params.end());
}

const VarSet& Templates::params() const {
    return params_;
}

const VarSet& Templates::vars() const {
    return vars_;
}

bool Templates::isParametric(const Expr &e) const {
    VarSet relVars = e.vars();
    for (const Var &x: params()) {
        if (relVars.count(x) > 0) {
            return true;
        }
    }
    return false;
}

const std::vector<Expr> Templates::subs(const Subs &sigma) const {
    std::vector<Expr> res;
    for (Expr e: templates) {
        res.push_back(sigma(e));
    }
    return res;
}

Templates::iterator Templates::begin() const {
    return templates.begin();
}

Templates::iterator Templates::end() const {
    return templates.end();
}

const Templates::Template Templates::buildTemplate(const VarSet &vars, VariableManager &varMan) const {
    VarSet params;
    const Var &c0 = varMan.getFreshUntrackedSymbol("c0", Expr::Int);
    params.insert(c0);
    Expr res = c0;
    for (const Var &x: vars) {
        const Var &param = varMan.getFreshUntrackedSymbol("c", Expr::Int);
        params.insert(param);
        res = res + (x * param);
    }
    return Templates::Template(res, vars, std::move(params));
}
