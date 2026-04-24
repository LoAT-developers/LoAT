#pragma once

#include "itsproblem.hpp"
#include "smt.hpp"
#include "itssafetycex.hpp"

class RulePreprocessor {

    ITSPtr its;
    std::vector<linked_hash_map<RulePtr, RulePtr>> replacements;

public:
    explicit RulePreprocessor(ITSPtr its);
    std::optional<SmtResult> run();

    template <class CEX>
    CEX transform_cex(const CEX &cex) const {
        auto res = cex;
        for (auto it = replacements.rbegin(); it != replacements.rend(); ++it) {
            res = cex.replace_rules(*it);
        }
        return res;
    }

};
