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

#pragma once

#include <streambuf>
#include <ostream>
#include <string>

#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <variant>

#include <boost/algorithm/string.hpp>

#include "itsproblem.hpp"
#include "proof.hpp"

class ITSProof: public Proof {
public:

    void ruleTransformationProof(const Rule &oldRule, const std::string &transformation, const Rule &newRule, const ITSProblem &its);

    void majorProofStep(const std::string &step, const ITSProblem &its);

    void minorProofStep(const std::string &step, const ITSProblem &its);

    void deletionProof(const std::set<TransIdx> &rules);

    void chainingProof(const Rule &fst, const Rule &snd, const Rule &newRule);

};
