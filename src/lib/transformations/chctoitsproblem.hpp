#pragma once

#include "chcmodel.hpp"
#include "chccex.hpp"
#include "itscex.hpp"
#include "chcproblem.hpp"
#include "itsmodel.hpp"
#include "itsproblem.hpp"

class CHCToITS {

private:

    CHCPtr chcs;
    ITSPtr its {std::make_shared<ITSProblem>()};
    std::vector<Arith::Var> vars;
    std::vector<Bools::Var> bvars;
    std::unordered_map<RulePtr, ClausePtr> clause_map;

public:
    CHCToITS(CHCPtr chcs);

    CHCModel transform_model(const ITSModel &) const;

    ClausePtr rule_to_clause(const RulePtr rule, const ClausePtr prototype) const;

    CHCCex transform_cex(const ITSCex &);

    ITSPtr transform();
};
