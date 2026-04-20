#include "adclsat.hpp"

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

ADCLSat::ADCLSat(const ITSPtr& its, const Config::TRPConfig &config): TRPUtil(its, config) {
    std::unordered_map<Bools::Expr, Int> rev;
    for (const auto &[id,trans]: rule_map) {
        rev.emplace(trans, id);
    }
    for (const auto &[id,trans]: rule_map) {
        const auto preds {t.get_dg().getPredecessors(trans)};
        const auto succs {t.get_dg().getSuccessors(trans)};
        for (const auto &p: preds) {
            dg_over_approx.addEdge(rev.at(p), id);
        }
        for (const auto &s: succs) {
            dg_over_approx.addEdge(id, rev.at(s));
        }
        if (t.get_dg().getRoots().contains(trans)) {
            dg_over_approx.markRoot(id);
        }
        if (t.get_dg().getSinks().contains(trans)) {
            dg_over_approx.markSink(id);
        }
    }
}

std::optional<Range> ADCLSat::has_looping_infix() {
    for (unsigned i = 0; i < trace.size(); ++i) {
        for (unsigned start = 0; start + i < trace.size(); ++start) {
            if (dependency_graph.hasEdge(trace[start + i].implicant, trace[start].implicant) && (i > 0 || trace[start].id <= last_orig_clause)) {
                if (i == 0) {
                    if (const auto loop {trace[start].implicant}; SmtFactory::check(loop->renameVars(get_subs(0,1)) && loop->renameVars(get_subs(1,1))) == SmtResult::Unsat) {
                        continue;
                    }
                }
                return {Range::from_interval(start, start + i)};
            }
        }
    }
    return {};
}

void ADCLSat::add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) {
    const auto s{get_subs(range.start(), range.length())};
    auto &map{blocked_per_step.emplace(range.end(), std::map<Int, BoolExprSet>()).first->second};
    auto it{map.emplace(id, BoolExprSet()).first};
    if (range.length() == 1) {
        it->second.insert((!loop || bools::mkLit(arith::mkGeq(trace_var, arith::mkConst(id))))->renameVars(s));
    } else {
        it->second.insert(!loop->renameVars(s));
    }
}

void ADCLSat::handle_loop(const Range& range) {
    if (Config::Analysis::abstraction_refinement) {
        if (const auto backtrack_point = refine_partially(range)) {
            if (Config::Analysis::log) {
                std::cout << "refined loop" << std::endl;
            }
            while (trace.size() > *backtrack_point) {
                trace.pop_back();
                solver->pop();
            }
            backtracking = false;
            return;
        }
    }
    backtracking = true;
    auto [loop_non_bool, loop_bool, model]{specialize(range, theory::isTempCell)};
    solver->pop();
    if (add_blocking_clauses(range, model)) {
        if (Config::Analysis::log) {
            std::cout << "***** Covered *****" << std::endl;
        }
        trace.pop_back();
        return;
    }
    if (Config::Analysis::log) {
        std::cout << "***** Accelerate *****" << std::endl;
    }
    auto ti{trp.compute(loop_non_bool, loop_bool, model)};
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
        projected = mbp::int_mbp(ti, model, mbp_kind, [&](const auto &x) {
            return x == Cell(n);
        });
    }
    const auto fst_elem {trace.at(range.start())};
    const auto last_elem {trace.at(range.end())};
    const auto preds {dg_over_approx.getPredecessors(fst_elem.id)};
    const auto succs {dg_over_approx.getSuccessors(last_elem.id)};
    dg_over_approx.addNode(id, preds, succs, true);
    if (dg_over_approx.getRoots().contains(fst_elem.id)) {
        dg_over_approx.markRoot(id);
    }
    if (dg_over_approx.getSinks().contains(last_elem.id)) {
        dg_over_approx.markSink(id);
    }
    if (range.length() == 1) {
        add_projection(id, projected);
    }
    trace.pop_back();
    while (trace.size() > range.start()) {
        trace.pop_back();
        solver->pop();
    }
}

