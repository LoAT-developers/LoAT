#pragma once

#include "chcmodel.hpp"
#include "chcproblem.hpp"
#include "itsmodel.hpp"
#include "itsproblem.hpp"
#include "reversible.hpp"

class ReversibleCHCToITS : public Reversible<ITSPtr, ITSModel, CHCModel> {

    const linked_hash_map<std::string, std::vector<Var>> signature;
    const std::vector<Arith::Var> arith_vars;
    const std::vector<Bools::Var> bool_vars;

public:
    ReversibleCHCToITS(
        const ITSPtr its,
        const linked_hash_map<std::string, std::vector<Var>> &signature,
        const std::vector<Arith::Var> &arith_vars,
        const std::vector<Bools::Var> &bool_vars);

    CHCModel revert_model(const ITSModel &) const override;
};

ReversibleCHCToITS chcs_to_its(CHCProblem chcs);
