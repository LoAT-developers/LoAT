#include "trl.hpp"

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

TRL::LoopStatus TRL::handle_loop(const Range &range) {
    auto [loop_non_bool, loop_bool, model]{specialize(range, theory::isTempCell)};
    const auto kind = trp.get_loop_kind(loop_non_bool, loop_bool);
    if (kind == TRP::NoLoop) {
        return LoopStatus::NoLoop;
    }
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
            return LoopStatus::Failure;
        }
    }
    if (TRPUtil::add_blocking_clauses(range, model)) {
        return LoopStatus::Success;
    }
    auto ti = kind == TRP::Transitive ? loop : trp.compute(loop_non_bool, loop_bool, model);
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
        projected = rule_map.at(id)->subs(Subs::build(trp.get_n(), arith::one()));
    }
    step = step || encode_transition(rule_map.at(id), id);
    add_projection(id, projected);
    if (range.length() > 1) {
        add_blocking_clause(range, id, projected);
    }
    return LoopStatus::Success;
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
            build_trace();
            if (Config::Analysis::log) {
                std::cout << "proving safety failed, trying to construct counterexample" << std::endl;
            }
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
                    unsigned next_start = 0;
                    unsigned next_length = 1;
                    while (const auto range{has_looping_infix(next_start, next_length)}) {
                        if (Config::Analysis::log) {
                            std::cout << "found loop: " << range->start() << " to " << range->end() << std::endl;
                        }
                        switch (handle_loop(*range)) {
                            case LoopStatus::Failure: return SmtResult::Unknown;
                            case LoopStatus::NoLoop: {
                                next_start = range->start() + 1;
                                next_length = range->length();
                                break;
                            }
                            case LoopStatus::Success: {
                                while (depth > range->start()) {
                                    pop();
                                    trace.pop_back();
                                }
                            }
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
