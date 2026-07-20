#pragma once

#include "formulapreprocessing.hpp"
#include "itscex.hpp"
#include "rule.hpp"

class AbstractRulePreprocessor: public ModelTransformer {

protected:

    RulePtr in;

    explicit AbstractRulePreprocessor(RulePtr);

public:

    virtual RulePtr process() = 0;

};

class RulePreprocessor : public AbstractRulePreprocessor {

    std::vector<std::unique_ptr<AbstractRulePreprocessor>> procs;

public:
    explicit RulePreprocessor(const RulePtr &in);
    RulePtr process() override;
    ModelPtr transform_model(ModelPtr) override;

};

namespace Preprocess {

    RulePtr preprocessRule(const RulePtr &rule);

    RulePtr chain(const std::vector<RulePtr>&);

}
