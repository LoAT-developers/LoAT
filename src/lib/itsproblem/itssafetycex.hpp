#pragma once

#include "itscex.hpp"
#include "model.hpp"

class ITSSafetyCex: public ITSCex {

friend std::ostream& operator<<(std::ostream &s, const ITSSafetyCex &);

private:

    std::vector<RulePtr> transitions;
    std::vector<Model> states;

public:

    ITSSafetyCex(ITSPtr its);

    size_t num_transitions() const;
    RulePtr get_transition(const size_t i) const;
    bool try_step(const RulePtr trans, const Model &m);
    void set_initial_state(const Model &m);
    bool try_final_transition(const RulePtr trans);
    size_t num_states() const;
    Model get_state(const size_t i) const;
    ITSSafetyCex replace_rules(const linked_hash_map<RulePtr, RulePtr>&) const;
    std::vector<std::pair<RulePtr, ProofStepKind>> get_used_rules() const;

};