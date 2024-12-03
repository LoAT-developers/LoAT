#include "pbsa.hpp"
#include "realqe.hpp"
#include "realmbp.hpp"

const Config::TRPConfig config {
    .mbpKind = Config::TRPConfig::RealQe,
    .recurrent_cycles = false,
    .recurrent_exps = true,
    .recurrent_pseudo_divs = false,
    .recurrent_pseudo_bounds = true,
    .recurrent_bounds = true};

PBSA::PBSA(const ITSPtr its)
    : its_to_safety(its),
      t(its_to_safety.transform()),
      post_to_pre(t.pre_to_post().invert()),
      trp(t.pre_to_post(), config) {
    Int id = 0;
    for (const auto &t : t.trans()) {
        transitions.emplace(id, mbp::real_qe(t, theory::isTempVar));
        ++id;
    }
    for (const auto &[pre, post] : t.pre_to_post()) {
        const auto i{theory::next(pre)};
        pre_to_intermediate.insert(pre, i);
        intermediate_to_post.insert(i, post);
    }
    pre_to_intermediate.insert(trace_var, ArithVar::next());
    intermediate_to_pre = pre_to_intermediate.invert();
    post_to_intermediate = intermediate_to_post.invert();
    std::vector<Bools::Expr> disjuncts;
    std::vector<Bools::Expr> reach_disjuncts {reachable};
    for (Int i = 0; i < transitions.size(); ++i) {
        disjuncts.emplace_back(transitions[i] && theory::mkEq(theory::toExpr(trace_var), arith::mkConst(i)));
        reach_disjuncts.emplace_back(mbp::real_qe(transitions[i], [](const auto &x) {
            return !theory::isProgVar(x);
        }));
    }
    step = bools::mkOr(disjuncts);
    reachable = bools::mkOr(reach_disjuncts);
    const auto reachable_intermediate{pre_to_intermediate(reachable)};
    const auto reachable_post{intermediate_to_post(reachable_intermediate)};
    solver->add(!reachable_intermediate);
    solver->add(!reachable_post);
}

std::optional<SmtResult> PBSA::do_step() {
    solver->push();
    solver->add(reachable);
    solver->add(post_to_intermediate(step));
    solver->add(pre_to_intermediate(step));
    switch (solver->check()) {
        case SmtResult::Unsat:
            if (SmtFactory::check(reachable && t.err()) == SmtResult::Unsat) {
                return SmtResult::Sat;
            } else {
                return SmtResult::Unknown;
            }
        case SmtResult::Unknown:
            return SmtResult::Unknown;
        case SmtResult::Sat:
            break;
    }
    const auto model{solver->model()};
    const auto fst_trans_id{model.get<Arith>(trace_var)};
    const auto snd_trans_id{model.get<Arith>(pre_to_intermediate.get<Arith>(trace_var))};
    const auto fst_trans{transitions.at(fst_trans_id)};
    const auto snd_trans{transitions.at(snd_trans_id)};
    const auto fst_imp{model.syntacticImplicant(post_to_intermediate(fst_trans))};
    const auto snd_imp{model.syntacticImplicant(pre_to_intermediate(snd_trans))};
    if (Config::Analysis::log) {
        std::cout << "fst_imp: " << fst_imp << std::endl;
        std::cout << "snd_imp: " << snd_imp << std::endl;
    }
    const auto imp{intermediate_to_post(fst_imp)};
    Bools::Expr learned{top()};
    if (imp == intermediate_to_pre(snd_imp)) {
        if (Config::Analysis::log) {
           std::cout << "found loop: " << imp << std::endl;
        }
        const auto m {model.composeBackwards(post_to_intermediate)};
        learned = trp.compute(imp, m);
        learned = qe::real_qe(learned, model, [&](const auto &x) {
            return x == Var(trp.get_n());
        });
    } else {
        if (Config::Analysis::log) {
           std::cout << "no loop" << std::endl;
        }
        learned = qe::real_qe(fst_imp && snd_imp, model, theory::isTempVar);
    }
    learned = Preprocess::preprocessFormula(learned);
    if (Config::Analysis::log) {
        std::cout << "learned " << learned << std::endl;
    }
    const auto trans{learned && theory::mkEq(theory::toExpr(trace_var), arith::mkConst(transitions.size()))};
    transitions.emplace(transitions.size(), trans);
    step = step || trans;
    const auto reach {model.syntacticImplicant(reachable)};
    if (Config::Analysis::log) {
        std::cout << "computing newly reachable states..." << std::endl;
    }
    auto r {post_to_pre(qe::real_qe(reach && learned, model, [](const auto &x) {
        return !theory::isPostVar(x);
    }))};
    if (Config::Analysis::log) {
        std::cout << "reachable: " << r << std::endl;
    }
    reachable = reachable || r;
    solver->pop();
    const auto reachable_intermediate{pre_to_intermediate(r)};
    const auto reachable_post{intermediate_to_post(reachable_intermediate)};
    solver->add(!reachable_intermediate);
    solver->add(!reachable_post);
    return {};
}

ITSModel PBSA::get_model() {
    // TODO
}

ITSSafetyCex PBSA::get_cex() {
    // TODO
}
