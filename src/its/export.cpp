#include "export.hpp"
#include "config.hpp"
#include "theory.hpp"
#include "expr.hpp"
#include "ruleexport.hpp"

using namespace RuleExport;
using namespace std;
namespace Color = Config::Color;

/**
 * Helper that prints the location's name or (if it has no name) its index to the given stream
 */
static void printLocation(LocationIdx loc, const ITSProblem &its, std::ostream &s, bool colors) {
    if (colors) printColor(s, Color::Location);
    s << its.getPrintableLocationName(loc);
    if (colors) printColor(s, Color::None);
}

void ITSExport::printForProof(const ITSProblem &its, std::ostream &s) {
    s << "Start location: ";
    printLocation(its.getInitialLocation(), its, s, true);
    s << endl << endl;
    if (!its.getLocations().empty()) {
        s << "Location map:" << std::endl;
        for (const auto p: its.getLocations()) {
            printLocation(p, its, s, true);
            s << " -> " << p << std::endl;
        }
    }
    s << endl << endl;
    s << "Rules:" << endl;
    if (its.isEmpty()) {
        s << "  <empty>" << endl;
    } else {
        for (const auto &idx : its.getAllTransitions()) {
            s << setw(4);
            printRule(idx, s);
            s << endl;
        }
    }
    if (Config::Output::PrintDependencyGraph) {
        s << endl << "Dependency graph:" << endl;
        s << its.getDependencyGraph() << endl;
    }
}

std::ostream& operator<<(std::ostream &s, const ITSProblem &its) {
    ITSExport::printForProof(its, s);
    return s;
}
