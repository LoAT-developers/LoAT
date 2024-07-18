#include "til.hpp"
#include "chain.hpp"
// #include "crabcfg.hpp"
#include "cvc5.hpp"
#include "dependencygraph.hpp"
#include "intmbp.hpp"
#include "linkedhashmap.hpp"
#include "optional.hpp"
#include "pair.hpp"
#include "preprocessing.hpp"
#include "realmbp.hpp"
#include "rulepreprocessing.hpp"
#include "theory.hpp"
#include "guardtoolbox.hpp"

Range::Range(const unsigned s, const unsigned e) : s(s), e(e) {}

unsigned Range::start() const {
    return s;
}

unsigned Range::end() const {
    return e;
}

unsigned Range::length() const {
    return e - s + 1;
}

bool Range::empty() const {
    return length() == 0;
}

Range Range::from_length(const unsigned start, const unsigned length) {
    return Range(start, start + length - 1);
}

Range Range::from_interval(const unsigned start, const unsigned end) {
    return Range(start, end);
}

TIL::TIL(SafetyProblem &t, const Config::TILConfig &config) : config(config), t(t) {
    vars.insert(trace_var);
    vars.insert(n);
    for (const auto &x : t.vars()) {
        if (theory::isPostVar(x)) {
            const auto pre {theory::progVar(x)};
            pre_vars.insert(pre);
            vars.insert(pre);
            post_to_pre.put(x, theory::toExpr(pre));
            pre_to_post.put(pre, theory::toExpr(x));
        } else {
            if (theory::isProgVar(x)) {
                const auto post {theory::postVar(x)};
                pre_vars.insert(x);
                post_to_pre.put(post, theory::toExpr(x));
                pre_to_post.put(x, theory::toExpr(post));
            }
            vars.insert(x);
        }
    }
    solver->enableModels();
}

std::optional<Range> TIL::has_looping_infix() {
    for (int i = 0; i < trace.size(); ++i) {
        for (int start = 0; start + i < trace.size(); ++start) {
            if (dependency_graph.hasEdge(trace[start + i].implicant, trace[start].implicant) && (i > 0 || trace[start].id <= last_orig_clause)) {
                return {Range::from_interval(start, start + i)};
            }
        }
    }
    return {};
}

std::pair<Bools::Expr, Model> TIL::compress(const Range &range) {
    std::optional<Bools::Expr> loop;
    Subs var_renaming;
    for (int i = range.end(); i >= 0 && i >= range.start(); --i) {
        const auto rule{trace[i].implicant};
        const auto s{get_subs(i, 1)};
        if (loop) {
            // sigma1 maps vars from chained to the corresponding vars from rule
            // sigma2 maps vars from chained to the corresponding vars from loop
            // temporary variables in rule remain unchanged
            // temporary variables in loop that clash with rule are renamed
            const auto [chained, sigma1, sigma2]{Chaining::chain(rule, *loop)};
            // all pre-vars and temp vars that already occured in rule correspond to vars from rule
            auto fst_vars{t.pre_vars()};
            rule->collectVars(fst_vars);
            for (const auto &x : t.post_vars()) {
                fst_vars.erase(x);
            }
            // map them to the corresponding SMT vars by taking sigma1 and s (the var renaming that
            // was used for the step with rule) into account
            const auto fst_var_renaming{sigma1.compose(s).project(fst_vars)};
            // all post-vars and all other variables that occur in chained, but not in rule, correspond
            // to variables from loop
            auto snd_vars{t.post_vars()};
            chained->collectVars(snd_vars);
            for (const auto &x : fst_vars) {
                snd_vars.erase(x);
            }
            // map them to SMT vars by taking sigma2 and the variable renaming that has been constructed
            // so far into account
            auto snd_var_renaming{sigma2.compose(var_renaming).project(snd_vars)};
            // both var renamings are disjoint by construction
            var_renaming = fst_var_renaming.unite(snd_var_renaming);
            loop = chained;
        } else {
            loop = rule;
            var_renaming = s;
        }
    }
    auto vars{(*loop)->vars()};
    var_renaming.collectCoDomainVars(vars);
    const auto m{model.composeBackwards(var_renaming)};
    return {*loop, m};
}

Int TIL::add_learned_clause(const Bools::Expr &accel) {
    if (Config::Analysis::log) {
        std::cout << "learned transition: " << accel << " with id " << next_id << std::endl;
    }
    const auto id = next_id;
    ++next_id;
    const auto encoded {encode_transition(accel, id)};
    rule_map.left.insert(rule_map_t::left_value_type(id, encoded));
    blocked.emplace_back(id, accel);
    step = step || encoded;
    return id;
}

