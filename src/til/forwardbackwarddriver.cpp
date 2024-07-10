#include "forwardbackwarddriver.hpp"

void ForwardBackwardDriver::analyze(SafetyProblem p) {
    auto q {p.reverse()};
    TIL f {p};
    TIL b {q};
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