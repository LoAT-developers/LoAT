/*  This file is part of LoAT.
 *  Copyright (c) 2015-2016 Matthias Naaf, RWTH Aachen University, Germany
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses>.
 */

#pragma once

#include "itsproblem.hpp"
#include "result.hpp"


namespace Chaining {
    /**
     * Applies a simple chaining strategy to the entire ITS problem.
     *
     * Starting from the initial node, all "linear paths" are chained (in a DFS traversal).
     * Here, "linear path" is a path where each node has at most one incoming and outgoing edge.
     * Such paths have no interesting control flow and can safely be chained into a single edge.
     *
     * After calling this, all nodes with exactly one in- and one outgoing edge have either been
     * (1) eliminated, if chaining the in- and outgoing edge was possible, or
     * (2) their outgoing edge was removed, if chaining was not possible (so the edge can never be taken).
     *
     * @return true iff the ITS was modified
     */
    ResultViaSideEffects chainLinearPaths(ITSProblem &its);

}
