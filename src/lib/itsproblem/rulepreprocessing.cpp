#include "rulepreprocessing.hpp"
#include "theory.hpp"
#include "formulapreprocessing.hpp"
#include "config.hpp"
#include "impliedequivalences.hpp"

AbstractRulePreprocessor::AbstractRulePreprocessor(const RulePtr &in): in(in) {}

class RuleEquivalencePropagator : public AbstractRulePreprocessor {

    std::unique_ptr<EquivalencePropagator> prop;

public:
    explicit RuleEquivalencePropagator(const RulePtr &in): AbstractRulePreprocessor(in) {}

    RulePtr process() override {
        const auto guard = in->getGuard();
        prop = std::make_unique<EquivalencePropagator>(guard);
        const auto new_guard = prop->process();
        if (new_guard == guard) {
            return in;
        }
        const auto subs = prop->get_subs();
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "propagated equivalences: " << subs << std::endl;
        }
        return Rule::mk(new_guard, in->getUpdate().concat(subs));
    }

    ModelPtr transform_model(const ModelPtr& cex) const override {
        return prop->transform_model(cex);
    }

};

class IdentityEliminator : public AbstractRulePreprocessor {

public:
    explicit IdentityEliminator(const RulePtr &in): AbstractRulePreprocessor(in) {}

    RulePtr process() override {
        VarSet remove;
        for (const auto& p : in->getUpdate()) {
            theory::apply(
                p,
                [&](const std::pair<Bools::Var, Bools::Expr>& p) {
                    if (bools::mkLit(bools::mk(p.first)) == p.second) {
                        remove.insert(p.first);
                    }
                },
                [&](const std::pair<Arrays<Arith>::Var, Arrays<Arith>::Expr>& p) {
                    if (p.first->dim() == 0 && arrays::readConst(p.first) == arrays::readConst(p.second)) {
                        remove.insert(p.first);
                    } else if (p.first == p.second) {
                        remove.insert(p.first);
                    }
                });
        }
        if (remove.empty()) {
            return in;
        }
        auto new_update{in->getUpdate()};
        new_update.erase(remove);
        auto res{in->withUpdate(new_update)};
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "removed identity updates: " << res << std::endl;
        }
        return res;
    }

    ModelPtr transform_model(const ModelPtr& cex) const override {
        return cex;
    }

};

class RuleEqualityPropagator : public AbstractRulePreprocessor {

    std::unique_ptr<EqualityPropagator> prop;

public:
    explicit RuleEqualityPropagator(const RulePtr &in): AbstractRulePreprocessor(in) {}

    RulePtr process() override {
        const auto guard = in->getGuard();
        prop = std::make_unique<EqualityPropagator>(guard, theory::isTempVar);
        const auto new_guard = prop->process();
        if (new_guard == guard) {
            return in;
        }
        const auto subs = prop->get_subs();
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "extracted implied equalities: " << subs << std::endl;
        }
        return Rule::mk(new_guard, in->getUpdate().concat(subs));
    }

    ModelPtr transform_model(const ModelPtr& cex) const override {
        return prop->transform_model(cex);
    }

};

class RuleIntegerFourierMotzkin : public AbstractRulePreprocessor {

    std::unique_ptr<IntegerFourierMotzkin> prop;

public:
    explicit RuleIntegerFourierMotzkin(const RulePtr &in): AbstractRulePreprocessor(in) {}

    RulePtr process() override {
        const auto varsInUpdate{in->getUpdate().coDomainVars()};
        auto isTempOnlyInGuard = [&](const Var &sym) {
            return theory::apply(sym, [&](const auto& sym) {
                return sym->isTempVar() && !varsInUpdate.contains(sym);
            });
        };
        prop = std::make_unique<IntegerFourierMotzkin>(in->getGuard(), isTempOnlyInGuard);
        return in->withGuard(prop->process());
    }

    ModelPtr transform_model(const ModelPtr& cex) const override {
        return prop->transform_model(cex);
    }

};

RulePreprocessor::RulePreprocessor(const RulePtr &in) : AbstractRulePreprocessor(in) {}

RulePtr RulePreprocessor::process() {
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "preprocessing " << in << std::endl;
    }
    auto current{in};
    if (const auto g{AndSimplifier(current->getGuard()).process()}; g != current->getGuard()) {
        current = current->withGuard(g);
    }
    auto changed = false;
    const auto apply = [&]<class T, class... Args>(Args... args) {
        auto proc = std::make_unique<T>(args...);
        const auto next = proc->process();
        if (next == current) {
            return false;
        }
        changed = true;
        procs.emplace_back(std::move(proc));
        current = next;
        return true;
    };
    do {
        changed = false;
        apply.operator()<RuleEquivalencePropagator>(current);
        if (!apply.operator()<RuleEqualityPropagator>(current)) {
            apply.operator()<RuleIntegerFourierMotzkin>(current);
        }
        if (changed) {
            current = current->withGuard(AndSimplifier(current->getGuard()).process());
        }
    } while (changed);
    apply.operator()<IdentityEliminator>(current);
    if (current != in && Config::Analysis::doLogPreproc()) {
        std::cout << "got " << *current << std::endl;
    }
    return current;
}

ModelPtr RulePreprocessor::transform_model(const ModelPtr &cex) const {
    ModelPtr res = cex;
    for (const auto &proc: procs | std::views::reverse) {
        res = proc->transform_model(res);
    }
    return res;
}

RulePtr Preprocess::preprocessRule(const RulePtr &rule) {
    return RulePreprocessor(rule).process();
}

RulePtr Preprocess::chain(const std::vector<RulePtr> &rules) {
    std::vector<Bools::Expr> guards;
    Subs up;
    for (const auto &r: rules) {
        guards.push_back(r->getGuard()->subs(up));
        up = r->getUpdate().compose(up);
    }
    return Rule::mk(bools::mkAnd(guards), up);
}
