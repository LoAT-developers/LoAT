#pragma once

#include <vector>
#include <string>
#include <any>
#include <stdexcept>

// List of immutable initial configuration options
enum class InitialParameterKey
{
    Engine,
    Mode,
    SmtSolver,
    Direction,
    MbpKind,
    Model
};

// List of tunable runtime parameters (only from DynamicConfig)
enum class DynamicParameterKey
{
    Log,
    LogAccel,
    LogPreproc,
    PrintDependencyGraph,
    BlockingClauses,
    TRP_RecurrentCycles,
    TRP_RecurrentExps,
    TRP_RecurrentPseudoDivs,
    TRP_RecurrentPseudoBounds,
    TRP_RecurrentBounds
};

// LoatConfig encapsulates configuration in two parts:
// 1. InitialConfig: fixed at construction, cannot change after the solver was instanciated
// 2. DynamicConfig: can be modified after the solver was instanciated
class LoatConfig
{
public:
    // Immutable configuration defined at solver construction time
    class InitialConfig
    {
    public:
        // The core engine used for solving – tightly coupled with internal setup.
        // Cannot be switched on the fly without reinitializing solver components.
        enum Engine
        {
            ADCL,
            BMC,
            ABMC,
            TRL,
            KIND,
            ADCLSAT
        };

        // Mode determines what kind of problem we're solving (e.g., termination).
        // Cant be changed later, because we might need a different tool then.
        enum Mode
        {
            Termination,
            Safety
        };

        // The SMT solver backend is chosen once and affects all results.
        enum SmtSolver
        {
            Z3,
            CVC5,
            Swine,
            Yices,
            Heuristic
        };

        // Direction of analysis (at the moment only forward available)
        enum Direction
        {
            Forward
        };

        // Solver-level tuning parameter.
        enum MbpKind
        {
            LowerIntMbp,
            UpperIntMbp,
            IntMbp,
            RealMbp,
            RealQe
        };

        // Constructor
        InitialConfig(Engine engine, Mode mode,
                      SmtSolver solver, Direction direction,
                      MbpKind mbp, bool model)
            : m_engine(engine), m_mode(mode),
              m_solver(solver), m_direction(direction),
              m_mbpKind(mbp), m_model(model)
        {
            // Validate (engine, mode) combinations
            const bool terminationSupported = engine == ADCL || engine == ABMC || engine == TRL;

            const bool safetySupported = true;

            switch (mode)
            {
            case Termination:
                if (!terminationSupported)
                {
                    throw std::invalid_argument(
                        "Invalid configuration: Termination is only supported with engines: ADCL, ABMC, TRL.");
                }
                break;
            case Safety:
                if (!safetySupported)
                {
                    throw std::invalid_argument(
                        "Invalid configuration: Saftey is only supported with engines: ADCL, ABMC, ADCLSAT, BMC, TRL, KIND.");
                }
                break;

            default:
                throw std::invalid_argument("Unknown analysis mode.");
            }
        }

        // Getter
        std::any get(InitialParameterKey key) const;

    private:
        Engine m_engine;
        Mode m_mode;
        SmtSolver m_solver;
        Direction m_direction;
        MbpKind m_mbpKind;
        bool m_model;
    };

    // Mutable configuration that has default values
    class DynamicConfig
    {
    public:
        // Constructor
        DynamicConfig() = default;

        // Getter for dynamic parameter
        std::any get(DynamicParameterKey key) const;

        // Setter for dynamic parameter
        void set(DynamicParameterKey key, const std::any &value);

    private:
        // Logging options. Can be toggled. Default value is false
        bool m_log = false;
        bool m_logAccel = false;
        bool m_logPreproc = false;

        // Should the dependency graph be printed to output? Default value is false.
        bool m_printDependencyGraph = false;

        // Configuration for Transition Relation Partitioning (TRP)
        struct TRPConfig
        {
            // Options controlling which recurrence patterns to use.
            // Can be enabled/disabled dynamically during analysis.
            bool m_recurrent_cycles = false;
            bool m_recurrent_exps = true;
            bool m_recurrent_pseudo_divs = true;
            bool m_recurrent_pseudo_bounds = true;
            bool m_recurrent_bounds = true;
        } m_trp;

        // ABMC-specific option – whether to use blocking clauses.
        bool m_blocking_clauses = false;
    };

private:
    // Initial config is fixed (immutable) once constructed
    const InitialConfig m_initial;

    // Dynamic config can be modified
    DynamicConfig m_dynamic;

public:
    // Constructors
    LoatConfig(const InitialConfig &init);
    LoatConfig(const InitialConfig &init, const DynamicConfig &dyn);

    // Read only access to configuration
    const InitialConfig &getInitial() const;
    const DynamicConfig &getDynamic() const;

    // Write access to configuration
    DynamicConfig &getDynamic();

    // Apply this configuration to the global Config:: namespace
    void applyToGlobalConfig() const;
};