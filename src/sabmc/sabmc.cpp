#include "sabmc.hpp"
#include "chain.hpp"
#include "expr.hpp"
#include "preprocessing.hpp"
#include "rulepreprocessing.hpp"
#include "config.hpp"
#include "dependencygraph.hpp"
#include "recurrence.hpp"
#include "map.hpp"
#include "theory.hpp"
#include "pair.hpp"
#include "optional.hpp"

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

Range Range::from_length(const unsigned start, const unsigned length) {
    return Range(start, start + length - 1);
}

Range Range::from_interval(const unsigned start, const unsigned end) {
    return Range(start, end);
}

SABMC::Loop::Loop(const BoolExpr trans, const unsigned length, const unsigned id): trans(trans), length(length), id(id) {}

SABMC::SABMC(SafetyProblem &t):
    t(t),
    var_map(*t.var_map()) {
    var_map.emplace(trace_var, NumVar::next());
    vars.insert(trace_var);
    var_map.emplace(n, NumVar::next());
    vars.insert(n);
    for (const auto &[x,y]: var_map) {
        inverse_var_map.emplace(y, x);
    }
    for (const auto &x: t.vars()) {
        if (!t.post_vars().contains(x)) {
            vars.insert(x);
        }
    }
    for (const auto &x: t.pre_vars().get<NumVar>()) {
        lower_vars.emplace(x, NumVar::next());
        upper_vars.emplace(x, NumVar::next());
        reverse_low_up_vars.put(lower_vars[x], x);
        reverse_low_up_vars.put(upper_vars[x], x);
    }
    solver->enableModels();
}

