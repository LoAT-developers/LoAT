#pragma once

#include <string>
#include <ostream>
#include "loatlocation.hpp"
#include "loatboolexpr.hpp"

class LoatTransition
{
private:
    LoatLocation m_sourceLocation;
    LoatLocation m_targetLocation;
    LoatBoolExprPtr m_formula;

public:
    LoatTransition(const LoatLocation &source, const LoatLocation &target, const LoatBoolExprPtr &formula)
        : m_sourceLocation(source), m_targetLocation(target), m_formula(formula) {}

    const LoatLocation &getSourceLocation() const { return m_sourceLocation; }
    const LoatLocation &getTargetLocation() const { return m_targetLocation; }
    const LoatBoolExprPtr &getFormula() const { return m_formula; }

    friend std::ostream &operator<<(std::ostream &os, const LoatTransition &t)
    {
        os << t.m_sourceLocation << " -> " << t.m_targetLocation << " [" << t.m_formula << "]";
        return os;
    }
};