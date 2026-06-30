#pragma once

#include <utility>

#include "chcmodel.hpp"

class LoatModel {
    CHCModel m_model;

public:
    explicit LoatModel(CHCModel model) : m_model(std::move(model)) {}

    const CHCModel &raw() const {
        return m_model;
    }

    friend std::ostream &operator<<(std::ostream &os, const LoatModel &model) {
        return os << model.m_model;
    }
};
