#include "adclsat.hpp"

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

ADCLSat::ADCLSat(const ITSPtr its, const Config::TRPConfig &config): TRPUtil(its, config) {}

std::optional<unsigned> ADCLSat::has_looping_suffix() {
    const auto last {trace.size() - 1};
    for (unsigned start = last; start + 1 > 0; --start) {
        if (dependency_graph.hasEdge(trace.back().implicant, trace[start].implicant) && (start < last || trace[start].id <= last_orig_clause)) {
            if (Config::Analysis::termination() &&
                start < last &&
                model.get<Arith>(get_subs(start, 1).get<Arith>(safety_var)) >= 0 &&
                model.get<Arith>(get_subs(last, 1).get<Arith>(safety_var)) < 0) {
                continue;
            }
            if (start == last) {
                const auto loop{trace[start].implicant};
                if (SmtFactory::check(get_subs(0, 1)(loop) && get_subs(1, 1)(loop)) == SmtResult::Unsat) {
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
    if (Config::Analysis::termination()) {
        std::vector<Bools::Expr> disjuncts;
        disjuncts.emplace_back(s(!loop));
        if (range.length() == 1) {
            disjuncts.emplace_back(bools::mkLit(arith::mkGeq(s.get<Arith>(trace_var), arith::mkConst(id))));
        }
        const auto safety_loop {this->model.get<Arith>(get_subs(range.start(), 1).get<Arith>(safety_var)) >= 0};
        if (safety_loop) {
            const auto last_s {get_subs(range.end(), 1)};
            const auto no_safety_loop{bools::mkLit(arith::mkLt(last_s.get<Arith>(safety_var), arith::mkConst(0)))};
            disjuncts.emplace_back(no_safety_loop);
        } else {
            const auto first_s {get_subs(range.start(), 1)};
            const auto no_term_loop{bools::mkLit(arith::mkGeq(first_s.get<Arith>(safety_var), arith::mkConst(0)))};
            disjuncts.emplace_back(no_term_loop);
        }
        solver->add(bools::mkOr(disjuncts));
    } else if (range.length() == 1) {
        solver->add(s(!loop || bools::mkLit(arith::mkGeq(trace_var, arith::mkConst(id)))));
    } else {
        solver->add(s(!loop));
    }
}

bool ADCLSat::handle_loop(const unsigned start) {
    const auto range {Range::from_interval(start, trace.size() - 1)};
    auto [loop, model]{specialize(range, theory::isTempVar)};
    Bools::Expr termination_argument {top()};
    if (Config::Analysis::termination()) {
        if (const auto rf {prove_term(loop, model)}) {
            termination_argument = bools::mkAndFromLits({arith::mkGt(*rf, arith::mkConst(0)), arith::mkGt((*rf)->renameVars(post_to_pre.get<Arith>()), (*rf)->renameVars(t.pre_to_post().get<Arith>()))});
            loop = loop && termination_argument;
        } else {
            return false;
        }
    }
    solver->pop();
    if (TRPUtil::add_blocking_clauses(range, model)) {
        if (Config::Analysis::log) {
            std::cout << "***** Covered *****" << std::endl;
        }
        trace.pop_back();
        return true;
    }
    if (Config::Analysis::log) {
        std::cout << "***** Accelerate *****" << std::endl;
    }
    auto ti{trp.compute(loop, model)};
    if (Config::Analysis::termination()) {
        ti = ti && termination_argument;
    }
    Int id;
    Bools::Expr projected{top()};
    const auto n {trp.get_n()};
    if (mbp_kind == Config::TRPConfig::RealQe) {
        projected = qe::real_qe(ti, model, [&](const auto &x) {
            return x == Var(n);
        });
        projected = Preprocess::preprocessFormula(projected, theory::isTempVar);
        id = add_learned_clause(range, projected);
    } else {
        ti = Preprocess::preprocessFormula(ti, theory::isTempVar);
        id = add_learned_clause(range, ti);
        model.put<Arith>(n, 1);
        projected = mbp::int_mbp(ti, model, [&](const auto &x) {
            return x == Var(n);
        });
    }
    if (range.length() == 1) {
        projections.emplace_back(id, projected);
    } else {
        add_blocking_clause(range, id, ti);
    }
    trace.pop_back();
    return true;
}

std::optional<SmtResult> ADCLSat::do_step() {
    if (Config::Analysis::log) {
        std::cout << "Trace:" << std::endl;
        for (const auto &e: trace) {
            std::cout << e.implicant << std::endl;
        }
    }
    if (!backtracking) {
        solver->push();
        solver->add(get_subs(trace.size(), 1)(t.err()));
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
        if (!handle_loop(*start)) {
            return SmtResult::Unknown;
        } else {
            return {};
        }
    }
    const auto subs{get_subs(trace.size(), 1)};
    solver->push();
    solver->add(subs(step));
    if (!trace.empty() && trace.back().id > last_orig_clause) {
        solver->add(subs(theory::mkNeq(theory::toExpr(trace_var), arith::mkConst(trace.back().id))));
    }
    if (Config::Analysis::termination() && !trace.empty()) {
        solver->add(bools::mkLit(arith::mkGeq(get_subs(trace.size() - 1, 1).get<Arith>(safety_var), subs.get<Arith>(safety_var))));
    }
    for (const auto &[id, b] : projections) {
        solver->add(subs(!b) || bools::mkLit(arith::mkGeq(subs.get<Arith>(trace_var), arith::mkConst(id))));
    }
    switch (solver->check()) {
        case SmtResult::Unknown:
            return SmtResult::Unknown;
        case SmtResult::Unsat: {
            if (trace.empty()) {
                return safe ? SmtResult::Sat : SmtResult::Unsat;
            }
            backtracking = true;
            const auto projection{trp.mbp(trace.back().implicant, trace.back().model, theory::isTempVar)};
            solver->pop(); // current step
            solver->pop(); // backtracking
            trace.pop_back();
            const auto b {!get_subs(trace.size(), 1)(projection)};
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
    const auto id{model.get<Arith>(subs.get<Arith>(trace_var))};
    if (Config::Analysis::log) {
        std::cout << "***** Step *****" << std::endl;
        std::cout << "with " << id << std::endl;
    }
    const auto trans{rule_map.left.at(id)};
    const auto m{model.composeBackwards(subs)};
    const auto imp{m.syntacticImplicant(trans)};
    solver->push();
    solver->add(subs(imp));
    const auto smt_res{solver->check()};
    assert(smt_res == SmtResult::Sat);
    trace.emplace_back(id, imp, m);
    if (trace.size() > 1) {
        dependency_graph.addEdge(trace.at(trace.size() - 2).implicant, imp);
    }
    return {};
}
