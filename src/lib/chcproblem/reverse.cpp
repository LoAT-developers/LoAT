#include "reverse.hpp"
#include "config.hpp"

Reverse::Reverse(const CHCPtr orig): orig(orig) {}

std::pair<ClausePtr, Subs> rev(const ClausePtr c) {
    std::vector<Bools::Expr> constr{c->get_constraint()};
    std::optional<LhsPtr> premise;
    Subs subs;
    if (const auto conc{c->get_conclusion()}) {
        std::vector<Var> lhs_args;
        for (const auto &arg : (*conc)->get_args()) {
            if (const auto &x{theory::is_var(arg)}) {
                lhs_args.emplace_back(*x);
            } else {
                const auto y{theory::next(arg)};
                lhs_args.emplace_back(y);
                subs.put(y, arg);
                constr.push_back(theory::mkEq(theory::toExpr(y), arg));
            }
        }
        premise = Lhs::mk((*conc)->get_pred(), lhs_args);
    }
    std::optional<FunAppPtr> conclusion;
    if (const auto prem{c->get_premise()}) {
        std::vector<Expr> rhs_args;
        for (const auto &x : (*prem)->get_args()) {
            rhs_args.emplace_back(theory::toExpr(x));
        }
        conclusion = FunApp::mk((*prem)->get_pred(), rhs_args);
    }
    return {Clause::mk(premise, bools::mkAnd(constr), conclusion), subs};
}

CHCPtr Reverse::reverse() {
    auto res {std::make_shared<CHCProblem>()};
    for (const auto &c: orig->get_clauses()) {
        const auto reversed {rev(c).first};
        if (Config::Analysis::model) {
            rev_map.emplace(reversed, c);
        }
        res->add_clause(reversed);
    }
    return res;
}

CHCModel Reverse::transform_model(const CHCModel &model) const {
    CHCModel res;
    for (const auto &[f,i]: model.get_interpretations()) {
        res.set_interpretation(f, !i);
    }
    return res;
}

CHCCex Reverse::transform_cex(const CHCCex &cex) const {
    CHCCex res {orig};
    std::unordered_map<ClausePtr, std::pair<ClausePtr, Subs>> learned_rev_map;
    const auto lookup = [&](const ClausePtr x) {
        const auto it1 {rev_map.find(x)};
        if (it1 == rev_map.end()) {
            const auto it2 {learned_rev_map.find(x)};
            if (it2 == learned_rev_map.end()) {
                const auto p {rev(x)};
                learned_rev_map.emplace(x, p);
                return p.first;
            }
            return it2->second.first;
        }
        return it1->second;
    };
    for (const auto &[x,y]: cex.get_implicants()) {
        res.add_implicant(lookup(y), lookup(x));
    }
    for (const auto &[x,y]: cex.get_accel()) {
        res.add_accel(lookup(y), lookup(x));
    }
    for (const auto &[x,ys]: cex.get_resolvents()) {
        std::vector<ClausePtr> rev;
        for (auto it = ys.rbegin(); it != ys.rend(); ++it) {
            rev.push_back(lookup(*it));
        }
        res.add_resolvent(rev, lookup(x));
    }
    const auto &states {cex.get_states()};
    const auto &transitions {cex.get_transitions()};
    assert(states.size() == transitions.size());
    for (int i = states.size() - 1; i >= 0; --i) {
        const auto &s {states.at(i)};
        const auto &t {transitions.at(i)};
        const auto it {rev_map.find(t)};
        if (it == rev_map.end()) {
            const auto &[trans,subs] {learned_rev_map.at(t)};
            if (!res.try_step(s.composeBackwards(subs), trans)) {
                throw std::logic_error("transform_cex failed");
            }
        } else if (!res.try_step(s, it->second)) {
            throw std::logic_error("transform_cex failed");
        }
    }
    return res;
}