Bools::Expr TIL::mbp_impl(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var &)> &eliminate) {
    if (!model.eval<Bools>(trans)) {
        std::cout << "mbp: not a model" << std::endl;
        std::cout << "trans: " << trans << std::endl;
        std::cout << "model: " << model << std::endl;
        assert(false);
    }
    switch (config.mbpKind) {
    case Config::TILConfig::RealMbp:
        return mbp::real_mbp(trans, model, eliminate);
    case Config::TILConfig::LowerIntMbp:
        return mbp::int_mbp(trans, model, eliminate, false);
    case Config::TILConfig::UpperIntMbp:
        return mbp::int_mbp(trans, model, eliminate, true);
    default:
        throw std::invalid_argument("unknown mbp kind");
    }
}

Bools::Expr TIL::specialize(const Bools::Expr e, const Model &model, const std::function<bool(const Var &)> &eliminate) {
    const auto sip{model.syntacticImplicant(e)};
    if (Config::Analysis::log) {
        std::cout << "sip: " << sip << std::endl;
    }
    auto simp{Preprocess::preprocessTransition(sip)};
    if (Config::Analysis::log && simp) {
        std::cout << "simp: " << *simp << std::endl;
    }
    const auto mbp_res{mbp_impl(*simp, model, eliminate)};
    if (Config::Analysis::log) {
        std::cout << "mbp: " << mbp_res << std::endl;
    }
    return mbp_res;
}

std::pair<Bools::Expr, Model> TIL::specialize(const Range &range, const std::function<bool(const Var &)> &eliminate) {
    if (range.empty()) {
        return {top(), Model()};
    }
    const auto [transition, model]{compress(range)};
    if (Config::Analysis::log) {
        std::cout << "compressed:" << std::endl;
        std::cout << transition << std::endl;
        std::cout << "model: " << model << std::endl;
    }
    return {specialize(transition, model, eliminate), model};
}

void TIL::recurrent_divisibility(const Bools::Expr loop, const Model &model, LitSet &res_lits) {
    if (!config.recurrent_divs) {
        return;
    }
    assert(loop->isConjunction());
    const auto lits {loop->lits().get<Arith::Lit>()};
    for (const auto &l: lits) {
        if (const auto div {l->isDivisibility()}) {
            const auto &[t,mod] {*div};
            auto is_recurrent {true};
            const auto vars {t->vars()};
            for (const auto &x: vars) {
                if (x->isProgVar()) {
                    const auto pre_coeff {*(*t->coeff(x))->isInt()};
                    const auto post {ArithVar::postVar(x)};
                    if (vars.contains(post)) {
                        const auto post_coeff {*(*t->coeff(post))->isInt()};
                        // due to our normalization of mod-terms, the coefficients should be positive
                        assert(pre_coeff > 0);
                        assert(post_coeff > 0);
                        if (mod == pre_coeff + post_coeff) {
                            // we have:
                            //   pre_coeff * x + post_coeff * x'              % mod
                            // = pre_coeff * x + post_coeff * x' - mod * x'   % mod (as -mod % mod = 0)
                            // = pre_coeff * x + (post_coeff - mod) * x'      % mod
                            // = pre_coeff * x - pre_coeff * x'               % mod (as mod == pre_coeff + post_coeff)
                            continue;
                        }
                    }
                    is_recurrent = false;
                    break;
                } else {
                    const auto pre {ArithVar::progVar(x)};
                    if (!vars.contains(pre)) {
                        is_recurrent = false;
                        break;
                    }
                }
            }
            if (is_recurrent) {
                const auto constant {arith::mkConst(t->getConstantAddend())};
                res_lits.insert(arith::mkEq(arith::mkMod(t - constant + n * constant, arith::mkConst(mod)), arith::mkConst(0)));
            }
        }
    }
}

void TIL::recurrent_pseudo_divisibility(const Bools::Expr loop, const Model &model, LitSet &res_lits) {
    assert(loop->isConjunction());
    const auto lits {loop->lits().get<Arith::Lit>()};
    for (const auto &l: lits) {
        if (const auto div {l->isDivisibility()}) {
            const auto &[t,mod] {*div};
            const auto vars {t->vars()};
            if (std::all_of(vars.begin(), vars.end(), theory::isProgVar)) {
                const auto post {pre_to_post.get<Arith>()(t)};
                auto diff {model.eval<Arith>(t) - model.eval<Arith>(post)};
                if (diff % mod == 0) {
                    res_lits.insert(arith::mkEq(arith::mkMod(post, arith::mkConst(mod)), arith::mkConst(0)));
                }
            } else if (std::all_of(vars.begin(), vars.end(), theory::isPostVar)) {
                const auto pre {post_to_pre.get<Arith>()(t)};
                auto diff {model.eval<Arith>(t) - model.eval<Arith>(pre)};
                if (diff % mod == 0) {
                    res_lits.insert(arith::mkEq(arith::mkMod(pre, arith::mkConst(mod)), arith::mkConst(0)));
                }
            }
        }
    }
}

