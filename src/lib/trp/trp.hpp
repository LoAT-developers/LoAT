#pragma once

#include "model.hpp"
#include "theory.hpp"
#include "config.hpp"

class TRP {

    const Renaming &pre_to_post;
    const Renaming post_to_pre;
    Renaming post_to_intermediate;
    Renaming pre_to_intermediate;
    const Config::TRPConfig &config;
    LitSet res_lits;
    const Arith::Var n {ArithVar::next(0)};

    void recurrent_exps(const Bools::Expr loop, const Model &model);
    void recurrent_pseudo_divisibility(const Bools::Expr loop, const Model &model);
    void recurrent_cycles(const Bools::Expr loop, const Model &model);
    void recurrent_bounds(const Bools::Expr loop, Model model);
    Bools::Expr recurrent(const Bools::Expr loop, const Model &model);

public:

    TRP(const Renaming &pre_to_post, const Config::TRPConfig &config);
    Bools::Expr compute(const Bools::Expr loop, const Model &model);
    Arith::Var get_n() const;
    Bools::Expr mbp(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var &)> &eliminate) const;

};
