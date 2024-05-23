#include "sabmc.hpp"
#include "chain.hpp"
#include "theory.hpp"
#include "preprocessing.hpp"
#include "rulepreprocessing.hpp"
#include "config.hpp"
#include "dependencygraph.hpp"
#include "linkedhashmap.hpp"
#include "theory.hpp"
#include "pair.hpp"
#include "optional.hpp"
#include "crabcfg.hpp"
#include "realmbp.hpp"
#include "intmbp.hpp"
#include "cvc5.hpp"

Range::Range(const unsigned s, const unsigned e): s(s), e(e) {}

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

mbp_kind SABMC::m_mbp {INT_MBP};

SABMC::SABMC(SafetyProblem &t):
    t(t) {
    vars.insert(trace_var);
    vars.insert(n);
    for (const auto &x: t.vars()) {
        if (theory::isPostVar(x)) {
            vars.insert(theory::progVar(x));
        } else {
            vars.insert(x);
        }
    }
    solver->enableModels();
}

std::optional<Range> SABMC::has_looping_infix() {
    long start {((long)trace.size()) - 1};
    long end {((long)trace.size()) - 1};
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

std::pair<Bools::Expr, Model> SABMC::compress(const Range &range) {
    std::optional<Bools::Expr> loop;
    Subs var_renaming;
    for (int i = range.end(); i >= 0 && i >= range.start(); --i) {
        const auto rule {trace[i].implicant};
        const auto s {get_subs(i, 1)};
        if (loop) {
            // sigma1 maps vars from chained to the corresponding vars from rule
            // sigma2 maps vars from chained to the corresponding vars from loop
            // temporary variables in rule remain unchanged
            // temporary variables in loop that clash with rule are renamed
            const auto [chained, sigma1, sigma2] {Chaining::chain(rule, *loop)};
            // all pre-vars and temp vars that already occured in rule correspond to vars from rule
            auto fst_vars {t.pre_vars()};
            rule->collectVars(fst_vars);
            for (const auto &x: t.post_vars()) {
                fst_vars.erase(x);
            }
            // map them to the corresponding SMT vars by taking sigma1 and s (the var renaming that
            // was used for the step with rule) into account
            const auto fst_var_renaming {sigma1.compose(s).project(fst_vars)};
            // all post-vars and all other variables that occur in chained, but not in rule, correspond
            // to variables from loop
            auto snd_vars {t.post_vars()};
            chained->collectVars(snd_vars);
            for (const auto &x: fst_vars) {
                snd_vars.erase(x);
            }
            // map them to SMT vars by taking sigma2 and the variable renaming that has been constructed
            // so far into account
            auto snd_var_renaming {sigma2.compose(var_renaming).project(snd_vars)};
            // both var renamings are disjoint by construction
            var_renaming = fst_var_renaming.unite(snd_var_renaming);
            loop = chained;
        } else {
            loop = rule;
            var_renaming = s;
        }
    }
    auto vars {(*loop)->vars()};
    var_renaming.collectCoDomainVars(vars);
    const auto model {solver->model(vars).composeBackwards(var_renaming)};
    return {*loop, model};
}

Int SABMC::add_learned_clause(const Bools::Expr &accel) {
    if (Config::Analysis::log) std::cout << "learned transition: " << accel << std::endl;
    const auto id = next_id;
    ++next_id;
    rule_map.left.insert(rule_map_t::left_value_type(id, accel));
    blocked.emplace(id, accel);
    step = step || encode_transition(accel);
    return id;
}

Bools::Expr mbp_impl(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var&)> &eliminate) {
    switch (SABMC::m_mbp) {
        case REAL_MBP: return mbp::real_mbp(trans, model, eliminate);
        case INT_MBP: return mbp::int_mbp(trans, model, eliminate);
        default: throw std::invalid_argument("unknown mbp kind");
    }
}

Bools::Expr SABMC::specialize(const Bools::Expr e, const Model &model, const std::function<bool(const Var&)> &eliminate) {
    const auto sip {model.syntacticImplicant(e)};
    if (Config::Analysis::log) {
        std::cout << "sip: " << sip << std::endl;
    }
    auto simp {Preprocess::preprocessTransition(sip)};
    if (Config::Analysis::log && simp) {
        std::cout << "simp: " << *simp << std::endl;
    }
    const auto mbp_res {mbp_impl(*simp, model, eliminate)};
    if (Config::Analysis::log) {
        std::cout << "mbp: " << mbp_res << std::endl;
    }
    return mbp_res;
}

