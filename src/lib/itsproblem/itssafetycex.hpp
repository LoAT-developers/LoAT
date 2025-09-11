#pragma once

#include "itscex.hpp"
#include "valuation.hpp"

class ITSSafetyCex: public ITSCex {

friend std::ostream& operator<<(std::ostream &s, const ITSSafetyCex &);

    std::vector<RulePtr> transitions;
    std::vector<Valuation> states;

public:

    explicit ITSSafetyCex(const ITSPtr& its);

    size_t num_transitions() const;
    RulePtr get_transition(size_t i) const;
    bool try_step(const RulePtr &trans, const Valuation &next);
    void set_initial_state(const Valuation &m);
    bool try_final_transition(const RulePtr& trans);
    size_t num_states() const;
    Valuation get_state(size_t i) const;
    ITSSafetyCex replace_rules(const linked_hash_map<RulePtr, RulePtr>&) const;
    std::vector<std::pair<RulePtr, ProofStepKind>> get_used_rules() const;

};
