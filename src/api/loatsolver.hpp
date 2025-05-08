#pragma once

#include "loattransition.hpp"
#include "loatlocation.hpp"
#include "itsproblem.hpp"
#include "loattransitiontoitsconverter.hpp"
#include "loatconfig.hpp"
#include <any>
#include <vector>

class LoatSolver
{
private:
    LoatConfig m_config;
    std::vector<LoatTransition> m_transitions;
    LoatTransitionToITSConverter m_converter;
    ITSPtr m_its;

    LoatLocation m_start;
    LoatLocation m_sink;

public:
    // Constructor for LoatSolver
    // Takes a LoatConfig object as parameter.
    // Stores it internally (copied/moved into the solver).
    // Immediately applies the configuration to the global Config namespace,
    LoatSolver(const LoatConfig &config)
        : m_config(config)
    {
        m_config.applyToGlobalConfig();
    }

    // Getter for internal config (read-only)
    const LoatConfig &getConfig() const { return m_config; }

    // Modify runtime parameter (DynamicConfig) by enum key and value
    void setParameter(DynamicParameterKey key, const std::any &value);

    // Optional: Re-apply dynamic config after updates (if needed)
    void refreshConfig();

    // Adds a transition to the solver.
    void add(const LoatTransition &transition);

    void setStartLocation(const LoatLocation &location);

    bool isStartLocation(const LoatLocation &location) const;

    void addSinkLocation(const LoatLocation &location);

    bool isSinkLocation(const LoatLocation &location) const;
};