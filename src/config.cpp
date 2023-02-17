/*  This file is part of LoAT.
 *  Copyright (c) 2015-2016 Matthias Naaf, RWTH Aachen University, Germany
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses>.
 */

#include "config.hpp"
#include <iostream>

using namespace std;

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
        // Whether to enable colors in the proof output
        bool Colors = true;
    }

    namespace Input {
        Format format = Koat;
    }

    namespace Color {
        const std::string None = "\033[0m";
        // ITS Output
        const std::string Location = "\033[1;34m"; // bold blue
        const std::string Update = "\033[0;36m"; // cyan
        const std::string Guard = "\033[0;32m"; // green
        const std::string Cost = "\033[0;35m"; // bold magenta

        const std::string BoldBlue = "\033[0;34m"; // blue
        const std::string Gray = "\033[0;90m"; // gray/bright black (avoid distraction)
        const std::string BoldyYellow = "\033[1;33m"; // bold yellow
        const std::string BoldRed = "\033[1;31m"; // bold red
        const std::string Cyan = "\033[0;36m"; // cyan
    }

    namespace Smt {
        const unsigned MeterTimeout = 500u;
        const unsigned StrengtheningTimeout = 750u;
        const unsigned LimitTimeout = 500u;
        const unsigned LimitTimeoutFinal = 3000u;
        const unsigned LimitTimeoutFinalFast = 500u;
        const unsigned SimpTimeout = 200u;
    }

    namespace Qelim {
        const bool useRedlog = false;
    }

    // Loop acceleration technique
    namespace LoopAccel {
        // If KeepTempVarForIterationCount is false, then "k" is instantiated by its upper bounds.
        // If there are several upperbounds, several rules are created.
        // To avoid rule explosion, the propagation is only performed up to this number of upperbounds.
        const unsigned MaxUpperboundsForPropagation = 3;
        const AccelerationTechnique accelerationTechnique = Calculus;
    }

    namespace Accel {
        // Simplify rules before trying to accelerate them.
        // Should be enabled (especially helps to eliminate free variables).
        const bool SimplifyRulesBefore = true;

        // Heuristic to shorten nonlinear rules by deleting some of the rhss if metering failed.
        // We currently try to meter all pairs and every single rhs, so this is rather expensive.
        bool PartialDeletionHeuristic = true;

        // If true, tries to nest parallel rules. Nesting means that one iteration of the "outer"
        // loop is followed by a full execution of the "inner" loop. This is a simple application
        // of chaining combined with acceleration, but is not described in the paper.
        bool TryNesting = true;
    }

    // Chaining and chaining strategies
    namespace Chain {
        // Whether to check if the chained rule's guard is still satisfiable.
        // This is expensive if many rules are chained, but should nevertheless be enabled.
        // If disabled, a rule with high complexity can become unsatisfiable if chained with an incompatible rule.
        // If disabled, many unsatisfiable rules could be created, leading to rule explosion.
        const bool CheckSat = true;
    }

    namespace Prune {
        // Prune parallel rules if there are more than this number.
        // We consider two rules parallel if they have an edge in common, e.g. f -> f,g and f -> g are parallel.
        const unsigned MaxParallelRules = 5;
    }

    // Asymptotic complexity computation using limit problems
    namespace Limit {
        // Discard a limit problem of size >= ProblemDiscardSize in a non-final check if z3 yields "unknown"
        const unsigned int ProblemDiscardSize = 10;
    }

    namespace Analysis {

        std::vector<Mode> modes { Complexity, NonTermination, Reachability, Satisfiability, CheckLinear };

        // Whether to enable pruning to reduce the number of rules.
        // Pruning works by greedily keeping rules with a high complexity.
        // To be more accurate, this involves the asymptotic check (and can thus be expensive).
        bool Pruning = true;

        Mode mode = Complexity;

        std::string modeName(const Mode mode) {
            switch (mode) {
            case Complexity: return "complexity";
                break;
            case NonTermination: return "non_termination";
                break;
            case Reachability: return "reachability";
                break;
            case Satisfiability: return "satisfiability";
                break;
            case CheckLinear: return "check_linear";
                break;
            default:
                throw std::invalid_argument("unknown mode");
            }
        }

        bool nonTermination() {
            return mode == NonTermination;
        }

        bool reachability() {
            return mode == Reachability;
        }

        bool satisfiability(){
            return mode == Satisfiability;
        }

        bool complexity() {
            return mode == Complexity;
        }

        bool tryNonterm() {
            return nonTermination() || complexity();
        }

    }

}