/**
 * handles constraints like x' = 2x
 */
void TIL::recurrent_exps(const Bools::Expr loop, const Model &model, LitSet &res_lits) {
    if (!config.recurrent_exps) {
        return;
    }
    assert(loop->isConjunction());
    // collect bounds of the form b >= 0
    const auto lits{loop->lits().get<Arith::Lit>()};
    for (const auto &l : lits) {
        if (l->lhs()->isLinear()) {
            auto lhs{l->lhs()};
            const auto vars{lhs->vars()};
            if (l->isEq() && vars.size() == 2) {
                auto pre{*vars.begin()};
                auto post{*std::next(vars.begin())};
                if (!pre->isProgVar()) {
                    const auto tmp{pre};
                    pre = post;
                    post = tmp;
                }
                if (pre->isProgVar() && post == ArithVar::postVar(pre)) {
                    auto pre_coeff{***(*lhs->coeff(pre))->isRational()};
                    auto post_coeff{***(*lhs->coeff(post))->isRational()};
                    if (post_coeff < 0) {
                        lhs = -lhs;
                        pre_coeff = -pre_coeff;
                        post_coeff = -post_coeff;
                    }
                    if (pre_coeff == -post_coeff) {
                        continue;
                    }
                    if (pre_coeff < 0) {
                        const auto val{model.get<Arith>(pre)};
                        if (post_coeff < -pre_coeff) {
                            if (val >= 0) {
                                // x' = 2x ~> x' >= 2x for non-negative x
                                res_lits.insert(arith::mkGeq(pre, arith::mkConst(0)));
                                res_lits.insert(arith::mkGeq(lhs, arith::mkConst(0)));
                            } else {
                                // x' = 2x ~> x' <= 2x for negative x
                                res_lits.insert(arith::mkLt(pre, arith::mkConst(0)));
                                res_lits.insert(arith::mkLeq(lhs, arith::mkConst(0)));
                            }
                        } else {
                            if (val >= 0) {
                                // 2x' = x ~> 2x' <= x for non-negative x
                                res_lits.insert(arith::mkGeq(pre, arith::mkConst(0)));
                                res_lits.insert(arith::mkLeq(lhs, arith::mkConst(0)));
                            } else {
                                // 2x' = x ~> 2x' >= x for negative x
                                res_lits.insert(arith::mkLt(pre, arith::mkConst(0)));
                                res_lits.insert(arith::mkGeq(lhs, arith::mkConst(0)));
                            }
                        }
                    }
                }
            }
        }
    }
}

/**
 * handles constraints like x' = -x or x' = y /\ y' = x
 */
void TIL::recurrent_cycles(const Bools::Expr loop, LitSet &res_lits, linked_hash_set<Arith::Var> &fully_known) {
    if (!config.recurrent_cycles) {
        return;
    }
    const auto arith_vars{pre_vars.get<Arith::Var>()};
    for (const auto &pre : arith_vars) {
        if (fully_known.contains(pre)) {
            continue;
        }
        if (const auto orig_eq{loop->getEquality(pre)}) {
            auto vars{(*orig_eq)->vars()};
            vars.erase(pre);
            if (vars.size() != 1) {
                continue;
            }
            const auto post{ArithVar::postVar(pre)};
            auto eq{*orig_eq};
            auto other{*vars.begin()};
            auto other_coeff{*eq->coeff(other)};
            if (other_coeff->is(1)) {
                continue;
            }
            auto other_sign{***other_coeff->isRational() > 0};
            linked_hash_set<std::pair<Arith::Var, bool>> seen;
            while (other->isPostVar() && !seen.contains({other, other_sign})) {
                if (other == post && other_coeff->is(1)) {
                    const auto constant{arith::mkConst(eq->getConstantAddend())};
                    const auto rhs_cycle_plus_one_steps{ArithSubs({{post, pre}})(*orig_eq + constant * n)};
                    res_lits.insert(arith::mkEq(post, rhs_cycle_plus_one_steps));
                    fully_known.insert(pre);
                    fully_known.insert(post);
                    break;
                } else {
                    seen.emplace(other, other_sign);
                    const auto other_eq{loop->getEquality(ArithVar::progVar(other))};
                    if (!other_eq) {
                        break;
                    }
                    eq = ArithSubs({{other, *other_eq}})(eq);
                    vars = (*other_eq)->vars();
                    if (vars.size() != 1) {
                        break;
                    }
                    other = *vars.begin();
                    other_coeff = *eq->coeff(other);
                    other_sign = ***other_coeff->isRational() > 0;
                }
            }
        }
    }
}

