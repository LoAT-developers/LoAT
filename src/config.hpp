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

#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>
#include <ostream>
#include "option.hpp"

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
    }

    namespace Input {
        enum Format {Koat, Its, T2, Horn};
        extern Format format;
    }

    // Colors (Ansi color codes) for output
    namespace Color {
        extern const std::string Section;
        extern const std::string Headline;
        extern const std::string Warning;
        extern const std::string Result;
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

    // All settings for interfacing z3
    namespace Smt {
        extern const unsigned DefaultTimeout;
        extern const unsigned MeterTimeout;
        extern const unsigned StrengtheningTimeout;
        extern const unsigned LimitTimeout;
        extern const unsigned LimitTimeoutFinal;
        extern const unsigned LimitTimeoutFinalFast;
        extern const unsigned MaxExponentWithoutPow;
        extern const unsigned SimpTimeout;
    }

    namespace Qelim {
        extern const bool useRedlog;
    }

    // Loop acceleration technique
    namespace LoopAccel {
        extern const unsigned MaxUpperboundsForPropagation;
        enum AccelerationTechnique {
            Calculus, QE, Combined
        };
        extern const AccelerationTechnique accelerationTechnique;
    }

    // High level acceleration strategy
    namespace Accel {
        extern const bool SimplifyRulesBefore;
        extern bool PartialDeletionHeuristic;
        extern bool TryNesting;
    }

    // Chaining and chaining strategies
    namespace Chain {
        extern const bool CheckSat;
    }

    // Pruning in case of too many rules
    namespace Prune {
        extern const unsigned MaxParallelRules;
    }

    // Asymptotic complexity computation using limit problems
    namespace Limit {
        class PolynomialLimitProblemStrategy {
        public:
            virtual bool smtEnabled() const = 0;
            virtual bool calculusEnabled() const = 0;
            virtual std::string name() const = 0;
        };
        class: public PolynomialLimitProblemStrategy {
            bool smtEnabled() const override {return true;}
            bool calculusEnabled() const override {return false;}
            std::string name() const override {return "smt";}
        } Smt;
        class: public PolynomialLimitProblemStrategy {
            bool smtEnabled() const override {return false;}
            bool calculusEnabled() const override {return true;}
            std::string name() const override {return "calculus";}
        } Calculus;
        class: public PolynomialLimitProblemStrategy {
            bool smtEnabled() const override {return true;}
            bool calculusEnabled() const override {return true;}
            std::string name() const override {return "smtAndCalculus";}
        } SmtAndCalculus;

        static const std::vector<PolynomialLimitProblemStrategy*> PolyStrategies = {&Smt, &Calculus, &SmtAndCalculus};

        extern PolynomialLimitProblemStrategy* PolyStrategy;
        extern const unsigned int ProblemDiscardSize;
    }

    // Main algorithm
    namespace Analysis {

        enum Mode { Complexity, NonTermination, Smt2Export, CIntExport, Reachability };
        extern std::vector<Mode> modes;
        extern bool Pruning;
        extern Mode mode;

        std::string modeName(const Mode mode);
        bool nonTermination();
        bool reachability();
        bool complexity();

    }

    /**
     * Prints all of the above config values to the given stream.
     * Useful to test command line flags and to include configuration benchmarks.
     */
    void printConfig(std::ostream &s, bool withDescription);
}

#endif //CONFIG_H
