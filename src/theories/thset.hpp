#pragma once

#include "itheory.hpp"
#include "option.hpp"

namespace theory {

template <class VS, class VSI, class Var, ITheory... Th>
class ThSet {

    using TheTheory = Theory<Th...>;
    using Self = ThSet<VS, VSI, Var, Th...>;

    VS t;
    static const size_t variant_size = std::variant_size_v<VSI>;

public:

    class Iterator {

        friend class ThSet<VS, VSI, Var, Th...>;

        template <size_t I = 0>
        inline VSI beginImpl(size_t i) const {
            if constexpr (I < variant_size) {
                if (I == i) {
                    return VSI(std::get<I>(set->t).begin());;
                } else {
                    return beginImpl<I + 1>(i);
                }
            } else {
                throw std::invalid_argument("i too large");
            }
        }

        VSI begin(size_t i) const {
            return beginImpl(i);
        }

        template <size_t I = 0>
        inline VSI endImpl(size_t i) const {
            if constexpr (I < variant_size) {
                if (I == i) {
                    return VSI(std::get<I>(set->t).end());;
                } else {
                    return endImpl<I + 1>(i);
                }
            }
            throw std::invalid_argument("i too large");
        }

        VSI end(size_t i) const {
            return endImpl(i);
        }

        template <size_t I = 0>
        inline Var getCurrentImpl() const {
            if constexpr (I < variant_size) {
                if (ptr.index() == I) {
                    return Var(*std::get<I>(ptr));
                }
                return getCurrentImpl<I+1>();
            }
            throw std::invalid_argument("unknown index");
        }

        Var getCurrent() const {
            return getCurrentImpl<0>();
        }

    public:

        using iterator_category = std::input_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Var;
        using pointer           = const value_type*;
        using reference         = const value_type&;

        Iterator(const Self *set, const VSI &ptr) : set(set), ptr(ptr) {}

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
        }

        friend bool operator!= (const Iterator& a, const Iterator& b) {
            return a.ptr != b.ptr;
        }

    private:

        const Self *set;
        VSI ptr;
        option<Var> current;

    };

private:

    template<std::size_t I = 0>
    inline void eraseImpl(const Var &var) {
        if constexpr (I < sizeof...(Th)) {
            if (var.index() == I) {
                std::get<I>(t).erase(std::get<I>(var));
            } else {
                eraseImpl<I+1>(var);
            }
        }
    }

public:

    void erase(const Var &var) {
        eraseImpl(var);
    }

private:

    template<std::size_t I = 0>
    inline Iterator eraseImpl(const Iterator &it) {
        if constexpr (I < sizeof...(Th)) {
            if (it.ptr.index() == I) {
                return Iterator(this, std::get<I>(t).erase(std::get<I>(it.ptr)));
            } else {
                return eraseImpl<I+1>(it);
            }
        }
        throw std::invalid_argument("unknown index");
    }

public:

    Iterator erase(const Iterator &it) {
        return eraseImpl(it);
    }

private:

    template<std::size_t I = 0>
    inline void insertImpl(const Var &var) {
        if constexpr (I < sizeof...(Th)) {
            if (var.index() == I) {
                std::get<I>(t).insert(std::get<I>(var));
            } else {
                insertImpl<I+1>(var);
            }
        }
    }

public:

    void insert(const Var &var) {
        insertImpl(var);
    }

private:

    template<std::size_t I = 0>
    inline void insertAllImpl(const Self &that) {
        if constexpr (I < sizeof...(Th)) {
            const auto &s = std::get<I>(that.t);
            std::get<I>(t).insert(s.begin(), s.end());
            insertAllImpl<I+1>(that);
        }
    }

public:

    void insertAll(const Self &that) {
        insertAllImpl(that);
    }

    template <class V>
    void insertAll(const std::set<V> &that) {
        std::get<std::set<V>>(t).insert(that.begin(), that.end());
    }

private:

    template<std::size_t I = 0>
    inline Iterator findImpl(const Var &var) const {
        if constexpr (I < sizeof...(Th)) {
            if (var.index() == I) {
                const auto &set = std::get<I>(t);
                const auto &it = set.find(std::get<I>(var));
                if (it == set.end()) {
                    return end();
                } else {
                    return Iterator(this, it);
                }
            } else {
                return findImpl<I+1>(var);
            }
        } else {
            return end();
        }
    }

public:

    Iterator find(const Var &var) const {
        return findImpl(var);
    }

    size_t size() const {
        return std::apply([](const auto&... x){return (0 + ... + x.size());}, t);
    }

    bool empty() const {
        return std::apply([](const auto&... x){return (true && ... && x.empty());}, t);
    }

    Iterator end() const {
        return Iterator(this, std::get<variant_size - 1>(t).end());
    }

private:

    template <size_t I = 0>
    inline Iterator beginImpl() const {
        if constexpr (I < variant_size) {
            const auto& x = std::get<I>(t);
            if (x.empty()) {
                return beginImpl<I+1>();
            } else {
                return Iterator(this, x.begin());
            }
        } else {
            return end();
        }
    }

public:

    Iterator begin() const {
        return beginImpl();
    }

    template <class T>
    std::set<T>& get() {
        return std::get<std::set<T>>(t);
    }

    template <class T>
    const std::set<T>& get() const {
        return std::get<std::set<T>>(t);
    }

    template <size_t I>
    std::tuple_element_t<I, decltype(t)>& get() {
        return std::get<I>(t);
    }

    template <size_t I>
    const std::tuple_element_t<I, decltype(t)>& get() const {
        return std::get<I>(t);
    }

    void clear() {
        std::apply([](auto &... s){(..., s.clear());}, t);
    }

};

template<ITheory... Th>
using VarSet = ThSet<std::tuple<std::set<typename Th::Var>...>, std::variant<typename std::set<typename Th::Var>::iterator...>, typename Theory<Th...>::Var, Th...>;

template<ITheory... Th>
using LitSet = ThSet<std::tuple<std::set<typename Th::Lit>...>, std::variant<typename std::set<typename Th::Lit>::iterator...>, typename Theory<Th...>::Lit, Th...>;

}
