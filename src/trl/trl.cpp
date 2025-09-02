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

TRL::TRL(const ITSPtr its, const Config::TRPConfig &config) : TRPUtil(its, config) {
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
                model.get<Arith>(get_subs(start, 1).get<Arith>(safety_var)) >= 0 &&
                model.get<Arith>(get_subs(start + i, 1).get<Arith>(safety_var)) < 0) {
                continue;
            }
            if (dependency_graph.hasEdge(trace[start + i].implicant, trace[start].implicant) && (i > 0 || trace[start].id <= last_orig_clause)) {
                if (i == 0) {
                    const auto loop {trp.mbp(trace[start].implicant, trace[start].model, theory::isTempVar)};
                    if (SmtFactory::check(get_subs(0,1)(loop) && get_subs(1,1)(loop)) == SmtResult::Unsat) {
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
            termination_argument = bools::mkAndFromLits({arith::mkGt(*rf, arith::mkConst(0)), arith::mkGt((*rf)->renameVars(post_to_pre.get<Arith>()), (*rf)->renameVars(t.pre_to_post().get<Arith>()))});
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
        projected = qe::real_qe(ti, model, [&](const auto &x) {
            return x == Var(n);
        });
        projected = Preprocess::preprocessFormula(projected, theory::isTempVar);
        ti = projected;
        id = add_learned_clause(range, ti);
    } else {
        ti = Preprocess::preprocessFormula(ti, theory::isTempVar);
        id = add_learned_clause(range, ti);
        model.put<Arith>(n, 1);
        projected = mbp::int_mbp(ti, model, mbp_kind, [&](const auto &x) {
            return x == Var(n);
        });
    }
    step = step || encode_transition(ti, id);
    if (range.length() == 1) {
        projections.emplace_back(id, projected);
    } else {
        add_blocking_clause(range, id, projected);
    }
    return true;
}

void TRL::add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) {
    const auto s{get_subs(range.start(), range.length())};
    auto &map{blocked_per_step.emplace(range.end(), std::map<Int, Bools::Expr>()).first->second};
    auto it{map.emplace(id, top()).first};
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
        it->second = it->second && bools::mkOr(disjuncts);
    } else if (range.length() == 1) {
        it->second = it->second && s(!loop || bools::mkLit(arith::mkGeq(trace_var, arith::mkConst(id))));
    } else {
        it->second = it->second && s(!loop);
    }
}

void TRL::add_blocking_clauses() {
    const auto s1{get_subs(depth, 1)};
    const auto s2{get_subs(depth + 1, 1)};
    for (const auto &[id, b] : projections) {
        solver->add(s1(!b) || bools::mkLit(arith::mkGeq(s1.get<Arith>(trace_var), arith::mkConst(id))));
    }
    const auto it{blocked_per_step.find(depth)};
    if (it != blocked_per_step.end()) {
        for (const auto &[_, b] : it->second) {
            solver->add(b);
        }
    }
}

std::optional<Bools::Expr> TRL::inductive_subset() {
    LitSet max_ind;
    auto solver {SmtFactory::solver(QF_LA)};
    solver->add(step);
    bool changed;
    const auto lits {post_to_pre(current_projection.back())->lits()};
    do {
        changed = false;
        for (const auto &l : lits) {
            if (max_ind.contains(l)) continue;
            solver->push();
            solver->add(bools::mkLit(l));
            solver->push();
            solver->add(!t.pre_to_post()(bools::mkLit(l)));
            if (solver->check() == SmtResult::Unsat) {
                max_ind.insert(l);
                changed = true;
            } else {
                solver->pop();
            }
            solver->pop();
        }
    } while (changed);
    solver = SmtFactory::solver(QF_LA);
    solver->add(t.err());
    solver->push();
    solver->add(bools::mkAndFromLits(max_ind));
    if (solver->check() == SmtResult::Unsat) {
        solver->pop();
        LitSet min_safe {max_ind};
        LitSet removed;
        for (const auto &lit : max_ind) {
            min_safe.erase(lit);
            solver->push();
            solver->add(bools::mkAndFromLits(min_safe));
            if (solver->check() != SmtResult::Unsat) {
                min_safe.insert(lit);
            } else {
                removed.insert(lit);
            }
            solver->pop();
        }
        LitSet safe_ind {max_ind};
        auto solver {SmtFactory::solver(QF_LA)};
        solver->add(step);
        for (const auto &l: removed) {
            safe_ind.erase(l);
            solver->push();
            solver->add(bools::mkAndFromLits(safe_ind));
            solver->add(t.pre_to_post()(!bools::mkAndFromLits(safe_ind)));
            if (solver->check() != SmtResult::Unsat) {
                safe_ind.insert(l);
            }
            solver->pop();
        }
        return bools::mkAndFromLits(safe_ind);
    }
    return std::nullopt;
}

