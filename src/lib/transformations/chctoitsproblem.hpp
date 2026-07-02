#pragma once

#include "chcmodel.hpp"
#include "chccex.hpp"
#include "itssafetycex.hpp"
#include "chcproblem.hpp"
#include "itsmodel.hpp"
#include "itsproblem.hpp"

class CHCToITS {

    CHCPtr chcs;
    ITSPtr its {std::make_shared<ITSProblem>()};
    std::vector<ArithVarPtr> vars;
    std::unordered_map<size_t, std::vector<Arrays<Arith>::Var>> avars;
    std::vector<Bools::Var> bvars;
    std::unordered_map<RulePtr, ClausePtr> clause_map;
    std::unordered_map<RulePtr, Renaming> renamings;
    std::unordered_map<std::string, LocationIdx> loc_map;
    std::unordered_map<LocationIdx, std::string> rev_loc_map;
    static const LocationIdx init_loc;
    static const LocationIdx err_loc;
    LocationIdx next_loc = 2;

public:
    explicit CHCToITS(CHCPtr  chcs);

    CHCModel transform_model(const ITSModel &);

    ClausePtr rule_to_clause(const RulePtr& rule, const ClausePtr& prototype) const;

    CHCCex transform_cex(const ITSSafetyCex &);

    ITSPtr transform();
};
