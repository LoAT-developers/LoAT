#include "main.hpp"

#include "abmc.hpp"
#include "accelerationproblem.hpp"
#include "bmc.hpp"
#include "chctoitsproblem.hpp"
#include "cintparser.hpp"
#include "config.hpp"
#include "forwardbackwarddriver.hpp"
#include "itsparser.hpp"
#include "parser.hpp"
#include "preprocessing.hpp"
#include "reachability.hpp"
#include "recurrence.hpp"
#include "reverse.hpp"
#include "safetyproblem.hpp"
#include "sexpressoparser.hpp"
#include "til.hpp"
#include "version.hpp"
#include "yices.hpp"

#include <boost/algorithm/string.hpp>
#include <chrono>
#include <iostream>

// Variables for command line flags
std::string filename;

void printHelp(char *arg0) {
    std::cout << "Usage: " << arg0 << " [options] <file>" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  --print_dep_graph                                Print the dependency graph in the proof output (can be very verbose)" << std::endl;
    std::cout << "  --mode <complexity|termination|safety>           Analysis mode" << std::endl;
    std::cout << "  --format <koat|its|horn|c>                       Input format" << std::endl;
    std::cout << "  --engine <adcl|bmc|abmc>                         Analysis engine" << std::endl;
    std::cout << "  --log                                            Enable logging" << std::endl;
    std::cout << "  --proof                                          Print model/counterexample/recurrent set/..." << std::endl;
    std::cout << "  --abmc::blocking_clauses <true|false>            ABMC: En- or disable blocking clauses" << std::endl;
    std::cout << "  --smt <z3|cvc5|swine|yices|heuristic>            Choose the SMT solver" << std::endl;
    std::cout << "  --til::mode <forward|backward|interleaved>       TIL: run the analysis forward, backward, or both directions interleaved" << std::endl;
    std::cout << "  --til::recurrent_exps <true|false>               TIL: En- or disable recurrence analysis for variables with exponential bounds" << std::endl;
    std::cout << "  --til::recurrent_cycles <true|false>             TIL: En- or disable search for variables that behave recurrently after more than one iteration" << std::endl;
    std::cout << "  --til::recurrent_pseudo_divs <true|false>        TIL: En- or disable search for pseudo-recurrent divisibility constraints" << std::endl;
    std::cout << "  --til::recurrent_bounds <true|false>             TIL: En- or disable search for recurrent bounds" << std::endl;
    std::cout << "  --til::context_sensitive <true|false>            TIL: En- or disable context sensitivity" << std::endl;
    std::cout << "  --til::mbp_kind <lower_int|upper_int|real>       TIL: use model based projection for LIA or LRA" << std::endl;
}

void setBool(const char *str, bool &b) {
    if (strcmp("true", str) == 0) {
        b = true;
    } else if (strcmp("false", str) == 0) {
        b = false;
    }
}

void print_version() {
    std::cout << Version::GIT_SHA;
    if (Version::GIT_DIRTY != "CLEAN") {
        std::cout << "_DIRTY";
    }
    std::cout << std::endl;
}

