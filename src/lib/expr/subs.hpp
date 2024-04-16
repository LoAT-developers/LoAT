#pragma once

#include "theory.hpp"
#include "boolsubs.hpp"

#include <boost/functional/hash.hpp>
#include <utility>

class Subs {

    using It = std::variant<Arith::Subs::const_iterator, Bools::Subs::const_iterator>;

    typename TheTheory::Subs t {};

public:

    using Pair = typename TheTheory::Pair;

    class Iterator {

        template <size_t I = 0>
        inline It beginImpl(size_t i) const {
            if constexpr (I < num_theories) {
                if (I == i) {
                    return It{std::get<I>(subs.t).begin()};;
                } else {
                    return beginImpl<I + 1>(i);
                }
            } else {
                throw std::invalid_argument("i too large");
            }
        }

        It begin(size_t i) const;

        template <size_t I = 0>
        inline It endImpl(size_t i) const {
            if constexpr (I < num_theories) {
                if (I == i) {
                    return It(std::get<I>(subs.t).end());;
                } else {
                    return endImpl<I + 1>(i);
                }
            } else {
                throw std::invalid_argument("i too large");
            }
        }

        It end(size_t i) const;

        template <size_t I = 0>
        inline Pair getCurrentImpl() const {
            if constexpr (I < num_theories) {
                if (ptr.index() == I) {
                    return Pair(*std::get<I>(ptr));
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

        Iterator(const Subs &subs, const It &ptr);
        reference operator*();
        pointer operator->();

        template <size_t I = 0>
        inline void incrementImpl() {
            if constexpr (I < num_theories) {
                if (ptr.index() == I) {
                    std::get<I>(ptr)++;
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

        const Subs &subs;
        It ptr;
        std::optional<Pair> current{};

    };

    Iterator end() const;
    Iterator begin() const;
    Subs project(const VarSet &vars) const;
    void put(const Pair &p);
    void put(const Var &x, const Expr &y);

    template <ITheory T>
    void put(const typename T::Var &var, const typename T::Expr &expr) {
        std::get<typename T::Subs>(t).put(var, expr);
    }

    Subs();
    Subs(Pair &p);

    template<ITheory T>
    static Subs build(const typename T::Var var, const typename T::Expr expr) {
        Subs subs;
        subs.put<T>(var, expr);
        return subs;
    }

    template <ITheory T>
    static Subs build(typename T::Subs subs) {
        Subs res;
        res.get<T>() = subs;
        return res;
    }

    VarSet domain() const;
    Expr get(const Var &var) const;

    template <ITheory T>
    typename T::Expr get(const typename T::Var &var) const {
        return std::get<typename T::Subs>(t).get(var);
    }

    Subs unite(const Subs &that) const;
    bool changes(const Var &x) const;
    void erase(const Var &x);
    void erase(const VarSet &xs);
    void print(std::ostream &s) const;
    size_t hash() const;
    bool contains(const Var &var) const;
    size_t size() const;
    bool empty() const;
    bool isLinear() const;
    bool isPoly() const;
    bool operator==(const Subs &that) const = default;

    template <size_t I>
    typename std::tuple_element_t<I, decltype(t)>::Subs& get() {
        return std::get<I>(t);
    }

    template <ITheory T>
    typename T::Subs& get() {
        return std::get<typename T::Subs>(t);
    }

    template <ITheory T>
    const typename T::Subs& get() const {
        return std::get<typename T::Subs>(t);
    }

    template <size_t I>
    std::tuple_element_t<I, decltype(t)>& get() {
        return std::get<I>(t);
    }

    template <size_t I>
    const std::tuple_element_t<I, decltype(t)>& get() const {
        return std::get<I>(t);
    }

    Bools::Expr operator()(const Lit &lit) const;
    Bools::Expr operator()(const Bools::Expr e) const;
    Expr operator()(const Expr &expr) const;
    /**
     * that.concat(this)
     */
    BoolSubs tac(const BoolSubs &that) const;
    Subs concat(const Subs &that) const;
    Subs compose(const Subs &that) const;
    void collectCoDomainVars(VarSet &res) const;
    void collectVars(VarSet &vars) const;
    VarSet vars() const;
    VarSet coDomainVars() const;

    static Var first(const Pair &p);
    static Expr second(const Pair &p);

    static Subs Empty;

};

std::ostream& operator<<(std::ostream &s, const Subs &subs);


namespace std {

template<>
struct tuple_size<Subs::Pair> {
    static constexpr size_t value = 2;
};


template<>
struct tuple_element<0, Subs::Pair> {
    using type = Var;
};

template<>
struct tuple_element<1, Subs::Pair> {
    using type = Expr;
};

template<std::size_t Index>
std::tuple_element_t<Index, Subs::Pair> get(const Subs::Pair& p) {
    if constexpr (Index == 0) {
        return Subs::first(p);
    }
    if constexpr (Index == 1) {
        return Subs::second(p);
    }
}

}
