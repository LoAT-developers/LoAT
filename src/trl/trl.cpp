#include "trl.hpp"

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
#include "imcsafety.hpp"

TRL::TRL(const ITSPtr its, const Config::TRPConfig &config) : TRPUtil(its, config) {
    BoolExprSet steps;
    for (const auto &[id, t]: rule_map) {
        steps.insert(encode_transition(t.abstraction, id));
    }
    step = bools::mkOr(steps);
}

std::optional<Range> TRL::has_looping_infix() {
    for (unsigned i = 0; i < trace.size(); ++i) {
        for (unsigned start = 0; start + i < trace.size(); ++start) {
            if (Config::Analysis::termination() &&
                i > 0 &&
                model.get<Arith>(renaming_central->get_subs(start, 1).get<Arith>(safety_var)) >= 0 &&
                model.get<Arith>(renaming_central->get_subs(start + i, 1).get<Arith>(safety_var)) < 0) {
                continue;
            }
            if (dependency_graph.hasEdge(trace[start + i].implicant, trace[start].implicant) && (i > 0 || !learned_rule_map.contains(trace[start].id))) {
                if (i == 0) {
                    const auto loop {trp.mbp(trace[start].implicant, trace[start].model, theory::isTempVar)};
                    if (SmtFactory::check(renaming_central->get_subs(0,1)(loop) && renaming_central->get_subs(1,1)(loop)) == SmtResult::Unsat) {
                        continue;
                    }
                }
                return {Range::from_interval(start, start + i)};
            }
        }
    }
    return {};
}

bool TRL::handle_loop(const Range &range) {
    auto [loop, model]{specialize(range, theory::isTempVar)};
    Bools::Expr termination_argument {top()};
    if (Config::Analysis::termination()) {
        if (const auto rf {prove_term(loop, model)}) {
            termination_argument = bools::mkAndFromLits({arith::mkGt(*rf, arith::mkConst(0)), arith::mkGt((*rf)->renameVars(renaming_central->post_to_pre().get<Arith>()), (*rf)->renameVars(t.pre_to_post().get<Arith>()))});
            loop = loop && termination_argument;
        } else {
            return false;
        }
    }
    if (TRPUtil::add_blocking_clauses(range, model)) {
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
        projected = qe::real_qe(ti, model, theory::isTempVar);
        projected = Preprocess::preprocessFormula(projected, theory::isTempVar);
        ti = projected;
        id = add_learned_clause(range, ti);
    } else {
        ti = Preprocess::preprocessFormula(ti, theory::isTempVar);
        model.put<Arith>(n, 1);
        assert(model.eval<Bools>(ti));
        id = add_learned_clause(range, ti);
        projected = mbp::int_mbp(ti, model, mbp_kind, [&](const auto &x) {
            return x == Var(n);
        });
    }
    step = step || encode_transition(ti, id);
    if (range.length() == 1) {
        learned_rule_map.at(id).projection = projected;
    } else {
        add_blocking_clause(range, id, projected);
    }
    return true;
}