void TIL::force_fully_known_to_zero(const Bools::Expr &loop, linked_hash_set<Arith::Var> &fully_known, SmtPtr &solver) {
    const auto arith_vars{pre_vars.get<Arith::Var>()};
    const auto lits{loop->lits().get<Arith::Lit>()};
    for (const auto &lit : lits) {
        if (lit->isLinear() && lit->isEq()) {
            const auto lhs{lit->lhs()};
            const auto vars{lhs->vars()};
            if (vars.size() == 2) {
                auto pre{*vars.begin()};
                if (fully_known.contains(pre)) {
                    continue;
                }
                auto post{*std::next(vars.begin())};
                if (!pre->isProgVar()) {
                    const auto tmp{pre};
                    pre = post;
                    post = tmp;
                }
                if (pre->isProgVar() && post == ArithVar::postVar(pre)) {
                    const auto pre_coeff{*lhs->coeff(pre)};
                    const auto post_coeff{*lhs->coeff(post)};
                    if (pre_coeff == -post_coeff) {
                        fully_known.insert(pre);
                        fully_known.insert(post);
                        solver->add(arith::mkEq(pre, arith::mkConst(0)));
                    }
                }
            }
        }
    }
    auto changed{false};
    const auto known = [&](const auto &x) {
        return fully_known.contains(x);
    };
    do {
        changed = false;
        for (const auto &pre : arith_vars) {
            if (fully_known.contains(pre)) {
                continue;
            }
            const auto post{ArithVar::postVar(pre)};
            if (const auto pre_eq{loop->getEquality(pre)}) {
                auto pre_vars{(*pre_eq)->vars()};
                if (std::all_of(pre_vars.begin(), pre_vars.end(), known)) {
                    if (const auto post_eq{loop->getEquality(post)}) {
                        const auto post_vars{(*post_eq)->vars()};
                        if (std::all_of(post_vars.begin(), post_vars.end(), known)) {
                            fully_known.insert(pre);
                            fully_known.insert(post);
                            solver->add(arith::mkEq(pre, arith::mkConst(0)));
                            changed = true;
                            continue;
                        }
                    }
                }
            }
        }
    } while (changed);
};

