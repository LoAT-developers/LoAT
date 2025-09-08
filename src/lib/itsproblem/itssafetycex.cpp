#include "itssafetycex.hpp"
#include "formulapreprocessing.hpp"
#include "vector.hpp"
#include "smtfactory.hpp"

#include <cassert>

ITSSafetyCex::ITSSafetyCex(const ITSPtr& its): ITSCex(its) {}

bool ITSSafetyCex::try_step(const RulePtr& trans, const ModelPtr &next) {
    const auto last {states.back()};
    const auto solver {SmtFactory::modelBuildingSolver(QF_NAT)};
    solver->add(last->evalPartially(trans->getGuard()));
    const auto &up{trans->getUpdate()};
    for (const auto &x : its->getVars()) {
        if (theory::isProgVar(x) && next->contains(x)) {
            theory::apply(x, Overload{
                [&](const Arith::Var &y) {
                    solver->add(arith::mkEq(arith::mkConst(next->get(y)), last->evalPartially(up.get<Arith>(y))));
                },
            [&](const Bools::Var &y){
                solver->add(bools::mkEq(next->get(y) ? top() : bot(), last->evalPartially(up.get<Bools>(y))));
            }});

        }
    }
    if (solver->check() == SmtResult::Sat) {
        const auto new_last{last->unite(solver->model())};
        states.pop_back();
        states.push_back(new_last);
        auto new_next{next};
        for (const auto &x : its->getVars()) {
            if (theory::isProgVar(x) && !new_next->contains(x)) {
                std::visit(
                    Overload{
                        [&](const auto &y) {
                            using Th = decltype(theory::theory(y));
                            new_next->put(y, new_last->eval(up.get<Th>(y)));
                        }},
                    x);
            }
        }
        states.push_back(new_next);
        transitions.push_back(trans);
        return true;
    }
    return false;
}

void ITSSafetyCex::set_initial_state(const ModelPtr &m) {
    assert(transitions.empty());
    states.clear();
    states.push_back(m);
}

bool ITSSafetyCex::try_final_transition(const RulePtr& trans) {
    assert(trans->getUpdate().get<Arith>(its->getLocVar()) == arith::mkConst(its->getSink()));
    const auto solver {SmtFactory::modelBuildingSolver(QF_NAT)};
    auto &last {states.back()};
    solver->add(last->evalPartially(trans->getGuard()));
    if (solver->check() == SmtResult::Sat) {
        last = last->unite(solver->model());
        transitions.push_back(trans);
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream &s, const ITSSafetyCex &cex) {
    const auto derived {cex.get_used_rules()};
    s << "init: " << cex.its->getLocVar() << " = " << cex.its->getInitialLocation();
    s << "\n\nerr: " << cex.its->getLocVar() << " = " << cex.its->getSink();
    if (!derived.empty()) {
        s << "\n\nrules:" << std::endl;
        for (const auto &[t,kind]: derived) {
            s << "\t" << *t << std::endl;
            switch (kind) {
                case ProofStepKind::ORIG: {
                    s << "\t\toriginal rule" << std::endl;
                    break;
                }
                case ProofStepKind::IMPLICANT: {
                    s << "\t\t-" << t << "-> is subset of -" << cex.implicants.at(t) << "->\n";
                    break;
                }
                case ProofStepKind::ACCEL: {
                    s << "\t\t-" << t << "-> is subset of -" << cex.accel.at(t) << "->^+" << std::endl;
                    break;
                }
                case ProofStepKind::RESOLVENT: {
                    s << "\t\t" << "chain(";
                    auto first{true};
                    for (const auto &r : cex.resolvents.at(t)) {
                        if (first) {
                            s << r;
                            first = false;
                        } else {
                            s << ", " << r;
                        }
                    }
                    s << ") = " << t << std::endl;
                    break;
                }
                case ProofStepKind::RECURRENT_SET: {
                    s << "\t\tguard(" << t << ") is a recurrent set of " << cex.recurrent_set.at(t) << std::endl;
                    break;
                }
            }
        }
        s << "\ncounterexample:" << std::endl;
        for (size_t i = 0; i < cex.transitions.size(); ++i) {
            const auto &trans{cex.transitions.at(i)};
            const auto vars{trans->vars()};
            const auto projection{cex.states.at(i)->project([&](const auto &x) {
                return theory::isProgVar(x) || vars.contains(x);
            })};
            s << "\t" << projection << "\n\t-" << trans->getId() << "->\n";
        }
        s << "\terr";
    }
    return s;
}

size_t ITSSafetyCex::num_states() const {
    return states.size();
}

ModelPtr ITSSafetyCex::get_state(const size_t i) const {
    return states.at(i);
}

size_t ITSSafetyCex::num_transitions() const {
    return transitions.size();
}

RulePtr ITSSafetyCex::get_transition(const size_t i) const {
    return transitions.at(i);
}

std::vector<std::pair<RulePtr, ProofStepKind>> ITSSafetyCex::get_used_rules() const {
    return ITSCex::get_used_rules(transitions);
}

ITSSafetyCex ITSSafetyCex::replace_rules(const linked_hash_map<RulePtr, RulePtr> &map) const {
    ITSSafetyCex res{its};
    for (const auto &[x, y] : implicants) {
        res.add_implicant(map.get(y).value_or(y), map.get(x).value_or(x));
    }
    for (const auto &[x, y] : accel) {
        res.add_accel(map.get(y).value_or(y), map.get(x).value_or(x));
    }
    for (const auto &[x, ys] : resolvents) {
        std::vector<RulePtr> transformed;
        for (const auto &y : ys) {
            transformed.emplace_back(map.get(y).value_or(y));
        }
        res.add_resolvent(transformed, map.get(x).value_or(x));
    }
    for (const auto &[x, y] : recurrent_set) {
        res.add_recurrent_set(map.get(y).value_or(y), map.get(x).value_or(x));
    }
    res.set_initial_state(states.front()->project(theory::isProgVar));
    for (size_t i = 1; i < num_states(); ++i) {
        auto trans{transitions.at(i - 1)};
        if (auto state{states.at(i)->project(theory::isProgVar)}; !res.try_step(map.get(trans).value_or(trans), state)) {
            throw std::logic_error("replace_rules failed");
        }
    }
    if (const auto trans{transitions.back()}; !res.try_final_transition(map.get(trans).value_or(trans))) {
        throw std::logic_error("replace_rules failed");
    }
    return res;
}
