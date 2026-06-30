#include "itsmodel.hpp"

ITSModel::ITSModel(ITSPtr p_its, unsigned p_k): m_its(std::move(p_its)), m_k(p_k) {}

std::ostream& operator<<(std::ostream &p_s, const ITSModel &p_m) {
    return p_s << "the following system is " << p_m.m_k << "-inductive:\n" << p_m.m_its << std::endl;
}
