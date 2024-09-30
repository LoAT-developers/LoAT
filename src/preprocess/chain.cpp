#include "chain.hpp"
#include "rulepreprocessing.hpp"
#include "config.hpp"

Chain::Chain(ITSPtr its): its(its) {}

ITSModel Chain::transform_model(const ITSModel &m) const {
    ITSModel res {m};
    for (const auto &[from,rule,to]: removed) {
        const auto r {rule->renameTmpVars()};
        res.set_invariant(to, res.get_invariant(to) || (r->getGuard() && r->getUpdate()(res.get_invariant(from))));
    }
    return res;
}

ITSCex Chain::transform_cex(const ITSCex &cex) const {
    ITSCex res {cex};
    for (const auto &[c,p]: chained) {
        res.add_resolvent({p.first, p.second}, c);
    }
    return res;
}

bool Chain::chainLinearPaths() {
    bool changed{false};
    bool success{false};
    do {
        changed = false;
        for (const auto &first : its->getAllTransitions()) {
            const auto succ{its->getSuccessors(first)};
            if (succ.size() == 1 && !succ.contains(first)) {
                const auto second_idx{*succ.begin()};
                if (!its->isSimpleLoop(second_idx)) {
                    const auto c{Preprocess::chain({first, second_idx->renameTmpVars()})};
                    if (Config::Analysis::doLogPreproc()) {
                        std::cout << "chaining\n\trule 1: " << first << "\n\trule 2: " << second_idx << "\n\tresult: " << c << std::endl;
                    }
                    its->addRule(c, first, second_idx);
                    if (Config::Analysis::model) {
                        chained.emplace(c, std::pair{first, second_idx});
                        removed.emplace(its->getLhsLoc(first), first, its->getRhsLoc(first));
                    }
                    its->removeRule(first);
                    if (its->getPredecessors(second_idx).empty()) {
                        if (Config::Analysis::model) {
                            removed.emplace(its->getLhsLoc(second_idx), second_idx, its->getRhsLoc(second_idx));
                        }
                        its->removeRule(second_idx);
                    }
                    changed = true;
                    success = true;
                    break;
                }
            }
        }
    } while (changed);
    return success;
}
