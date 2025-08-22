#include "imcsafety.hpp"
#include "config.hpp"
#include "smtfactory.hpp"

#include <stdexcept>

IMCSafety::IMCSafety(const SafetyProblem &t) : t(t), renaming_central(t.vars()), step(bools::mkOr(t.trans())) {}

std::optional<SmtResult> IMCSafety::do_step() {
    ++lookahead;
    if (Config::Analysis::log > 0) {
        std::cout << "[IMC] Checking with lookahead length " << lookahead << '\n';
    }
    solver.resetSolver();
    const auto suffix = [&]() {
        std::vector<Bools::Expr> suffixTransitions;
        for (unsigned i = 1; i < lookahead; ++i) {
            suffixTransitions.push_back(renaming_central.get_subs(i)(step));
        }
        suffixTransitions.push_back(renaming_central.get_subs(lookahead)(t.err()));
        return bools::mkAnd(std::move(suffixTransitions));
    }();
    solver.add(suffix);
    solver.add(step);
    auto movingInit{t.init()};
    auto reached_states {t.init()};
    unsigned iter {0};
    while (true) {
        solver.push();
        solver.add(movingInit);
        const auto res{solver.check()};
        if (res == SmtResult::Unsat) {
            opensmt::ipartitions_t mask {0};
            opensmt::setbit(mask, 1);
            opensmt::setbit(mask, iter + 2);
            itp = solver.interpolate(mask);
            itp = renaming_central.post_to_pre()(itp);
            // if R' => R return False(if R' /\ not R returns True)
            if (SmtFactory::check(itp && !reached_states) == SmtResult::Unsat) {
                return SmtResult::Sat;
            }
            movingInit = itp;
            reached_states = reached_states || itp;
        } else if (res == SmtResult::Sat) {
            if (iter > 0) {
                // Possibly spurious counterexample => Abort and continue with larger k
                return std::nullopt;
            } else {
                // Real counterexample
                return SmtResult::Unsat;
            }
        } else {
            return SmtResult::Unknown;
        }
        solver.pop();
        ++iter;
    }
}

SmtResult IMCSafety::analyze() {
    std::optional<SmtResult> res;
    while (!(res = do_step()));
    return *res;
}

Bools::Expr IMCSafety::get_itp() const {
    return itp;
}

Model IMCSafety::get_model() {
    return solver.model();
}
