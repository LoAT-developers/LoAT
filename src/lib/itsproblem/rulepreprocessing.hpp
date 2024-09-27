#pragma once

#include "rule.hpp"
#include "itscex.hpp"

class SingleRulePreprocessor {

private:

    RulePtr propagateEquivalences(const RulePtr &rule);
    RulePtr propagateEqualities(const RulePtr &rule);
    RulePtr eliminateArithVars(const RulePtr &rule);
    RulePtr integerFourierMotzkin(const RulePtr &rule);

public:

    RulePtr run(const RulePtr &rule);

};

namespace Preprocess {

    RulePtr chain(const std::vector<RulePtr> &);

}
