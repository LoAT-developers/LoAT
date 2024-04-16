#pragma once

#include "arithexpr.hpp"

#include <purrs.hh>

namespace Purrs = Parma_Recurrence_Relation_Solver;

namespace arith {

struct SymbolHasher {
    size_t operator()(const Purrs::Symbol &x) const {
        return std::hash<std::string>{}(x.get_name());
    }
};

struct SymbolEqual {
    bool operator()(const Purrs::Symbol &x, const Purrs::Symbol &y) const {
        return x.get_name() == y.get_name();
    }
};

using purrs_var_map = boost::bimap<boost::bimaps::unordered_set_of<ArithVarPtr>, boost::bimaps::unordered_set_of<Purrs::Symbol, SymbolHasher, SymbolEqual>>;

std::pair<Purrs::Expr, purrs_var_map> toPurrs(const ArithExprPtr e, const ArithVarPtr n);
Purrs::Expr toPurrs(const ArithExprPtr e, purrs_var_map &);
std::optional<ArithExprPtr> solveTermFor(const ArithExprPtr e, const ArithVarPtr var);
ArithExprPtr fromPurrs(const Purrs::Expr &, const purrs_var_map &);

}
