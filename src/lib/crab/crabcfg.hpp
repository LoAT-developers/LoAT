#pragma once

#include "crab.hpp"
#include "crabcontext.hpp"
#include "theory.hpp"

#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>

using crab_var_map = boost::bimap<boost::bimaps::unordered_set_of<Var>, boost::bimaps::unordered_set_of<z_var>>;

class CrabCfg {

public:

    static Bools::Expr compute_invariants(const Bools::Expr stem, const Bools::Expr cycle);

private:

    CrabCfg(const VarSet &prog_vars);

    void assume(const Bools::Expr t, z_basic_block_t &b);

    void transition_to_bb(const Bools::Expr t, z_basic_block_t &b);

    std::shared_ptr<cfg_impl::z_cfg_t> lasso_to_cfg(const Bools::Expr stem, const Bools::Expr cycle);

    Bools::Expr get_invariants(const Bools::Expr stem, const Bools::Expr cycle);

    CrabContext ctx;
    crab_var_map var_map;
    linked_hash_map<Var, Var> snapshots;

};