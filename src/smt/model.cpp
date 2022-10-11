#include "model.hpp"

Model::Model(const TheTheory::Model &m): m(m) {}

Model::Model() {}

std::ostream& operator<<(std::ostream &s, const Model &e) {
    return s << e.toSubs();
}
