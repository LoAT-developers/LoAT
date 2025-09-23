#pragma once

#include "linkedhashmap.hpp"
#include "variantset.hpp"

template <class IK, class IV, class AK, class AV, class BK, class BV>
class ExprMap {

protected:

    linked_hash_map<IK, IV> m_arith;
    linked_hash_map<BK, BV> m_bool;
    linked_hash_map<AK, AV> m_arr;

public:

    void put(const IK& x, const IV& v) {
        m_arith.put(x, v);
    }

    void put(const BK& x, const BV& v) {
        m_bool.put(x, v);
    }

    void put(const AK& x, const AV& v) {
        m_arr.put(x, v);
    }

    std::optional<IV> get(const IK& x) const {
        return m_arith.get(x);
    }

    std::optional<BV> get(const BK& x) const {
        return m_bool.get(x);
    }

    std::optional<AV> get(const AK& x) const {
        return m_arr.get(x);
    }

    void erase(const IK& x) {
        m_arith.erase(x);
    }

    void erase(const BK& x) {
        m_bool.erase(x);
    }

    void erase(const AK& x) {
        m_arr.erase(x);
    }

    void erase(const VariantSet<IK, AK, BK>& keys) {
        for (const auto &x: keys.template get<IK>()) {
            m_arith.erase(x);
        }
        for (const auto &x: keys.template get<BK>()) {
            m_bool.erase(x);
        }
        for (const auto &x: keys.template get<AK>()) {
            m_arr.erase(x);
        }
    }

    template <class Visitor>
    void for_each(const Visitor& f) const {
        for (const auto &p: m_arith) {
            f(p);
        }
        for (const auto &p: m_bool) {
            f(p);
        }
        for (const auto &p: m_arr) {
            f(p);
        }
    }

    bool empty() const {
        return m_arith.empty() && m_bool.empty() && m_arr.empty();
    }

    VariantSet<IK, AK, BK> domain() const {
        VariantSet<IK, AK, BK> res;
        for_each([&](const auto &p) {
            res.insert(p.first);
        });
        return res;
    }

};

template <class IK, class IV, class BK, class BV, class AK, class AV>
std::ostream& operator<<(std::ostream& s, const ExprMap<IK, IV, BK, BV, AK, AV>& map) {
    s << "}";
    auto first {true};
    map.for_each([&](const auto &p) {
        if (first) {
            first = false;
        } else {
            s << ", ";
        }
        s << p.first << " = " << p.second;
    });
    return s << "}";
}
