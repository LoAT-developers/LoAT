#pragma once

#include "itsproblem.hpp"
#include "smtfactory.hpp"
#include "itsmodel.hpp"
#include "itssafetycex.hpp"
#include "itstosafetyproblem.hpp"

class BMC {

    enum class Winner {
        BMC, BKIND, KIND
    };

    ITSToSafety to_safety;
    SafetyProblem sp;
    Bools::Expr init;
    Bools::Expr err;
    Bools::Expr step;
    Bools::Expr abstraction;
    SmtPtr solver;
    SmtPtr kind;
    SmtPtr bkind;
    VarSet vars;
    Renaming pre_to_post {};
    unsigned depth {0};
    std::vector<Renaming> renamings;
    Renaming two_steps;
    bool do_kind;
    Winner winner {Winner::BMC};

    Int next_id = 0;
    ArithVarPtr id_var = arrays::nextConst<Arith>();
    std::unordered_map<Int, BoolExprSet> transitions;
    std::unordered_map<Int, BoolExprSet> abstractions;

    void restart();
    bool sample();
    bool is_transitive();
    SmtResult refine();
    Renaming get_renaming(unsigned);
    Bools::Expr encode_transition(Bools::Expr trans, Int id);
    ITSPtr build_approx_its();

public:
    explicit BMC(const ITSPtr& its, bool do_kind = true);
    SmtResult analyze();
    ITSModel get_model() const;
    ITSSafetyCex get_cex() const;

};
