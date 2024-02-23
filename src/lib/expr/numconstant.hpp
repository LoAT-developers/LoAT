#pragma once

#include "numexpression.hpp"
#include "conshash.hpp"

class NumConstant: public Expr {

    friend ExprPtr num_expression::buildConstant(const Rational &r);

private:

    NumConstant(const Rational &t);

    Rational t;

    struct CacheEqual {

        bool operator()(const std::tuple<Rational> &args1, const std::tuple<Rational> &args2) const noexcept;

    };

    struct CacheHash {

        size_t operator()(const std::tuple<Rational> &args) const noexcept;

    };

    friend ConsHash<Expr, NumConstant, CacheHash, CacheEqual, Rational>;

    static ConsHash<Expr, NumConstant, CacheHash, CacheEqual, Rational> cache;

public:

    bool isLinear(const std::optional<linked_hash_set<NumVarPtr>> &vars) const override;
    bool isPoly() const override;
    std::optional<Int> totalDegree() const override;
    void collectVars(linked_hash_set<NumVarPtr> &res) const override;
    bool hasVarWith(const std::function<bool(const NumVarPtr)> predicate) const override;
    std::optional<Int> degree(const NumVarPtr var) const override;
    Int denomLcm() const override;
    std::optional<Int> isInt() const override;
    std::optional<Rational> isRational() const override;
    std::optional<NumVarPtr> isVar() const override;
    std::optional<std::pair<ExprPtr, ExprPtr>> isPow() const override;
    const linked_hash_set<ExprPtr>* isMul() const override;
    const linked_hash_set<ExprPtr>* isAdd() const override;
    bool isPoly(const NumVarPtr n) const override;
    std::optional<NumVarPtr> someVar() const override;
    std::optional<ExprPtr> coeff(const NumVarPtr var, const Int &degree = 1) const override;
    std::optional<ExprPtr> lcoeff(const NumVarPtr var) const override;
    bool isIntegral() const override;
    Rational eval(const std::function<Rational(const NumVarPtr)> &valuation) const override;
    Purrs::Expr toPurrs(purrs_var_map &) const override;

protected:

    bool isUnivariate(std::optional<NumVarPtr> &) const override;
    bool isNotMultivariate(std::optional<NumVarPtr> &) const override;
    bool isMultivariate(std::optional<NumVarPtr> &) const override;
    std::pair<Rational, std::optional<ExprPtr>> decompose() const override;

};
