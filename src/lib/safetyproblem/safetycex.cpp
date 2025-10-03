#include "safetycex.hpp"

#include <utility>

SafetyCex::SafetyCex(SafetyProblem sp): sp(std::move(sp)) {}

bool SafetyCex::try_step(const ModelPtr &m, const Bools::Expr& trans) {
    if (!m->eval(trans)) {
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
    VarSet prog_vars;
    for (const auto& b: {cex.sp.init(), cex.sp.err()}) {
        for (const auto& x: b->vars()) {
            if (theory::isProgVar(x)) {
                prog_vars.insert(x);
            }
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
        auto vars {trans->vars()};
        for (const auto& x: vars) {
            if (theory::isProgVar(x)) {
                prog_vars.insert(x);
            }
        }
        vars.insertAll(prog_vars);
        s << "\t";
        cex.states.at(i)->print(s, vars);
        s << "\n\t-" << transitions.at(trans) << "->\n";
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
