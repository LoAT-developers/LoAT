#pragma once

#include <optional>

#include "linkedhashset.hpp"
#include "string.hpp"
#include "conshash.hpp"
#include "exprfwd.hpp"

class ArithConst;
class ArithExp;
class ArithAdd;
class ArithMult;
class ArithMod;

using ArithExprPtr = cpp::not_null<std::shared_ptr<const ArithExpr>>;
using ArithVarPtr = cpp::not_null<std::shared_ptr<const ArithVar>>;
using ArithConstPtr = cpp::not_null<std::shared_ptr<const ArithConst>>;
using ArithAddPtr = cpp::not_null<std::shared_ptr<const ArithAdd>>;
using ArithMultPtr = cpp::not_null<std::shared_ptr<const ArithMult>>;
using ArithModPtr = cpp::not_null<std::shared_ptr<const ArithMod>>;
using ArithExpPtr = cpp::not_null<std::shared_ptr<const ArithExp>>;
using ArithExprSet = linked_hash_set<ArithExprPtr>;
using ArithExprVec = std::vector<ArithExprPtr>;

namespace arith {

ArithExprPtr mkPlusImpl(ArithExprVec &&args);
ArithExprPtr mkPlus(ArithExprVec &&args);
ArithExprPtr mkPlus(ArithExprPtr, ArithExprPtr);
ArithExprPtr mkTimesImpl(ArithExprVec &&args);
ArithExprPtr mkTimes(ArithExprVec &&args);
ArithExprPtr mkTimes(const ArithExprPtr, const ArithExprPtr);
ArithExprPtr mkMod(ArithExprPtr x, ArithExprPtr y);
ArithExprPtr mkConst(const Rational &r);
ArithExprPtr mkConst(const Rational &&r);
ArithExprPtr mkExp(const ArithExprPtr base, const ArithExprPtr exponent);

enum class Kind {
    Plus, Times, Mod, Exp, Constant, Variable
};

}

class ArithExpr: public std::enable_shared_from_this<ArithExpr> {

    friend class ArithExp;
    friend ArithExprPtr arith::mkPlusImpl(ArithExprVec &&args);
    friend ArithExprPtr arith::mkTimesImpl(ArithExprVec &&args);

protected:

    ArithExpr(const arith::Kind kind);
    ArithExpr();

private:

    arith::Kind kind;

    /**
     * @return [a,b] s.t. a*b = *this
     */
    std::pair<Rational, std::optional<ArithExprPtr>> decompose() const;

public:

    template <class T>
    T apply(const std::function<T(const ArithConstPtr)> &constant,
          const std::function<T(const ArithVarPtr)> &var,
          const std::function<T(const ArithAddPtr)> &add,
          const std::function<T(const ArithMultPtr)> &mult,
          const std::function<T(const ArithModPtr)> &mod,
          const std::function<T(const ArithExpPtr)> &exp) const {
        const auto c {isRational()};
        if (c) {
            return constant(*c);
        }
        const auto v {isVar()};
        if (v) {
            return var(*v);
        }
        const auto a {isAdd()};
        if (a) {
            return add(*a);
        }
        const auto m {isMult()};
        if (m) {
            return mult(*m);
        }
        const auto mo {isMod()};
        if (mo) {
            return mod(*mo);
        }
        const auto e {isPow()};
        if (e) {
            return exp(*e);
        }
        throw std::invalid_argument("unknown expression" + toString(this->shared_from_this()));
    }

    /**
     * @return True iff this is a variable.
     */
    std::optional<ArithVarPtr> isVar() const;

    /**
     * @return True iff this is of the form x^y for some expressions x, y.
     */
    std::optional<ArithExpPtr> isPow() const;

    /**
     * @return True iff this is of the form x*y for some expressions x, y.
     */
    const std::optional<ArithMultPtr> isMult() const;

    const std::optional<ArithModPtr> isMod() const;

    /**
     * @return True iff this is of the form x+y for some expressions x, y.
     */
    const std::optional<ArithAddPtr> isAdd() const;

    /**
     * @return The set of all variables that occur in this expression.
     */
    linked_hash_set<ArithVarPtr> vars() const;

    bool isNegated() const;

    bool is(const Rational &val) const;

    /**
     * @return The highest degree of any variable in this expression.
     */
    std::optional<Int> maxDegree() const;

    /**
     * @return True iff the expression contains the given variable.
     */
    bool has(const ArithVarPtr) const;

    ArithExprPtr divide(const Rational &d) const;

    /**
     * @return True iff this expression is a linear polynomial wrt. the given variables (resp. all variables, if vars is empty).
     */
    bool isLinear(const std::optional<linked_hash_set<ArithVarPtr>> &vars = std::nullopt) const;

    std::optional<Int> isPoly() const;

    /**
     * @brief Collects all variables that occur in this expression.
     */
    void collectVars(linked_hash_set<ArithVarPtr> &res) const;

    /**
     * @return True iff this expression contains a variable that satisfies the given predicate.
     * @param A function of type `const Var & => bool`.
     */
    bool hasVarWith(const std::function<bool(const ArithVarPtr)> predicate) const;

    std::optional<ArithConstPtr> isRational() const;

    /**
     * @return True iff this expression is an integer value (and thus a constant).
     */
    std::optional<Int> isInt() const;

    Int denomLcm() const;

    Rational getConstantFactor() const;

    Rational getConstantAddend() const;

    /**
     * @return True iff this is a polynomial wrt. the given variable.
     */
    std::optional<Int> isPoly(const ArithVarPtr n) const;

    std::optional<ArithVarPtr> someVar() const;

