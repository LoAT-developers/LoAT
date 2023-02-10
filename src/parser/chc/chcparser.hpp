#pragma once

#include <string>
#include <vector>

#include "itsproblem.hpp"

namespace hornParser {

class HornParser {
public:
    /**
     * Tries to load the given file and convert it into an ITSProblem
     * @param path The file to load
     * @return The resulting ITSProblem (a FileError is thrown if parsing fails)
     */
    static ITSProblem loadFromFile(const std::string &path);

};

}
