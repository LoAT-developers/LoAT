#pragma once

#include <string>
#include <vector>

#include "itsproblem.hpp"

namespace cintParser {

class CIntParser {
public:

    static ITSPtr loadFromFile(const std::string &path);

};

}
