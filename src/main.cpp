#include "main.hpp"

#include "abmc.hpp"
#include "accelerationproblem.hpp"
#include "bmc.hpp"
#include "chctoitsproblem.hpp"
#include "cintparser.hpp"
#include "config.hpp"
#include "interleaved.hpp"
#include "itsparser.hpp"
#include "parser.hpp"
#include "preprocessing.hpp"
#include "adcl.hpp"
#include "recurrence.hpp"
#include "reverse.hpp"
#include "safetyproblem.hpp"
#include "sexpressoparser.hpp"
#include "trl.hpp"
#include "version.hpp"
#include "yices.hpp"
#include "adclsat.hpp"

#include <boost/algorithm/string.hpp>
#include <chrono>
#include <iostream>

// Variables for command line flags
std::string filename;

void printHelp(char *arg0) {
    std::cout << "Usage: " << arg0 << " [options] <file>" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  --print_dep_graph                                      Print the dependency graph in the proof output (can be very verbose)" << std::endl;
    std::cout << "  --mode <complexity|termination|safety>                 Analysis mode" << std::endl;
    std::cout << "  --format <koat|its|horn|c>                             Input format" << std::endl;
    std::cout << "  --engine <adcl|bmc|abmc|trl|kind>                      Analysis engine" << std::endl;
    std::cout << "  --log                                                  Enable logging" << std::endl;
    std::cout << "  --proof                                                Print model/counterexample/recurrent set/..." << std::endl;
    std::cout << "  --abmc::blocking_clauses <true|false>                  ABMC: En- or disable blocking clauses" << std::endl;
    std::cout << "  --smt <z3|cvc5|swine|yices|heuristic>                  Choose the SMT solver" << std::endl;
    std::cout << "  --direction <forward|backward|interleaved>             run the analysis forward, backward, or both directions interleaved (if supported)" << std::endl;
    std::cout << "  --trl::recurrent_exps <true|false>                     TRL: En- or disable recurrence analysis for variables with exponential bounds" << std::endl;
    std::cout << "  --trl::recurrent_cycles <true|false>                   TRL: En- or disable search for variables that behave recurrently after more than one iteration" << std::endl;
    std::cout << "  --trl::recurrent_pseudo_divs <true|false>              TRL: En- or disable search for pseudo-recurrent divisibility constraints" << std::endl;
    std::cout << "  --trl::recurrent_bounds <true|false>                   TRL: En- or disable search for recurrent bounds" << std::endl;
    std::cout << "  --trl::mbp_kind <int|lower_int|upper_int|real|real_qe> TRL: use model based projection for LIA or LRA, or QF for LRA" << std::endl;
}

void setBool(const char *str, bool &b) {
    if (strcmp("true", str) == 0) {
        b = true;
    } else if (strcmp("false", str) == 0) {
        b = false;
    }
}

