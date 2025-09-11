#pragma once

#include "safetyproblem.hpp"
#include "model.hpp"

class SafetyCex {

friend std::ostream& operator<<(std::ostream &s, const SafetyCex &);

    SafetyProblem sp;
    std::vector<Bools::Expr> transitions;
    std::vector<ModelPtr> states;

public:

    explicit SafetyCex(SafetyProblem sp);

    bool is_valid_step(const ModelPtr &m) const;
    bool try_step(const ModelPtr &m, const Bools::Expr& trans);
    void set_final_state(const ModelPtr &m);
    std::pair<const ModelPtr&, Bools::Expr> get_step(size_t i) const;
    const ModelPtr& get_state(size_t i) const;
    size_t num_states() const;
    size_t num_transitions() const;

};
