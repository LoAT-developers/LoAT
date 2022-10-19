#pragma once

#include "itheory.hpp"

namespace theory {

template <class VS, class VSI, class Var, ITheory... Th>
class ThSet {

    using TheTheory = Theory<Th...>;
    using Self = ThSet<VS, VSI, Var, Th...>;

    VS t;
    static const size_t variant_size = std::variant_size_v<VSI>;

public:

    class Iterator {

        VSI begin(size_t i) const {
            return std::visit([](const auto &set){return VSI(set.begin());}, get_rt(i, set.t));
        }

        VSI end(size_t i) const {
            return std::visit([](const auto &set){return VSI(set.end());}, get_rt(i, set.t));
        }

        Var get_current() const {
            return std::visit([](const auto &it){return Var(*it);}, ptr);
        }

    public:

        using iterator_category = std::input_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Var;
        using pointer           = const value_type*;
        using reference         = const value_type&;

        Iterator(const Self &set, const VSI &ptr) : set(set), ptr(ptr), current(get_current()) {}

        reference operator*() const {
            return current;
        }

        pointer operator->() {
            return &current;
        }

        // Prefix increment
        Iterator& operator++() {
            if (ptr == end(ptr.index())) {
                if (ptr.index() + 1 == variant_size) {
                    throw std::invalid_argument("out of bounds");
                }
                ptr = begin(ptr.index() + 1);
            } else {
                ptr = std::visit([](auto &it){
                    ++it;
                    return VSI(it);
                }, ptr);
            }
            current = get_current();
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

        friend bool operator!= (const Iterator& a, const Iterator& b) {
            return a.ptr != b.ptr;
        };

    private:

        const Self &set;
        VSI ptr;
        Var current;

    };

    template<std::size_t I = 0>
    void erase(const Var &var) {
        if constexpr (I < sizeof...(Th)) {
            if (std::holds_alternative<std::variant_alternative_t<I, Var>>(var)) {
                std::get<I>(t).erase(std::get<I>(var));
            } else {
                erase<I+1>(var);
            }
        }
    }

    template<std::size_t I = 0>
    void insert(const Var &var) {
        if constexpr (I < sizeof...(Th)) {
            if (std::holds_alternative<std::variant_alternative_t<I, Var>>(var)) {
                std::get<I>(t).insert(std::get<I>(var));
            } else {
                insert<I+1>(var);
            }
        }
    }

    template<std::size_t I = 0>
    void insertAll(const Self &that) {
        if constexpr (I < sizeof...(Th)) {
            const auto &s = std::get<I>(that.t);
            std::get<I>(t).insert(s.begin(), s.end());
            insertAll<I+1>(that);
        }
    }

    template <class V>
    void insertAll(const std::set<V> &that) {
        std::get<std::set<V>>(t).insert(that.begin(), that.end());
    }

    template<std::size_t I = 0>
    Iterator find(const Var &var) const {
        if constexpr (I < sizeof...(Th)) {
            if (std::holds_alternative<std::variant_alternative_t<I, Var>>(var)) {
                const auto &set = std::get<I>(t);
                const auto &it = set.find(std::get<I>(var));
                if (it == set.end()) {
                    return end();
                } else {
                    return Iterator(*this, it);
                }
            } else {
                return find<I+1>(var);
            }
        } else {
            return end();
        }
    }

    template <std::size_t I = 0>
    size_t size() const {
        if constexpr (I < sizeof...(Th)) {
            return std::get<I>(t).size() + size<I+1>();
        } else {
            return 0;
        }
    }

    bool empty() const {
        return std::apply([](const auto&... x){return (true && ... && x.empty());}, t);
    }

    const Iterator begin() const {
        return Iterator(*this, std::get<0>(t).begin());
    }

    const Iterator end() const {
        return Iterator(*this, std::get<variant_size - 1>(t).end());
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
