#include "export.hpp"
#include "config.hpp"
#include "theory.hpp"
#include "expr.hpp"

using namespace std;
namespace Color = Config::Color;


/**
 * Helper to display colors only if colored export is enabled.
 */
static void printColor(ostream &os, const std::string &s) {
    if (Config::Output::Colors) {
        os << s;
    }
}

/**
 * Helper that prints the location's name or (if it has no name) its index to the given stream
 */
static void printLocation(LocationIdx loc, const ITSProblem &its, std::ostream &s, bool colors) {
    if (colors) printColor(s, Color::Location);
    s << its.getPrintableLocationName(loc);
    if (colors) printColor(s, Color::None);
}

void ITSExport::printGuard(const BoolExpr guard, std::ostream &s, bool colors) {
    if (colors) printColor(s, Color::Guard);
    s << guard;
}

void ITSExport::printRule(const Rule &rule, std::ostream &s, bool colors) {
    s << rule.getId() << ": ";
    printGuard(rule.getGuard(), s, colors);
    s << " /\\ ";
    bool first = true;
    for (auto upit : rule.getUpdate()) {
        if (first) {
            first = false;
        } else {
            s << ", ";
        }
        if (colors) printColor(s, Color::Update);
        s << expr::first(upit) << "'";
        s << "=" << expr::second(upit);
        if (colors) printColor(s, Color::None);
    }
}

void ITSExport::printForProof(const ITSProblem &its, std::ostream &s) {
    s << "Start location: ";
    printLocation(its.getInitialLocation(), its, s, true);
    s << endl << endl;
    if (!its.getLocationNames().empty()) {
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
    s << endl << "Dependency graph:" << endl;
    s << its.getDependencyGraph() << endl;
}

std::ostream& operator<<(std::ostream &s, const ITSProblem &its) {
    ITSExport::printForProof(its, s);
    return s;
}
