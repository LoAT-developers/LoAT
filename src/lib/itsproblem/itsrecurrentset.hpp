#pragma once

#include "itsproblem.hpp"

class ITSRecurrentSet {

    std::unordered_map<LocationIdx, BoolExprSet> m_map;
    linked_hash_set<RulePtr> m_rules;

public:

    void add(LocationIdx, const BoolExprSet&);
    void add(LocationIdx, Bools::Expr);
    void add(RulePtr);
    BoolExprSet& get(LocationIdx);
    void simplify();
    const linked_hash_set<RulePtr>& rules() const;

};
