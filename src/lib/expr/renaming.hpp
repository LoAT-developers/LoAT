#pragma once

#include "theory.hpp"

#include <utility>

class Renaming {

    using It = std::variant<Arith::Renaming::left_const_iterator, Bools::Renaming::left_const_iterator, Arrays<Arith>::Renaming::left_const_iterator>;

    TheTheory::Renaming t {};

public:

    using Pair = TheTheory::VarPair;

    class Iterator {

        template <size_t I = 0>
        It beginImpl(const size_t i) const {
            if constexpr (I < num_theories) {
                if (I == i) {
                    return It{std::get<I>(subs.t).left.begin()};
                }
                return beginImpl<I + 1>(i);
            } else {
                throw std::invalid_argument("i too large");
            }
        }

        It begin(size_t i) const;

        template <size_t I = 0>
        It endImpl(const size_t i) const {
            if constexpr (I < num_theories) {
                if (I == i) {
                    return It(std::get<I>(subs.t).left.end());
                }
                return endImpl<I + 1>(i);
            } else {
                throw std::invalid_argument("i too large");
            }
        }

        It end(size_t i) const;

        template <size_t I = 0>
        Pair getCurrentImpl() const {
            if constexpr (I < num_theories) {
                if (ptr.index() == I) {
                    const auto p {std::get<I>(ptr)};
                    return Pair(std::pair{p->first, p->second});
                }
                return getCurrentImpl<I+1>();
            }
            throw std::invalid_argument("unknown index");
        }

        Pair getCurrent() const;

    public:

        using iterator_category = std::input_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Pair;
        using pointer           = const value_type*;
        using reference         = const value_type&;

        Iterator(const Renaming &subs, const It &ptr);
        reference operator*();
        pointer operator->();

        template <size_t I = 0>
        void incrementImpl() {
            if constexpr (I < num_theories) {
                if (ptr.index() == I) {
                    ++std::get<I>(ptr);
                } else {
                    incrementImpl<I+1>();
                }
            } else {
                throw std::logic_error("unknown index");
            }
        }

        void increment();
        // Prefix increment
        Iterator& operator++();
        // Postfix increment
        Iterator operator++(int);
        friend bool operator== (const Iterator& a, const Iterator& b);

    private:

        const Renaming &subs;
        It ptr;
        std::optional<Pair> current{};

    };

    Iterator end() const;
    Iterator begin() const;
    void insert(const Pair &p);
    void insert(const Var &x, const Var &y);

    template <ITheory T>
    void insert(const T::Var &var, const T::Var &expr) {
        using R = T::Renaming;
        std::get<R>(t).insert(typename R::value_type(var, expr));
    }

    Renaming() = default;
    explicit Renaming(const Pair &p);

    template<ITheory T>
    static Renaming build(const T::Var var, const T::Var expr) {
        Renaming subs;
        subs.insert<T>(var, expr);
        return subs;
    }

    template <ITheory T>
    static Renaming build(T::Renaming subs) {
        Renaming res;
        res.get<T>() = subs;
        return res;
    }

    Var get(const Var &var) const;

    template <ITheory T>
    T::Var get(const T::Var &var) const {
        const auto &m {std::get<typename T::Renaming>(t).left};
        const auto it {m.find(var)};
        return it == m.end() ? var : it->second;
    }

    Renaming unite(const Renaming &that) const;
    bool changes(const Var &x) const;
    void erase(const Var &x);
    void erase(const VarSet &xs);
    void print(std::ostream &s) const;
    size_t hash() const;
    bool contains(const Var &var) const;
    size_t size() const;
    bool empty() const;
    bool operator==(const Renaming &that) const = default;

    template <size_t I>
    std::tuple_element_t<I, decltype(t)>::Renaming& get() {
        return std::get<I>(t);
    }

    template <ITheory T>
    T::Renaming& get() {
        return std::get<typename T::Renaming>(t);
    }

    template <ITheory T>
    const T::Renaming& get() const {
        return std::get<typename T::Renaming>(t);
    }

    template <size_t I>
    std::tuple_element_t<I, decltype(t)>& get() {
        return std::get<I>(t);
    }

    template <size_t I>
    const std::tuple_element_t<I, decltype(t)>& get() const {
        return std::get<I>(t);
    }

    Lit operator()(const Lit &lit) const;
    Expr operator()(const Expr &expr) const;
    Bools::Expr operator()(const Bools::Expr& e) const;
    Arith::Expr operator()(const Arith::Expr &e) const;
    Arrays<Arith>::Lval operator()(const Arrays<Arith>::Lval&) const;
    Bools::Var operator()(const Bools::Var&) const;
    Arith::Var operator()(const Arith::Var&) const;

    VarSet coDomainVars() const;
    void collectCoDomainVars(VarSet &res) const;
    VarSet domain() const;
    Renaming compose(const Renaming &that) const;
    Renaming project(const VarSet &vars) const;
    Renaming invert() const;

    static Var first(const Pair &p);
    static Var second(const Pair &p);

    static Renaming Empty;

    static Var renameVar(const Var &x, Renaming &sigma);

};

std::ostream& operator<<(std::ostream &s, const Renaming &subs);


namespace std {

template<>
struct tuple_size<Renaming::Pair> {
    static constexpr size_t value = 2;
};


template<>
struct tuple_element<0, Renaming::Pair> {
    using type = Var;
};

template<>
struct tuple_element<1, Renaming::Pair> {
    using type = Var;
};

template<std::size_t Index>
std::tuple_element_t<Index, Renaming::Pair> get(const Renaming::Pair& p) {
    if constexpr (Index == 0) {
        return Renaming::first(p);
    }
    if constexpr (Index == 1) {
        return Renaming::second(p);
    }
}

}
