#ifndef ITSPARSER_H
#define ITSPARSER_H

#include <string>
#include <vector>

#include "itsproblem.hpp"

namespace parser {

class ITSParser {
public:
    /**
     * Tries to load the given file and convert it into an ITSProblem
     * @param path The file to load
     * @return The resulting ITSProblem (a FileError is thrown if parsing fails)
     */
    static ITSProblem loadFromFile(const std::string &path);
};

}

#endif //ITSPARSER_H
