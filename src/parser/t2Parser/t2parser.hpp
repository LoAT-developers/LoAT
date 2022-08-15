/*  This file is part of LoAT.
 *  Copyright (c) 2019 Florian Frohn
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

#ifndef LOAT_T2_PARSER_H
#define LOAT_T2_PARSER_H


#include "itsproblem.hpp"

namespace t2parser {

    class T2Parser {

    public:
        static ITSProblem loadFromFile(const std::string &filename);

    private:
        void run(const std::string &filename);

        void parseTransition(LocationIdx start, std::ifstream &ifs);

        LocationIdx getLoc(const std::string &str);

        Var addVar(const std::string &str);

        Rel parseConstraint(const std::string &str);

        Expr parseExpression(std::string str);

        std::string trim(std::string toTrim, std::string prefix, std::string suffix);

        std::string removeComment(const std::string &string);

        ITSProblem res;

        const std::string START = "START:";
        const std::string FROM = "FROM:";
        const std::string TO = "TO:";
        const std::string ASSUME = "assume(";
        const std::string NONDET = "nondet()";
        const std::string ASSIGN = ":=";
        std::map<std::string, LocationIdx> locs;
        std::map<std::string, Var> vars;
        std::map<std::string, GiNaC::ex> symtab;

    };

}

#endif //LOAT_T2_PARSER_H
