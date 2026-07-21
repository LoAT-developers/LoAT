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

AbstractITSPreprocessor::AbstractITSPreprocessor(ITSPtr its): its(std::move(its)) {}

namespace {
    class ITSRulePreprocessor : public AbstractITSPreprocessor {

        std::vector<ITSCex::TransformationInfo> m_transformation_info;

    public:

        explicit ITSRulePreprocessor(const ITSPtr& its): AbstractITSPreprocessor(its) {}

        ITSPtr process() override {
            std::unordered_map<RulePtr, RulePtr> map;
            for (const auto& r: its->getAllTransitions()) {
                auto proc = std::make_shared<RulePreprocessor>(r);
                if (const auto res = proc->process(); res != r) {
                    m_transformation_info.emplace_back(r, proc, res);
                    map.emplace(r, res);
                }
            }
            for (const auto &[x,y]: map) {
                its = its->replaceRule(x, y);
            }
            return its;
        }

        ITSModel transform_model(const ITSModel &m) const override {
            return m;
        }

        std::shared_ptr<ITSCex> transform_cex(std::shared_ptr<ITSCex> cex) const override {
            for (const auto& t: m_transformation_info | std::views::reverse) {
                cex->undo(t);
            }
            return cex;
        }
    };
}

namespace {
    class BotRemover : public AbstractITSPreprocessor {
    public:

        explicit BotRemover(const ITSPtr& its): AbstractITSPreprocessor(its) {}

        ITSPtr process() override {
            std::vector<RulePtr> remove;
            for (const auto& r: its->getAllTransitions()) {
                if (r->getGuard() == bot()) {
                    remove.emplace_back(r);
                }
            }
            for (const auto &r: remove) {
                its = its->removeRule(r);
            }
            return its;
        }

        ITSModel transform_model(const ITSModel &m) const override {
            return m;
        }

        std::shared_ptr<ITSCex> transform_cex(std::shared_ptr<ITSCex> cex) const override {
            return cex;
        }
    };
}

namespace {
    class IrrelevantRuleRemover : public AbstractITSPreprocessor {

        bool forward;

    public:

        IrrelevantRuleRemover(const ITSPtr& its, const bool forward): AbstractITSPreprocessor(its), forward(forward) {}

        ITSPtr process() override {
            if (!Config::Analysis::safety()) {
                return its;
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
                its = its->removeRule(r);
            }
            if (Config::Analysis::doLogPreproc() && !deleted.empty()) {
                std::cout << "removed the following irrelevant transitions: " << deleted << std::endl;
            }
            return its;
        }

        ITSModel transform_model(const ITSModel &m) const override {
            return m;
        }

        std::shared_ptr<ITSCex> transform_cex(std::shared_ptr<ITSCex> cex) const override {
            return cex;
        }
    };
}

namespace {
    class IdentityRuleRemover : public AbstractITSPreprocessor {
    public:

        explicit IdentityRuleRemover(const ITSPtr& its): AbstractITSPreprocessor(its) {}

        ITSPtr process() override {
            linked_hash_set<RulePtr> remove;
            if (Config::Analysis::mode != Config::Analysis::Safety) {
                return its;
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
                its = its->removeRule(r);
            }
            if (!remove.empty() && Config::Analysis::doLogPreproc()) {
                std::cout << "removed the following identity transitions: " << remove << std::endl;
            }
            return its;
        }

        ITSModel transform_model(const ITSModel &m) const override {
            return m;
        }

        std::shared_ptr<ITSCex> transform_cex(std::shared_ptr<ITSCex> cex) const override {
            return cex;
        }
    };
}

namespace {
    /**
    * Motivating example: f(x,y) -> f(-x,z) :|: (y=0 /\ z=1) \/ (y=1 /\ z=0)
    * In contrast to its implicants, it can be unrolled to obtain simpler closed forms.
    */
    class Unroller : public AbstractITSPreprocessor {

        std::vector<ITSCex::ResolventInfo> m_chaining_info;

    public:

        explicit Unroller(const ITSPtr& its): AbstractITSPreprocessor(its) {}

        ITSPtr process() override {
            for (const auto &r : its->getAllTransitions()) {
                if (its->isSimpleLoop(r) && !r->getGuard()->isConjunction()) {
                    if (const auto chaining_info = LoopAcceleration::chain(r)) {
                        if (Config::Analysis::doLogPreproc()) {
                            std::cout
                                    << "unrolled the following rule " << chaining_info.size() << " times:\n"
                                    << r
                                    << "\nresult:\n"
                                    << chaining_info.out() << std::endl;
                        }
                        its = its->addRule(chaining_info.out(), r, r);
                        m_chaining_info.emplace_back(chaining_info);
                    }
                }
            }
            return its;
        }

        ITSModel transform_model(const ITSModel &m) const override {
            return m;
        }

        std::shared_ptr<ITSCex> transform_cex(std::shared_ptr<ITSCex> cex) const override {
            for (const auto& ci: m_chaining_info | std::views::reverse) {
                cex->undo(ci);
            }
            return cex;
        }
    };
}

namespace {
    class DGRefiner : public AbstractITSPreprocessor {

    public:

        explicit DGRefiner(const ITSPtr& its): AbstractITSPreprocessor(its) {}

