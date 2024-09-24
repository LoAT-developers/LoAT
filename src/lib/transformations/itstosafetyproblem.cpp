#include "itstosafetyproblem.hpp"
#include "formulapreprocessing.hpp"

ITSToSafety::ITSToSafety(const ITSPtr its)
    : its(its),
      init_preprocessor(theory::isTempVar),
      err_preprocessor(theory::isTempVar) {}

ITSModel ITSToSafety::transform_model(const Bools::Expr &e) const {
    ITSModel res;
    const auto loc_var {its->getLocVar()};
    for (const auto &x : its->getLocations()) {
        Subs s{Subs::build<Arith>(loc_var, arith::mkConst(x))};
        res.set_invariant(x, s(e));
    }
    res.set_invariant(its->getInitialLocation(), top());
    return res;
}

Bools::Expr ITSToSafety::rule_to_formula(const RulePtr r, const VarSet &prog_vars) {
    Subs subs;
    std::vector<Bools::Expr> conjuncts;
    conjuncts.push_back(r->getGuard());
    for (const auto &x : prog_vars) {
        if (const auto y {theory::is_var(r->getUpdate().get(x))}) {
            if (theory::isTempVar(*y) && !subs.contains(*y)) {
                subs.put(*y, theory::toExpr(theory::postVar(x)));
                continue;
            }
        }
        conjuncts.push_back(theory::mkEq(theory::toExpr(theory::postVar(x)), r->getUpdate().get(x)));
    }
    const auto res {subs(bools::mkAnd(conjuncts))};
    rev_map.emplace(res, r);
    return res;
}

SafetyProblem ITSToSafety::transform() {
    SafetyProblem sp;
    const auto vars {its->getVars()};
    for (const auto &x: vars) {
        if (theory::isProgVar(x)) {
            sp.add_pre_var(x);
            sp.add_post_var(theory::postVar(x));
        } else if (theory::isPostVar(x)) {
            sp.add_pre_var(theory::progVar(x));
            sp.add_post_var(x);
        }
    }
    for (const auto &y: sp.post_vars()) {
        const auto x {theory::progVar(y)};
        init_map.insert(y, x);
        init_map.insert(x, theory::next(x));
    }
    std::vector<Bools::Expr> init;
    std::vector<Bools::Expr> err;
    for (const auto &r: its->getAllTransitions()) {
        if (its->isInitialTransition(r)) {
            init.emplace_back(init_preprocessor.run(init_map(rule_to_formula(r, sp.pre_vars()))));
        }
        if (its->isSinkTransition(r)) {
            err.emplace_back(err_preprocessor.run(r->getGuard()));
        }
        if (!its->isInitialTransition(r) && !its->isSinkTransition(r)) {
            sp.add_transition(rule_to_formula(r, sp.pre_vars()));
        }
    }
    sp.set_init(bools::mkOr(init));
    sp.set_err(bools::mkOr(err));
    return sp;
}

ITSCex ITSToSafety::transform_cex(const SafetyCex &cex) const {
    ITSCex res{its};
    const auto &init_model{cex.get_step(0).first};
    auto transformed_init_model{init_model};
    transformed_init_model = init_preprocessor.transform_model(transformed_init_model.composeBackwards(init_map));
    const auto incorporate_update = [](const Subs &up, Model &m) {
        for (const auto &p : up) {
            std::visit(
                Overload{
                    [&](const auto &p) {
                        const auto [x,t]{p};
                        using Th = decltype(theory::theory(x));
                        if (const auto y{t->isVar()}; y && (*y)->isTempVar() && !m.contains<Th>(*y)) {
                            m.put<Th>(*y, m.get<Th>(x->postVar(x)));
                        }
                    }},
                p);
        }
    };
    for (const auto &init: its->getInitialTransitions()) {
        auto transformed {transformed_init_model};
        incorporate_update(init->getUpdate(), transformed);
        if (res.try_step(transformed, init)) {
            break;
        }
    }
    assert(res.size() > 0);
    const auto size{cex.size()};
    for (size_t i = 0; i < size; ++i) {
        const auto &[model, transition]{cex.get_step(i)};
        const auto rule{rev_map.at(transition)};
        Model transformed{model};
        incorporate_update(rule->getUpdate(), transformed);
        if (!res.try_step(transformed, rule)) {
            std::cerr << "transformed: " << transformed << std::endl;
            std::cerr << "rule: " << *rule << std::endl;
            throw std::logic_error("transform_cex failed");
        }
    }
    const auto &last {cex.get_step(size - 1).first};
    const auto transformed {err_preprocessor.transform_model(last)};
    for (const auto &t: its->getSinkTransitions()) {
        if (transformed.eval<Bools>(t->getGuard()) && !res.try_step(transformed, t)) {
            throw std::logic_error("transform_cex failed");
        }
    }
    return res;
}
