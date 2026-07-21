#include "itsrecurrentset.hpp"

#include "formulapreprocessing.hpp"

void ITSRecurrentSet::add(const LocationIdx f, const BoolExprSet &b) {
    auto& rs = get(f);
    rs.insert(Preprocess::preprocessFormula(bools::mkAnd(b) && bools::mkLit(arith::mkEq(ITSProblem::loc_var(), arith::mkConst(f)))));
}

void ITSRecurrentSet::add(const LocationIdx f, const Bools::Expr b) {
    add(f, BoolExprSet{b});
}

void ITSRecurrentSet::add(const RulePtr c) {
    m_rules.insert(c);
}

BoolExprSet& ITSRecurrentSet::get(const LocationIdx f) {
    return m_map.emplace(f, BoolExprSet()).first->second;
}

void ITSRecurrentSet::simplify() {
    for (auto &bs: m_map | std::views::values) {
        const auto b = OrSimplifier(bools::mkOr(bs)).process();
        bs.clear();
        bs.insert(b);
    }
}

const linked_hash_set<RulePtr> & ITSRecurrentSet::rules() const {
    return m_rules;
}
