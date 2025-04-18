#pragma once

#include "loatintexpr.hpp"

#include <memory>
#include <unordered_map>

/**
 * Represents a substitution from integer variables to integer expressions. (e.g., x := x + 1)
 */
class LoatIntSubs
{
private:
    std::unordered_map<LoatIntExprPtr, LoatIntExprPtr> m_subsmap;

public:
    LoatIntSubs() = default;

    explicit LoatIntSubs(const std::unordered_map<LoatIntExprPtr, LoatIntExprPtr> &subsmap);

    void put(const LoatIntExprPtr &var, const LoatIntExprPtr &expr);

    const std::unordered_map<LoatIntExprPtr, LoatIntExprPtr> &getSubsMap() const;

    auto begin() const { return m_subsmap.begin(); }
    auto end() const { return m_subsmap.end(); }

    friend std::ostream &operator<<(std::ostream &os, const LoatIntSubs &subs);
};

std::ostream &operator<<(std::ostream &os, const LoatIntSubs &subs);