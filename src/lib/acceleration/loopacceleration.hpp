/*  This file is part of LoAT.
 *  Copyright (c) 2018-2019 Florian Frohn
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

#pragma once

#include "rule.hpp"
#include "accelerationresult.hpp"
#include "accelconfig.hpp"

class LoopAcceleration {
public:

    struct AcceleratedRules {
        const std::vector<Rule> rules;
        const unsigned int validityBound;
    };

    static acceleration::Result accelerate(const Rule &rule, const Subs &sample_point, const AccelConfig &config = AccelConfig());

    static const std::pair<Rule, unsigned> chain(const Rule &rule);

private:
    LoopAcceleration(const Rule &rule, const Subs &sample_point, const AccelConfig &config);

    /**
     * Main function, just calls the methods below in the correct order
     */
    acceleration::Result run();

    static Rule renameTmpVars(const Rule &rule);

private:
    Rule rule;
    const Subs sample_point;
    const AccelConfig config;
};
