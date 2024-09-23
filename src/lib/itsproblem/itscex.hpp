#pragma once

#include "itsproblem.hpp"
#include "rule.hpp"
#include "model.hpp"

class ITSCex {

friend std::ostream& operator<<(std::ostream &s, const ITSCex &);

private:

    ITSPtr its;
    linked_hash_map<RulePtr, std::vector<RulePtr>> accel;
    std::vector<RulePtr> transitions;
    std::vector<Model> states;

public:

    ITSCex(ITSPtr its);

    bool is_valid_step(const Model &m) const;
    bool try_step(const Model &m, const RulePtr trans);
    void add_final_state(const Model &m);
    void add_accel(const std::vector<RulePtr> &loop, const RulePtr res);

};