#pragma once

#include <ostream>
#include <string>

#include "itsproblem.hpp"


namespace ITSExport {

    /**
     * Prints the ITS problem in a readable but ugly format for debugging
     */
    void printDebug(const ITSProblem &its, std::ostream &s);

    /**
     * Print the ITS problem in a more readable format suitable for the proof output
     */
    void printForProof(const ITSProblem &its, std::ostream &s);

    void printKoAT(const ITSProblem &its, std::ostream &s);

}

std::ostream& operator<<(std::ostream &s, const ITSProblem &its);
