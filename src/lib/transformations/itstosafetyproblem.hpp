#pragma once

#include "itsproblem.hpp"
#include "safetyproblem.hpp"
#include "itsmodel.hpp"
#include "safetycex.hpp"
#include "itscex.hpp"
#include "formulapreprocessing.hpp"

class ITSToSafety {

private:

    const ITSPtr its;
    std::unordered_map<Bools::Expr, RulePtr> rev_map;
    Renaming init_map;

public:

    ITSToSafety(const ITSPtr its);

    Bools::Expr rule_to_formula(const RulePtr r, const VarSet &prog_vars);

    ITSModel transform_model(const Bools::Expr&) const;

    ITSCex transform_cex(const SafetyCex &) const;

    SafetyProblem transform();

};
