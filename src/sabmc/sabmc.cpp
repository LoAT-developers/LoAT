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

SABMC::Loop::Loop(const Bools::Expr trans, const unsigned length): trans(trans), length(length) {}

SABMC::SABMC(SafetyProblem &t):
    t(t) {
    vars.insert(trace_var);
    vars.insert(n);
    for (const auto &x: t.vars()) {
        if (!theory::isPostVar(x)) {
            vars.insert(x);
        }
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

std::pair<Bools::Expr, Model> SABMC::build_loop(const Range &range) {
    std::optional<Bools::Expr> loop;
    Subs var_renaming;
    for (unsigned i = range.end(); i >= range.start(); --i) {
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
    const auto model {solver->model(vars).composeBackwards(var_renaming)};
    if (Config::Analysis::log) {
        std::cout << "found loop from " << range.start() << " to " << range.end() << ":" << std::endl;
        std::cout << *loop << std::endl;
        std::cout << std::endl;
    }
    return {*loop, model};
}

void SABMC::add_learned_clause(const Bools::Expr &accel, unsigned length) {
    if (Config::Analysis::log) std::cout << "learned transition: " << accel << std::endl;
    rule_map.left.insert(rule_map_t::left_value_type(next_id, accel));
    ++next_id;
    blocked.emplace_back(Subs::build<Arith>(n, arith::mkConst(1))(accel), length);
    step = step || encode_transition(accel);
}

std::optional<Arith::Expr> closest_bound(const linked_hash_set<Arith::Expr> &bounds, const Model &model, const Arith::Var &x, const linked_hash_set<Arith::Expr> &chosen = {}) {
    std::optional<Arith::Expr> closest;
    Int dist;
    const auto val {model.get<Arith>(x)};
    for (const auto &b: bounds) {
        if (chosen.contains(b)) {
            continue;
        }
        const auto b_val {model.eval<Arith>(b)};
        const auto d {mp::abs(val - b_val)};
        if (!closest || d < dist || (d == dist && b < *closest)) {
            dist = d;
            closest = b;
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
    const auto bounds {t->getBounds(x)};
    if (!bounds.realEqualities().empty()) {
        return Subs::build<Arith>(x, *bounds.realEqualities().begin())(t);
    } else {
        const auto closest =
            bounds.realLowerBounds().size() <= bounds.realUpperBounds().size() ?
                                 closest_bound(bounds.realLowerBounds(), model, x) :
                                 closest_bound(bounds.realUpperBounds(), model, x);
        if (closest) {
            return Subs::build<Arith>(x, *closest)(t);
        } else if (bounds.realLowerBounds().size() <= bounds.realUpperBounds().size()) {
            return t->toMinusInfinity(x);
        } else {
            return t->toInfinity(x);
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

Bools::Expr SABMC::mbp(const Bools::Expr &trans, const Model &model) const {
    Bools::Expr res {trans};
    for (const auto &x: trans->vars()) {
        if (theory::isTempVar(x)) {
            res = ::mbp(res, model, x);
        }
    }
    return res;
}

void SABMC::handle_loop(const Range &range) {
    const auto lm {build_loop(range)};
    const auto loop {lm.first};
    const auto model {lm.second};
    if (Config::Analysis::log) {
        std::cout << "model: " << model << std::endl;
    }
    const auto sip_res {model.syntacticImplicant(loop)};
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
    // TODO
    // add_learned_clause(bools::mkOr(disj), range.length());
}

Bools::Expr SABMC::encode_transition(const Bools::Expr &t) {
    return t && theory::mkEq(trace_var, arith::mkConst(rule_map.right.at(t)));
}

void SABMC::add_blocking_clauses() {
    for (const auto &b: blocked) {
        const auto s {get_subs(depth, b.length)};
        // std::cout << "blocking clause: " << b.trans->subs(Subs::build<IntTheory>(n, 1))) << std::endl;
        const auto block {Subs::build<Arith>(n, arith::mkConst(1)).compose(s)(!b.trans)};
        const auto id {arith::mkConst(rule_map.right.at(b.trans))};
        solver->add(block || bools::mkLit(arith::mkGeq(s.get<Arith>(trace_var), id)));
        const auto cur {get_subs(depth, 1)};
        const auto next {get_subs(depth + 1, 1)};
        const std::vector<Bools::Expr> lits {theory::mkNeq(trace_var, id), theory::mkNeq(trace_var, id)};
        solver->add(bools::mkOr(lits));
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
        const auto rule {rule_map.left.at(model.get<Arith>(trace_var))};
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
        Subs s;
        for (const auto &x: vars) {
            if (theory::isProgVar(x)) {
                const auto y {theory::postVar(x)};
                theory::apply(y, [&](const auto &y) {
                    const auto th{theory::theory(y)};
                    s.put<decltype(th)>(y, th.varToExpr(th.next()));
                });
            }
        }
        subs.push_back({s});
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
            // ITSExport::printForProof(its, std::cout);
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
        solver->add(s(step));
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

std::ostream& operator<<(std::ostream &s, const std::vector<Bools::Expr> &trace) {
    for (const auto &imp: trace) {
        s << imp << std::endl;
    }
    return s;
}
