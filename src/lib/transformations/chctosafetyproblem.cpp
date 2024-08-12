#include "chctosafetyproblem.hpp"
#include "chctoitsproblem.hpp"
#include "itstosafetyproblem.hpp"

ReversibleCHCToSafety::ReversibleCHCToSafety(
    const SafetyProblem &sp,
    const ReversibleCHCToITS &to_its,
    const ReversibleITSToSafety &to_safety) : Reversible<SafetyProblem, Bools::Expr, CHCModel>(sp), to_its(to_its), to_safety(to_safety) {}

CHCModel ReversibleCHCToSafety::revert_model(const Bools::Expr &e) const {
    return to_its.revert_model(to_safety.revert_model(e));
}

ReversibleCHCToSafety chc_to_safetyproblem(const CHCProblem &chcs) {
    const auto r1{chcs_to_its(chcs)};
    const auto r2{its_to_safetyproblem(*r1)};
    return ReversibleCHCToSafety(*r2, r1, r2);
}
