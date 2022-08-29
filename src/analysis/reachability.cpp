#include "reachability.hpp"
#include "chainstrategy.hpp"
#include "preprocess.hpp"

Reachability::Reachability(const ITSProblem &its): its(its), z3(its) {}

void Reachability::removeIrrelevantTransitions() {
    std::set<LocationIdx> keep;
    std::stack<LocationIdx> todo;
    todo.push(*its.getSink());
    do {
        const LocationIdx current = todo.top();
        todo.pop();
        keep.insert(current);
        for (const auto p: its.getPredecessorLocations(current)) {
            if (keep.find(p) == keep.end()) {
                todo.push(p);
            }
        }

    } while (!todo.empty());
    std::set<TransIdx> deleted;
    for (const auto idx: its.getAllTransitions()) {
        const LocationIdx target = its.getRule(idx).getRhsLoc(0);
        if (keep.find(target) == keep.end()) {
            const std::set<TransIdx> d = its.removeLocationAndRules(target);
            deleted.insert(d.begin(), d.end());
        }
    }
    if (!deleted.empty()) {
        proof.deletionProof(deleted);
    }
}

void Reachability::simplify() {
    for (const TransIdx idx: its.getAllTransitions()) {
        const auto res = Preprocess::preprocessRule(its, its.getRule(idx));
        if (res) {
            its.replaceRules({idx}, {res.get()});
            proof.storeSubProof(res.getProof());
        }
    }
}

void Reachability::chain() {
    const ResultViaSideEffects chain = Chaining::chainLinearPaths(its);
    if (chain) {
        proof.section("chained linear paths");
        proof.storeSubProof(chain.getProof());
    }
}

std::set<const Rel&> satisfied(const BoolExpr &b, const Subs &model) {
    std::set<const Rel&> res;
    for (const auto &rel: b->litRefs()) {
        if (rel.subs(model).isTriviallyTrue()) {
            res.insert(rel);
        }
    }
    return res;
}



bool Reachability::is_redundant(const TransIdx idx, const Subs &model) const {

}

bool Reachability::is_blocked(const TransIdx idx, const Subs &model) const {
    const auto &blocked = this->blocked.back();
    const auto it = blocked.find(idx);
    return it != blocked.end() && std::any_of(it->second.begin(), it->second.end(), [&](const auto &s){
        return std::all_of(s.begin(), s.end(), [&](const auto &r){
            return r.subs(model).isTriviallyTrue();
        });
    });
}

void Reachability::analyze() {
    removeIrrelevantTransitions();
    chain();
    blocked.push_back({});
    do {
        if (current == sink) {
            std::cout << "UNSAT" << std::endl;
            return;
        }
        for (const TransIdx c: its.getTransitionsFrom(current)) {
            const Rule r = its.getRule(c);
            const BoolExpr g = r.getGuard()->subs(sigma);
            z3.push();
            z3.add(g);
            if (z3.check() == Smt::Sat) {
                const Subs model = sigma.compose(z3.model().toSubs());
                const std::set<const Rel&> sat = satisfied(g, model);
            }
        }
    } while (1);
}