std::pair<Bools::Expr, Model> SABMC::specialize(const Range &range, const std::function<bool(const Var&)> &eliminate) {
    if (range.empty()) {
        return {top(), Model()};
    }
    const auto [transition, model] {compress(range)};
    if (Config::Analysis::log) {
        std::cout << "compressed:" << std::endl;
        std::cout << transition << std::endl;
        std::cout << "model: " << model << std::endl;
    }
    return {specialize(transition, model, eliminate), model};;
}

Bools::Expr SABMC::recurrence_analysis(const Bools::Expr loop) {
    // the loop counter is bounded by 0
    const auto n_term {Arith::varToExpr(n)};
    BoolExprSet res {bools::mkLit(arith::mkGt(n_term, arith::mkConst(0)))};
    const auto lits {loop->lits().get<Arith::Lit>()};
    // find "toggling" vars:
    // x' = -x + c
    linked_hash_map<Arith::Var, Arith::Expr> toggling;
    bool changed;
    do {
        changed = false;
        for (const auto &rel : lits) {
            if (!rel->isLinear() || !rel->isEq()) {
                continue;
            }
            const auto vars {rel->vars()};
            if (vars.size() != 2) {
                continue;
            }
            const auto x {*vars.begin()};
            const auto y {*(++vars.begin())};
            const auto [pre, post] = x->isProgVar() ? std::pair{x, y} : std::pair{y, x};
            if (!pre->isProgVar() || post != ArithVar::postVar(pre)) {
                continue;
            }
            if (toggling.contains(pre)) {
                continue;
            }
            const auto t{rel->lhs()};
            const auto pre_coeff_term{*t->coeff(pre)};
            const auto post_coeff_term{*t->coeff(post)};
            const auto pre_coeff{*pre_coeff_term->isInt()};
            const auto post_coeff{*post_coeff_term->isInt()};
            if (mp::abs(pre_coeff) != 1 || mp::abs(post_coeff) != 1) {
                continue;
            }
            const auto addend {t - pre_coeff_term * pre - post_coeff_term * post};
            if ((pre_coeff > 0) == (post_coeff > 0)) {
                changed = true;
                toggling.emplace(pre, addend);
                res.insert(bools::mkLit(arith::mkEq(
                    arith::mkMod(
                        n_term + arith::mkConst(1),
                        arith::mkConst(2)),
                    arith::mkConst(0))));
                res.insert(bools::mkLit(arith::mkEq(post, -pre + addend)));
            }
        }
    } while (changed);
    // find vars that only depend on toggling vars:
    // x' = -x + c
    // y' = y + x + d
    // z' = z + x' + k
    for (const auto &rel : lits) {
        if (!rel->isLinear() || !rel->isEq()) {
            continue;
        }
        const auto vars{rel->vars()};
        std::optional<Arith::Var> pre;
        std::optional<Arith::Var> post;
        auto all_toggling {true};
        auto some_toggling {false};
        Arith::Subs odd;
        const auto t{rel->lhs()};
        for (const auto &x : vars) {
            const auto p = x->isProgVar() ? x : x->progVar(x);
            if (toggling.contains(p)) {
                some_toggling = true;
                const auto c {toggling.at(p)};
                if (x->isProgVar()) {
                    // y' = y + x + ...
                    // y(1)=y+x, y(2)=(y-x+c)+x=y+c, y(3)=y+x+c y(4)=(y-x+c)+x+c=y+2c, ...
                    // we can ignore sign and coefficient here, they are taken into account by applying the substitutions
                    // e.g., with y' = y - 2x, we get the following for the case that n is odd:
                    // y' = y - 2 * (x + (n-1) * c) = y - 2 * x - 2 * (n-1) * c
                    // y(1) = y-2x = (y - 2 * x - 2 * (n-1) * c/2)[n/1]
                    // y(2) = y-2(-x+c)-2x = y-2c
                    // y(3) = y-2x-2c = (y - 2 * x - 2 * (n-1) * c/2)[n/3]
                    // ...
                    odd.put(x, x + (n_term - arith::mkConst(1)) * c->divide(2));
                } else {
                    // y' = y + x' + ...
                    // y(0)=y, y(1)=y-x+c, y(2)=(y+x)-x+c=y+c, y(3)=(y-x+c)+c=y-x+2c y(4)=(y+x)-x+2c=y+2c, ...
                    odd.put(x, -x + (n_term + arith::mkConst(1)) * c->divide(2));
                }
                continue;
            } else if (x->isProgVar()) {
                if (pre) {
                    all_toggling = false;
                    break;
                }
                pre = x;
            } else {
                if (post) {
                    all_toggling = false;
                    break;
                }
                post = x;
            }
        }
        if (!some_toggling || !all_toggling || !pre || !post || *post != (*pre)->postVar(*pre)) {
            continue;
        }
        const auto pre_coeff_term{*t->coeff(*pre)};
        const auto post_coeff_term{*t->coeff(*post)};
        const auto pre_coeff{*pre_coeff_term->isInt()};
        const auto post_coeff{*post_coeff_term->isInt()};
        if (mp::abs(pre_coeff) != 1 || mp::abs(post_coeff) != 1) {
            continue;
        }
        if ((pre_coeff > 0) == (post_coeff > 0)) {
            continue;
        }
        const auto constant_addend {arith::mkConst(t->getConstantAddend())};
        const auto var_addend {t - pre_coeff_term * *pre - post_coeff_term * *post - constant_addend};
        res.insert(bools::mkLit(arith::mkEq(
            arith::mkMod(
                n_term + arith::mkConst(1),
                arith::mkConst(2)),
            arith::mkConst(0))));
        res.insert(bools::mkLit(arith::mkEq(*post, *pre + odd(var_addend) + n_term * constant_addend)));
    }
    // find recurrent equations and inequations
    linked_hash_map<Arith::Var, Int> eqs;
    linked_hash_map<Arith::Var, Int> lbs;
    linked_hash_map<Arith::Var, Int> ubs;
    for (const auto &rel: lits) {
        if (!rel->isLinear() || rel->isNeq()) {
            continue;
        }
        const auto vars {rel->vars()};
        if (vars.size() != 2) {
            continue;
        }
        const auto x {*vars.begin()};
        const auto y {*(++vars.begin())};
        const auto [pre, post] = x->isProgVar() ? std::pair{x, y} : std::pair{y, x};
        if (!pre->isProgVar() || post != ArithVar::postVar(pre)) {
            continue;
        }
        if (eqs.contains(pre)) {
            continue;
        }
        const auto t {rel->lhs()};
        const auto pre_coeff_term {*t->coeff(pre)};
        const auto post_coeff_term {*t->coeff(post)};
        const auto pre_coeff {*pre_coeff_term->isInt()};
        const auto post_coeff {*post_coeff_term->isInt()};
        if (mp::abs(pre_coeff) != 1 || mp::abs(post_coeff) != 1) {
            continue;
        }
        const auto constant_term {t - pre_coeff_term * pre - post_coeff_term * post};
        if ((pre_coeff > 0) == (post_coeff > 0)) {
            continue;
        }
        auto constant {*constant_term->isInt()};
        if (rel->isEq()) {
            eqs.emplace(pre, post_coeff > 0 ? -constant : constant);
            lbs.erase(pre);
            ubs.erase(pre);
        } else {
            if (post_coeff > 0) {
                constant = -constant + 1;
                auto it{lbs.emplace(pre, constant).first};
                if (it->second < constant) {
                    lbs.put(pre, constant);
                }
            } else {
                constant = constant - 1;
                auto it{ubs.emplace(pre, constant).first};
                if (it->second > constant) {
                    ubs.put(pre, constant);
                }
            }
            const auto lb {lbs.get(pre)};
            const auto ub {ubs.get(pre)};
            if (lb == ub) {
                eqs.emplace(pre, *lb);
                lbs.erase(pre);
                ubs.erase(pre);
            }
        }
    }
    if (!eqs.empty() || !lbs.empty() || ubs.empty()) {
        // each recurrent (in)equation gives rise to a new literal
        Arith::Subs subs_first;
        Arith::Subs subs_last;
        for (const auto &[pre, c] : eqs) {
            const auto c_term{arith::mkConst(c)};
            const auto post{ArithVar::postVar(pre)};
            subs_first.put(post, pre + c_term);
            const auto rhs{pre + c_term * n_term};
            subs_last.put(pre, rhs - c_term);
            subs_last.put(post, rhs);
            res.insert(bools::mkLit(arith::mkEq(ArithVar::postVar(pre), rhs)));
        }
        for (const auto &[pre, c] : lbs) {
            res.insert(bools::mkLit(arith::mkGeq(ArithVar::postVar(pre), pre + arith::mkConst(c) * n_term)));
        }
        for (const auto &[pre, c] : ubs) {
            res.insert(bools::mkLit(arith::mkLeq(ArithVar::postVar(pre), pre + arith::mkConst(c) * n_term)));
        }
        for (const auto &rel : lits) {
            const auto vars{rel->vars()};
            // keep literals that only refer to post-vars
            if (std::all_of(vars.begin(), vars.end(), theory::isPostVar)) {
                res.insert(bools::mkLit(rel));
            }
            if (!rel->isLinear()) {
                continue;
            }
            if (std::any_of(vars.begin(), vars.end(), theory::isTempVar)) {
                continue;
            }
            {
                // construct literal for the but-last iteration
                auto s{subs_last};
                auto fail{false};
                for (const auto &x : vars) {
                    const auto pre = x->isProgVar() ? x : ArithVar::progVar(x);
                    if (!eqs.contains(pre)) {
                        const auto bounds = *(*rel->lhs()->coeff(x))->isInt() > 0 ? ubs : lbs;
                        const auto c{bounds.get(pre)};
                        if (c) {
                            const auto c_term{arith::mkConst(*c)};
                            const auto rhs{pre + c_term * n_term};
                            s.put(x, x->isProgVar() ? rhs - c_term : rhs);
                        } else {
                            fail = true;
                            break;
                        }
                    }
                }
                if (!fail) {
                    res.insert(bools::mkLit(rel->subs(s)));
                }
            }
            {
                // construct literal for the first iteration
                auto s{subs_first};
                auto fail{false};
                for (const auto &post : vars) {
                    if (!post->isPostVar()) {
                        continue;
                    }
                    const auto pre{ArithVar::progVar(post)};
                    if (!eqs.contains(pre)) {
                        const auto bounds = *(*rel->lhs()->coeff(post))->isInt() > 0 ? ubs : lbs;
                        const auto c{bounds.get(pre)};
                        if (c) {
                            s.put(post, pre + arith::mkConst(*c));
                        } else {
                            fail = true;
                            break;
                        }
                    }
                }
                if (!fail) {
                    res.insert(bools::mkLit(rel->subs(s)));
                }
            }
        }
    }
    return bools::mkAnd(res);
}

