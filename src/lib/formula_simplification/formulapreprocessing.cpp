/*  This file is part of LoAT.
 *  Copyright (c) 2015-2016 Matthias Naaf, RWTH Aachen University, Germany
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses>.
 */

#include "formulapreprocessing.hpp"
#include "subs.hpp"
#include "impliedequivalences.hpp"
#include "intfm.hpp"

using namespace std;

Result<ArithSubs, Proof> Preprocess::propagateEqualities(const Bools::Expr e, const SymbolAcceptor &allow) {
    Result<ArithSubs, Proof> res;
    const auto subs {e->propagateEqualities(allow)};
    if (!subs.empty()) {
        res = subs;
        res.appendAll("propagated equalities: ", subs);
    }
    return res;
}

Result<BoolSubs, Proof> Preprocess::propagateEquivalences(const Bools::Expr e) {
    Result<BoolSubs, Proof> res;
    const auto equiv {impliedEquivalences(e)};
    if (!equiv.empty()) {
        res = equiv.get<Bools>();
        res.appendAll("propagated equivalences: ", equiv);
    }
    return res;
}

Result<Bools::Expr, Proof> propagateEquivalences(const Bools::Expr e) {
    Result<Bools::Expr, Proof> res {e};
    const auto subs {Preprocess::propagateEquivalences(e)};
    if (subs) {
        res = Subs::build<Bools>(*subs)(e);
        res.append("Propagated Equivalences");
        res.storeSubProof(subs.getProof());
    }
    return res;
}

Result<Bools::Expr, Proof> propagateEqualities(const Bools::Expr e, const Preprocess::SymbolAcceptor &allow) {
    Result<Bools::Expr, Proof> res {e};
    const auto subs {Preprocess::propagateEqualities(e, allow)};
    if (subs) {
        res = Subs::build<Arith>(*subs)(e);
        res.append("Extracted Implied Equalities");
        res.storeSubProof(subs.getProof());
    }
    return res;
}

Result<Bools::Expr, Proof> Preprocess::preprocessFormula(const Bools::Expr e, const SymbolAcceptor &allow) {
    Result<Bools::Expr, Proof> res {e};
    auto changed {false};
    do {
        const auto tmp {::propagateEquivalences(*res)};
        changed = bool(tmp);
        res.concat(tmp);
    } while (changed);
    do {
        auto tmp {::propagateEqualities(*res, allow)};
        changed = bool(tmp);
        res.concat(tmp);
        tmp = integerFourierMotzkin(*res, allow);
        changed |= bool(tmp);
        res.concat(tmp);
    } while (changed);
    return res;
}