    /**
     * @return The coefficient of the monomial where var occurs with the given degree (which defaults to 1).
     */
    std::optional<ArithExprPtr> coeff(const ArithVarPtr var, const Int &degree = 1) const;

    /**
     * @return The coefficient of the monomial whose degree wrt. var is minimal.
     */
    std::optional<ArithExprPtr> lcoeff(const ArithVarPtr var) const;

    bool isIntegral() const;

    Rational evalToRational(const linked_hash_map<ArithVarPtr, Int> &valuation) const;

    Int eval(const linked_hash_map<ArithVarPtr, Int> &valuation) const;

    std::optional<ArithExprPtr> solve(const ArithVarPtr var) const;

    ArithExprPtr toPtr() const;

    sexpresso::Sexp to_smtlib() const;

    ArithExprPtr renameVars(const arith_var_map &map) const;

    /**
     * @brief exponentiation
     */
    friend ArithExprPtr operator^(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithExprPtr operator-(const ArithExprPtr x);
    friend ArithExprPtr operator-(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithExprPtr operator+(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithExprPtr operator*(const ArithExprPtr x, const ArithExprPtr y);

};

std::size_t hash_value(const ArithExprPtr&);
std::size_t hash_value(const ArithVarPtr&);

class ArithConst: public ArithExpr {

    friend ArithExprPtr arith::mkConst(const Rational &r);
    friend ArithExprPtr arith::mkConst(const Rational &&r);
    friend class ArithExpr;

public:
    ArithConst(const Rational &t);
    ~ArithConst();

private:
    Rational t;

    struct CacheEqual {
        bool operator()(const std::tuple<Rational> &args1, const std::tuple<Rational> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<Rational> &args) const noexcept;
    };
    static ConsHash<ArithExpr, ArithConst, CacheHash, CacheEqual, Rational> cache;

public:

    const Rational& operator*() const;
    const Rational& getValue() const;
    const ArithConstPtr numerator() const;
    const ArithConstPtr denominator() const;
    std::optional<Int> intValue() const;

};

std::ostream& operator<<(std::ostream &s, const ArithVarPtr x);


class ArithAdd: public ArithExpr {

    friend ArithExprPtr arith::mkPlusImpl(ArithExprVec &&args);
    friend ArithExprPtr arith::mkPlus(ArithExprPtr, ArithExprPtr);
    friend ArithExprPtr arith::mkTimes(ArithExprPtr, ArithExprPtr);
    friend class ArithExpr;

public:

    const ArithExprSet& getArgs() const;

private:

    ArithExprSet args;

    struct CacheEqual {
        bool operator()(const std::tuple<ArithExprSet> &args1, const std::tuple<ArithExprSet> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<ArithExprSet> &args) const noexcept;
    };
    static ConsHash<ArithExpr, ArithAdd, CacheHash, CacheEqual, ArithExprSet> cache;

public:
    ArithAdd(const ArithExprSet &args);
    ~ArithAdd();

};


class ArithMult: public ArithExpr {

    friend ArithExprPtr arith::mkTimesImpl(ArithExprVec &&args);
    friend ArithExprPtr arith::mkTimes(ArithExprPtr, ArithExprPtr);
    friend class ArithExpr;

public:

    const ArithExprSet& getArgs() const;

private:

    ArithExprSet args;

    struct CacheEqual {
        bool operator()(const std::tuple<ArithExprSet> &args1, const std::tuple<ArithExprSet> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<ArithExprSet> &args) const noexcept;
    };
    static ConsHash<ArithExpr, ArithMult, CacheHash, CacheEqual, ArithExprSet> cache;

public:
    ArithMult(const ArithExprSet &args);
    ~ArithMult();

};

class ArithMod: public ArithExpr {

    friend ArithExprPtr arith::mkMod(ArithExprPtr x, ArithExprPtr y);
    friend class ArithExpr;

public:

    const ArithExprPtr getLhs() const;
    const ArithExprPtr getRhs() const;

private:

    ArithExprPtr lhs;
    ArithExprPtr rhs;

    struct CacheEqual {
        bool operator()(const std::tuple<ArithExprPtr, ArithExprPtr> &args1, const std::tuple<ArithExprPtr, ArithExprPtr> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<ArithExprPtr, ArithExprPtr> &args) const noexcept;
    };
    static ConsHash<ArithExpr, ArithMod, CacheHash, CacheEqual, ArithExprPtr, ArithExprPtr> cache;

public:
    ArithMod(const ArithExprPtr, const ArithExprPtr);
    ~ArithMod();

};


class ArithExp: public ArithExpr {

    friend ArithExprPtr arith::mkExp(const ArithExprPtr base, const ArithExprPtr exponent);
    friend class ArithExpr;

private:

    ArithExprPtr base;
    ArithExprPtr exponent;

public:
    ArithExp(const ArithExprPtr base, const ArithExprPtr exponent);
    ~ArithExp();

private:
    struct CacheEqual {
        bool operator()(const std::tuple<ArithExprPtr, ArithExprPtr> &args1, const std::tuple<ArithExprPtr, ArithExprPtr> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<ArithExprPtr, ArithExprPtr> &args) const noexcept;
    };
    static ConsHash<ArithExpr, ArithExp, CacheHash, CacheEqual, ArithExprPtr, ArithExprPtr> cache;

public:

    ArithExprPtr getBase() const;
    ArithExprPtr getExponent() const;

};

namespace arith {
ArithExprPtr toExpr(const ArithVarPtr&);
}

std::ostream& operator<<(std::ostream &s, const ArithExprPtr e);
std::ostream& operator<<(std::ostream &s, const ArithVarPtr e);
