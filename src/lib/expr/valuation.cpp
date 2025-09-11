#include "valuation.hpp"

LitSet Valuation::lits() const {
    LitSet res;
    for (const auto& [x,v]: m_arith) {
        res.insert(arith::mkEq(x, arith::mkConst(v)));
    }
    for (const auto& [x,v]: m_bool) {
        res.insert(bools::mk(x, !v));
    }
    for (const auto& [x,v]: m_arr) {
        res.insert(arrays::mkElemEq<Arith>(x, arith::mkConst(v)));
    }
    return res;
}
