#include "abmc.hpp"
#include "chain.hpp"
#include "theory.hpp"
#include "preprocessing.hpp"
#include "rulepreprocessing.hpp"
#include "smtfactory.hpp"
#include "loopacceleration.hpp"
#include "config.hpp"
#include "export.hpp"
#include "vector.hpp"
#include "rule.hpp"
#include "dependencygraph.hpp"
#include "ruleexport.hpp"

using namespace Config::ABMC;

ABMC::ABMC(ITSProblem &its):
    its(its),
    trace_var(ArithVar::next()) {
    vars.insert(trace_var);
    vars.insert(n);
    solver->enableModels();
}

bool ABMC::is_orig_clause(const TransIdx idx) const {
    return idx->getId() <= last_orig_clause;
}

bool ends_with_square(const std::vector<int> &w) {
    const auto start {w.rbegin()};
    const auto size {w.size()};
    const auto max_length {size / 2};
    auto end {start};
    for (auto length = 1u; length <= max_length; ++length) {
        ++end;
        if (std::equal(start, end, end)) {
            return true;
        }
    }
    return false;
}

bool ABMC::is_redundant(const std::vector<int> &ww) const {
    auto it {ww.begin()};
    const auto size {ww.size() / 2};
    for (auto i = 0u; i < size; ++i, ++it) {
        auto h {history.find(*it)};
        if (h != history.end()) {
            auto next {it};
            ++next;
            if (h->second.size() == size - 1 && std::equal(h->second.begin(), h->second.end(), next)) {
                return true;
            }
        }
    }
    return false;
}

std::optional<unsigned> ABMC::has_looping_suffix(unsigned start, std::vector<int> &lang) {
    const auto last {trace.back()};
    for (unsigned pos = start; pos > 0; --pos) {
        lang.push_back(get_language(pos));
        if (ends_with_square(lang)) {
            if (Config::Analysis::log) std::cout << "skipping square " << lang << std::endl;
            return {};
        } else {
            if (Config::Analysis::log) std::cout << lang << " does not have a square" << std::endl;
        }
        const auto &imp {trace[pos]};
        if (dependency_graph.hasEdge(last, imp)) {
            std::vector<int> ll{lang.begin(), lang.end()};
            ll.insert(ll.end(), lang.begin(), lang.end());
            if (is_redundant(ll)) {
                if (Config::Analysis::log) std::cout << "skipping redundant loop" << std::endl;
            } else {
                return pos;
            }
        }
    }
    return {};
}

int ABMC::get_language(unsigned i) {
    const auto imp {trace[i]};
    if (is_orig_clause(imp.first)) {
        const auto res {lang_map.emplace(imp, next)};
        if (res.second) {
            ++next;
        }
        return res.first->second;
    } else {
        return lang_map.at(imp);
    }
}

std::pair<Rule, Model> ABMC::build_loop(const int backlink) {
    std::optional<Rule> loop;
    Subs var_renaming;
    for (long i = trace.size() - 1; i >= backlink; --i) {
        const auto imp {trace[i]};
        const auto rule {imp.first
                            ->withGuard(imp.second)
                            .subs(Subs::build<Arith>(n, subs.at(i).get<Arith>(n)))};
        if (loop) {
            const auto [chained, sigma] {Chaining::chain(rule, *loop)};
            loop = chained;
            var_renaming = sigma.compose(var_renaming);
        } else {
            loop = rule;
        }
        var_renaming = subs[i].project(rule.vars()).compose(var_renaming);
    }
    auto vars {loop->vars()};
    var_renaming.collectCoDomainVars(vars);
    const auto model {solver->model(vars).composeBackwards(var_renaming)};
    auto up {loop->getUpdate()};
    const auto imp {model.syntacticImplicant(loop->getGuard())};
    const auto implicant {loop->withGuard(imp)};
    if (Config::Analysis::log) {
        std::cout << "found loop of length " << (trace.size() - backlink) << ":" << std::endl;
        RuleExport::printRule(implicant, std::cout);
        std::cout << std::endl;
    }
    return {implicant, model};
}