void TRL::build_trace() {
    std::optional<std::pair<Bools::Expr, Int>> prev;
    trace.clear();
    for (unsigned d = 0; d < depth; ++d) {
        const auto s{get_subs(d, 1)};
        const auto id{model.eval<Arith>(s.get<Arith>(trace_var))};
        const auto rule{encode_transition(rule_map.at(id), id)};
        const auto comp{model.composeBackwards(s)};
        auto imp{comp.syntacticImplicant(rule)};
        if (current_projection.size() == d) {
            Bools::Expr proj {top()};
            if (d == 0) {
                proj = model.syntacticImplicant(t.init()) && imp;
            } else {
                proj = current_projection.back() && imp;
            }
            proj = post_to_pre(mbp::int_mbp(proj, comp, mbp_kind, [](const auto x) {
                return !theory::isPostVar(x);
            }));
            current_projection.push_back(proj);
        }
        imp = imp && theory::mkEq(trace_var, arith::mkConst(id));
        auto relevant_vars{vars};
        for (const auto &x : vars) {
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
        std::cout << "projections:" << std::endl;
        for (const auto &t : current_projection) {
            std::cout << t << std::endl;
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
    current_projection.pop_back();
}

std::optional<SmtResult> TRL::do_step() {
    auto s{get_subs(depth, 1)};
    // push error states
    solver->push();
    solver->add(s(t.err()));
    switch (solver->check()) {
        case SmtResult::Unknown:
            return SmtResult::Unknown;
        case SmtResult::Sat:
            model = solver->model();
            current_projection.clear();
            if (Config::Analysis::log) {
                std::cout << "proving safety failed, trying to construct counterexample" << std::endl;
            }
            build_trace();
            return build_cex() ? SmtResult::Unsat : SmtResult::Unknown;
        case SmtResult::Unsat: {
            // pop error states
            solver->pop();
            solver->push();
            solver->add(s(step) && get_subs(depth + 1, 1)(unsafe));
            if (Config::Analysis::termination() && depth > 0) {
                solver->add(bools::mkLit(arith::mkGeq(get_subs(depth - 1, 1).get<Arith>(safety_var), s.get<Arith>(safety_var))));
            }
            add_blocking_clauses();
            SmtResult smt_res {SmtResult::Unknown};
            while (!current_projection.empty()) {
                solver->push();
                solver->add(get_subs(current_projection.size(), 1)(current_projection.back()));
                smt_res = solver->check();
                if (smt_res == SmtResult::Sat) {
                    model = solver->model();
                    solver->pop();
                    break;
                }
                solver->pop();
                current_projection.pop_back();
            }
            if (smt_res != SmtResult::Sat) {
                smt_res = solver->check();
                if (smt_res == SmtResult::Sat) {
                    model = solver->model();
                }
            }
            switch (smt_res) {
                case SmtResult::Unsat:
                    return SmtResult::Sat;
                case SmtResult::Unknown:
                    std::cerr << "unknown from SMT solver" << std::endl;
                    return SmtResult::Unknown;
                case SmtResult::Sat: {
                    ++depth;
                    build_trace();
                    if (const auto inductive {inductive_subset()}) {
                        unsafe = unsafe && !*inductive;
                        pop();
                        return std::nullopt;
                    }
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
    return {};
}

ITSModel TRL::get_model() {
    std::vector<Bools::Expr> res{t.init()};
    Bools::Expr last{t.init()};
    for (unsigned i = 0; i < trace.size(); ++i) {
        const auto s1{get_subs(i, 1)};
        last = last && s1(step);
        Renaming s2;
        for (const auto &x : vars) {
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
