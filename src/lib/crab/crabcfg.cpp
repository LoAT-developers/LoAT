#include "crabcfg.hpp"
#include "exprconverter.hpp"
#include "subs.hpp"

#include <crab/domains/elina_domains.hpp>
#include <crab/fixpoint/fixpoint_params.hpp>
#include <crab/analysis/fwd_analyzer.hpp>
#include <crab/domains/flat_boolean_domain.hpp>

CrabCfg::CrabCfg(const VarSet &prog_vars) {
    auto &vfac {ctx.getVfac()};
    const auto add_var = [&](const auto &x) {
        const auto name{vfac[theory::getName(x)]};
        const z_var var{
            std::visit(
                Overload{
                    [&](const Arith::Var &x) {
                        return z_var(name, crab::INT_TYPE, 32);
                    },
                    [&](const Bools::Var &x) {
                        return z_var(name, crab::BOOL_TYPE);
                    }},
                x)};
        var_map.left.insert(crab_var_map::left_value_type(x, var));
    };
    for (const auto &pre : prog_vars) {
        const auto s{theory::next(pre)};
        add_var(pre);
        add_var(theory::postVar(pre));
        add_var(s);
        snapshots.emplace(s, pre);
    }
}

void CrabCfg::assume(const Bools::Expr t, z_basic_block_t &b) {
    if (!t->isConjunction()) {
        throw std::invalid_argument("crab only supports conjunctions");
    }
    auto literals {t->lits()};
    auto it {literals.begin()};
    while (it != literals.end()) {
        if (!theory::isLinear(*it)) {
            it = literals.erase(it);
        } else {
            ++it;
        }
    }
    const auto t_lin {bools::mkAndFromLits(literals)};
    auto conjunction {ExprConverter<z_lin_exp_t, CrabConjunction>::convert(t_lin, ctx)};
    for (const auto &lit : conjunction.constraints) {
        b.assume(lit);
    }
    for (const auto &lit : conjunction.positive_lits) {
        b.bool_assume(lit);
    }
    for (const auto &lit : conjunction.negative_lits) {
        b.bool_not_assume(lit);
    }
}

void CrabCfg::transition_to_bb(const Bools::Expr t, z_basic_block_t &b) {
    assume(t, b);
    for (const auto &[x, y] : var_map) {
        if (theory::isProgVar(x)) {
            const auto post{var_map.left.at(theory::postVar(x))};
            std::visit(
                Overload{
                    [&](const Arith::Var) {
                        b.assign(y, post);
                    },
                    [&](const Bools::Var) {
                        b.bool_assign(y, post);
                    }}, x);
        }
    }
    for (const auto &[x, y] : var_map) {
        if (theory::isPostVar(x) || (theory::isTempVar(x) && !snapshots.contains(x))) {
            b.havoc(y);
        }
    }
}

std::shared_ptr<cfg_impl::z_cfg_t> CrabCfg::lasso_to_cfg(const Bools::Expr stem, const Bools::Expr cycle) {
    auto cfg{std::make_shared<cfg_impl::z_cfg_t>("entry", "ret")};
    auto &entry = cfg->insert("entry");
    auto &loop = cfg->insert("loop");
    auto &ret = cfg->insert("ret");
    entry >> loop;
    loop >> loop;
    loop >> ret;
    assume(stem, entry);
    for (const auto &[s,x]: snapshots) {
        std::visit(
            Overload{
                [&](const Arith::Var) {
                    entry.assign(var_map.left.at(s), var_map.left.at(x));
                },
                [&](const Bools::Var) {
                    entry.bool_assign(var_map.left.at(s), var_map.left.at(x));
                }}, s);
    }
    transition_to_bb(cycle, loop);
    return cfg;
}

