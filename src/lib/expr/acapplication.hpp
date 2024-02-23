#pragma once

#include "numexpression.hpp"

class ACApplication: public Expr {

protected:

    linked_hash_set<ExprPtr> args;

public:

    bool isPoly() const override;
    void collectVars(linked_hash_set<NumVarPtr> &res) const override;
    bool hasVarWith(const std::function<bool(const NumVarPtr)> predicate) const override;
    Int denomLcm() const override;
    std::optional<Int> isInt() const override;
    std::optional<Rational> isRational() const override;
    std::optional<NumVarPtr> isVar() const override;
    std::optional<std::pair<ExprPtr, ExprPtr>> isPow() const override;
    bool isPoly(const NumVarPtr n) const override;
    std::optional<NumVarPtr> someVar() const override;

protected:

    ACApplication(const linked_hash_set<ExprPtr> &args);
    bool isUnivariate(std::optional<NumVarPtr> &) const override;
    bool isNotMultivariate(std::optional<NumVarPtr> &) const override;
    bool isMultivariate(std::optional<NumVarPtr> &) const override;

};
