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

ADCLSat::ADCLSat(
    const ITSPtr its,
    const Config::TRPConfig &config) : TRPUtil(its, SmtFactory::solver(QF_LA), config),
                                       pre_to_post(t.pre_to_post()),
                                       post_to_pre(pre_to_post.invert()) {
    linked_hash_map<Bools::Expr, Bools::Expr> map;
    std::vector<Bools::Expr> steps;
    for (const auto &[id, trans] : rule_map) {
        steps.emplace_back(trans);
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
            dg_over_approx.markRoot(encoded);
        }
        if (t.get_dg().getSinks().contains(trans)) {
            dg_over_approx.markSink(encoded);
        }
    }
    step = bools::mkOr(steps);
}

bool ADCLSat::handle_loop(const Range range) {
    auto [loop, model]{specialize(range, theory::isTempVar)};
    if (TRPUtil::add_blocking_clauses(range, model)) {
        if (Config::Analysis::log) {
            std::cout << "***** Covered *****" << std::endl;
        }
        while (depth > range.end()) {
            --depth;
            trace.pop_back();
            solver->pop();
        }
        return true;
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
    const auto fst_elem {trace.at(range.start())};
    const auto last_elem {trace.at(range.end())};
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
    while (depth > range.end()) {
        --depth;
        trace.pop_back();
        solver->pop();
    }
    return true;
}

std::optional<SmtResult> ADCLSat::do_step() {
    if (Config::Analysis::log) {
        std::cout << "Trace:" << std::endl;
        for (const auto &e: trace) {
            std::cout << e.implicant << std::endl;
        }
    }
    std::optional<Bools::Expr> last =
        trace.empty()
            ? std::optional<Bools::Expr>{}
            : std::optional{encode_transition(rule_map.at(trace.back().id), trace.back().id)};
    if (!backtracking && (!last || dg_over_approx.getSinks().contains(*last))) {
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
    if (const auto range{has_looping_infix()}) {
        if (Config::Analysis::log) {
            std::cout << "found loop: [" << range->start() << "," << range->end() << "]" << std::endl;
        }
        backtracking = true;
        if (!handle_loop(*range)) {
            return SmtResult::Unknown;
        } else {
            return {};
        }
    }
    const auto subs{get_subs(trace.size(), 1)};
    // if (!trace.empty()) {
        // const auto projection = trace.back().projection;
        // auto isolver{SmtFactory::interpolatingSolver()};
        // isolver->add(projection);
        // auto reached{pre_to_post(t.err())};
        // auto err{step && reached};
        // for (unsigned i = 0; i < trace.size(); ++i) {
        //     const auto opt{isolver->interpolate({err})};
        //     if (!opt) {
        //         break;
        //     }
        //     const auto itp {pre_to_post(*opt)};
        //     std::cout << "interpolant: " << itp << std::endl;
        //     std::cout << "err: " << err << std::endl;
        //     std::cout << "reached: " << reached << std::endl;
        //     if (SmtFactory::check(itp && !reached) == SmtResult::Unsat) {
        //         std::cout << "interpolant is inductive!" << std::endl;
        //         backtracking = true;
        //         solver->pop(); // backtracking
        //         trace.pop_back();
        //         const auto b{!subs(projection)};
        //         if (Config::Analysis::log) {
        //             std::cout << "***** Interpolation *****" << std::endl;
        //         }
        //         std::cout << "blocking clause: " << b << std::endl;
        //         solver->add(b);
        //         return {};
        //     }
        //     err = step && itp;
        //     reached = reached || itp;
        // }
        // const auto projection = trace.back().projection;
        // auto ksolver {SmtFactory::solver(QF_LA)};
        // for (unsigned i = 0; i < trace.size(); ++i) {
        //     ksolver->add(get_subs(i,1)(step));
        //     ksolver->add(!get_subs(i+1,1)(projection));
        //     ksolver->push();
        //     ksolver->add(t.err());
        //     if (ksolver->check() != SmtResult::Unsat) {
        //         return SmtResult::Unknown;
        //     }
        //     ksolver->pop();
        //     ksolver->push();
        //     ksolver->add(projection);
        //     if (ksolver->check() == SmtResult::Unsat) {
        //         backtracking = true;
        //         solver->pop(); // backtracking
        //         trace.pop_back();
        //         const auto b{!subs(projection)};
        //         if (Config::Analysis::log) {
        //             std::cout << "***** k-induction *****" << std::endl;
        //         }
        //         std::cout << "blocking clause: " << b << std::endl;
        //         solver->add(b);
        //         return {};
        //     }
        // }
    // }
    solver->push();
    const auto steps = last ? dg_over_approx.getSuccessors(*last) : dg_over_approx.getRoots();
    const auto step {bools::mkOr(steps)};
    solver->add(subs(step));
    solver->add(get_subs(trace.size() + 1, 1)(unreached));
    if (!trace.empty() && trace.back().id > last_orig_clause) {
        solver->add(subs(theory::mkNeq(theory::toExpr(trace_var), arith::mkConst(trace.back().id))));
    }
    add_blocking_clauses();
    switch (solver->check()) {
        case SmtResult::Unknown:
            return SmtResult::Unknown;
        case SmtResult::Unsat: {
            if (trace.empty()) {
                return safe ? SmtResult::Sat : SmtResult::Unknown;
            }
            backtracking = true;
            const auto projection{trace.back().projection};
            solver->pop(); // current step
            solver->pop(); // backtracking
            trace.pop_back();
            --depth;
            const auto b {!subs(projection)};
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
    const auto trans{rule_map.at(id)};
    const auto m{model.composeBackwards(subs)};
    const auto imp{m.syntacticImplicant(trans)};
    auto projection {imp};
    if (trace.empty()) {
        projection = projection && m.syntacticImplicant(t.init());
    } else {
        projection = projection && trace.back().projection;
    }
    projection = mbp::int_mbp(projection, m, mbp_kind, [](const auto x){
        return !theory::isPostVar(x);
    });
    solver->push();
    solver->add(subs(imp && projection));
    projection = post_to_pre(projection);
    unreached = unreached && !projection;
    const auto smt_res{solver->check()};
    assert(smt_res == SmtResult::Sat);
    ++depth;
    trace.emplace_back(id, imp, m, projection);
    if (trace.size() > 1) {
        dependency_graph.addEdge(trace.at(trace.size() - 2).implicant, imp);
    }
    return {};
}

ITSModel ADCLSat::get_model() {
    // TODO
}
