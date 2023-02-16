#include "boolexpr.hpp"

#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
#include <numeric>

Quantifier::Quantifier(const Type &qType, const std::set<NumVar> &vars, const std::map<NumVar, Expr> &lowerBounds, const std::map<NumVar, Expr> &upperBounds): qType(qType), vars(vars), lowerBounds(lowerBounds), upperBounds(upperBounds) {}

std::optional<Expr> Quantifier::lowerBound(const NumVar &x) const {
    const auto it = lowerBounds.find(x);
    if (it == lowerBounds.end()) {
        return {};
    } else {
        return it->second;
    }
}

std::optional<Expr> Quantifier::upperBound(const NumVar &x) const {
    const auto it = upperBounds.find(x);
    if (it == upperBounds.end()) {
        return {};
    } else {
        return it->second;
    }
}

Quantifier Quantifier::negation() const {
    auto _qType = qType == Type::Exists ? Type::Forall : Type::Exists;
    return Quantifier(_qType, vars, lowerBounds, upperBounds);
}

const std::set<NumVar>& Quantifier::getVars() const {
    return vars;
}

Quantifier::Type Quantifier::getType() const {
    return qType;
}

std::string Quantifier::toRedlog() const {
    std::string q = qType == Type::Exists ? "ex" : "all";
    std::string res;
    for (const auto& var: vars) {
        res = q + "(" + var.getName() + ",";
    }
    return res;
}

Quantifier Quantifier::remove(const NumVar &x) const {
    std::set<NumVar> newVars(vars);
    std::map<NumVar, Expr> newLowerBounds(lowerBounds);
    std::map<NumVar, Expr> newUpperBounds(upperBounds);
    newVars.erase(x);
    newLowerBounds.erase(x);
    newUpperBounds.erase(x);
    return Quantifier(qType, newVars, newLowerBounds, newUpperBounds);
}