void TIL::recurrent_bounds(const Bools::Expr loop, const Model &model, LitSet &res_lits, linked_hash_set<Arith::Var> &fully_known) {
    if (!config.recurrent_bounds) {
        return;
    }
    assert(loop->isConjunction());
    // collect bounds of the form b >= 0
    const auto lits {loop->lits().get<Arith::Lit>()};
    ArithExprVec bounded;
    std::vector<std::pair<Arith::Expr, Arith::Expr>> pseudo_recurrent;
    for (const auto &l: lits) {
        if (l->lhs()->isLinear()) {
            auto lhs {l->lhs()};
            if (l->isGt() || l->isEq()) {
                std::vector<Arith::Expr> recurrent_addends;
                const auto vars {lhs->vars()};
                for (const auto &x: vars) {
                    if (x->isProgVar()) {
                        const auto pre_coeff {*lhs->coeff(x)};
                        const auto post {ArithVar::postVar(x)};
                        if (vars.contains(post)) {
                            const auto post_coeff {*lhs->coeff(post)};
                            if (pre_coeff == -post_coeff) {
                                recurrent_addends.push_back(pre_coeff * x);
                                recurrent_addends.push_back(post_coeff * post);
                                continue;
                            }
                        }
                    }
                }
                const auto recurrent {arith::mkPlus(std::move(recurrent_addends))};
                const auto non_recurrent {lhs - recurrent};
                const auto is_recurrent {!recurrent->isRational() && non_recurrent->isRational()};
                const auto is_pseudo_recurrent {!recurrent->isRational() && !non_recurrent->isRational()};
                if (is_recurrent) {
                    if (l->isEq()) {
                        const auto constant {lhs->getConstantAddend()};
                        res_lits.insert(arith::mkEq(lhs - arith::mkConst(constant) + n * arith::mkConst(constant), arith::mkConst(0)));
                    } else {
                        lhs = lhs - arith::mkConst(1);
                        const auto constant {lhs->getConstantAddend()};
                        res_lits.insert(arith::mkGeq(lhs - arith::mkConst(constant) + n * arith::mkConst(constant), arith::mkConst(0)));
                    }
                } else {
                    if (l->isGt()) {
                        bounded.push_back(lhs - arith::mkConst(1));
                    } else {
                        bounded.push_back(lhs);
                        bounded.push_back(-lhs);
                    }
                    if (is_pseudo_recurrent) {
                        if (l->isGt()) {
                            pseudo_recurrent.emplace_back(recurrent, non_recurrent - arith::mkConst(1));
                        } else {
                            pseudo_recurrent.emplace_back(recurrent, non_recurrent);
                            pseudo_recurrent.emplace_back(-recurrent, -non_recurrent);
                        }
                    }
                }
            }
        }
    }
    // set up one non-negative multiplier for each bound
    auto solver {SmtFactory::modelBuildingSolver(QF_LA)};
    ArithExprVec factors;
    for (const auto &b: bounded) {
        const auto f {Arith::next()};
        factors.push_back(f);
        solver->add(arith::mkGeq(f, arith::mkConst(0)));
    }
    // set up one equation for each pre and post variable, respectively
    const auto arith_vars {pre_vars.get<Arith::Var>()};
    for (const auto &pre: arith_vars) {
        const auto post {ArithVar::postVar(pre)};
        ArithExprVec pre_addends;
        ArithExprVec post_addends;
        for (unsigned idx = 0; idx < bounded.size(); ++idx) {
            if (bounded[idx]->has(pre)) {
                pre_addends.push_back(*bounded[idx]->coeff(pre) * factors[idx]);
            }
            if (bounded[idx]->has(post)) {
                post_addends.push_back(*bounded[idx]->coeff(post) * factors[idx]);
            }
        }
        solver->add(arith::mkEq(pre, arith::mkPlus(std::move(pre_addends))));
        solver->add(arith::mkEq(post, arith::mkPlus(std::move(post_addends))));
        // enforce that the result corresponds to a *recurrent* inequation
        solver->add(arith::mkEq(pre, -post));
    }
    // force variables x where the relation between x and x' is fully determined by the information we've inferred so far to 0
    force_fully_known_to_zero(loop, fully_known, solver);
    const auto const_var {ArithVar::next()};
    {
        // and one equation for the constant part
        ArithExprVec addends;
        for (unsigned idx = 0; idx < bounded.size(); ++idx) {
            addends.push_back(arith::mkConst(bounded[idx]->getConstantAddend()) * factors[idx]);
        }
        solver->add(arith::mkEq(arith::mkPlus(std::move(addends)), const_var));
    }
    {
        // block trivial solutions
        BoolExprSet disjuncts;
        for (const auto &pre: arith_vars) {
            disjuncts.insert(bools::mkLit(arith::mkNeq(pre, arith::mkConst(0))));
        }
        solver->add(bools::mkOr(disjuncts));
    }
    const auto build_sum = [&](const Model &model) {
        ArithExprVec addends;
        for (unsigned idx = 0; idx < bounded.size(); ++idx) {
            addends.push_back(bounded[idx] * arith::mkConst(model.eval<Arith>(factors[idx])));
        }
        return arith::mkPlus(std::move(addends));
    };
    const auto process_solution = [&]() {
        auto model{solver->model()};
        // construct the recurrent inequation that corresponds to the current solution
        auto sum = build_sum(model);
        auto constant {sum->getConstantAddend()};
        // minimze constant
        solver->push();
        for (const auto &pre : arith_vars) {
            solver->add(arith::mkEq(pre, arith::mkConst(model.get<Arith>(pre))));
        }
        bool sat;
        do {
            sat = false;
            solver->add(arith::mkLt(const_var, arith::mkConst(constant)));
            if (solver->check() == SmtResult::Sat) {
                sat = true;
                model = solver->model();
                sum = build_sum(model);
                constant = sum->getConstantAddend();
            }
        } while (sat);
        solver->pop();
        const auto lit {arith::mkGeq(sum - arith::mkConst(constant) + n * arith::mkConst(constant), arith::mkConst(0))};
        res_lits.insert(lit);
        // block current solution
        BoolExprSet disjuncts;
        // allow coefficients with different signs
        for (const auto &pre : arith_vars) {
            const auto sign {model.get<Arith>(pre)};
            if (sign == 0) {
                disjuncts.insert(bools::mkLit(arith::mkNeq(pre, arith::mkConst(0))));
            } else if (sign < 0) {
                disjuncts.insert(bools::mkLit(arith::mkGeq(pre, arith::mkConst(0))));
            } else {
                disjuncts.insert(bools::mkLit(arith::mkLeq(pre, arith::mkConst(0))));
            }
        }
        solver->add(bools::mkOr(disjuncts));
    };
    // first handle pseudo-recurrent inequations
    for (const auto &[recurrent, non_recurrent]: pseudo_recurrent) {
        solver->push();
        for (const auto &pre: arith_vars) {
            if (recurrent->has(pre)) {
                solver->add(arith::mkNeq(pre, arith::mkConst(0)));
            } else {
                solver->add(arith::mkEq(pre, arith::mkConst(0)));
            }
        }
        if (solver->check() == SmtResult::Sat) {
            process_solution();
        } else {
            const auto val {model.eval<Arith>(non_recurrent)};
            if (val <= 0) {
                res_lits.insert(arith::mkLeq(non_recurrent, arith::mkConst(0)));
                res_lits.insert(arith::mkGeq(recurrent + non_recurrent, arith::mkConst(0)));
                if (val < 0) {
                    res_lits.insert(arith::mkGeq(recurrent - n, arith::mkConst(0)));
                }
            }
        }
        solver->pop();
    }
    // then try to infer relations of the form x - x' >= c or x' - x >= c to obtain more fully known variables
    for (const auto &pre: arith_vars) {
        if (fully_known.contains(pre)) {
            continue;
        }
        solver->push();
        for (const auto &other_pre: arith_vars) {
            if (pre != other_pre) {
                solver->add(arith::mkEq(other_pre, arith::mkConst(0)));
            }
        }
        while (solver->check() == SmtResult::Sat) {
            process_solution();
        }
        solver->pop();
    }
    Subs subs {Subs::build<Arith>(n, arith::mkConst(1))};
    force_fully_known_to_zero(loop && subs(bools::mkAndFromLits(res_lits)), fully_known, solver);
    {
        // require that at least one interesting relation is used
        ArithExprVec addends;
        for (unsigned i = 0; i < bounded.size(); ++i) {
            const auto vars {bounded[i]->vars()};
            auto has_pre {false};
            auto has_post {false};
            for (const auto &x: vars) {
                if (!fully_known.contains(x)) {
                    if (x->isProgVar()) {
                        has_pre = true;
                    } else if (x->isPostVar()) {
                        has_post = true;
                    }
                    if (has_pre && has_post) {
                        break;
                    }
                }
            }
            if (has_pre && has_post) {
                addends.push_back(factors[i]);
            }
        }
        solver->add(arith::mkGt(arith::mkPlus(std::move(addends)), arith::mkConst(0)));
    }
    // enumerate remaing solutions
    while (solver->check() == SmtResult::Sat) {
        process_solution();
    }
}

