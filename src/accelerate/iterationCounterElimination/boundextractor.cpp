#include "boundextractor.hpp"
#include "rel.hpp"

BoundExtractor::BoundExtractor(const BoolExpr guard, const Var &N): guard(guard), N(N) {
    extractBounds();
}

const option<Expr> BoundExtractor::getEq() const {
    return eq;
}

const std::vector<Expr> BoundExtractor::getLower() const {
    return lower;
}

const std::vector<Expr> BoundExtractor::getUpper() const {
    return upper;
}

const std::vector<Expr> BoundExtractor::getLowerAndUpper() const {
    std::vector<Expr> res;
    res.insert(res.end(), lower.begin(), lower.end());
    res.insert(res.end(), upper.begin(), upper.end());
    return res;
}

void BoundExtractor::extractBounds() {
    if (guard->isConjunction()) {
        // First check if there is an equality constraint (we can then ignore all other upper bounds)
        for (const Rel &rel : guard->lits()) {
            if (rel.isEq() && rel.has(N)) {
                auto optSolved = GuardToolbox::solveTermFor(rel.lhs() - rel.rhs(), N, GuardToolbox::ResultMapsToInt);
                if (optSolved) {
                    // One equality is enough, as all other bounds must also satisfy this equality
                    eq = optSolved.get();
                }
                return;
            }
        }
    }

    // Otherwise, collect all bounds
    for (const Rel &rel : guard->lits()) {
        if (!rel.has(N)) continue;
        if (rel.isEq()) {
            auto optSolved = GuardToolbox::solveTermFor(rel.lhs() - rel.rhs(), N, GuardToolbox::ResultMapsToInt);
            if (optSolved) {
                lower.push_back(optSolved.get());
                upper.push_back(optSolved.get());
            }
        } else {
            std::pair<option<Expr>, option<Expr>> bounds = GuardToolbox::getBoundFromIneq(rel, N);
            if (bounds.first) {
                lower.push_back(bounds.first.get());
            }
            if (bounds.second) {
                upper.push_back(bounds.second.get());
            }
        }
    }
}

const ExprSet BoundExtractor::getConstantBounds() const {
    if (eq && eq.get().isInt()) {
        return {eq.get()};
    }
    ExprSet res;
    for (const Expr &e: getLowerAndUpper()) {
        if (e.isInt()) {
            res.insert(e);
        }
    }
    return res;
}
