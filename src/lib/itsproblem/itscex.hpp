#pragma once

#include "itsproblem.hpp"
#include "rule.hpp"
#include "proof.hpp"

class ITSCex {

protected:

    linked_hash_set<RulePtr> orig;
    linked_hash_map<RulePtr, RulePtr> accel;
    linked_hash_map<RulePtr, RulePtr> implicants;
    linked_hash_map<RulePtr, RulePtr> recurrent_set;
    linked_hash_map<RulePtr, std::vector<RulePtr>> resolvents;

    bool is_known(const RulePtr& rule) const;

public:

    explicit ITSCex(const linked_hash_set<RulePtr>& orig);

    LocationIdx get_lhs_loc(const RulePtr&) const;
    void add_orig(const RulePtr& rule);
    void undo_chaining(const std::vector<RulePtr> &rules, const RulePtr& res);
    void add_accel(const RulePtr& loop, const RulePtr& res);
    void add_recurrent_set(const RulePtr& loop, const RulePtr& res);
    void add_resolvent(const std::vector<RulePtr> &rules, const RulePtr& res);
    void add_implicant(const RulePtr& rule, const RulePtr& imp);
    const linked_hash_set<RulePtr> &get_orig() const;
    const linked_hash_map<RulePtr, RulePtr> &get_accel() const;
    const linked_hash_map<RulePtr, RulePtr> &get_recurrent_set() const;
    const linked_hash_map<RulePtr, RulePtr> &get_implicants() const;
    const linked_hash_map<RulePtr, std::vector<RulePtr>> &get_resolvents() const;
    std::vector<std::pair<RulePtr, ProofStepKind>> get_used_rules(const std::vector<RulePtr> &transitions) const;

};