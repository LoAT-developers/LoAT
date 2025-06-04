#include "trputil.hpp"
#include "formulapreprocessing.hpp"
#include "config.hpp"
#include "rulepreprocessing.hpp"
#include "loopacceleration.hpp"
#include "intmbp.hpp"
#include "realqe.hpp"
#include "safetycex.hpp"
#include "opensmt.hpp"

#include <stack>

const Config::TRPConfig TRPUtil::forwardConfig{
    .mbpKind = Config::TRPConfig::LowerIntMbp,
    .recurrent_cycles = false,
    .recurrent_exps = true,
    .recurrent_pseudo_divs = true,
    .recurrent_pseudo_bounds = true,
    .recurrent_bounds = true};

const Config::TRPConfig TRPUtil::backwardConfig{
    .mbpKind = Config::TRPConfig::RealMbp,
    .recurrent_cycles = false,
    .recurrent_exps = true,
    .recurrent_pseudo_divs = false,
    .recurrent_pseudo_bounds = true,
    .recurrent_bounds = true};

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

TRPUtil::LearnedTransInfo::LearnedTransInfo(
    const std::vector<std::pair<Int, Bools::Expr>> &loop):
    loop(loop) {}

TRPUtil::TransInfo::TransInfo(
    const Bools::Expr t,
    const Bools::Expr abstraction):
    t(t),
    abstraction(abstraction)  {}

Bools::Expr abstract(const Bools::Expr &t) {
    return t->map([](const auto &lit) {
        return std::visit(
            Overload{
                [](const Bools::Lit &) {
                    return top();
                },
                [](const Arith::Lit &x) {
                    return bools::mkLit(x);
                }},
            lit);
    });
}

TRPUtil::TRPUtil(
    const ITSPtr its,
    const Config::TRPConfig &config)
    : mbp_kind(config.mbpKind),
      its2safety(its),
      t(its2safety.transform()),
      its(its),
      trp(t.pre_to_post(), config) {
    if (Config::Analysis::log) {
        std::cout << "safetyproblem:\n"
                  << t << std::endl;
    }
    auto vars{t.vars()};
    vars.insert(trace_var);
    vars.insert(trp.get_n());
    if (Config::Analysis::termination()) {
        vars.insert(safety_var);
    }
    renaming_central = RenamingCentral(vars);
    const auto linearize_if_term =
        [&](const auto trans) {
            if (Config::Analysis::termination()) {
                return trans->map([&](const auto &lit) {
                    return std::visit(
                        Overload{
                            [](const Arith::Lit &l) {
                                if (!l->isLinear()) {
                                    return top();
                                } else {
                                    return bools::mkLit(l);
                                }
                            },
                            [](const auto &l) {
                                return bools::mkLit(l);
                            }},
                        lit);
                });
            } else {
                return trans;
            }
        };
    for (const auto &trans : t.trans()) {
        const auto lin {linearize_if_term(trans)};
        const TransInfo info {lin, abstract(lin)};
        rule_map.emplace(next_id, info);
        ++next_id;
    }
    solver->add(linearize_if_term(t.init()));
}

