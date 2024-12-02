#include "reverse.hpp"
#include "config.hpp"

Reverse::Reverse(const CHCPtr orig): orig(orig) {}

ClausePtr rev(const ClausePtr c) {
    return Clause::mk(c->get_conclusion(), c->get_constraint(), c->get_premise());
}

CHCPtr Reverse::reverse() {
    auto res {std::make_shared<CHCProblem>()};
    for (const auto &c: orig->get_clauses()) {
        const auto reversed {rev(c)};
        if (Config::Analysis::model) {
            rev_map.emplace(reversed, c);
        }
        res->add_clause(reversed);
    }
    return res;
}

CHCModel Reverse::transform_model(const CHCModel &model) const {
    CHCModel res;
    for (const auto &[f,p]: model.get_interpretations()) {
        const auto &[args, i] {p};
        res.set_interpretation(f, args, !i);
    }
    return res;
}

CHCCex Reverse::transform_cex(const CHCCex &cex) {
    CHCCex res {orig};
    std::unordered_map<ClausePtr, ClausePtr> learned_rev_map;
    const auto lookup = [&](const ClausePtr x) {
        auto it {rev_map.find(x)};
        if (it == rev_map.end()) {
            it = rev_map.emplace(x, rev(x)).first;
        }
        return it->second;
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
        if (!res.try_step(s, rev_map.at(t))) {
            throw std::logic_error("transform_cex failed");
        }
    }
    return res;
}
