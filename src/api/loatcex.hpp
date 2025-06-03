#pragma once

#include "itssafetycex.hpp"
#include "rule.hpp"
#include "model.hpp"
#include "proof.hpp"
#include "linkedhashmap.hpp"

class LoatCex
{
private:
    ITSCex m_cex;

public:
    explicit LoatCex(const ITSCex &cex)
        : m_cex(cex) {}

    const linked_hash_map<RulePtr, RulePtr> &getAccelerations() const
    {
        return m_cex.get_accel();
    }

    const linked_hash_map<RulePtr, RulePtr> &getImplicants() const
    {
        return m_cex.get_implicants();
    }

    const linked_hash_map<RulePtr, std::vector<RulePtr>> &getResolvents() const
    {
        return m_cex.get_resolvents();
    }

    std::vector<std::pair<RulePtr, ProofStepKind>> getUsedSteps(const std::vector<RulePtr> &transitions) const
    {
        return m_cex.get_used_rules(transitions);
    }

    const ITSCex &raw() const
    {
        return m_cex;
    }
};