void SABMC::handle_loop(const Range &range) {
    auto [loop, model] {specialize(range, theory::isTempVar)};
    Subs post_to_pre;
    for (const auto &x: vars) {
        if (theory::isProgVar(x)) {
            post_to_pre.put(theory::postVar(x), theory::toExpr(x));
        }
    }
    // const auto inv {CrabCfg::compute_invariants(post_to_pre(stem), loop)};
    const auto inv {CrabCfg::compute_invariants(top(), loop)};
    if (Config::Analysis::log) {
        std::cout << "invariants: " << inv << std::endl;
    }
    const auto rec {recurrence_analysis(loop)};
    if (Config::Analysis::log) {
        std::cout << "recurrence analysis: " << rec << std::endl;
    }
    model.put<Arith>(n, 1);
    const auto is_n {[&](const Var &x){
        return x == Var(n);
    }};
    const auto rec_projected {mbp_impl(rec, model, is_n)};
    if (Config::Analysis::log) {
        std::cout << "projection of recurrence analysis: " << rec_projected << std::endl;
    }
    const auto id {add_learned_clause(inv && rec_projected)};
    std::vector<Int> expanded;
    for (unsigned i = range.start(); i <= range.end(); ++i) {
        expanded.push_back(trace.at(i).id);
    }
    loops.emplace(id, Loop{.expanded=expanded, .compressed=loop});
}

