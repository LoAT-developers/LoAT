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

        std::vector<Mode> modes { Complexity, Termination, RelativeTermination, Safety };

        Mode mode;
        Engine engine;
        SmtSolver smtSolver = Heuristic;
        bool log = false;
        bool logPreproc = false;
        bool logAccel = false;
        bool model = false;
        Direction dir;

        std::string modeName(const Mode mode) {
            switch (mode) {
            case Complexity: return "complexity";
            case Termination: return "termination";
            case RelativeTermination: return "relative_termination";
            case Safety: return "safety";
            }
        }

        bool relative_termination() {
            return mode == RelativeTermination;
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
            return termination() || relative_termination() || complexity();
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

    namespace Accel {
        bool non_linear {true};
    }

    bool validate() {
        switch (Analysis::mode) {
            case Analysis::Mode::Complexity: {
                if (Analysis::engine != Analysis::ADCL) {
                    std::cerr << "complexity analysis is only supported by the engine adcl" << std::endl;
                    return false;
                }
                switch (Analysis::dir) {
                    case Analysis::Interleaved: {
                        std::cerr << "interleaved complexity analysis does not make sense" << std::endl;
                        return false;
                    }
                    case Analysis::Backward: {
                        std::cerr << "warning: analyzing the backward-complexity -- is this intended?" << std::endl;
                    }
                    default: break;
                }
                if (Input::format == Input::Horn) {
                    std::cerr << "warning: analyzing the complexity of CHCs -- is this intended?" << std::endl;
                }
                return true;
            }
            case Analysis::Mode::Termination: {
                switch (Analysis::engine) {
                    case Analysis::BMC:
                    case Analysis::KIND:
                    case Analysis::ADCLSAT: {
                        std::cerr << "termination analysis is not supported by the given engine" << std::endl;
                        return false;
                    }
                    default: break;
                }
                switch (Analysis::dir) {
                    case Analysis::Interleaved: {
                        std::cerr << "interleaved termination analysis does not make sense" << std::endl;
                        return false;
                    }
                    case Analysis::Backward: {
                        std::cerr << "warning: analyzing backward-termination -- is this intended?" << std::endl;
                    }
                    default: break;
                }
                if (Input::format == Input::Horn) {
                    std::cerr << "warning: analyzing termination of CHCs -- is this intended?" << std::endl;
                }
                return true;
            }
            default: return true;
        }
    }

}
