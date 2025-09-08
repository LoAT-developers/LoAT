#pragma once

#include "itscex.hpp"
#include "model.hpp"

class ITSSafetyCex: public ITSCex {

friend std::ostream& operator<<(std::ostream &s, const ITSSafetyCex &);

private:

    std::vector<RulePtr> transitions;
    std::vector<ModelPtr> states;

public:

    explicit ITSSafetyCex(const ITSPtr& its);

    size_t num_transitions() const;
    RulePtr get_transition(size_t i) const;
    bool try_step(const RulePtr &trans, const ModelPtr &next);
    void set_initial_state(const ModelPtr &m);
    bool try_final_transition(const RulePtr& trans);
    size_t num_states() const;
    ModelPtr get_state(size_t i) const;
    ITSSafetyCex replace_rules(const linked_hash_map<RulePtr, RulePtr>&) const;
    std::vector<std::pair<RulePtr, ProofStepKind>> get_used_rules() const;

};