#include "reachability.hpp"
#include "chainstrategy.hpp"
#include "chain.hpp"
#include "preprocess.hpp"
#include "loopacceleration.hpp"
#include "result.hpp"
#include "yices.hpp"

Reachability::Reachability(const ITSProblem &its): its(its), z3(its) {
    z3.enableModels();
}

Reachability::Step::Step(const TransIdx transition, const fset &sat): transition(transition), sat(sat) {}

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

Reachability::fset Reachability::satisfied(const BoolExpr &b, const Subs &model) const {
    fset res;
    for (const auto &rel: b->lits()) {
        if (rel.subs(model).isTriviallyTrue()) {
            res.insert(rel);
        }
    }
    return res;
}

bool covers(const RelSet rels, const Subs &model) {
    return std::all_of(rels.begin(), rels.end(), [&](const auto &rel){return rel.subs(model).isTriviallyTrue();});
}

bool Reachability::leaves_scc(const TransIdx idx) const {
    const Rule &r = its.getRule(idx);
    return sccs.getSccIndex(r.getLhsLoc()) != sccs.getSccIndex(r.getRhsLoc(0));
}

option<unsigned> Reachability::is_loop(const TransIdx idx, const Subs &model) const {
    for (int pos = trace.size() - 1; pos >= 0; --pos) {
        const Step step = trace[pos];
        if (leaves_scc(step.transition)) {
            return {};
        }
        if (step.transition == idx && covers(step.sat, model)) {
            return pos;
        }
    }
    return {};
}

bool Reachability::is_redundant(const TransIdx idx, const Subs &model) const {
    if (leaves_scc(idx)) {
        return false;
    }
    Automaton<TransIdx> regex({idx});
    for (int pos = trace.size() - 1; pos >= 0; --pos) {
        const Step step = trace[pos];
        if (leaves_scc(step.transition)) {
            return false;
        }
        const Automaton<TransIdx> previous = regexes.at(step.transition);
        regex = previous.compose(regex);
        bool matches = regex.is_subset_of(previous);
        std::cout << "regex: " << regex << std::endl;
        std::cout << "previous: " << previous << std::endl;
        bool cover = covers(step.sat, model);
        std::cout << "matches: " << matches << ", cover: " << cover << std::endl;
        if (matches && cover) {
            return true;
        }
    }
    return false;
}

BoolExpr Reachability::handle_update(const Rule &r) {
    RelSet eqs;
    const Subs &oldSigma = sigmas.back();
    Subs newSigma;
    for (const auto &p: r.getUpdate(0)) {
        const Var x = its.addFreshTemporaryVariable(p.first.get_name());
        eqs.insert(Rel::buildEq(x, p.second.subs(oldSigma)));
        newSigma.put(p.first, x);
    }
    sigmas.push_back(newSigma);
    return buildAnd(eqs);
}

void Reachability::analyze() {
    Yices::init();
    removeIrrelevantTransitions();
    simplify();
    chain();
    simplify();
    for (const TransIdx idx: its.getAllTransitions()) {
        regexes[idx] = Automaton<TransIdx>({idx});
    }
    do {
        if (current == sink) {
            std::cout << "UNSAT" << std::endl;
            proof.print();
            break;
        }
        Subs &sigma = sigmas.back();
        bool success = false;
        const auto do_block = [&](const auto idx, const fset &sat){
            auto block = blocked.back().find(idx);
            if (block == blocked.back().end()) {
                blocked.back()[idx] = {sat};
            } else {
                block->second.insert(sat);
            }
        };
        for (const TransIdx idx: its.getTransitionsFrom(current)) {
            const Rule r = its.getRule(idx);
            const BoolExpr g = r.getGuard()->subs(sigma);
            z3.push();
            z3.add(g);
            const auto block = blocked.back().find(idx);
            if (block != blocked.back().end()) {
                for (const auto &fset: block->second) {
                    z3.add(!buildAnd(fset));
                }
            }
            if (z3.check() == Smt::Sat) {
                Subs model = sigma.compose(z3.model().toSubs());
                fset sat = satisfied(g, model);
                if (is_redundant(idx, model)) {
                    do_block(idx, sat);
                    z3.pop();
                    continue;
                }
                option<unsigned> backlink = is_loop(idx, model);
                if (backlink) {
                    std::vector<TransIdx> path{trace[*backlink].transition};
                    Rule loop = its.getRule(trace[*backlink].transition);
                    for (unsigned i = *backlink + 1; i < trace.size(); ++i) {
                        loop = *Chaining::chainRules(its, loop, its.getRule(trace[i].transition));
                        path.push_back(trace[i].transition);
                    }
                    loop = *Chaining::chainRules(its, loop, r);
                    const Result<Rule> simplified = Preprocess::simplifyRule(its, loop, false);
                    if (simplified) {
                        loop = *simplified;
                    }
                    const AccelerationResult accel_res = LoopAcceleration::accelerate(its, loop.toLinear(), -1, Complexity::Const);
                    std::cout << "accelerating ";
                    for (const auto l: path) {
                        std::cout << l;
                    }
                    std::cout << std::endl;
                    if (accel_res.rules.empty()) {
                        std::cout << "failed!" << std::endl;
                        do_block(idx, sat);
                        z3.pop();
                        continue;
                    } else {
                        assert(accel_res.rules.size() == 1);
                        const Rule accel = accel_res.rules.front();
                        const Automaton<TransIdx> automaton = Automaton(path).mk_cyclic(idx);
                        const auto loop_idx = its.addRule(accel);
                        if (loop_idx) {
                            trace.emplace_back(idx, sat);
                            z3.add(handle_update(r));
                            z3.add(accel.getGuard()->subs(sigmas.back()));
                            if (z3.check() == Smt::Sat) {
                                std::cout << "success!" << std::endl;
                                success = true;
                                current = accel.getRhsLoc(0);
                                sigma = sigmas.back();
                                model = sigma.compose(z3.model().toSubs());
                                sat = satisfied(g, model);
                                trace.emplace_back(*loop_idx, sat);
                                z3.add(handle_update(accel));
                                regexes[*loop_idx] = automaton;
                                if (simplified) {
                                    proof.storeSubProof(simplified.getProof());
                                    proof.storeSubProof(accel_res.proof);
                                }
                                break;
                            } else {
                                sigmas.pop_back();
                                do_block(idx, sat);
                                z3.pop();
                                continue;
                            }
                        } else {
                            std::cout << "failed..." << std::endl;
                            do_block(idx, sat);
                            z3.pop();
                            continue;
                        }
                    }
                } else {
                    current = r.getRhsLoc(0);
                    trace.emplace_back(idx, sat);
                    z3.add(handle_update(r));
                }
                success = true;
                break;
            } else {
                z3.pop();
            }
        }
        if (!success && !trace.empty()) {
            const Step &step = trace.back();
            current = its.getRule(step.transition).getLhsLoc();
            sigmas.pop_back();
            blocked.pop_back();
            do_block(step.transition, step.sat);
            trace.pop_back();
            z3.pop();
        }
    } while (!trace.empty());
    if (trace.empty()) {
        std::cout << "MAYBE" << std::endl;
    }
    Yices::exit();
}

void Reachability::analyze(const ITSProblem &its) {
    Reachability(its).analyze();
}
