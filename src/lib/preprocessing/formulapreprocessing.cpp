#include "formulapreprocessing.hpp"
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

ModelPtr EquivalencePropagator::transform_model(const ModelPtr &model) {
    return model->composeBackwards(subs);
}

EqualityPropagator::EqualityPropagator(const Bools::Expr &in, const std::function<bool(const Var&)>& allow): AbstractFormulaPreprocessor(in), allow(allow) {}

Bools::Expr EqualityPropagator::process() {
    subs = in->propagateEqualities(allow);
    if (subs.empty()) {
        return in;
    }
    return in->subs(subs);
}

ModelPtr EqualityPropagator::transform_model(const ModelPtr &model) {
    return model->composeBackwards(subs);
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

ModelPtr AndSimplifier::transform_model(const ModelPtr &model) {
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

ModelPtr OrSimplifier::transform_model(const ModelPtr &model) {
    return model;
}

IntegerFourierMotzkin::IntegerFourierMotzkin(const Bools::Expr &in, const std::function<bool(const Var&)>& allow): AbstractFormulaPreprocessor(in), allow(allow) {}

Bools::Expr IntegerFourierMotzkin::process() {
    const auto [res, lb] = integerFourierMotzkin(in, allow);
    lower_bound_map = lb;
    return res;
}

ModelPtr IntegerFourierMotzkin::transform_model(const ModelPtr &model) {
    for (const auto& [x,lbs]: lower_bound_map | std::views::reverse) {
        auto max_val = model->eval(lbs.front());
        for (const auto& lb: lbs) {
            const auto val = model->eval(lb);
            if (val > max_val) {
                max_val = val;
            }
        }
        model->put(x, max_val);
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

ModelPtr FormulaPreprocessor::transform_model(const ModelPtr &model) {
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
