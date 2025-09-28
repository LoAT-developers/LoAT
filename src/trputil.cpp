#include "trputil.hpp"

#include <ranges>

#include "formulapreprocessing.hpp"
#include "config.hpp"
#include "rulepreprocessing.hpp"
#include "loopacceleration.hpp"
#include "intmbp.hpp"
#include "safetycex.hpp"

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
    return {start, start + length - 1};
}

Range Range::from_interval(const unsigned start, const unsigned end) {
    return {start, end};
}

TRPUtil::TRPUtil(
    const ITSPtr &its,
    const Config::TRPConfig &config)
    : mbp_kind(config.mbpKind),
      its2safety(its),
      t(its2safety.transform()),
      its(its),
      trp(t.pre_to_post(), config),
      post_to_pre(t.pre_to_post().invert()),
      last_orig_clause(t.trans().size() - 1) {
    if (Config::Analysis::log) {
        std::cout << "safetyproblem:\n"
                  << t << std::endl;
    }
    vars.insert(trace_var);
    vars.insert(trp.get_n());
    if (Config::Analysis::termination()) {
        vars.insert(safety_var);
    }
    for (const auto &x : t.vars()) {
        theory::apply(x, [&](const auto &x) {
            vars.insert(x->isPostVar() ? x->progVar(x) : x);
        });
    }
    solver->enableModels();
    if (Config::Analysis::termination()) {
        const auto linearize{
            [&](const auto& lit) {
                return std::visit(
                    Overload{
                        [](const Arith::Lit& l) {
                            if (!l->isLinear()) {
                                return top();
                            }
                            return bools::mkLit(l);
                        },
                        [](const auto& l) {
                            return bools::mkLit(l);
                        }
                    },
                    lit);
            }
        };
        for (const auto &trans : t.trans()) {
            if (const auto lin{trans->map(linearize)}; rule_map.emplace(next_id, lin).second) {
                ++next_id;
            }
        }
        solver->add(t.init()->map(linearize));
    } else {
        for (const auto &trans : t.trans()) {
            if (rule_map.emplace(next_id, trans).second) {
                ++next_id;
            }
        }
        solver->add(t.init());
    }
}

const Renaming &TRPUtil::get_subs(const unsigned start, const unsigned steps) {
    if (subs.empty()) {
        subs.push_back({Renaming()});
    }
    while (subs.size() < start + steps) {
        Renaming s;
        for (const auto &var : vars) {
            if (theory::isProgVar(var)) {
                const auto post_var{theory::postVar(var)};
                s.insert(var, subs.back()[0].get(post_var));
                s.insert(post_var, theory::next(post_var));
            } else {
                s.insert(var, theory::next(var));
            }
        }
        subs.push_back({s});
    }
    auto &pre_vec{subs.at(start)};
    while (pre_vec.size() < steps) {
        auto &post{subs.at(start + pre_vec.size()).front()};
        Renaming s;
        for (const auto &var : vars) {
            s.insert(var, pre_vec.front().get(var));
            if (theory::isProgVar(var)) {
                const auto post_var{theory::postVar(var)};
                s.insert(post_var, post.get(post_var));
            }
        }
        pre_vec.push_back(s);
    }
    return pre_vec.at(steps - 1);
}