Bools::Expr TIL::recurrence_analysis(const Bools::Expr loop, const Model &model) {
    assert(loop->isConjunction());
    LitSet res_lits;
    res_lits.insert(arith::mkGt(n, arith::mkConst(0)));
    recurrent_divisibility(loop, model, res_lits);
    recurrent_pseudo_divisibility(loop, model, res_lits);
    recurrent_exps(loop, model, res_lits);
    linked_hash_set<Arith::Var> fully_known;
    recurrent_cycles(loop, res_lits, fully_known);
    recurrent_bounds(loop, model, res_lits, fully_known);
    return bools::mkAndFromLits(res_lits);
}

Bools::Expr TIL::compute_transition_invariant(const Bools::Expr pre_ctx, const Bools::Expr loop, const Bools::Expr post_ctx, Model model) {
    const auto pre{mbp_impl(loop, model, [](const auto &x) {
        return !theory::isProgVar(x);
    })};
    if (Config::Analysis::log) {
        std::cout << "pre_ctx: " << pre_ctx << std::endl;
        std::cout << "pre: " << pre << std::endl;
    }
    auto step{recurrence_analysis(pre_ctx && loop && post_ctx, model)};
    if (Config::Analysis::log) {
        std::cout << "recurrence analysis: " << step << std::endl;
    }
    const auto post{mbp_impl(loop, model, [](const auto &x) {
        return !theory::isPostVar(x);
    })};
    auto res {pre && step && post};
    return GuardToolbox::removeRedundantInequations(res);
}

void TIL::handle_loop(const Range &range) {
    auto [loop, model]{specialize(range, theory::isTempVar)};
    if (add_blocking_clauses(range, model)) {
        return;
    }
    auto context{top()};
    if (config.context_sensitive) {
        auto init{this->model.syntacticImplicant(t.init())};
        init = mbp_impl(init, this->model, [](const auto &x) {
            return !theory::isProgVar(x);
        });
        auto stem {top()};
        if (range.start() == 0) {
            stem = init;
        } else {
            const auto p{specialize(Range::from_length(0, range.start()), theory::isTempVar)};
            stem = p.first;
            const auto stem_model {p.second};
            stem = init && stem;
            stem = mbp_impl(stem, stem_model, [](const auto &x) {
                return !theory::isPostVar(x);
            });
            stem = post_to_pre(stem);
        }
        auto solver{SmtFactory::solver(QF_LA)};
        const auto subs1{get_subs(0, 1)};
        const auto subs2{get_subs(1, 1)};
        solver->add(subs1(loop) && subs2(loop));
        if (solver->check() != SmtResult::Sat) {
            const auto id{add_learned_clause(loop)};
            add_blocking_clause(range, id, loop);
            return;
        }
        const auto orig_lits{stem->lits()};
        std::vector<Lit> lits;
        for (const auto &lit : orig_lits) {
            std::visit(Overload{
                           [&](const Arith::Lit &l) {
                               if (l->isEq() && !l->isDivisibility()) {
                                   lits.push_back(arith::mkLeq(l->lhs(), arith::mkConst(0)));
                                   lits.push_back(arith::mkGeq(l->lhs(), arith::mkConst(0)));
                               } else {
                                   lits.push_back(l);
                               }
                           },
                           [&](const auto &) {
                               lits.push_back(lit);
                           }},
                       lit);
        }
        LitSet context_lits;
        for (const auto &lit : lits) {
            solver->push();
            solver->add(subs1(lit));
            solver->add(subs2(lit));
            if (solver->check() == SmtResult::Sat) {
                context_lits.insert(lit);
            } else {
                solver->pop();
            }
        }
        context = bools::mkAndFromLits(context_lits);
    }
    auto ti{compute_transition_invariant(context, loop, top(), model)};
    model.put<Arith>(n, 1);
    const auto projected {mbp_impl(ti, model, [&](const auto &x) {
        return x == Var(n);
    })};
    const auto id{add_learned_clause(ti)};
    if (range.length() == 1) {
        projections.emplace_back(id, projected);
    } else {
        add_blocking_clause(range, id, projected);
    }
}

