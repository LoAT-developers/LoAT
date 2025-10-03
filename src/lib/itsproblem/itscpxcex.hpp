#pragma once

#include "itscex.hpp"
#include "model.hpp"

class ITSCpxCex: public ITSCex {

friend std::ostream& operator<<(std::ostream &s, const ITSCpxCex &);

    std::optional<RulePtr> witness;
    std::optional<ModelPtr> valuation;
    std::optional<ArithVarPtr> param;

public:
    explicit ITSCpxCex(const ITSPtr& its);

    ITSCpxCex replace_rules(const linked_hash_map<RulePtr, RulePtr>&) const;

    void set_witness(const RulePtr& witness, const ModelPtr &valuation, const ArithVarPtr &param);

};
