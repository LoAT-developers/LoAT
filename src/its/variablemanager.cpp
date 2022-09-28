/*  This file is part of LoAT.
 *  Copyright (c) 2015-2016 Matthias Naaf, RWTH Aachen University, Germany
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

#include "variablemanager.hpp"

using namespace std;


std::recursive_mutex VariableManager::mutex;

bool VariableManager::isTempVar(const Var &var) const {
    std::lock_guard guard(mutex);
    return temporaryVariables.count(var) > 0;
}

Var VariableManager::addFreshVariable(string basename) {
    std::lock_guard guard(mutex);
    return addVariable(getFreshName(basename));
}

Var VariableManager::addFreshTemporaryVariable(string basename) {
    std::lock_guard guard(mutex);
    Var x = addVariable(getFreshName(basename));
    temporaryVariables.insert(x);
    return x;
}

Var VariableManager::getFreshUntrackedSymbol(string basename, Expr::Type type) {
    std::lock_guard guard(mutex);
    Var res(getFreshName(basename));
    variableNameLookup.emplace(res.get_name(), res);
    untrackedVariables[res] = type;
    return res;
}

void toLower(string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

Var VariableManager::addVariable(string name) {
    std::lock_guard guard(mutex);
    toLower(name);
    auto sym = Var(name);

    // remember variable
    if (basenameCount.count(name) == 0) {
        basenameCount.emplace(name, 0);
    }
    variables.insert(sym);
    variableNameLookup.emplace(name, sym);

    return sym;
}

string VariableManager::getFreshName(string basename) {
    std::lock_guard guard(mutex);
    toLower(basename);
    if (basenameCount.count(basename) == 0) {
        basenameCount.emplace(basename, 0);
        return basename;
    } else {
        unsigned int count = basenameCount.at(basename);
        std::string res = basename + to_string(count);
        while (variableNameLookup.count(res) != 0) {
            ++count;
            res = basename + to_string(count);
        }
        basenameCount[basename] = count + 1;
        return res;
    }
}

const VarSet &VariableManager::getTempVars() const {
    std::lock_guard guard(mutex);
    return temporaryVariables;
}

VarSet VariableManager::getVars() const {
    std::lock_guard guard(mutex);
    return variables;
}

option<Var> VariableManager::getVar(std::string name) const {
    std::lock_guard guard(mutex);
    toLower(name);
    auto it = variableNameLookup.find(name);
    if (it == variableNameLookup.end()) {
        return {};
    } else {
        return it->second;
    }
}

Expr::Type VariableManager::getType(const Var &x) const {
    std::lock_guard guard(mutex);
    if (untrackedVariables.find(x) != untrackedVariables.end()) {
        return untrackedVariables.at(x);
    } else {
        return Expr::Int;
    }
}

