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

#include "itsparser.hpp"
#include "parser.hpp"
#include "chcparser.hpp"
#include "cintparser.hpp"
#include "config.hpp"
#include "proof.hpp"
#include "version.hpp"
#include "reachability.hpp"
#include "bmc.hpp"
#include "abmc.hpp"
#include "yices.hpp"

#include <iostream>
#include <boost/algorithm/string.hpp>

using namespace std;

// Variables for command line flags
string filename;

void printHelp(char *arg0) {
    cout << "Usage: " << arg0 << " [options] <file>" << endl;
    cout << "Options:" << endl;
    cout << "  --proof-level <n>                                Detail level for proof output" << endl;
    cout << "  --plain                                          Disable colored output" << endl;
    cout << "  --mode <complexity|non_termination|reachability> Analysis mode" << endl;
    cout << "  --format <koat|its|horn>                         Input format" << endl;
    cout << "  --engine <adcl|bmc|abmc>                         Analysis engine" << endl;
    cout << "  --log                                            Enable logging" << endl;
}


void parseFlags(int argc, char *argv[]) {
    int arg=0;

    auto getNext = [&]() {
        if (arg < argc-1) {
            return argv[++arg];
        } else {
            cout << "Error: Argument missing for " << argv[arg] << endl;
            exit(1);
        }
    };

    while (++arg < argc) {
        if (strcmp("--help",argv[arg]) == 0) {
            printHelp(argv[0]);
            exit(1);
        } else if (strcmp("--proof-level",argv[arg]) == 0) {
            int proofLevel = atoi(getNext());
            if (proofLevel < 0) {
                cerr << "proof level must be non-negative, ignoring value " << proofLevel << endl;
            } else {
                Proof::setProofLevel(proofLevel);
            }
        } else if (strcmp("--plain",argv[arg]) == 0) {
            Config::Output::Colors = false;
            Proof::disableColors();
        } else if (strcmp("--log", argv[arg]) == 0) {
            Config::Analysis::log = true;
        } else if (strcmp("--mode", argv[arg]) == 0) {
            bool found = false;
            std::string str = getNext();
            for (const Config::Analysis::Mode mode: Config::Analysis::modes) {
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
            } else {
                cout << "Error: unknown engine " << str << std::endl;
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

    ITSProblem its;
    switch (Config::Input::format) {
    case Config::Input::Koat:
        its = parser::ITSParser::loadFromFile(filename);
        break;
    case Config::Input::Its:
        its = sexpressionparser::Parser::loadFromFile(filename);
        break;
    case Config::Input::Horn:
        its = hornParser::HornParser::loadFromFile(filename);
        break;
    case Config::Input::C:
        its = cintParser::CIntParser::loadFromFile(filename);
        break;
    default:
        std::cout << "Error: unknown format" << std::endl;
        exit(1);
    }

    yices::init();
    switch (Config::Analysis::engine) {
    case Config::Analysis::ADCL:
        reachability::Reachability::analyze(its);
        break;
    case Config::Analysis::BMC:
        BMC::analyze(its);
        break;
    case Config::Analysis::ABMC:
        ABMC::analyze(its);
        break;
    }
    yices::exit();

    cout << "Build SHA: " << Version::GIT_SHA << (Version::GIT_DIRTY == "DIRTY" ? " (dirty)" : "") << endl;

    return 0;
}
