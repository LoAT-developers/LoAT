#pragma once

#include "itsmodel.hpp"
#include "boolexpr.hpp"

class LoatModel
{
private:
    ITSModel m_model;

public:
    explicit LoatModel(const ITSModel &model) : m_model(model) {}

    Bools::Expr getInvariant(LocationIdx loc) const
    {
        return m_model.get_invariant(loc);
    }

    const ITSModel &raw() const
    {
        return m_model;
    }

    friend std::ostream &operator<<(std::ostream &os, const LoatModel &model)
    {
        return os << model.m_model;
    }
};