std::pair<Bools::Expr, ModelPtr> TRPUtil::compress(const Range &range) {
    std::optional<Bools::Expr> loop;
    Renaming var_renaming;
    for (long i = range.end(); i >= 0 && i >= static_cast<long>(range.start()); --i) {
        const auto rule{trace[i].implicant};
        const auto s{get_subs(i, 1)};
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
    const auto m{model->composeBackwards(var_renaming)};
    return {*loop, m};
}

Bools::Expr TRPUtil::encode_transition(const Bools::Expr &t, const Int &id) const {
    return t && theory::mkEq(trace_var, arith::mkConst(id));
}

Int TRPUtil::add_learned_clause(const Range &range, const Bools::Expr &accel) {
    if (Config::Analysis::log) {
        std::cout << "learned transition: " << accel << " with id " << next_id << std::endl;
    }
    const auto id = next_id;
    ++next_id;
    rule_map.emplace(id, accel);
    std::vector<std::pair<Int, Bools::Expr>> loop;
    for (size_t i = range.start(); i <= range.end(); ++i) {
        const auto &e {trace.at(i)};
        loop.emplace_back(e.id, e.implicant);
    }
    learned_to_loop.emplace(id, loop);
    return id;
}

Bools::Expr TRPUtil::specialize(const Bools::Expr& e, const ModelPtr &model, const std::function<bool(const Var &)> &eliminate) const {
    const auto sip{model->syntacticImplicant(e)};
    if (Config::Analysis::log) {
        std::cout << "sip: " << sip << std::endl;
    }
    const auto simp{Preprocess::preprocessFormula(sip)};
    if (Config::Analysis::log && simp != sip) {
        std::cout << "simp: " << simp << std::endl;
    }
    const auto mbp_res{trp.mbp(simp, model, eliminate)};
    if (Config::Analysis::log && mbp_res != simp) {
        std::cout << "mbp: " << mbp_res << std::endl;
    }
    return mbp_res;
}

std::pair<Bools::Expr, ModelPtr> TRPUtil::specialize(const Range &range, const std::function<bool(const Var &)> &eliminate) {
    assert (!range.empty());
    const auto [transition, model]{compress(range)};
    if (Config::Analysis::log) {
        std::cout << "compressed:" << std::endl;
        std::cout << transition << std::endl;
        std::cout << "model: " << model << std::endl;
    }
    return {specialize(transition, model, eliminate), model};
}

std::optional<Arith::Expr> TRPUtil::prove_term(const Bools::Expr& loop, const ModelPtr &model) {
    const auto &ptp {t.pre_to_post().get<Arith>()};
    for (const auto lits {loop->lits().get<Arith::Lit>()}; const auto &l: lits) {
        if (l->isGt()) {
            auto lhs{l->lhs()};
            if (const auto vars{lhs->vars()};
                (std::ranges::all_of(vars, theory::isProgVar) && model->eval(lhs) > model->eval(lhs->renameVars(ptp)))
                || (std::ranges::all_of(vars, theory::isPostVar) && model->eval(
                    lhs->renameVars(post_to_pre.get<Arith>())) > model->eval(lhs))) {
                if (Config::Analysis::log) {
                    std::cout << "found ranking function " << lhs << std::endl;
                }
                return lhs;
            }
        }
    }
    const auto solver {SmtFactory::modelBuildingSolver(QF_LA)};
    std::vector<Arith::Expr> bounded;
    std::vector<Arith::Expr> decreasing;
    std::unordered_map<Arith::Var, Arith::Var> coeffs;
    for (const auto &[pre,post]: ptp) {
        if (pre == its->getLocVar() || !model->contains(pre) || !model->contains(post)) {
            continue;
        }
        const auto coeff {ArithVar::next()};
        coeffs.emplace(pre, coeff);
        const auto pre_val {arith::mkConst(model->get(pre))};
        const auto post_val {arith::mkConst(model->get(post))};
        bounded.emplace_back(coeff->toExpr() * pre_val);
        decreasing.emplace_back(coeff->toExpr() * pre_val - coeff->toExpr() * post_val);
    }
    solver->add(arith::mkGt(arith::mkPlus(std::move(bounded)), arith::mkConst(0)));
    solver->add(arith::mkGt(arith::mkPlus(std::move(decreasing)), arith::mkConst(0)));
    if (solver->check() == SmtResult::Sat) {
        const auto rf_model {solver->model()};
        std::vector<Arith::Expr> addends;
        for (const auto &[x,coeff]: coeffs) {
            if (rf_model->contains(coeff)) {
                addends.emplace_back(arith::mkConst(rf_model->get(coeff)) * x->toExpr());
            }
        }
        auto rf {arith::mkPlus(std::move(addends))};
        if (Config::Analysis::log) {
            std::cout << "found ranking function " << rf << std::endl;
        }
        return rf;
    }
    return {};
}

bool TRPUtil::build_cex() {
    safe = false;
    if (trace.empty()) {
        return SmtFactory::check(t.init() && t.err()) == SmtResult::Sat;
    }
    std::stack<Int> todo;
    for (const auto &e: trace) {
        if (e.id > last_orig_clause && !accel.contains(e.id)) {
            todo.push(e.id);
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
        const auto &loop {learned_to_loop.at(current)};
        auto ready {true};
        for (const auto& id : loop | std::views::keys) {
            if (id > last_orig_clause && !accel.contains(id)) {
                todo.push(id);
                ready = false;
            }
        }
        if (!ready) {
            continue;
        }
        todo.pop();
        std::optional<Bools::Expr> trans;
        for (const auto &[next_id, next_t]: loop) {
            const auto next = next_id > last_orig_clause ? accel.at(next_id) : next_t;
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
            std::vector conjuncts {accel_res.accel->rule->getGuard()};
            const auto &accel_up {accel_res.accel->rule->getUpdate()};
            for (const auto &[pre,post]: t.pre_to_post()) {
                if (accel_up.contains(pre)) {
                    conjuncts.push_back(theory::mkEq(theory::toExpr(post), accel_up.get(pre)));
                } else {
                    conjuncts.push_back(theory::mkEq(theory::toExpr(post), theory::toExpr(pre)));
                }
            }
            accel.put(current, tmp_to_post(bools::mkAnd(conjuncts)));
        } else {
            if (Config::Analysis::log) {
                std::cout << "acceleration failed" << std::endl;
            }
            accel.put(current, *trans);
        }
    }
    std::optional<Bools::Expr> trans;
    for (const auto &e: trace) {
        const auto next = e.id > last_orig_clause ? accel.at(e.id) : e.implicant;
        trans = trans ? std::get<Bools::Expr>(Preprocess::chain(*trans, next)) : next;
    }
    return SmtFactory::check(t.init() && *trans && t.pre_to_post()(t.err())) == SmtResult::Sat;
}

bool TRPUtil::add_blocking_clauses(const Range &range, const ModelPtr& model) {
    const auto n {trp.get_n()};
    model->put(n, 1);
    for (const auto &[id, b] : rule_map) {
        const auto is_orig_clause {id <= last_orig_clause};
        if (Config::Analysis::termination() && is_orig_clause) {
            continue;
        }
        if (range.length() == 1 && is_orig_clause) {
            continue;
        }
        if (const auto vars {b->vars()}; is_orig_clause && std::any_of(vars.begin(), vars.end(), theory::isTempVar)) {
            continue;
        }
        if (model->eval(b)) {
            add_blocking_clause(range, id, b);
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
        auto m{model->composeBackwards(get_subs(i, 1))};
        const auto it{std::ranges::find_if(trans, [&](const auto &c) {
            return res.try_step(m, c);
        })};
        if (it == trans.end()) {
            throw std::logic_error("get_cex failed");
        }
    }
    res.set_final_state(model->composeBackwards(get_subs(depth, 1)));
    return its2safety.transform_cex(res);
}
