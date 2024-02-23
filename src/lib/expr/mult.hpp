#pragma once

#include "acapplication.hpp"
#include "conshash.hpp"

class Mult: public ACApplication {

    friend ExprPtr num_expression::buildTimes(std::vector<ExprPtr> args);

private:

    struct CacheEqual {

        bool operator()(const std::tuple<linked_hash_set<ExprPtr>> &args1, const std::tuple<linked_hash_set<ExprPtr>> &args2) const noexcept;

    };

    struct CacheHash {

        size_t operator()(const std::tuple<linked_hash_set<ExprPtr>> &args) const noexcept;

    };

    friend ConsHash<Expr, Mult, CacheHash, CacheEqual, linked_hash_set<ExprPtr>>;

    static ConsHash<Expr, Mult, CacheHash, CacheEqual, linked_hash_set<ExprPtr>> cache;

    Mult(const linked_hash_set<ExprPtr> &args);

public:

    bool isLinear(const std::optional<linked_hash_set<NumVarPtr>> &vars) const override;
    std::optional<Int> totalDegree() const override;
    std::optional<Int> degree(const NumVarPtr var) const override;
    const linked_hash_set<ExprPtr>* isMul() const override;
    const linked_hash_set<ExprPtr>* isAdd() const override;
    bool isIntegral() const override;
    Rational eval(const std::function<Rational(const NumVarPtr)> &valuation) const override;
    std::optional<ExprPtr> coeff(const NumVarPtr var, const Int &degree = 1) const override;
    std::optional<ExprPtr> lcoeff(const NumVarPtr var) const override;
    Purrs::Expr toPurrs(purrs_var_map &) const override;

protected:

    std::pair<Rational, std::optional<ExprPtr>> decompose() const override;

};
