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

#include "main.hpp"

#include "abmc.hpp"
#include "accelerationproblem.hpp"
#include "bmc.hpp"
#include "chcparser.hpp"
#include "sexpressoparser.hpp"
#include "chctoitsproblem.hpp"
#include "chctosafetyproblem.hpp"
#include "cintparser.hpp"
#include "config.hpp"
#include "forwardbackwarddriver.hpp"
#include "itsparser.hpp"
#include "parser.hpp"
#include "proof.hpp"
#include "reachability.hpp"
#include "recurrence.hpp"
#include "safetyproblem.hpp"
#include "til.hpp"
#include "version.hpp"
#include "yices.hpp"

#include <boost/algorithm/string.hpp>
#include <chrono>
#include <iostream>

using namespace std;

// Variables for command line flags
string filename;

void printHelp(char *arg0) {
    cout << "Usage: " << arg0 << " [options] <file>" << endl;
    cout << "Options:" << endl;
    cout << "  --proof-level <n>                                Detail level for proof output" << endl;
    cout << "  --plain                                          Disable colored output" << endl;
    cout << "  --print_dep_graph                                Print the dependency graph in the proof output (can be very verbose)" << endl;
    cout << "  --mode <complexity|non_termination|reachability> Analysis mode" << endl;
    cout << "  --format <koat|its|horn|c>                       Input format" << endl;
    cout << "  --engine <adcl|bmc|abmc>                         Analysis engine" << endl;
    cout << "  --log                                            Enable logging" << endl;
    cout << "  --abmc::blocking_clauses <true|false>            ABMC: En- or disable blocking clauses" << std::endl;
    cout << "  --smt <z3|cvc5|swine|yices|heuristic>            Choose the SMT solver" << std::endl;
    cout << "  --til::mode <forward|backward|interleaved>       TIL: run the analysis forward, backward, or both directions interleaved" << std::endl;
    cout << "  --til::recurrent_exps <true|false>               TIL: En- or disable recurrence analysis for variables with exponential bounds" << std::endl;
    cout << "  --til::recurrent_cycles <true|false>             TIL: En- or disable search for variables that behave recurrently after more than one iteration" << std::endl;
    cout << "  --til::recurrent_pseudo_divs <true|false>        TIL: En- or disable search for pseudo-recurrent divisibility constraints" << std::endl;
    cout << "  --til::recurrent_bounds <true|false>             TIL: En- or disable search for recurrent bounds" << std::endl;
    cout << "  --til::context_sensitive <true|false>            TIL: En- or disable context sensitivity" << std::endl;
    cout << "  --til::mbp_kind <int|real>                       TIL: use model based projection for LIA or LRA" << std::endl;
}

void setBool(const char *str, bool &b) {
    if (strcmp("true", str) == 0) {
        b = true;
    } else if (strcmp("false", str) == 0) {
        b = false;
    }
}

void print_version() {
    cout << Version::GIT_SHA;
    if (Version::GIT_DIRTY != "CLEAN") {
        cout << "_DIRTY";
    }
    cout << endl;
}