void parseFlags(int argc, char *argv[]) {
    int arg = 0;

    auto getNext = [&]() {
        if (arg < argc - 1) {
            return argv[++arg];
        } else {
            std::cout << "Error: Argument missing for " << argv[arg] << std::endl;
            exit(1);
        }
    };
    auto has_engine{false};
    while (++arg < argc) {
        if (strcmp("--help", argv[arg]) == 0) {
            printHelp(argv[0]);
            exit(0);
        } else if (strcmp("--print_dep_graph", argv[arg]) == 0) {
            Config::Output::PrintDependencyGraph = true;
        } else if (strcmp("--log", argv[arg]) == 0) {
            Config::Analysis::log = true;
        } else if (strcmp("--model", argv[arg]) == 0) {
            Config::Analysis::model = true;
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
                std::cerr << "Unknown mode " << str << ", defaulting to " << Config::Analysis::modeName(Config::Analysis::mode) << std::endl;
            }
        } else if (strcmp("--engine", argv[arg]) == 0) {
            has_engine = true;
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
                std::cout << "Error: unknown engine " << str << std::endl;
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
                std::cout << "Error: unknown SMT solver " << str << std::endl;
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
                std::cout << "Error: unknown mode " << str << " for polynomial acceleration" << std::endl;
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
                std::cout << "Error: unknown format " << str << std::endl;
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
                std::cout << "Error: unknown TIL mode " << str << std::endl;
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
                std::cout << "Error: unknown MBP kind " << str << std::endl;
                exit(1);
            }
        } else if (strcmp("--version", argv[arg]) == 0) {
            print_version();
            exit(0);
        } else {
            if (!filename.empty()) {
                std::cout << "Error: additional argument " << argv[arg] << " (already got filename: " << filename << ")" << std::endl;
                exit(1);
            }
            filename = argv[arg];
        }
    }
    if (!has_engine) {
        switch (Config::Analysis::mode) {
            case Config::Analysis::Safety:
                Config::Analysis::engine = Config::Analysis::ABMC;
                break;
            default:
                Config::Analysis::engine = Config::Analysis::ADCL;
                break;
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
        std::cerr << "Error: missing filename" << std::endl;
        return 1;
    }

    if (Config::Analysis::mode == Config::Analysis::Recurrence) {
        Recurrence::solve(filename);
        return 0;
    }

    std::optional<ITSPtr> its{};
    std::optional<CHCProblem> chcs{};
    std::optional<SafetyProblem> sp{};
    std::optional<ReversibleCHCToITS> chc2its{};
    const auto start{std::chrono::steady_clock::now()};
    switch (Config::Input::format) {
        case Config::Input::Koat:
            its = parser::ITSParser::loadFromFile(filename);
            break;
        case Config::Input::Its:
            its = sexpressionparser::Parser::loadFromFile(filename);
            break;
        case Config::Input::Horn: {
            chcs = SexpressoParser::loadFromFile(filename);
            Config::Analysis::model |= chcs->get_produce_model();
            if (Config::Analysis::engine == Config::Analysis::TIL && Config::til.mode == Config::TILConfig::Mode::Backward) {
                chcs = reverse(*chcs);
            }
            chc2its = chcs_to_its(*chcs);
            its = **chc2its;
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
    if (Config::Analysis::log) {
        std::cout << "Initial ITS\n"
                  << **its << std::endl;
    }
    yices::init();
    std::optional<ITSModel> its_model;
    auto preprocessor{std::make_shared<Preprocessor>(**its)};
    if (const auto status{preprocessor->preprocess()}; status != SmtResult::Unknown && Config::Analysis::safety()) {
        if (Config::Analysis::log) {
            std::cout << "solved by preprocessing" << std::endl;
        }
        if (Config::Analysis::model) {
            its_model = preprocessor->get_model();
        }
        std::cout << status << std::endl;
    } else {
        if (preprocessor->successful() && Config::Analysis::log) {
            std::cout << "Simplified ITS\n"
                      << **its << std::endl;
        }
        switch (Config::Analysis::engine) {
            case Config::Analysis::ADCL:
                reachability::Reachability::analyze(**its);
                break;
            case Config::Analysis::BMC: {
                BMC bmc{**its};
                if (bmc.analyze() == SmtResult::Sat && Config::Analysis::model) {
                    its_model = bmc.get_model();
                }
                break;
            }
            case Config::Analysis::ABMC: {
                ABMC abmc{**its};
                if (abmc.analyze() == SmtResult::Sat && Config::Analysis::model) {
                    its_model = abmc.get_model();
                }
                break;
            }
            case Config::Analysis::TIL: {
                switch (Config::til.mode) {
                    case Config::TILConfig::Mode::Forward:
                    case Config::TILConfig::Mode::Backward: {
                        TIL til(**its, Config::til);
                        if (til.analyze() == SmtResult::Sat && Config::Analysis::model) {
                            its_model = til.get_model();
                        }
                        break;
                    }
                    case Config::TILConfig::Mode::Interleaved: {
                        auto reversed_chc2its{chcs_to_its(reverse(*chcs))};
                        auto reversed{*reversed_chc2its};
                        auto backward_preprocessor{std::make_shared<Preprocessor>(*reversed)};
                        if (const auto status{backward_preprocessor->preprocess()}; status != SmtResult::Unknown && Config::Analysis::safety()) {
                            if (Config::Analysis::log) {
                                std::cout << "solved by backward preprocessing" << std::endl;
                            }
                            if (Config::Analysis::model) {
                                its_model = backward_preprocessor->get_model();
                                chc2its = reversed_chc2its;
                                preprocessor = backward_preprocessor;
                            }
                            std::cout << status << std::endl;
                        } else {
                            if (backward_preprocessor->successful() && Config::Analysis::log) {
                                std::cout << "Simplified reversed ITS\n"
                                          << *reversed << std::endl;
                            }
                            ForwardBackwardDriver fb(**its, *reversed);
                            if (fb.analyze() == SmtResult::Sat && Config::Analysis::model) {
                                its_model = fb.get_model();
                                if (!fb.is_forward()) {
                                    chc2its = reversed_chc2its;
                                    preprocessor = backward_preprocessor;
                                }
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
    }
    if (its_model) {
        its_model = preprocessor->transform_model(*its_model);
        const auto chc_model{chc2its->revert_model(*its_model)};
        std::cout << chc_model.to_smtlib().toString() << std::endl;
    }
    yices::exit();

    print_version();

    return 0;
}
