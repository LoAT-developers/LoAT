#pragma once

#include "itsproblem.hpp"
#include "safetyproblem.hpp"
#include "itsmodel.hpp"
#include "safetycex.hpp"
#include "itssafetycex.hpp"
#include "formulapreprocessing.hpp"
#include "safetymodel.hpp"

class ITSToSafety {

    const ITSPtr its;
    std::unordered_map<Bools::Expr, RulePtr> rev_map;
    std::unordered_map<Bools::Expr, RulePtr> rev_init_map;
    std::unordered_map<Bools::Expr, RulePtr> rev_err_map;
    Renaming post_to_pre;
    VarSet prog_vars;

public:
    explicit ITSToSafety(ITSPtr its);

    Bools::Expr rule_to_formula(const RulePtr& r);

    RulePtr formula_to_rule(const Bools::Expr&);

    ITSSafetyCex transform_cex(const SafetyCex &) const;

    SafetyProblem transform();

};
