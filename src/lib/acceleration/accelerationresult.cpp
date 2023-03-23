#include "accelerationresult.hpp"

bool acceleration::Result::successful() const {
    return rule || nontermCertificate != BExpression::False;
}

bool acceleration::Result::inexact() const {
    return !successful() || strengthened;
}
