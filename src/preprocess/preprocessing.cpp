#include "preprocessing.hpp"
#include "config.hpp"
#include "loopacceleration.hpp"
#include "rulepreprocessing.hpp"
#include "smtfactory.hpp"
#include "theory.hpp"
#include "profile.hpp"

#include <unordered_set>
#include <stack>
#include <utility>

#include "formulapreprocessing.hpp"

AbstractITSPreprocessor::AbstractITSPreprocessor(ITSPtr its): its(std::move(its)) {}

class ITSRulePreprocessor : public AbstractITSPreprocessor {

    linked_hash_map<RulePtr, std::shared_ptr<RulePreprocessor>> procs;
    linked_hash_map<RulePtr, RulePtr> back_map;

public:

    explicit ITSRulePreprocessor(const ITSPtr& its): AbstractITSPreprocessor(its) {}

    bool process() override {
        for (const auto& r: its->getAllTransitions()) {
            auto proc = std::make_shared<RulePreprocessor>(r);
            if (const auto res = proc->process(); res != r) {
                procs.emplace(res, proc);
                back_map.emplace(res, r);
            }
        }
        for (const auto &[x,y]: back_map) {
            its->replaceRule(y, x);
        }
        return !back_map.empty();
    }

    ITSModel transform_model(const ITSModel &m) const override {
        return m;
    }

    std::shared_ptr<ITSCex> transform_cex(const std::shared_ptr<ITSCex> &cex) const override {
        return cex->replace_rules(back_map, procs);
    }
};

class BotRemover : public AbstractITSPreprocessor {
public:

    explicit BotRemover(const ITSPtr& its): AbstractITSPreprocessor(its) {}

    bool process() override {
        std::vector<RulePtr> remove;
        for (const auto& r: its->getAllTransitions()) {
            if (r->getGuard() == bot()) {
                remove.emplace_back(r);
            }
        }
        for (const auto &r: remove) {
            its->removeRule(r);
        }
        return !remove.empty();
    }

    ITSModel transform_model(const ITSModel &m) const override {
        return m;
    }

    std::shared_ptr<ITSCex> transform_cex(const std::shared_ptr<ITSCex> &cex) const override {
        return cex;
    }
};

class EmptyClauseRemover : public AbstractITSPreprocessor {
public:

    explicit EmptyClauseRemover(const ITSPtr& its): AbstractITSPreprocessor(its) {}

    bool process() override {
        std::vector<RulePtr> remove;
        for (const auto& r: its->getInitialTransitions()) {
            if (its->isSinkTransition(r) && SmtFactory::check(r->getGuard()) != SmtResult::Sat) {
                remove.emplace_back(r);
            }
        }
        for (const auto& r: remove) {
            its->removeRule(r);
        }
        return !remove.empty();
    }

    ITSModel transform_model(const ITSModel &m) const override {
        return m;
    }

    std::shared_ptr<ITSCex> transform_cex(const std::shared_ptr<ITSCex> &cex) const override {
        return cex;
    }
};

class IrrelevantRuleRemover : public AbstractITSPreprocessor {

    bool forward;

public:

    IrrelevantRuleRemover(const ITSPtr& its, const bool forward): AbstractITSPreprocessor(its), forward(forward) {}

    bool process() override {
        if (!Config::Analysis::safety()) {
            return false;
        }
        std::unordered_set<RulePtr> keep;
        std::stack<RulePtr> todo;
        for (const auto &x : forward ? its->getInitialTransitions() : its->getSinkTransitions()) {
            todo.push(x);
        }
        while (!todo.empty()) {
            const auto current {todo.top()};
            todo.pop();
            keep.insert(current);
            for (const auto &p : forward ? its->getSuccessors(current) : its->getPredecessors(current)) {
                if (!keep.contains(p)) {
                    todo.push(p);
                }
            }
        }
        linked_hash_set<RulePtr> deleted;
        for (const auto &r : its->getAllTransitions()) {
            if (!keep.contains(r)) {
                deleted.insert(r);
            }
        }
        for (const auto& r: deleted) {
            its->removeRule(r);
        }
        if (Config::Analysis::doLogPreproc() && !deleted.empty()) {
            std::cout << "removed the following irrelevant transitions: " << deleted << std::endl;
        }
        return !deleted.empty();
    }

    ITSModel transform_model(const ITSModel &m) const override {
        return m;
    }

