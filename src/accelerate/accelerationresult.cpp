#include "accelerationresult.hpp"

bool AccelerationResult::successful() const {
    return rule || nontermRule;
}

bool AccelerationResult::inexact() const {
    return !successful() || strengthened;
}

std::vector<Rule> AccelerationResult::rules() const {
    std::vector<Rule> res;
    if ( rule) {
        res.push_back(*rule);
    }
    if (nontermRule) {
        res.push_back(*nontermRule);
    }
    return res;
}