std::optional<Range> SABMC::has_looping_infix() {
    auto start {trace.size() - 1};
    auto end {trace.size() - 1};
    while (end > 0) {
        while (start > 0) {
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

std::pair<Transition, Subs> SABMC::build_loop(const Range &range) {
    std::optional<Transition> loop;
    Subs var_renaming;
    for (unsigned i = range.end(); i >= range.start(); --i) {
        const auto rule {trace[i]};
        const auto s {get_subs(i, 1)};
        if (loop) {
            const auto [chained, sigma1, sigma2] {Chaining::chain(rule, *loop)};
            loop = chained;
            auto fst_vars {t.pre_vars()};
            rule.collectVars(fst_vars);
            for (const auto &x: t.post_vars()) {
                fst_vars.erase(x);
            }
            const auto fst_var_renaming {expr::compose(sigma1, s).project(fst_vars)};
            auto snd_vars {t.post_vars()};
            loop->collectVars(snd_vars);
            for (const auto &x: t.pre_vars()) {
                snd_vars.erase(x);
            }
            auto snd_var_renaming {expr::compose(sigma2, var_renaming).project(snd_vars)};
            var_renaming = expr::compose(fst_var_renaming, snd_var_renaming);
        } else {
            loop = rule;
            var_renaming = s;
        }
    }
    auto vars {loop->vars()};
    expr::collectCoDomainVars(var_renaming, vars);
    const auto model {expr::compose(var_renaming, solver->model(vars).toSubs())};
    if (Config::Analysis::log) {
        std::cout << "found loop from " << range.start() << " to " << range.end() << ":" << std::endl;
        std::cout << *loop << std::endl;
        std::cout << std::endl;
    }
    return {*loop, model};
}

void SABMC::add_learned_clause(const Transition &accel, unsigned length) {
    if (Config::Analysis::log) std::cout << "learned transition: " << accel << std::endl;
    rule_map.emplace(accel.getId(), accel);
    blocked.emplace_back(accel.toBoolExpr()->subs(Subs::build<IntTheory>(n, 1)), length, accel.getId());
    step = step | encode_transition(accel);
}

std::optional<Expr> closest_bound(const linked_hash_set<Expr> &bounds, const Subs &model, const NumVar &x, const linked_hash_set<Expr> &chosen = {}) {
    std::optional<Expr> closest;
    Num dist;
    const auto val {model.get<IntTheory>(x)};
    for (const auto &b: bounds) {
        if (chosen.contains(b)) {
            continue;
        }
        const auto b_val {b.subs(model.get<IntTheory>())};
        const auto d {GiNaC::abs((val - b_val).toNum())};
        if (!closest || d < dist || (d == dist && b_val < *closest)) {
            dist = d;
            closest = b;
        }
    }
    return closest;
}

bool is_increasing(const Expr &e, const Subs &model, const NumVar &x) {
    const auto &current {model.get<IntTheory>()};
    const auto next {ExprSubs{{x, Expr(x) + 1}}.compose(current)};
    return (e.coeff(x).subs(current) - e.coeff(x).subs(next)).toNum() < 0;
}

std::pair<SABMC::NondetSubs, unsigned> SABMC::closed_form(const NondetSubs &update, const Subs &model) {
    ExprSubs up;
    std::unordered_set<NumVar> done_lower;
    std::unordered_set<NumVar> done_upper;
    auto changed {false};
    ExprSubs dec_n {{n, Expr(n)-1}};
    do {
        changed = false;
        for (const auto &[x,p]: update) {
            const auto &[lower,upper] {p};
            if (lower && !done_lower.contains(x)) {
                const auto vars {lower->vars()};
                ExprSubs subs;
                for (const auto &y: vars) {
                    if (y == x) {
                        subs.put(x, lower_vars[x]);
                    } else {
                        const auto y_pre = t.pre_vars().contains(y) ? y : std::get<NumVar>(inverse_var_map[y]);
                        std::optional<Expr> y_res;
                        if (is_increasing(*lower, model, y)) {
                            if (!done_lower.contains(y_pre)) {
                                goto UPPER;
                            }
                            if (up.contains(lower_vars[y_pre])) {
                                y_res = up.get(lower_vars[y_pre]);
                            }
                        } else {
                            if (!done_upper.contains(y_pre)) {
                                goto UPPER;
                            }
                            if (up.contains(upper_vars[y_pre])) {
                                y_res = up.get(upper_vars[y_pre]);
                            }
                        }
                        if (!y_res) {
                            done_lower.insert(x);
                            changed = true;
                            goto UPPER;
                        } else {
                            if (t.pre_vars().contains(y)) {
                                y_res = y_res->subs(dec_n);
                            }
                            subs.put(y, *y_res);
                        }
                    }
                }
                done_lower.insert(x);
                changed = true;
                up.put(lower_vars[x], lower->subs(subs));
            }
            UPPER: if (upper && !done_upper.contains(x)) {
                const auto vars {upper->vars()};
                ExprSubs subs;
                for (const auto &y: vars) {
                    if (y == x) {
                        subs.put(x, upper_vars[x]);
                    } else {
                        const auto y_pre = t.pre_vars().contains(y) ? y : std::get<NumVar>(inverse_var_map[y]);
                        std::optional<Expr> y_res;
                        if (is_increasing(*upper, model, y)) {
                            if (!done_upper.contains(y_pre)) {
                                goto NEXT;
                            }
                            if (up.contains(upper_vars[y_pre])) {
                                y_res = up.get(upper_vars[y_pre]);
                            }
                        } else {
                            if (!done_lower.contains(y_pre)) {
                                goto NEXT;
                            }
                            if (up.contains(lower_vars[y_pre])) {
                                y_res = up.get(lower_vars[y_pre]);
                            }
                        }
                        if (!y_res) {
                            done_upper.insert(x);
                            changed = true;
                            goto NEXT;
                        } else {
                            if (t.pre_vars().contains(y)) {
                                y_res = y_res->subs(dec_n);
                            }
                            subs.put(y, *y_res);
                        }
                    }
                }
                done_upper.insert(x);
                changed = true;
                up.put(upper_vars[x], upper->subs(subs));
            }
            NEXT:;
        }
    } while (changed);
    const auto rec {Recurrence::solve(Subs::build<IntTheory>(up), n)};
    std::pair<NondetSubs, unsigned> res;
    if (rec) {
        for (const auto &[x,_]: update) {
            const auto low_var {lower_vars[x]};
            const auto up_var {upper_vars[x]};
            const auto low = rec->closed_form.contains(low_var) ? rec->closed_form.get<IntTheory>(low_var).subs(reverse_low_up_vars) : std::optional<Expr>();
            const auto up = rec->closed_form.contains(up_var) ? rec->closed_form.get<IntTheory>(up_var).subs(reverse_low_up_vars) : std::optional<Expr>();
            res.first.emplace(x, BoundPair{low, up});
        }
        res.second = rec->prefix;
    } else {
        res.second = 0;
    }
    return res;
}

linked_hash_map<BoolVar, bool> SABMC::value_selection(const Subs &model) const {
    linked_hash_map<BoolVar, bool> res;
    for (const auto &x: t.pre_vars()) {
        if (std::holds_alternative<BoolVar>(x)) {
            const auto bv {std::get<BoolVar>(x)};
            res.emplace(bv, model.get(var_map[x]) == ThExpr(BExpression::top()));
        }
    }
    return res;
}

SABMC::BoundPair SABMC::bound_selection(const Transition &trans, const Subs &model, const NumVar &x, linked_hash_set<Expr> &chosen) const {
    const auto post_var {std::get<NumVar>(var_map[x])};
    const auto bounds {trans.toBoolExpr()->getBounds(post_var)};
    if (!bounds.equalities.empty()) {
        std::optional<Expr> res;
        for (const auto &e: bounds.equalities) {
            if (!res) {
                res = e;
            } else {
                const auto old_rec {res->has(x)};
                const auto new_rec {e.has(x)};
                if (!old_rec && new_rec) {
                    res = e;
                } else if (old_rec == new_rec) {
                    const auto is_post = [this](const auto x) {
                        return t.post_vars().contains(x);
                    };
                    const auto old_post {res->hasVarWith(is_post)};
                    const auto new_post {e.hasVarWith(is_post)};
                    if (old_post && !new_post) {
                        res = e;
                    } else if (old_post == new_post) {
                        const auto old_vars {res->vars().size()};
                        const auto new_vars {e.vars().size()};
                        if (old_vars > new_vars) {
                            res = e;
                        }
                    }
                }
            }
        }
        if (res) {
            chosen.emplace(*res);
            return {res, res};
        }
    }
    const auto lower {closest_bound(bounds.lowerBounds, model, post_var, chosen)};
    const auto upper {closest_bound(bounds.upperBounds, model, post_var, chosen)};
    if (lower) {
        chosen.emplace(*lower);
    }
    if (upper) {
        chosen.emplace(*upper);
    }
    return {lower, upper};
}

SABMC::NondetSubs SABMC::bound_selection(const Transition &trans, const Subs &model) const {
    NondetSubs res;
    linked_hash_set<Expr> chosen;
    for (const auto &x: t.pre_vars()) {
        if (std::holds_alternative<NumVar>(x)) {
            const auto nv {std::get<NumVar>(x)};
            res.emplace(nv, bound_selection(trans, model, nv, chosen));
        }
    }
    return res;
}

Transition mbp(const Transition &t, const Subs &model, const BoolVar &x) {
    return t.subs(Subs::build<BoolTheory>(x, model.get<BoolTheory>(x)));
}

Transition mbp(const Transition &t, const Subs &model, const NumVar &x) {
    const auto bounds {t.toBoolExpr()->getBounds(x, SolvingLevel::ConstantCoeffs)};
    if (!bounds.equalities.empty()) {
        return t.subs(Subs::build<IntTheory>(x, *bounds.equalities.begin()));
    } else {
        const auto closest =
            bounds.lowerBounds.size() <= bounds.upperBounds.size() ?
                                 closest_bound(bounds.lowerBounds, model, x) :
                                 closest_bound(bounds.upperBounds, model, x);
        const auto lin {t.linearize(x)};
        if (closest) {
            return lin.subs(Subs::build<IntTheory>(x, *closest));
        } else if (bounds.lowerBounds.size() <= bounds.upperBounds.size()) {
            return lin.toMinusInfinity(x);
        } else {
            return lin.toInfinity(x);
        }
    }
}

Transition mbp(const Transition &t, const Subs &model, const Var &x) {
    return std::visit(
        Overload{[&](const BoolVar &x) {
                return mbp(t, model, x);
            },
            [&](const NumVar &x) {
                const auto res {mbp(t, model, x)};
                assert(!res.toBoolExpr()->isTriviallyFalse());
                return res;
            }
        }, x);
}

Transition SABMC::mbp(const Transition &trans, const Subs &model) const {
    Transition res {trans};
    for (const auto &x: trans.vars()) {
        if (expr::isTempVar(x) && !t.post_vars().contains(x)) {
            res = ::mbp(res, model, x);
        }
    }
    return res;
}

void SABMC::handle_rel(const Rel &rel, const NondetSubs &update, const NondetSubs &closed, const Subs &model, std::vector<BoolExpr> &res) {
    const auto lhs {rel.toG().makeRhsZero().lhs()};
    const auto vars {lhs.vars()};
    ExprSubs init;
    auto add_init {true};
    for (const auto &x: vars) {
        if (t.post_vars().contains(x)) {
            const auto pre {std::get<NumVar>(inverse_var_map[x])};
            const auto up {update.get(pre)};
            if (up) {
                if (is_increasing(lhs, model, x)) {
                    if (up->second && !up->second->hasVarWith([this](const auto &x) {
                            return t.post_vars().contains(x);
                        })) {
                        init.put(x, *up->second);
                    } else {
                        add_init = false;
                        break;
                    }
                } else {
                    if (up->first && !up->first->hasVarWith([this](const auto &x) {
                            return t.post_vars().contains(x);
                        })) {
                        init.put(x, *up->first);
                    } else {
                        add_init = false;
                        break;
                    }
                }
            } else {
                add_init = false;
            }
        }
    }
    if (add_init) {
        res.push_back(BExpression::buildTheoryLit(rel.subs(init)));
    }
    auto dec_n {ExprSubs{{n, Expr(n) - 1}}};
    auto add_but_last {true};
    ExprSubs but_last;
    for (const auto &x: vars) {
        if (!t.post_vars().contains(x)) {
            Expr updated;
            if (closed.contains(x)) {
                const auto up {closed[x]};
                if (is_increasing(lhs, model, x)) {
                    if (up.second) {
                        updated = *up.second;
                    } else {
                        add_but_last = false;
                    }
                } else {
                    if (up.first) {
                        updated = *up.first;
                    } else {
                        add_but_last = false;
                    }
                }
            } else {
                add_but_last = false;
            }
            if (add_but_last) {
                but_last.put(x, updated.subs(dec_n));
            } else {
                break;
            }
        }
    }
    if (add_but_last) {
        res.push_back(BExpression::buildTheoryLit(rel.subs(but_last)));
    }
}

void SABMC::handle_loop(const Range &range) {
    const auto lm {build_loop(range)};
    const auto loop {lm.first};
    const auto model {lm.second};
    if (Config::Analysis::log) {
        std::cout << "model: " << model << std::endl;
    }
    const auto sip_res {loop.syntacticImplicant(model)};
    if (Config::Analysis::log) {
        std::cout << "sip: " << sip_res << std::endl;
    }
    auto simp {Preprocess::preprocessTransition(sip_res)};
    if (Config::Analysis::log && simp) {
        std::cout << "simplified: " << *simp << std::endl;
    }
    const auto mbp_res {mbp(*simp, model)};
    if (Config::Analysis::log) {
        std::cout << "mbp: " << mbp_res << std::endl;
    }
    const auto bool_update {value_selection(model)};
    if (Config::Analysis::log && !bool_update.empty()) {
        std::cout << "bool update: " << bool_update << std::endl;
    }
    const auto int_update {bound_selection(mbp_res, model)};
    if (Config::Analysis::log && !int_update.empty()) {
        std::cout << "int update: " << int_update << std::endl;
    }
    const auto cp {closed_form(int_update, model)};
    const auto closed {cp.first};
    auto prefix {cp.second};
    if (Config::Analysis::log) {
        std::cout << "closed form: " << closed << std::endl;
        std::cout << "prefix: " << prefix << std::endl;
    }
    std::vector<BoolExpr> res;
    for (const auto &lit: mbp_res.toBoolExpr()->lits()) {
        std::visit(
            Overload {
                [&](const Rel &rel) {
                    if (rel.isEq()) {
                        handle_rel(Rel::buildGeq(rel.lhs(), rel.rhs()), int_update, closed, model, res);
                        handle_rel(Rel::buildLeq(rel.lhs(), rel.rhs()), int_update, closed, model, res);
                    } else {
                        handle_rel(rel, int_update, closed, model, res);
                    }
                },
                [](const auto &){}
            }, lit);
    }
    if (Config::Analysis::log) {
        std::cout << "handled rels: " << BExpression::buildAnd(res) << std::endl;
    }
    for (const auto &[x,b]: bool_update) {
        const auto post {std::get<BoolVar>(var_map[x])};
        res.push_back(BExpression::buildTheoryLit(BoolLit(post, b)));
    }
    res.push_back(BExpression::buildTheoryLit(Rel::buildGeq(n, Expr(prefix))));
    std::vector<BoolExpr> disj;
    disj.push_back(BExpression::buildAnd(res));
    if (prefix > 1) {
        auto chained {mbp_res};
        disj.push_back(chained.toBoolExpr());
        for (unsigned i = 1; i < prefix; ++i) {
            chained = std::get<Transition>(Chaining::chain(chained, mbp_res));
            disj.push_back(chained.toBoolExpr());
        }
    }
    add_learned_clause(Transition::build(BExpression::buildOr(disj), t.var_map()), range.length());
}

BoolExpr SABMC::encode_transition(const Transition &t) {
    return t.toBoolExpr() & Rel::buildEq(trace_var, t.getId());
}

void SABMC::add_blocking_clauses() {
    for (const auto &b: blocked) {
        const auto s {get_subs(depth, b.length)};
        // std::cout << "blocking clause: " << b.trans->subs(Subs::build<IntTheory>(ExprSubs({{n, 1}}))) << std::endl;
        const auto block {!b.trans->subs(expr::compose(Subs::build<IntTheory>(ExprSubs({{n, 1}})), s))};
        solver->add(block | Rel::buildGeq(s.get<IntTheory>(trace_var), b.id));
        const auto cur {get_subs(depth, 1)};
        const auto next {get_subs(depth + 1, 1)};
        const std::vector<Lit> lits {Rel::buildNeq(cur.get<IntTheory>(trace_var), b.id), Rel::buildNeq(next.get<IntTheory>(trace_var), b.id)};
        solver->add(BExpression::buildOrFromLits(lits));
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
    const auto model {solver->model().toSubs()};
    std::vector<Subs> run;
    std::optional<Transition> prev;
    for (unsigned d = 0; d < depth; ++d) {
        const auto s {get_subs(d, 1)};
        const auto rule {rule_map.at(s.get<IntTheory>(trace_var).subs(model.get<IntTheory>()).toNum().to_int())};
        const auto comp {expr::compose(s, model)};
        const auto imp {rule.syntacticImplicant(comp)};
        run.push_back(comp.project(vars));
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
        Subs s;
        for (const auto &[_,x]: var_map) {
            expr::apply(x, [&s](const auto &x) {
                const auto th {expr::theory(x)};
                s.put<decltype(th)>(x, th.varToExpr(th.next()));
            });
        }
        subs.push_back({s});
    }
    while (subs.size() < start + steps) {
        Subs s;
        for (const auto &var: vars) {
            const auto post_var {var_map.get(var)};
            if (post_var) {
                s.put(var, subs.back()[0].get(*post_var));
                s.put(*post_var, expr::toExpr(expr::next(*post_var)));
            } else {
                s.put(var, expr::toExpr(expr::next(var)));
            }
        }
        subs.push_back({s});
    }
    auto &pre_vec {subs.at(start)};
    auto &post {subs.at(start + steps - 1).front()};
    while (pre_vec.size() < steps) {
        Subs s;
        for (const auto &var: vars) {
            const auto post_var {var_map.get(var)};
            if (post_var) {
                s.put(var, pre_vec.front().get(var));
                s.put(*post_var, post.get(*post_var));
            } else {
                s.put(var, expr::toExpr(expr::next(var)));
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
            // ITSExport::printForProof(its, std::cout);
        }
    }
    std::vector<BoolExpr> steps;
    for (const auto &trans: t.trans()) {
        rule_map.emplace(trans.getId(), trans);
        steps.push_back(encode_transition(trans));
    }
    step = BExpression::buildOr(steps);
    solver->add(t.init());
    solver->push();

    while (true) {
        const auto &s {get_subs(depth, 1)};
        solver->push();
        solver->add(t.err()->subs(s));
        switch (solver->check()) {
        case SmtResult::Sat:
        case SmtResult::Unknown:
            unknown();
            return;
        case SmtResult::Unsat: {}
        }
        solver->pop();
        solver->add(step->subs(s));
        add_blocking_clauses();
        ++depth;
        switch (solver->check()) {
        case SmtResult::Unsat:
            sat();
            return;
        case SmtResult::Sat:
        case SmtResult::Unknown: {
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

std::ostream& operator<<(std::ostream &s, const std::vector<Transition> &trace) {
    for (const auto &imp: trace) {
        s << imp << std::endl;
    }
    return s;
}
