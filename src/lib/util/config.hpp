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

        enum Mode { Complexity, NonTermination, Reachability, Safety, Recurrence };
        enum Engine { ADCL, BMC, ABMC, TIL };
        enum SmtSolver { Z3, CVC5, Swine, Yices, Heuristic };
        extern std::vector<Mode> modes;
        extern Mode mode;
        extern Engine engine;
        extern SmtSolver smtSolver;
        extern bool log;
        extern bool logAccel;
        extern bool logPreproc;
        extern bool reverse;

        std::string modeName(const Mode mode);

        bool nonTermination();
        bool tryNonterm();
        bool reachability();
        bool safety();
        bool complexity();
        bool doLogAccel();
        bool doLogPreproc();

    }

    struct TILConfig {
        enum Mode {Forward, Backward, Interleaved};
        enum MbpKind {LowerIntMbp, UpperIntMbp, RealMbp};
        Mode mode {Forward};
        MbpKind mbpKind {LowerIntMbp};
        bool recurrent_cycles {false};
        bool recurrent_exps {true};
        bool recurrent_pseudo_divs {true};
        bool recurrent_bounds {true};
        bool context_sensitive {false};
    };

    extern TILConfig til;

    namespace ABMC {
        extern bool blocking_clauses;
    }

}
