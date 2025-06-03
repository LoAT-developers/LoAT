#pragma once

#include <memory>
#include <string>

#include "exprfwd.hpp"
#include "sexpresso.hpp"

template <theory::Type T, class S>
class TVar;

template <theory::Type T, class S>
using VarPtr = cpp::not_null<std::shared_ptr<const TVar<T, S>>>;

namespace theory {
template <Type T, class S>
VarPtr<T, S> mkVar(const int idx);
}

template <theory::Type T, class S>
class TVar: public S {

public:
    using ptr = VarPtr<T, S>;

    friend ptr theory::mkVar(const int idx);

private:

    static int last_prog_idx;
    static int last_tmp_idx;

    int idx;

    struct CacheEqual {

        bool operator()(const std::tuple<int> &args1, const std::tuple<int> &args2) const noexcept {
            return args1 == args2;
        }

    };

    struct CacheHash {

        size_t operator()(const std::tuple<int> &args) const noexcept {
            return std::hash<int>{}(std::get<0>(args));
        }

    };

    static ConsHash<TVar<T, S>, TVar<T, S>, CacheHash, CacheEqual, int> cache;

public:

    friend auto operator<=>(const TVar<T, S> &x, const TVar<T, S> &y) = default;
    friend bool operator==(const TVar<T, S> &x, const TVar<T, S> &y) = default;

    TVar(const int idx): idx(idx) {}

    ~TVar() {
        cache.erase(idx);
    }

    std::string getName() const {
        auto name {theory::abbrev(T)};
        if (idx > 0) {
            return name + std::to_string(idx);
        } else {
            return name + "t" + std::to_string(-idx);
        }
    }

    int getIdx() const {
        return idx;
    }

    static ptr next() {
        --last_tmp_idx;
        return theory::mkVar<T, S>(last_tmp_idx);
    }

    static ptr nextProgVar() {
        last_prog_idx += 2;
        return theory::mkVar<T, S>(last_prog_idx);
    }

    static ptr postVar(const ptr &var) {
        return theory::mkVar<T, S>(var->getIdx() + 1);
    }

    static ptr progVar(const ptr &var) {
        return theory::mkVar<T, S>(var->getIdx() - 1);
    }

    bool isTempVar() const {
        return idx < 0;
    }

    bool isProgVar() const {
        return idx > 0 && idx % 2 == 1;
    }

    bool isPostVar() const {
        return idx > 0 && idx % 2 == 0;
    }

    std::size_t hash() const {
        return std::hash<int>{}(idx);
    }

    sexpresso::Sexp to_smtlib() const {
        return sexpresso::Sexp(getName());
    }

};

template<theory::Type T, class S>
int TVar<T, S>::last_prog_idx {1};

template<theory::Type T, class S>
int TVar<T, S>::last_tmp_idx {0};

template<theory::Type T, class S>
ConsHash<TVar<T, S>, TVar<T, S>, typename TVar<T, S>::CacheHash, typename TVar<T, S>::CacheEqual, int> TVar<T, S>::cache {};

namespace theory {
    template <Type T, class S>
    VarPtr<T, S> mkVar(const int idx) {
        return TVar<T, S>::cache.from_cache(idx);
    }
}

template <theory::Type T, class S>
std::ostream& operator<<(std::ostream &s, const VarPtr<T, S> e) {
    return s << e->getName();
}

template<theory::Type T, class S>
struct std::hash<TVar<T, S>> {
    std::size_t operator()(const TVar<T, S>& x) const noexcept {
        return x.hash();
    }
};

template<theory::Type T, class S>
size_t hash_value(const TVar<T, S> &x) {
    return x.hash();
}
