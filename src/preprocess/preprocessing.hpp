#pragma once

#include "itsproblem.hpp"
#include "itsmodel.hpp"
#include "itssafetycex.hpp"
#include "smt.hpp"
#include "chain.hpp"
#include "rulepreprocessor.hpp"

class Preprocessor {

    bool success{false};

    SmtResult status{SmtResult::Unknown};

    ITSPtr its;

    Chain chain;

    RulePreprocessor rule_preproc;

    ITSSafetyCex cex;

    std::vector<std::pair<RulePtr, std::vector<RulePtr>>> unrolled;

public:
    explicit Preprocessor(const ITSPtr& its);

    ITSModel transform_model(const ITSModel &) const;

    template <class CEX>
    CEX transform_cex(const CEX &cex) const {
        CEX transformed = cex;
        for (const auto &[resolvent, rules]: unrolled | std::views::reverse) {
            transformed.add_resolvent(rules, resolvent);
        }
        transformed = chain.transform_cex(transformed);
        transformed = rule_preproc.transform_cex(transformed);
        return transformed;
    }

    SmtResult preprocess();

    bool successful() const;

    ITSModel get_model() const;

    const ITSSafetyCex& get_cex() const;

    std::optional<SmtResult> check_empty_clauses(const ITSPtr& its);

    bool unroll(const ITSPtr& its);

};
