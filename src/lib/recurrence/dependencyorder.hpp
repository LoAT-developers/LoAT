#pragma once

#include <optional>

#include "theory.hpp"
#include "subs.hpp"

/**
 * Functions to compute an ordering on updated variables,
 * such that we can solve recurrences in this order.
 *
 * For an update A := B+C, the recurrences for B and C must be known before
 * we can compute the recurrence for A. So B,C come before A in the ordering.
 *
 * Note that such an ordering does not always exist,
 * e.g., A := B+1, B := A+2.
 */
namespace DependencyOrder {

/**
 * Tries to find an order to calculate recurrence equations.
 * Fails if there is a nontrivial set of variables whose updates depend on each other.
 * @return list indicating the order (if successful)
 */
std::optional<std::vector<Var>> findOrder(const Subs &update);

}
