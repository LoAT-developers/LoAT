#include "export.hpp"
#include "config.hpp"
#include "rel.hpp"

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


void ITSExport::printCost(const Expr &cost, std::ostream &s, bool colors) {
    if (colors) printColor(s, Color::Cost);
    s << cost;
    if (colors) printColor(s, Color::None);

}


void ITSExport::printRule(const Rule &rule, const ITSProblem &its, std::ostream &s, bool colors) {
    printLocation(rule.getLhsLoc(), its, s, colors);
    s << " -> ";

    for (auto it = rule.rhsBegin(); it != rule.rhsEnd(); ++it) {
        printLocation(it->getLoc(), its, s, colors);
        s << " : ";

        for (auto upit : it->getUpdate()) {
            if (colors) printColor(s, Color::Update);
            s << upit.first << "'";
            s << "=" << upit.second;
            if (colors) printColor(s, Color::None);
            s << ", ";
        }
    }

    printGuard(rule.getGuard(), s, colors);
    s << ", cost: ";
    printCost(rule.getCost(), s, colors);
}


void ITSExport::printLabeledRule(TransIdx rule, const ITSProblem &its, std::ostream &s) {
    s << setw(4) << rule << ": ";
    printRule(its.getRule(rule), its, s, true);
}


void ITSExport::printDebug(const ITSProblem &its, std::ostream &s) {
    s << "Variables:";
    for (const Var &x: its.getVars()) {
        s << " " << x;
        if (its.isTempVar(x)) {
            s << "*";
        }
    }
    s << endl;

    s << "Nodes:";
    for (LocationIdx loc : its.getLocations()) {
        s << " " << loc;
        auto optName = its.getLocationName(loc);
        if (optName) {
            s << "/" << optName.get();
        }
        if (its.isInitialLocation(loc)) {
            s << "*";
        }
    }
    s << endl;

    s << "Transitions:" << endl;
    for (LocationIdx loc : its.getLocations()) {
        for (TransIdx trans : its.getTransitionsFrom(loc)) {
            printLabeledRule(trans, its, s);
            s << endl;
        }
    }
}


void ITSExport::printForProof(const ITSProblem &its, std::ostream &s) {
    s << "Start location: ";
    printLocation(its.getInitialLocation(), its, s, true);
    s << endl;
    s << "Program variables:";
    for (const Var &x: its.getVars()) {
        if (!its.isTempVar(x)) {
            s << " " << x;
        }
    }
    s << endl;

    if (its.isEmpty()) {
        s << "  <empty>" << endl;
        return;
    }

    for (LocationIdx n : its.getLocations()) {
        for (TransIdx trans : its.getTransitionsFrom(n)) {
            printLabeledRule(trans, its, s);
            s << endl;
        }
    }
}

void ITSExport::printKoAT(const ITSProblem &its, std::ostream &s) {
    auto printNode = [&](LocationIdx n) {
        auto optName = its.getLocationName(n);
        if (optName) {
            s << optName.get();
        } else {
            s << "loc" << n << "'";
        }
    };

    s << "(GOAL COMPLEXITY)" << endl;
    s << "(STARTTERM (FUNCTIONSYMBOLS "; printNode(its.getInitialLocation()); s << "))" << endl;
    s << "(VAR";

    // collect variables that actually appear in the rules
    VarSet vars;
    for (TransIdx rule : its.getAllTransitions()) {
        VarSet rVars = its.getRule(rule).vars();
        vars.insert(rVars.begin(), rVars.end());
    }
    for (const Var &var : vars) {
        s << " " << var;
    }

    s << ")" << endl << "(RULES" << endl;

    for (LocationIdx n : its.getLocations()) {
        // figure out which variables appear on the lhs of the given location
        VarSet relevantVars;
        for (auto x: its.getVars()) {
            if (!its.isTempVar(x)) {
                relevantVars.insert(x);
            }
        }

        //write transition in KoAT format (note that relevantVars is an ordered set)
        for (TransIdx trans : its.getTransitionsFrom(n)) {
            const Rule &rule = its.getRule(trans);
            if (!rule.isSimpleLoop() || rule.getGuard()->size() < 30) continue;
            //lhs
            printNode(n);
            bool first = true;
            for (const Var &var : relevantVars) {
                s << ((first) ? "(" : ",");
                s << var;
                first = false;
            }

            //cost
            s << ") -{" << rule.getCost().expand() << "," << rule.getCost().expand() << "}> ";

            //rhs updates
            if (rule.rhsCount() > 1) {
                s << "Com_" << rule.rhsCount() << "(";
            }

            for (auto rhs = rule.rhsBegin(); rhs != rule.rhsEnd(); ++rhs) {
                if (rhs != rule.rhsBegin()) s << ",";
                printNode(rhs->getLoc());

                first = true;
                for (const Var &var : relevantVars) {
                    s << ((first) ? "(" : ",");
                    auto it = rhs->getUpdate().find(var);
                    if (it != rhs->getUpdate().end()) {
                        s << it->second.expand();
                    } else {
                        s << var;
                    }
                    first = false;
                }
            }

            if (rule.rhsCount() > 1) {
                s << ")";
            }

            //guard
            s << ") :|: ";
            assert(rule.getGuard()->isConjunction());
            first = true;
            for (auto lit: rule.getGuard()->lits()) {
                if (first) first = false;
                else s << " && ";
                s << lit;
            }
            s << endl;
        }
    }
    s << ")" << endl;
}
