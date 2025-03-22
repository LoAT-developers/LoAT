#pragma once

#include "loatconfig.hpp"
#include "dynamicparameters.hpp"
#include <any>

class LoatSolver
{
private:
    LoatConfig config;

public:
    // Constructor for LoatSolver
    // Takes a LoatConfig object as parameter.
    // Stores it internally (copied/moved into the solver).
    // Immediately applies the configuration to the global Config namespace,
    LoatSolver(LoatConfig cfg)
        : config(std::move(cfg))
    {
        config.applyToGlobalConfig();
    }

    // Modify runtime parameter (DynamicConfig) by enum key and value
    void setParameter(DynamicParameterKey key, const std::any &value);

    // Optional: Re-apply dynamic config after updates (if needed)
    void refreshConfig();
};