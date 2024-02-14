#include "sabmc.hpp"
#include "chain.hpp"
#include "expr.hpp"
#include "preprocessing.hpp"
#include "rulepreprocessing.hpp"
#include "config.hpp"
#include "dependencygraph.hpp"
#include "recurrence.hpp"

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
    trace_var(NumVar::next()) {
    vars.insert(trace_var);
    vars.insert(n);
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
    }
    return {};
}

std::pair<Transition, Subs> SABMC::build_loop(const Range &range) {
    std::optional<Transition> loop;
    Subs var_renaming;
    for (unsigned i = range.end(); i >= range.start(); --i) {
        const auto imp {trace[i]};
        const auto rule {imp.subs(Subs::build<IntTheory>(n, get_subs(i, 1).get<IntTheory>(n)))};
        if (loop) {
            const auto [chained, sigma1, sigma2] {Chaining::chain(rule, *loop)};
            loop = chained;
            const auto fst_var_renaming {expr::compose(sigma1, get_subs(i, 1).project(rule.vars()))};
            const auto snd_var_renaming {expr::compose(sigma2, var_renaming)};
            var_renaming = expr::compose(fst_var_renaming, snd_var_renaming);
        } else {
            loop = rule;
            var_renaming = expr::compose(get_subs(i, 1).project(rule.vars()),  var_renaming);
        }
    }
    auto vars {loop->vars()};
    expr::collectCoDomainVars(var_renaming, vars);
    const auto model {expr::compose(var_renaming, solver->model(vars).toSubs())};
    if (Config::Analysis::log) {
        std::cout << "found loop of length " << range.length() << ":" << std::endl;
        std::cout << *loop << std::endl;
        std::cout << std::endl;
    }
    return {*loop, model};
}

void SABMC::add_learned_clause(const Transition &accel, unsigned length) {
    rule_map.emplace(accel.getId(), accel);
    blocked.emplace_back(accel.toBoolExpr()->subs(Subs::build<IntTheory>(n, 1)), length, accel.getId());
    step = step | encode_transition(accel);
}

std::optional<Expr> closest_bound(const linked_hash_set<Expr> &bounds, const Subs &model, const NumVar &x) {
    std::optional<Expr> closest;
    Num dist;
    const auto val {model.get<IntTheory>(x)};
    for (const auto &b: bounds) {
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
    do {
        changed = false;
        NEXT: for (const auto &[x,p]: update) {
            const auto &[lower,upper] {p};
            if (lower && !done_lower.contains(x)) {
                const auto vars {lower->vars()};
                ExprSubs subs;
                for (const auto &y: vars) {
                    std::optional<Expr> y_res;
                    if (is_increasing(*lower, model, y)) {
                        if (!done_lower.contains(y)) {
                            goto UPPER;
                        }
                        y_res = update[y].first;
                    } else {
                        if (!done_upper.contains(y)) {
                            goto UPPER;
                        }
                        y_res = update[y].second;
                    }
                    if (!y_res) {
                        done_lower.insert(x);
                        changed = true;
                        goto UPPER;
                    } else {
                        subs.put(y, *y_res);
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
                    std::optional<Expr> y_res;
                    if (is_increasing(*upper, model, y)) {
                        if (!done_upper.contains(y)) {
                            goto NEXT;
                        }
                        y_res = update[y].first;
                    } else {
                        if (!done_lower.contains(y)) {
                            goto NEXT;
                        }
                        y_res = update[y].second;
                    }
                    if (!y_res) {
                        done_upper.insert(x);
                        changed = true;
                        goto NEXT;
                    } else {
                        subs.put(y, *y_res);
                    }
                }
                done_upper.insert(x);
                changed = true;
                up.put(upper_vars[x], upper->subs(subs));
            }
        }
    } while (changed);
    const auto rec {Recurrence::solve(Subs::build<IntTheory>(up), n)};
    std::pair<NondetSubs, unsigned> res;
    if (rec) {
        for (const auto &[x,_]: update) {
            const auto low_var {lower_vars[x]};
            const auto up_var {upper_vars[x]};
            const auto low = rec->closed_form.contains(low_var) ? rec->closed_form.get<IntTheory>(low_var) : std::optional<Expr>();
            const auto up = rec->closed_form.contains(up_var) ? rec->closed_form.get<IntTheory>(up_var) : std::optional<Expr>();
            res.first.emplace(x, BoundPair{low_var, up_var});
        }
        res.second = rec->prefix;
    } else {
        res.second = 0;
    }
    return res;
}

linked_hash_map<BoolVar, bool> SABMC::value_selection(const Subs &model) const {
    linked_hash_map<BoolVar, bool> res;
    for (const auto &x: t.post_vars()) {
        if (std::holds_alternative<BoolVar>(x)) {
            const auto bv {std::get<BoolVar>(x)};
            res.emplace(bv, model.get<BoolTheory>(bv) == BExpression::top());
        }
    }
    return res;
}

SABMC::BoundPair SABMC::bound_selection(const Transition &t, const Subs &model, const NumVar &x) const {
    const auto bounds {t.toBoolExpr()->getBounds(x)};
    if (bounds.equality) {
        return {bounds.equality, bounds.equality};
    } else {
        return {closest_bound(bounds.lowerBounds, model, x), closest_bound(bounds.upperBounds, model, x)};
    }
}

SABMC::NondetSubs SABMC::bound_selection(const Transition &trans, const Subs &model) const {
    NondetSubs res;
    for (const auto &x: t.post_vars()) {
        if (std::holds_alternative<NumVar>(x)) {
            const auto nv {std::get<NumVar>(x)};
            res.emplace(nv, bound_selection(trans, model, nv));
        }
    }
    return res;
}

Transition mbp(const Transition &t, const Subs &model, const BoolVar &x) {
    return t.subs(Subs::build<BoolTheory>(x, model.get<BoolTheory>(x)));
}

Transition mbp(const Transition &t, const Subs &model, const NumVar &x) {
    const auto bounds {t.toBoolExpr()->getBounds(x)};
    if (bounds.equality) {
        return t.subs(Subs::build<IntTheory>(x, *bounds.equality));
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
                return mbp(t, model, x);
            }
        }, x);
}

