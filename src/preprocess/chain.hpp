#pragma once

#include "itsmodel.hpp"
#include "itsproblem.hpp"

class Chain {

private:

    ITSProblem &its;

    linked_hash_set<std::tuple<LocationIdx, Rule, LocationIdx>> predecessors;

public:

    Chain(ITSProblem &its);

    ITSModel transform_model(const ITSModel &) const;

    bool chainLinearPaths();
};
