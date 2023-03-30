#include "accelerationresult.hpp"

bool acceleration::Result::successful() const {
    return accel || nonterm;
}

bool acceleration::Result::inexact() const {
    return !successful() || strengthened;
}
