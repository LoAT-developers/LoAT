#include "safetymodel.hpp"

SafetyModel::SafetyModel(SafetyProblem p_sp, unsigned p_k): m_sp(p_sp), m_k(p_k) {}

SafetyProblem SafetyModel::getSafetyProblem() {
    return m_sp;
}

unsigned SafetyModel::k() {
    return m_k;
}
