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
        x.collectVariables(res);
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
concept ITheory = requires(T t, typename T::Val val) {
        requires IBaseTheory<T>;
        typename T::Expression;
        typename T::Subs;
        {T::valToExpr(val)} -> std::same_as<typename T::Expression>;
};

template<ITheory... Th>
struct TheorySubs {

    using Subs = std::tuple<typename Th::Subs...>;
    using Var = std::variant<typename Th::Var...>;
    using Expression = std::variant<typename Th::Expression...>;
    using Pair = std::variant<std::pair<typename Th::Var, typename Th::Expression>...>;
    using Iterator = std::variant<typename Th::Subs::const_iterator...>;

};

template<ITheory... Th>
struct Theory {

    using Theories = std::tuple<Th...>;
    const Theories theories;
    using Lit = std::variant<typename Th::Lit...>;
    using Var = std::variant<typename Th::Var...>;
    using Val = std::variant<typename Th::Val...>;
    using VarSet = std::tuple<std::set<typename Th::Var>...>;
    using VarSetIterator = std::variant<typename std::set<typename Th::Var>::iterator...>;
    using Model = std::tuple<std::map<typename Th::Var, typename Th::Val>...>;

};

namespace theory {

template <typename ... Ts, std::size_t ... Is>
std::variant<Ts...> get_impl(std::size_t index,
                             std::index_sequence<Is...>,
                             const std::tuple<Ts...>& t) {
    using getter_type = std::variant<Ts...> (*)(const std::tuple<Ts...>&);
    getter_type funcs[] = {+[](const std::tuple<Ts...>& tuple)
                            -> std::variant<Ts...>
                            { return std::get<Is>(tuple); } ...};

    return funcs[index](t);
}

template <typename ... Ts>
std::variant<Ts...> get_rt(std::size_t index, const std::tuple<Ts...>& t) {
    return get_impl(index, std::index_sequence_for<Ts...>(), t);
}

template <ITheory... Th>
class Subs;

template <ITheory... Th>
class VarSet {

    using TheTheory = Theory<Th...>;
    using VS = typename TheTheory::VarSet;
    using VSI = typename TheTheory::VarSetIterator;
    using Var = typename TheTheory::Var;

    friend class Subs<Th...>;
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

        Iterator(const VarSet &set, const VSI &ptr) : set(set), ptr(ptr), current(get_current()) {}

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

        const VarSet &set;
        VSI ptr;
        Var current;

    };

private:

    template<class S, std::size_t I = 0, typename... Sets>
    inline void _collectVars(const S &s) const {
        if constexpr (I < sizeof...(Sets)) {
            if (std::holds_alternative<I>(s)) {
                std::get<I>(s).collectVars(std::get<I>(t));
            } else {
                _collectVars<I+1, Sets...>(s);
            }
        }
    }

public:

    template <class S>
    void collectVars(const S &s) {
        _collectVars(s);
    }

private:

    template<std::size_t I = 0, typename... Sets>
    inline void _erase(const Var &var) const {
        if constexpr (I < sizeof...(Sets)) {
            if (std::holds_alternative<I>(var)) {
                std::get<I>(t).erase(std::get<I>(var));
            } else if constexpr(I+1 != sizeof...(Sets)) {
                _erase<I+1, Sets...>(var);
            }
        }
    }

public:

    void erase(const Var &var) {
        _erase(var);
    }

private:

    template<std::size_t I = 0, typename... Sets>
    inline void _insert(const Var &var) const {
        if constexpr (I < sizeof...(Sets)) {
            if (std::holds_alternative<I>(var)) {
                std::get<I>(t).insert(std::get<I>(var));
            } else {
                _insert<I+1, Sets...>(var);
            }
        }
    }

public:

    void insert(const Var &var) {
        _insert(var);
    }

private:

    template<std::size_t I = 0, typename... Sets>
    inline void _insertAll(const VarSet &that) const {
        if constexpr (I < sizeof...(Sets)) {
            if (std::holds_alternative<I>(that)) {
                const auto &s = std::get<I>(that);
                std::get<I>(t).insert(that.begin(), that.end());
            } else {
                _insert<I+1, Sets...>(that);
            }
        }
    }

public:

    void insertAll(const VarSet &that) {
        _insertAll(that);
    }

    template <class Var>
    void insertAll(const std::set<Var> &that) {
        std::get<std::set<Var>>(t).insert(that.begin(), that.end());
    }

private:

