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

    Const get(const Var &var) const;

    template <ITheory T>
    void put(const typename T::Var &var, const typename T::Const &val) {
        std::get<linked_hash_map<typename T::Var, typename T::Const>>(m).put(var, val);
    }

    template <ITheory T>
    bool contains(const typename T::Var &var) const {
        return std::get<linked_hash_map<typename T::Var, typename T::Const>>(m).contains(var);
    }

    bool contains(const Var &var) const;

    template <ITheory T>
    typename T::Model& get() {
        return std::get<typename T::Model>(m);
    }

    template <ITheory T>
    const typename T::Model& get() const {
        return std::get<typename T::Model>(m);
    }

private:

    template<std::size_t I = 0>
    inline void toSubsImpl(Subs &subs) const {
        if constexpr (I < num_theories) {
            using T = std::tuple_element_t<I, Theories>;
            auto &substitution {subs.get<T>()};
            const auto &model {std::get<I>(m)};
            for (const auto &[x,_]: model) {
                substitution.put(x, T::constToExpr(model[x]));
            }
            toSubsImpl<I+1>(subs);
        }
    }

public:

    Subs toSubs() const;

private:

    template <size_t I = 0>
    inline bool evalImpl(const Lit &lit) const {
        if constexpr (I < num_theories) {
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
                        }) == top();
        } else {
            return e->eval(std::get<typename T::Model>(m));
        }
    }

    Const eval(const Expr &e) const;

private:

    template <size_t I = 0>
    inline void composeBackwardsImpl(const Subs &subs, Model &res) const {
        if constexpr (I < num_theories) {
            using Th = std::tuple_element_t<I, Theories>;
            const auto &substitution {subs.get<Th>()};
            const auto &model {std::get<I>(m)};
            auto &result {res.get<Th>()};
            for (const auto &[key, _]: substitution) {
                result.put(key, eval<Th>(substitution.get(key)));
            }
            for (const auto &[key, value]: model) {
                if (!result.contains(key)) {
                    result.put(key, value);
                }
            }
            composeBackwardsImpl<I+1>(subs, res);
        }
    }

public:

    Model composeBackwards(const Subs &subs) const;
    Bools::Expr syntacticImplicant(const Bools::Expr e) const;

private:

    typename TheTheory::Model m{};

};

std::ostream& operator<<(std::ostream &s, const Model &e);