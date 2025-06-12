#pragma once

#include "model.hpp"
#include "theory.hpp"
#include "config.hpp"
#include "conjunction.hpp"

class TRP {

    const Renaming &pre_to_post;
    const Renaming post_to_pre;
    Renaming post_to_intermediate;
    Renaming pre_to_intermediate;
    const Config::TRPConfig &config;
    Conjunction res_lits;
    const Arith::Var n {ArithVar::next()};

    void recurrent_exps(const Conjunction &loop, const Model &model);
    void recurrent_pseudo_divisibility(const Conjunction &loop, const Model &model);
    void recurrent_cycles(const Conjunction &loop, const Model &model);
    void recurrent_bounds(const Conjunction &loop, Model model);
    Conjunction recurrent(const Conjunction &loop, const Model &model);

public:

    TRP(const Renaming &pre_to_post, const Config::TRPConfig &config);
    Conjunction compute(const Conjunction &loop, const Model &model);
    Arith::Var get_n() const;
    Conjunction mbp(const Conjunction &trans, const Model &model, const std::function<bool(const Var &)> &eliminate) const;

};
