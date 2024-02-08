#pragma once

#include "itheory.hpp"
#include "thset.hpp"

#include <boost/functional/hash.hpp>

namespace theory {

template <ITheory... Th>
class Subs {

    using TheTheory = Theory<Th...>;
    using VS = VarSet<Th...>;
    using Var = typename TheTheory::Var;
    using Lit = typename TheTheory::Lit;
    using It = typename TheTheory::Iterator;
    using Expr = typename TheTheory::Expression;

    typename TheTheory::Subs t {};
    static const size_t variant_size = std::variant_size_v<Expr>;

public:

    using Pair = typename TheTheory::Pair;

    class Iterator {

        template <size_t I = 0>
        inline It beginImpl(size_t i) const {
            if constexpr (I < variant_size) {
                if (I == i) {
                    return It(std::get<I>(subs.t).begin());;
                } else {
                    return beginImpl<I + 1>(i);
                }
            } else {
                throw std::invalid_argument("i too large");
            }
        }

        It begin(size_t i) const {
            return beginImpl(i);
        }

        template <size_t I = 0>
        inline It endImpl(size_t i) const {
            if constexpr (I < variant_size) {
                if (I == i) {
                    return It(std::get<I>(subs.t).end());;
                } else {
                    return endImpl<I + 1>(i);
                }
            } else {
                throw std::invalid_argument("i too large");
            }
        }

        It end(size_t i) const {
            return endImpl(i);
        }

        template <size_t I = 0>
        inline Pair getCurrentImpl() const {
            if constexpr (I < variant_size) {
                if (ptr.index() == I) {
                    return Pair(*std::get<I>(ptr));
                }
                return getCurrentImpl<I+1>();
            }
            throw std::invalid_argument("unknown index");
        }

        Pair getCurrent() const {
            return getCurrentImpl<0>();
        }

    public:

        using iterator_category = std::input_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Pair;
        using pointer           = const value_type*;
        using reference         = const value_type&;

        Iterator(const Subs &subs, const It &ptr) : subs(subs), ptr(ptr) {}

        reference operator*() {
            current = getCurrent();
            return *current;
        }

        pointer operator->() {
            current = getCurrent();
            return &(*current);
        }

        template <size_t I = 0>
        inline void incrementImpl() {
            if constexpr (I < variant_size) {
                if (ptr.index() == I) {
                    std::get<I>(ptr)++;
                } else {
                    incrementImpl<I+1>();
                }
            } else {
                throw std::logic_error("unknown index");
            }
        }

        void increment() {
            incrementImpl<0>();
        }

        // Prefix increment
        Iterator& operator++() {
            increment();
            while (ptr.index() + 1 < variant_size && ptr == end(ptr.index())) {
                ptr = begin(ptr.index() + 1);
            }
            return *this;
        }

        // Postfix increment
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator== (const Iterator& a, const Iterator& b) {
            return a.ptr == b.ptr;
        };

    private:

        const Subs &subs;
        It ptr;
        std::optional<Pair> current{};

    };

    Iterator end() const {
        return Iterator(*this, std::get<variant_size - 1>(t).end());
    }

private:

    template <size_t I = 0>
    inline Iterator beginImpl() const {
        if constexpr (I < variant_size) {
            const auto& x = std::get<I>(t);
            if (x.empty()) {
                return beginImpl<I+1>();
            } else {
                return Iterator(*this, x.begin());
            }
        } else {
            return end();
        }
    }

public:

    Iterator begin() const {
        return beginImpl();
    }

private:

    template<std::size_t I = 0>
    inline void projectImpl(Subs& res, const VS &vars) const {
        if constexpr (I < sizeof...(Th)) {
            std::get<I>(res.t) = std::get<I>(t).project(vars.template get<I>());
            projectImpl<I+1>(res, vars);
        }
    }

public:

    Subs project(const VS &vars) const {
        Subs res;
        projectImpl(res, vars);
        return Subs(res);
    }

private:

    template<std::size_t I = 0>
    inline void putImpl(const Pair &p) {
        if constexpr (I < sizeof...(Th)) {
            if (p.index() == I) {
                const auto &[x,y] = std::get<I>(p);
                std::get<I>(t).put(x, y);
            } else {
                putImpl<I+1>(p);
            }
        }
    }

public:

    void put(const Pair &p) {
        putImpl(p);
    }

private:

    template<std::size_t I = 0>
    inline void putImpl(const Var &x, const Expr &y) {
        if constexpr (I < sizeof...(Th)) {
            if (x.index() == I) {
                std::get<I>(t).put(std::get<I>(x), std::get<I>(y));
            } else {
                putImpl<I+1>(x, y);
            }
        }
    }

public:

    void put(const Var &x, const Expr &y) {
        putImpl(x, y);
    }

    template <ITheory T>
    void put(const typename T::Var &var, const typename T::Expression &expr) {
        std::get<typename T::Subs>(t).put(var, expr);
    }

    Subs(){}

    Subs(Pair &p) {
        put(p);
    }

