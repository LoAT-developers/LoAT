#include "chain.hpp"
#include "rulepreprocessing.hpp"
#include "config.hpp"

Chain::Chain(ITSProblem &its): its(its) {}

ITSModel Chain::transform_model(const ITSModel &m) const {
    ITSModel res {m};
    for (const auto &[from,rule,to]: predecessors) {
        const auto r {rule.renameTmpVars()};
        res.set_invariant(to, res.get_invariant(to) || (r.getGuard() && r.getUpdate()(res.get_invariant(from))));
    }
    return res;
}

bool Chain::chainLinearPaths() {
    bool changed{false};
    do {
        changed = false;
        for (const auto &first : its.getAllTransitions()) {
            const auto succ{its.getSuccessors(&first)};
            if (succ.size() == 1 && !succ.contains(&first)) {
                const auto second_idx{*succ.begin()};
                if (!its.isSimpleLoop(second_idx)) {
                    predecessors.emplace(its.getLhsLoc(&first), first, its.getRhsLoc(&first));
                    const auto chained{Preprocess::chain({first, second_idx->renameTmpVars()})};
                    its.addRule(chained, &first, second_idx);
                    linked_hash_set<TransIdx> deleted;
                    deleted.insert(&first);
                    if (its.getPredecessors(second_idx).size() == 1) {
                        deleted.insert(second_idx);
                    }
                    if (Config::Analysis::doLogPreproc()) {
                        std::cout << "chaining\n\trule 1: " << first << "\n\trule 2: " << *second_idx << "\n\tresult: " << chained << std::endl;
                        std::cout << "removed the following rules after chaining: " << deleted << std::endl;
                    }
                    for (const auto &idx : deleted) {
                        its.removeRule(idx);
                    }
                    changed = true;
                    break;
                }
            }
        }
    } while (changed);
    return !predecessors.empty();
}
