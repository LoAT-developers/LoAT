#pragma once

#include "chcproblem.hpp"
#include "smtlibutil.hpp"

class SexpressoParser {

    CHCPtr chcs {std::make_shared<CHCProblem>()};

    SMTLibParsingState state;

    void run(const std::string &filename);

public:

    static CHCPtr loadFromFile(const std::string &filename);

};
