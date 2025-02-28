#pragma once

class ITSProblem;
class ITSModel;
class ITSSafetyCex;
class Rule;

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

using ITSPtr = std::shared_ptr<ITSProblem>;
using RulePtr = cpp::not_null<std::shared_ptr<const Rule>>;
