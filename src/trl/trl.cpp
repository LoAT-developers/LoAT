#include "trl.hpp"
#include "cvc5.hpp"
#include "dependencygraph.hpp"
#include "formulapreprocessing.hpp"
#include "intmbp.hpp"
#include "itstosafetyproblem.hpp"
#include "linkedhashmap.hpp"
#include "optional.hpp"
#include "pair.hpp"
#include "realmbp.hpp"
#include "theory.hpp"
#include "safetycex.hpp"
#include "eliminate.h"
#include "realqe.hpp"
#include "loopacceleration.hpp"
#include "rulepreprocessing.hpp"

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

const Config::TRPConfig TRL::forwardConfig{
    .mbpKind = Config::TRPConfig::LowerIntMbp,
    .recurrent_cycles = false,
    .recurrent_exps = true,
    .recurrent_pseudo_divs = true,
    .recurrent_pseudo_bounds = true,
    .recurrent_bounds = true};

const Config::TRPConfig TRL::backwardConfig{
    .mbpKind = Config::TRPConfig::RealMbp,
    .recurrent_cycles = false,
    .recurrent_exps = true,
    .recurrent_pseudo_divs = false,
    .recurrent_pseudo_bounds = true,
    .recurrent_bounds = true};

TRL::TRL(
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
    vars.insert(trace_var);
    vars.insert(trp.get_n());
    if (Config::Analysis::termination()) {
        vars.insert(safety_var);
    }
    for (const auto &x : t.vars()) {
        if (theory::isPostVar(x)) {
            const auto pre{theory::progVar(x)};
            vars.insert(pre);
        } else {
            vars.insert(x);
        }
    }
    solver->enableModels();
    std::vector<Bools::Expr> steps;
    if (Config::Analysis::termination()) {
        const auto linearize{
            [&](const auto &lit) { return std::visit(
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
                                       lit); }};
        for (const auto &trans : t.trans()) {
            const auto lin{trans->map(linearize)};
            if (rule_map.left.insert(rule_map_t::left_value_type(next_id, lin)).second) {
                steps.push_back(encode_transition(lin, next_id));
                ++next_id;
            }
        }
        solver->add(t.init()->map(linearize));
    } else {
        for (const auto &trans : t.trans()) {
            if (rule_map.left.insert(rule_map_t::left_value_type(next_id, trans)).second) {
                steps.push_back(encode_transition(trans, next_id));
                ++next_id;
            }
        }
        solver->add(t.init());
    }
    last_orig_clause = next_id - 1;
    step = bools::mkOr(steps);
}

std::optional<Range> TRL::has_looping_infix() {
    for (unsigned i = 0; i < trace.size(); ++i) {
        for (unsigned start = 0; start + i < trace.size(); ++start) {
            if (Config::Analysis::termination() &&
                i > 0 &&
                model.get<Arith>(get_subs(start, 1).get<Arith>(safety_var)) >= 0 &&
                model.get<Arith>(get_subs(start + i, 1).get<Arith>(safety_var)) < 0) {
                continue;
            }
            if (dependency_graph.hasEdge(trace[start + i].implicant, trace[start].implicant) && (i > 0 || trace[start].id <= last_orig_clause)) {
                return {Range::from_interval(start, start + i)};
            }
        }
    }
    return {};
}

