#include "arraytype.hpp"

#include <boost/functional/hash.hpp>

theory::Type ArrayType::get_type() const {
    return t;
}

unsigned ArrayType::get_dimension() const {
    return dimension;
}

ArrayType::ArrayType(const theory::Type t, const unsigned dimension): t(t), dimension(dimension) {}

std::ostream& operator<<(std::ostream &s, const ArrayType &a) {
    s << theory::abbreviate(a.get_type());
    const auto d {a.get_dimension()};
    for (unsigned i = 0; i < d; ++i) {
        s << "[]";
    }
    return s;
}

std::size_t std::hash<ArrayType>::operator()(const ArrayType &x) const noexcept {
    size_t seed{23};
    boost::hash_combine(seed, x.get_dimension());
    boost::hash_combine(seed, x.get_type());
    return seed;
}
