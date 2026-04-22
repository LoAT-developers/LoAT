#include "trl.hpp"

#include <ranges>

#include "dependencygraph.hpp"
#include "formulapreprocessing.hpp"
#include "intmbp.hpp"
#include "itstosafetyproblem.hpp"
#include "linkedhashmap.hpp"
#include "optional.hpp"
#include "theory.hpp"
#include "eliminate.h"
#include "realqe.hpp"
#include "loopacceleration.hpp"

TRL::TRL(const ITSPtr& its, const Config::TRPConfig &config) : TRPUtil(its, config) {
    build_step();
}

void TRL::build_step() {
    std::vector<Bools::Expr> steps;
    for (const auto &[id,t]: rule_map) {
        steps.emplace_back(encode_transition(t, id));
    }
    step = bools::mkOr(steps);
}

std::optional<Range> TRL::has_looping_infix() {
    for (unsigned i = 0; i < trace.size(); ++i) {
        for (unsigned start = 0; start + i < trace.size(); ++start) {
            if (Config::Analysis::termination() &&
                i > 0 &&
                (*model)->get(safety_var->renameVars(get_subs(start, 1))) >= 0 &&
                (*model)->get(safety_var->renameVars(get_subs(start + i, 1))) < 0) {
                continue;
            }
            if (dependency_graph.hasEdge(trace[start + i].implicant, trace[start].implicant) && (i > 0 || trace[start].id <= last_orig_clause)) {
                if (i == 0) {
                    if (const auto loop {trp.mbp(trace[start].implicant, (*model)->composeBackwards(get_subs(start, 1)), theory::isTempCell)}; SmtFactory::check(loop->renameVars(get_subs(0,1)) && loop->renameVars(get_subs(1,1))) == SmtResult::Unsat) {
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
    const auto old_model = *model;
    if (Config::Analysis::abstraction_refinement) {
        if (const auto backtrack_point = refine_abstraction(range, true)) {
            if (Config::Analysis::log) {
                std::cout << "refined loop" << std::endl;
            }
            while (depth > *backtrack_point) {
                pop();
            }
            build_step();
            return true;
        }
    }
    auto [loop_non_bool, loop_bool, model]{specialize(range, theory::isTempCell)};
    auto loop = loop_non_bool && loop_bool;
    Bools::Expr termination_argument {top()};
    if (Config::Analysis::termination()) {
        if (const auto rf {prove_term(loop, model)}) {
            termination_argument =
                bools::mkAnd(
                    std::vector{
                        arith::mkGt(*rf, arith::zero()),
                        arith::mkGt(
                            (*rf)->renameVars(post_to_pre),
                            (*rf)->renameVars(t.pre_to_post()))
                    });
            loop_non_bool = loop_non_bool && termination_argument;
            loop = loop && termination_argument;
        } else {
            return false;
        }
    }
    if (TRPUtil::add_blocking_clauses(range, model)) {
        if (Config::Analysis::abstraction_refinement) {
            if (!add_blocking_clauses(range, old_model->composeBackwards(get_subs(range.start(), range.length())))) {
                if (last_model) {
                    CellSet cells;
                    loop_non_bool->collectCells(cells);
                    loop_bool->collectCells(cells);
                    if (std::ranges::all_of(cells, [&](const auto& c) {
                        return theory::apply(c, [&](const auto& c) {
                            return (*last_model)->get(c) == model->get(c);
                        });
                    })) {
                        last_model.reset();
                        const auto backtrack_point = refine_by_model(range, old_model);
                        if (!backtrack_point) {
                            throw std::logic_error("failed to refine with original model");
                        }
                        if (Config::Analysis::log) {
                            std::cout << "refined loop" << std::endl;
                        }
                        while (depth > *backtrack_point) {
                            pop();
                        }
                        build_step();
                        return true;
                    }
                }
            }
            last_model = model;
        }
        return true;
    }
    auto ti{trp.compute(loop_non_bool, loop_bool, model)};
    if (Config::Analysis::termination()) {
        ti = ti && termination_argument;
    }

    Int id;
    Bools::Expr projected{top()};
    const auto n {trp.get_n()};
    if (mbp_kind == Config::TRPConfig::RealQe) {
        projected = qe::real_qe(ti, model, [&](const auto &x) {
            return x == Cell(n);
        });
        projected = Preprocess::preprocessFormula(projected);
        ti = projected;
        id = add_learned_clause(range, ti);
    } else {
        ti = Preprocess::preprocessFormula(ti);
        id = add_learned_clause(range, ti);
        model->put(n, 1);
        projected = mbp::int_mbp(rule_map.at(id), model, mbp_kind, [&](const Cell &x) {
            return x == Cell(n);
        });
    }
    step = step || encode_transition(rule_map.at(id), id);
    if (range.length() == 1) {
        add_projection(id, projected);
    } else {
        add_blocking_clause(range, id, projected);
    }
    return true;
}

void TRL::add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) {
    const auto s{get_subs(range.start(), range.length())};
    auto &map{blocked_per_step.emplace(range.end(), std::map<Int, BoolExprSet>()).first->second};
    auto it{map.emplace(id, BoolExprSet()).first};
    if (Config::Analysis::termination()) {
        std::vector<Bools::Expr> disjuncts;
        disjuncts.emplace_back(!loop->renameVars(s));
        if (range.length() == 1) {
            disjuncts.emplace_back(
                bools::mkLit(
                    arith::mkGeq(
                        trace_var->renameVars(s),
                        arith::mkConst(id))));
        }
        if ((*model)->get(safety_var->renameVars(get_subs(range.start(), 1))) >= 0) {
            const auto last_s {get_subs(range.end(), 1)};
            const auto no_safety_loop{bools::mkLit(arith::mkLt(safety_var->renameVars(last_s), arith::zero()))};
            disjuncts.emplace_back(no_safety_loop);
        } else {
            const auto first_s {get_subs(range.start(), 1)};
            const auto no_term_loop{bools::mkLit(arith::mkGeq(safety_var->renameVars(first_s), arith::zero()))};
            disjuncts.emplace_back(no_term_loop);
        }
        it->second.insert(bools::mkOr(disjuncts));
    } else if (range.length() == 1) {
        it->second.insert((!loop || bools::mkLit(arith::mkGeq(trace_var, arith::mkConst(id))))->renameVars(s));
    } else {
        it->second.insert(!loop->renameVars(s));
    }
}

void TRL::build_trace() {
    trace.clear();
    model = solver->model();
    std::optional<std::pair<Bools::Expr, Int>> prev;
    for (unsigned d = 0; d < depth; ++d) {
        const auto s{get_subs(d, 1)};
        const auto id{(*model)->get(trace_var->renameVars(s))};
        const auto rule{encode_transition(rule_map.at(id), id)};
        const auto comp{(*model)->composeBackwards(s)};
        const auto [non_bool_imp, bool_imp] = comp->structuralImplicant(rule);
        const auto imp= bools::mkAnd(BoolExprSet{non_bool_imp, bool_imp, Arith::mkEq(trace_var, arith::mkConst(id))});
        if (prev) {
            dependency_graph.addEdge(prev->first, imp);
        }
        prev = {imp, id};
        trace.emplace_back(id, imp);
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
        for (unsigned i = 0; i < trace.size(); ++i) {
            std::cout << (*model)->composeBackwards(get_subs(i, 1))->toString(vars) << std::endl;
        }
    }
}

void TRL::pop() {
    solver->pop();
    --depth;
}

std::optional<SmtResult> TRL::do_step() {
    const auto s{get_subs(depth, 1)};
    // push error states
    solver->push();
    solver->add(t.err()->renameVars(s));
    switch (solver->check()) {
        case SmtResult::Unknown:
            return SmtResult::Unknown;
        case SmtResult::Sat:
            if (Config::Analysis::abstraction_refinement && depth > 0) {
                build_trace();
                if (Config::Analysis::log) {
                    std::cout << "proving safety failed, abstraction refinement" << std::endl;
                }
                if (const auto backtrack_point = refine_abstraction(Range::from_length(0, trace.size()), true)) {
                    solver->pop();
                    while (depth > *backtrack_point) {
                        pop();
                    }
                    build_step();
                    return std::nullopt;
                }
            }
            if (Config::Analysis::log) {
                std::cout << "proving safety failed, trying to construct counterexample" << std::endl;
            }
            build_trace();
            return build_cex() ? SmtResult::Unsat : SmtResult::Unknown;
        case SmtResult::Unsat: {
            // pop error states
            solver->pop();
            solver->push();
            solver->add(step->renameVars(s));
            if (Config::Analysis::termination() && depth > 0) {
                solver->add(bools::mkLit(arith::mkGeq(safety_var->renameVars(get_subs(depth - 1, 1)), safety_var->renameVars(s))));
            }
            add_blocking_clauses(depth);
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
                    if (const auto range{has_looping_infix()}) {
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
    std::vector res{t.init()};
    Bools::Expr last{t.init()};
    for (unsigned i = 0; i < trace.size(); ++i) {
        const auto s1{get_subs(i, 1)};
        last = last && step->renameVars(s1);
        Renaming s2;
        for (const auto& x : vars) {
            theory::apply(
                x,
                [&](const auto& x) {
                    using T = decltype(theory::theory(x));
                    if (x->isProgVar()) {
                        s2.insert(s1.get(x->postVar()), x);
                        s2.insert(x, T::next(x->dim()));
                    }
                });
        }
        res.push_back(last->renameVars(s2));
    }
    const auto sp_model{bools::mkOr(res)};
    return its2safety.transform_model(sp_model);
}