Bools::Expr SABMC::encode_transition(const Bools::Expr &t) {
    return t && theory::mkEq(trace_var, arith::mkConst(rule_map.right.at(t)));
}

void SABMC::add_blocking_clauses() {
    // std::cout << "BLOCKING CLAUSES" << std::endl;
    for (unsigned from = 0; from <= depth; ++from) {
        for (const auto &[id,b] : blocked) {
            for (unsigned to = from + 1; to <= depth + 1; ++to) {
                const auto s {get_subs(from, to - from)};
                auto block {s(!b)};
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

void SABMC::unknown() {
    const auto str {"unknown"};
    std::cout << str << std::endl;
    proof.result(str);
    proof.print();
}

void SABMC::sat() {
    const auto str {"sat"};
    std::cout << str << std::endl;
    proof.append(std::to_string(depth) + "-fold unrolling of the transition relation is unsatisfiable");
    proof.result(str);
    proof.print();
}

void SABMC::build_trace() {
    trace.clear();
    const auto model {solver->model()};
    // std::cout << "model: " << model << std::endl;
    std::optional<std::pair<Bools::Expr, Int>> prev;
    for (unsigned d = 0; d < depth; ++d) {
        const auto s {get_subs(d, 1)};
        const auto id {model.eval<Arith>(s.get<Arith>(trace_var))};
        const auto rule {rule_map.left.at(id)};
        const auto comp {model.composeBackwards(s)};
        const auto imp {comp.syntacticImplicant(rule) && theory::mkEq(trace_var, arith::mkConst(id))};
        const auto projected_model {comp.project(vars)};
        if (prev && (prev->second <= last_orig_clause || prev->second != id)) {
            dependency_graph.addEdge(prev->first, imp);
        }
        prev = {imp, id};
        trace.emplace_back(TraceElem{.id=id, .implicant=imp, .model=projected_model});
    }
    if (Config::Analysis::log) {
        std::cout << "trace:" << std::endl;
        for (const auto &t: trace) {
            std::cout << t.implicant << std::endl;
        }
        std::cout << "trace var: " << trace_var << std::endl;
        std::cout << "run:" << std::endl;
        for (const auto &t: trace) {
            std::cout << t.model << std::endl;
        }
    }
}

const Subs& SABMC::get_subs(const unsigned start, const unsigned steps) {
    if (subs.empty()) {
        subs.push_back({Subs()});
    }
    while (subs.size() < start + steps) {
        Subs s;
        for (const auto &var: vars) {
            if (theory::isProgVar(var)) {
                const auto post_var {theory::postVar(var)};
                s.put(var, subs.back()[0].get(post_var));
                s.put(post_var, theory::toExpr(theory::next(post_var)));
            } else {
                s.put(var, theory::toExpr(theory::next(var)));
            }
        }
        subs.push_back({s});
    }
    auto &pre_vec {subs.at(start)};
    while (pre_vec.size() < steps) {
        auto &post {subs.at(start + pre_vec.size()).front()};
        Subs s;
        for (const auto &var: vars) {
            s.put(var, pre_vec.front().get(var));
            if (theory::isProgVar(var)) {
                const auto post_var {theory::postVar(var)};
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

SABMC::RefinementResult SABMC::refine() {
    Subs pre_to_post;
    for (const auto &x: vars) {
        pre_to_post.put(x, theory::toExpr(theory::postVar(x)));
    }
    auto unsat {true};
    build_trace();
    std::vector<RefinementJob> todo;
    for (unsigned i = 0; i < trace.size(); ++i) {
        const auto step {trace.at(i)};
        if (step.id > last_orig_clause) {
            const auto pre {specialize(Range::from_interval(0, i-1), [&](const auto &x) {
                return !theory::isProgVar(x);
            }).first};
            const auto loop {loops.at(step.id)};
            const auto post {specialize(Range::from_interval(i+1, trace.size() - 1), [&](const auto &x) {
                return !theory::isPostVar(x);
            }).first};
            todo.push_back(RefinementJob{.id=step.id, .pre=pre && t.init(), .loop=loop, .post=post && pre_to_post(t.err()), .unrolling=loop.compressed});
        }
    }
    for (auto it = todo.begin(); it != todo.end();) {
        auto &job {*it};
        std::cout << "pre: " << job.pre << std::endl;
        std::cout << "post: " << job.post << std::endl;
        std::cout << "unrolling: " << job.unrolling << std::endl;
        auto smt_res {SmtFactory::check(job.pre && job.post && job.unrolling)};
        switch (smt_res) {
            case Sat: {
                it = todo.erase(it);
                break;
            }
            case Unknown: {
                it = todo.erase(it);
                unsat = false;
                break;
            }
            case Unsat: {
                auto interpolant {CVC5::getInterpolant(job.pre && job.post, !job.unrolling)};
                const auto inductive_step {std::get<0>(Chaining::chain(interpolant, job.loop.compressed))};
                smt_res = SmtFactory::check(job.pre && inductive_step && !interpolant);
                if (smt_res != SmtResult::Unsat) {
                    smt_res = SmtFactory::check(job.post && inductive_step && !interpolant);
                }
                switch (smt_res) {
                    case Unknown:
                    [[fallthrough]];
                    case Sat: {
                        job.unrolling = std::get<0>(Chaining::chain(job.unrolling, job.loop.compressed));
                        break;
                    }
                    case Unsat: {
                        replace(job.id, interpolant);
                        solver->pop();
                        solver->push();
                        depth = 0;
                        return Refined;
                    }
                }
            }
        }
    }
    if (unsat) {
        return Unsat;
    } else {
        return Failed;
    }
}

void SABMC::replace(const Int id, const Bools::Expr replacement) {
    const auto old_trans {rule_map.left.at(id)};
    const auto new_trans {old_trans && !replacement};
    rule_map.left.erase(id);
    rule_map.left.insert(rule_map_t::left_value_type(id, new_trans));
    blocked.put(id, new_trans);
    std::vector<Bools::Expr> steps;
    for (const auto &[_,t]: rule_map) {
        steps.push_back(encode_transition(t));
    }
    step = bools::mkOr(steps);
    add_learned_clause(old_trans && replacement);
}

void SABMC::analyze() {
    if (Config::Analysis::log) {
        std::cout << "initial problem" << std::endl;
        std::cout << t << std::endl;
    }
    // proof.majorProofStep("Initial ITS", ITSProof(), its);
    const auto res {Preprocess::preprocess(t)};
    if (res) {
        proof.concat(res.getProof());
        t = *res;
        if (Config::Analysis::log) {
            std::cout << "Simplified Problem" << std::endl;
            std::cout << t <<std::endl;
        }
    }
    std::vector<Bools::Expr> steps;
    for (const auto &trans: t.trans()) {
        rule_map.left.insert(rule_map_t::left_value_type(next_id, trans));
        ++next_id;
        steps.push_back(encode_transition(trans));
    }
    last_orig_clause = next_id - 1;
    step = bools::mkOr(steps);
    solver->add(t.init());
    solver->push();

    while (true) {
        const auto &s {get_subs(depth, 1)};
        solver->push();
        solver->add(s(t.err()));
        switch (solver->check()) {
        case SmtResult::Sat:
            if (refine() != Refined) {
                unknown();
                return;
            }
            break;
        case SmtResult::Unknown:
            unknown();
            return;
        case SmtResult::Unsat: {
            solver->pop();
            // std::cout << "TRANSITION FORMULA" << std::endl;
            // std::cout << "depth: " << depth << std::endl;
            // std::cout << "s: " << s << std::endl;
            // std::cout << "formula: " << s(step) << std::endl;
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
            case SmtResult::Sat:
                build_trace();
                if (Config::Analysis::log) std::cout << "starting loop handling" << std::endl;
                const auto range {has_looping_infix()};
                if (range) {
                    if (Config::Analysis::log) {
                        std::cout << "found loop: " << range->start() << " to " << range->end() << std::endl;
                    }
                    handle_loop(*range);
                    solver->pop();
                    solver->push();
                    depth = 0;
                }
                if (Config::Analysis::log) std::cout << "done with loop handling" << std::endl;
                break;
            }
        }
        }
        if (Config::Analysis::log) {
            std::cout << "depth: " << depth << std::endl;
        }
    }
}

void SABMC::analyze(SafetyProblem &its) {
    SABMC(its).analyze();
}
