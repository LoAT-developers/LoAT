#pragma once

#include "itsproblem.hpp"

class ARIParser {

    ITSPtr its {std::make_shared<ITSProblem>()};
    std::unordered_map<std::string, std::vector<theory::Type>> types;

    void run(const std::string &filename);

public:

    static ITSPtr loadFromFile(const std::string &filename);

};
