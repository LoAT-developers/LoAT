#include "sabmc.hpp"
#include "chain.hpp"
#include "theory.hpp"
#include "preprocessing.hpp"
#include "rulepreprocessing.hpp"
#include "config.hpp"
#include "dependencygraph.hpp"
#include "recurrence.hpp"
#include "linkedhashmap.hpp"
#include "theory.hpp"
#include "pair.hpp"
#include "optional.hpp"
#include "crabcfg.hpp"

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

SABMC::Loop::Loop(const Bools::Expr trans, const unsigned length): trans(trans), length(length) {}

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
            if (dependency_graph.hasEdge(trace[end], trace[start])) {
                return {Range::from_interval(start, end)};
            }
            --start;
        }
        --end;
        start = end;
    }
    return {};
}

std::pair<Bools::Expr, Model> SABMC::compress(const Bools::Expr pre, const Range &range) {
    std::optional<Bools::Expr> loop;
    Subs var_renaming;
    for (int i = range.end(); i >= 0 && i >= range.start(); --i) {
        const auto rule {trace[i]};
        const auto s {get_subs(i, 1)};
        if (loop) {
            const auto [chained, sigma1, sigma2] {Chaining::chain(rule, *loop)};
            loop = chained;
            auto fst_vars {t.pre_vars()};
            rule->collectVars(fst_vars);
            for (const auto &x: t.post_vars()) {
                fst_vars.erase(x);
            }
            const auto fst_var_renaming {sigma1.compose(s).project(fst_vars)};
            auto snd_vars {t.post_vars()};
            (*loop)->collectVars(snd_vars);
            for (const auto &x: t.pre_vars()) {
                snd_vars.erase(x);
            }
            auto snd_var_renaming {sigma2.compose(var_renaming).project(snd_vars)};
            var_renaming = fst_var_renaming.compose(snd_var_renaming);
        } else {
            loop = rule;
            var_renaming = s;
        }
    }
    auto vars {(*loop)->vars()};
    var_renaming.collectCoDomainVars(vars);
    pre->collectVars(vars);
    const auto model {solver->model(vars).composeBackwards(var_renaming)};
    return {pre && *loop, model};
}

void SABMC::add_learned_clause(const Bools::Expr &accel, unsigned length) {
    if (Config::Analysis::log) std::cout << "learned transition: " << accel << std::endl;
    rule_map.left.insert(rule_map_t::left_value_type(next_id, accel));
    ++next_id;
    blocked.emplace_back(accel, length);
    step = step || encode_transition(accel);
}

std::optional<Arith::Expr> closest_lower_bound(const linked_hash_set<Bound> &bounds, const Arith::Model &model, const Arith::Var &x) {
    std::optional<Arith::Expr> closest;
    Rational dist;
    const auto val {x->eval(model)};
    for (const auto &b: bounds) {
        if (b.kind == BoundKind::Lower) {
            const auto b_val{b.bound->evalToRational(model)};
            const auto d{mp::abs(val - b_val)};
            if (!closest || d < dist || (d == dist && b.bound < *closest)) {
                dist = d;
                closest = b.bound;
            }
        }
    }
    return closest;
}

bool is_increasing(const Arith::Expr e, const Model &model, const Arith::Var x) {
    const auto next {model.composeBackwards(Subs::build<Arith>(x, x + arith::mkConst(1)))};
    const auto coeff {*e->coeff(x)};
    return model.eval<Arith>(coeff) - next.eval<Arith>(coeff) < 0;
}

Bools::Expr mbp(const Bools::Expr &t, const Model &model, const Bools::Var x) {
    return Subs::build<Bools>(x, Bools::constToExpr(model.get<Bools>(x)))(t);
}

Bools::Expr mbp(const Bools::Expr &t, const Model &model, const Arith::Var x) {
    auto bounds {t->getBounds(x)};
    const auto it {std::find_if(bounds.begin(), bounds.end(), [](const auto &b) {
        return b.kind == BoundKind::Equality;
    })};
    if (it != bounds.end()) {
        return Subs::build<Arith>(x, it->bound)(t);
    } else {
        const auto closest {closest_lower_bound(bounds, model.get<Arith>(), x)};
        if (closest) {
            return Subs::build<Arith>(x, *closest)(t);
        } else {
            return t->toMinusInfinity(x);
        }
    }
}

Bools::Expr mbp(const Bools::Expr &t, const Model &model, const Var &x) {
    return std::visit(
        Overload{
            [&](const Bools::Var x) {
                return mbp(t, model, x);
            },
            [&](const Arith::Var x) {
                const auto res {mbp(t, model, x)};
                assert(res != bot());
                return res;
            }
        }, x);
}

Bools::Expr SABMC::mbp(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var&)> &eliminate) const {
    Bools::Expr res {trans};
    for (const auto &x: trans->vars()) {
        if (eliminate(x)) {
            res = ::mbp(res, model, x);
        }
    }
    return res;
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
    const auto mbp_res {mbp(*simp, model, eliminate)};
    if (Config::Analysis::log) {
        std::cout << "mbp: " << mbp_res << std::endl;
    }
    return mbp_res;
}