    template<std::size_t I = 0, typename... Sets>
    inline Iterator _find(const Var &var) const {
        if constexpr (I < sizeof...(Sets)) {
            if (std::holds_alternative<I>(var)) {
                const auto &set = std::get<I>(t);
                const auto &it = set.find(std::get<I>(var));
                if (it == set.end()) {
                    return end();
                } else {
                    return it;
                }
            } else {
                return _find<I+1, Sets...>(var);
            }
        } else {
            return end();
        }
    }

public:

    Iterator find(const Var &var) const {
        return _find(var);
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

    template <ITheory T>
    std::set<typename T::Var>& get() {
        return std::get<std::set<typename T::Var>>(t);
    }

    template <ITheory T>
    const std::set<typename T::Var>& get() const {
        return std::get<std::set<typename T::Var>>(t);
    }

    void clear() {
        std::apply([](auto &... s){(..., s.clear());}, t);
    }

};

template <ITheory... Th>
class Subs {

    using TheTheory = Theory<Th...>;
    using TheSubs = TheorySubs<Th...>;
    using VS = VarSet<Th...>;
    using VSI = typename TheTheory::VarSetIterator;
    using Var = typename TheTheory::Var;
    using It = typename TheSubs::Iterator;
    using Expr = typename TheSubs::Expression;

    typename TheSubs::Subs t;
    static const size_t variant_size = std::variant_size_v<Expr>;

    template <ITheory... Th_>
    friend bool operator==(const Subs<Th_...> &fst, const Subs<Th_...> &snd);

    template <ITheory... Th_>
    friend bool operator<(const Subs<Th_...> &fst, const Subs<Th_...> &snd);

public:

    using Pair = typename TheSubs::Pair;

    class Iterator {

        It begin(size_t i) const {
            return std::visit([](const auto &subs){return It(subs.begin());}, get_rt(i, subs.t));
        }

        It end(size_t i) const {
            return std::visit([](const auto &subs){return It(subs.end());}, get_rt(i, subs.t));
        }

        Pair get_current() const {
            Pair res = std::visit([](const auto &it){return Pair(*it);}, ptr);
            return res;
        }

    public:

        using iterator_category = std::input_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Pair;
        using pointer           = const value_type*;
        using reference         = const value_type&;

        Iterator(const Subs &subs, const It &ptr) : subs(subs), ptr(ptr), current(get_current()) {}

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
                    return It(it);
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

        const Subs &subs;
        It ptr;
        Pair current;

    };

    const Iterator begin() const {
        return Iterator(*this, std::get<0>(t).begin());
    }

    const Iterator end() const {
        return Iterator(*this, std::get<variant_size - 1>(t).end());
    }

private:

    template<std::size_t I = 0, typename... S>
    inline void _project(Subs& res, const VS &vars) const {
        if constexpr (I < sizeof...(S)) {
            std::get<I>(res) = std::get<I>(t).project(std::get<I>(vars.t));
            _project<I+1, S...>(res, vars);
        }
    }

public:

    Subs project(const VS &vars) const {
        Subs res;
        _project(res, vars);
        return Subs(res);
    }

private:

    template<std::size_t I = 0, typename... S>
    inline void _put(const Pair &p) {
        if constexpr (I < sizeof...(S)) {
            if (std::holds_alternative<I>(p)) {
                const auto &[x,y] = std::get<I>(p);
                std::get<I>(t).put(x, y);
            } else {
                _put<I+1, S...>(p);
            }
        }
    }

public:

