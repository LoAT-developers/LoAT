#pragma once

#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <assert.h>

template <class T>
class Automaton {

    using State = unsigned;
    using StateSet = std::set<State>;

    std::set<T> sigma;
    StateSet states;
    StateSet final;
    std::map<State, std::map<T, State>> transitions_inv;
    std::map<State, std::map<T, State>> transitions;

    StateSet non_final() const {
        StateSet res(states);
        res.erase(final.begin(), final.end());
        return res;
    }

    size_t num_transitions() const {
        size_t res = 0;
        for (const auto &p: transitions) {
            res += p->second.size();
        }
        return res;
    }

    bool equal(const Automaton<T> &that) const {
        if (num_transitions() != that.num_transitions()) {
            return false;
        }
        std::map<State, State> equiv;
        std::map<State, State> equiv_inv;
        std::stack<std::pair<State, State>> todo;
        todo.emplace(0,0);
        while (!todo.empty()) {
            const auto p = todo.top();
            todo.pop();
            const auto it1 = transitions.find(p.first);
            const auto it2 = that.transitions.find(p.second);
            if ((it1 == transitions.end()) != (it2 == that.transitions.end())) {
                return false;
                // *it1 and *it2 are supposed to be equivalent, one has transitions, the other does not
            }
            if (it1 != transitions.end()) {
                for (const auto &q1: it1->second) {
                    const T &t = q1->first;
                    const State dst1 = q1->second;
                    const auto q2 = it2->second.find(t);
                    if (q2 == it2->second.end()) {
                        // this has a transition for t, that does not
                        return false;
                    }
                    const State dst2 = q2->second;
                    const auto eq = equiv.find(dst1);
                    if (eq != equiv.end()) {
                        if (eq->second != dst2) {
                            // we already marked a different state as equivalent to dst1
                            return false;
                        }
                    } else {
                        const auto eq_inv = equiv_inv.find(dst2);
                        if (eq_inv != equiv_inv.end()) {
                            if (eq_inv->second != dst1) {
                                // we already marked a different state as equivalent to dst2
                                return false;
                            }
                        } else {
                            todo.emplace(dst1, dst2);
                        }
                    }
                    equiv[*it1] = *it2;
                    equiv_inv[*it2] = *it1;
                }
            }
        }
    }

    bool is_subset_of(const Automaton<T> &that) const {
        const Automaton<T> min1 = minimize();
        const Automaton<T> min2 = that.minimize();
        const Automaton<T> inter = min1.inter(min2);
        return inter.equal(min1);
    }

    void add_transition(const State src, const T &t, const State dst) {
        const auto it = transitions.find(src);
        if (it == transitions.end()) {
            transitions[src] = {t, dst};
        } else {
            transitions[src][t] = dst;
        }
        it = transitions_inv.find(dst);
        if (it == transitions_inv.end()) {
            transitions_inv[dst] = {t, src};
        } else {
            transitions_inv[dst][t] = src;
        }
    }

    void add_state(const State s, bool is_final) {
        states.insert(s);
        if (is_final) {
            final.insert(s);
        }
    }

    bool is_final(const State s) {
        return final.find(s) != final.end();
    }

    Automaton<T> inter(const Automaton<T> &that) const {
        Automaton<T> res;
        res.add_state(0, false);
        std::map<std::pair<State, State>, State> stateMap;
        stateMap[{0,0}] = 0;
        std::stack<std::pair<State, State>> todo;
        todo.emplace(0,0);
        State next = 1;
        while (!todo.empty()) {
            const auto p = todo.top();
            todo.pop();
            const auto it1 = transitions.find(p.first);
            const auto it2 = that.transitions.find(p.second);
            if (it1 != transitions.end() && it2 != that.transitions.end()) {
                // there is a transition with the right source in both automata
                for (const auto &p1: it1->second) {
                    const auto &t = p1->first;
                    const State dst1 = p1->second;
                    const auto p2 = it2->second.find(t);
                    if (p2 != it2->second.end()) {
                        // there is a transition with the right symbol in both automata
                        const State dst2 = p2->second;
                        const auto it = stateMap.find({dst1, dst2});
                        if (it == stateMap.end()) {
                            // make sure the required state exists in the intersection
                            res.add_state(next, is_final(dst1) && that.is_final(dst2));
                            stateMap[{dst1, dst2}] = next;
                            todo.emplace(dst1, dst2);
                            ++next;
                        }
                        res.add_transition(p.second, t, stateMap[{dst1, dst2}]);
                    }
                }
            }
        }
        return res;
    }

