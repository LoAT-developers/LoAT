#pragma once

#include <concepts>
#include <type_traits>
#include <stdexcept>
#include <string>
#include <variant>
#include <tuple>

#include "set.hpp"
#include "map.hpp"

template<typename ... Ts>
struct Overload : Ts ... {
    using Ts::operator()...;
};
template<class... Ts> Overload(Ts...) -> Overload<Ts...>;

template <typename T>
concept IComparable = requires(T x1, T x2) {
        {x1 < x2} -> std::same_as<bool>;
        {x1 == x2} -> std::same_as<bool>;
};

template <typename T, typename Var>
concept IVars = requires(T x, linked_hash_set<Var> res) {
        x.collectVars(res);
};

template <typename T>
concept ILit = requires(T x, T y) {
        {x.isTriviallyTrue()} -> std::same_as<bool>;
        {x.isPoly()} -> std::same_as<bool>;
        {x.isLinear()} -> std::same_as<bool>;
        {x.hash()} -> std::same_as<std::size_t>;
};

template <typename T>
concept IVar = requires(T x, unsigned idx) {
        requires IComparable<T>;
        {x->next()} -> std::same_as<T>;
};

template <typename T>
concept IBaseTheory = requires(T t) {
        requires IVar<typename T::Var>;
        requires ILit<typename T::Lit>;
        // requires IVars<typename T::Lit, typename T::Var>;
        typename T::Const;
};

template <typename T>
concept ITheory = requires(T t, typename T::Const val, typename T::Var var) {
        requires IBaseTheory<T>;
        typename T::Expr;
        typename T::Subs;
        {T::valToExpr(val)} -> std::same_as<typename T::Expr>;
        {T::varToExpr(var)} -> std::same_as<typename T::Expr>;
        {T::anyValue()} -> std::same_as<typename T::Expr>;
};

template<ITheory... Th>
class Theory {

public:

    using Theories = std::tuple<Th...>;
    static const Theories theories;
    using Lit = std::variant<typename Th::Lit...>;
    using Var = std::variant<typename Th::Var...>;
    using Const = std::variant<typename Th::Const...>;
    using Model = std::tuple<linked_hash_map<typename Th::Var, typename Th::Const>...>;
    using Subs = std::tuple<typename Th::Subs...>;
    using Expr = std::variant<typename Th::Expr...>;
    using Pair = std::variant<std::pair<typename Th::Var, typename Th::Expr>...>;
    using Iterator = std::variant<typename Th::Subs::const_iterator...>;

private:

    template <size_t I = 0>
    inline static Expr varToExprImpl(const Var &var) {
        if constexpr (I < sizeof...(Th)) {
            if (var.index() == I) {
                return std::tuple_element_t<I, Theories>::varToExpr(std::get<I>(var));
            } else {
                return varToExprImpl<I+1>(var);
            }
        } else {
            throw std::logic_error("I too large");
        }
    }

public:

    static Expr varToExpr(const Var &var) {
        return varToExprImpl<0>(var);
    }

private:

    template <size_t I = 0>
    inline static Expr anyValueImpl(const size_t i) {
        if constexpr (I < sizeof...(Th)) {
            if (i == I) {
                return std::tuple_element_t<I, Theories>::anyValue();
            } else {
                return anyValueImpl<I+1>(i);
            }
        } else {
            throw std::logic_error("I too large");
        }
    }

public:

    static Expr anyValue(const size_t i) {
        return anyValueImpl<0>(i);
    }

};

namespace theory {

template <ITheory... Th>
class Subs;


template<ITheory... Th>
std::ostream& operator<<(std::ostream &s, const Subs<Th...> &subs) {
    subs.print(s);
    return s;
}

template<ITheory... Th>
std::enable_if_t<(sizeof...(Th) > 0), typename Theory<Th...>::Var> first(const typename Subs<Th...>::Pair &p) {
    return std::visit([](const auto &p){return typename Theory<Th...>::Var(p.first);}, p);
}

template<ITheory... Th>
std::enable_if_t<(sizeof...(Th) > 0), typename Theory<Th...>::Expr> second(const typename Subs<Th...>::Pair &p) {
    return std::visit([](const auto &p){return typename Theory<Th...>::Expr(p.second);}, p);
}

}