void TRL::add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) {
    const auto s{renaming_central->get_subs(range.start(), range.length())};
    auto &map{blocked_per_step.emplace(range.end(), std::map<Int, Bools::Expr>()).first->second};
    auto it{map.emplace(id, top()).first};
    if (Config::Analysis::termination()) {
        std::vector<Bools::Expr> disjuncts;
        disjuncts.emplace_back(s(!loop));
        if (range.length() == 1) {
            disjuncts.emplace_back(bools::mkLit(arith::mkGeq(s.get<Arith>(trace_var), arith::mkConst(id))));
        }
        const auto safety_loop {this->model.get<Arith>(renaming_central->get_subs(range.start(), 1).get<Arith>(safety_var)) >= 0};
        if (safety_loop) {
            const auto last_s {renaming_central->get_subs(range.end(), 1)};
            const auto no_safety_loop{bools::mkLit(arith::mkLt(last_s.get<Arith>(safety_var), arith::mkConst(0)))};
            disjuncts.emplace_back(no_safety_loop);
        } else {
            const auto first_s {renaming_central->get_subs(range.start(), 1)};
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

void TRL::add_blocking_clauses() {
    const auto s1{renaming_central->get_subs(depth, 1)};
    const auto s2{renaming_central->get_subs(depth + 1, 1)};
    for (const auto &[id, info] : learned_rule_map) {
        if (info.projection) {
            solver->add(s1(!(*info.projection)) || bools::mkLit(arith::mkGeq(s1.get<Arith>(trace_var), arith::mkConst(id))));
        }
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
    std::optional<std::pair<Bools::Expr, Int>> prev;
    for (unsigned d = 0; d < depth; ++d) {
        const auto s{renaming_central->get_subs(d, 1)};
        const auto id{model.eval<Arith>(s.get<Arith>(trace_var))};
        const auto rule{encode_transition(rule_map.at(id).abstraction, id)};
        const auto comp{model.composeBackwards(s)};
        const auto imp{comp.syntacticImplicant(rule)};
        auto relevant_vars{renaming_central->pre_vars()};
        for (const auto &x : renaming_central->pre_vars()) {
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

void TRL::pop() {
    solver->pop();
    --depth;
}

std::pair<SmtResult, std::unordered_map<Int, Bools::Expr>> TRL::refine() {
    Model model;
    model.get<Arith>() = solver->model().get<Arith>();
    std::unordered_map<Int, Bools::Expr> refinement;
    std::unordered_set<Int> to_refine{};
    while (true) {
        const auto opt {build_trace_for_refinement(model, depth)};
        if (!opt) {
            return {SmtResult::Unknown, refinement};
        }
        const auto var {*opt};
        if (std::holds_alternative<std::unordered_map<Int, Bools::Expr>>(var)) {
            return {SmtResult::Sat, std::get<std::unordered_map<Int, Bools::Expr>>(var)};
        }
        const auto trace {std::get<std::vector<std::pair<Int, Bools::Expr>>>(var)};
        // if (build_cex(trace)) {
        //     return {SmtResult::Unsat, refinement};
        // }
        SafetyProblem sub;
        for (const auto &x: t.pre_vars()) {
            sub.add_pre_var(x);
            sub.add_post_var(theory::postVar(x));
        }
        Renaming ren{renaming_central->get_subs(depth, 1)};
        sub.set_init(model.specialize(t.init()));
        Model composed_model {model.composeBackwards(ren)};
        sub.set_err(composed_model.specialize(t.err()));
        auto has_learned_transitions{false};
        for (const auto &[id,t] : trace) {
            const auto it {learned_rule_map.find(id)};
            if (it != learned_rule_map.end()) {
                to_refine.insert(id);
                for (const auto &[id, t] : it->second.loop) {
                    if (learned_rule_map.contains(id)) {
                        has_learned_transitions = true;
                    }
                    sub.add_transition(t);
                }
            } else {
                sub.add_transition(t);
            }
        }
        std::cout << sub << std::endl;
        IMCSafety imc(sub);
        const auto res{imc.analyze()};
        switch (res) {
            case SmtResult::Unknown: {
                return {SmtResult::Unknown, refinement};
            }
            case SmtResult::Sat: {
                const auto itp {imc.get_itp()};
                for (const auto &id: to_refine) {
                    refinement.emplace(id, itp && t.pre_to_post()(itp));
                }
                return {SmtResult::Sat, refinement};
            }
            case SmtResult::Unsat: {
                if (!has_learned_transitions) {
                    return {SmtResult::Unsat, refinement};
                }
                model = imc.get_model();
                break;
            }
        }
    }
}

std::optional<SmtResult> TRL::do_step() {
    auto s{renaming_central->get_subs(depth, 1)};
    // push error states
    solver->push();
    solver->add(s(t.err()));
    switch (solver->check()) {
        case SmtResult::Unknown: {
            return SmtResult::Unknown;
        }
        case SmtResult::Sat: {
            std::cout << "STARTING REFINEMENT" << std::endl;
            const auto [res, refinement] {refine()};
            solver->pop();
            switch (res) {
                case SmtResult::Sat: {
                    std::cout << "refinement succeeded" << std::endl;
                    std::unordered_set<Int> invalidated {};
                    for (const auto &[id,ref]: refinement) {
                        std::cout << id << " --> " << ref << std::endl;
                        auto &info {rule_map.at(id)};
                        info.abstraction = info.abstraction && ref;
                        invalidated.insert(info.offsprings.begin(), info.offsprings.end());
                        info.offsprings.clear();
                        if (learned_rule_map.contains(id)) {
                            info.t = info.t && ref;
                        } else {
                            info.abstraction = info.abstraction && ref;
                            rule_map.emplace(-Int(next_orig_id), TransInfo(info.t, info.abstraction && !ref));
                            ++next_orig_id;
                        }
                    }
                    size_t size {0};
                    do {
                        size = invalidated.size();
                        std::unordered_set<Int> invalidate {};
                        for (const auto &i: invalidated) {
                            const auto it {rule_map.find(i)};
                            if (it != rule_map.end()) {
                                invalidate.insert(it->second.offsprings.begin(), it->second.offsprings.end());
                            }
                        }
                        invalidated.insert(invalidate.begin(), invalidate.end());
                    } while (invalidated.size() > size);
                    for (const auto &i: invalidated) {
                        rule_map.erase(i);
                        learned_rule_map.erase(i);
                    }
                    while (depth > 0) {
                        pop();
                    }
                    blocked_per_step.clear();
                    BoolExprSet steps;
                    for (const auto &[id, t] : rule_map) {
                        steps.insert(encode_transition(t.abstraction, id));
                    }
                    step = bools::mkOr(steps);
                    return std::nullopt;
                }
                case SmtResult::Unknown: {
                    std::cout << "refinement failed" << std::endl;
                    return SmtResult::Unknown;
                }
                case SmtResult::Unsat: {
                    return SmtResult::Unsat;
                }
            }
        }
        case SmtResult::Unsat: {
            // pop error states
            solver->pop();
            solver->push();
            solver->add(s(step));
            if (Config::Analysis::termination() && depth > 0) {
                solver->add(bools::mkLit(arith::mkGeq(renaming_central->get_subs(depth - 1, 1).get<Arith>(safety_var), s.get<Arith>(safety_var))));
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
                    model = solver->model();
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
    return std::nullopt;
}

ITSModel TRL::get_model() {
    std::vector<Bools::Expr> res{t.init()};
    Bools::Expr last{t.init()};
    for (unsigned i = 0; i < trace.size(); ++i) {
        const auto s1{renaming_central->get_subs(i, 1)};
        last = last && s1(step);
        Renaming s2;
        for (const auto &x : renaming_central->pre_vars()) {
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
