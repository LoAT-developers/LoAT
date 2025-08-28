#include "imc.hpp"
#include "config.hpp"
#include "smtfactory.hpp"
#include "opensmt.hpp"
#include "realqe.hpp"
#include "intmbp.hpp"

#include <stdexcept>

void IMC::add(const Bools::Expr e) {
    solver.add(e);
    ++assertions;
}

IMC::IMC(const ITSPtr its, const Config::TRPConfig &config) : TRPUtil(its, config) {
    std::vector<Bools::Expr> steps;
    for (const auto &[id,r]: rule_map) {
        steps.emplace_back(encode_transition(r, id));
    }
    step = bools::mkOr(steps);
    add(t.init());
}

void IMC::build_trace() {
    trace.clear();
    model = solver.model();
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

std::optional<Range> IMC::has_looping_infix() {
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

bool IMC::handle_loop(const Range &range) {
    auto [loop, model]{specialize(range, theory::isTempVar)};
    if (TRPUtil::add_blocking_clauses(range, model)) {
        return true;
    }
    auto ti{trp.compute(loop, model)};

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
    const auto s1{get_subs(depth - 1, 1)};
    const auto s2{get_subs(depth, 1)};
    for (const auto &[id, b] : projections) {
        add(s1(!b) || bools::mkLit(arith::mkGeq(s1.get<Arith>(trace_var), arith::mkConst(id))));
    }
    const auto it{blocked_per_step.find(depth)};
    if (it != blocked_per_step.end()) {
        for (const auto &[_, b] : it->second) {
            add(b);
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

std::optional<SmtResult> IMC::do_step() {
    if (depth > 0) {
        add_blocking_clauses();
        auto res{solver.check()};
        if (res == SmtResult::Unsat) {
            if (Config::Analysis::log) {
                std::cout << "SAT BY TRL" << std::endl;
            }
            return SmtResult::Sat;
        } else if (res == SmtResult::Sat) {
            build_trace();
            const auto range{has_looping_infix()};
            if (range) {
                if (Config::Analysis::log) {
                    std::cout << "starting loop handling" << std::endl;
                }
                if (Config::Analysis::log) {
                    std::cout << "found loop: " << range->start() << " to " << range->end() << std::endl;
                }
                if (!handle_loop(*range)) {
                    return SmtResult::Unknown;
                }
                while (depth > range->start()) {
                    solver.pop();
                    --depth;
                }
                if (Config::Analysis::log) {
                    std::cout << "done with loop handling" << std::endl;
                }
                return std::nullopt;
            }
        }
    }
    ++depth;
    if (Config::Analysis::log > 0) {
        std::cout << "[IMC] Checking with lookahead length " << depth << '\n';
    }
    const auto pre_subs {get_subs(depth - 1, 1)};
    const auto pre_subs_inverted {pre_subs.invert()};
    const auto post_subs {get_subs(depth, 1)};
    const auto post_subs_inverted {post_subs.invert()};
    solver.push();
    add(pre_subs(step));
    opensmt::ipartitions_t mask {0};
    opensmt::setbit(mask, assertions - 1);
    auto movingErr{post_subs(t.err())};
    auto reached_states {movingErr};
    unsigned iter {0};
    while (iter < depth) {
        solver.push();
        add(movingErr);
        const auto res {solver.check()};
        if (res == SmtResult::Unsat) {
            opensmt::setbit(mask, assertions - 1);
            itp = solver.interpolate(mask);
            opensmt::clrbit(mask, assertions - 1);
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
            solver.pop(); // moving err
            ++iter;
        } else if (res == SmtResult::Sat) {
            if (iter > 0) {
                solver.pop(); // moving err
                return std::nullopt;
            } else {
                // Real counterexample
                return SmtResult::Unknown;
            }
        } else {
            return SmtResult::Unknown;
        }
    }
    return std::nullopt;
}

ITSModel IMC::get_model() {
    throw std::runtime_error("not yet implemented");
}

ITSSafetyCex IMC::get_cex() {
    throw std::runtime_error("not yet implemented");
}
