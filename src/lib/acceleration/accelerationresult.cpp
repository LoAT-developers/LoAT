#include "accelerationresult.hpp"

bool acceleration::Result::successful() const {
    return accel || nonterm;
}
