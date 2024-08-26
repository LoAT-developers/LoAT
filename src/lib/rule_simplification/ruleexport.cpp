#include "ruleexport.hpp"

using namespace std;

void RuleExport::printRule(const Rule &rule, std::ostream &s) {
    s << rule.getId() << ": ";
    s << rule.getGuard();
    s << " /\\ ";
    bool first = true;
    for (const auto &[x,v] : rule.getUpdate()) {
        if (first) {
            first = false;
        } else {
            s << ", ";
        }
        s << x << "'";
        s << " = " << v;
    }
}
