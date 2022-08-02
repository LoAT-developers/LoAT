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

#ifndef PROOFOUTPUT_H
#define PROOFOUTPUT_H

#include <streambuf>
#include <ostream>
#include <string>

#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <variant>

#include <boost/algorithm/string.hpp>

#include "../config.hpp"
#include "../its/itsproblem.hpp"

class Proof {
public:
    enum Style {
        Section,
        Headline,
        Result,
        None
    };

    static void setProofLevel(unsigned int proofLevel);

    Proof();

    void append(const std::string &s);

    void append(const std::ostream &s);

    void append(const Style &style, std::string s);

    void newline();

    void headline(const std::string &s);

    void headline(const std::ostream &s);

    void section(const std::string &s);

    void section(const std::ostream &s);

    void result(const std::string &s);

    void result(const std::ostream &s);

    void print() const;

    void ruleTransformationProof(const Rule &oldRule, const std::string &transformation, const Rule &newRule, const ITSProblem &its);

    void majorProofStep(const std::string &step, const ITSProblem &its);

    void minorProofStep(const std::string &step, const ITSProblem &its);

    void deletionProof(const std::set<TransIdx> &rules);

    void storeSubProof(Proof subProof, const std::string &technique);

    void chainingProof(const Rule &fst, const Rule &snd, const Rule &newRule, const ITSProblem &its);

    void concat(const Proof &that);

    bool empty() const;

    static unsigned int defaultProofLevel;

    static unsigned int maxProofLevel;

private:

    static unsigned int proofLevel;

    using ProofStep = std::pair<Style, std::string>;

    std::vector<std::variant<ProofStep, Proof>> proof;

    unsigned level;

};

#endif // PROOFOUTPUT_H
