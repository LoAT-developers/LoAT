#pragma once

#include <ostream>
#include <string>

#include "itsproblem.hpp"


namespace ITSExport {

    void printForProof(const ITSProblem &its, std::ostream &s);

}

std::ostream& operator<<(std::ostream &s, const ITSProblem &its);
