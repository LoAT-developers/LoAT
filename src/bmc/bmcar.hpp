#pragma once

#include "itsproblem.hpp"
#include "smtfactory.hpp"
#include "itstosafetyproblem.hpp"

class BMCAR {

    std::optional<ITSToSafety> to_safety;
    SafetyProblem sp;
    Bools::Expr init;
    Bools::Expr err;
    Bools::Expr step;
    Bools::Expr abstraction = bot();
    SmtPtr solver;
    VarSet vars;
    Renaming pre_to_post {};
    unsigned depth {0};
    std::vector<Renaming> renamings;
    Renaming two_steps;

    Int next_id = 0;
    ArithVarPtr id_var = arrays::nextConst<Arith>();
    std::unordered_map<Int, BoolExprSet> transitions;
    std::unordered_map<Int, BoolExprSet> abstractions;
    ArithVarPtr loc_var;
    BoolExprSet learned;
    unsigned completeness_threshold = 0;

    void build_abstraction();
    void restart();
    bool sample();
    bool is_transitive();
    SmtResult refine();
    Renaming get_renaming(unsigned);
    Bools::Expr encode_transition(Bools::Expr trans, Int id) const;
    SafetyProblem build_approx_sp();
    void initialize();

public:
    explicit BMCAR(const ITSPtr& its);
    explicit BMCAR(const SafetyProblem&, ArithVarPtr);
    SmtResult analyze();

};
