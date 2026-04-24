#pragma once

#include <ranges>

#include "theory.hpp"
#include "boolsubs.hpp"
#include "renaming.hpp"

#include <utility>

class Subs {

    using It = std::variant<Arrays<Arith>::Subs::const_iterator, Bools::Subs::const_iterator>;

    TheTheory::Subs t {};

public:

    static constexpr size_t variants {std::variant_size_v<It>};

    using Pair = TheTheory::Pair;

    class Iterator {

        template <size_t I = 0>
        It beginImpl(const size_t i) const {
            if constexpr (I < variants) {
                if (I == i) {
                    return It{std::get<I>(subs->t).begin()};
                }
                return beginImpl<I + 1>(i);
            } else {
                throw std::invalid_argument("i too large");
            }
        }

        It begin(size_t i) const;

        template <size_t I = 0>
        It endImpl(const size_t i) const {
            if constexpr (I < variants) {
                if (I == i) {
                    return It(std::get<I>(subs->t).end());
                }
                return endImpl<I + 1>(i);
            } else {
                throw std::invalid_argument("i too large");
            }
        }

        It end(size_t i) const;

        template <size_t I = 0>
        std::optional<Pair> getCurrentImpl() const {
            if constexpr (I < variants) {
                if (ptr.index() == I) {
                    const auto it {std::get<I>(ptr)};
                    return it == std::get<I>(subs->t).end() ? std::nullopt : std::optional(*it);
                }
                return getCurrentImpl<I+1>();
            }
            throw std::invalid_argument("unknown index");
        }

        std::optional<Pair> getCurrent() const;

    public:

        using iterator_category = std::input_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Pair;
        using pointer           = const value_type*;
        using reference         = const value_type&;

        Iterator(const Subs &subs, const It &ptr);
        Iterator() = default;
        reference operator*() const;
        pointer operator->() const;

        template <size_t I = 0>
        void incrementImpl() {
            if constexpr (I < variants) {
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

        const Subs* subs;
        It ptr;
        std::optional<Pair> current{};

    };

    Iterator end() const;
    Iterator begin() const;
    Subs project(const VarSet &vars) const;
    Subs project(const std::function<bool(Var)> &keep) const;
    void put(const Pair &p);

    void put(const Bools::Var&, const Bools::Expr&);
    void put(const Arrays<Arith>::Var&, const Arrays<Arith>::Expr&);

    void writeConst(const Arrays<Arith>::Var&, const Arith::Expr&);
    void update(const ArrayReadPtr<Arith>&, const Arith::Expr&);

    Subs() = default;
    explicit Subs(const Pair &p);
    explicit Subs(const Renaming&);

    static Subs build(const Bools::Var&, const Bools::Expr&);
    static Subs build(const Arrays<Arith>::Var&, const Arrays<Arith>::Expr&);
    static Subs build(const ArrayReadPtr<Arith>&, const Arith::Expr&);

    template <ITheory T>
    static Subs build(T::Subs subs) {
        Subs res;
        res.get<T>() = subs;
        return res;
    }

    VarSet domain() const;

    Bools::Expr get(const Bools::Var &var) const;
    Arrays<Arith>::Expr get(const Arrays<Arith>::Var &var) const;
    Arith::Expr getConst(const ArithVarPtr&) const;

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
    bool isIdempotent() const;
    bool operator==(const Subs &that) const = default;

    template <size_t I>
    std::tuple_element_t<I, decltype(t)>::Subs& get() {
        return std::get<I>(t);
    }

    template <ITheory T>
    const T::Subs& get() const {
        return std::get<typename T::Subs>(t);
    }

    template <ITheory T>
    T::Subs& get() {
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
    Expr operator()(const Expr &expr) const;
    Subs concat(const Subs &that) const;
    Subs concat(const Renaming &that) const;
    Subs compose(const Subs &that) const;
    Subs unite(const Subs &that) const;
    void collectCoDomainVars(VarSet &res) const;
    void collectVars(VarSet &vars) const;
    VarSet vars() const;
    VarSet coDomainVars() const;
    void collectCoDomainCells(CellSet &res) const;
    CellSet coDomainCells() const;

    static Var first(const Pair &p);
    static std::variant<Arrays<Arith>::Expr, Bools::Expr> second(const Pair &p);

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
    using type = std::variant<Arrays<Arith>::Expr, Bools::Expr>;
};

template<std::size_t Index>
std::tuple_element_t<Index, Subs::Pair> get(const Subs::Pair& p) {
    if constexpr (Index == 0) {
        return Subs::first(p);
    }
    if constexpr (Index == 1) {
        return Subs::second(p);
    }
    throw std::invalid_argument("invalid index");
}

}