    void put(const Pair &p) {
        _put(p);
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

private:

    template<std::size_t I = 0, typename... S>
    inline void _domain(VS &res) const {
        if constexpr (I < sizeof...(S)) {
            std::get<I>(res.t) = std::get<I>(t).domain();
            _domain<I+1, S...>(res);
        }
    }

public:

    VS domain() const {
        VS res;
        _domain(res);
        return res;
    }

private:

    template<class Res, std::size_t I = 0, typename... S>
    inline Res _subs(const Res &s) const {
        if constexpr (I < sizeof...(S)) {
            if (std::holds_alternative<I>(s)) {
                return std::get<I>(s).subs(std::get<I>(t));
            } else {
                return _subs<I+1, S...>(s);
            }
        } else {
            return s;
        }
    }

public:

    template <class Res>
    Res subs(const Res &s) const {
        return _subs(s);
    }

private:

    template<std::size_t I = 0, typename... S>
    inline void _collectVars(VS &res) const {
        if constexpr (I < sizeof...(S)) {
            std::get<I>(t).collectVariables(std::get<I>(res.t));
            _collectVars<I+1, S...>(res);
        }
    }

public:

    void collectVars(VS &vars) const {
        _collectVars(vars);
    }

private:

    template<std::size_t I = 0, typename... S>
    inline size_t _hash() const {
        if constexpr (I + 1 >= sizeof...(S)) {
            return std::get<I>(t).hash();
        } else {
            return boost::hash_combine(_hash<I+1>(), std::get<I>(t).hash());
        }
    }

public:

    size_t hash() const {
        return _hash();
    }

private:

    template<std::size_t I = 0, typename... S>
    inline Expr _get(const Var &var) const {
        if constexpr (I >= sizeof...(S)) {
            throw std::invalid_argument("variable not found");
        } else if (std::holds_alternative<I>(var)) {
            return std::get<I>(t).get(std::get<I>(var));
        } else {
            return _get<I+1, S...>(var);
        }
    }

public:

    Expr get(const Var &var) const {
        return _get(var);
    }

    template <ITheory T>
    typename T::Expression get(const typename T::Var &var) const {
        return std::get<typename T::Subs>(t).get(var);
    }

private:

    template<std::size_t I = 0, typename... S>
    inline void _compose(const Subs &that) {
        if constexpr (I < sizeof...(S)) {
            std::get<I>(t).compose(std::get<I>(that.t));
            _compose<I+1, S...>(that);
        }
    }

public:

    Subs compose(const Subs &that) const {
        Subs res(*this);
        res._compose(that);
        return res;
    }

private:

    template<std::size_t I = 0, typename... S>
    inline void _concat(const Subs &that) {
        if constexpr (I < sizeof...(S)) {
            std::get<I>(t).compose(std::get<I>(that.t));
            _concat<I+1, S...>(that);
        }
    }

public:

    Subs concat(const Subs &that) const {
        Subs res(*this);
        res._concat(that);
        return res;
    }

private:

    template<std::size_t I = 0, typename... S>
    inline bool _changes(const Var &x) const {
        if constexpr (I < sizeof...(S)) {
            if (std::holds_alternative<I>(x)) {
                return std::get<I>(t).changes(std::get<I>(x));
            } else {
                return _changes<I+1, S...>(x);
            }
        } else {
            return false;
        }
    }

public:

    bool changes(const Var &x) const {
        return _changes(x);
    }

private:

    template<std::size_t I = 0, typename... S>
    inline void _erase(const Var &x) {
        if constexpr (I < sizeof...(S)) {
            if (std::holds_alternative<I>(x)) {
                std::get<I>(t).erase(x);
            } else {
                _erase<I+1, S...>(x);
            }
        }
    }

public:

    void erase(const Var &x) {
        _erase(x);
    }

private:

    template<std::size_t I = 0, typename... S>
    inline void _print(std::ostream &s) const {
        if constexpr (I < sizeof...(S)) {
            s << std::get<I>(t);
            if constexpr (I + 1 < variant_size) {
                _print<I+1, S...>(s);
            }
        }
    }

public:

    void print(std::ostream &s) const {
        _print(s);
    }

private:

    template<std::size_t I = 0, typename... S>
    inline Iterator _find(const Var &var) const {
        if constexpr (I < sizeof...(S)) {
            if (std::holds_alternative<I>(var)) {
                const auto &subs = std::get<I>(t);
                const auto &it = subs.find(std::get<I>(var));
                if (it == subs.end()) {
                    return end();
                } else {
                    return it;
                }
            } else {
                return _find<I+1, S...>(var);
            }
        } else {
            return end();
        }
    }

public:

    Iterator find(const Var &var) const {
        return _find(var);
    }

    bool contains(const Var &var) const {
        return find(var) != end();
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

    int compare(const Subs &that) const {
        if (this->t == that.t) {
            return 0;
        } else if (this->t < that.t) {
            return -1;
        } else {
            return 1;
        }
    }

    template <ITheory T>
    typename T::Subs& get() {
        return std::get<typename T::Subs>(t);
    }

    template <ITheory T>
    const typename T::Subs& get() const {
        return std::get<typename T::Subs>(t);
    }

};

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
std::enable_if_t<(sizeof...(Th) > 0), typename TheorySubs<Th...>::Expression> second(const typename Subs<Th...>::Pair &p) {
    return std::visit([](const auto &p){return typename TheorySubs<Th...>::Expression(p.second);}, p);
}

template<ITheory... Th>
VarSet<Th...> vars(const typename Theory<Th...>::Lit &lit) {
    VarSet<Th...> res;
    res.collectVars(lit);
    return res;
}

template<ITheory... Th>
VarSet<Th...> vars(const typename TheorySubs<Th...>::Expression &e) {
    VarSet<Th...> res;
    res.collectVars(e);
    return res;
}

}
