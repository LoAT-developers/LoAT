#pragma once

#include "itsproblem.hpp"
#include "rule.hpp"
#include "model.hpp"
#include "proof.hpp"

class ITSCex {

friend std::ostream& operator<<(std::ostream &s, const ITSCex &);

private:

    ITSPtr its;
    linked_hash_map<RulePtr, RulePtr> accel;
    linked_hash_map<RulePtr, RulePtr> implicants;
    linked_hash_map<RulePtr, std::vector<RulePtr>> resolvents;
    std::vector<RulePtr> transitions;
    std::vector<Model> states;

public:

    ITSCex(ITSPtr its);

    bool try_step(const RulePtr trans, const Model &m);
    void set_initial_state(const Model &m);
    bool try_final_transition(const RulePtr trans);
    void add_accel(const RulePtr loop, const RulePtr res);
    void add_resolvent(const std::vector<RulePtr> &rules, const RulePtr res);
    void add_implicant(const RulePtr rule, const RulePtr imp);
    size_t num_states() const;
    size_t num_transitions() const;
    RulePtr get_transition(const size_t i) const;
    Model get_state(const size_t i) const;
    void replace_state(const Model &m);
    const linked_hash_map<RulePtr, RulePtr> &get_accel() const;
    const linked_hash_map<RulePtr, RulePtr> &get_implicants() const;
    const linked_hash_map<RulePtr, std::vector<RulePtr>> &get_resolvents() const;
    std::vector<std::pair<RulePtr, ProofStepKind>> get_used_rules() const;
    ITSCex replace_rules(const linked_hash_map<RulePtr, RulePtr>&) const;

};