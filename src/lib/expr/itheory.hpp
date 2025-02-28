#pragma once

#include <concepts>
#include <stdexcept>
#include <variant>
#include <tuple>

#include "exprfwd.hpp"

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
concept IVars = requires(T x, linked_hash_set<Var> &res) {
        x.collectVars(res);
};

template <typename T>
concept ILit = requires(T x, T y) {
        {x->isTriviallyTrue()} -> std::same_as<bool>;
        {x->isPoly()} -> std::same_as<bool>;
        {x->isLinear()} -> std::same_as<bool>;
};

template <typename T>
concept IVar = requires(T x, unsigned idx) {
        requires IComparable<T>;
        {x->next()} -> std::same_as<T>;
        {x->nextProgVar()} -> std::same_as<T>;
        {x->postVar(x)} -> std::same_as<T>;
};

template <typename T>
concept ITheory = requires(T t, typename T::Const val, typename T::Var var, typename T::Lit lit, typename T::Model m) {
        requires IVar<typename T::Var>;
        requires ILit<typename T::Lit>;
        typename T::Const;
        typename T::Expr;
        typename T::Renaming;
        typename T::Subs;
        {T::constToExpr(val)} -> std::same_as<typename T::Expr>;
        {T::varToExpr(var)} -> std::same_as<typename T::Expr>;
        {T::anyValue()} -> std::same_as<typename T::Expr>;
        {lit->eval(m)} -> std::same_as<bool>;
};

template<ITheory... Th>
class Theory {

public:

    using Theories = std::tuple<Th...>;
    static const Theories theories;
    using Lit = std::variant<typename Th::Lit...>;
    using Var = std::variant<typename Th::Var...>;
    using Const = std::variant<typename Th::Const...>;
    using Model = std::tuple<typename Th::Model...>;
    using Expr = std::variant<typename Th::Expr...>;
    using Renaming = std::tuple<typename Th::Renaming...>;
    using Pair = std::variant<std::pair<typename Th::Var, typename Th::Expr>...>;
    using VarPair = std::variant<std::pair<typename Th::Var, typename Th::Var>...>;
    using Subs = std::tuple<typename Th::Subs...>;

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
    inline static Expr constToExprImpl(const Const &c) {
        if constexpr (I < sizeof...(Th)) {
            if (c.index() == I) {
                return std::tuple_element_t<I, Theories>::constToExpr(std::get<I>(c));
            } else {
                return constToExprImpl<I+1>(c);
            }
        } else {
            throw std::logic_error("I too large");
        }
    }

public:

    static Expr constToExpr(const Const &c) {
        return constToExprImpl<0>(c);
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