Transition mbp(const Transition &t, const Subs &model) {
    Transition res {t};
    for (const auto &x: t.vars()) {
        if (expr::isTempVar(x)) {
            res = mbp(res, model, x);
        }
    }
    return res;
}

void SABMC::handle_rel(const Rel &rel, const NondetSubs &update, const NondetSubs &closed, const Subs &model, std::vector<BoolExpr> &res) {
    const auto lhs {rel.toG().makeRhsZero().lhs()};
    const auto vars {lhs.vars()};
    auto just_pre {true};
    for (const auto &x: vars) {
        if (!t.pre_vars().contains(x)) {
            just_pre = false;
            break;
        }
    }
    if (just_pre) {
        res.push_back(BExpression::buildTheoryLit(rel));
    }
    ExprSubs init;
    auto add_init {true};
    for (const auto &x: vars) {
        if (t.post_vars().contains(x)) {
            const auto up {update[x]};
            if (is_increasing(lhs, model, x)) {
                if (up.second) {
                    init.put(x, *up.second);
                } else {
                    add_init = false;
                    break;
                }
            } else {
                if (up.first) {
                    init.put(x, *up.first);
                } else {
                    add_init = false;
                    break;
                }
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
        if (t.pre_vars().contains(x)) {
            Expr updated;
            const auto up {closed[x]};
            if (is_increasing(lhs, model, x)) {
                if (up.second) {
                    updated = *up.second;
                } else {
                    add_but_last = false;
                    break;
                }
            } else {
                if (up.first) {
                    updated = *up.first;
                } else {
                    add_but_last = false;
                    break;
                }
            }
            but_last.put(x, updated.subs(dec_n));
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
    auto simp {Preprocess::preprocessTransition(loop)};
    const auto sip_res {simp->syntacticImplicant(model)};
    const auto mbp_res {mbp(sip_res, model)};
    const auto bool_update {value_selection(model)};
    const auto int_update {bound_selection(mbp_res, model)};
    const auto cp {closed_form(int_update, model)};
    const auto closed {cp.first};
    auto prefix {cp.second};
    std::vector<BoolExpr> res;
    for (const auto &lit: mbp_res.toBoolExpr()->lits()) {
        std::visit(
            Overload{
                [this, &res](const BoolLit &x) {
                    if (t.pre_vars().contains(x.getBoolVar())) {
                        res.push_back(BExpression::buildTheoryLit(x));
                    }
                },
                [&](const Rel &rel) {
                    handle_rel(rel, int_update, closed, model, res);
                }
            }, lit);
    }
    for (const auto &[x,p]: int_update) {
        const auto &[lower, upper] {p};
        const auto post_var {std::get<NumVar>(t.vars()->at(x))};
        if (lower) {
            res.push_back(BExpression::buildTheoryLit(Rel::buildLeq(*lower, post_var)));
        }
        if (upper) {
            res.push_back(BExpression::buildTheoryLit(Rel::buildLeq(post_var, *upper)));
        }
    }
    for (const auto &[x,b]: bool_update) {
        res.push_back(BExpression::buildTheoryLit(BoolLit(std::get<BoolVar>(t.vars()->at(x)), b)));
    }
    std::vector<BoolExpr> disj;
    disj.push_back(BExpression::buildAnd(res));
    if (prefix == 0 && !bool_update.empty()) {
        prefix = 1;
    }
    if (prefix > 0) {
        auto chained {mbp_res};
        disj.push_back(chained.toBoolExpr());
        for (unsigned i = 1; i < prefix; ++i) {
            chained = std::get<Transition>(Chaining::chain(chained, mbp_res));
            disj.push_back(chained.toBoolExpr());
        }
    }
    add_learned_clause(Transition(BExpression::buildOr(disj), t.vars()), range.length());
}

BoolExpr SABMC::encode_transition(const Transition &t) {
    return t.toBoolExpr() & Rel::buildEq(trace_var, t.getId());
}

void SABMC::add_blocking_clauses() {
    for (const auto &b: blocked) {
        const auto s {get_subs(depth, b.length)};
        const auto block {!b.trans->subs(s)};
        if (b.length == 1) {
            solver->add(block | Rel::buildGeq(trace_var, b.id).subs(s.get<IntTheory>()));
        } else {
            solver->add(block);
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
    const auto model {solver->model().toSubs()};
    std::vector<Subs> run;
    std::optional<Transition> prev;
    for (unsigned d = 0; d <= depth; ++d) {
        const auto s {get_subs(d, 1)};
        const auto rule {rule_map.at(s.get<IntTheory>(trace_var).subs(model.get<IntTheory>()).toNum().to_int())};
        const auto comp {expr::compose(s, model)};
        const auto imp {rule.syntacticImplicant(comp)};
        auto vars {this->vars};
        vars.insert(n);
        vars.insert(trace_var);
        run.push_back(comp.project(vars));
        if (prev) {
            dependency_graph.addEdge(*prev, imp);
        }
        prev = imp;
        trace.emplace_back(imp);
    }
    if (Config::Analysis::log) {
        std::cout << "trace:" << std::endl << trace;
        std::cout << "run:" << std::endl;
        for (const auto &s: run) {
            std::cout << s << std::endl;
        }
    }
}

const Subs& SABMC::get_subs(const unsigned start, const unsigned steps) {
    while (subs.size() < start + steps) {
        Subs s;
        for (const auto &var: vars) {
            const auto &post_var {t.vars()->at(var)};
            s.put(var, subs.back()[0].get(post_var));
            s.put(post_var, expr::toExpr(expr::next(post_var)));
        }
        subs.push_back({s});
    }
    auto &pre_vec {subs.at(start)};
    auto &pre {pre_vec.front()};
    auto &post {subs.at(start + steps - 1).front()};
    while (pre_vec.size() < steps) {
        Subs s;
        for (const auto &var: vars) {
            const auto &post_var {t.vars()->at(var)};
            s.put(var, pre.get(var));
            s.put(post_var, post.get(var));
        }
        pre_vec.push_back(s);
    }
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
        if (Config::Analysis::log) {
            std::cout << "Simplified Problem" << std::endl;
            // ITSExport::printForProof(its, std::cout);
        }
    }
    vars = t.pre_vars();
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
        case SmtResult::Sat: {
        case SmtResult::Unknown:
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