Bools::Expr TIL::encode_transition(const Bools::Expr &t, const Int &id) {
    return t && theory::mkEq(trace_var, arith::mkConst(id));
}

void TIL::add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) {
    const auto s{get_subs(range.start(), range.length())};
    auto it {blocked_per_step.emplace(range.start(), top()).first};
    if (range.length() == 1) {
        it->second = it->second && s(!loop || bools::mkLit(arith::mkGeq(trace_var, arith::mkConst(id))));
    } else {
        it->second = it->second && s(!loop);
    }
}

bool TIL::add_blocking_clauses(const Range &range, Model model) {
    Subs m {model.toSubs()};
    const auto s{get_subs(range.start(), range.length())};
    const auto nn {*s.get<Arith>(n)->isVar()};
    m.erase(nn);
    auto solver {SmtFactory::modelBuildingSolver(QF_LA)};
    for (const auto &[id, b] : blocked) {
        if (range.length() == 1 && id <= last_orig_clause) {
            continue;
        }
        auto block{s(b)};
        if (b->vars().contains(n)) {
            solver->push();
            solver->add(m(block));
            if (solver->check() == SmtResult::Sat) {
                const auto n_val {solver->model({{nn}}).get<Arith>(nn)};
                model.put<Arith>(nn, n_val);
                const auto projected {mbp_impl(block, model, [&](const auto &x) {
                    return x == Var(nn);
                })};
                add_blocking_clause(range, id, projected);
                return true;
            }
            solver->pop();
        } else if (model.eval<Bools>(block)) {
            add_blocking_clause(range, id, block);
        }
    }
    return false;
}

void TIL::add_blocking_clauses() {
    const auto s1 {get_subs(depth, 1)};
    const auto s2 {get_subs(depth, 2)};
    for (const auto &[id, b] : projections) {
        solver->add(s1(!b) || bools::mkLit(arith::mkGeq(s1.get<Arith>(trace_var), arith::mkConst(id))));
        solver->add(s2(!b));
    }
    const auto it {blocked_per_step.find(depth)};
    if (it != blocked_per_step.end()) {
        solver->add(it->second);
    }
}

void TIL::unknown() {
    const auto str{"unknown"};
    std::cout << str << std::endl;
    proof.result(str);
    proof.print();
}

void TIL::sat() {
    const auto str{"sat"};
    std::cout << str << std::endl;
    proof.append(std::to_string(depth) + "-fold unrolling of the transition relation is unsatisfiable");
    proof.result(str);
    proof.print();
}

void TIL::build_trace() {
    trace.clear();
    model = solver->model();
    std::optional<std::pair<Bools::Expr, Int>> prev;
    for (unsigned d = 0; d < depth; ++d) {
        const auto s{get_subs(d, 1)};
        const auto id{model.eval<Arith>(s.get<Arith>(trace_var))};
        const auto rule{rule_map.left.at(id)};
        const auto comp{model.composeBackwards(s)};
        const auto imp{comp.syntacticImplicant(rule) && theory::mkEq(trace_var, arith::mkConst(id))};
        auto relevant_vars{vars};
        for (const auto &x : vars) {
            relevant_vars.insert(theory::postVar(x));
        }
        imp->collectVars(relevant_vars);
        const auto projected_model{comp.project(relevant_vars)};
        if (prev) {
            dependency_graph.addEdge(prev->first, imp);
        }
        prev = {imp, id};
        trace.emplace_back(TraceElem{.id = id, .implicant = imp, .model = projected_model});
    }
    if (Config::Analysis::log) {
        std::cout << "trace:" << std::endl;
        for (const auto &t : trace) {
            std::cout << t.implicant << std::endl;
        }
        std::cout << "trace var: " << trace_var << std::endl;
        std::cout << "run:" << std::endl;
        for (const auto &t : trace) {
            std::cout << t.model << std::endl;
        }
    }
}

