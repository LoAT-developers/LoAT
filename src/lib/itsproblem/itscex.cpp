#include "itscex.hpp"
#include <assert.h>

ITSCex::ITSCex(const ITSProblem &its): its(its) {}

bool ITSCex::is_valid_step(const Model &m) const {
    if (states.size() != transitions.size()) {
        return false;
    }
    if (transitions.empty()) {
        const auto &init{its.getInitialTransitions()};
        return std::any_of(init.begin(), init.end(), [&](const auto &i) {
            return m.eval<Bools>(i->getGuard());
        });
    } else {
        const auto &up{transitions.back()->getUpdate()};
        const auto &last{states.back()};
        for (const auto &x : its.getVars()) {
            if (theory::isProgVar(x) && m.get(x) != last.eval(up.get(x))) {
                return false;
            }
        }
        return true;
    }
}

bool ITSCex::try_step(const Model &m, const TransIdx trans) {
    if (!m.eval<Bools>(trans->getGuard()) || !is_valid_step(m)) {
        return false;
    }
    m.project(trans->vars());
    states.push_back(m);
    transitions.push_back(trans);
    return true;
}

void ITSCex::add_final_state(const Model &m) {
    assert(is_valid_step(m));
    const auto &err{its.getSinkTransitions()};
    const auto it{std::find_if(err.begin(), err.end(), [&](const auto &e) {
        return m.eval<Bools>(e->getGuard());
    })};
    assert(it != err.end());
    states.push_back(m.project((*it)->getGuard()->vars()));
}

std::ostream& operator<<(std::ostream &s, const ITSCex &cex) {
    for (size_t i = 0; i < cex.transitions.size(); ++i) {
        s << cex.states.at(i) << "\n-" << cex.transitions.at(i)->getId() << "->\n";
    }
    return s << cex.states.back();
}
