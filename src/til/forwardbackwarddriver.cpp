#include "forwardbackwarddriver.hpp"
#include "config.hpp"
#include "til.hpp"

void ForwardBackwardDriver::analyze(const ITSProblem &forward, const ITSProblem &backward) {
    Config::TILConfig forwardConfig {
        .mode = Config::TILConfig::Forward,
        .mbpKind = Config::TILConfig::LowerIntMbp,
        .recurrent_cycles = false,
        .recurrent_exps = true,
        .recurrent_pseudo_divs = true,
        .recurrent_bounds = true,
        .context_sensitive = false,
        .smtSolver = Config::Analysis::Yices
    };
    Config::TILConfig backwardConfig {
        .mode = Config::TILConfig::Backward,
        .mbpKind = Config::TILConfig::RealMbp,
        .recurrent_cycles = false,
        .recurrent_exps = true,
        .recurrent_pseudo_divs = false,
        .recurrent_bounds = true,
        .context_sensitive = false,
        .smtSolver = Config::Analysis::Z3
    };
    TIL f {forward, forwardConfig};
    TIL b {backward, backwardConfig};
    const auto f_setup {f.setup()};
    if (!f_setup) {
        if (Config::Analysis::log) {
            std::cout << "\n===== FORWARD SETUP FAILED =====" << std::endl;
        }
        b.analyze();
        return;
    }
    switch (*f_setup) {
    case SmtResult::Sat:
        f.sat();
        return;
    case SmtResult::Unsat:
        f.unsat();
        return;
    case SmtResult::Unknown:
        break;
    }
    const auto b_setup {b.setup()};
    if (!b_setup) {
        if (Config::Analysis::log) {
            std::cout << "\n===== BACKWARD SETUP FAILED =====" << std::endl;
        }
        while (true) {
            const auto res{f.do_step()};
            if (res) {
                switch (*res) {
                case SmtResult::Sat:
                    f.sat();
                    return;
                case SmtResult::Unsat:
                    f.unsat();
                    return;
                default:
                    std::cout << "unknown" << std::endl;
                    return;
                }
            }
        }
    }
    switch (*b_setup) {
    case SmtResult::Sat:
        b.sat();
        return;
    case SmtResult::Unsat:
        b.unsat();
        return;
    case SmtResult::Unknown:
        break;
    }
    TIL *active {&f};
    TIL *passive {&b};
    auto is_forward {true};
    while (true) {
        if (Config::Analysis::log) {
            if (is_forward) {
                std::cout << "\n===== FORWARD =====" << std::endl;
            } else {
                std::cout << "\n===== BACKWARD =====" << std::endl;
            }
        }
        auto res{active->do_step()};
        if (res) {
            if (res != SmtResult::Unknown) {
                if (Config::Analysis::log) {
                    if (is_forward) {
                        std::cout << "\n===== FORWARD SUCCEEDED =====" << std::endl;
                    } else {
                        std::cout << "\n===== BACKWARD SUCCEEDED =====" << std::endl;
                    }
                }
                switch (*res) {
                case SmtResult::Sat:
                    active->sat();
                    return;
                case SmtResult::Unsat:
                    active->unsat();
                    return;
                default:
                    std::cout << "unknown" << std::endl;
                    return;
                }
            }
            if (Config::Analysis::log) {
                if (is_forward) {
                    std::cout << "\n===== FORWARD FAILED =====" << std::endl;
                } else {
                    std::cout << "\n===== BACKWARD FAILED =====" << std::endl;
                }
            }
            while (true) {
                const auto res{passive->do_step()};
                if (res) {
                    switch (*res) {
                    case SmtResult::Sat:
                        passive->sat();
                        return;
                    case SmtResult::Unsat:
                        passive->unsat();
                        return;
                    default:
                        std::cout << "unknown" << std::endl;
                        return;
                    }
                }
            }
        }
        auto *tmp {active};
        active = passive;
        passive = tmp;
        is_forward = !is_forward;
    }
}