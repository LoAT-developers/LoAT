#pragma once

#include "itsproblem.hpp"
#include "smt.hpp"
#include "itscex.hpp"

class RulePreprocessor {

private:

    ITSPtr its;
    linked_hash_map<RulePtr, RulePtr> replacements;

public:

    RulePreprocessor(const ITSPtr its);
    std::optional<SmtResult> run();
    ITSCex transform_cex(const ITSCex&) const;

};
