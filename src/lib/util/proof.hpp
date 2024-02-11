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
#include <stack>

#include <boost/algorithm/string.hpp>

class Proof {
public:
    enum Style {
        Section,
        Headline,
        Result,
        None
    };

    static void setProofLevel(unsigned int proofLevel);

    static bool disabled();

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

    void print(unsigned level = 1) const;

    void storeSubProof(const Proof &subProof);

    void concat(const Proof &that);

    bool empty() const;

    void push();

    void pop();

    static unsigned int defaultProofLevel;

    static void disableColors() {
        use_colors = false;
    }

private:

    static unsigned int proofLevel;

    static bool use_colors;

    using ProofStep = std::pair<Style, std::string>;

    std::vector<std::variant<ProofStep, Proof>> proof{};

    std::stack<unsigned> pop_stack{};

};
