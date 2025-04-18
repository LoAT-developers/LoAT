#pragma once

#include "loatintsubs.hpp"
#include "loatboolsubs.hpp"
#include "loatintexpr.hpp"
#include "loatboolexpr.hpp"

/**
 * Represents a combined substitution over both integer and boolean variables.
 */
class LoatSubs
{
private:
    LoatIntSubs intSubs;
    LoatBoolSubs boolSubs;

public:
    LoatSubs() = default;

    void put(const LoatIntExprPtr &var, const LoatIntExprPtr &expr);
    void put(const LoatBoolExprPtr &var, const LoatBoolExprPtr &expr);

    const LoatIntSubs &getIntSubs() const;
    const LoatBoolSubs &getBoolSubs() const;

    friend std::ostream &operator<<(std::ostream &os, const LoatSubs &subs);
};

std::ostream &operator<<(std::ostream &os, const LoatSubs &subs);