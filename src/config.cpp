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

    // Asymptotic complexity computation using limit problems
    namespace Limit {
        // Discard a limit problem of size >= ProblemDiscardSize in a non-final check if z3 yields "unknown"
        const unsigned int ProblemDiscardSize = 10;
        const unsigned Timeout = 500u;
    }

    namespace Analysis {

        std::vector<Mode> modes { Complexity, NonTermination, Reachability };

        Mode mode = Complexity;
        Engine engine = ADCL;

        std::string modeName(const Mode mode) {
            switch (mode) {
            case Complexity: return "complexity";
                break;
            case NonTermination: return "non_termination";
                break;
            case Reachability: return "reachability";
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

        bool complexity() {
            return mode == Complexity;
        }

        bool tryNonterm() {
            return nonTermination() || complexity();
        }

    }

}
