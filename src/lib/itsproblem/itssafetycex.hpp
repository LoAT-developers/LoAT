#pragma once

#include "itscex.hpp"
#include "model.hpp"

class ITSSafetyCex: public ITSCex {

friend std::ostream& operator<<(std::ostream &s, const ITSSafetyCex &);

    std::vector<RulePtr> m_transitions;
    std::vector<ModelPtr> m_states;

public:

    explicit ITSSafetyCex(const linked_hash_set<RulePtr>& orig);

    size_t num_transitions() const;
    RulePtr get_transition(size_t) const;
    void do_step(const RulePtr&, const ModelPtr&);
    void set_initial_state(const ModelPtr&);
    void add_final_transition(const RulePtr&);
    size_t num_states() const;
    ModelPtr get_state(size_t) const;
    std::vector<std::pair<RulePtr, ProofStepKind>> get_used_rules() const;

};
