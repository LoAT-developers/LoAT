#include "forwardbackwarddriver.hpp"
#include "config.hpp"
#include "til.hpp"
#include "chctosafetyproblem.hpp"

void ForwardBackwardDriver::analyze(CHCProblem p) {
    auto q {p.reverse()};
    Config::TILConfig forwardConfig {
        .mode = Config::TILConfig::Forward,
        .mbpKind = Config::TILConfig::LowerIntMbp,
        .recurrent_cycles = false,
        .recurrent_exps = true,
        .recurrent_divs = true,
        .recurrent_pseudo_divs = true,
        .recurrent_bounds = true,
        .context_sensitive = false
    };
    Config::TILConfig backwardConfig {
        .mode = Config::TILConfig::Backward,
        .mbpKind = Config::TILConfig::RealMbp,
        .recurrent_cycles = false,
        .recurrent_exps = true,
        .recurrent_divs = false,
        .recurrent_pseudo_divs = false,
        .recurrent_bounds = true,
        .context_sensitive = false
    };
    TIL f {p, forwardConfig};
    TIL b {q, backwardConfig};
    if (!f.setup()) {
        if (Config::Analysis::log) {
            std::cout << "\n===== FORWARD SETUP FAILED =====" << std::endl;
        }
        b.analyze();
        return;
    }
    if (!b.setup()) {
        if (Config::Analysis::log) {
            std::cout << "\n===== BACKWARD SETUP FAILED =====" << std::endl;
        }
        while (true) {
            const auto res{f.do_step()};
            if (res) {
                if (res == SmtResult::Sat) {
                    f.sat();
                } else {
                    std::cout << "unknown" << std::endl;
                }
                return;
            }
        }
    }
    TIL *active {&f};
    TIL *passive {&b};
    auto forward {true};
    while (true) {
        if (Config::Analysis::log) {
            if (forward) {
                std::cout << "\n===== FORWARD =====" << std::endl;
            } else {
                std::cout << "\n===== BACKWARD =====" << std::endl;
            }
            forward = !forward;
        }
        auto res {active->do_step()};
        if (res) {
            if (res == SmtResult::Sat) {
                if (forward) {
                    std::cout << "\n===== FORWARD SUCCEEDED =====" << std::endl;
                } else {
                    std::cout << "\n===== BACKWARD SUCCEEDED =====" << std::endl;
                }
                active->sat();
                return;
            }
            if (forward) {
                std::cout << "\n===== FORWARD FAILED =====" << std::endl;
            } else {
                std::cout << "\n===== BACKWARD FAILED =====" << std::endl;
            }
            while (true) {
                const auto res {passive->do_step()};
                if (res) {
                    if (res == SmtResult::Sat) {
                        passive->sat();
                    } else {
                        std::cout << "unknown" << std::endl;
                    }
                    return;
                }
            }
        }
        auto *tmp {active};
        active = passive;
        passive = tmp;
    }
}