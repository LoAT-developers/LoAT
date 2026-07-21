#include "itscex.hpp"
#include "formulapreprocessing.hpp"
#include "smtfactory.hpp"
#include "config.hpp"

#include <ranges>
#include <stack>
#include <utility>

ITSCex::AccelInfo::AccelInfo(RulePtr p_in, ArrayReadPtr<Arith> p_n, RulePtr p_out): m_in(p_in), m_n(p_n), m_out(p_out) {}

RulePtr ITSCex::AccelInfo::in() const {
    return m_in;
}

RulePtr ITSCex::AccelInfo::out() const {
    return m_out;
}

ArrayReadPtr<Arith> ITSCex::AccelInfo::n() const {
    return m_n;
}

ITSCex::TransformationInfo::TransformationInfo(RulePtr p_in, RulePtr p_out) : m_in(std::move(p_in)),
                                                                              m_out(std::move(p_out)) {
}

ITSCex::TransformationInfo::TransformationInfo(
    RulePtr p_in,
    std::shared_ptr<ModelTransformer> p_transformer,
    RulePtr p_out) : m_in(std::move(p_in)),
                     m_transformer(std::move(p_transformer)),
                     m_out(std::move(p_out)) {
}

ModelPtr ITSCex::TransformationInfo::transform_model(const ModelPtr p_model) const {
    return m_transformer->transform_model(p_model);
}

RulePtr ITSCex::TransformationInfo::in() const {
    return m_in;
}

RulePtr ITSCex::TransformationInfo::out() const {
    return m_out;
}

ITSCex::ResolventInfo::ResolventInfo(
    std::vector<RulePtr> p_in,
    std::vector<Renaming> p_subs,
    RulePtr p_out) : m_in(std::move(p_in)),
                     m_subs(std::move(p_subs)),
                     m_out(std::move(p_out)) {
}

std::vector<ModelPtr> ITSCex::ResolventInfo::transform_model(const ModelPtr p_model) const {
    std::vector<ModelPtr> res;
    ModelPtr current = p_model;
    for (unsigned i = 0; i < m_in.size(); ++i) {
        const auto r = m_in.at(i);
        const auto subs = m_subs.at(i);
        current = current->composeBackwards(subs);
        res.emplace_back(current);
        current = current->composeBackwards(r->getUpdate());
    }
    return res;
}

const std::vector<RulePtr>& ITSCex::ResolventInfo::in() const {
    return m_in;
}

RulePtr ITSCex::ResolventInfo::out() const {
    return m_out;
}

size_t ITSCex::ResolventInfo::size() const {
    return m_in.size();
}

ITSCex::ResolventInfo::operator bool() const {
    return m_in.size() > 1;
}

bool ITSCex::is_known(const RulePtr &rule) const {
    return accel.contains(rule) || resolvents.contains(rule) || recurrent_set.contains(rule) || implicants.
           contains(rule) || orig.contains(rule);
}

ITSCex::ITSCex(const linked_hash_set<RulePtr> &orig) : orig(orig) {
}

void ITSCex::add_orig(const RulePtr &rule) {
    if (Config::Analysis::model) {
        orig.insert(rule);
    }
}

void ITSCex::undo(const TransformationInfo& ti) {
    orig.erase(ti.out());
    if (!is_known(ti.in())) {
        orig.insert(ti.in());
    }
    implicants.emplace(ti.out(), ti);
}

void ITSCex::undo(const ResolventInfo &ri) {
    orig.erase(ri.out());
    for (const auto &r: ri.in()) {
        if (!is_known(r)) {
            orig.insert(r);
        }
    }
    add_resolvent(ri);
}

std::vector<std::pair<RulePtr, ProofStepKind> > ITSCex::get_used_rules(const std::vector<RulePtr> &transitions) const {
    linked_hash_set<RulePtr> done;
    std::stack<RulePtr> todo;
    std::vector<std::pair<RulePtr, ProofStepKind> > derived;
    for (const auto &transition: std::ranges::reverse_view(transitions)) {
        todo.push(transition);
    }
    while (!todo.empty()) {
        const auto t{todo.top()};
        auto ready{true};
        if (!done.contains(t)) {
            if (const auto ti{accel.get(t)}) {
                if ((ready = done.contains(ti->in()))) {
                    derived.emplace_back(t, ProofStepKind::ACCEL);
                } else {
                    todo.push(ti->in());
                }
            } else if (const auto ti{implicants.get(t)}) {
                if ((ready = done.contains(ti->in()))) {
                    derived.emplace_back(t, ProofStepKind::IMPLICANT);
                } else {
                    todo.push(ti->in());
                }
            } else if (const auto ri{resolvents.get(t)}) {
                for (const auto &r: ri->in()) {
                    if (!done.contains(r)) {
                        todo.push(r);
                        ready = false;
                    }
                }
                if (ready) {
                    derived.emplace_back(t, ProofStepKind::RESOLVENT);
                }
            } else if (const auto ti{recurrent_set.get(t)}) {
                if ((ready = done.contains(*ti))) {
                    derived.emplace_back(t, ProofStepKind::RECURRENT_SET);
                } else {
                    todo.push(*ti);
                }
            } else {
                assert(orig.contains(t));
                derived.emplace_back(t, ProofStepKind::ORIG);
            }
        }
        if (ready) {
            done.insert(t);
            todo.pop();
        }
    }
    return derived;
}

void ITSCex::add_recurrent_set(const RulePtr &ti, const RulePtr &res) {
    if (Config::Analysis::model) {
        assert(res->getGuard() != bot());
        assert(is_known(ti));
        recurrent_set.put(res, ti);
    }
}

void ITSCex::add_accel(const AccelInfo &ai) {
    if (Config::Analysis::model) {
        assert(ai.in()->getGuard() != bot());
        assert(is_known(ai.in()));
        if (ai.in() != ai.out()) {
            accel.put(ai.out(), ai);
        }
    }
}

void ITSCex::add_resolvent(const ResolventInfo &ri) {
    if (Config::Analysis::model) {
        assert(ri.out()->getGuard() != bot());
        assert(std::ranges::all_of(ri.in(), [&](const auto& r) { return is_known(r);}));
        resolvents.put(ri.out(), ri);
    }
}

void ITSCex::add_implicant(const TransformationInfo &ti) {
    if (Config::Analysis::model) {
        assert(is_known(ti.in()));
        assert(ti.out()->getGuard() != bot());
        if (ti.in() != ti.out()) {
            implicants.put(ti.out(), ti);
        }
    }
}

const linked_hash_set<RulePtr> &ITSCex::get_orig() const {
    return orig;
}

const linked_hash_map<RulePtr, ITSCex::AccelInfo> &ITSCex::get_accel() const {
    return accel;
}

const linked_hash_map<RulePtr, RulePtr> &ITSCex::get_recurrent_set() const {
    return recurrent_set;
}

const linked_hash_map<RulePtr, ITSCex::TransformationInfo> &ITSCex::get_implicants() const {
    return implicants;
}

const linked_hash_map<RulePtr, ITSCex::ResolventInfo> &ITSCex::get_resolvents() const {
    return resolvents;
}
