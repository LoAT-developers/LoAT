#include "acapplication.hpp"

ACApplication::ACApplication(const linked_hash_set<ExprPtr> &args): args(args) {}

bool ACApplication::isPoly() const {
    return std::all_of(args.begin(), args.end(), [](const auto &arg) -> bool {
        return arg->isPoly();
    });
}

void ACApplication::collectVars(linked_hash_set<NumVarPtr> &res) const {
    for (const auto &arg: args) {
        arg->collectVars(res);
    }
}

bool ACApplication::hasVarWith(const std::function<bool(const NumVarPtr)> predicate) const {
    return std::any_of(args.begin(), args.end(), [&predicate](const auto &arg) -> bool {
        return arg->hasVarWith(predicate);
    });
}

Int ACApplication::denomLcm() const {
    Int res {1};
    for (const auto &arg: args) {
        res *= arg->denomLcm();
    }
    return res;
}

std::optional<Int> ACApplication::isInt() const {
    return {};
}

std::optional<Rational> ACApplication::isRational() const {
    return {};
}

std::optional<NumVarPtr> ACApplication::isVar() const {
    return {};
}

std::optional<std::pair<ExprPtr, ExprPtr>> ACApplication::isPow() const {
    return {};
}

bool ACApplication::isPoly(const NumVarPtr n) const {
    return std::all_of(args.begin(), args.end(), [&n](const auto &arg) -> bool {
        return arg->isPoly(n);
    });
}

std::optional<NumVarPtr> ACApplication::someVar() const {
    for (const auto &arg: args) {
        const auto res {arg->someVar()};
        if (res) {
            return res;
        }
    }
    return {};
}

bool ACApplication::isUnivariate(std::optional<NumVarPtr> &x) const {
    return std::all_of(args.begin(), args.end(), [&x](const auto &arg) -> bool {
        return arg->isUnivariate(x);
    });
}

bool ACApplication::isNotMultivariate(std::optional<NumVarPtr> &x) const {
    return std::all_of(args.begin(), args.end(), [&x](const auto &arg) -> bool {
        return arg->isNotMultivariate(x);
    });
}

bool ACApplication::isMultivariate(std::optional<NumVarPtr> &x) const {
    return std::any_of(args.begin(), args.end(), [&x](const auto &arg) -> bool {
        return arg->isMultivariate(x);
    });
}
