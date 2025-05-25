#pragma once

#include "loattransition.hpp"
#include "loatlocation.hpp"
#include "itsproblem.hpp"
#include "loattransitiontoitsconverter.hpp"
#include "loatconfig.hpp"
#include "loatresult.hpp"
#include "optional.hpp"
#include "loatmodel.hpp"
#include "loatcex.hpp"

#include <any>
#include <vector>

class LoatSolver
{
private:
    LoatConfig m_config;
    std::vector<LoatTransition> m_transitions;
    LoatTransitionToITSConverter m_converter;
    ITSPtr m_its;

    std::optional<LoatLocation> m_start;
    std::optional<LoatLocation> m_sink;

    std::optional<LoatModel> m_its_model;
    std::optional<LoatCex> m_its_cex;

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

    // Adds a transition to the solver.
    void add(const LoatTransition &transition);

    // Sets the start location of the Transition System
    void setStartLocation(const LoatLocation &location);

    // Sets the end location of the Transition System
    void addSinkLocation(const LoatLocation &location);

    // Applies the Loop Acceleration Tool to find the desired output (model/ctx/..).
    // Returns true if found the desired output successfully
    LoatResult check();

    // Returns the Model, if proof is activated in the initial config and the selected engine supports a model
    LoatModel getModel();

    // Returns the Cex, if proof is activated in the initial config and the selected engine supports a cex
    LoatCex getCex();

    // Returns a solver to proof termination
    static LoatSolver forTermination()
    {
        LoatConfig::InitialConfig init(
            LoatConfig::InitialConfig::Engine::TRL,
            LoatConfig::InitialConfig::Mode::Termination,
            LoatConfig::InitialConfig::SmtSolver::Z3,
            LoatConfig::InitialConfig::Direction::Forward,
            LoatConfig::InitialConfig::MbpKind::IntMbp,
            false // proof
        );
        return LoatSolver(LoatConfig(init));
    }

    // Returns a solver to proof non termination
    static LoatSolver forNonTermination()
    {
        LoatConfig::InitialConfig init(
            LoatConfig::InitialConfig::Engine::ADCL,
            LoatConfig::InitialConfig::Mode::Termination,
            LoatConfig::InitialConfig::SmtSolver::Z3,
            LoatConfig::InitialConfig::Direction::Forward,
            LoatConfig::InitialConfig::MbpKind::IntMbp,
            false);
        return LoatSolver(LoatConfig(init));
    }

    // Returns a solver to proof safety
    static LoatSolver forSafety()
    {
        LoatConfig::InitialConfig init(
            LoatConfig::InitialConfig::Engine::ABMC,
            LoatConfig::InitialConfig::Mode::Safety,
            LoatConfig::InitialConfig::SmtSolver::Z3,
            LoatConfig::InitialConfig::Direction::Forward,
            LoatConfig::InitialConfig::MbpKind::IntMbp,
            false);
        return LoatSolver(LoatConfig(init));
    }

    // Returns a solver to proof unsafety
    static LoatSolver forUnsafety()
    {
        LoatConfig::InitialConfig init(
            LoatConfig::InitialConfig::Engine::BMC,
            LoatConfig::InitialConfig::Mode::Safety,
            LoatConfig::InitialConfig::SmtSolver::Z3,
            LoatConfig::InitialConfig::Direction::Forward,
            LoatConfig::InitialConfig::MbpKind::IntMbp,
            false);
        return LoatSolver(LoatConfig(init));
    }

private:
    // Re-applys dynamic config after updates (if needed)
    void refreshConfig();

    // Creates an its with the given members of the class
    void produceITS();
};