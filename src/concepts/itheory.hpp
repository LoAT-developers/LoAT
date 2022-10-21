#pragma once

#include <concepts>
#include <type_traits>
#include <stdexcept>
#include <string>
#include <set>
#include <map>
#include <variant>
#include <tuple>
#include <boost/functional/hash.hpp>

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
concept IVars = requires(T x, std::set<Var> res) {
        x.collectVars(res);
};

template <typename T>
concept ILit = requires(T x) {
        requires IComparable<T>;
        {x.normalize()} -> std::same_as<T>;
        {x.toRedlog()} -> std::same_as<std::string>;
        {x.hash()} -> std::same_as<unsigned>;
        {x.isTriviallyTrue()} -> std::same_as<bool>;
        {x.isWellformed()} -> std::same_as<bool>;
};

template <typename T>
concept IVar = requires(T x, std::string name) {
        requires IComparable<T>;
        {T(name)} -> std::same_as<T>;
};

template <typename T>
concept IBaseTheory = requires(T t) {
        requires IVar<typename T::Var>;
        requires ILit<typename T::Lit>;
        requires IVars<typename T::Lit, typename T::Var>;
        typename T::Val;
};

template <typename T>
concept ITheory = requires(T t, typename T::Val val, typename T::Var var) {
        requires IBaseTheory<T>;
        typename T::Expression;
        typename T::Subs;
        {T::valToExpr(val)} -> std::same_as<typename T::Expression>;
        {T::varToExpr(var)} -> std::same_as<typename T::Expression>;
};

template<ITheory... Th>
class Theory {

public:

    using Theories = std::tuple<Th...>;
    static const Theories theories;
    using Lit = std::variant<typename Th::Lit...>;
    using Var = std::variant<typename Th::Var...>;
    using Val = std::variant<typename Th::Val...>;
    using Model = std::tuple<std::map<typename Th::Var, typename Th::Val>...>;
    using Subs = std::tuple<typename Th::Subs...>;
    using Expression = std::variant<typename Th::Expression...>;
    using Pair = std::variant<std::pair<typename Th::Var, typename Th::Expression>...>;
    using Iterator = std::variant<typename Th::Subs::const_iterator...>;

private:

    template <size_t I = 0>
    inline static Expression varToExprImpl(const Var &var) {
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

    static Expression varToExpr(const Var &var) {
        return varToExprImpl<0>(var);
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
bool operator==(const Subs<Th...> &fst, const Subs<Th...> &snd) {
    return fst.t == snd.t;
}

template<ITheory... Th>
bool operator<(const Subs<Th...> &fst, const Subs<Th...> &snd) {
    return fst.t < snd.t;
}

template<ITheory... Th>
std::enable_if_t<(sizeof...(Th) > 0), typename Theory<Th...>::Var> first(const typename Subs<Th...>::Pair &p) {
    return std::visit([](const auto &p){return typename Theory<Th...>::Var(p.first);}, p);
}

template<ITheory... Th>
std::enable_if_t<(sizeof...(Th) > 0), typename Theory<Th...>::Expression> second(const typename Subs<Th...>::Pair &p) {
    return std::visit([](const auto &p){return typename Theory<Th...>::Expression(p.second);}, p);
}

}
