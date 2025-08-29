#include "imc.hpp"
#include "config.hpp"
#include "smtfactory.hpp"
#include "opensmt.hpp"
#include "realqe.hpp"
#include "intmbp.hpp"

#include <stdexcept>

IMC::IMC(const ITSPtr its, const bool aimc, const Config::TRPConfig &config) : TRPUtil(its, SmtFactory::interpolatingSolver(), config), aimc(aimc) {
    std::vector<Bools::Expr> steps;
    for (const auto &[id,r]: rule_map) {
        steps.emplace_back(aimc ? encode_transition(r, id) : r);
    }
    step = bools::mkOr(steps);
}

void IMC::build_trace(unsigned depth) {
    trace.clear();
    model = solver->model();
    std::optional<std::pair<Bools::Expr, Int>> prev;
    for (unsigned d = 0; d < depth; ++d) {
        const auto s{get_subs(d, 1)};
        const auto id{model.eval<Arith>(s.get<Arith>(trace_var))};
        const auto rule{encode_transition(rule_map.at(id), id)};
        const auto comp{model.composeBackwards(s)};
        const auto imp{comp.syntacticImplicant(rule) && theory::mkEq(trace_var, arith::mkConst(id))};
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
        std::cout << "trace var: " << trace_var << std::endl;
        std::cout << "run:" << std::endl;
        for (const auto &t : trace) {
            std::cout << t.model << std::endl;
        }
    }
}

bool IMC::has_looping_infix(unsigned start, unsigned length) {
    const auto i {length - 1};
    if (dependency_graph.hasEdge(trace[start + i].implicant, trace[start].implicant) && (i > 0 || trace[start].id <= last_orig_clause)) {
        if (i == 0) {
            const auto loop{trp.mbp(trace[start].implicant, trace[start].model, theory::isTempVar)};
            if (SmtFactory::check(get_subs(0, 1)(loop) && get_subs(1, 1)(loop)) == SmtResult::Unsat) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool IMC::handle_loop(const Range &range) {
    auto [loop, model]{specialize(range, theory::isTempVar)};
    if (TRPUtil::add_blocking_clauses(range, model)) {
        return true;
    }
    auto ti{trp.compute(loop, model)};
    for (const auto &s: forgotten) {
        if (SmtFactory::check(s(ti)) != SmtResult::Unsat) {
            return false;
        }
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

void IMC::add_blocking_clauses() {
    const auto s1{get_subs(depth, 1)};
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

void IMC::add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) {
    const auto s{get_subs(range.start(), range.length())};
    auto &map{blocked_per_step.emplace(range.end(), std::map<Int, Bools::Expr>()).first->second};
    auto it{map.emplace(id, top()).first};
    if (range.length() == 1) {
        it->second = it->second && s(!loop || bools::mkLit(arith::mkGeq(trace_var, arith::mkConst(id))));
    } else {
        it->second = it->second && s(!loop);
    }
}

void IMC::forget(const Subs subs, const Int id) {
    forgotten.emplace_back(subs);
    rule_map.erase(id);
    for (auto &[_, m] : blocked_per_step) {
        m.erase(id);
    }
    for (auto it = projections.begin(); it != projections.end();) {
        if (it->first == id) {
            it = projections.erase(it);
        } else {
            ++it;
        }
    }
    const auto l{level.at(id)};
    level.erase(id);
    accel.erase(id);
    learned_to_loop.erase(id);
    while (depth > l) {
        solver->pop();
        --depth;
    }
    std::vector<Bools::Expr> steps;
    for (const auto &[id, r] : rule_map) {
        steps.emplace_back(encode_transition(r, id));
    }
    step = bools::mkOr(steps);
    if (Config::Analysis::log) {
        std::cout << "forgetting " << id << std::endl;
        std::cout << "backtracking to level " << l << std::endl;
    }
}

std::optional<SmtResult> IMC::do_step() {
    if (aimc && depth > 0) {
        auto res{solver->check()};
        if (res == SmtResult::Unsat) {
            if (Config::Analysis::log) {
                std::cout << "SAT BY TRL" << std::endl;
            }
            return SmtResult::Sat;
        } else if (res == SmtResult::Sat) {
            build_trace(depth);
            for (unsigned length = 1; length <= trace.size(); ++length) {
                for (unsigned start = 0; start + length < trace.size(); ++start) {
                    if (has_looping_infix(start, length)) {
                        Range range{Range::from_length(start, length)};
                        if (Config::Analysis::log) {
                            std::cout << "starting loop handling" << std::endl;
                        }
                        if (Config::Analysis::log) {
                            std::cout << "found loop: " << range.start() << " to " << range.end() << std::endl;
                        }
                        if (handle_loop(range)) {
                            while (depth > range.start()) {
                                solver->pop();
                                --depth;
                            }
                            if (Config::Analysis::log) {
                                std::cout << "done with loop handling" << std::endl;
                            }
                            return std::nullopt;
                        }
                    }
                }
            }
        }
    }
    if (Config::Analysis::log > 0) {
        std::cout << "[IMC] Checking with lookahead length " << depth << '\n';
    }
    const auto pre_subs {get_subs(depth, 1)};
    const auto pre_subs_inverted {pre_subs.invert()};
    const auto post_subs {get_subs(depth + 1, 1)};
    const auto post_subs_inverted {post_subs.invert()};
    const auto s {pre_subs(step)};
    BoolExprSet concl{s};
    auto movingErr{post_subs(t.err())};
    auto reached_states{movingErr};
    unsigned iter{0};
    while (!aimc || iter < depth) {
        if (Config::Analysis::log > 0) {
            std::cout << "[IMC] iter " << iter << '\n';
        }
        concl.emplace(movingErr);
        const auto res{solver->interpolate(concl)};
        concl.erase(movingErr);
        if (res) {
            itp = *res;
            itp = pre_subs_inverted(itp);
            itp = post_subs(itp);
            if (Config::Analysis::log) {
                std::cout << "interpolant: " << itp << std::endl;
            }
            // if R' => R return False(if R' /\ not R returns True)
            if (SmtFactory::check(itp && !reached_states) == SmtResult::Unsat) {
                if (Config::Analysis::log) {
                    std::cout << "SAT BY IMC" << std::endl;
                }
                return SmtResult::Sat;
            }
            movingErr = itp;
            reached_states = reached_states || itp;
            ++iter;
        } else {
            if (iter > 0) {
                break;
            }
            if (aimc) {
                // Real counterexample?
                build_trace(depth + 1);
                if (!build_cex()) {
                    for (const auto &e : trace) {
                        if (e.id > last_orig_clause) {
                            const auto acc{accel.at(e.id)};
                            const auto subs{e.model.toSubs()};
                            if (SmtFactory::check(subs(acc)) != SmtResult::Sat) {
                                forget(subs, e.id);
                                return std::nullopt;
                            }
                        }
                    }
                }
            }
            return SmtResult::Unsat;
        }
    }
    solver->push();
    solver->add(s);
    if (aimc) {
        add_blocking_clauses();
    }
    ++depth;
    return std::nullopt;
}

ITSModel IMC::get_model() {
    throw std::runtime_error("not yet implemented");
}

ITSSafetyCex IMC::get_cex() {
    throw std::runtime_error("not yet implemented");
}
