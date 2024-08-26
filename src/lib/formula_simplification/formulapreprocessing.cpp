#include "formulapreprocessing.hpp"
#include "subs.hpp"
#include "impliedequivalences.hpp"
#include "intfm.hpp"

Bools::Expr propagateEquivalences(const Bools::Expr e) {
    const auto subs {impliedEquivalences(e)};
    return subs.empty() ? e : Subs::build<Bools>(subs)(e);
}

Bools::Expr propagateEqualities(const Bools::Expr e, const Preprocess::SymbolAcceptor &allow) {
    const auto subs {e->propagateEqualities(allow)};
    return subs.empty() ? e : Subs::build<Arith>(subs)(e);

}

Bools::Expr Preprocess::preprocessFormula(const Bools::Expr e, const SymbolAcceptor &allow) {
    Bools::Expr res {e};
    auto changed {false};
    do {
        changed = false;
        const auto tmp {::propagateEquivalences(res)};
        if (tmp != res) {
            changed = true;
            res = tmp;
        }
    } while (changed);
    do {
        changed = false;
        auto tmp {::propagateEqualities(res, allow)};
        if (tmp != res) {
            changed = true;
            res = tmp;
        }
        tmp = integerFourierMotzkin(res, allow);
        if (tmp != res) {
            changed = true;
            res = tmp;
        }
    } while (changed);
    return res;
}
