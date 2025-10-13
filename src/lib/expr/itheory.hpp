#pragma once

#include <concepts>
#include <variant>
#include <tuple>

#include "linkedhashset.hpp"

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
        {x->postVar(x)} -> std::same_as<T>;
};

template <typename T>
concept ITheory = requires(T t, typename T::Var var, typename T::Cell cell, typename T::Lit lit) {
        requires IVar<typename T::Var>;
        requires ILit<typename T::Lit>;
        typename T::Expr;
        typename T::Renaming;
        typename T::Subs;
        {T::varToExpr(var)} -> std::same_as<typename T::Expr>;
        {T::cellToExpr(cell)} -> std::same_as<typename T::Expr>;
};

template<ITheory... Th>
class Theory {

public:

    using Theories = std::tuple<Th...>;
    static const Theories theories;
    using Lit = std::variant<typename Th::Lit...>;
    using Var = std::variant<typename Th::Var...>;
    using Expr = std::variant<typename Th::Expr...>;
    using Renaming = std::tuple<typename Th::Renaming...>;
    using Pair = std::variant<std::pair<typename Th::Var, typename Th::Expr>...>;
    using VarPair = std::variant<std::pair<typename Th::Var, typename Th::Var>...>;
    using Subs = std::tuple<typename Th::Subs...>;

};
