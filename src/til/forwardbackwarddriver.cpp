#include "forwardbackwarddriver.hpp"
#include "config.hpp"

void ForwardBackwardDriver::analyze(SafetyProblem p) {
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
        b.analyze();
        return;
    }
    if (!b.setup()) {
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
    while (true) {
        auto res {active->do_step()};
        if (res) {
            if (res == SmtResult::Sat) {
                active->sat();
                return;
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