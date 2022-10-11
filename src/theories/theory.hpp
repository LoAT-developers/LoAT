#pragma once

#include "itheory.hpp"
#include "inttheory.hpp"
#include "booltheory.hpp"

#include <boost/functional/hash.hpp>
#include <variant>

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
    using Lit = std::variant<typename Th::Lit...>;
    using Var = std::variant<typename Th::Var...>;
    using Val = std::variant<typename Th::Val...>;
    using VarSet = std::tuple<std::set<typename Th::Var>...>;
    using VarSetIterator = std::variant<typename std::set<typename Th::Var>::iterator...>;
    using Model = std::tuple<std::map<typename Th::Var, typename Th::Val>...>;

};

using TheTheory = Theory<IntTheory, BoolTheory>;
using TheTheorySubs = TheorySubs<IntTheory>;
using Lit = TheTheory::Lit;
using Var = TheTheory::Var;
using ThExpr = TheTheorySubs::Expression;
using ThVar = TheTheorySubs::Var;
using Theories = TheTheory::Theories;

template <typename V>
concept ValidVarType = requires(V v) {
    Var(v);
};

template<typename ... Ts>
struct Overload : Ts ... {
    using Ts::operator() ...;
};
template<class... Ts> Overload(Ts...) -> Overload<Ts...>;

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

class ThSubs;

class VarSet {

    friend class ThSubs;
    TheTheory::VarSet t;
    static const size_t variant_size = std::variant_size_v<TheTheory::VarSetIterator>;

public:

    class Iterator {

        TheTheory::VarSetIterator begin(size_t i) const {
            return std::visit([](const auto &set){return TheTheory::VarSetIterator(set.begin());}, get_rt(i, set.t));
        }

        TheTheory::VarSetIterator end(size_t i) const {
            return std::visit([](const auto &set){return TheTheory::VarSetIterator(set.end());}, get_rt(i, set.t));
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

        Iterator(const VarSet &set, const TheTheory::VarSetIterator &ptr) : set(set), ptr(ptr), current(get_current()) {}

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
                    return TheTheory::VarSetIterator(it);
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
        TheTheory::VarSetIterator ptr;
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

    template <ValidVarType Var>
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

    template <ITheory Th>
    std::set<typename Th::Var>& get() {
        return std::get<std::set<typename Th::Var>>(t);
    }

    template <ITheory Th>
    const std::set<typename Th::Var>& get() const {
        return std::get<std::set<typename Th::Var>>(t);
    }

    void clear() {
        std::apply([](auto &... s){(..., s.clear());}, t);
    }

};

class ThSubs {

    using T = TheTheorySubs::Subs;
    T t;
    static const size_t variant_size = std::variant_size_v<ThExpr>;

    friend bool operator==(const ThSubs &fst, const ThSubs &snd);

public:

    using Pair = TheTheorySubs::Pair;

    class Iterator {

        TheTheorySubs::Iterator begin(size_t i) const {
            return std::visit([](const auto &subs){return TheTheorySubs::Iterator(subs.begin());}, get_rt(i, subs.t));
        }

        TheTheorySubs::Iterator end(size_t i) const {
            return std::visit([](const auto &subs){return TheTheorySubs::Iterator(subs.end());}, get_rt(i, subs.t));
        }

        TheTheorySubs::Pair get_current() const {
            return std::visit([](const auto &it){return TheTheorySubs::Pair(*it);}, ptr);
        }

    public:

        using iterator_category = std::input_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = TheTheorySubs::Pair;
        using pointer           = const value_type*;
        using reference         = const value_type&;

        Iterator(const ThSubs &subs, const TheTheorySubs::Iterator &ptr) : subs(subs), ptr(ptr), current(get_current()) {}

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
                    return TheTheorySubs::Iterator(it);
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

        const ThSubs &subs;
        TheTheorySubs::Iterator ptr;
        TheTheorySubs::Pair current;

    };

