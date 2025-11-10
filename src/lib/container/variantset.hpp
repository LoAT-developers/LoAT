#pragma once

#include "linkedhashset.hpp"

#include <optional>
#include <ostream>

template <class... S>
class VariantSet {

    using VS = std::tuple<linked_hash_set<S>...>;
    using VSI = std::variant<typename linked_hash_set<S>::const_iterator...>;
    using Var = std::variant<S...>;
    using Self = VariantSet;

    VS t{};
    static const size_t variant_size = std::variant_size_v<VSI>;

public:

    class Iterator {

        friend class VariantSet;

        template <size_t I = 0>
        VSI beginImpl(const size_t i) const {
            if constexpr (I < variant_size) {
                if (I == i) {
                    return VSI(std::get<I>(set->t).begin());
                }
                return beginImpl<I + 1>(i);
            } else {
                throw std::invalid_argument("i too large");
            }
        }

        VSI begin(const size_t i) const {
            return beginImpl(i);
        }

        template <size_t I = 0>
        VSI endImpl(const size_t i) const {
            if constexpr (I < variant_size) {
                if (I == i) {
                    return VSI(std::get<I>(set->t).end());
                }
                return endImpl<I + 1>(i);
            }
            throw std::invalid_argument("i too large");
        }

        VSI end(const size_t i) const {
            return endImpl(i);
        }

        template <size_t I = 0>
        Var getCurrentImpl() const {
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

        Iterator(const Self *set, const VSI &ptr) : set(set), ptr(ptr), current(getCurrent()) {}

        Iterator(const Iterator &that): set(that.set), ptr(that.ptr), current(that.current) {}

        Iterator() = default;

        Iterator& operator=(const Iterator &that) {
            if (this != &that) {
                this->set = that.set;
                this->ptr = that.ptr;
            }
            return *this;
        }

        reference operator*() const {
            return *current;
        }

        pointer operator->() const {
            return &*current;
        }

        template <size_t I = 0>
        void incrementImpl() {
            if constexpr (I < variant_size) {
                if (ptr.index() == I) {
                    ++std::get<I>(ptr);
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
            current = getCurrent();
            return *this;
        }

        // Postfix increment
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++*this;
            current = getCurrent();
            return tmp;
        }

        friend bool operator== (const Iterator& a, const Iterator& b) {
            return a.ptr == b.ptr;
        }

    private:

        const Self *set;
        VSI ptr;
        std::optional<Var> current{};

    };

private:

    template<std::size_t I = 0>
    void eraseImpl(const Var &var) {
        if constexpr (I < variant_size) {
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
    Iterator eraseImpl(const Iterator &it) {
        if constexpr (I < variant_size) {
            if (it.ptr.index() == I) {
                const auto res = std::get<I>(t).erase(std::get<I>(it.ptr));
                if (res == std::get<I>(t).end()) {
                    return beginImpl<I+1>();
                }
                return Iterator(this, res);
            }
            return eraseImpl<I+1>(it);
        }
        throw std::invalid_argument("unknown index");
    }

public:

    Iterator erase(const Iterator &it) {
        return eraseImpl(it);
    }

private:

    template<std::size_t I = 0>
    bool insertImpl(const Var &var) {
        if constexpr (I < variant_size) {
            if (var.index() == I) {
                return std::get<I>(t).insert(std::get<I>(var)).second;
            }
            return insertImpl<I+1>(var);
        } else {
            return false;
        }
    }

public:

    bool insert(const Var &var) {
        return insertImpl(var);
    }

private:

    template<std::size_t I = 0>
    void insertAllImpl(const Self &that) {
        if constexpr (I < variant_size) {
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
    void insertAll(const linked_hash_set<V> &that) {
        std::get<linked_hash_set<V>>(t).insert(that.begin(), that.end());
    }

private:

    template<std::size_t I = 0>
    bool containsImpl(const Var &var) const {
        if constexpr (I < variant_size) {
            if (var.index() == I) {
                const auto &set = std::get<I>(t);
                return set.contains(std::get<I>(var));
            }
            return containsImpl<I+1>(var);
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

    Iterator end() const {
        return Iterator(this, VSI(std::get<variant_size - 1>(t).end()));
    }

private:

    template <size_t I = 0>
    Iterator beginImpl() const {
        if constexpr (I < variant_size) {
            const auto& x = std::get<I>(t);
            if (x.empty()) {
                return beginImpl<I+1>();
            }
            return Iterator(this, x.begin());
        } else {
            return end();
        }
    }

public:

    Iterator begin() const {
        return beginImpl();
    }

private:

    template <size_t I = 0>
    std::ostream& printImpl(std::ostream &s) const {
        if constexpr (I < variant_size) {
            if (I > 0) {
                s << " u ";
            }
            return printImpl<I+1>(s << std::get<I>(t));
        } else {
            return s;
        }
    }

public:

    std::ostream& print(std::ostream &that) const {
        return printImpl(that);
    }

    template <class T>
    linked_hash_set<T>& get() {
        return std::get<linked_hash_set<T>>(t);
    }

    template <class T>
    const linked_hash_set<T>& get() const {
        return std::get<linked_hash_set<T>>(t);
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

    auto operator<=>(const Self &) const = default;

    VariantSet(const std::initializer_list<Var> &xs) {
        for (const auto &x: xs) {
            insert(x);
        }
    }

    VariantSet() = default;

};

template <class... T>
std::ostream& operator<<(std::ostream &s, const VariantSet<T...> &set) {
    return set.print(s);
}
