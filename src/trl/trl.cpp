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
#include "yices.hpp"

TRL::TRL(const ITSPtr its, const Config::TRPConfig &config) : TRPUtil(its, config) {
    BoolExprSet steps;
    for (const auto &[id, t]: rule_map) {
        steps.insert(encode_transition(t, id));
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
            const auto first {bools::mkAndFromLits(trace[start].implicant)};
            const auto last {bools::mkAndFromLits(trace[start + i].implicant)};
            if (dependency_graph.hasEdge(last, first) && (i > 0 || !learned_rule_map.contains(trace[start].id))) {
                if (i == 0) {
                    const auto loop {trp.mbp(trace[start].implicant, trace[start].model, theory::isTempVar)};
                    const auto fst_unrolling {renaming_central->get_subs(0,1)(loop)};
                    const auto snd_unrolling {renaming_central->get_subs(1,1)(loop)};
                    if (SmtFactory::check(fst_unrolling && snd_unrolling) == SmtResult::Unsat) {
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
    std::optional<Arith::Expr> rf;
    if (Config::Analysis::termination()) {
        if ((rf = prove_term(loop, model))) {
            // boundedness: rf > 0
            loop.insert(arith::mkGt(*rf, arith::mkConst(0)));
            // decrease: rf > rf'
            loop.insert(arith::mkGt((*rf)->renameVars(renaming_central->post_to_pre().get<Arith>()), (*rf)->renameVars(t.pre_to_post().get<Arith>())));
        } else {
            return false;
        }
    }
    if (TRPUtil::add_blocking_clauses(range, model)) {
        return true;
    }
    auto ti{trp.compute(loop, model)};
    if (Config::Analysis::termination()) {
        // boundedness: rf > 0
        ti.insert(arith::mkGt(*rf, arith::mkConst(0)));
        // decrease: rf > rf'
        ti.insert(arith::mkGt((*rf)->renameVars(renaming_central->post_to_pre().get<Arith>()), (*rf)->renameVars(t.pre_to_post().get<Arith>())));
    }

    Int id;
    Conjunction projected;
    const auto n {trp.get_n()};
    if (mbp_kind == Config::TRPConfig::RealQe) {
        projected = qe::real_qe(ti, model, [&](const auto &x) {
            return x == Var(n);
        });
        projected = *Preprocess::preprocessFormula(projected, theory::isTempVar);
        ti = projected;
        id = add_learned_clause(range, loop, ti);
    } else {
        ti = *Preprocess::preprocessFormula(ti, theory::isTempVar);
        id = add_learned_clause(range, loop, ti);
        model.put<Arith>(n, 1);
        projected = mbp::int_mbp(ti, model, mbp_kind, [&](const auto &x) {
            return x == Var(n);
        });
    }
    step = step || encode_transition(bools::mkAndFromLits(ti), id);
    if (range.length() == 1) {
        learned_rule_map.at(id).one_step_blocker = projected;
    } else {
        add_blocking_clause(range, id, bools::mkAndFromLits(projected));
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
        if (info.one_step_blocker) {
            solver->add(s1(!(*info.one_step_blocker)) || bools::mkLit(arith::mkGeq(s1.get<Arith>(trace_var), arith::mkConst(id))));
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
        const auto rule{encode_transition(rule_map.at(id), id)};
        const auto comp{model.composeBackwards(s)};
        const auto imp{comp.syntacticImplicant(rule)};
        const auto imp_be{bools::mkAndFromLits(imp)};
        auto relevant_vars{renaming_central->pre_vars()};
        for (const auto &x : renaming_central->pre_vars()) {
            relevant_vars.insert(theory::postVar(x));
        }
        imp.collectVars(relevant_vars);
        const auto projected_model{comp.project(relevant_vars)};
        if (prev) {
            dependency_graph.addEdge(prev->first, imp_be);
        }
        prev = {imp_be, id};
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
    std::unordered_map<Int, Bools::Expr> refinement;
    std::unordered_set<Int> to_refine{};
    while (true) {
        if (build_cex()) {
            return {SmtResult::Unsat, refinement};
        }
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
        for (const auto &t : trace) {
            const auto it {learned_rule_map.find(t.id)};
            if (it != learned_rule_map.end()) {
                to_refine.insert(t.id);
                for (const auto &[id, t] : it->second.loop) {
                    if (learned_rule_map.contains(id)) {
                        has_learned_transitions = true;
                    }
                    sub.add_transition(bools::mkAndFromLits(t));
                }
            } else {
                sub.add_transition(bools::mkAndFromLits(t.implicant));
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
                std::cout << "IMC: SAT" << std::endl;
                const auto itp {imc.get_itp()};
                for (const auto &id: to_refine) {
                    refinement.emplace(id, itp && t.pre_to_post()(itp));
                }
                return {SmtResult::Sat, refinement};
            }
            case SmtResult::Unsat: {
                std::cout << "IMC: UNSAT" << std::endl;
                if (!has_learned_transitions) {
                    return {SmtResult::Unsat, refinement};
                }
                model = imc.get_model();
                // TODO get cex from IMC and replace trace by it
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
            if (depth == 0) {
                return SmtResult::Unsat;
            }
            return SmtResult::Unknown;
            // model = solver->model();
            // solver->pop();
            // build_trace();
                    // std::cout << "STARTING REFINEMENT" << std::endl;
                    // const auto [res, refinement] {refine()};
                    // switch (res) {
                    //     case SmtResult::Sat: {
                    //         std::cout << "refinement succeeded" << std::endl;
                    //         for (const auto &[id, ref] : refinement) {
                    //             std::cout << id << " --> " << ref << std::endl;
                    //             if (learned_rule_map.contains(id)) {
                    //                 auto &t{rule_map.at(id)};
                    //                 t = t && ref;
                    //             }
                    //         }
                    //         while (depth > 0) {
                    //             pop();
                    //         }
                    //         blocked_per_step.clear();
                    //         BoolExprSet steps;
                    //         for (const auto &[id, t] : rule_map) {
                    //             steps.insert(encode_transition(t, id));
                    //         }
                    //         step = bools::mkOr(steps);
                    //         return std::nullopt;
                    //     }
                    //     case SmtResult::Unknown: {
                    //         std::cout << "refinement failed" << std::endl;
                    //         return SmtResult::Unknown;
                    //     }
                    //     case SmtResult::Unsat: {
                    //         return SmtResult::Unsat;
                    //     }
                    // }
            // break;
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
