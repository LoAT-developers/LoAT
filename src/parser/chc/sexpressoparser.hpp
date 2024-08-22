#pragma once

#include "chcproblem.hpp"

class SexpressoParser {

    CHCProblem chcs;

    void run(const std::string &filename);

public:

    static CHCProblem loadFromFile(const std::string &filename);

};