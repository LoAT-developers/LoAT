#include "intfm.hpp"
#include "vector.hpp"
#include "config.hpp"

#include <unordered_set>

Bools::Expr integerFourierMotzkin(const Bools::Expr& e, const std::function<bool(const Var &)> &allow) {
    if (!e->isConjunction()) {
        return e;
    }
    auto lits {e->lits()};

    // get all variables that appear in an inequality
    linked_hash_set<Arith::Var> candidates;
    for (const auto &lit : lits) {
        if (std::holds_alternative<Arith::Lit>(lit)) {
            if (const auto &rel = std::get<Arith::Lit>(lit); rel->isGt()) {
                rel->collectVars(candidates);
            }
        }
    }

    std::unordered_set<Arith::Var> eliminated;
    const auto is_explosive = [&](const auto &var, const auto &term){
        return term->hasVarWith([&](const auto x) {
            return x != var && !eliminated.contains(x) && candidates.contains(x);
        });
    };

    for (const auto &var: candidates) {
        if (!allow(var)) continue;
        std::vector<Arith::Expr> upper_bounds;
        std::vector<Arith::Expr> lower_bounds;
        std::vector<Arith::Lit> eliminated_lits;
        auto may_be_dually_bounded {true};
        auto lower_bounded {false};
        auto upper_bounded {false};
        // used for heuristic for detecting cases where we get an exponential blow-up
        size_t explosive_lower {0};
        size_t explosive_upper {0};
        for (const auto &lit: lits) {
            if (theory::vars(lit).contains(var)) {
                if (std::holds_alternative<Arith::Lit>(lit)) {
                    const auto &rel {std::get<Arith::Lit>(lit)};
                    if (!rel->isGt()) {
                        // if the variable occurs in an equality, then it should be eliminated by equality propagation
                        // if it occurs in a negated equality, then we cannot eliminate
                        goto abort;
                    }
                    if (!rel->isLinear({{var}})) {
                        // no variable elimination for non-linear arithmetic
                        goto abort;
                    }
                    const auto term {rel->lhs()};
                    if (const auto coeff {*term->coeff(var)}; coeff->is(1) == 1) {
                        // we have var + p > 0, i.e., var >= -p+1
                        lower_bounds.push_back(arith::mkPlus({-term, var, arith::mkConst(1)}));
                        lower_bounded = true;
                        if (is_explosive(var, term)) {
                            ++explosive_upper;
                        }
                    } else if (coeff->is(-1)) {
                        // we have -var + p > 0, i.e., p-1 >= var
                        upper_bounds.push_back(arith::mkPlus({term, var, arith::mkConst(-1)}));
                        upper_bounded = true;
                        if (is_explosive(var, term)) {
                            ++explosive_lower;
                        }
                    } else {
                        if (const auto int_coeff {coeff->isInt()}) {
                            // the coefficient is constant, but neither 1 nor -1
                            // if the variable bounded from both sides, then we need divisibility constraints to eliminate it
                            may_be_dually_bounded = false;
                            if (*int_coeff > 0) {
                                lower_bounded = true;
                            } else {
                                upper_bounded = true;
                            }
                        } else {
                            // non-constant coefficient
                            goto abort;
                        }
                    }
                    if (!may_be_dually_bounded && lower_bounded && upper_bounded) {
                        goto abort;
                    }
                    if (explosive_upper > 1 && explosive_lower > 1) {
                        // elimination might cause exponential blow-up
                        goto abort;
                    }
                    eliminated_lits.push_back(rel);
                } else {
                    // variable occurs in a literal from another theory
                    goto abort;
                }
            }
        }
        // perform the elimination
        for (const Arith::Lit &rel: eliminated_lits) {
            lits.erase(rel);
        }
        for (const auto &upper : upper_bounds) {
            for (const auto &lower : lower_bounds) {
                lits.insert(arith::mkLeq(lower, upper));
            }
        }
        eliminated.insert(var);
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "eliminated " << var << "; lower bounds: " << lower_bounds << "; upper bounds: " << upper_bounds << std::endl;
        }

abort:  ; //this symbol could not be eliminated, try the next one
    }
    if (eliminated.empty()) {
        return e;
    }
    return bools::mkAndFromLits(lits);
}
