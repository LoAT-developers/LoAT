#pragma once

#include "chcproblem.hpp"

class SexpressoParser {

    CHCPtr chcs {std::make_shared<CHCProblem>()};

    void run(const std::string &filename) const;

public:

    static CHCPtr loadFromFile(const std::string &filename);

};
