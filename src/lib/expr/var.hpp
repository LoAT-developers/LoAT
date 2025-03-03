#pragma once

#include <memory>
#include <string>
#include <boost/functional/hash.hpp>

#include "exprfwd.hpp"
#include "sexpresso.hpp"
#include "arraytype.hpp"

template <theory::Type T, class S>
class TVar;

template <theory::Type T, class S>
using VarPtr = cpp::not_null<std::shared_ptr<const TVar<T, S>>>;

namespace theory {
template <Type T, class S>
VarPtr<T, S> mkVar(const int idx, const unsigned dimension);
}

template <theory::Type T, class S>
class TVar: public S {

public:
    using ptr = VarPtr<T, S>;

    friend ptr theory::mkVar(const int idx, const unsigned dimension);

private:

    static int last_prog_idx;
    static int last_tmp_idx;

    int idx;
    unsigned dimension;

    struct CacheEqual {

        bool operator()(const std::tuple<int, unsigned> &args1, const std::tuple<int, unsigned> &args2) const noexcept {
            return std::get<int>(args1) == std::get<int>(args2);
        }

    };

    struct CacheHash {

        size_t operator()(const std::tuple<int, unsigned> &args) const noexcept {
            return std::hash<int>()(std::get<int>(args));
        }

    };

    static ConsHash<TVar<T, S>, TVar<T, S>, CacheHash, CacheEqual, int, unsigned> cache;

public:

    friend auto operator<=>(const TVar<T, S> &x, const TVar<T, S> &y) {
        return x.idx <=> y.idx;
    }

    friend bool operator==(const TVar<T, S> &x, const TVar<T, S> &y) {
        return x.idx == y.idx;
    }

    TVar(const int idx, const unsigned dimension): idx(idx), dimension(dimension) {}

    ~TVar() {
        cache.erase(idx, dimension);
    }

    std::string getName() const {
        auto res {theory::abbreviate(T)};
        if (idx > 0) {
            res += std::to_string(idx);
        } else {
            res += "t" + std::to_string(-idx);
        }
        for (unsigned i = 0; i < dimension; ++i) {
            res += "[]";
        }
        return res;
    }

    int getIdx() const {
        return idx;
    }

    unsigned getDimension() const {
        return dimension;
    }

    static ptr next(const unsigned dimension) {
        --last_tmp_idx;
        return theory::mkVar<T, S>(last_tmp_idx, dimension);
    }

    static ptr nextProgVar(const unsigned dimension) {
        last_prog_idx += 2;
        return theory::mkVar<T, S>(last_prog_idx, dimension);
    }

    ptr postVar() const {
        return theory::mkVar<T, S>(idx + 1, dimension);
    }

    ptr progVar() const {
        return theory::mkVar<T, S>(idx - 1, dimension);
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
        return std::hash<int>()(idx);
    }

    sexpresso::Sexp to_smtlib() const {
        return sexpresso::Sexp(getName());
    }

    ArrayType get_type() const {
        return ArrayType(T, dimension);
    }

};

template<theory::Type T, class S>
int TVar<T, S>::last_prog_idx {1};

template<theory::Type T, class S>
int TVar<T, S>::last_tmp_idx {0};

template<theory::Type T, class S>
ConsHash<TVar<T, S>, TVar<T, S>, typename TVar<T, S>::CacheHash, typename TVar<T, S>::CacheEqual, int, unsigned> TVar<T, S>::cache {};

namespace theory {
    template <Type T, class S>
    VarPtr<T, S> mkVar(const int idx, const unsigned d) {
        return TVar<T, S>::cache.from_cache(idx, d);
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
