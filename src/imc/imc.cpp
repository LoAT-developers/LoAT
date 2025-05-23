#include "imc.hpp"
#include "config.hpp"
#include "smtfactory.hpp"
#include "cvc5.hpp"
#include "yices.hpp"

#include <stdexcept>

IMC::IMC(const ITSPtr its) : its2safety(its), t(its2safety.transform()), renaming_central(t.vars()), step(bools::mkOr(t.trans())) {}

std::optional<SmtResult> IMC::do_step() {
    ++lookahead;
    if (Config::Analysis::log > 0) {
        std::cout << "[IMC] Checking with lookahead length " << lookahead << '\n';
    }
    Yices solver{QF_LA};
    const auto suffix = [&]() {
        std::vector<Bools::Expr> suffixTransitions;
        for (unsigned i = 1; i < lookahead; ++i) {
            suffixTransitions.push_back(renaming_central.get_subs(i)(step));
        }
        suffixTransitions.push_back(renaming_central.get_subs(lookahead)(t.err()));
        return bools::mkAnd(std::move(suffixTransitions));
    }();
    solver.add(suffix);
    std::cout << "suffix: " << std::endl << suffix << std::endl;
    auto movingInit{t.init() && step};
    auto reachedStates{t.init()};
    auto approx {false};
    while (true) {
        std::cout << "moving init: " << std::endl << movingInit << std::endl;
        const auto opt{solver.interpolate(movingInit)};
        if (opt) {
            auto itp{*opt};
            itp = renaming_central.post_to_pre()(itp);
            std::cout << "interpolant: " << itp << std::endl;
            // if R' => R return False(if R' /\ not R returns True)
            if (SmtFactory::check(itp && !reachedStates) == SmtResult::Unsat) {
                return SmtResult::Sat;
                // if (not computeWitness) { return {VerificationAnswer::SAFE, PTRef_Undef}; }
                // PTRef inductiveInvariant = reachedStates;
                // PTRef finalInductiveInvariant = computeFinalInductiveInvariant(inductiveInvariant, k, ts);
                // return {VerificationAnswer::SAFE, finalInductiveInvariant};
            }
            movingInit = itp && step;
            reachedStates = reachedStates || itp;
            approx = true;
        } else {
            solver.add(movingInit);
            const auto res {solver.check()};
            assert(res != SmtResult::Unsat);
            if (res == SmtResult::Sat) {
                if (approx) {
                    // Possibly spurious counterexample => Abort and continue with larger k
                    return std::nullopt;
                } else {
                    // Real counterexample
                    return SmtResult::Unsat;
                }
            } else {
                return SmtResult::Unknown;
            }
        }
    }
}

ITSModel IMC::get_model() {
    throw std::runtime_error("not yet implemented");
}

ITSSafetyCex IMC::get_cex() {
    throw std::runtime_error("not yet implemented");
}
