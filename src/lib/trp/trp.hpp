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
    const ArithVarPtr n {arrays::nextConst<Arith>()};

    void recurrent_exps(const Bools::Expr& loop, const ModelPtr &model);
    void recurrent_pseudo_divisibility(const Bools::Expr& loop, const ModelPtr &model);
    void recurrent_cycles(const Bools::Expr& loop, const linked_hash_set<ArithVarPtr>& pre_cells);
    void recurrent_bounds(const Bools::Expr& loop, const linked_hash_set<ArithVarPtr>& pre_cells, const ModelPtr& model);
    Bools::Expr recurrent(const Bools::Expr& loop, const ModelPtr &model);

public:

    TRP(const Renaming &pre_to_post, const Config::TRPConfig &config);
    Bools::Expr compute(const Bools::Expr& loop, const ModelPtr &model);
    ArithVarPtr get_n() const;
    Bools::Expr mbp(const Bools::Expr &trans, const ModelPtr &model, const std::function<bool(const Cell &)> &eliminate) const;

};
