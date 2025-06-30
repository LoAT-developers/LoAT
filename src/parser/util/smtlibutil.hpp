#pragma once

#include "theory.hpp"

struct SMTLibParsingState {
    std::unordered_map<std::string, Var> vars;
    std::vector<Bools::Expr> refinement;
    std::vector<std::unordered_map<std::string, Expr>> bindings;
};

Expr parseExpr(sexpresso::Sexp &exp, SMTLibParsingState &state);

Bools::Expr parseBoolExpr(sexpresso::Sexp &exp, SMTLibParsingState &state);

Arith::Expr parseArithExpr(sexpresso::Sexp &exp, SMTLibParsingState &state);