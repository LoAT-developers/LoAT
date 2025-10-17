#pragma once

#include "itsmodel.hpp"
#include "itscpxcex.hpp"
#include "itsproblem.hpp"

class Chain {

    ITSPtr its;

    linked_hash_set<std::tuple<LocationIdx, RulePtr, LocationIdx>> removed;

    linked_hash_map<RulePtr, std::pair<RulePtr, RulePtr>> chained;

public:
    explicit Chain(ITSPtr  its);

    ITSModel transform_model(const ITSModel &) const;

    template <class CEX>
    CEX transform_cex(const CEX &cex) const {
        CEX res {cex};
        for (const auto &[c,p]: chained) {
            res.add_resolvent({p.first, p.second}, c);
        }
        return res;
    }

    bool chainLinearPaths();
};
