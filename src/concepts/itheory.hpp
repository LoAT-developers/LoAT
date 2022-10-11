#pragma once

#include <concepts>
#include <string>
#include <set>

template <typename T>
concept IComparable = requires(T x1, T x2) {
        {x1 < x2} -> std::same_as<bool>;
        {x1 == x2} -> std::same_as<bool>;
};

template <typename T, typename Var>
concept IVars = requires(T x, std::set<Var> res) {
        x.collectVariables(res);
};

template <typename T>
concept ILit = requires(T x) {
        requires IComparable<T>;
        {x.normalize()} -> std::same_as<T>;
        {x.toRedlog()} -> std::same_as<std::string>;
        {x.hash()} -> std::same_as<unsigned>;
};

template <typename T>
concept IVar = requires(T x, std::string name) {
        requires IComparable<T>;
        {T(name)} -> std::same_as<T>;
};

template <typename T>
concept ITheory = requires(T t) {
        requires IVar<typename T::Var>;
        requires ILit<typename T::Lit>;
        requires IVars<typename T::Lit, typename T::Var>;
        typename T::Val;
};

template <typename T>
concept INonBoolTheory = requires(T t) {
        typename T::Subs;
        typename T::Expression;
        requires(ITheory<T>);
};
