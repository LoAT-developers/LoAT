#pragma once

#include <vector>
#include <string>

// LoatConfig encapsulates configuration in two parts:
// 1. InitialConfig: fixed at construction, cannot change after the solver was instanciated
// 2. DynamicConfig: can be modified after the solver was instanciated
class LoatConfig
{
public:
    struct InitialConfig
    {
        // Input format must be fixed when parsing starts,
        // and cannot change mid-execution (e.g. Koat, ITS, Horn)
        enum Format
        {
            Koat,
            Its,
            Horn
        };

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
            Complexity,
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

        // Variables to store the choosen preferences
        Format format;
        Engine engine;
        Mode mode;
        SmtSolver solver;

        // Constructor
        InitialConfig(Format f, Engine e, Mode m, SmtSolver s)
            : format(f), engine(e), mode(m), solver(s) {}
    };

    struct DynamicConfig
    {
        // Direction of analysis (forward, backward, interleaved)
        // @FROHN is this actually changable after the solvers instanciation?
        enum Direction
        {
            Forward,
            Backward,
            Interleaved
        };
        Direction direction = Forward;

        // Logging options. Can be toggled. Default value is false
        bool log = false;
        bool logAccel = false;
        bool logPreproc = false;

        // @FROHN What exactly does this? It is a boolean in the original config.
        bool model = false;

        // Should the dependency graph be printed to output? Default value is false.
        bool printDependencyGraph = false;

        // Configuration for Transition Relation Partitioning (TRP)
        struct TRPConfig
        {
            // Solver-level tuning parameter.
            enum MbpKind
            {
                LowerIntMbp,
                UpperIntMbp,
                IntMbp,
                RealMbp,
                RealQe
            };
            MbpKind mbpKind = IntMbp;

            // Options controlling which recurrence patterns to use.
            // Can be enabled/disabled dynamically during analysis.
            bool recurrent_cycles = false;
            bool recurrent_exps = true;
            bool recurrent_pseudo_divs = true;
            bool recurrent_pseudo_bounds = true;
            bool recurrent_bounds = true;
        } trp;

        // ABMC-specific option – whether to use blocking clauses.
        // @FROHN Can this be changed dynamicly? Im not sure about this.
        bool blocking_clauses = false;
    };

private:
    // Initial config is fixed (immutable) once constructed
    const InitialConfig initial;

    // Dynamic config can be modified
    DynamicConfig dynamic;

public:
    LoatConfig(InitialConfig init, DynamicConfig dyn)
        : initial(std::move(init)), dynamic(std::move(dyn)) {}

    const InitialConfig &getInitial() const { return initial; }
    const DynamicConfig &getDynamic() const { return dynamic; }

    DynamicConfig &getDynamic() { return dynamic; }

    // Apply this configuration to the global Config:: namespace
    void applyToGlobalConfig() const;
};