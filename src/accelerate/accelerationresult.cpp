#include "accelerationresult.hpp"

bool acceleration::Result::successful() const {
    return rule || nontermRule;
}

bool acceleration::Result::inexact() const {
    return !successful() || strengthened;
}

std::vector<Rule> acceleration::Result::rules() const {
    std::vector<Rule> res;
    if ( rule) {
        res.push_back(*rule);
    }
    if (nontermRule) {
        res.push_back(*nontermRule);
    }
    return res;
}
