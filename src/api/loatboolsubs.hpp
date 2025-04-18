#pragma once

#include "loatboolexpr.hpp"

#include <memory>
#include <unordered_map>

/**
 * Represents a substitution from boolean variables to boolean expressions.
 */
class LoatBoolSubs
{
private:
    std::unordered_map<LoatBoolExprPtr, LoatBoolExprPtr> m_subsmap;

public:
    LoatBoolSubs() = default;

    explicit LoatBoolSubs(const std::unordered_map<LoatBoolExprPtr, LoatBoolExprPtr> &subsmap);

    void put(const LoatBoolExprPtr &var, const LoatBoolExprPtr &expr);

    const std::unordered_map<LoatBoolExprPtr, LoatBoolExprPtr> &getSubsMap() const;

    auto begin() const { return m_subsmap.begin(); }
    auto end() const { return m_subsmap.end(); }

    friend std::ostream &operator<<(std::ostream &os, const LoatBoolSubs &subs);
};

std::ostream &operator<<(std::ostream &os, const LoatBoolSubs &subs);