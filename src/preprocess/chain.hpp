#pragma once

#include "itsmodel.hpp"
#include "itsproblem.hpp"

class Chain {

private:

    ITSPtr its;

    linked_hash_set<std::tuple<LocationIdx, RulePtr, LocationIdx>> predecessors;

public:

    Chain(ITSPtr its);

    ITSModel transform_model(const ITSModel &) const;

    bool chainLinearPaths();
};