void parseFlags(int argc, char *argv[]) {
    int arg = 0;

    auto getNext = [&]() {
        if (arg < argc - 1) {
            return argv[++arg];
        } else {
            cout << "Error: Argument missing for " << argv[arg] << endl;
            exit(1);
        }
    };

    while (++arg < argc) {
        if (strcmp("--help", argv[arg]) == 0) {
            printHelp(argv[0]);
            exit(0);
        } else if (strcmp("--proof-level", argv[arg]) == 0) {
            int proofLevel = atoi(getNext());
            if (proofLevel < 0) {
                cerr << "proof level must be non-negative, ignoring value " << proofLevel << endl;
            } else {
                Proof::setProofLevel(proofLevel);
            }
        } else if (strcmp("--plain", argv[arg]) == 0) {
            Config::Output::Colors = false;
            Proof::disableColors();
        } else if (strcmp("--print_dep_graph", argv[arg]) == 0) {
            Config::Output::PrintDependencyGraph = true;
        } else if (strcmp("--log", argv[arg]) == 0) {
            Config::Analysis::log = true;
        } else if (strcmp("--mode", argv[arg]) == 0) {
            bool found = false;
            std::string str = getNext();
            for (const Config::Analysis::Mode mode : Config::Analysis::modes) {
                if (boost::iequals(str, Config::Analysis::modeName(mode))) {
                    Config::Analysis::mode = mode;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cerr << "Unknown mode " << str << ", defaulting to " << Config::Analysis::modeName(Config::Analysis::mode) << endl;
            }
        } else if (strcmp("--engine", argv[arg]) == 0) {
            std::string str = getNext();
            if (boost::iequals("adcl", str)) {
                Config::Analysis::engine = Config::Analysis::ADCL;
            } else if (boost::iequals("abmc", str)) {
                Config::Analysis::engine = Config::Analysis::ABMC;
            } else if (boost::iequals("bmc", str)) {
                Config::Analysis::engine = Config::Analysis::BMC;
            } else if (boost::iequals("til", str)) {
                Config::Analysis::engine = Config::Analysis::TIL;
            } else {
                cout << "Error: unknown engine " << str << std::endl;
                exit(1);
            }
        } else if (strcmp("--smt", argv[arg]) == 0) {
            std::string str = getNext();
            if (boost::iequals("z3", str)) {
                Config::Analysis::smtSolver = Config::Analysis::Z3;
            } else if (boost::iequals("cvc5", str)) {
                Config::Analysis::smtSolver = Config::Analysis::CVC5;
            } else if (boost::iequals("swine", str)) {
                Config::Analysis::smtSolver = Config::Analysis::Swine;
            } else if (boost::iequals("yices", str)) {
                Config::Analysis::smtSolver = Config::Analysis::Yices;
            } else if (boost::iequals("heuristic", str)) {
                Config::Analysis::smtSolver = Config::Analysis::Heuristic;
            } else {
                cout << "Error: unknown SMT solver " << str << std::endl;
                exit(1);
            }
        } else if (strcmp("--polyaccel", argv[arg]) == 0) {
            std::string str = getNext();
            if (boost::iequals("full", str)) {
                AccelerationProblem::polyaccel = AccelerationProblem::PolyAccelMode::Full;
            } else if (boost::iequals("low_degree", str)) {
                AccelerationProblem::polyaccel = AccelerationProblem::PolyAccelMode::LowDegree;
            } else if (boost::iequals("none", str)) {
                AccelerationProblem::polyaccel = AccelerationProblem::PolyAccelMode::None;
            } else {
                cout << "Error: unknown mode " << str << " for polynomial acceleration" << std::endl;
                exit(1);
            }
        } else if (strcmp("--format", argv[arg]) == 0) {
            std::string str = getNext();
            if (boost::iequals("koat", str)) {
                Config::Input::format = Config::Input::Koat;
            } else if (boost::iequals("its", str)) {
                Config::Input::format = Config::Input::Its;
            } else if (boost::iequals("horn", str)) {
                Config::Input::format = Config::Input::Horn;
            } else if (boost::iequals("c", str)) {
                Config::Input::format = Config::Input::C;
            } else {
                cout << "Error: unknown format " << str << std::endl;
                exit(1);
            }
        } else if (strcmp("--abmc::blocking_clauses", argv[arg]) == 0) {
            setBool(getNext(), Config::ABMC::blocking_clauses);
        } else if (strcmp("--til::mode", argv[arg]) == 0) {
            const auto str{getNext()};
            if (boost::iequals("forward", str)) {
                Config::til.mode = Config::TILConfig::Mode::Forward;
            } else if (boost::iequals("backward", str)) {
                Config::til.mode = Config::TILConfig::Mode::Backward;
            } else if (boost::iequals("interleaved", str)) {
                Config::til.mode = Config::TILConfig::Mode::Interleaved;
            } else {
                cout << "Error: unknown TIL mode " << str << std::endl;
                exit(1);
            }
        } else if (strcmp("--til::recurrent_exps", argv[arg]) == 0) {
            setBool(getNext(), Config::til.recurrent_exps);
        } else if (strcmp("--til::recurrent_cycles", argv[arg]) == 0) {
            setBool(getNext(), Config::til.recurrent_cycles);
        } else if (strcmp("--til::recurrent_pseudo_divs", argv[arg]) == 0) {
            setBool(getNext(), Config::til.recurrent_pseudo_divs);
        } else if (strcmp("--til::recurrent_bounds", argv[arg]) == 0) {
            setBool(getNext(), Config::til.recurrent_bounds);
        } else if (strcmp("--til::context_sensitive", argv[arg]) == 0) {
            setBool(getNext(), Config::til.context_sensitive);
        } else if (strcmp("--til::mbp_kind", argv[arg]) == 0) {
            const auto str{getNext()};
            if (boost::iequals("lower_int", str)) {
                Config::til.mbpKind = Config::TILConfig::MbpKind::LowerIntMbp;
            } else if (boost::iequals("upper_int", str)) {
                Config::til.mbpKind = Config::TILConfig::MbpKind::UpperIntMbp;
            } else if (boost::iequals("real", str)) {
                Config::til.mbpKind = Config::TILConfig::MbpKind::RealMbp;
            } else {
                cout << "Error: unknown MBP kind " << str << std::endl;
                exit(1);
            }
        } else if (strcmp("--version", argv[arg]) == 0) {
            print_version();
            exit(0);
        } else {
            if (!filename.empty()) {
                cout << "Error: additional argument " << argv[arg] << " (already got filename: " << filename << ")" << endl;
                exit(1);
            }
            filename = argv[arg];
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printHelp(argv[0]);
        return 1;
    }

    // Parse and interpret command line flags
    parseFlags(argc, argv);

    // Start parsing
    if (filename.empty()) {
        cerr << "Error: missing filename" << endl;
        return 1;
    }

    if (Config::Analysis::mode == Config::Analysis::Recurrence) {
        Recurrence::solve(filename);
        return 0;
    }

    std::optional<ITSPtr> its{};
    std::optional<CHCProblem> chcs{};
    std::optional<SafetyProblem> sp{};
    const auto start{std::chrono::steady_clock::now()};
    switch (Config::Input::format) {
    case Config::Input::Koat:
        its = parser::ITSParser::loadFromFile(filename);
        break;
    case Config::Input::Its:
        its = sexpressionparser::Parser::loadFromFile(filename);
        break;
    case Config::Input::Horn: {
        // chcs = hornParser::HornParser::loadFromFile(filename);
        chcs = SexpressoParser::loadFromFile(filename);
        break;
    }
    case Config::Input::C:
        its = cintParser::CIntParser::loadFromFile(filename);
        break;
    default:
        std::cout << "Error: unknown format" << std::endl;
        exit(1);
    }
    const auto end{std::chrono::steady_clock::now()};
    if (Config::Analysis::log) {
        std::cout << "parsing took " << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << " seconds" << std::endl;
    }

    yices::init();
    switch (Config::Analysis::engine) {
    case Config::Analysis::ADCL:
        reachability::Reachability::analyze(**its);
        break;
    case Config::Analysis::BMC:
        BMC::analyze(**its);
        break;
    case Config::Analysis::ABMC:
        ABMC::analyze(**its);
        break;
    case Config::Analysis::TIL:
        switch (Config::til.mode) {
        case Config::TILConfig::Mode::Forward: {
            TIL::analyze(*chcs);
            break;
        }
        case Config::TILConfig::Mode::Backward: {
            auto b{chcs->reverse()};
            TIL::analyze(b);
            break;
        }
        case Config::TILConfig::Mode::Interleaved: {
            ForwardBackwardDriver::analyze(*chcs);
            break;
        }
        }
        break;
    }
    yices::exit();

    print_version();

    return 0;
}
