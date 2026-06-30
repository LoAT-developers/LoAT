#include "chcmodel.hpp"

CHCModel::CHCModel(CHCPtr p_chcs, unsigned p_k): m_chcs(p_chcs), m_k(p_k) {}

CHCPtr CHCModel::chcs() const {
    return m_chcs;
}

unsigned CHCModel::k() const {
    return m_k;
}

std::ostream& operator<<(std::ostream &p_s, const CHCModel &p_m) {
    return p_s << "the following system is " << p_m.m_k << "-inductive:\n" << p_m.m_chcs << std::endl;
}