    Automaton<T> renumber_states(State next) const {
        Automaton<T> res;
        std::map<State, State> stateMap{0, 0};
        for (const auto s: states) {
            res.add_state(next);
            stateMap[s] = next;
            ++next;
        }
        for (const auto s: final) {
            res.final.insert(stateMap[s]);
        }
        for (const auto p1: transitions) {
            for (const auto p2: p1->second) {
                res.add_transition(p1.first, p2.first, p2.second);
            }
        }
    }

    unsigned max_state() const {
        unsigned res = 0;
        for (const State s: states) {
            res = std::max(res, s);
        }
        return res;
    }

    void compose(const Automaton<T> &that) const {
        Automaton<T> t = that.renumber_states(max_state() + 1);
    }

    Automaton<T> minimize() const {
        // P := {F, Q \ F}
        // W := {F, Q \ F}
        // while (W is not empty) do
        //      choose and remove a set A from W
        //      for each c in Sigma do
        //           let X be the set of states for which a transition on c leads to a state in A
        //           for each set Y in P for which X \cap Y is nonempty and Y \ X is nonempty do
        //                replace Y in P by the two sets X \cap Y and Y \ X
        //                if Y is in W
        //                     replace Y in W by the same two sets
        //                else
        //                     if |X \cap Y| <= |Y \ X|
        //                          add X \cap Y to W
        //                     else
        //                          add Y \ X to W
        const StateSet nf = non_final();
        std::vector<StateSet> P{final, nf};
        std::set<StateSet> W{final, nf};
        while (!W.empty()) {
            StateSet A = *W.begin();
            W.erase(W.begin());
            for (const auto &c: sigma) {
                StateSet X;
                for (const auto &t: transitions_inv) {
                    const auto it = t.second.find(c);
                    if (it != t.second.end() && A.find(t.first) != A.end()) {
                        X.insert(it->second);
                    }
                }
                for (auto yit = P.begin(); yit  != P.end();) {
                    StateSet inter;
                    StateSet diff;
                    for (const auto &y: *yit) {
                        bool in_x = false;
                        for (const auto &x: X) {
                            if (x == y) {
                                inter.insert(y);
                                in_x = true;
                                break;
                            }
                        }
                        if (!in_x) {
                            diff.insert(y);
                        }
                    }
                    if (inter.empty() || diff.empty()) {
                        ++yit;
                    } else {
                        yit = P.erase(yit);
                        P.push_back(inter);
                        P.push_back(diff);
                        const auto wit = W.find(*yit);
                        if (wit != W.end()) {
                            W.erase(wit);
                            W.insert(inter);
                            W.insert(diff);
                        } else {
                            if (inter.size() <= diff.size()) {
                                W.insert(inter);
                            } else {
                                W.insert(diff);
                            }
                        }
                    }
                }
            }
        }
        Automaton res;
        std::map<State, State> representatives;
        for (const auto &p: P) {
            bool init = false;
            bool is_final = false;
            const auto rep = *p.begin();
            for (const auto s: p) {
                if (s == 0) {
                    init = true;
                    representatives[s] = 0;
                } else if (this->is_final(s)) {
                    is_final = true;
                    representatives[s] = rep;
                }
            }
            if (init) {
                assert(!is_final);
                res.add_state(0, false);
            } else {
                res.add_state(rep, is_final);
            }
        }
        for (const auto &t: transitions_inv) {
            for (const auto &p: t->second) {
                res.add_transition(representatives[t->first], p->first, representatives[t->second]);
            }
        }
        return res;
    }

};
