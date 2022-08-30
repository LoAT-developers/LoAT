#pragma once

#include <vector>
#include <map>
#include <algorithm>
#include <ostream>

template <class T>
class Automaton {

    struct Backlink {
        unsigned src;
        T t;
        unsigned dst;

        Backlink(const unsigned src, const T &t, const unsigned dst): src(src), t(t), dst(dst) {}

    };

    std::vector<T> forward;
    std::vector<Backlink> backward;

public:

    Automaton<T>() {}

    Automaton<T>(const std::vector<T> &forward): forward(forward) {}

    Automaton<T>(const std::vector<T> &forward, const std::vector<Backlink> &backward): forward(forward), backward(backward) {}

    Automaton<T> compose(const Automaton<T> &that) const {
        Automaton<T> res(forward, backward);
        size_t offset = forward.size();
        res.forward.insert(res.forward.end(), that.forward.begin(), that.forward.end());
        for (const auto &bl: that.backward) {
            res.backward.emplace_back(bl.src + offset, bl.t, bl.dst + offset);
        }
        return res;
    }

    Automaton<T> mk_cyclic(const T &t) const {
        Automaton<T> res(forward, backward);
        res.backward.emplace_back(forward.size() - 1, t, 0);
        res.forward.push_back(t);
        return res;
    }

    bool is_subset_of(const Automaton<T> &that) const {
        unsigned i1 = 0, i2 = 0;
        std::map<unsigned, unsigned> map;
        map[0] = 0;
        const auto store = [&]() {
            const auto it = map.find(i1);
            if (it != map.end()) {
                if (map[i1] != i2) {
                    return false;
                }
            } else {
                map[i1] = i2;
            }
            return true;
        };
        for (const auto &t: forward) {
            if (that.forward[i2] == t) {
                i1++;
                i2++;
                if (!store()) {
                    return false;
                }
            } else {
                const auto it = std::find_if(that.backward.begin(), that.backward.end(), [&](const auto &bl){return bl.src == i2 && bl.t == t;});
                if (it == that.backward.end()) {
                    return false;
                }
                i1++;
                i2 = it->dst;
                if (!store()) {
                    return false;
                }
            }
        }
        assert(i1 == forward.size());
        if (i2 != that.forward.size()) {
            return false;
        }
        // at that point, we've identified a potentially equivalent state for each state from *this
        for (const auto &bl: backward) {
            const unsigned src = map[bl.src];
            const unsigned dst = map[bl.dst];
            if (that.forward[src] == bl.t) {
                if (dst != src + 1) {
                    return false;
                }
            } else {
                const auto it = std::find_if(that.backward.begin(), that.backward.end(), [&](const auto &o_bl){return o_bl.src == src && o_bl.t == bl.t;});
                if (it == that.backward.end() || it->dst != dst) {
                    return false;
                }
            }
        }
        return true;
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