Bools::Expr ABMC::build_blocking_clause(const int backlink, const Loop &loop) {
    if (!blocking_clauses || loop.prefix > 1 || loop.period > 1 || !loop.deterministic) {
        return top();
    }
    const auto orig {loop.idx->subs(Subs::build<Arith>(n, arith::mkConst(1)))};
    const auto length{depth - backlink + 1};
    // we must not start another iteration of the loop in the next step,
    // so we require that we either use the learned transition,
    // or some implicant of the loop is violated
    VarSet pre_v;
    VarSet post_v;
    for (const auto &[x, y] : post_vars) {
        pre_v.insert(x);
        post_v.insert(y);
    }
    const auto not_trans {!encode_transition(&orig, false)};
    std::vector<Bools::Expr> pre;
    const auto s_next {subs_at(depth + 1).project(pre_v).compose(
            subs_at(depth + length).project(post_v))};
    pre.push_back(theory::mkEq(s_next.get(trace_var), arith::mkConst((*shortcut)->getId())));
    pre.push_back(s_next(not_trans));
    // we must not start another iteration of the loop after using the learned transition in the next step
    std::vector<Bools::Expr> post;
    post.push_back(theory::mkNeq(s_next.get(trace_var), arith::mkConst((*shortcut)->getId())));
    const auto s_next_next {subs_at(depth + 2).project(pre_v).compose(
            subs_at(depth + length + 1).project(post_v))};
    post.push_back(s_next_next(not_trans));
    const auto not_covered{s_next(!loop.covered)};
    return not_covered || (bools::mkOr(pre) && bools::mkOr(post));
}

TransIdx ABMC::add_learned_clause(const Rule &accel, const unsigned backlink) {
    const auto idx {its.addLearnedRule(accel, trace.at(backlink).first, trace.back().first)};
    rule_map.emplace(idx->getId(), idx);
    return idx;
}

std::optional<ABMC::Loop> ABMC::handle_loop(int backlink, const std::vector<int> &lang) {
    auto [loop, sample_point] {build_loop(backlink)};
    auto simp {Preprocess::preprocessRule(loop)};
    auto &map {cache.emplace(lang, std::unordered_map<Bools::Expr, std::optional<Loop>>()).first->second};
    for (const auto &[imp, loop]: map) {
        if (sample_point.eval<Bools>(imp)) {
            if (Config::Analysis::log) std::cout << "cache hit" << std::endl;
            if (loop) {
                shortcut = loop->idx;
                return loop;
            } else {
                return {};
            }
        }
    }
    const auto nonterm_to_query = [this](const Rule &rule, const acceleration::Result &accel_res) {
        if (Config::Analysis::tryNonterm() && accel_res.nonterm) {
            query = query || accel_res.nonterm->certificate;
            RuleProof nonterm_proof;
            std::stringstream ss;
            ss << "Original rule:" << std::endl;
            RuleExport::printRule(rule, ss);
            ss << std::endl;
            nonterm_proof.append(ss);
            ss << "Certificate:" << std::endl;
            ss << accel_res.nonterm->certificate;
            nonterm_proof.append(ss);
            nonterm_proof.storeSubProof(accel_res.nonterm->proof);
            proof.majorProofStep("Certificate of non-termination", nonterm_proof, its);
            if (Config::Analysis::log) {
                std::cout << "found certificate of non-termination" << std::endl;
                std::cout << accel_res.nonterm->certificate << std::endl;
            }
        }
    };
    if (Config::Analysis::tryNonterm() && !nonterm_cache.contains(lang)) {
        const AccelConfig config {.tryNonterm = true, .tryAccel = false, .n = n};
        const auto accel_res {LoopAcceleration::accelerate(*simp, config)};
        nonterm_to_query(*simp, accel_res);
        nonterm_cache.emplace(lang);
    }
    const auto deterministic {simp->isDeterministic()};
    if (Config::Analysis::reachability() && !deterministic) {
        if (Config::Analysis::log) std::cout << "not accelerating non-deterministic loop" << std::endl;
    } else if (Config::Analysis::reachability() && simp->getUpdate() == simp->getUpdate().concat(simp->getUpdate())) {
        if (Config::Analysis::log) std::cout << "acceleration would yield equivalent rule" << std::endl;
    } else if (Config::Analysis::reachability() && simp->getUpdate().empty()) {
        if (Config::Analysis::log) std::cout << "trivial looping suffix" << std::endl;
    } else {
        if (Config::Analysis::log && simp) {
            std::cout << "simplified loop:" << std::endl;
            RuleExport::printRule(*simp, std::cout);
            std::cout << std::endl;
        }
        const AccelConfig config {.tryNonterm = Config::Analysis::tryNonterm(), .n = n};
        const auto accel_res {LoopAcceleration::accelerate(*simp, config)};
        nonterm_to_query(*simp, accel_res);
        if (accel_res.accel) {
            auto simplified = Preprocess::preprocessRule(accel_res.accel->rule);
            if (simplified->getUpdate() != simp->getUpdate() && simplified->isPoly()) {
                const auto new_idx {add_learned_clause(*simplified, backlink)};
                shortcut = new_idx;
                history.emplace(next, lang);
                lang_map.emplace(Implicant(new_idx, new_idx->getGuard()), next);
                ++next;
                const Loop loop {.idx = new_idx,
                                .prefix = accel_res.prefix,
                                .period = accel_res.period,
                                .covered = accel_res.accel->covered,
                                .deterministic = deterministic};
                map.emplace(accel_res.accel->covered, loop);
                RuleProof sub_proof, acceleration_proof;
                acceleration_proof.storeSubProof(simp.getProof());
                acceleration_proof.ruleTransformationProof(*simp, "Loop Acceleration", accel_res.accel->rule);
                acceleration_proof.storeSubProof(accel_res.accel->proof);
                sub_proof.concat(acceleration_proof);
                sub_proof.concat(simplified.getProof());
                proof.majorProofStep("Accelerate", sub_proof, its);
                if (Config::Analysis::log) {
                    std::cout << "accelerated rule, idx " << new_idx->getId() << std::endl;
                    RuleExport::printRule(*simplified, std::cout);
                    std::cout << std::endl;
                }
                return loop;
            }
        }
    }
    map.emplace(top(), std::optional<Loop>());
    return {};
}