std::pair<Bools::Expr, Model> TRPUtil::compress(const Range &range) {
    std::optional<Bools::Expr> loop;
    Renaming var_renaming;
    for (long i = static_cast<long>(range.end()); i >= 0 && i >= static_cast<long>(range.start()); --i) {
        const auto rule{trace[i].implicant};
        const auto s{renaming_central->get_subs(i, 1)};
        if (loop) {
            // sigma1 maps vars from chained to the corresponding vars from rule
            // sigma2 maps vars from chained to the corresponding vars from loop
            // temporary variables in rule remain unchanged
            // temporary variables in loop that clash with rule are renamed
            const auto [chained, sigma1, sigma2]{Preprocess::chain(rule, *loop)};
            // all pre-vars and temp vars that already occured in rule correspond to vars from rule
            auto fst_vars{t.pre_vars()};
            rule->collectVars(fst_vars);
            for (const auto &x : t.post_vars()) {
                fst_vars.erase(x);
            }
            // map them to the corresponding SMT vars by taking sigma1 and s (the var renaming that
            // was used for the step with rule) into account
            auto fst_var_renaming{sigma1.compose(s).project(fst_vars)};
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

Bools::Expr TRPUtil::encode_transition(const Bools::Expr &t, const Int &id) {
    return t && theory::mkEq(trace_var, arith::mkConst(id));
}

Int TRPUtil::add_learned_clause(const Range &range, const Bools::Expr &accel) {
    if (Config::Analysis::log) {
        std::cout << "learned transition: " << accel << " with id " << next_id << std::endl;
    }
    const auto id = next_id;
    ++next_id;
    std::vector<std::pair<Int, Bools::Expr>> loop;
    for (size_t i = range.start(); i <= range.end(); ++i) {
        const auto &e {trace.at(i)};
        loop.emplace_back(e.id, e.model.specialize(rule_map.at(e.id).t));
        rule_map.at(e.id).offsprings.insert(id);
    }
    TransInfo info{accel, accel};
    rule_map.emplace(id, info);
    learned_rule_map.emplace(id, LearnedTransInfo(loop));
    return id;
}

Bools::Expr TRPUtil::specialize(const Bools::Expr e, const Model &model, const std::function<bool(const Var &)> &eliminate) {
    const auto sip{model.syntacticImplicant(e)};
    if (Config::Analysis::log) {
        std::cout << "sip: " << sip << std::endl;
    }
    auto simp{Preprocess::preprocessFormula(sip)};
    if (Config::Analysis::log && simp != sip) {
        std::cout << "simp: " << simp << std::endl;
    }
    const auto mbp_res{trp.mbp(simp, model, eliminate)};
    if (Config::Analysis::log && mbp_res != simp) {
        std::cout << "mbp: " << mbp_res << std::endl;
    }
    return mbp_res;
}

std::pair<Bools::Expr, Model> TRPUtil::specialize(const Range &range, const std::function<bool(const Var &)> &eliminate) {
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

std::optional<Arith::Expr> TRPUtil::prove_term(const Bools::Expr loop, const Model &model) {
    const auto &m {model.get<Arith>()};
    const auto &ptp {t.pre_to_post().get<Arith>()};
    const auto lits {loop->lits().get<Arith::Lit>()};
    for (const auto &l: lits) {
        if (l->isGt()) {
            const auto lhs {l->lhs()};
            const auto vars {lhs->vars()};
            if (std::all_of(vars.begin(), vars.end(), theory::isProgVar) && lhs->eval(m) > lhs->renameVars(ptp)->eval(m)) {
                if (Config::Analysis::log) {
                    std::cout << "found ranking function " << lhs << std::endl;
                }
                return lhs;
            } else if (std::all_of(vars.begin(), vars.end(), theory::isPostVar) && lhs->renameVars(renaming_central->post_to_pre().get<Arith>())->eval(m) > lhs->eval(m)) {
                if (Config::Analysis::log) {
                    std::cout << "found ranking function " << lhs << std::endl;
                }
                return lhs;
            }
        }
    }
    auto solver {SmtFactory::modelBuildingSolver(Logic::QF_LA)};
    std::vector<Arith::Expr> bounded;
    std::vector<Arith::Expr> decreasing;
    std::unordered_map<Arith::Var, Arith::Var> coeffs;
    for (const auto &[pre,post]: ptp) {
        if (pre == its->getLocVar() || !m.contains(pre) || !m.contains(post)) {
            continue;
        }
        const auto coeff {ArithVar::next()};
        coeffs.emplace(pre, coeff);
        const auto pre_val {arith::mkConst(m.at(pre))};
        const auto post_val {arith::mkConst(m.at(post))};
        bounded.emplace_back(arith::toExpr(coeff) * pre_val);
        decreasing.emplace_back(arith::toExpr(coeff) * pre_val - arith::toExpr(coeff) * post_val);
    }
    solver->add(arith::mkGt(arith::mkPlus(std::move(bounded)), arith::mkConst(0)));
    solver->add(arith::mkGt(arith::mkPlus(std::move(decreasing)), arith::mkConst(0)));
    if (solver->check() == SmtResult::Sat) {
        const auto rf_model {solver->model().get<Arith>()};
        std::vector<Arith::Expr> addends;
        for (const auto &[x,coeff]: coeffs) {
            if (const auto val {rf_model.get(coeff)}) {
                addends.emplace_back(arith::mkConst(*val) * arith::toExpr(x));
            }
        }
        const auto rf {arith::mkPlus(std::move(addends))};
        if (Config::Analysis::log) {
            std::cout << "found ranking function " << rf << std::endl;
        }
        return rf;
    }
    return {};
}

std::optional<std::variant<std::vector<std::pair<Int, Bools::Expr>>, std::unordered_map<Int, Bools::Expr>>> TRPUtil::build_trace_for_refinement(const Model &m, const size_t depth) {
    std::vector<std::pair<Int, Bools::Expr>> trace;
    std::vector<opensmt::ipartitions_t> partitions;
    OpenSmt solver {true};
    solver.add(m.specialize(t.init()));
    opensmt::ipartitions_t mask {0};
    opensmt::setbit(mask, 0);
    partitions.emplace_back(mask);
    const auto interpolate = [&] (const auto &d) {
        opensmt::ipartitions_t mask {0};
        // 2 * d as popped assertions count as well
        opensmt::setbit(mask, 2 * d + 1);
        partitions.emplace_back(mask);
        const auto itps {solver.interpolate_path(partitions)};
        std::cout << "INTERPOLANTS:" << std::endl;
        for (const auto &i: itps) {
            std::cout << i << std::endl;
        }
        std::unordered_map<Int, Bools::Expr> res;
        for (size_t i = 0; i < d; ++i) {
            const auto id {trace.at(i).first};
            auto itp {itps.at(i)};
            if (i + 1 < itps.size()) {
                itp = itp && itps.at(i+1);
            }
            itp = renaming_central->get_subs(i, 1).invert()(itp);
            auto [it,changed] {res.emplace(id, itp)};
            if (!changed) {
                it->second = it->second || itp;
            }
        }
        return res;
    };
    for (unsigned d = 0; d < depth; ++d) {
        const auto s{renaming_central->get_subs(d, 1)};
        const auto id{m.eval<Arith>(s.get<Arith>(trace_var))};
        const auto rule{rule_map.at(id).t && theory::mkEq(trace_var, arith::mkConst(id))};
        const auto comp {m.composeBackwards(s)};
        const auto spec {comp.specialize(rule)};
        switch (SmtFactory::check(spec)) {
            case SmtResult::Unknown: {
                return std::nullopt;
            }
            case SmtResult::Unsat: {
                std::cout << "CONCRETIZATION OF TRANSITION FAILED, COMPUTING UNSAT CORE" << std::endl;
                OpenSmt solver{false};
                solver.add(rule);
                for (const auto &lit : rule->lits()) {
                    if (comp.partialEval(lit) == TVL::FALSE) {
                        solver.add(!bools::mkLit(lit));
                    }
                }
                const auto res{solver.check()};
                assert(res == SmtResult::Unsat);
                auto core{solver.unsatCore()};
                core.erase(rule);
                return {{std::unordered_map{std::pair{id, !bools::mkAnd(core)}}}};
            }
            case SmtResult::Sat: {
                break;
            }
        }
        solver.push();
        solver.add(s(spec));
        switch (solver.check()) {
            case SmtResult::Unknown: {
                return std::nullopt;
            }
            case SmtResult::Unsat: {
                std::cout << "CONCRETIZATION OF TRACE FAILED, COMPUTING PATH INTERPOLANT" << std::endl;
                return interpolate(d);
            }
            case SmtResult::Sat: {
                const auto model {solver.model().composeBackwards(s)};
                const auto imp {trp.mbp(model.syntacticImplicant(spec), model, theory::isTempVar)};
                trace.emplace_back(id, imp);
                solver.pop();
                solver.add(s(imp));
                opensmt::ipartitions_t mask {0};
                // 2 * d as popped assertions count as well
                opensmt::setbit(mask, 2 * d + 2);
                partitions.emplace_back(mask);
                break;
            }
        }
    }
    const auto s {renaming_central->get_subs(depth, 1)};
    solver.add(m.specialize(s(t.err())));
    switch (solver.check()) {
        case SmtResult::Unknown: {
            return std::nullopt;
        }
        case SmtResult::Unsat: {
            std::cout << "CONCRETIZATION OF ERROR TRACE FAILED, COMPUTING PATH INTERPOLANT" << std::endl;
            return interpolate(depth);
        }
        case SmtResult::Sat: {
            break;
        }
    }
    return trace;
}

bool TRPUtil::build_cex(const std::vector<std::pair<Int, Bools::Expr>> &trace) {
    safe = false;
    if (trace.empty()) {
        return SmtFactory::check(t.init() && t.err()) == SmtResult::Sat;
    }
    std::stack<Int> todo;
    for (const auto &[id,_]: trace) {
        const auto it {learned_rule_map.find(id)};
        if (it != learned_rule_map.end() && !it->second.accel) {
            todo.push(id);
        }
    }
    Subs up;
    Renaming post_to_tmp;
    for (const auto &[pre, post]: t.pre_to_post()) {
        const auto tmp {theory::next(post)};
        up.put(pre, theory::toExpr(tmp));
        post_to_tmp.insert(post, tmp);
    }
    Renaming tmp_to_post {post_to_tmp.invert()};
    while (!todo.empty()) {
        const auto current {todo.top()};
        auto &info {learned_rule_map.at(current)};
        auto ready {true};
        for (const auto &[id,_]: info.loop) {
            const auto it {learned_rule_map.find(id)};
            if (it != learned_rule_map.end() && !it->second.accel) {
                todo.push(id);
                ready = false;
            }
        }
        if (!ready) {
            continue;
        }
        todo.pop();
        std::optional<Bools::Expr> trans;
        for (const auto &[next_id, next_t]: info.loop) {
            const auto next_it {learned_rule_map.find(next_id)};
            const auto next = next_it == learned_rule_map.end() ? next_t : *next_it->second.accel;
            trans = trans ? std::get<Bools::Expr>(Preprocess::chain(*trans, next)) : next;
        }
        if (SmtFactory::check(*trans) != SmtResult::Sat) {
            if (Config::Analysis::log) {
                std::cout << "loop is unsat" << std::endl;
            }
            return false;
        }
        const auto guard {post_to_tmp(*trans)};
        const auto rule {Preprocess::preprocessRule(Rule::mk(guard, up))};
        if (Config::Analysis::log) {
            std::cout << "accelerating " << *rule << std::endl;
        }
        const auto accel_res {LoopAcceleration::accelerate(rule, AccelConfig{
            false,
            true,
            Config::Accel::non_linear,
            ArithVar::next(),
            arith::mkConst(0)
        })};
        if (accel_res.accel) {
            if (Config::Analysis::log) {
                std::cout << "got " << *accel_res.accel->rule << std::endl;
            }
            std::vector<Bools::Expr> conjuncts {accel_res.accel->rule->getGuard()};
            const auto &accel_up {accel_res.accel->rule->getUpdate()};
            for (const auto &[pre,post]: t.pre_to_post()) {
                if (accel_up.contains(pre)) {
                    conjuncts.push_back(theory::mkEq(theory::toExpr(post), accel_up.get(pre)));
                } else {
                    conjuncts.push_back(theory::mkEq(theory::toExpr(post), theory::toExpr(pre)));
                }
            }
            info.accel = tmp_to_post(bools::mkAnd(conjuncts));
        } else {
            if (Config::Analysis::log) {
                std::cout << "acceleration failed" << std::endl;
            }
            info.accel = *trans;
        }
    }
    std::optional<Bools::Expr> trans;
    for (const auto &[id,implicant]: trace) {
        const auto it {learned_rule_map.find(id)};
        const auto next = it == learned_rule_map.end() ? implicant : *it->second.accel;
        trans = trans ? std::get<Bools::Expr>(Preprocess::chain(*trans, next)) : next;
    }
    return SmtFactory::check(t.init() && *trans && t.pre_to_post()(t.err())) == SmtResult::Sat;
}

bool TRPUtil::add_blocking_clauses(const Range &range, Model model) {
    Subs m{model.toSubs()};
    m.erase(trp.get_n());
    auto solver{SmtFactory::modelBuildingSolver(QF_LA)};
    const auto n {trp.get_n()};
    for (const auto &[id, info] : rule_map) {
        const auto is_orig_clause {!learned_rule_map.contains(id)};
        if (Config::Analysis::termination() && is_orig_clause) {
            continue;
        }
        if (range.length() == 1 && is_orig_clause) {
            continue;
        }
        const auto abstr {encode_transition(info.abstraction, id)};
        const auto vars {abstr->vars()};
        if (is_orig_clause && std::any_of(vars.begin(), vars.end(), theory::isTempVar)) {
            continue;
        }
        if (vars.contains(n)) {
            solver->push();
            solver->add(m(abstr));
            if (solver->check() == SmtResult::Sat) {
                const auto n_val{solver->model({{n}}).get<Arith>(n)};
                model.put<Arith>(n, n_val);
                Bools::Expr projected{mbp::int_mbp(abstr, model, mbp_kind, [&](const auto &x) {
                    return x == Var(n);
                })};
                add_blocking_clause(range, id, projected);
                return true;
            }
            solver->pop();
        } else if (model.eval<Bools>(abstr)) {
            add_blocking_clause(range, id, abstr);
            return true;
        }
    }
    return false;
}

ITSSafetyCex TRPUtil::get_cex() {
    SafetyCex res{t};
    const auto &trans {t.trans()};
    const auto depth {trace.size()};
    for (size_t i = 0; i < depth; ++i) {
        auto m{model.composeBackwards(renaming_central->get_subs(i, 1))};
        const auto it{std::find_if(trans.begin(), trans.end(), [&](const auto &c) {
            return res.try_step(m, c);
        })};
        if (it == trans.end()) {
            throw std::logic_error("get_cex failed");
        }
    }
    res.set_final_state(model.composeBackwards(renaming_central->get_subs(depth, 1)));
    return its2safety.transform_cex(res);
}