std::pair<Bools::Expr, Model> TRL::compress(const Range &range) {
    std::optional<Bools::Expr> loop;
    Renaming var_renaming;
    for (long i = static_cast<long>(range.end()); i >= 0 && i >= static_cast<long>(range.start()); --i) {
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
    const auto m{model.composeBackwards(var_renaming)};
    return {*loop, m};
}

Int TRL::add_learned_clause(const Range &range, const Bools::Expr &accel) {
    if (Config::Analysis::log) {
        std::cout << "learned transition: " << accel << " with id " << next_id << std::endl;
    }
    const auto id = next_id;
    ++next_id;
    rule_map.left.insert(rule_map_t::left_value_type(id, accel));
    std::vector<std::pair<Int, Bools::Expr>> loop;
    for (size_t i = range.start(); i <= range.end(); ++i) {
        const auto &e {trace.at(i)};
        loop.emplace_back(e.id, e.implicant);
    }
    learned_to_loop.emplace(id, loop);
    step = step || encode_transition(accel, id);
    return id;
}

Bools::Expr TRL::specialize(const Bools::Expr e, const Model &model, const std::function<bool(const Var &)> &eliminate) {
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

std::pair<Bools::Expr, Model> TRL::specialize(const Range &range, const std::function<bool(const Var &)> &eliminate) {
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

std::optional<Arith::Expr> TRL::prove_term(const Bools::Expr loop, const Model &model) {
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
        bounded.emplace_back(coeff->toExpr() * pre_val);
        decreasing.emplace_back(coeff->toExpr() * pre_val - coeff->toExpr() * post_val);
    }
    solver->add(arith::mkGt(arith::mkPlus(std::move(bounded)), arith::mkConst(0)));
    solver->add(arith::mkGt(arith::mkPlus(std::move(decreasing)), arith::mkConst(0)));
    if (solver->check() == SmtResult::Sat) {
        const auto rf_model {solver->model().get<Arith>()};
        std::vector<Arith::Expr> addends;
        for (const auto &[x,coeff]: coeffs) {
            if (const auto val {rf_model.get(coeff)}) {
                addends.emplace_back(arith::mkConst(*val) * x->toExpr());
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

bool TRL::handle_loop(const Range &range) {
    auto [loop, model]{specialize(range, theory::isTempVar)};
    Bools::Expr termination_argument {top()};
    if (Config::Analysis::termination()) {
        if (const auto rf {prove_term(loop, model)}) {
            termination_argument = bools::mkAndFromLits({arith::mkGt(*rf, arith::mkConst(0)), arith::mkGt(*rf, (*rf)->renameVars(t.pre_to_post().get<Arith>()))});
            loop = loop && termination_argument;
        } else {
            return false;
        }
    }
    if (add_blocking_clauses(range, model)) {
        return true;
    }
    auto ti{trp.compute(loop, model)};
    if (Config::Analysis::termination()) {
        ti = ti && termination_argument;
    }

    Int id;
    Bools::Expr projected{top()};
    const auto n {trp.get_n()};
    if (mbp_kind == Config::TRPConfig::RealQe) {
        projected = qe::real_qe(ti, model, [&](const auto &x) {
            return x == Var(n);
        });
        projected = Preprocess::preprocessFormula(projected, theory::isTempVar);
        id = add_learned_clause(range, projected);
    } else {
        ti = Preprocess::preprocessFormula(ti, theory::isTempVar);
        id = add_learned_clause(range, ti);
        model.put<Arith>(n, 1);
        projected = mbp::int_mbp(ti, model, [&](const auto &x) {
            return x == Var(n);
        });
    }
    if (range.length() == 1) {
        projections.emplace_back(id, projected);
    } else {
        add_blocking_clause(range, id, projected);
    }
    return true;
}

Bools::Expr TRL::encode_transition(const Bools::Expr &t, const Int &id) {
    return t && theory::mkEq(trace_var, arith::mkConst(id));
}

void TRL::add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) {
    const auto s{get_subs(range.start(), range.length())};
    auto &map{blocked_per_step.emplace(range.end(), std::map<Int, Bools::Expr>()).first->second};
    auto it{map.emplace(id, top()).first};
    if (Config::Analysis::termination()) {
        std::vector<Bools::Expr> disjuncts;
        disjuncts.emplace_back(s(!loop));
        if (range.length() == 1) {
            disjuncts.emplace_back(bools::mkLit(arith::mkGeq(s.get<Arith>(trace_var), arith::mkConst(id))));
        }
        const auto safety_loop {this->model.get<Arith>(get_subs(range.start(), 1).get<Arith>(safety_var)) >= 0};
        if (safety_loop) {
            const auto last_s {get_subs(range.end(), 1)};
            const auto no_safety_loop{bools::mkLit(arith::mkLt(last_s.get<Arith>(safety_var), arith::mkConst(0)))};
            disjuncts.emplace_back(no_safety_loop);
        } else {
            const auto first_s {get_subs(range.start(), 1)};
            const auto no_term_loop{bools::mkLit(arith::mkGeq(first_s.get<Arith>(safety_var), arith::mkConst(0)))};
            disjuncts.emplace_back(no_term_loop);
        }
        it->second = it->second && bools::mkOr(disjuncts);
    } else if (range.length() == 1) {
        it->second = it->second && s(!loop || bools::mkLit(arith::mkGeq(trace_var, arith::mkConst(id))));
    } else {
        it->second = it->second && s(!loop);
    }
}

bool TRL::add_blocking_clauses(const Range &range, Model model) {
    Subs m{model.toSubs()};
    m.erase(trp.get_n());
    auto solver{SmtFactory::modelBuildingSolver(QF_LA)};
    const auto n {trp.get_n()};
    for (const auto &[id, b] : rule_map) {
        const auto is_orig_clause {id <= last_orig_clause};
        if (Config::Analysis::termination() && is_orig_clause) {
            continue;
        }
        if (range.length() == 1 && is_orig_clause) {
            continue;
        }
        const auto vars {b->vars()};
        if (is_orig_clause && std::any_of(vars.begin(), vars.end(), theory::isTempVar)) {
            continue;
        }
        if (vars.contains(n)) {
            solver->push();
            solver->add(m(b));
            if (solver->check() == SmtResult::Sat) {
                const auto n_val{solver->model({{n}}).get<Arith>(n)};
                model.put<Arith>(n, n_val);
                const auto projected{mbp::int_mbp(b, model, [&](const auto &x) {
                    return x == Var(n);
                })};
                add_blocking_clause(range, id, projected);
                return true;
            }
            solver->pop();
        } else if (model.eval<Bools>(b)) {
            add_blocking_clause(range, id, b);
            return true;
        }
    }
    return false;
}

void TRL::add_blocking_clauses() {
    const auto s1{get_subs(depth, 1)};
    const auto s2{get_subs(depth + 1, 1)};
    for (const auto &[id, b] : projections) {
        solver->add(s1(!b) || bools::mkLit(arith::mkGeq(s1.get<Arith>(trace_var), arith::mkConst(id))));
    }
    const auto it{blocked_per_step.find(depth)};
    if (it != blocked_per_step.end()) {
        for (const auto &[_, b] : it->second) {
            solver->add(b);
        }
    }
}


void TRL::build_trace() {
    trace.clear();
    model = solver->model();
    std::optional<std::pair<Bools::Expr, Int>> prev;
    for (unsigned d = 0; d < depth; ++d) {
        const auto s{get_subs(d, 1)};
        const auto id{model.eval<Arith>(s.get<Arith>(trace_var))};
        const auto rule{encode_transition(rule_map.left.at(id), id)};
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
        if (Config::Analysis::termination()) {
            std::cout << "safety var: " << safety_var << std::endl;
        }
        std::cout << "run:" << std::endl;
        for (const auto &t : trace) {
            std::cout << t.model << std::endl;
        }
    }
}

const Renaming &TRL::get_subs(const unsigned start, const unsigned steps) {
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

void TRL::pop() {
    solver->pop();
    --depth;
}

bool TRL::build_cex() const {
    if (trace.empty()) {
        return SmtFactory::check(t.init() && t.err()) == SmtResult::Sat;
    }
    linked_hash_map<Int, Bools::Expr> accel;
    std::stack<Int> todo;
    for (const auto &e: trace) {
        if (e.id > last_orig_clause) {
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
        for (const auto &[id,t]: loop) {
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
            .tryNonterm=false,
            .tryAccel=true,
            .n=ArithVar::next()
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

std::optional<SmtResult> TRL::do_step() {
    auto s{get_subs(depth, 1)};
    // push error states
    solver->push();
    solver->add(s(t.err()));
    switch (solver->check()) {
        case SmtResult::Sat:
            if (Config::Analysis::log) {
                std::cout << "proving safety failed, trying to construct counterexample" << std::endl;
            }
            build_trace();
            return build_cex() ? SmtResult::Unsat : SmtResult::Unknown;
        case SmtResult::Unknown:
            std::cerr << "unknown from SMT solver" << std::endl;
            return SmtResult::Unknown;
        case SmtResult::Unsat: {
            // pop error states
            solver->pop();
            solver->push();
            solver->add(s(step));
            if (Config::Analysis::termination() && depth > 0) {
                solver->add(bools::mkLit(arith::mkGeq(get_subs(depth - 1, 1).get<Arith>(safety_var), s.get<Arith>(safety_var))));
            }
            add_blocking_clauses();
            switch (solver->check()) {
                case SmtResult::Unsat:
                    return SmtResult::Sat;
                case SmtResult::Unknown:
                    std::cerr << "unknown from SMT solver" << std::endl;
                    return SmtResult::Unknown;
                case SmtResult::Sat: {
                    ++depth;
                    build_trace();
                    if (Config::Analysis::log) {
                        std::cout << "starting loop handling" << std::endl;
                    }
                    const auto range{has_looping_infix()};
                    if (range) {
                        if (Config::Analysis::log) {
                            std::cout << "found loop: " << range->start() << " to " << range->end() << std::endl;
                        }
                        if (!handle_loop(*range)) {
                            return SmtResult::Unknown;
                        }
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

ITSModel TRL::get_model() {
    std::vector<Bools::Expr> res{t.init()};
    Bools::Expr last{t.init()};
    for (unsigned i = 0; i < depth; ++i) {
        const auto s1{get_subs(i, 1)};
        last = last && s1(step);
        Renaming s2;
        for (const auto &x : vars) {
            if (theory::isProgVar(x)) {
                s2.insert(s1.get(theory::postVar(x)), x);
                s2.insert(x, theory::next(x));
            }
        }
        res.push_back(s2(last));
    }
    const auto sp_model{bools::mkOr(res)};
    return its2safety.transform_model(sp_model);
}

ITSSafetyCex TRL::get_cex() {
    SafetyCex res{t};
    const auto model {solver->model()};
    const auto &trans {t.trans()};
    for (size_t i = 0; i < depth; ++i) {
        auto m{model.composeBackwards(get_subs(i, 1))};
        const auto it{std::find_if(trans.begin(), trans.end(), [&](const auto &c) {
            return res.try_step(m, c);
        })};
        if (it == trans.end()) {
            throw std::logic_error("get_cex failed");
        }
    }
    res.set_final_state(model.composeBackwards(get_subs(depth, 1)));
    return its2safety.transform_cex(res);
}
