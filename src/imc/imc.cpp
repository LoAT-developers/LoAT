#include "imc.hpp"
#include "config.hpp"
#include "smtfactory.hpp"
#include "cvc5.hpp"
#include "yices.hpp"
#include "opensmt.hpp"

#include <stdexcept>

IMC::IMC(const ITSPtr its) : its2safety(its), t(its2safety.transform()), renaming_central(t.vars()), step(bools::mkOr(t.trans())) {}

std::optional<SmtResult> IMC::do_step() {
    ++lookahead;
    if (Config::Analysis::log > 0) {
        std::cout << "[IMC] Checking with lookahead length " << lookahead << '\n';
    }
    OpenSmt solver(true);
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
    auto reachedStates{t.init()};
    unsigned iter {0};
    while (true) {
        solver.push();
        solver.add(movingInit);
        const auto res{solver.check()};
        if (res == SmtResult::Unsat) {
            opensmt::ipartitions_t mask {0};
            opensmt::setbit(mask, 1);
            opensmt::setbit(mask, iter + 2);
            auto itp {solver.interpolate(mask)};
            itp = renaming_central.post_to_pre()(itp);
            // if R' => R return False(if R' /\ not R returns True)
            if (SmtFactory::check(itp && !reachedStates) == SmtResult::Unsat) {
                return SmtResult::Sat;
                // if (not computeWitness) { return {VerificationAnswer::SAFE, PTRef_Undef}; }
                // PTRef inductiveInvariant = reachedStates;
                // PTRef finalInductiveInvariant = computeFinalInductiveInvariant(inductiveInvariant, k, ts);
                // return {VerificationAnswer::SAFE, finalInductiveInvariant};
            }
            movingInit = itp;
            reachedStates = reachedStates || itp;
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

ITSModel IMC::get_model() {
    throw std::runtime_error("not yet implemented");
}

ITSSafetyCex IMC::get_cex() {
    throw std::runtime_error("not yet implemented");
}
