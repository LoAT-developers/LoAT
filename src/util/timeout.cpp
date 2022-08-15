/*  This file is part of LoAT.
 *  Copyright (c) 2015-2016 Matthias Naaf, RWTH Aachen University, Germany
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses>.
 */

#include "timeout.hpp"
#include "config.hpp"

#include <algorithm>
#include <iostream>
#include <assert.h>

using namespace std;

static bool timeout_enable = false;
static TimePoint timeout_start;
static TimePoint timeout_soft;
static TimePoint timeout_hard;

void Timeout::setTimeouts(unsigned int seconds) {
    assert(seconds == 0 || seconds >= 10);
    timeout_start = chrono::steady_clock::now();

    if (seconds > 0) {
        unsigned long slack = max(5u, min(60u, seconds * 15 / 100));
        timeout_soft = timeout_start + static_cast<std::chrono::seconds>(seconds - slack);
        timeout_hard = timeout_start + static_cast<std::chrono::seconds>(seconds - 2);
        timeout_enable = true;
    }
}

bool Timeout::hard() {
    if (!timeout_enable || Config::Analysis::nonTermination()) return false;
    return remainingHard().count() <= 0;
}

bool Timeout::soft() {
    if (!timeout_enable) return false;
    return remainingSoft().count() <= 0;
}

bool Timeout::enabled() {
    return timeout_enable;
}

std::chrono::seconds Timeout::remainingSoft() {
    return std::chrono::duration_cast<std::chrono::seconds>(timeout_soft - chrono::steady_clock::now());
}

std::chrono::seconds Timeout::remainingHard() {
    return std::chrono::duration_cast<std::chrono::seconds>(timeout_hard - chrono::steady_clock::now());
}
