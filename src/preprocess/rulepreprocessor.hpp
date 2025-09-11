#pragma once

#include "itsproblem.hpp"
#include "smt.hpp"
#include "itssafetycex.hpp"

class RulePreprocessor {

    ITSPtr its;
    linked_hash_map<RulePtr, RulePtr> replacements;

public:
    explicit RulePreprocessor(const ITSPtr& its);
    std::optional<SmtResult> run();

    template <class CEX>
    CEX transform_cex(const CEX &cex) const {
        return cex.replace_rules(replacements);
    }

};
