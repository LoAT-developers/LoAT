#include "ruleexport.hpp"
#include "config.hpp"

using namespace std;
namespace Color = Config::Color;


/**
 * Helper to display colors only if colored export is enabled.
 */
void RuleExport::printColor(ostream &os, const std::string &s) {
    if (Config::Output::Colors) {
        os << s;
    }
}

void RuleExport::printGuard(const Bools::Expr guard, std::ostream &s, bool colors) {
    if (colors) printColor(s, Color::Guard);
    s << guard;
}

void RuleExport::printRule(const Rule &rule, std::ostream &s, bool colors) {
    s << rule.getId() << ": ";
    printGuard(rule.getGuard(), s, colors);
    s << " /\\ ";
    bool first = true;
    for (const auto &[x,v] : rule.getUpdate()) {
        if (first) {
            first = false;
        } else {
            s << ", ";
        }
        if (colors) printColor(s, Color::Update);
        s << x << "'";
        s << "=" << v;
        if (colors) printColor(s, Color::None);
    }
}
