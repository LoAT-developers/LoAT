#pragma once

class CHCProblem;
class CHCModel;
class CHCCex;
class Clause;

namespace std {
template <class T>
class shared_ptr;
}

namespace cpp {
inline namespace bitwizeshift {
template <typename T>
class not_null;
}
} // namespace cpp

using CHCPtr = std::shared_ptr<CHCProblem>;
using ClausePtr = cpp::not_null<std::shared_ptr<const Clause>>;
