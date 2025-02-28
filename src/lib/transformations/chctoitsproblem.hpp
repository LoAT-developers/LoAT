#pragma once

#include "chcfwd.hpp"
#include "itsfwd.hpp"
#include "theory.hpp"
#include "arraytype.hpp"

#include <memory>
#include <unordered_map>

class ArrayType;

class CHCToITS {

private:
    CHCPtr chcs;
    ITSPtr its{std::make_shared<ITSProblem>()};
    std::unordered_map<ArrayType, std::vector<Var>> vars;
    std::unordered_map<RulePtr, ClausePtr> clause_map;
    std::unordered_map<RulePtr, Renaming> renamings;

public:
    CHCToITS(CHCPtr chcs);

    CHCModel transform_model(const ITSModel &) const;

    ClausePtr rule_to_clause(const RulePtr rule, const ClausePtr prototype) const;

    CHCCex transform_cex(const ITSSafetyCex &);

    ITSPtr transform();
};