Bools::Expr ABMC::encode_transition(const TransIdx idx, const bool with_id) {
    const auto up {idx->getUpdate()};
    std::vector<Bools::Expr> res {idx->getGuard()};
    if (with_id) {
        res.emplace_back(theory::mkEq(trace_var, arith::mkConst(idx->getId())));
    }
    for (const auto &x: vars) {
        if (theory::isProgVar(x)) {
            res.push_back(theory::mkEq(theory::toExpr(post_vars.at(x)), up.get(x)));
        }
    }
    return bools::mkAnd(res);
}

void ABMC::unknown() {
    const auto str = Config::Analysis::reachability() ? "unknown" : "MAYBE";
    std::cout << str << std::endl;
    proof.result(str);
    proof.print();
}

void ABMC::unsat() {
    const auto str = Config::Analysis::reachability() ? "unsat" : "NO";
    std::cout << str << std::endl;
    proof.append("reached error location at depth " + std::to_string(depth));
    proof.result(str);
    proof.print();
}

void ABMC::sat() {
    const auto str = Config::Analysis::reachability() ? "sat" : "MAYBE";
    std::cout << str << std::endl;
    proof.append(std::to_string(depth) + "-fold unrolling of the transition relation is unsatisfiable");
    proof.result(str);
    proof.print();
}

void ABMC::build_trace() {
    trace.clear();
    const auto model {solver->model()};
    std::vector<Subs> run;
    std::optional<Implicant> prev;
    for (unsigned d = 0; d <= depth; ++d) {
        const auto m {model.composeBackwards(subs.at(d))};
        const auto rule {rule_map.at(m.get<Arith>(trace_var))};
        const auto imp {m.syntacticImplicant(rule->getGuard())};
        auto vars {rule->getUpdate().domain()};
        vars.insert(n);
        vars.insert(trace_var);
        run.push_back(m.toSubs().project(vars));
        const Implicant i {rule, imp};
        if (prev) {
            dependency_graph.addEdge(*prev, i);
        }
        prev = i;
        trace.emplace_back(rule, imp);
    }
    if (Config::Analysis::log) {
        std::cout << "trace:" << std::endl << trace;
        std::cout << "run:" << std::endl;
        for (const auto &s: run) {
            std::cout << s << std::endl;
        }
    }
}

