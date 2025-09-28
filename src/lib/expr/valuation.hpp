#pragma once

#include "linkedhashmap.hpp"
#include "variantset.hpp"
#include "theory.hpp"

class Valuation {

protected:

    linked_hash_map<Arith::Var, Arith::Const> m_arith;
    linked_hash_map<Bools::Var, Bools::Const> m_bool;
    linked_hash_map<ArrayReadPtr<Arith>, Arith::Const> m_arr;

public:

    void put(const Arith::Var& x, const Arith::Const& v);

    void put(const Bools::Var& x, const Bools::Const& v);

    void put(const ArrayReadPtr<Arith>& x, const Arith::Const& v);

    std::optional<Arith::Const> get(const Arith::Var& x) const;

    std::optional<Bools::Const> get(const Bools::Var& x) const;

    std::optional<Arith::Const> get(const ArrayReadPtr<Arith>& x) const;

    void erase(const Arith::Var& x);

    void erase(const Bools::Var& x);

    void erase(const ArrayReadPtr<Arith>& x);

    void erase(const VariantSet<Arith::Var, ArrayReadPtr<Arith>, Bools::Var>& keys);

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

    bool empty() const;

    VariantSet<Arith::Var, ArrayReadPtr<Arith>, Bools::Var> domain() const;

    LitSet lits() const;

    Valuation composeBackwards(const Renaming&) const;

};

std::ostream& operator<<(std::ostream& s, const Valuation& map);
