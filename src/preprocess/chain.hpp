#pragma once

#include "itsmodel.hpp"
#include "itscex.hpp"
#include "itsproblem.hpp"

class Chain {

private:

    ITSPtr its;

    linked_hash_set<std::tuple<LocationIdx, RulePtr, LocationIdx>> removed;

    linked_hash_map<RulePtr, std::pair<RulePtr, RulePtr>> chained;

public:

    Chain(ITSPtr its);

    ITSModel transform_model(const ITSModel &) const;

    ITSCex transform_cex(const ITSCex &) const;

    bool chainLinearPaths();
};