void print_version() {
    std::cout << "LoAT:  " << Version::GIT_SHA;
    if (Version::GIT_DIRTY != "CLEAN") {
        std::cout << "_DIRTY";
    }
    std::cout << std::endl;
    std::cout << "Yices: " << std::string(yices_version) << std::endl;
    std::cout << "       build mode: " << std::string(yices_build_mode) << std::endl;
    std::cout << "       build arch: " << std::string(yices_build_arch) << std::endl;
    std::cout << "       build date: " << std::string(yices_build_date) << std::endl;
    std::string z3_version {Z3_get_full_version()};
    std::cout << "Z3:    " << z3_version << std::endl;
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
    auto has_mode{false};
    auto has_direction{false};
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
            std::string str = getNext();
            for (const Config::Analysis::Mode mode : Config::Analysis::modes) {
                if (boost::iequals(str, Config::Analysis::modeName(mode))) {
                    Config::Analysis::mode = mode;
                    has_mode = true;
                    break;
                }
            }
            if (!has_mode) {
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
            } else if (boost::iequals("kind", str)) {
                Config::Analysis::engine = Config::Analysis::KIND;
            } else if (boost::iequals("trl", str)) {
                Config::Analysis::engine = Config::Analysis::TRL;
            } else if (boost::iequals("adcl_sat", str)) {
                Config::Analysis::engine = Config::Analysis::ADCLSAT;
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
        } else if (strcmp("--direction", argv[arg]) == 0) {
            has_direction = true;
            const auto str{getNext()};
            if (boost::iequals("forward", str)) {
                Config::Analysis::dir = Config::Analysis::Direction::Forward;
            } else if (boost::iequals("backward", str)) {
                Config::Analysis::dir = Config::Analysis::Direction::Backward;
            } else if (boost::iequals("interleaved", str)) {
                Config::Analysis::dir = Config::Analysis::Direction::Interleaved;
            } else {
                std::cout << "Error: unknown direction " << str << std::endl;
                exit(1);
            }
        } else if (strcmp("--trl::recurrent_exps", argv[arg]) == 0) {
            setBool(getNext(), Config::trp.recurrent_exps);
        } else if (strcmp("--trl::recurrent_cycles", argv[arg]) == 0) {
            setBool(getNext(), Config::trp.recurrent_cycles);
        } else if (strcmp("--trl::recurrent_pseudo_divs", argv[arg]) == 0) {
            setBool(getNext(), Config::trp.recurrent_pseudo_divs);
        } else if (strcmp("--trl::recurrent_pseudo_bounds", argv[arg]) == 0) {
            setBool(getNext(), Config::trp.recurrent_pseudo_bounds);
        } else if (strcmp("--trl::recurrent_bounds", argv[arg]) == 0) {
            setBool(getNext(), Config::trp.recurrent_bounds);
        } else if (strcmp("--trl::mbp_kind", argv[arg]) == 0) {
            const auto str{getNext()};
            if (boost::iequals("lower_int", str)) {
                Config::trp.mbpKind = Config::TRPConfig::MbpKind::LowerIntMbp;
            } else if (boost::iequals("upper_int", str)) {
                Config::trp.mbpKind = Config::TRPConfig::MbpKind::UpperIntMbp;
            } else if (boost::iequals("int", str)) {
                Config::trp.mbpKind = Config::TRPConfig::MbpKind::IntMbp;
            } else if (boost::iequals("real", str)) {
                Config::trp.mbpKind = Config::TRPConfig::MbpKind::RealMbp;
            } else if (boost::iequals("real_qe", str)) {
                Config::trp.mbpKind = Config::TRPConfig::MbpKind::RealQe;
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
    if (!has_mode) {
        std::cout << "Error: no mode given" << std::endl;
        exit(1);
    }
    if (!has_engine) {
        Config::Analysis::engine = Config::Analysis::safety() ? Config::Analysis::TRL : Config::Analysis::ADCL;
    }
    if (!has_direction) {
        Config::Analysis::dir = Config::Analysis::engine == Config::Analysis::TRL ? Config::Analysis::Interleaved : Config::Analysis::Forward;
    }
}

void print_result(const SmtResult res) {
    std::string str;
    switch (res) {
        case SmtResult::Sat: {
            str = Config::Analysis::safety() ? "sat" : "YES";
            break;
        }
        case SmtResult::Unsat: {
            str = Config::Analysis::safety() ? "unsat" : "NO";
            break;
        }
        case SmtResult::Unknown: {
            str = Config::Analysis::safety() ? "unknown" : "MAYBE";
            break;
        }
    }
    std::cout << str << std::endl << std::endl;
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
    std::optional<CHCPtr> chcs{};
    std::optional<SafetyProblem> sp{};
    std::optional<CHCToITS> chc2its{};
    std::optional<Reverse> reverse{};
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
            if (Config::Analysis::dir == Config::Analysis::Direction::Backward) {
                reverse = Reverse(*chcs);
                chcs = reverse->reverse();
            }
            chc2its = CHCToITS(*chcs);
            its = chc2its->transform();
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
        std::cout << "Initial ITS\n" << *its << std::endl;
    }
    yices::init();
    std::optional<ITSModel> its_model;
    std::optional<ITSSafetyCex> its_cex;
    auto preprocessor{std::make_shared<Preprocessor>(*its)};
    auto res {preprocessor->preprocess()};
    if (res != SmtResult::Unknown) {
        if (Config::Analysis::log) {
            std::cout << "solved by preprocessing" << std::endl;
        }
        if (Config::Analysis::model) {
            if (res == SmtResult::Sat) {
                its_model = preprocessor->get_model();
            } else {
                its_cex = preprocessor->get_cex();
            }
        }
    } else {
        if (preprocessor->successful() && Config::Analysis::log) {
            std::cout << "Simplified ITS\n" << *its << std::endl;
        }
        if (Config::Analysis::dir == Config::Analysis::Direction::Interleaved) {
            reverse = Reverse(*chcs);
            CHCToITS reversed_chc2its{reverse->reverse()};
            auto reversed{reversed_chc2its.transform()};
            auto backward_preprocessor{std::make_shared<Preprocessor>(reversed)};
            res = backward_preprocessor->preprocess();
            if (res != SmtResult::Unknown) {
                if (Config::Analysis::log) {
                    std::cout << "solved by backward preprocessing" << std::endl;
                }
                if (Config::Analysis::model) {
                    chc2its = reversed_chc2its;
                    preprocessor = backward_preprocessor;
                    if (res == SmtResult::Sat) {
                        its_model = backward_preprocessor->get_model();
                    } else {
                        its_cex = backward_preprocessor->get_cex();
                    }
                }
            } else {
                if (backward_preprocessor->successful() && Config::Analysis::log) {
                    std::cout << "Simplified reversed ITS\n"
                              << reversed << std::endl;
                }
                std::unique_ptr<StepwiseAnalysis> f, b;
                switch (Config::Analysis::engine) {
                    case Config::Analysis::TRL: {
                        f = std::make_unique<TRL>(*its, TRL::forwardConfig);
                        b = std::make_unique<TRL>(reversed, TRL::backwardConfig);
                        break;
                    }
                    case Config::Analysis::ABMC: {
                        f = std::make_unique<ABMC>(*its);
                        b = std::make_unique<ABMC>(reversed);
                        break;
                    }
                    case Config::Analysis::ADCLSAT: {
                        f = std::make_unique<ADCLSat>(*its, TRL::forwardConfig);
                        b = std::make_unique<ADCLSat>(reversed, TRL::backwardConfig);
                        break;
                    }
                    default: {
                        std::cerr << "interleaved analysis is only supported by TRL, ABMC, and ADCL-SAT" << std::endl;
                        exit(-1);
                    }
                }
                Interleaved fb(*f, *b);
                res = fb.analyze();
                if (Config::Analysis::model) {
                    if (res == SmtResult::Sat) {
                        its_model = fb.get_model();
                    } else if (res == SmtResult::Unsat) {
                        its_cex = fb.get_cex();
                    }
                    if (fb.is_forward()) {
                        reverse.reset();
                    } else {
                        chc2its = reversed_chc2its;
                        preprocessor = backward_preprocessor;
                    }
                }
            }
        } else {
            switch (Config::Analysis::engine) {
                case Config::Analysis::ADCL: {
                    adcl::ADCL r{
                        *its,
                        [&](const ITSCpxCex &cex) {
                            if (Config::Analysis::complexity()) {
                                std::cout << preprocessor->transform_cex(cex);
                            }
                        }};
                    res = r.analyze();
                    if (Config::Analysis::model && !Config::Analysis::complexity() && res == SmtResult::Unsat) {
                        its_cex = r.get_cex();
                    }
                    break;
                }
                case Config::Analysis::BMC:
                case Config::Analysis::KIND: {
                    BMC bmc{*its, Config::Analysis::engine == Config::Analysis::KIND};
                    res = bmc.analyze();
                    if (Config::Analysis::model) {
                        if (res == SmtResult::Sat) {
                            its_model = bmc.get_model();
                        } else if (res == SmtResult::Unsat) {
                            its_cex = bmc.get_cex();
                        }
                    }
                    break;
                }
                case Config::Analysis::ABMC: {
                    ABMC abmc{*its};
                    res = abmc.analyze();
                    if (Config::Analysis::model) {
                        if (res == SmtResult::Sat) {
                            its_model = abmc.get_model();
                        } else if (res == SmtResult::Unsat) {
                            its_cex = abmc.get_cex();
                        }
                    }
                    break;
                }
                case Config::Analysis::TRL: {
                    TRL trl(*its, Config::trp);
                    res = trl.analyze();
                    if (Config::Analysis::model) {
                        if (res == SmtResult::Sat) {
                            its_model = trl.get_model();
                        } else if (res == SmtResult::Unsat) {
                            its_cex = trl.get_cex();
                        }
                    }
                    break;
                }
                case Config::Analysis::ADCLSAT: {
                    ADCLSat adcl(*its, Config::trp);
                    res = adcl.analyze();
                    if (Config::Analysis::model) {
                        if (res == SmtResult::Sat) {
                            its_model = adcl.get_model();
                        } else if (res == SmtResult::Unsat) {
                            its_cex = adcl.get_cex();
                        }
                    }
                    break;
                }
            }
        }
    }
    // unsat means nonterm, so we also print it in complexity mode
    if (!Config::Analysis::complexity()) {
        print_result(res);
    }
    if (its_model) {
        its_model = preprocessor->transform_model(*its_model);
        if (chc2its) {
            auto chc_model{chc2its->transform_model(*its_model)};
            if (reverse) {
                chc_model = reverse->transform_model(chc_model);
            }
            std::cout << chc_model.to_smtlib().toString();
        } else {
            std::cout << *its_model;
        }
        std::cout << std::endl << std::endl;
    } else if (its_cex) {
        its_cex = preprocessor->transform_cex(*its_cex);
        if (chc2its) {
            auto chc_cex{chc2its->transform_cex(*its_cex)};
            if (reverse) {
                chc_cex = reverse->transform_cex(chc_cex);
            }
            std::cout << chc_cex;
        } else {
            std::cout << *its_cex;
        }
        std::cout << std::endl << std::endl;
    }
    yices::exit();

    print_version();

    return 0;
}
