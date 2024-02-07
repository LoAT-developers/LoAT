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

    // Proof output
    namespace Output {
        extern bool Colors;
        extern bool PrintDependencyGraph;
    }

    namespace Input {
        enum Format {Koat, Its, Horn, C};
        extern Format format;
    }

    // Colors (Ansi color codes) for output
    namespace Color {
        extern const std::string None;

        extern const std::string Location;
        extern const std::string Update;
        extern const std::string Guard;
        extern const std::string Cost;

        extern const std::string Debug;
        extern const std::string DebugProblem;
        extern const std::string DebugWarning;
        extern const std::string DebugHighlight;
    }

    // Asymptotic complexity computation using limit problems
    namespace Limit {
        extern const unsigned int ProblemDiscardSize;
        extern const unsigned Timeout;
    }

    // Main algorithm
    namespace Analysis {

        enum Mode { Complexity, NonTermination, Reachability, Safety, Recurrence };
        enum Engine { ADCL, BMC, ABMC };
        enum SmtSolver { Z3, CVC5, Swine, Yices };
        extern std::vector<Mode> modes;
        extern Mode mode;
        extern Engine engine;
        extern SmtSolver smtSolver;
        extern bool log;

        std::string modeName(const Mode mode);

        bool nonTermination();
        bool tryNonterm();
        bool reachability();
        bool safety();
        bool complexity();

    }

    namespace ABMC {
        extern bool blocking_clauses;
    }

}
