#pragma once

#include "itsproblem.hpp"
#include "safetyproblem.hpp"
#include "itsmodel.hpp"
#include "safetycex.hpp"
#include "itssafetycex.hpp"
#include "formulapreprocessing.hpp"

class ITSToSafety {

    const ITSPtr its;
    std::unordered_map<Bools::Expr, RulePtr> rev_map;
    std::unordered_map<Bools::Expr, RulePtr> rev_init_map;
    std::unordered_map<Bools::Expr, RulePtr> rev_err_map;
    Renaming post_to_pre;

public:
    explicit ITSToSafety(ITSPtr  its);

    static Bools::Expr rule_to_formula(const RulePtr& r, const VarSet &prog_vars);

    ITSModel transform_model(const Bools::Expr&) const;

    ITSSafetyCex transform_cex(const SafetyCex &) const;

    SafetyProblem transform();

};