const Subs& ABMC::subs_at(const unsigned i) {
    while (subs.size() <= i) {
        Subs s;
        for (const auto &var: vars) {
            const auto &post_var {post_vars.at(var)};
            s.put(var, subs.back().get(post_var));
            s.put(post_var, theory::toExpr(theory::next(post_var)));
        }
        subs.push_back(s);
    }
    return subs.at(i);
}

void ABMC::analyze() {
    if (Config::Analysis::log) {
        std::cout << "initial ITS" << std::endl;
        its.print(std::cout);
    }
    proof.majorProofStep("Initial ITS", ITSProof(), its);
    const auto res {Preprocess::preprocess(its)};
    if (res) {
        proof.concat(res.getProof());
        if (Config::Analysis::log) {
            std::cout << "Simplified ITS" << std::endl;
            ITSExport::printForProof(its, std::cout);
        }
    }
    vars.insertAll(its.getVars());
    for (const auto &var: vars) {
        post_vars.emplace(var, theory::next(var));
    }
    last_orig_clause = 0;
    for (const auto &r: its.getAllTransitions()) {
        rule_map.emplace(r.getId(), &r);
        last_orig_clause = std::max(last_orig_clause, r.getId());
    }
    std::vector<Bools::Expr> inits;
    for (const auto &idx: its.getInitialTransitions()) {
        if (its.isSinkTransition(idx)) {
            switch (SmtFactory::check(idx->getGuard())) {
            case SmtResult::Sat:
                unsat();
                return;
            case SmtResult::Unknown:
                if (Config::Analysis::log) {
                    std::cout << "got unknown from SMT solver -- approximating" << std::endl;
                }
                approx = true;
                break;
            case SmtResult::Unsat: {}
            }
        } else {
            inits.push_back(encode_transition(idx));
        }
    }
    solver->add(bools::mkOr(inits));

    std::vector<Bools::Expr> steps;
    for (const auto &r: its.getAllTransitions()) {
        if (its.isInitialTransition(&r) || its.isSinkTransition(&r)) {
            continue;
        }
        steps.push_back(encode_transition(&r));
    }
    const auto step {bools::mkOr(steps)};

    std::vector<Bools::Expr> queries;
    for (const auto &idx: its.getSinkTransitions()) {
        if (!its.isInitialTransition(idx)) {
            queries.push_back(idx->getGuard());
        }
    }
    query = bools::mkOr(queries);

    while (true) {
        const auto &s {subs_at(depth + 1)};
        solver->push();
        solver->add(s(query));
        switch (solver->check()) {
        case SmtResult::Sat:
            build_trace();
            unsat();
            return;
        case SmtResult::Unknown:
            if (Config::Analysis::log && !approx) {
                std::cout << "got unknown from SMT solver -- approximating" << std::endl;
            }
            approx = true;
            break;
        case SmtResult::Unsat: {}
        }
        solver->pop();
        if (!shortcut) {
            solver->add(s(step));
        } else {
            solver->add(s(encode_transition(*shortcut) || step));
        }
        ++depth;
        Bools::Expr blocking_clause {top()};
        switch (solver->check()) {
        case SmtResult::Unsat:
            if (!approx) {
                sat();
            }
            return;
        case SmtResult::Sat: {
            shortcut.reset();
            build_trace();
            std::vector<int> lang;
            if (Config::Analysis::log) std::cout << "starting loop handling" << std::endl;
            const auto backlink = has_looping_suffix(trace.size() - 1, lang);
            if (backlink) {
                const auto loop {handle_loop(*backlink, lang)};
                if (loop) {
                    blocking_clause = build_blocking_clause(*backlink, *loop);
                }
            }
            if (Config::Analysis::log) std::cout << "done with loop handling" << std::endl;
            break;
        }
        case SmtResult::Unknown:
            shortcut.reset();
            trace.clear();
        }
        if (Config::Analysis::log) {
            std::cout << "depth: " << depth << std::endl;
        }
        if (blocking_clause != top()) {
            solver->add(blocking_clause);
        }
    }
}

void ABMC::analyze(ITSProblem &its) {
    ABMC(its).analyze();
}

std::ostream& operator<<(std::ostream &s, const std::vector<Implicant> &trace) {
    for (const auto &imp: trace) {
        s << imp << std::endl;
    }
    return s;
}
