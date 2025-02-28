#pragma once

namespace sexpresso {
struct Sexp;
}

template <class Abstract, class Concrete, class Hash, class Eq, class... Args>
class ConsHash;

namespace cpp {
inline namespace bitwizeshift {
template <typename T>
class not_null;
}
} // namespace cpp