Bools::Expr SABMC::specialize(const Bools::Expr pre, const Range &range, const std::function<bool(const Var&)> &eliminate) {
    if (range.empty()) {
        return top();
    }
    const auto [transition, model] {compress(pre, range)};
    if (Config::Analysis::log) {
        std::cout << "compressed:" << std::endl;
        std::cout << transition << std::endl;
        std::cout << "model: " << model << std::endl;
    }
    return specialize(transition, model, eliminate);
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
            if (!rel.isLinear() || !rel.isEq()) {
                continue;
            }
            const auto vars {rel.vars()};
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
            const auto t{rel.lhs()};
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
                const auto premise_even{bools::mkLit(arith::mkEq(
                    arith::mkMod(
                        n_term,
                        arith::mkConst(2)),
                    arith::mkConst(1)))};
                const auto conclusion_even{bools::mkLit(arith::mkEq(post, pre))};
                const auto premise_odd{bools::mkLit(arith::mkEq(
                    arith::mkMod(
                        n_term,
                        arith::mkConst(2)),
                    arith::mkConst(0)))};
                const auto conclusion_odd{bools::mkLit(arith::mkEq(post, -pre + addend))};
                res.insert(bools::mkOr(std::vector{premise_even, conclusion_even}));
                res.insert(bools::mkOr(std::vector{premise_odd, conclusion_odd}));
            }
        }
    } while (changed);
    // find vars that only depend on toggling vars:
    // x' = -x + c
    // y' = y + x + d
    // z' = z + x' + k
    for (const auto &rel : lits) {
        if (!rel.isLinear() || !rel.isEq()) {
            continue;
        }
        const auto vars{rel.vars()};
        std::optional<Arith::Var> pre;
        std::optional<Arith::Var> post;
        auto all_toggling {true};
        auto some_toggling {false};
        Arith::Subs even;
        Arith::Subs odd;
        const auto t{rel.lhs()};
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
                    even.put(x, n_term * c->divide(2));
                } else {
                    // y' = y + x' + ...
                    // y(0)=y, y(1)=y-x+c, y(2)=(y+x)-x+c=y+c, y(3)=(y-x+c)+c=y-x+2c y(4)=(y+x)-x+2c=y+2c, ...
                    odd.put(x, -x + (n_term + arith::mkConst(1)) * c->divide(2));
                    even.put(x, n_term * c->divide(2));
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
        const auto premise_even {bools::mkLit(arith::mkEq(
            arith::mkMod(
                n_term,
                arith::mkConst(2)),
            arith::mkConst(1)))};
        const auto conclusion_even {bools::mkLit(arith::mkEq(*post, *pre + even(var_addend) + n_term * constant_addend))};
        const auto premise_odd {bools::mkLit(arith::mkEq(
            arith::mkMod(
                n_term,
                arith::mkConst(2)),
            arith::mkConst(0)))};
        const auto conclusion_odd {bools::mkLit(arith::mkEq(*post, *pre + odd(var_addend) + n_term * constant_addend))};
        res.insert(bools::mkOr(std::vector{premise_even, conclusion_even}));
        res.insert(bools::mkOr(std::vector{premise_odd, conclusion_odd}));
    }
    // find recurrent equations and inequations
    linked_hash_map<Arith::Var, Int> eqs;
    linked_hash_map<Arith::Var, Int> lbs;
    linked_hash_map<Arith::Var, Int> ubs;
    for (const auto &rel: lits) {
        if (!rel.isLinear() || rel.isNeq()) {
            continue;
        }
        const auto vars {rel.vars()};
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
        const auto t {rel.lhs()};
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
        if (rel.isEq()) {
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
            const auto vars{rel.vars()};
            // keep literals that only refer to post-vars
            if (std::all_of(vars.begin(), vars.end(), theory::isPostVar)) {
                res.insert(bools::mkLit(rel));
            }
            if (!rel.isLinear()) {
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
                        const auto bounds = *(*rel.lhs()->coeff(x))->isInt() > 0 ? ubs : lbs;
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
                    res.insert(bools::mkLit(rel.subs(s)));
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
                        const auto bounds = *(*rel.lhs()->coeff(post))->isInt() > 0 ? ubs : lbs;
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
                    res.insert(bools::mkLit(rel.subs(s)));
                }
            }
        }
    }
    const auto ret {bools::mkAnd(res)};
    return ret;
}