    template<ITheory T>
    static Subs build(const typename T::Var var, const typename T::Expression expr) {
        Subs subs;
        subs.put<T>(var, expr);
        return subs;
    }

    Subs(typename Th::Subs... subs): t(subs...) {}

    template <ITheory T>
    static Subs build(typename T::Subs subs) {
        Subs res;
        res.get<T>() = subs;
        return res;
    }

private:

    template<std::size_t I = 0>
    inline void domainImpl(VS &res) const {
        if constexpr (I < sizeof...(Th)) {
            res.template get<I>() = std::get<I>(t).domain();
            domainImpl<I+1>(res);
        }
    }

public:

    VS domain() const {
        VS res;
        domainImpl(res);
        return res;
    }

private:

    template<std::size_t I = 0>
    inline Expr getImpl(const Var &var) const {
        if constexpr (I >= sizeof...(Th)) {
            throw std::invalid_argument("variable not found");
        } else if (var.index() == I) {
            return std::get<I>(t).get(std::get<I>(var));
        } else {
            return getImpl<I+1>(var);
        }
    }

public:

    Expr get(const Var &var) const {
        return getImpl(var);
    }

    template <ITheory T>
    typename T::Expression get(const typename T::Var &var) const {
        return std::get<typename T::Subs>(t).get(var);
    }

private:

    template<std::size_t I = 0>
    inline void uniteImpl(const Subs &that, Subs &res) const {
        if constexpr (I < sizeof...(Th)) {
            std::get<I>(res.t) = std::get<I>(t).unite(std::get<I>(that.t));
            uniteImpl<I+1>(that, res);
        }
    }

public:

    Subs unite(const Subs &that) const {
        Subs res;
        uniteImpl(that, res);
        return res;
    }

private:

    template<std::size_t I = 0>
    inline bool changesImpl(const Var &x) const {
        if constexpr (I < sizeof...(Th)) {
            if (x.index() == I) {
                return std::get<I>(t).changes(std::get<I>(x));
            } else {
                return changesImpl<I+1>(x);
            }
        } else {
            return false;
        }
    }

public:

    bool changes(const Var &x) const {
        return changesImpl(x);
    }

private:

    template<std::size_t I = 0>
    inline void eraseImpl(const Var &x) {
        if constexpr (I < sizeof...(Th)) {
            if (x.index() == I) {
                std::get<I>(t).erase(std::get<I>(x));
            } else {
                eraseImpl<I+1>(x);
            }
        }
    }

public:

    void erase(const Var &x) {
        eraseImpl(x);
    }

private:

    template<std::size_t I = 0>
    inline void eraseImpl(const VarSet<Th...> &xs) {
        if constexpr (I < sizeof...(Th)) {
            auto &s = std::get<I>(t);
            for (const auto &x: xs.template get<I>()) {
                s.erase(x);
            }
            eraseImpl<I+1>(xs);
        }
    }

public:

    void erase(const VarSet<Th...> &xs) {
        eraseImpl(xs);
    }

private:

    template<std::size_t I = 0>
    inline void printImpl(std::ostream &s, bool first = true) const {
        if constexpr (I < sizeof...(Th)) {
            const auto &m {std::get<I>(t)};
            if (!m.empty()) {
                if (first) {
                    first = false;
                } else {
                    s << " u ";
                }
                s << m;
            }
            if constexpr (I + 1 < variant_size) {
                printImpl<I+1>(s, first);
            }
        }
    }

public:

    void print(std::ostream &s) const {
        printImpl(s);
    }

private:

    template<std::size_t I = 0>
    inline void hashImpl(size_t &res) const {
        if constexpr (I < sizeof...(Th)) {
            boost::hash_combine(res, std::get<I>(t).hash());
            if constexpr (I + 1 < variant_size) {
                hashImpl<I+1>(res);
            }
        }
    }

public:

    size_t hash() const {
        size_t res {0};
        hashImpl(res);
        return res;
    }

private:

    template<std::size_t I = 0>
    inline bool containsImpl(const Var &var) const {
        if constexpr (I < sizeof...(Th)) {
            if (var.index() == I) {
                const auto &subs = std::get<I>(t);
                return subs.contains(std::get<I>(var));
            } else {
                return containsImpl<I+1>(var);
            }
        } else {
            return false;
        }
    }

public:

    bool contains(const Var &var) const {
        return containsImpl(var);
    }

    size_t size() const {
        return std::apply([](const auto&... x){return (0 + ... + x.size());}, t);
    }

    bool empty() const {
        return std::apply([](const auto&... x){return (true && ... && x.empty());}, t);
    }

    bool isLinear() const {
        return std::apply([](const auto&... x){return (true && ... && x.isLinear());}, t);
    }

    bool isPoly() const {
        return std::apply([](const auto&... x){return (true && ... && x.isPoly());}, t);
    }

    bool operator==(const Subs &that) const = default;

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

    static Subs Empty;

};

template <ITheory... Th>
Subs<Th...> Subs<Th...>::Empty = Subs<Th...>();

}
