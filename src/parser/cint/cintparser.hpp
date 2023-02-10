#pragma once

#include <string>
#include <vector>

#include "itsproblem.hpp"

namespace cintParser {

class CIntParser {
public:

    static ITSProblem loadFromFile(const std::string &path);

};

}
