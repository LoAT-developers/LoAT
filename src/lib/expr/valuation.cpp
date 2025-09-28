#include "valuation.hpp"

void Valuation::put(const Arith::Var& x, const Arith::Const& v) {
    m_arith.put(x, v);
}

void Valuation::put(const Bools::Var& x, const Bools::Const& v) {
    m_bool.put(x, v);
}

void Valuation::put(const ArrayReadPtr<Arith>& x, const Arith::Const& v) {
    m_arr.put(x, v);
}

std::optional<Arith::Const> Valuation::get(const Arith::Var& x) const {
    return m_arith.get(x);
}

std::optional<Bools::Const> Valuation::get(const Bools::Var& x) const {
    return m_bool.get(x);
}

std::optional<Arith::Const> Valuation::get(const ArrayReadPtr<Arith>& x) const {
    return m_arr.get(x);
}

void Valuation::erase(const Arith::Var& x) {
    m_arith.erase(x);
}

void Valuation::erase(const Bools::Var& x) {
    m_bool.erase(x);
}

void Valuation::erase(const ArrayReadPtr<Arith>& x) {
    m_arr.erase(x);
}

void Valuation::erase(const VariantSet<Arith::Var, ArrayReadPtr<Arith>, Bools::Var>& keys) {
    for (const auto &x: keys.get<Arith::Var>()) {
        m_arith.erase(x);
    }
    for (const auto &x: keys.get<Bools::Var>()) {
        m_bool.erase(x);
    }
    for (const auto &x: keys.get<ArrayReadPtr<Arith>>()) {
        m_arr.erase(x);
    }
}

bool Valuation::empty() const {
    return m_arith.empty() && m_bool.empty() && m_arr.empty();
}

VariantSet<Arith::Var, ArrayReadPtr<Arith>, Bools::Var> Valuation::domain() const {
    VariantSet<Arith::Var, ArrayReadPtr<Arith>, Bools::Var> res;
    for_each([&](const auto &p) {
        res.insert(p.first);
    });
    return res;
}

LitSet Valuation::lits() const {
    LitSet res;
    for (const auto& [x,v]: m_arith) {
        res.insert(arith::mkEq(x, arith::mkConst(v)));
    }
    for (const auto& [x,v]: m_bool) {
        res.insert(bools::mk(x, !v));
    }
    for (const auto& [x,v]: m_arr) {
        res.insert(arrays::mkElemEq<Arith>(x, arith::mkConst(v)));
    }
    return res;
}

std::ostream& operator<<(std::ostream& s, const Valuation& map) {
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
