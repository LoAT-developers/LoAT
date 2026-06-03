#pragma once

#include "chcproblem.hpp"

class RecurrentSet {

    friend std::ostream& operator<<(std::ostream & lhs, const RecurrentSet & res);

    std::unordered_map<std::string, std::pair<FunAppPtr, BoolExprSet>> map;
    linked_hash_set<ClausePtr> clauses;

public:

    void add(const FunAppPtr&, const BoolExprSet&);
    void add(const FunAppPtr&, const Bools::Expr&);
    void add(const ClausePtr&);
    std::pair<FunAppPtr, BoolExprSet>& get(const FunAppPtr&);
    void simplify();
    sexpresso::Sexp to_certificate() const;

};