    std::shared_ptr<ITSCex> transform_cex(const std::shared_ptr<ITSCex> &cex) const override {
        return cex;
    }
};

class IdentityRuleRemover : public AbstractITSPreprocessor {
public:

    explicit IdentityRuleRemover(const ITSPtr& its): AbstractITSPreprocessor(its) {}

    bool process() override {
        linked_hash_set<RulePtr> remove;
        if (Config::Analysis::mode != Config::Analysis::Safety) {
            return false;
        }
        for (const auto &r: its->getAllTransitions()) {
            if (!r->isDeterministic()) {
                continue;
            }
            LitSet diseqs;
            const auto subs = r->getUpdate().get<Arrays<Arith> >();
            if (subs.size() != r->getUpdate().size()) {
                continue;
            }
            auto has_arrays = false;
            for (const auto &[k,v]: subs) {
                if (k->dim() > 0) {
                    has_arrays = true;
                    break;
                }
                diseqs.insert(arith::mkNeq(arrays::readConst(k), arrays::readConst(v)));
            }
            if (!has_arrays && SmtFactory::check(r->getGuard() && bools::mkOr(diseqs)) == SmtResult::Unsat) {
                remove.insert(r);
            }
        }
        for (const auto &r: remove) {
            its->removeRule(r);
        }
        if (!remove.empty() && Config::Analysis::doLogPreproc()) {
            std::cout << "removed the following identity transitions: " << remove << std::endl;
        }
        return !remove.empty();
    }

    ITSModel transform_model(const ITSModel &m) const override {
        return m;
    }

    std::shared_ptr<ITSCex> transform_cex(const std::shared_ptr<ITSCex> &cex) const override {
        return cex;
    }
};

/**
 * Motivating example: f(x,y) -> f(-x,z) :|: (y=0 /\ z=1) \/ (y=1 /\ z=0)
 * In contrast to its implicants, it can be unrolled to obtain simpler closed forms.
 */
class Unroller : public AbstractITSPreprocessor {

    std::unordered_map<RulePtr, RulePtr> m_back_map;
    std::unordered_map<RulePtr, unsigned> m_period;

public:

    explicit Unroller(const ITSPtr& its): AbstractITSPreprocessor(its) {}

    bool process() override {
        auto success{false};
        for (const auto &r : its->getAllTransitions()) {
            if (its->isSimpleLoop(r) && !r->getGuard()->isConjunction()) {
                if (const auto [res, period] = LoopAcceleration::chain(r); period > 1) {
                    success = true;
                    if (Config::Analysis::doLogPreproc()) {
                        std::cout
                            << "unrolled the following rule " << period << " times:\n"
                            << r
                            << "\nresult:\n"
                            << res << std::endl;
                    }
                    its->addRule(res, r, r);
                    m_back_map.emplace(res, r);
                    m_period.emplace(res, period);
                }
            }
        }
        return success;
    }

    ITSModel transform_model(const ITSModel &m) const override {
        return m;
    }

    std::shared_ptr<ITSCex> transform_cex(const std::shared_ptr<ITSCex> &cex) const override {
        for (const auto& [x,y]: m_back_map) {
            cex->undo_chaining(std::vector(m_period.at(x), y), x);
        }
        return cex;
    }
};

class DGRefiner : public AbstractITSPreprocessor {

public:

    explicit DGRefiner(const ITSPtr& its): AbstractITSPreprocessor(its) {}

    bool process() override {
        const auto is_edge = [](const RulePtr& fst, const RulePtr& snd) {
            return SmtFactory::check(Preprocess::chain({fst, snd->renameTmpVars()})->getGuard()) == SmtResult::Sat;
        };
        if (const auto removed{its->refineDependencyGraph(is_edge)}; removed.empty()) {
            return false;
        } else {
            if (Config::Analysis::doLogPreproc()) {
                std::cout << "removed the following edges from the dependency graph:" << std::endl;
                for (const auto &[s,d]: removed) {
                    std::cout << "(" << s->getId() << ", " << d->getId() << ")" << std::endl;
                }
            }
            return true;
        }
    }

    ITSModel transform_model(const ITSModel &m) const override {
        return m;
    }

    std::shared_ptr<ITSCex> transform_cex(const std::shared_ptr<ITSCex> &cex) const override {
        return cex;
    }
};

class Chainer : public AbstractITSPreprocessor {

