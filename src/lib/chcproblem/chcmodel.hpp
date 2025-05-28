#pragma once

#include "theory.hpp"
#include "chcproblem.hpp"
#include "sexpresso.hpp"

class CHCModel {

    friend std::ostream& operator<<(std::ostream &s, const CHCModel &m);

    linked_hash_map<std::string, std::pair<std::vector<Var>, Bools::Expr>> interpretations;

public:

    void set_interpretation(const std::string &f, const std::vector<Var> &args, const Bools::Expr interp);
    const linked_hash_map<std::string, std::pair<std::vector<Var>, Bools::Expr>> get_interpretations() const;
    sexpresso::Sexp to_smtlib() const;

};