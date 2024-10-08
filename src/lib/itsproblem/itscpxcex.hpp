#pragma once

#include "itscex.hpp"

class ITSCpxCex: public ITSCex {

friend std::ostream& operator<<(std::ostream &s, const ITSCpxCex &);

private:

    std::optional<RulePtr> witness;
    std::optional<ArithSubs> valuation;
    std::optional<ArithVarPtr> param;

public:

    ITSCpxCex(ITSPtr its);

    ITSCpxCex replace_rules(const linked_hash_map<RulePtr, RulePtr>&) const;

    void set_witness(const RulePtr withness, const ArithSubs &valuation, const ArithVarPtr &param);

};
