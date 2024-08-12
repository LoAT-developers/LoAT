#pragma once

#include "itsproblem.hpp"
#include "safetyproblem.hpp"
#include "reversible.hpp"
#include "itsmodel.hpp"

class ReversibleITSToSafety : public Reversible<SafetyProblem, Bools::Expr, ITSModel> {

    const linked_hash_set<LocationIdx> locations;
    const Arith::Var loc_var;

public:
    ReversibleITSToSafety(
        const SafetyProblem &sp,
        const linked_hash_set<LocationIdx> &locations,
        const Arith::Var &loc_var);

    ITSModel revert_model(const Bools::Expr&) const override;
};

ReversibleITSToSafety its_to_safetyproblem(const ITSPtr its);