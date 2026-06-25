#pragma once

#include "rule.hpp"

class AbstractRulePreprocessor {

protected:

    RulePtr in;

    explicit AbstractRulePreprocessor(const RulePtr&);

public:
    virtual ~AbstractRulePreprocessor() = default;

    virtual RulePtr process() = 0;
    virtual ModelPtr transform_model(const ModelPtr& cex) const = 0;

};

class RulePreprocessor : public AbstractRulePreprocessor {

    std::vector<std::unique_ptr<AbstractRulePreprocessor>> procs;

public:
    explicit RulePreprocessor(const RulePtr &in);
    RulePtr process() override;
    ModelPtr transform_model(const ModelPtr& cex) const override;

};

namespace Preprocess {

    RulePtr preprocessRule(const RulePtr &rule);

    RulePtr chain(const std::vector<RulePtr> &);

}
