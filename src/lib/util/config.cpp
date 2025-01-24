#include "config.hpp"
#include <iostream>

namespace Config {

    namespace Output {
        bool PrintDependencyGraph {false};
    }

    namespace Input {
        Format format = Horn;
    }

    // Asymptotic complexity computation using limit problems
    namespace Limit {
        // Discard a limit problem of size >= ProblemDiscardSize in a non-final check if z3 yields "unknown"
        const unsigned int ProblemDiscardSize = 10;
        const unsigned Timeout = 500u;
    }

    namespace Analysis {

        std::vector<Mode> modes { Complexity, Termination, Recurrence, Safety };

        Mode mode;
        Engine engine;
        SmtSolver smtSolver = Heuristic;
        bool log = false;
        bool logPreproc = false;
        bool logAccel = false;
        bool model = false;
        Direction dir;
        std::string filename;

        std::string modeName(const Mode mode) {
            switch (mode) {
            case Complexity: return "complexity";
            case Termination: return "termination";
            case Recurrence: return "recurrence";
            case Safety: return "safety";
            }
        }

        bool termination() {
            return mode == Termination;
        }

        bool complexity() {
            return mode == Complexity;
        }

        bool safety() {
            return mode == Safety;
        }

        bool tryNonterm() {
            return termination() || complexity();
        }

        bool doLogAccel() {
            return log || logAccel;
        }

        bool doLogPreproc() {
            return log || logPreproc;
        }

    }

    Config::TRPConfig trp;

    namespace ABMC {
        bool blocking_clauses {true};
    }

}
