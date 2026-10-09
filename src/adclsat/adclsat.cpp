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
    // for the first set of blocking clauses
    solver->push();
}

bool ADCLSat::handle_loop(const Range& range) {
    backtracking = true;
    const auto subs = get_subs(range.start(), range.length());
    auto model = (*this->model)->composeBackwards(subs);
    if (const auto id = add_blocking_clauses(range, model)) {
        if (Config::Analysis::log) {
            std::cout << "***** Covered *****" << std::endl;
            std::cout << "by " << *id << std::endl;
        }
        while (trace.size() > range.end()) {
            trace.pop_back();
            solver->pop();
        }
        return true;
    }
    if (Config::Analysis::abstraction_refinement) {
        if (refine_abstraction(range)) {
            if (Config::Analysis::log) {
                std::cout << "***** Refinement *****" << std::endl;
            }
            while (!trace.empty()) {
                trace.pop_back();
                solver->pop();
            }
            // also remove the first set of blocking clauses
            solver->pop();
            solver->push();
            return true;
        }
        model = (*this->model)->composeBackwards(subs);
        if (add_blocking_clauses(range, model)) {
            if (Config::Analysis::log) {
                std::cout << "***** Covered *****" << std::endl;
            }
            while (trace.size() > range.end()) {
                trace.pop_back();
                solver->pop();
            }
            return true;
        }
    }
    auto [loop_non_bool, loop_bool, _]{specialize(range, theory::isTempCell)};
    const auto kind = trp.get_loop_kind(loop_non_bool, loop_bool);
    if (kind == TRP::NoLoop) {
        return false;
    }
    const auto loop = loop_non_bool && loop_bool;
    if (Config::Analysis::log) {
        std::cout << "***** Accelerate *****" << std::endl;
    }
    auto ti = top();
    // With abstraction refinement, we have to apply tp even to transitive loops.
    // In this way, we obtain a set of literals such that every subset is transitive.
    if (kind == TRP::Transitive && !Config::Analysis::abstraction_refinement) {
        ti = loop;
    } else {
        ti = trp.compute(loop_non_bool, loop_bool, model);
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
    add_projection(id, projected);
    while (trace.size() > range.start()) {
        trace.pop_back();
        solver->pop();
    }
    return true;
}

std::optional<SmtResult> ADCLSat::do_step() {
    if (Config::Analysis::log) {
        std::cout << "Trace:" << std::endl;
        for (const auto &e: trace) {
            std::cout << e.id << ": " << e.implicant << std::endl;
        }
    }
    const std::optional<Int> last =
        trace.empty()
            ? std::optional<Int>{}
            : std::optional{trace.back().id};
    if (!backtracking) {
        solver->push();
        solver->add(t.err()->renameVars(get_subs(trace.size(), 1)));
        switch (solver->check()) {
            case SmtResult::Unknown:
                return SmtResult::Unknown;
            case SmtResult::Sat:
                if (Config::Analysis::abstraction_refinement && !trace.empty()) {
                    model = solver->model();
                    if (Config::Analysis::log) {
                        std::cout << "proving safety failed, abstraction refinement" << std::endl;
                    }
                    if (refine_abstraction(Range::from_length(0, trace.size()))) {
                        solver->pop();
                        while (!trace.empty()) {
                            trace.pop_back();
                            solver->pop();
                        }
                        // also remove the first set of blocking clauses
                        solver->pop();
                        solver->push();
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
    unsigned next_start = 0;
    unsigned next_length = 1;
    while (const auto range{has_looping_infix(next_start, next_length)}) {
        if (Config::Analysis::log) {
            std::cout << "found loop at [" << range->start() << ", " << range->end() << "]" << std::endl;
        }
        if (handle_loop(*range)) {
            return {};
        }
        next_start = range->start() + 1;
        next_length = range->length();
    }
    std::vector<Bools::Expr> steps, without_id;
    for (const auto& [id, transition]: rule_map) {
        steps.emplace_back(encode_transition(transition, id));
        without_id.emplace_back(transition);
    }
    const auto step {bools::mkOr(steps)};
    const auto subs{get_subs(trace.size(), 1)};
    solver->push(); // push blocking clauses
    add_blocking_clauses(trace.size());
    if (!trace.empty() && trace.back().id < 0) {
        solver->add(arith::mkNeq(trace_var, arith::mkConst(trace.back().id))->renameVars(subs));
    }
    solver->push(); // push step
    solver->add(step->renameVars(subs));
    switch (solver->check()) {
        case SmtResult::Unknown:
            return SmtResult::Unknown;
        case SmtResult::Unsat: {
            const auto all = bools::mkOr(t.trans());
            solver->pop(); // pop step
            solver->push(); // push concretization
            solver->add(all->renameVars(subs));
            const auto abstraction = bools::mkOr(without_id);
            solver->add(!abstraction->renameVars(subs));
            if (solver->check() == SmtResult::Sat) {
                const auto model = solver->model()->composeBackwards(subs);
                solver->pop(); // pop concretization
                solver->pop(); // pop blocking clauses
                const auto [imp_non_bool, imp_bool] = model->structuralImplicant(all);
                const auto transition = trp.mbp(imp_non_bool && imp_bool, model, theory::isTempCell);
                const auto id = next_id;
                ++next_id;
                concretization.emplace(id, transition);
                BoolExprSet lits;
                assert(transition->isAnd());
                for (const auto &c: transition->getChildren()) {
                    const auto vars = c->vars();
                    if (vars.contains(trace_var->var()) || vars.contains(its->getLocVar()->var()) || vars.contains(its->getLocVar()->var()->postVar())) {
                        lits.emplace(c);
                    }
                }
                rule_map.emplace(id, bools::mkAnd(lits));
                if (Config::Analysis::log) {
                    std::cout << "***** Sample *****" << std::endl;
                    std::cout << transition << std::endl;
                }
                return {};
            }
            if (trace.empty()) {
                return safe ? SmtResult::Sat : SmtResult::Unknown;
            }
            backtracking = true;
            const auto projection = trace.back().implicant;
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
            solver->add(arith::mkGeq(trace_var, arith::zero()));
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
    const auto imp = trp.mbp(imp_non_bool && imp_bool, m, theory::isTempCell);
    solver->add(encode_transition(imp, id)->renameVars(subs));
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
