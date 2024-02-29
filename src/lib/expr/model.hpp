#pragma once

#include "theory.hpp"
#include "subs.hpp"

class Model {

public:

    Model();
    Model(const typename TheTheory::Model &m);

    template <ITheory T>
    typename T::Const get(const typename T::Var &var) const {
        return std::get<linked_hash_map<typename T::Var, typename T::Const>>(m)[var];
    }

    TheTheory::Const get(const Var &var) const;

    template <ITheory T>
    void put(const typename T::Var &var, const typename T::Const &val) {
        std::get<linked_hash_map<typename T::Var, typename T::Const>>(m).emplace(var, val);
    }

    template <ITheory T>
    bool contains(const typename T::Var &var) const {
        return std::get<linked_hash_map<typename T::Var, typename T::Const>>(m).contains(var);
    }

    template <ITheory T>
    const typename T::Model& get() const {
        return std::get<typename T::Model>(m);
    }

private:

    template<std::size_t I = 0>
    inline void toSubsImpl(Subs &subs) const {
        using Pair = Subs::Pair;
        if constexpr (I < std::tuple_size_v<Theories>) {
            using T = std::tuple_element_t<I, Theories>;
            const auto &substitution {subs.get<T>()};
            const auto &model {std::get<I>(m)};
            for (const auto &[x,_]: substitution) {
                subs.put(Pair(std::pair{x, T::constToExpr(model[x])}));
            }
            toSubsImpl<I+1>(subs);
        }
    }

public:

    Subs toSubs() const;

private:

    template <size_t I = 0>
    inline bool evalImpl(const Lit &lit) const {
        if constexpr (I < std::tuple_size_v<Theories>) {
            if (lit.index() == I) {
                const auto &literal {std::get<I>(lit)};
                const auto &model {std::get<I>(m)};
                return literal.eval(model);
            }
            return evalImpl<I+1>(lit);
        } else {
            throw std::logic_error("unknown theory");
        }
    }

public:

    bool eval(const Lit &lit) const;

    template <ITheory T>
    typename T::Const eval(const typename T::Expr &e) const {
        if constexpr (std::is_same_v<T, Bools>) {
            return e->map(
                        [&](const auto &lit) {
                            return eval(lit) ? top() : bot();
                        })->isTriviallyTrue();
        } else {
            return e->eval(std::get<typename T::Model>(m));
        }
    }

    typename TheTheory::Const eval(const ThExpr &e) const;

private:

    template <size_t I = 0>
    inline void composeBackwardsImpl(const Subs &subs, Model &res) const {
        if constexpr (I < std::variant_size_v<ThExpr>) {
            using Th = std::tuple_element_t<I, Theories>;
            const auto &substitution {subs.get<Th>()};
            const auto &model {std::get<I>(m)};
            for (const auto &[key, _]: model) {
                res.put<Th>(key, eval<Th>(substitution.get(key)));
            }
            composeBackwardsImpl<I+1>(subs, res);
        }
    }

public:

    Model composeBackwards(const Subs &subs) const;
    BoolExprPtr syntacticImplicant(const BoolExprPtr e) const;

private:

    typename TheTheory::Model m{};

};

std::ostream& operator<<(std::ostream &s, const Model &e);
