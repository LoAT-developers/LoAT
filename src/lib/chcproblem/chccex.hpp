#pragma once

#include "chcproblem.hpp"
#include "model.hpp"
#include "proof.hpp"

class CHCCex {

    friend std::ostream& operator<<(std::ostream &s, const CHCCex &);

    CHCPtr chcs;
    linked_hash_map<ClausePtr, ClausePtr> accel;
    linked_hash_map<ClausePtr, ClausePtr> implicants;
    linked_hash_map<ClausePtr, ClausePtr> recurrent_set;
    linked_hash_map<ClausePtr, std::vector<ClausePtr>> resolvents;
    std::vector<ClausePtr> transitions;
    std::vector<ModelPtr> states;

public:

    explicit CHCCex(CHCPtr chcs);

    void do_step(const ModelPtr &m, const ClausePtr &c);
    void add_accel(const ClausePtr &loop, const ClausePtr &res);
    void add_recurrent_set(const ClausePtr &loop, const ClausePtr &res);
    void add_resolvent(const std::vector<ClausePtr> &rules, const ClausePtr &res);
    void add_implicant(const ClausePtr &rule, const ClausePtr &imp);
    const linked_hash_map<ClausePtr, ClausePtr>& get_accel() const;
    const linked_hash_map<ClausePtr, ClausePtr>& get_implicants() const;
    const linked_hash_map<ClausePtr, std::vector<ClausePtr>>& get_resolvents() const;
    const std::vector<ClausePtr>& get_transitions() const;
    const std::vector<ModelPtr>& get_states() const;
    std::vector<std::pair<ClausePtr, ProofStepKind>> get_used_clauses() const;
    void complete_recurrent_set(std::unordered_map<std::string, std::pair<FunAppPtr, BoolExprSet>>& rs, const ClausePtr& clause, bool with_start) const;
    std::unordered_map<std::string, std::pair<FunAppPtr, BoolExprSet>> to_recurrent_set() const;

};
