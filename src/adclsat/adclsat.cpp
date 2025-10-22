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
    linked_hash_map<Bools::Expr, Bools::Expr> map;
    for (const auto &[id,trans]: rule_map) {
        const auto encoded {encode_transition(trans, id)};
        map.emplace(trans, encoded);
        const auto preds {t.get_dg().getPredecessors(trans)};
        const auto succs {t.get_dg().getSuccessors(trans)};
        for (const auto &p: preds) {
            if (map.contains(p)) {
                dg_over_approx.addEdge(map.at(p), encoded);
            }
        }
        for (const auto &s: succs) {
            if (map.contains(s)) {
                dg_over_approx.addEdge(encoded, map.at(s));
            }
        }
        if (t.get_dg().getRoots().contains(trans)) {
            std::cout << "found root" << std::endl;
            dg_over_approx.markRoot(encoded);
        }
        if (t.get_dg().getSinks().contains(trans)) {
            dg_over_approx.markSink(encoded);
        }
    }
}

std::optional<unsigned> ADCLSat::has_looping_suffix() {
    const auto last {trace.size() - 1};
    for (unsigned start = last; start + 1 > 0; --start) {
        if (dependency_graph.hasEdge(trace.back().implicant, trace[start].implicant) && (start < last || trace[start].id <= last_orig_clause)) {
            if (start == last) {
                if (const auto loop{trace[start].implicant};
                    SmtFactory::check(loop->renameVars(get_subs(0, 1)) && loop->renameVars(get_subs(1, 1))) == SmtResult::Unsat) {
                    continue;
                }
            }
            return start;
        }
    }
    return {};
}

void ADCLSat::add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) {
    const auto s{get_subs(range.start(), range.length())};
    if (range.length() == 1) {
        solver->add((!loop || bools::mkLit(arith::mkGeq(trace_var, arith::mkConst(id))))->renameVars(s));
    } else {
        solver->add(!loop->renameVars(s));
    }
}

void ADCLSat::handle_loop(const unsigned start) {
    const auto range {Range::from_interval(start, trace.size() - 1)};
    auto [loop, model]{specialize(range, theory::isTempCell)};
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
    auto ti{trp.compute(loop, model)};
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
    const auto fst_elem {trace.at(start)};
    const auto last_elem {trace.back()};
    const auto fst {encode_transition(rule_map.at(fst_elem.id), fst_elem.id)};
    const auto last {encode_transition(rule_map.at(last_elem.id), last_elem.id)};
    const auto preds {dg_over_approx.getPredecessors(fst)};
    const auto succs {dg_over_approx.getSuccessors(last)};
    const auto node {encode_transition(ti, id)};
    dg_over_approx.addNode(node, preds, succs, true);
    if (dg_over_approx.getRoots().contains(fst)) {
        dg_over_approx.markRoot(node);
    }
    if (dg_over_approx.getSinks().contains(last)) {
        dg_over_approx.markSink(node);
    }
    if (range.length() == 1) {
        projections.emplace_back(id, projected);
    } else {
        add_blocking_clause(range, id, projected);
    }
    trace.pop_back();
}

std::optional<SmtResult> ADCLSat::do_step() {
    if (Config::Analysis::log) {
        std::cout << "Trace:" << std::endl;
        for (const auto &e: trace) {
            std::cout << e.implicant << std::endl;
        }
    }
    const std::optional<Bools::Expr> last =
        trace.empty()
            ? std::optional<Bools::Expr>{}
            : std::optional{encode_transition(rule_map.at(trace.back().id), trace.back().id)};
    if (!backtracking && (!last || dg_over_approx.getSinks().contains(*last))) {
        solver->push();
        solver->add(t.err()->renameVars(get_subs(trace.size(), 1)));
        switch (solver->check()) {
            case SmtResult::Sat:
            case SmtResult::Unknown:
                if (Config::Analysis::log) {
                    std::cout << "proving safety failed, trying to construct counterexample" << std::endl;
                }
                if (build_cex()) {
                    return SmtResult::Unsat;
                }
                break;
            case SmtResult::Unsat:
                break;
        }
        solver->pop();
    }
    if (const auto start{has_looping_suffix()}) {
        if (Config::Analysis::log) {
            std::cout << "found loop starting at " << start << std::endl;
        }
        backtracking = true;
        handle_loop(*start);
        return {};
    }
    const auto subs{get_subs(trace.size(), 1)};
    solver->push();
    const auto steps = last ? dg_over_approx.getSuccessors(*last) : dg_over_approx.getRoots();
    const auto step {bools::mkOr(steps)};
    solver->add(step->renameVars(subs));
    if (!trace.empty() && trace.back().id > last_orig_clause) {
        solver->add(theory::mkNeq(trace_var, arith::mkConst(trace.back().id))->renameVars(subs));
    }
    for (const auto &[id, b] : projections) {
        solver->add(!b->renameVars(subs) || bools::mkLit(arith::mkGeq(trace_var->renameVars(subs), arith::mkConst(id))));
    }
    switch (solver->check()) {
        case SmtResult::Unknown:
            return SmtResult::Unknown;
        case SmtResult::Unsat: {
            if (trace.empty()) {
                return safe ? SmtResult::Sat : SmtResult::Unknown;
            }
            backtracking = true;
            const auto projection{trp.mbp(trace.back().implicant, trace.back().model, theory::isTempCell)};
            solver->pop(); // current step
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
            break;
    }
    backtracking = false;
    model = solver->model();
    solver->pop();
    const auto id{(*model)->get(trace_var->renameVars(subs))};
    if (Config::Analysis::log) {
        std::cout << "***** Step *****" << std::endl;
        std::cout << "with " << id << std::endl;
    }
    const auto trans{rule_map.at(id)};
    const auto m{(*model)->composeBackwards(subs)};
    const auto imp{m->syntacticImplicant(trans)};
    solver->push();
    solver->add(imp->renameVars(subs));
    const auto smt_res{solver->check()};
    assert(smt_res == SmtResult::Sat);
    trace.emplace_back(id, imp, m);
    if (trace.size() > 1) {
        dependency_graph.addEdge(trace.at(trace.size() - 2).implicant, imp);
    }
    return {};
}

ITSModel ADCLSat::get_model() {
    // TODO
    throw std::logic_error("not yet implemented");
}
