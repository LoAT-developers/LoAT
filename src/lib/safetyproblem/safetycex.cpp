#include "safetycex.hpp"

SafetyCex::SafetyCex(const SafetyProblem &sp): sp(sp) {}

bool SafetyCex::is_valid_step(const Model &m) const {
    if (states.size() != transitions.size()) {
        return false;
    }
    if (transitions.empty()) {
        return m.eval<Bools>(sp.init());
    } else {
        const auto &last {states.back()};
        for (const auto &x: sp.pre_vars()) {
            if (theory::isProgVar(x) && last.get(theory::postVar(x)) != m.get(x)) {
                return false;
            }
        }
        return true;
    }
}

bool SafetyCex::try_step(const Model &m, const Bools::Expr trans) {
    if (!m.eval<Bools>(trans) || !is_valid_step(m)) {
        return false;
    }
    states.push_back(m);
    transitions.push_back(trans);
    return true;
}

std::ostream& operator<<(std::ostream &s, const SafetyCex &cex) {
    unsigned id {0};
    std::unordered_map<Bools::Expr, unsigned> transitions;
    for (const auto &t: cex.transitions) {
        if (transitions.emplace(t, id).second) {
            ++id;
        }
    }
    s << "input:" << std::endl;
    s << "\tinit: " << cex.sp.init() << std::endl;
    s << "\terr: " << cex.sp.err() << std::endl;
    for (const auto &[t,id]: transitions) {
        s << "\t" << id << ": " << t << std::endl;
    }
    s << "\ncounterexample:" << std::endl;
    for (size_t i = 0; i < cex.transitions.size(); ++i) {
        const auto &trans {cex.transitions.at(i)};
        const auto vars {trans->vars()};
        const auto projection {cex.states.at(i).project([&](const auto &x) {
                return theory::isProgVar(x) || vars.contains(x);
            })
        };
        s << "\t" << projection << "\n\t-" << transitions.at(trans) << "->\n";
    }
    return s << "\terr";
}

std::pair<const Model&, Bools::Expr> SafetyCex::get_step(size_t i) const {
    return {states.at(i), transitions.at(i)};
}

size_t SafetyCex::size() const {
    return states.size();
}
