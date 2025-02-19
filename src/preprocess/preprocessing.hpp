#pragma once

#include "itsproblem.hpp"
#include "itsmodel.hpp"
#include "itssafetycex.hpp"
#include "smt.hpp"
#include "chain.hpp"
#include "rulepreprocessor.hpp"

class Preprocessor {

private:
    bool success{false};

    SmtResult status{SmtResult::Unknown};

    ITSPtr its;

    Chain chain;

    RulePreprocessor rule_preproc;

    ITSSafetyCex cex;

public:
    Preprocessor(ITSPtr its);

    ITSModel transform_model(const ITSModel &) const;

    template <class CEX>
    CEX transform_cex(const CEX &cex) const {
        auto transformed {chain.transform_cex(cex)};
        transformed = rule_preproc.transform_cex(transformed);
        return transformed;
    }

    SmtResult preprocess();

    bool successful() const;

    ITSModel get_model() const;

    const ITSSafetyCex& get_cex() const;

    std::optional<SmtResult> check_empty_clauses(ITSPtr its);

};
