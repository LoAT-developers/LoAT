#pragma once

#include "theory.hpp"

#include <crab/cfg/basic_block_traits.hpp>
#include <crab/cfg/cfg.hpp>
#include <crab/cg/cg.hpp>
#include <crab/config.h>
#include <crab/support/debug.hpp>
#include <crab/types/varname_factory.hpp>
#include <crab/types/tag.hpp>

namespace crab {

namespace cfg_impl {

using variable_factory_t = var_factory_impl::str_variable_factory;
using varname_t = typename variable_factory_t::varname_t;
using basic_block_label_t = std::string;
using cfg_t = cfg::cfg<basic_block_label_t, varname_t, ikos::z_number>;
using z_cfg_t = cfg::cfg<basic_block_label_t, varname_t, ikos::z_number>;
using z_cfg_ref_t = cfg::cfg_ref<z_cfg_t>;
using z_cfg_rev_t = cfg::cfg_rev<z_cfg_ref_t>;
using z_basic_block_t = z_cfg_t::basic_block_t;
using z_var = variable<ikos::z_number, varname_t>;
using z_var_or_cst_t = variable_or_constant<ikos::z_number, varname_t>;
using z_lin_exp_t = ikos::linear_expression<ikos::z_number, varname_t>;
using z_lin_cst_t = ikos::linear_constraint<ikos::z_number, varname_t>;
using z_ref_cst_t = reference_constraint<ikos::z_number, varname_t>;

}

template<>
class variable_name_traits<std::string> {
public:
  static std::string to_string(std::string varname) {
    return varname;
  }
};

template<>
class basic_block_traits<cfg_impl::z_basic_block_t> {
public:
  using bb_label_t = typename cfg_impl::z_basic_block_t::basic_block_label_t;
  static std::string to_string(const bb_label_t &bbl) {
    return bbl;
  }
};

using namespace crab;

}

using namespace crab;
using namespace crab::cfg_impl;
