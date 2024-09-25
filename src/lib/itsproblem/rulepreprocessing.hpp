#pragma once

#include "rule.hpp"
#include "itscex.hpp"

class SingleRulePreprocessor {

private:

    Subs equiv;

    RulePtr propagateEquivalences(const RulePtr &rule);
    RulePtr propagateEqualities(const RulePtr &rule);
    RulePtr eliminateArithVars(const RulePtr &rule);
    RulePtr integerFourierMotzkin(const RulePtr &rule);

public:

    RulePtr run(const RulePtr &rule);
    const Subs& get_subs() const;

};

namespace Preprocess {

    RulePtr chain(const std::vector<RulePtr> &);

}