const Subs &TIL::get_subs(const unsigned start, const unsigned steps) {
    if (subs.empty()) {
        subs.push_back({Subs()});
    }
    while (subs.size() < start + steps) {
        Subs s;
        for (const auto &var : vars) {
            if (theory::isProgVar(var)) {
                const auto post_var{theory::postVar(var)};
                s.put(var, subs.back()[0].get(post_var));
                s.put(post_var, theory::toExpr(theory::next(post_var)));
            } else {
                s.put(var, theory::toExpr(theory::next(var)));
            }
        }
        subs.push_back({s});
    }
    auto &pre_vec{subs.at(start)};
    while (pre_vec.size() < steps) {
        auto &post{subs.at(start + pre_vec.size()).front()};
        Subs s;
        for (const auto &var : vars) {
            s.put(var, pre_vec.front().get(var));
            if (theory::isProgVar(var)) {
                const auto post_var{theory::postVar(var)};
                s.put(post_var, post.get(post_var));
            }
        }
        pre_vec.push_back(s);
    }
    // if (changed) {
    //     int from{0};
    //     for (const auto &vec : subs) {
    //         int to{from + 1};
    //         for (const auto &s : vec) {
    //             std::cout << from << " to " << to << ": " << s << std::endl;
    //             ++to;
    //         }
    //         ++from;
    //     }
    // }
    return pre_vec.at(steps - 1);
}

void TIL::pop() {
    solver->pop();
    --depth;
}

bool TIL::setup() {
    if (Config::Analysis::log) {
        std::cout << "initial problem" << std::endl;
        std::cout << t << std::endl;
    }
    // proof.majorProofStep("Initial ITS", ITSProof(), its);
    const auto res{Preprocess::preprocess(t)};
    if (res) {
        proof.concat(res.getProof());
        t = *res;
        if (Config::Analysis::log) {
            std::cout << "Simplified Problem" << std::endl;
            std::cout << t << std::endl;
        }
    }
    std::vector<Bools::Expr> steps;
    for (const auto &trans : t.trans()) {
        const auto encoded {encode_transition(trans, next_id)};
        rule_map.left.insert(rule_map_t::left_value_type(next_id, encoded));
        steps.push_back(encoded);
        blocked.emplace_back(next_id, trans);
        ++next_id;
    }
    last_orig_clause = next_id - 1;
    step = bools::mkOr(steps);
    solver->add(t.init());
    solver->push();
    auto s{get_subs(depth, 1)};
    {
        solver->push();
        solver->add(s(t.err()));
        if (solver->check() != SmtResult::Unsat) {
            return false;
        }
        solver->pop();
    }
    return true;
}

std::optional<SmtResult> TIL::do_step() {
    solver->push();
    auto s{get_subs(depth, 1)};
    solver->add(s(step));
    add_blocking_clauses();
    ++depth;
    switch (solver->check()) {
    case SmtResult::Unsat:
        return SmtResult::Sat;
    case SmtResult::Unknown:
        std::cerr << "unknown from SMT solver" << std::endl;
        return SmtResult::Unknown;
    case SmtResult::Sat: {
        build_trace();
        s = get_subs(depth, 1);
        // push error states
        solver->push();
        solver->add(s(t.err()));
        switch (solver->check()) {
        case SmtResult::Sat:
            build_trace();
            return SmtResult::Unknown;
        case SmtResult::Unknown:
            std::cerr << "unknown from SMT solver" << std::endl;
            return SmtResult::Unknown;
        case SmtResult::Unsat: {
            // pop error states
            solver->pop();
            if (Config::Analysis::log) {
                std::cout << "starting loop handling" << std::endl;
            }
            const auto range{has_looping_infix()};
            if (range) {
                if (Config::Analysis::log) {
                    std::cout << "found loop: " << range->start() << " to " << range->end() << std::endl;
                }
                handle_loop(*range);
                while (depth > range->start()) {
                    pop();
                }
            }
            if (Config::Analysis::log) {
                std::cout << "done with loop handling" << std::endl;
            }
            break;
        }
        }
    }
    }
    if (Config::Analysis::log) {
        std::cout << "depth: " << depth << std::endl;
    }
    return {};
}

void TIL::analyze() {
    if (!setup()) {
        unknown();
        return;
    }
    while (true) {
        const auto res {do_step()};
        if (res) {
            if (res == SmtResult::Sat) {
                sat();
            } else {
                unknown();
            }
            return;
        }
    }
}

void TIL::analyze(SafetyProblem &its) {
    TIL(its, Config::til).analyze();
}