    const Iterator begin() const {
        return Iterator(*this, std::get<0>(t).begin());
    }

    const Iterator end() const {
        return Iterator(*this, std::get<variant_size - 1>(t).end());
    }

private:

    template<std::size_t I = 0, typename... Subs>
    inline void _project(ThSubs& res, const VarSet &vars) const {
        if constexpr (I < sizeof...(Subs)) {
            std::get<I>(res) = std::get<I>(t).project(std::get<I>(vars.t));
            _project<I+1, Subs...>(res, vars);
        }
    }

public:

    ThSubs project(const VarSet &vars) const {
        ThSubs res;
        _project(res, vars);
        return ThSubs(res);
    }

private:

    template<std::size_t I = 0, typename... Subs>
    inline void _put(const TheTheorySubs::Pair &p) {
        if constexpr (I < sizeof...(Subs)) {
            if (std::holds_alternative<I>(p)) {
                const auto &[x,y] = std::get<I>(p);
                std::get<I>(t).put(x, y);
            } else {
                _put<I+1, Subs...>(p);
            }
        }
    }

public:

    void put(const TheTheorySubs::Pair &p) {
        _put(p);
    }

    ThSubs(){}

    ThSubs(typename TheTheorySubs::Pair &p) {
        put(p);
    }

private:

    template<std::size_t I = 0, typename... Subs>
    inline void _domain(VarSet &res) const {
        if constexpr (I < sizeof...(Subs)) {
            std::get<I>(res.t) = std::get<I>(t).domain();
            _domain<I+1, Subs...>(res);
        }
    }

public:

    VarSet domain() const {
        VarSet res;
        _domain(res);
        return res;
    }

private:

    template<class S, std::size_t I = 0, typename... Subs>
    inline S _subs(const S &s) const {
        if constexpr (I < sizeof...(Subs)) {
            if (std::holds_alternative<I>(s)) {
                return std::get<I>(s).subs(std::get<I>(t));
            } else {
                return _subs<I+1, Subs...>(s);
            }
        } else {
            return s;
        }
    }

public:

    template <class S>
    S subs(const S &s) const {
        return _subs(s);
    }

private:

    template<std::size_t I = 0, typename... Subs>
    inline void _collectVars(VarSet &res) const {
        if constexpr (I < sizeof...(Subs)) {
            std::get<I>(t).collectVariables(std::get<I>(res.t));
            _collectVars<I+1, Subs...>(res);
        }
    }

public:

    void collectVars(VarSet &vars) const {
        _collectVars(vars);
    }

private:

