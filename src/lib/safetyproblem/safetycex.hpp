#pragma once

#include <ostream>

#include "safetyproblem.hpp"
#include "model.hpp"

class SafetyCex {

friend std::ostream& operator<<(std::ostream &s, const SafetyCex &);

private:

    SafetyProblem sp;
    std::vector<Bools::Expr> transitions;
    std::vector<Model> states;

public:

    SafetyCex(const SafetyProblem &sp);

    bool is_valid_step(const Model &m) const;
    bool try_step(const Model &m, const Bools::Expr trans);
    std::pair<const Model&, Bools::Expr> get_step(size_t i) const;
    size_t size() const;

};