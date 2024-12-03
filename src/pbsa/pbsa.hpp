#pragma once

#include "itstosafetyproblem.hpp"
#include "stepwise.hpp"
#include "trp.hpp"
#include "smtfactory.hpp"

class PBSA: public StepwiseAnalysis {

    ITSToSafety its_to_safety;
    SafetyProblem t;
    Bools::Expr reachable;
    Bools::Expr step {top()};
    linked_hash_map<Int, Bools::Expr> transitions;
    Renaming pre_to_intermediate;
    Renaming intermediate_to_pre;
    Renaming intermediate_to_post;
    Renaming post_to_intermediate;
    Renaming post_to_pre;
    TRP trp;
    Arith::Var trace_var {ArithVar::next()};
    SmtPtr solver{SmtFactory::modelBuildingSolver(Logic::QF_LA)};

public:

    PBSA(const ITSPtr its);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;
    ITSSafetyCex get_cex() override;

};