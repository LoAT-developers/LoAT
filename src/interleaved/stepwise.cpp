#include "stepwise.hpp"

SmtResult StepwiseAnalysis::analyze() {
    while (true) {
        if (const auto res{do_step()}) {
            return *res;
        }
    }
}