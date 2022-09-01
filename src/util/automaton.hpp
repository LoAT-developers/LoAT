#pragma once

#include <variant>
#include <set>
#include <queue>
#include <algorithm>
#include <ostream>

template <class T>
class Automaton {

    using kleene = std::set<T>;
    using Segment = std::variant<T, kleene>;
    using Seq = std::vector<Segment>;
    Seq t;

public:

    Automaton<T>() {}

    Automaton<T>(const T &t): t({t}) {}

    Automaton<T>(const kleene &t): t({t}) {}

    Automaton<T>(const Segment &t): t(t) {}

    Automaton<T> compose(const Automaton<T> &that) const {
        Automaton<T> res(t);
        res.t.insert(res.t.end(), that.t.begin(), that.t.end());
    }

    bool is_subset_of(const Automaton<T> &that) const {
        std::queue<T> definite;
        auto it1 = t.begin();
        auto it2 = that.t.begin();
        while (it1 != t.end() && it2 != that.t.end()) {
            if (std::holds_alternative<T>(*it1)) {
                const T t1 = std::get<T>(*it1);
                if (std::holds_alternative<T>(*it2)) {
                    const T t2 = std::get<T>(*it2);
                    if (t1 != t2) {
                        if (!definite.empty() && definite.first() == t2) {
                            definite = std::queue<T>();
                            it2++;
                        } else {
                            return false;
                        }
                    } else {
                        if (!definite.empty()) {
                            if (definite.first() == t1) {
                                definite = std::queue<T>();
                                definite.push(t1);
                            } else {
                                definite = std::queue<T>();
                            }
                        }
                        it1++;
                        it2++;
                    }
                } else {
                    const kleene ts = std::get<kleene>(*it2);
                    if (ts.find(t) == ts.end()) {
                        it2++;
                    } else {
                        definite.push(t);
                        it1++;
                    }
                }
            } else {
                if (std::holds_alternative<T>(*it2)) {
                    if (!definite.empty() && definite.first() == std::get<T>(*it2)) {
                        definite.pop();
                        it2++;
                    } else {
                        return false;
                    }
                } else {
                    const kleene k1 = std::get<kleene>(*it1);
                    const kleene k2 = std::get<kleene>(*it2);
                    if (std::any_of(k1.begin(), k1.end(), [&](const T &t){return k2.find(t) == k2.end();})) {
                        it2++;
                    } else {
                        definite = std::queue<T>();
                        it1++;
                    }
                }
            }
        }
        if (it1 != t.end()) {
            return false;
        }
        while (it2 != that.t.end() && std::holds_alternative<kleene>(*it2)) {
            it2++;
        }
        return it2 == that.t.end();
    }

    friend std::ostream& operator<<(std::ostream &s, const Automaton<T> &t) {
        for (unsigned i = 0; i < t.forward.size(); ++i) {
            s << i << "-" << t.forward[i] << ">" << (i+1) << " ";
        }
        for (const auto &bl: t.backward) {
            s << bl.src << "-" << bl.t << ">" << bl.dst << " ";
        }
        return s;
    }

};
