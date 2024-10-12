#include "interleaved.hpp"
#include "config.hpp"

Interleaved::Interleaved(
    const ITSPtr forward,
    const ITSPtr backward,
    const Config::TILConfig &f_conf,
    const Config::TILConfig &b_conf):
    f(forward, f_conf),
    b(backward, b_conf) {}

SmtResult Interleaved::analyze() {
    f.setup();
    b.setup();
    active = &f;
    passive = &b;
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
                return *res;
            }
            if (Config::Analysis::log) {
                if (is_forward) {
                    std::cout << "\n===== FORWARD FAILED =====" << std::endl;
                } else {
                    std::cout << "\n===== BACKWARD FAILED =====" << std::endl;
                }
            }
            active = passive;
            while (true) {
                const auto res{active->do_step()};
                if (res) {
                    return *res;
                }
            }
        }
        auto *tmp {active};
        active = passive;
        passive = tmp;
        is_forward = !is_forward;
    }
}

ITSModel Interleaved::get_model() {
    return active->get_model();
}

ITSSafetyCex Interleaved::get_cex() {
    return active->get_cex();
}

bool Interleaved::is_forward() const {
    return active == &f;
}
