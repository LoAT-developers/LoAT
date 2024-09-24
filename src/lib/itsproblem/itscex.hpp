#pragma once

#include "itsproblem.hpp"
#include "rule.hpp"
#include "model.hpp"

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

    bool is_valid_step(const Model &m) const;
    bool try_step(const Model &m, const RulePtr trans);
    void add_accel(const RulePtr loop, const RulePtr res);
    void add_resolvent(const std::vector<RulePtr> &rules, const RulePtr res);
    void add_implicant(const RulePtr rule, const RulePtr imp);
    size_t size() const;

};