#pragma once

#include "itheory.hpp"
#include "thset.hpp"
#include "arith.hpp"
#include "bools.hpp"
#include "boolsubs.hpp"

#include <boost/functional/hash.hpp>
#include <utility>

namespace theory {

class Subs {

    using TheTheory = Theory<Arith, Bools>;
    using VS = theories::VarSet<Arith, Bools>;
    using Var = typename TheTheory::Var;
    using Lit = typename TheTheory::Lit;
    using It = std::variant<Arith::Subs::const_iterator, Bools::Subs::const_iterator>;
    using Expr = typename TheTheory::Expr;

    typename TheTheory::Subs t {};
    static const size_t variant_size = std::variant_size_v<Expr>;

public:

    using Pair = typename TheTheory::Pair;

    class Iterator {

        template <size_t I = 0>
        inline It beginImpl(size_t i) const {
            if constexpr (I < variant_size) {
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

        It end(size_t i) const;

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

    Iterator begin() const;

private:

    template<std::size_t I = 0>
    inline void projectImpl(Subs& res, const VS &vars) const {
        if constexpr (I < variant_size) {
            std::get<I>(res.t) = std::get<I>(t).project(vars.template get<I>());
            projectImpl<I+1>(res, vars);
        }
    }

public:

    Subs project(const VS &vars) const;

private:

    template<std::size_t I = 0>
    inline void putImpl(const Pair &p) {
        if constexpr (I < variant_size) {
            if (p.index() == I) {
                const auto &[x,y] = std::get<I>(p);
                std::get<I>(t).put(x, y);
            } else {
                putImpl<I+1>(p);
            }
        }
    }

public:

    void put(const Pair &p);

private:

    template<std::size_t I = 0>
    inline void putImpl(const Var &x, const Expr &y) {
        if constexpr (I < variant_size) {
            if (x.index() == I) {
                std::get<I>(t).put(std::get<I>(x), std::get<I>(y));
            } else {
                putImpl<I+1>(x, y);
            }
        }
    }

public:

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

    // Subs(typename Th::Subs... subs): t(subs...) {}

    template <ITheory T>
    static Subs build(typename T::Subs subs) {
        Subs res;
        res.get<T>() = subs;
        return res;
    }

private:

    template<std::size_t I = 0>
    inline void domainImpl(VS &res) const {
        if constexpr (I < variant_size) {
            res.template get<I>() = std::get<I>(t).domain();
            domainImpl<I+1>(res);
        }
    }

public:

    VS domain() const;

private:

    template<std::size_t I = 0>
    inline Expr getImpl(const Var &var) const {
        if constexpr (I >= variant_size) {
            throw std::invalid_argument("variable not found");
        } else if (var.index() == I) {
            return std::get<I>(t).get(std::get<I>(var));
        } else {
            return getImpl<I+1>(var);
        }
    }

public:

    Expr get(const Var &var) const;

    template <ITheory T>
    typename T::Expr get(const typename T::Var &var) const {
        return std::get<typename T::Subs>(t).get(var);
    }

private:

    template<std::size_t I = 0>
    inline void uniteImpl(const Subs &that, Subs &res) const {
        if constexpr (I < variant_size) {
            std::get<I>(res.t) = std::get<I>(t).unite(std::get<I>(that.t));
            uniteImpl<I+1>(that, res);
        }
    }

public:

    Subs unite(const Subs &that) const;

private:

    template<std::size_t I = 0>
    inline bool changesImpl(const Var &x) const {
        if constexpr (I < variant_size) {
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

    bool changes(const Var &x) const;

private:

    template<std::size_t I = 0>
    inline void eraseImpl(const Var &x) {
        if constexpr (I < variant_size) {
            if (x.index() == I) {
                std::get<I>(t).erase(std::get<I>(x));
            } else {
                eraseImpl<I+1>(x);
            }
        }
    }

public:

    void erase(const Var &x);

private:

    template<std::size_t I = 0>
    inline void eraseImpl(const VS &xs) {
        if constexpr (I < variant_size) {
            auto &s = std::get<I>(t);
            for (const auto &x: xs.template get<I>()) {
                s.erase(x);
            }
            eraseImpl<I+1>(xs);
        }
    }

public:

    void erase(const VS &xs);

private:

    template<std::size_t I = 0>
    inline void printImpl(std::ostream &s, bool first = true) const {
        if constexpr (I < variant_size) {
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

    void print(std::ostream &s) const;

private:

    template<std::size_t I = 0>
    inline void hashImpl(size_t &res) const {
        if constexpr (I < variant_size) {
            boost::hash_combine(res, t);
            if constexpr (I + 1 < variant_size) {
                hashImpl<I+1>(res);
            }
        }
    }

public:

    size_t hash() const;

private:

    template<std::size_t I = 0>
    inline bool containsImpl(const Var &var) const {
        if constexpr (I < variant_size) {
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

    bool contains(const Var &var) const;
    size_t size() const;
    bool empty() const;
    bool isLinear() const;
    bool isPoly() const;
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

private:

    template<std::size_t I = 0>
    inline BExpr subsImpl(const Lit &lit) const {
        if constexpr (I < variant_size) {
            if (lit.index() == I) {
                using T = typename std::tuple_element_t<I, TheTheory::Theories>;
                if constexpr (std::same_as<typename T::Var, Bools::Var>) {
                    return this->template get<T>().subs(std::get<I>(lit));
                } else {
                    return (*this)(BoolExpression::mkLit(std::get<I>(lit)));
                }
            } else {
                return subsImpl<I+1>(lit);
            }
        } else {
            throw std::logic_error("unknown theory");
        }
    }

public:

    BExpr operator()(const Lit &lit) const;
    BExpr operator()(const BExpr e) const;
    TheTheory::Expr operator()(const TheTheory::Expr &expr) const;
    /**
     * that.concat(this)
     */
    BoolSubs tac(const BoolSubs &that) const;

private:

    template<std::size_t I = 0>
    inline void concatImpl(const Subs &that, Subs &res) const {
        if constexpr (I < std::tuple_size_v<TheTheory::Theories>) {
            if constexpr (std::same_as<std::tuple_element_t<I, TheTheory::Theories>, Bools>) {
                res.get<I>() = that.tac(get<I>());
            } else {
                res.get<I>() = get<I>().concat(that.get<I>());
            }
            concatImpl<I+1>(that, res);
        }
    }

public:

    Subs concat(const Subs &that) const;

private:

    template<std::size_t I = 0>
    inline void composeImpl(const Subs &that, Subs &res) const {
        if constexpr (I < std::tuple_size_v<TheTheory::Theories>) {
            if constexpr (std::same_as<std::tuple_element_t<I, TheTheory::Theories>, Bools>) {
                res.get<I>() = that.tac(get<I>()).unite(that.get<I>());
            } else {
                res.get<I>() = get<I>().compose(that.get<I>());
            }
            composeImpl<I+1>(that, res);
        }
    }

public:

    Subs compose(const Subs &that) const;

    static Subs Empty;

};

typename Theory<Arith, Bools>::Var first(const typename Subs::Pair &p);
typename Theory<Arith, Bools>::Expr second(const typename Subs::Pair &p);
std::ostream& operator<<(std::ostream &s, const Subs &subs);

}