    linked_hash_set<std::tuple<LocationIdx, RulePtr, LocationIdx>> removed;
    linked_hash_map<RulePtr, std::pair<RulePtr, RulePtr>> chained;

public:

    explicit Chainer(const ITSPtr& its): AbstractITSPreprocessor(its) {}

    bool process() override {
        bool changed{false};
        bool success{false};
        do {
            changed = false;
            for (const auto &first : its->getAllTransitions()) {
                if (const auto succ{its->getSuccessors(first)}; succ.size() == 1 && !succ.contains(first)) {
                    if (const auto second_idx{*succ.begin()}; !its->isSimpleLoop(second_idx)) {
                        const auto c{Preprocess::chain({first, second_idx->renameTmpVars()})};
                        if (Config::Analysis::doLogPreproc()) {
                            std::cout << "chaining\n\trule 1: " << *first << "\n\trule 2: " << *second_idx << "\n\tresult: " << *c << std::endl;
                        }
                        its->addRule(c, first, second_idx);
                        if (Config::Analysis::model) {
                            chained.emplace(c, std::pair{first, second_idx});
                            removed.emplace(ITSProblem::getLhsLoc(first), first, ITSProblem::getRhsLoc(first));
                        }
                        its->removeRule(first);
                        if (its->getPredecessors(second_idx).empty()) {
                            if (Config::Analysis::model) {
                                removed.emplace(ITSProblem::getLhsLoc(second_idx), second_idx, ITSProblem::getRhsLoc(second_idx));
                            }
                            its->removeRule(second_idx);
                        }
                        changed = true;
                        success = true;
                        break;
                    }
                }
            }
        } while (changed);
        return success;
    }

    ITSModel transform_model(const ITSModel &m) const override {
        ITSModel res {m};
        for (const auto &[from,rule,to]: removed) {
            const auto r {rule->renameTmpVars()};
            res.set_invariant(to, res.get_invariant(to) || (r->getGuard() && res.get_invariant(from)->subs(r->getUpdate())));
        }
        return res;
    }

    std::shared_ptr<ITSCex> transform_cex(const std::shared_ptr<ITSCex> &cex) const override {
        auto res {cex};
        for (const auto &[c,p]: chained) {
            res->undo_chaining(std::vector{p.first, p.second}, c);
        }
        return res;
    }
};

ITSPreprocessor::ITSPreprocessor(const ITSPtr &its) : AbstractITSPreprocessor(its) {}

bool ITSPreprocessor::process() {
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "starting preprocessing..." << std::endl;
    }
    const Profile profile_preproc{"preprocessing"};
    auto success = false;
    const auto apply = [&]<class T, class... Args>(const std::string &message, const Args &... args) {
        auto proc = std::make_unique<T>(args...);
        if (Config::Analysis::doLogPreproc()) {
            std::cout << message << "..." << std::endl;
        }
        const Profile profile{message};
        const auto res = proc->process();
        profile.end();
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "done " << message << std::endl;
        }
        if (!res) {
            return false;
        }
        success = true;
        procs.emplace_back(std::move(proc));
        return true;
    };
    apply.operator()<IrrelevantRuleRemover>("removing irrelevant rules (forward)", its, true);
    apply.operator()<IrrelevantRuleRemover>("removing irrelevant rules (backward)", its, false);
    apply.operator()<Chainer>("chaining", its);
    apply.operator()<ITSRulePreprocessor>("preprocessing rules", its);
    apply.operator()<BotRemover>("removing unsat rules", its);
    apply.operator()<IdentityRuleRemover>("removing identity rules", its);
    if (Config::Analysis::engine == Config::Analysis::ADCL) {
        apply.operator()<Unroller>("unrolling", its);
        if (its->size() <= 1000) {
            apply.operator()<DGRefiner>("refining dependency graph", its);
        }
    }
    apply.operator()<EmptyClauseRemover>("removing unsat empty clauses", its);
    profile_preproc.end();
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "done with preprocessing" << std::endl;
    }
    return success;
}

ITSModel ITSPreprocessor::transform_model(const ITSModel &m) const {
    auto res = m;
    for (const auto &proc: procs | std::views::reverse) {
        res = proc->transform_model(res);
    }
    return res;
}

std::shared_ptr<ITSCex> ITSPreprocessor::transform_cex(const std::shared_ptr<ITSCex> &cex) const {
    auto res = cex;
    for (const auto &proc: procs | std::views::reverse) {
        res = proc->transform_cex(res);
    }
    return res;
}