void SABMC::handle_loop(const Range &range) {
    // std::cout << "computing init" << std::endl;
    // const auto init {specialize(t.init(), solver->model(t.init()->vars()), theory::isTempVar)};
    // std::cout << "computing stem" << std::endl;
    // const auto stem {specialize(init, Range::from_length(0, range.start()), [](const auto &x) {
    //     return !theory::isPostVar(x);
    // })};
    const auto loop {specialize(top(), range, theory::isTempVar)};
    Subs post_to_pre;
    for (const auto &x: vars) {
        if (theory::isProgVar(x)) {
            post_to_pre.put(theory::postVar(x), theory::toExpr(x));
        }
    }
    // const auto inv {CrabCfg::compute_invariants(post_to_pre(stem), loop)};
    const auto inv {CrabCfg::compute_invariants(top(), loop)};
    const auto rec {recurrence_analysis(loop)};
    add_learned_clause(inv && rec, range.length());
}

Bools::Expr SABMC::encode_transition(const Bools::Expr &t) {
    return t && theory::mkEq(trace_var, arith::mkConst(rule_map.right.at(t)));
}

void SABMC::add_blocking_clauses() {
    // std::cout << "BLOCKING CLAUSES" << std::endl;
    // std::cout << "depth: " << depth << std::endl;
    for (const auto &b : blocked) {
        const auto s {get_subs(depth, b.length)};
        const auto n_subs {Subs::build<Arith>(n, arith::mkConst(1))};
        const auto block {s(n_subs(!b.trans))};
        const auto id {arith::mkConst(rule_map.right.at(b.trans))};
        solver->add(block || bools::mkLit(arith::mkGeq(s.get<Arith>(trace_var), id)));
        // std::cout << "length: " << b.length << std::endl;
        // std::cout << "s: " << s << std::endl;
        // std::cout << "first blocking clause: " << (block || bools::mkLit(arith::mkGeq(s.get<Arith>(trace_var), id))) << std::endl;
        const auto cur {get_subs(depth, 1)};
        const auto next {get_subs(depth + 1, 1)};
        // std::cout << "cur: " << cur << std::endl;
        // std::cout << "next: " << next << std::endl;
        const std::vector<Bools::Expr> lits {theory::mkNeq(cur.get<Arith>(trace_var), id), theory::mkNeq(next.get<Arith>(trace_var), id)};
        solver->add(bools::mkOr(lits));
        // std::cout << "second blocking clause: " << bools::mkOr(lits) << std::endl;
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
    std::vector<Subs> run;
    std::optional<Bools::Expr> prev;
    for (unsigned d = 0; d < depth; ++d) {
        const auto s {get_subs(d, 1)};
        const auto rule {rule_map.left.at(model.eval<Arith>(s.get<Arith>(trace_var)))};
        const auto comp {model.composeBackwards(s)};
        const auto imp {comp.syntacticImplicant(rule)};
        run.push_back(comp.toSubs().project(vars));
        if (prev) {
            dependency_graph.addEdge(*prev, imp);
        }
        prev = imp;
        trace.emplace_back(imp);
    }
    if (Config::Analysis::log) {
        std::cout << "trace:" << std::endl << trace;
        std::cout << "trace var: " << trace_var << std::endl;
        std::cout << "run:" << std::endl;
        for (const auto &s: run) {
            std::cout << s << std::endl;
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
    auto &post {subs.at(start + steps - 1).front()};
    while (pre_vec.size() < steps) {
        Subs s;
        for (const auto &var: vars) {
            if (theory::isProgVar(var)) {
                const auto post_var {theory::postVar(var)};
                s.put(var, pre_vec.front().get(var));
                s.put(post_var, post.get(post_var));
            } else {
                s.put(var, theory::toExpr(theory::next(var)));
            }
        }
        pre_vec.push_back(s);
    }
    // std::cout << "get_subs(" << start << ", " << steps << "): " << pre_vec.at(steps - 1) << std::endl;
    return pre_vec.at(steps - 1);
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
    step = bools::mkOr(steps);
    solver->add(t.init());
    solver->push();

    while (true) {
        const auto &s {get_subs(depth, 1)};
        solver->push();
        solver->add(s(t.err()));
        switch (solver->check()) {
        case SmtResult::Sat:
        case SmtResult::Unknown:
            unknown();
            return;
        case SmtResult::Unsat: {}
        }
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
        case SmtResult::Sat:
        case SmtResult::Unknown: {
            // std::cout << "model: " << solver->model() << std::endl;
            build_trace();
            if (Config::Analysis::log) std::cout << "starting loop handling" << std::endl;
            const auto range {has_looping_infix()};
            if (range) {
                handle_loop(*range);
                solver->pop();
                solver->push();
                depth = 0;
            }
            if (Config::Analysis::log) std::cout << "done with loop handling" << std::endl;
            break;
        }}
        if (Config::Analysis::log) {
            std::cout << "depth: " << depth << std::endl;
        }
    }
}

void SABMC::analyze(SafetyProblem &its) {
    SABMC(its).analyze();
}

std::ostream& operator<<(std::ostream &s, const std::vector<Bools::Expr> &trace) {
    for (const auto &imp: trace) {
        s << imp << std::endl;
    }
    return s;
}
