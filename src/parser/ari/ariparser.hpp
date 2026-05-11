#pragma once

#include "chcproblem.hpp"

class SMTLibParsingState;

class ARIParser {

    CHCPtr its {std::make_shared<CHCProblem>()};
    std::unordered_map<std::string, std::vector<theory::Type>> types;

    FunAppPtr parseFunApp(const sexpresso::Sexp& sexp, SMTLibParsingState& state) const;
    void run(const std::string &filename);

public:

    static CHCPtr loadFromFile(const std::string &filename);

};
