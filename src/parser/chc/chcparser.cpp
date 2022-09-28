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

#include "chcparser.hpp"
#include "exceptions.hpp"
#include "CHCLexer.h"
#include "CHCParser.h"
#include "CHCParseVisitor.h"

using namespace antlr4;

using namespace hornParser;

ITSProblem HornParser::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileError("Unable to open file: " + filename);
    }
    ANTLRInputStream input(file);
    CHCLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CHCParser parser(&tokens);
    parser.setBuildParseTree(true);
    CHCParseVisitor vis;
    auto ctx = parser.main();
    if (parser.getNumberOfSyntaxErrors() > 0) {
        throw FileError("parsing failed");
    } else {
        return any_cast<ITSProblem>(vis.visit(ctx));
    }
}
