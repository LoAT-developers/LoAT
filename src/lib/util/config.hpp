#pragma once

#include <string>
#include <vector>
#include <ostream>

/**
 * Global settings and constants.
 *
 * Variables which are "const" should mostly not be changed.
 * The other variables may be changed (e.g., to choose which heuristics are used)
 * and may be controlled via command line options.
 *
 * See the source file for documentation (since this is also where the default values are defined)
 */
namespace Config {

    namespace Output {
        extern bool PrintDependencyGraph;
    }

    namespace Input {
        enum Format {Koat, Its, Horn, C};
        extern Format format;
    }

    // Asymptotic complexity computation using limit problems
    namespace Limit {
        extern const unsigned int ProblemDiscardSize;
        extern const unsigned Timeout;
    }

    // Main algorithm
    namespace Analysis {

        enum Mode { Complexity, Termination, Safety, Recurrence };
        enum Engine { ADCL, BMC, ABMC, TRL, KIND, ADCLSAT };
        enum SmtSolver { Z3, CVC5, Swine, Yices, Heuristic };
        enum Direction {Forward, Backward, Interleaved};
        extern Mode mode;
        extern std::vector<Mode> modes;
        extern Direction dir;
        extern Engine engine;
        extern SmtSolver smtSolver;
        extern bool log;
        extern bool logAccel;
        extern bool logPreproc;
        extern bool model;

        std::string modeName(const Mode mode);

        bool termination();
        bool tryNonterm();
        bool safety();
        bool complexity();
        bool doLogAccel();
        bool doLogPreproc();

    }

    struct TRPConfig {
        enum MbpKind {LowerIntMbp, UpperIntMbp, IntMbp, RealMbp, RealQe};
        MbpKind mbpKind {IntMbp};
        bool recurrent_cycles {false};
        bool recurrent_exps {true};
        bool recurrent_pseudo_divs {true};
        bool recurrent_pseudo_bounds {true};
        bool recurrent_bounds {true};
    };

    extern TRPConfig trp;

    namespace ABMC {
        extern bool blocking_clauses;
    }

}
