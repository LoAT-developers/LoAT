#pragma once

#include "chcproblem.hpp"
#include "chctoitsproblem.hpp"
#include "itstosafetyproblem.hpp"

class ReversibleCHCToSafety : public Reversible<SafetyProblem, Bools::Expr, CHCModel> {

    ReversibleCHCToITS to_its;
    ReversibleITSToSafety to_safety;

public:
    ReversibleCHCToSafety(
        const SafetyProblem &sp,
        const ReversibleCHCToITS &to_its,
        const ReversibleITSToSafety &to_safety);

    CHCModel revert_model(const Bools::Expr&) const override;
};

ReversibleCHCToSafety chc_to_safetyproblem(const CHCProblem &chcs);
