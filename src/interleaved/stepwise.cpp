#include "stepwise.hpp"

StepwiseAnalysis::~StepwiseAnalysis(){}

SmtResult StepwiseAnalysis::analyze() {
    while (true) {
        if (const auto res{do_step()}) {
            return *res;
        }
    }
}