#pragma once

#include "itscex.hpp"
#include "model.hpp"

class ITSCpxCex: public ITSCex {

friend std::ostream& operator<<(std::ostream &s, const ITSCpxCex &);

    std::optional<RulePtr> witness;
    std::optional<ModelPtr> valuation;
    std::optional<ArithVarPtr> param;

public:
    explicit ITSCpxCex(const linked_hash_set<RulePtr> &orig);

    std::shared_ptr<ITSCex> replace_rules(
        const linked_hash_map<RulePtr, RulePtr>&,
        const linked_hash_map<RulePtr, std::shared_ptr<RulePreprocessor>>&) const override;

    void set_witness(const RulePtr& witness, const ModelPtr &valuation, const ArithVarPtr &param);

    VarSet vars() const;

};
