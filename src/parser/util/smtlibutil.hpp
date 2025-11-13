#pragma once

#include "theory.hpp"

struct SMTLibParsingState {
    std::vector<Arrays<Arith>::Var> arith_vars;
    std::vector<Bools::Var> bool_vars;
    std::vector<Arrays<Arith>::Var> arr_vars;
    size_t next_arith_var {0};
    size_t next_bool_var {0};
    size_t next_arr_var {0};
    std::vector<Arrays<Arith>::Var> tmp_arith_vars;
    std::vector<Bools::Var> tmp_bool_vars;
    std::vector<Arrays<Arith>::Var> tmp_arr_vars;
    size_t next_tmp_arith_var {0};
    size_t next_tmp_bool_var {0};
    size_t next_tmp_arr_var {0};
    std::unordered_map<std::string, Var> vars;
    std::vector<Bools::Expr> refinement;
    std::vector<std::unordered_map<std::string, Expr>> bindings;

    Var get_var(const std::string &name, theory::Type type);
    void clear();

};

Expr parseExpr(sexpresso::Sexp &exp, SMTLibParsingState &state);

Bools::Expr parseBoolExpr(sexpresso::Sexp &exp, SMTLibParsingState &state);

Arith::Expr parseArithExpr(sexpresso::Sexp &exp, SMTLibParsingState &state);