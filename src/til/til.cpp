#include "til.hpp"
#include "chain.hpp"
#include "config.hpp"
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

mbp_kind TIL::m_mbp{INT_MBP};

TIL::TIL(SafetyProblem &t) : t(t) {
    vars.insert(trace_var);
    vars.insert(n);
    for (const auto &x : t.vars()) {
        if (theory::isPostVar(x)) {
            const auto pre {theory::progVar(x)};
            pre_vars.insert(pre);
            vars.insert(pre);
        } else {
            if (theory::isProgVar(x)) {
                pre_vars.insert(x);
            }
            vars.insert(x);
        }
    }
    solver->enableModels();
}

std::optional<Range> TIL::has_looping_infix() {
    long start{((long)trace.size()) - 1};
    long end{((long)trace.size()) - 1};
    while (end >= 0) {
        while (start >= 0) {
            if (dependency_graph.hasEdge(trace[end].implicant, trace[start].implicant)) {
                return {Range::from_interval(start, end)};
            }
            --start;
        }
        --end;
        start = end;
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
    if (Config::Analysis::log)
        std::cout << "learned transition: " << accel << " with id " << next_id << std::endl;
    const auto id = next_id;
    ++next_id;
    rule_map.left.insert(rule_map_t::left_value_type(id, accel));
    blocked.emplace(id, accel);
    step = step || encode_transition(accel);
    return id;
}

Bools::Expr mbp_impl(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var &)> &eliminate) {
    switch (TIL::m_mbp) {
    case REAL_MBP:
        return mbp::real_mbp(trans, model, eliminate);
    case INT_MBP:
        return mbp::int_mbp(trans, model, eliminate);
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
    ;
}

Bools::Expr TIL::recurrence_analysis(const Bools::Expr loop) {
    assert(loop->isConjunction());
    LitSet res;
    // collect bounds of the form b >= 0
    const auto lits {loop->lits().get<Arith::Lit>()};
    ArithExprVec bounded;
    for (const auto &l: lits) {
        auto lhs {l->lhs()};
        if (lhs->isLinear()) {
            if (l->isGt() || l->isEq()) {
                auto is_recurrent {true};
                const auto vars {lhs->vars()};
                unsigned num_vars {0};
                for (const auto &x: vars) {
                    if (x->isProgVar()) {
                        const auto post {ArithVar::postVar(x)};
                        ++num_vars;
                        if (!vars.contains(post) || *lhs->coeff(x) != -*lhs->coeff(post)) {
                            is_recurrent = false;
                            break;
                        }
                    }
                }
                is_recurrent &= vars.size() == 2 * num_vars;
                if (is_recurrent) {
                    if (l->isEq()) {
                        const auto constant {lhs->getConstantAddend()};
                        res.insert(arith::mkEq(lhs - arith::mkConst(constant) + n * arith::mkConst(constant), arith::mkConst(0)));
                    } else {
                        lhs = lhs - arith::mkConst(1);
                        const auto constant {lhs->getConstantAddend()};
                        res.insert(arith::mkGeq(lhs - arith::mkConst(constant) + n * arith::mkConst(constant), arith::mkConst(0)));
                    }
                } else {
                    if (l->isGt()) {
                        bounded.push_back(lhs - arith::mkConst(1));
                    } else if (l->isEq()) {
                        bounded.push_back(lhs);
                        bounded.push_back(-lhs);
                    }
                }
            }
        }
    }
    // set up one non-negative multiplier for each bound
    auto solver {SmtFactory::modelBuildingSolver(QF_LA)};
    std::vector<Arith::Var> factors;
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
    const auto const_var {ArithVar::next()};
    {
        // and one equation for the constant part
        ArithExprVec addends;
        for (unsigned idx = 0; idx < bounded.size(); ++idx) {
            addends.push_back(arith::mkConst(bounded[idx]->getConstantAddend()) * factors[idx]);
        }
        solver->add(arith::mkEq(arith::mkPlus(std::move(addends)), const_var));
    }
    // block trivial solutions
    {
        BoolExprSet disjuncts;
        for (const auto &pre: arith_vars) {
            disjuncts.insert(bools::mkLit(arith::mkNeq(pre, arith::mkConst(0))));
        }
        solver->add(bools::mkOr(disjuncts));
    }
    // enumerate solutions
    while (solver->check() == SmtResult::Sat) {
        auto model{solver->model()};
        // construct the recurrent inequation that corresponds to the current solution
        const auto build_sum = [&]() {
            ArithExprVec addends;
            for (unsigned idx = 0; idx < bounded.size(); ++idx) {
                addends.push_back(bounded[idx] * arith::mkConst(model.get<Arith>(factors[idx])));
            }
            return arith::mkPlus(std::move(addends));
        };
        auto sum = build_sum();
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
                sum = build_sum();
                constant = sum->getConstantAddend();
            }
        } while (sat);
        solver->pop();
        res.insert(arith::mkGeq(sum - arith::mkConst(constant) + n * arith::mkConst(constant), arith::mkConst(0)));
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
    }
    // construct transition invariants
    return bools::mkAndFromLits(res);
}