        ITSPtr process() override {
            const auto is_edge = [](const RulePtr& fst, const RulePtr& snd) {
                return SmtFactory::check(Preprocess::chain({fst, snd->renameTmpVars().first})->getGuard()) == SmtResult::Sat;
            };
            if (const auto [new_its,removed]{its->refineDependencyGraph(is_edge)}; removed.empty()) {
                return its;
            } else {
                if (Config::Analysis::doLogPreproc()) {
                    std::cout << "removed the following edges from the dependency graph:" << std::endl;
                    for (const auto &[s,d]: removed) {
                        std::cout << "(" << s->getId() << ", " << d->getId() << ")" << std::endl;
                    }
                }
                return new_its;
            }
        }

        ITSModel transform_model(const ITSModel &m) const override {
            return m;
        }

        std::shared_ptr<ITSCex> transform_cex(std::shared_ptr<ITSCex> cex) const override {
            return cex;
        }
    };
}

namespace {
    class Chainer : public AbstractITSPreprocessor {

        std::vector<ITSCex::ResolventInfo> m_chained;

    public:

        explicit Chainer(const ITSPtr& its): AbstractITSPreprocessor(its) {}

        ITSPtr process() override {
            bool changed{false};
            do {
                changed = false;
                for (const auto first : its->getAllTransitions()) {
                    if (const auto succ{its->getSuccessors(first)}; succ.size() == 1 && !succ.contains(first)) {
                        if (const auto second_idx{*succ.begin()}; !its->isSimpleLoop(second_idx)) {
                            const auto [renamed, renaming] = second_idx->renameTmpVars();
                            const auto chained = Preprocess::chain({first, renamed});
                            if (Config::Analysis::doLogPreproc()) {
                                std::cout << "chaining\n\trule 1: " << *first << "\n\trule 2: " << *second_idx << "\n\tresult: " << chained << std::endl;
                            }
                            its = its->addRule(chained, first, second_idx);
                            if (Config::Analysis::model) {
                                m_chained.emplace_back(std::vector{first, second_idx}, std::vector{Renaming(), renaming}, chained);
                            }
                            its = its->removeRule(first);
                            if (its->getPredecessors(second_idx).empty()) {
                                its = its->removeRule(second_idx);
                            }
                            changed = true;
                            break;
                        }
                    }
                }
            } while (changed);
            return its;
        }

        ITSModel transform_model(const ITSModel &m) const override {
            auto its = m.its();
            for (const auto &ri: m_chained) {
                assert(ri.size() == 2);
                const auto fst = ri.in().front();
                const auto snd = ri.in().back();
                const auto res = ri.out();
                ITSProblem::RuleProperties props {
                    .is_loop = false,
                    .is_initial = its->isInitialTransition(res),
                    .is_sink = false
                };
                its = its->addRule(fst, props, its->getPredecessors(res), {});
                props = {
                    .is_loop = false,
                    .is_initial = false,
                    .is_sink = its->isSinkTransition(res)
                };
                its = its->addRule(snd, props, {fst}, its->getSuccessors(res));
            }
            return {its, m.k()};
        }

        std::shared_ptr<ITSCex> transform_cex(std::shared_ptr<ITSCex> cex) const override {
            for (const auto& ci: m_chained) {
                cex->undo(ci);
            }
            return cex;
        }
    };
}

ITSPreprocessor::ITSPreprocessor(const ITSPtr &its) : AbstractITSPreprocessor(its) {}

ITSPtr ITSPreprocessor::process() {
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "starting preprocessing..." << std::endl;
    }
    const Profile profile_preproc{"preprocessing"};
    const auto apply = [&]<class T, class... Args>(const std::string &message, const Args &... args) {
        auto proc = std::make_unique<T>(its, args...);
        if (Config::Analysis::doLogPreproc()) {
            std::cout << message << "..." << std::endl;
        }
        const Profile profile{message};
        const auto res = proc->process();
        profile.end();
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "done " << message << std::endl;
        }
        if (res == its) {
            return false;
        }
        its = res;
        procs.emplace_back(std::move(proc));
        return true;
    };
    apply.operator()<IrrelevantRuleRemover>("removing irrelevant rules (forward)", true);
    apply.operator()<IrrelevantRuleRemover>("removing irrelevant rules (backward)", false);
    apply.operator()<Chainer>("chaining");
    apply.operator()<ITSRulePreprocessor>("preprocessing rules");
    apply.operator()<BotRemover>("removing unsat rules");
    apply.operator()<IdentityRuleRemover>("removing identity rules");
    if (Config::Analysis::engine == Config::Analysis::ADCL) {
        apply.operator()<Unroller>("unrolling");
        if (its->size() <= 1000) {
            apply.operator()<DGRefiner>("refining dependency graph");
        }
    }
    profile_preproc.end();
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "done with preprocessing" << std::endl;
    }
    return its;
}

ITSModel ITSPreprocessor::transform_model(const ITSModel &m) const {
    auto res = m;
    for (const auto &proc: procs | std::views::reverse) {
        res = proc->transform_model(res);
    }
    return res;
}

std::shared_ptr<ITSCex> ITSPreprocessor::transform_cex(std::shared_ptr<ITSCex> cex) const {
    for (const auto &proc: procs | std::views::reverse) {
        cex = proc->transform_cex(cex);
    }
    return cex;
}
