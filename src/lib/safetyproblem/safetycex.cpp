#include "safetycex.hpp"

#include <utility>

SafetyCex::SafetyCex(SafetyProblem sp): sp(std::move(sp)) {}

bool SafetyCex::is_valid_step(const ModelPtr &m) const {
    if (states.size() != transitions.size()) {
        return false;
    }
    if (transitions.empty()) {
        return m->eval(sp.init());
    }
    const auto &last {states.back()};
    for (const auto &x: sp.pre_vars()) {
        if (!theory::apply(x, [&](const auto &x) {
            return m->contains(x) && last->get(x->postVar(x)) == m->get(x);
        })) {
            return false;
        }
    }
    return true;
}

bool SafetyCex::try_step(const ModelPtr &m, const Bools::Expr& trans) {
    if (!m->eval(trans) || !is_valid_step(m)) {
        return false;
    }
    states.push_back(m);
    transitions.push_back(trans);
    return true;
}

void SafetyCex::set_final_state(const ModelPtr &m) {
    const auto vars {sp.err()->vars()};
    assert(std::all_of(vars.begin(), vars.end(), [&](const auto &x) {
        return vars.contains(x);
    }));
    assert(m->eval(sp.err()));
    states.push_back(m);
}

std::ostream& operator<<(std::ostream &s, const SafetyCex &cex) {
    unsigned id {0};
    std::unordered_map<Bools::Expr, unsigned> transitions;
    for (const auto &t: cex.transitions) {
        if (transitions.emplace(t, id).second) {
            ++id;
        }
    }
    s << "init: " << cex.sp.init();
    s << "\n\nerr: " << cex.sp.err();
    s << "\n\nunsat core:" << std::endl;
    for (const auto &[t,id]: transitions) {
        s << "\t" << id << ": " << t << std::endl;
    }
    s << "\ncounterexample:" << std::endl;
    for (size_t i = 0; i < cex.transitions.size(); ++i) {
        const auto &trans {cex.transitions.at(i)};
        const auto vars {trans->vars()};
        const auto projection {cex.states.at(i)->project([&](const auto &x) {
                return theory::isProgVar(x) || vars.contains(x);
            })
        };
        s << "\t" << projection << "\n\t-" << transitions.at(trans) << "->\n";
    }
    return s << "\terr";
}

std::pair<const ModelPtr&, Bools::Expr> SafetyCex::get_step(const size_t i) const {
    return {states.at(i), transitions.at(i)};
}

const ModelPtr& SafetyCex::get_state(const size_t i) const {
    return states.at(i);
}

size_t SafetyCex::num_states() const {
    return states.size();
}

size_t SafetyCex::num_transitions() const {
    return transitions.size();
}