Bools::Expr CrabCfg::get_invariants(const Bools::Expr stem, const Bools::Expr cycle) {
    using namespace crab::domains;
    using namespace crab::cfg_impl;
    using namespace ikos;
    using z_pk_elina_domain_t = elina_domain<z_number, varname_t, ELINA_PK>;
    using domain = flat_boolean_numerical_domain<z_pk_elina_domain_t>;
    using namespace crab::analyzer;
    using intra_fwd_analyzer_t = intra_fwd_analyzer<crab::cfg_impl::z_cfg_ref_t, domain>;
    domain init;
    auto absval_fac = init.make_top();
    crab::fixpoint_parameters fixpo_params;
    const auto cfg {lasso_to_cfg(stem, cycle)};
    intra_fwd_analyzer_t a(*cfg, absval_fac, nullptr, fixpo_params);
    typename intra_fwd_analyzer_t::assumption_map_t assumptions;
    a.run(cfg->entry(), init, assumptions);
    std::vector<z_var> keep;
    for (const auto &[s,x]: snapshots) {
        keep.emplace_back(var_map.left.at(x));
        keep.emplace_back(var_map.left.at(s));
    }
    auto res {a.get_post(cfg->exit())};
    res.project(keep);
    const auto lin_unsorted {res.to_linear_constraint_system()};
    std::vector<z_lin_cst_t> lin {lin_unsorted.begin(), lin_unsorted.end()};
    std::sort(lin.begin(), lin.end(), [](const auto &x, const auto &y) {
        return x.lexicographical_compare(y);
    });
    LitSet lits;
    for (const auto &lit: lin) {
        auto all_int {true};
        auto all_bool {true};
        std::vector<z_var> forget;
        for (const auto &x : lit.variables()) {
            if (!x.get_type().is_integer()) {
                all_int = false;
            }
            if (!x.get_type().is_bool()) {
                all_bool = false;
            }
        }
        if (all_int) {
            std::vector<Arith::Expr> addends;
            for (const auto &[c,x]: lit) {
                const auto var {std::get<Arith::Var>(var_map.right.at(x))};
                addends.emplace_back(arith::mkConst(Int(c.get_str())) * var);
            }
            const auto constant {arith::mkConst(Int(lit.constant().get_str()))};
            const auto sum {arith::mkPlus(std::move(addends))};
            if (lit.is_equality()) {
                lits.insert(arith::mkEq(sum, constant));
            } else if (lit.is_disequation()) {
                lits.insert(arith::mkNeq(sum, constant));
            } else if (lit.is_inequality()) {
                lits.insert(arith::mkLeq(sum, constant));
            } else if (lit.is_strict_inequality()) {
                lits.insert(arith::mkLt(sum, constant));
            }
        } else if (all_bool) {
            if ((lit.is_equality() || lit.is_disequation()) && lit.size() == 1) {
                auto negated {lit.is_disequation()};
                const auto &[c,x] {*lit.begin()};
                if (c == 1) {
                    const auto var {std::get<Bools::Var>(var_map.right.at(x))};
                    if (lit.constant() == 1) {
                        lits.insert(BoolLit(var, negated));
                    } else if (lit.constant() == 0) {
                        lits.insert(BoolLit(var, !negated));
                    }
                }
            }
        }
    }
    const auto inv {bools::mkAndFromLits(lits)};
    Subs subs;
    for (const auto &[s,x]: snapshots) {
        subs.put(s, theory::toExpr(x));
        subs.put(x, theory::toExpr(theory::postVar(x)));
    }
    return subs(inv);
}

Bools::Expr CrabCfg::compute_invariants(const Bools::Expr stem, const Bools::Expr cycle) {
    VarSet prog_vars;
    for (const auto &b: {stem, cycle}) {
        for (const auto &x: b->vars()) {
            if (theory::isProgVar(x)) {
                prog_vars.insert(x);
            } else if (theory::isPostVar(x)) {
                prog_vars.insert(theory::progVar(x));
            }
        }
    }
    return CrabCfg(prog_vars).get_invariants(stem, cycle);
}