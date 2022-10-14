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

#include <iterator>

#include "variablemanager.hpp"

class Templates {

public:

    struct Template {

        Template(Expr t, std::set<NumVar> vars, std::set<NumVar> params) :
                t(std::move(t)), vars(std::move(vars)), params(std::move(params)) {}

        const Expr t;
        const std::set<NumVar> vars;
        const std::set<NumVar> params;

    };

    typedef std::vector<Expr>::const_iterator iterator;

    void add(const Template &t);

    const std::set<NumVar>& params() const;

    const std::set<NumVar>& vars() const;

    bool isParametric(const Expr &e) const;

    const std::vector<Expr> subs(const ExprSubs &sigma) const;

    iterator begin() const;

    iterator end() const;

    const Templates::Template buildTemplate(const std::set<NumVar> &vars, VariableManager &varMan) const;

private:

    std::vector<Expr> templates;
    std::set<NumVar> params_;
    std::set<NumVar> vars_;

};
