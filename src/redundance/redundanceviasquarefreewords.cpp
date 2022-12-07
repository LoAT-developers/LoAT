#include "redundanceviasquarefreewords.hpp"

using T = RedundanceViaSquareFreeWords::T;

T RedundanceViaSquareFreeWords::get_singleton_language(const TransIdx idx, const BoolExpr g) {
    const auto it = alphabet.find({idx, g});
    if (it == alphabet.end()) {
        long res = next_char;
        alphabet.emplace(std::pair<TransIdx, BoolExpr>(idx, g), res);
        ++next_char;
        return {res};
    } else {
        return {it->second};
    }
}

T RedundanceViaSquareFreeWords::get_language(const TransIdx idx) {
    return regexes[idx];
}

void RedundanceViaSquareFreeWords::set_language(const TransIdx idx, const T &t) {
    regexes.emplace(idx, t);
}

bool has_squares(const T &v) {
    for (size_t len = 1; len <= v.size() / 2; ++len) {
        for (size_t start = 0; start < v.size() - len; ++start) {
            bool is_square = true;
            for (size_t i = 0; i < len; ++i) {
                if (v[start+i] != v[start+len+i]) {
                    is_square = false;
                    break;
                }
            }
            if (is_square) {
                return true;
            }
        }
    }
    return false;
}

bool RedundanceViaSquareFreeWords::is_redundant(const T &t) const {
    return has_squares(t) || covered.contains(t);
}

void RedundanceViaSquareFreeWords::mark_as_redundant(const T &t) {
    covered.insert(t);
}

void RedundanceViaSquareFreeWords::concat(T &t1, const T &t2) const {
    t1.insert(t1.begin(), t2.begin(), t2.end());
}

void RedundanceViaSquareFreeWords::transitive_closure(T &t) const {
    return;
}
