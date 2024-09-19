#pragma once

#include "itsproblem.hpp"
#include "rule.hpp"
#include "model.hpp"

class ITSCex {

friend std::ostream& operator<<(std::ostream &s, const ITSCex &);

private:

    const ITSProblem &its;
    std::vector<TransIdx> transitions;
    std::vector<Model> states;

public:

    ITSCex(const ITSProblem &its);

    bool is_valid_step(const Model &m) const;
    bool try_step(const Model &m, const TransIdx trans);
    void add_final_state(const Model &m);

};