std::optional<SmtResult> ADCLSat::do_step() {
    if (Config::Analysis::log) {
        std::cout << "Trace:" << std::endl;
        for (const auto &e: trace) {
            std::cout << e.implicant << std::endl;
        }
    }
    const std::optional<Int> last =
        trace.empty()
            ? std::optional<Int>{}
            : std::optional{trace.back().id};
    if (!backtracking && (!last || dg_over_approx.getSinks().contains(*last))) {
        solver->push();
        solver->add(t.err()->renameVars(get_subs(trace.size(), 1)));
        switch (solver->check()) {
            case SmtResult::Sat:
            case SmtResult::Unknown:
                if (Config::Analysis::abstraction_refinement && !trace.empty()) {
                    if (Config::Analysis::log) {
                        std::cout << "proving safety failed, abstraction refinement" << std::endl;
                    }
                    if (const auto backtrack_point = refine_partially(Range::from_length(0, trace.size()))) {
                        solver->pop();
                        while (trace.size() > *backtrack_point) {
                            trace.pop_back();
                            solver->pop();
                        }
                        return std::nullopt;
                    }
                }
                if (Config::Analysis::log) {
                    std::cout << "proving safety failed, trying to construct counterexample" << std::endl;
                }
                if (build_cex()) {
                    return SmtResult::Unsat;
                }
                if (Config::Analysis::fail_early) {
                    return SmtResult::Unknown;
                }
                break;
            case SmtResult::Unsat:
                break;
        }
        solver->pop();
    }
    if (const auto range{has_looping_infix()}) {
        if (Config::Analysis::log) {
            std::cout << "found loop at [" << range->start() << ", " << range->end() << "]" << std::endl;
        }
        handle_loop(*range);
        return {};
    }
    const auto subs{get_subs(trace.size(), 1)};
    solver->push();
    add_blocking_clauses(trace.size());
    if (!trace.empty() && trace.back().id > last_orig_clause) {
        solver->add(arith::mkNeq(trace_var, arith::mkConst(trace.back().id))->renameVars(subs));
    }
    solver->push();
    const auto ids = last ? dg_over_approx.getSuccessors(*last) : dg_over_approx.getRoots();
    std::vector<Bools::Expr> steps;
    for (const auto& id: ids) {
        steps.emplace_back(encode_transition(rule_map.at(id), id));
    }
    const auto step {bools::mkOr(steps)};
    solver->add(step->renameVars(subs));
    switch (solver->check()) {
        case SmtResult::Unknown:
            return SmtResult::Unknown;
        case SmtResult::Unsat: {
            if (trace.empty()) {
                return safe ? SmtResult::Sat : SmtResult::Unknown;
            }
            backtracking = true;
            const auto projection{trace.back().implicant};
            solver->pop(); // current step
            solver->pop(); // blocking clauses
            solver->pop(); // backtracking
            trace.pop_back();
            const auto b {!projection->renameVars(get_subs(trace.size(), 1))};
            if (Config::Analysis::log) {
                std::cout << "***** Backtrack *****" << std::endl;
            }
            solver->add(b);
            return {};
        }
        case SmtResult::Sat:
            model = solver->model();
            solver->push();
            solver->add(arith::mkGt(trace_var, arith::mkConst(last_orig_clause)));
            if (solver->check() == SmtResult::Sat) {
                model = solver->model();
            }
            solver->pop();
            break;
    }
    backtracking = false;
    solver->pop();
    const auto id{(*model)->get(trace_var->renameVars(subs))};
    if (Config::Analysis::log) {
        std::cout << "***** Step *****" << std::endl;
        std::cout << "with " << id << std::endl;
    }
    const auto trans{rule_map.at(id)};
    const auto m{(*model)->composeBackwards(subs)};
    const auto [imp_non_bool, imp_bool] = m->structuralImplicant(trans);
    const auto imp = imp_non_bool && imp_bool;
    solver->add(imp->renameVars(subs));
    const auto smt_res{solver->check()};
    assert(smt_res == SmtResult::Sat);
    trace.emplace_back(id, imp);
    if (trace.size() > 1) {
        dependency_graph.addEdge(trace.at(trace.size() - 2).implicant, imp);
    }
    return {};
}

ITSModel ADCLSat::get_model() {
    // TODO
    throw std::logic_error("not yet implemented");
}
