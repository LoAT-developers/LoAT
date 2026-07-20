#pragma once

#include "formulapreprocessing.hpp"
#include "itsproblem.hpp"
#include "rule.hpp"
#include "proof.hpp"

class ITSCex {

public:

    class TransformationInfo {
        RulePtr m_in;
        std::shared_ptr<ModelTransformer> m_transformer;
        RulePtr m_out;

    public:
        explicit TransformationInfo(RulePtr, RulePtr);
        TransformationInfo(RulePtr, std::shared_ptr<ModelTransformer>, RulePtr);
        ModelPtr transform_model(ModelPtr) const;
        RulePtr in() const;
        RulePtr out() const;
    };

    class ResolventInfo {
        std::vector<RulePtr> m_in;
        std::vector<Renaming> m_subs;
        RulePtr m_out;

    public:
        ResolventInfo(std::vector<RulePtr>, std::vector<Renaming>, RulePtr);
        std::vector<ModelPtr> transform_model(ModelPtr) const;
        const std::vector<RulePtr>& in() const;
        RulePtr out() const;
        size_t size() const;

        explicit operator bool() const;

    };

protected:

    linked_hash_set<RulePtr> orig;
    linked_hash_map<RulePtr, RulePtr> accel;
    linked_hash_map<RulePtr, TransformationInfo> implicants;
    linked_hash_map<RulePtr, RulePtr> recurrent_set;
    linked_hash_map<RulePtr, ResolventInfo> resolvents;

    bool is_known(const RulePtr& rule) const;

public:
    virtual ~ITSCex() = default;

    explicit ITSCex(const linked_hash_set<RulePtr>& orig);

    void add_orig(const RulePtr& rule);
    void undo(const TransformationInfo&);
    void undo(const ResolventInfo&);
    void add_accel(const RulePtr&, const RulePtr& res);
    void add_recurrent_set(const RulePtr&, const RulePtr& res);
    void add_resolvent(const ResolventInfo&);
    void add_implicant(const TransformationInfo&);
    const linked_hash_set<RulePtr> &get_orig() const;
    const linked_hash_map<RulePtr, RulePtr> &get_accel() const;
    const linked_hash_map<RulePtr, RulePtr> &get_recurrent_set() const;
    const linked_hash_map<RulePtr, TransformationInfo> &get_implicants() const;
    const linked_hash_map<RulePtr, ResolventInfo> &get_resolvents() const;
    std::vector<std::pair<RulePtr, ProofStepKind>> get_used_rules(const std::vector<RulePtr> &transitions) const;

};