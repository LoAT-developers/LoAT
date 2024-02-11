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

    void majorProofStep(const std::string &step, const Proof &subproof, const ITSProblem &its);

    template <class Edge>
    void dependencyGraphRefinementProof(const linked_hash_set<Edge> &removed) {
        if (Proof::disabled()) {
            return;
        }
        if (!removed.empty()) {
            std::stringstream s;
            s << "Removed the following edges from the dependency graph:" << std::endl;
            for (const auto &e: removed) {
                s << e.first << " -> " << e.second << std::endl;
            }
            append(s);
        }
    }

    void deletionProof(const linked_hash_set<TransIdx> &rules);

    void chainingProof(const Rule &fst, const Rule &snd, const Rule &newRule);

};
