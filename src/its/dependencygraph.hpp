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


#include <vector>
#include <map>
#include <set>
#include <functional>
#include <ostream>

#include "rule.hpp" // for TransIdx

using Node = Implicant;
using Edge = std::pair<Node, Node>;

class DependencyGraph {
public:
    DependencyGraph();

    void addNode(const Node node, std::set<Node> preds, std::set<Node> succs, bool self_loop);
    void replaceNode(Node to_replace, Node replacement);
    void removeEdge(Node from, Node to);
    void removeEdges(const std::set<Edge> &remove);
    std::set<Edge> refine(Node node, std::function<bool(const Node&, const Node&)> is_edge);
    std::set<Edge> refine(std::function<bool(const Node&, const Node&)> is_edge);
    bool hasEdge(Node from, Node to) const;
    const std::set<Node>& getNodes() const;
    std::set<Node> getSuccessors(Node node) const;
    std::set<Node> getPredecessors(Node node) const;
    void removeNode(Node node);
    size_t size() const;

private:

    std::set<Node> nodes;
    std::map<Node, std::set<Node>> successors;
    std::map<Node, std::set<Node>> predecessors;
    size_t edgecount {0};

};

std::ostream& operator<<(std::ostream &s, const Edge &e);
std::ostream& operator<<(std::ostream &s, const DependencyGraph &d);
