#pragma once

#include "itsproblem.hpp"
#include "reversible.hpp"
#include "itsmodel.hpp"

namespace Preprocess {

using ReversiblePreprocessing = Reversible<bool, ITSModel, ITSModel>;

class ReversibleChaining: public ReversiblePreprocessing {

private:

    const linked_hash_set<std::tuple<LocationIdx, Rule, LocationIdx>> predecessors;

public:

    ReversibleChaining(const linked_hash_set<std::tuple<LocationIdx, Rule, LocationIdx>> &predecessors);
    ITSModel revert_model(const ITSModel&) const override;

};

    ReversibleChaining chainLinearPaths(ITSProblem &its);

}