    template<std::size_t I = 0, typename... Subs>
    inline size_t _hash() const {
        if constexpr (I + 1 >= sizeof...(Subs)) {
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

    template<std::size_t I = 0, typename... Subs>
    inline Expr _get(const Var &var) const {
        if constexpr (I >= sizeof...(Subs)) {
            throw std::invalid_argument("variable not found");
        } else if (std::holds_alternative<I>(var)) {
            return std::get<I>(t).get(std::get<I>(var));
        } else {
            return _get<I+1, Subs...>(var);
        }
    }

public:

    Expr get(const Var &var) const {
        return _get(var);
    }

private:

    template<std::size_t I = 0, typename... Subs>
    inline void _compose(const ThSubs &that) {
        if constexpr (I < sizeof...(Subs)) {
            std::get<I>(t).compose(std::get<I>(that.t));
            _compose<I+1, Subs...>(that);
        }
    }

public:

    ThSubs compose(const ThSubs &that) const {
        ThSubs res(*this);
        res._compose(that);
        return res;
    }

private:

    template<std::size_t I = 0, typename... Subs>
    inline void _concat(const ThSubs &that) {
        if constexpr (I < sizeof...(Subs)) {
            std::get<I>(t).compose(std::get<I>(that.t));
            _concat<I+1, Subs...>(that);
        }
    }

public:

    ThSubs concat(const ThSubs &that) const {
        ThSubs res(*this);
        res._concat(that);
        return res;
    }

private:

    template<std::size_t I = 0, typename... Subs>
    inline bool _changes(const Var &x) const {
        if constexpr (I < sizeof...(Subs)) {
            if (std::holds_alternative<I>(x)) {
                return std::get<I>(t).changes(std::get<I>(x));
            } else {
                return _changes<I+1, Subs...>(x);
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

    template<std::size_t I = 0, typename... Subs>
    inline void _erase(const Var &x) {
        if constexpr (I < sizeof...(Subs)) {
            if (std::holds_alternative<I>(x)) {
                std::get<I>(t).erase(x);
            } else {
                _erase<I+1, Subs...>(x);
            }
        }
    }

public:

    void erase(const Var &x) {
        _erase(x);
    }

private:

    template<std::size_t I = 0, typename... Subs>
    inline void _print(std::ostream &s) const {
        if constexpr (I < sizeof...(Subs)) {
            s << std::get<I>(t);
            if constexpr (I + 1 < variant_size) {
                _print<I+1, Subs...>(s);
            }
        }
    }

public:

    void print(std::ostream &s) const {
        _print(s);
    }

private:

    template<std::size_t I = 0, typename... Subs>
    inline Iterator _find(const Var &var) const {
        if constexpr (I < sizeof...(Subs)) {
            if (std::holds_alternative<I>(var)) {
                const auto &subs = std::get<I>(t);
                const auto &it = subs.find(std::get<I>(var));
                if (it == subs.end()) {
                    return end();
                } else {
                    return it;
                }
            } else {
                return _find<I+1, Subs...>(var);
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

    int compare(const ThSubs &that) const {
        if (this->t == that.t) {
            return 0;
        } else if (this->t < that.t) {
            return -1;
        } else {
            return 1;
        }
    }

    template <ITheory Th>
    typename Th::Subs& get() {
        return std::get<typename Th::Subs>(t);
    }

    template <ITheory Th>
    const typename Th::Subs& get() const {
        return std::get<typename Th::Subs>(t);
    }

};

Lit operator!(const Lit &lit) {
    return std::visit([](const auto &lit){return Lit(!lit);}, lit);
};

std::ostream& operator<<(std::ostream &s, const Lit &lit) {
    std::visit([&s](const auto &lit){s << lit;}, lit);
    return s;
}

std::ostream& operator<<(std::ostream &s, const ThSubs &subs) {
    subs.print(s);
    return s;
}

bool operator==(const ThSubs &fst, const ThSubs &snd) {
    return fst.t == snd.t;
}

namespace Th {

Lit normalize(const Lit &lit) {
    return std::visit([](const auto &lit){
        return Lit(lit.normalize());
    }, lit);
}

std::string toRedlog(const Lit &lit) {
    return std::visit([](const auto &lit){
        return lit.toRedlog();
    }, lit);
}

unsigned hash(const Lit &lit) {
    return std::visit([](const auto &lit){
        return lit.hash();
    }, lit);
}

void getBounds(const Lit &lit, const Var &var, Bounds &bounds) {
    std::visit(Overload{
                   [&bounds](const Rel &lit, const NumVar &var){
                       lit.getBounds(var, bounds);
                   },
                   [](const auto &lit, const auto &var){}
               }, lit, var);
}

std::string getName(const Var &var) {
    return std::visit([](const auto &var){return var.get_name();}, var);
}

ThVar first(const ThSubs::Pair &p) {
    return std::visit([](const auto &p){return p.first;}, p);
}

ThExpr second(const ThSubs::Pair &p) {
    return std::visit([](const auto &p){return p.second;}, p);
}

VarSet vars(const Lit &lit) {
    VarSet res;
    res.collectVars(lit);
    return res;
}

bool operator ==(const ThExpr &e, const ThVar &var) {
    return std::visit([](const Expr &e, const NumVar &var) {return e.equals(var);}, e, var);
}

}