Bools::Expr TIL::compute_transition_invariant(const Bools::Expr loop, Model model) {
    const auto pre{mbp_impl(loop, model, [](const auto &x) {
        return !theory::isProgVar(x);
    })};
    auto step{recurrence_analysis(loop)};
    model.put<Arith>(n, 1);
    step = mbp_impl(step, model, [&](const auto &x) {
        return x == Var(n);
    });
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
    Subs post_to_pre;
    for (const auto &x : vars) {
        if (theory::isProgVar(x)) {
            post_to_pre.put(theory::postVar(x), theory::toExpr(x));
        }
    }
    // const auto inv {CrabCfg::compute_invariants(post_to_pre(stem), loop)};
    const auto ti{compute_transition_invariant(loop, model)};
    const auto id{add_learned_clause(ti)};
    std::vector<Int> expanded;
    for (unsigned i = range.start(); i <= range.end(); ++i) {
        expanded.push_back(trace.at(i).id);
    }
    loops.emplace(id, Loop{.expanded = expanded, .compressed = loop});
}

Bools::Expr TIL::encode_transition(const Bools::Expr &t) {
    return t && theory::mkEq(trace_var, arith::mkConst(rule_map.right.at(t)));
}

void TIL::add_blocking_clauses() {
    // std::cout << "BLOCKING CLAUSES" << std::endl;
    for (unsigned from = 0; from <= depth; ++from) {
        for (const auto &[id, b] : blocked) {
            for (unsigned to = from + 1; to <= depth + 1; ++to) {
                const auto s{get_subs(from, to - from)};
                auto block{s(!b)};
                if (to == from + 1) {
                    block = block || bools::mkLit(arith::mkGeq(s.get<Arith>(trace_var), arith::mkConst(id)));
                }
                solver->add(block);
                // std::cout << "trans: " << b.trans << std::endl;
                // std::cout << "s: " << s << std::endl;
                // std::cout << "first blocking clause: " << (block || bools::mkLit(arith::mkGeq(s.get<Arith>(trace_var), id))) << std::endl;
            }
        }
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
    // std::cout << "model: " << model << std::endl;
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
        if (prev && (prev->second <= last_orig_clause || prev->second != id)) {
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

TIL::RefinementResult TIL::refine() {
    Subs pre_to_post;
    for (const auto &x : vars) {
        pre_to_post.put(x, theory::toExpr(theory::postVar(x)));
    }
    const auto model{solver->model()};
    const auto err_model{model.composeBackwards(get_subs(depth, 1))};
    std::cout << "err model: " << err_model << std::endl;
    auto err{t.err()};
    std::cout << "err1: " << err << std::endl;
    err = err_model.syntacticImplicant(err);
    std::cout << "err2: " << err << std::endl;
    err = mbp_impl(err, err_model, theory::isTempVar);
    std::cout << "err3: " << err << std::endl;
    err = pre_to_post(err);
    std::cout << "err4: " << err << std::endl;
    build_trace();
    for (unsigned i = 0; i < trace.size(); ++i) {
        const auto step{trace.at(i)};
        if (step.id > last_orig_clause) {
            const auto partial_model{step.model.toSubs().project(theory::isProgVar)};
            const auto loop{rule_map.left.at(step.id)};
            const auto post_loop{partial_model(loop)};
            Bools::Expr post{top()};
            if (i == trace.size() - 1) {
                post = err;
            } else {
                auto [p, post_model]{specialize(Range::from_interval(i + 1, trace.size() - 1), theory::isTempVar)};
                post = p;
                std::cout << "post1: " << post << std::endl;
                post = post && err;
                std::cout << "post2: " << post << std::endl;
                post = mbp_impl(post, post_model, [](const auto &x) {
                    return !theory::isProgVar(x);
                });
                std::cout << "post3: " << post << std::endl;
                post = pre_to_post(post);
                std::cout << "post4: " << post << std::endl;
            }
            if (!step.model.eval<Bools>(post)) {
                std::cout << "model: " << step.model << std::endl;
                std::cout << "post: " << post << std::endl;
            }
            assert(step.model.eval<Bools>(post));
            const auto lits{post->lits()};
            for (const auto &lit : lits) {
                const auto negated{bools::mkLit(theory::negate(lit))};
                std::cout << "trying to refine " << lit << std::endl;
                auto tmp_solver{SmtFactory::solver()};
                tmp_solver->add(post_loop);
                tmp_solver->add(negated);
                for (const auto &[id, b] : blocked) {
                    if (id != step.id) {
                        tmp_solver->add(!partial_model(b));
                    }
                }
                const auto smt_res{tmp_solver->check()};
                if (smt_res == SmtResult::Sat) {
                    const auto refinement{compute_transition_invariant(loop && negated, tmp_solver->model())};
                    if (Config::Analysis::log) {
                        std::cout << "refinement:" << std::endl;
                        std::cout << "old: " << loop << std::endl;
                        std::cout << "new: " << refinement << std::endl;
                    }
                    replace(step.id, refinement);
                    return Refined;
                }
            }
        }
    }
    std::cout << "refinement failed" << std::endl;
    return Failed;
}

void TIL::replace(const Int id, const Bools::Expr replacement) {
    std::cout << "replacing " << id << " with " << replacement << std::endl;
    rule_map.left.erase(id);
    rule_map.left.insert(rule_map_t::left_value_type(id, replacement));
    blocked.put(id, replacement);
    std::vector<Bools::Expr> steps;
    for (const auto &[_, t] : rule_map) {
        steps.push_back(encode_transition(t));
    }
    step = bools::mkOr(steps);
}

void TIL::analyze() {
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
        rule_map.left.insert(rule_map_t::left_value_type(next_id, trans));
        ++next_id;
        steps.push_back(encode_transition(trans));
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
            unknown();
            return;
        }
        solver->pop();
    }
    while (true) {
        s = get_subs(depth, 1);
        solver->add(s(step));
        add_blocking_clauses();
        ++depth;
        switch (solver->check()) {
        case SmtResult::Unsat:
            sat();
            return;
        case SmtResult::Unknown:
            unknown();
            return;
        case SmtResult::Sat: {
            build_trace();
            s = get_subs(depth, 1);
            // push error states
            solver->push();
            solver->add(s(t.err()));
            switch (solver->check()) {
            case SmtResult::Sat:
                // if (refine() != Refined) {
                    unknown();
                    return;
                // }
                // // pop error states
                // solver->pop();
                // // pop steps
                // solver->pop();
                // solver->push();
                // depth = 0;
                // break;
            case SmtResult::Unknown:
                unknown();
                return;
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
                    // pop steps
                    solver->pop();
                    solver->push();
                    depth = 0;
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
    }
}

void TIL::analyze(SafetyProblem &its) {
    TIL(its).analyze();
}