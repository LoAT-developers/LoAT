#include "formulapreprocessing.hpp"

#include "config.hpp"
#include "subs.hpp"
#include "impliedequivalences.hpp"
#include "intfm.hpp"
#include "model.hpp"

AbstractFormulaPreprocessor::AbstractFormulaPreprocessor(const Bools::Expr& in): in(in) {}

EquivalencePropagator::EquivalencePropagator(const Bools::Expr &in): AbstractFormulaPreprocessor(in) {}

Bools::Expr EquivalencePropagator::process() {
    subs = impliedEquivalences(in);
    if (subs.empty()) {
        return in;
    }
    return in->subs(subs);
}

ModelPtr EquivalencePropagator::transform_model(ModelPtr model) {
    return model->composeBackwards(subs);
}

Subs EquivalencePropagator::get_subs() const {
    return subs;
}

EqualityPropagator::EqualityPropagator(const Bools::Expr &in, const std::function<bool(const Var&)>& allow): AbstractFormulaPreprocessor(in), allow(allow) {}

Bools::Expr EqualityPropagator::process() {
    subs = in->propagateEqualities(allow);
    if (subs.empty()) {
        return in;
    }
    return in->subs(subs);
}

ModelPtr EqualityPropagator::transform_model(ModelPtr model) {
    return model->composeBackwards(subs);
}

Subs EqualityPropagator::get_subs() const {
    return subs;
}

AndSimplifier::AndSimplifier(const Bools::Expr &in): AbstractFormulaPreprocessor(in) {}

Bools::Expr AndSimplifier::process() {
    if (in->isConjunction()) {
        if (auto lits{in->lits()}; ArithLit::simplifyAnd(lits.get<Arith::Lit>())) {
            return bools::mkAnd(lits);
        }
    }
    return in;
}

ModelPtr AndSimplifier::transform_model(ModelPtr model) {
    return model;
}

OrSimplifier::OrSimplifier(const Bools::Expr &in): AbstractFormulaPreprocessor(in) {}

Bools::Expr OrSimplifier::process() {
    if (in->isDisjunction()) {
        if (auto lits{in->lits()}; ArithLit::simplifyOr(lits.get<Arith::Lit>())) {
            return bools::mkOr(lits);
        }
    }
    return in;
}

ModelPtr OrSimplifier::transform_model(ModelPtr model) {
    return model;
}

IntegerFourierMotzkin::IntegerFourierMotzkin(const Bools::Expr &in, const std::function<bool(const Var&)>& allow): AbstractFormulaPreprocessor(in), res(in), allow(allow) {}

Bools::Expr IntegerFourierMotzkin::process() {
    res = integerFourierMotzkin(in, allow);
    return res.t;
}

ModelPtr IntegerFourierMotzkin::transform_model(ModelPtr model) {
    for (const auto& [x, bounds]: res.bounds | std::views::reverse) {
        if (!bounds.lower.empty()) {
            auto max_val = model->evalToRational(bounds.lower.front());
            for (const auto& lb: bounds.lower) {
                const auto val = model->evalToRational(lb);
                if (val > max_val) {
                    max_val = val;
                }
            }
            Int div = mp::abs(mp::numerator(max_val)) / mp::abs(mp::denominator(max_val));
            Int mod = mp::abs(mp::numerator(max_val)) % mp::abs(mp::denominator(max_val));
            Int val = max_val >= 0 ? div : -div;
            val = mod == 0 ? val : val + 1;
            model = model->put(x, val);
        } else if (!bounds.upper.empty()) {
            auto min_val = model->evalToRational(bounds.upper.front());
            for (const auto& ub: bounds.upper) {
                const auto val = model->evalToRational(ub);
                if (val < min_val) {
                    min_val = val;
                }
            }
            Int div = mp::abs(mp::numerator(min_val)) / mp::abs(mp::denominator(min_val));
            Int mod = mp::abs(mp::numerator(min_val)) % mp::abs(mp::denominator(min_val));
            Int val = min_val >= 0 ? div : -div;
            val = mod == 0 ? val : val - 1;
            model = model->put(x, val);
        } else {
            model = model->put(x, 0);
        }
    }
    return model;
}

FormulaPreprocessor::FormulaPreprocessor(const Bools::Expr &in, const std::function<bool(const Var&)>& allow): AbstractFormulaPreprocessor(in), allow(allow) {}

Bools::Expr FormulaPreprocessor::process() {
    Bools::Expr last = in;
    Bools::Expr current = in;
    const auto apply_proc = [&](auto proc) {
        current = proc->process();
        if (current != last) {
            procs.emplace_back(std::move(proc));
            last = current;
            return true;
        }
        return false;
    };
    while (apply_proc(std::make_unique<EquivalencePropagator>(current))){}
    apply_proc(std::make_unique<AndSimplifier>(current));
    bool changed;
    do {
        changed = false;
        if (apply_proc(std::make_unique<EqualityPropagator>(current, allow))) {
            changed = true;
            apply_proc(std::make_unique<AndSimplifier>(current));
        }
        if (apply_proc(std::make_unique<IntegerFourierMotzkin>(current, allow))) {
            changed = true;
            apply_proc(std::make_unique<AndSimplifier>(current));
        }
    } while (changed);
    return current;
}

ModelPtr FormulaPreprocessor::transform_model(ModelPtr model) {
    ModelPtr res = model;
    for (const auto& proc: procs | std::views::reverse) {
        res = proc->transform_model(res);
    }
    return res;
}

Bools::Expr Preprocess::preprocessFormula(Bools::Expr e, const std::function<bool(const Var &)> &allow) {
    return FormulaPreprocessor(e, allow).process();
}

std::tuple<Bools::Expr, Renaming, Renaming> Preprocess::chain(const Bools::Expr &fst, const Bools::Expr &snd) {
    Renaming sigma1;
    Renaming sigma2;
    auto first_vars {fst->vars()};
    auto second_vars {snd->vars()};
    VarSet post_vars;
    for (const auto &vars : {first_vars, second_vars}) {
        for (const auto &x : vars) {
            if (theory::isProgVar(x)) {
                post_vars.insert(theory::postVar(x));
            } else if (theory::isPostVar(x)) {
                post_vars.insert(x);
            }
        }
    }
    for (const auto& post : post_vars) {
        theory::apply(
            post,
            [&](const auto& post) {
                const auto pre{post->progVar()};
                const auto x{Renaming::renameVar(post, sigma1)};
                sigma2.insert(pre, x);
            });
    }
    for (const auto& x : second_vars) {
        theory::apply(
            x,
            [&](const auto& x) {
                if (x->isTempVar() && first_vars.contains(x)) {
                    Renaming::renameVar(x, sigma2);
                }
            });
    }
    return {fst->renameVars(sigma1) && snd->renameVars(sigma2), sigma1.invert(), sigma2.invert()};
}
