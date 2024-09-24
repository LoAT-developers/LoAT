#include "forwardbackwarddriver.hpp"
#include "config.hpp"

Config::TILConfig forwardConfig{
    .mode = Config::TILConfig::Forward,
    .mbpKind = Config::TILConfig::LowerIntMbp,
    .recurrent_cycles = false,
    .recurrent_exps = true,
    .recurrent_pseudo_divs = true,
    .recurrent_bounds = true,
    .context_sensitive = false};

Config::TILConfig backwardConfig{
    .mode = Config::TILConfig::Backward,
    .mbpKind = Config::TILConfig::RealMbp,
    .recurrent_cycles = false,
    .recurrent_exps = true,
    .recurrent_pseudo_divs = false,
    .recurrent_bounds = true,
    .context_sensitive = false};

ForwardBackwardDriver::ForwardBackwardDriver(
    const ITSPtr forward,
    const ITSPtr backward):
    f(forward, forwardConfig),
    b(backward, backwardConfig) {}

SmtResult ForwardBackwardDriver::analyze() {
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

ITSModel ForwardBackwardDriver::get_model() {
    return active->get_model();
}

ITSCex ForwardBackwardDriver::get_cex() {
    return active->get_cex();
}

bool ForwardBackwardDriver::is_forward() const {
    return active == &f;
}
