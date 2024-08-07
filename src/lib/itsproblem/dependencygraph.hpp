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
#include <unordered_set>
#include <functional>
#include <ostream>

#include "rule.hpp" // for TransIdx

template <class Node>
class DependencyGraph {

public:

    using Edge = std::pair<Node, Node>;

    DependencyGraph() {}

    bool addEdge(const Node &fst, const Node &snd) {
        const auto loop {fst == snd};
        const auto contains_fst {nodes.contains(fst)};
        const auto contains_snd {nodes.contains(snd)};
        auto changed {true};
        if (contains_fst) {
            if (contains_snd) {
                if (predecessors.at(snd).insert(fst).second) {
                    successors.at(fst).insert(snd);
                    ++edgecount;
                } else {
                    changed = false;
                }
            } else {
                addNode(snd, {fst}, {}, loop);
            }
        } else {
            if (contains_snd) {
                addNode(fst, {}, {snd}, loop);
            } else {
                addNode(fst, {}, {}, loop);
                if (!loop) {
                    addNode(snd, {fst}, {}, loop);
                }
            }
        }
        return changed;
    }

    void addNode(const Node node, linked_hash_set<Node> preds, linked_hash_set<Node> succs, bool self_loop) {
        if (self_loop) {
            preds.insert(node);
            succs.insert(node);
        }
        predecessors.emplace(node, preds);
        successors.emplace(node, succs);
        edgecount += preds.size();
        edgecount += succs.size();
        for (const auto &p: preds) {
            successors.at(p).insert(node);
        }
        for (const auto &s: succs) {
            predecessors.at(s).insert(node);
        }
        nodes.insert(node);
    }

    void replaceNode(Node to_replace, Node replacement) {
        nodes.insert(replacement);
        nodes.erase(to_replace);
        // all predecessors of to_replace get replacement as successor
        for (const auto &pred: predecessors.at(to_replace)) {
            auto it {successors.find(pred)};
            it->second.erase(to_replace);
            it->second.insert(replacement);
        }
        for (const auto &succ: successors.at(to_replace)) {
            auto it {predecessors.find(succ)};
            // all former successors of to_replace get replacement as predecessor
            if (it != predecessors.end()) {
                it->second.erase(to_replace);
                it->second.insert(replacement);
            }
            // to_replace has a self-loop -- redirect it to replacement
            // we'll copy the predecessors of to_replace to replacement later
            if (succ == replacement) {
                auto it {predecessors.find(to_replace)};
                it->second.erase(to_replace);
                it->second.insert(replacement);
            }
        }
        auto [it, new_node] {predecessors.emplace(replacement, predecessors.at(to_replace))};
        if (!new_node) {
            // replacement is an old node -- add all predecessors of to_replace
            const auto &to_insert {predecessors.at(to_replace)};
            it->second.insert(to_insert.begin(), to_insert.end());
        }
        it = successors.emplace(replacement, successors.at(to_replace)).first;
        if (!new_node) {
            const auto &to_insert {successors.at(to_replace)};
            it->second.insert(to_insert.begin(), to_insert.end());
        }
        predecessors.erase(to_replace);
        successors.erase(to_replace);
    }

    void removeEdge(Node from, Node to) {
        successors.at(from).erase(to);
        predecessors.at(to).erase(from);
        --edgecount;
    }

    void removeEdges(const linked_hash_set<Edge> &remove) {
        for (const auto &p: remove) {
            removeEdge(p.first, p.second);
        }
    }

    linked_hash_set<Edge> refine(Node node, std::function<bool(const Node&, const Node&)> is_edge) {
        linked_hash_set<Edge> remove;
        for (const auto &succ: successors.at(node)) {
            if (!is_edge(node, succ)) {
                remove.emplace(node, succ);
            }
        }
        for (const auto &pred: predecessors.at(node)) {
            if (!is_edge(pred, node)) {
                remove.emplace(pred, node);
            }
        }
        removeEdges(remove);
        return remove;
    }

    linked_hash_set<Edge> refine(std::function<bool(const Node&, const Node&)> is_edge) {
        linked_hash_set<Edge> remove;
        for (auto p: successors) {
            Node from = p.first;
            for (const auto &to: p.second) {
                if (!is_edge(from, to)) {
                    remove.emplace(from, to);
                }
            }
        }
        removeEdges(remove);
        return remove;
    }

    bool hasEdge(Node from, Node to) const {
        const auto it {successors.find(from)};
        return it != successors.end() && it->second.contains(to);
    }

    const linked_hash_set<Node>& getNodes() const {
        return nodes;
    }

    linked_hash_set<Node> getSuccessors(Node node) const {
        const auto it = successors.find(node);
        if (it == successors.end()) {
            return {};
        } else {
            return it->second;
        }
    }

    linked_hash_set<Node> getPredecessors(Node node) const {
        const auto it = predecessors.find(node);
        if (it == predecessors.end()) {
            return {};
        } else {
            return it->second;
        }
    }

    void removeNode(Node node) {
        nodes.erase(node);
        for (const auto &s: successors.at(node)) {
            predecessors.at(s).erase(node);
        }
        for (const auto &p: predecessors.at(node)) {
            successors.at(p).erase(node);
        }
        edgecount -= predecessors.at(node).size();
        edgecount -= successors.at(node).size();
        predecessors.erase(node);
        successors.erase(node);
    }

    size_t size() const {
        return edgecount;
    }

private:

    linked_hash_set<Node> nodes {};
    std::unordered_map<Node, linked_hash_set<Node>> successors {};
    std::unordered_map<Node, linked_hash_set<Node>> predecessors {};
    size_t edgecount {0};

};

template <class Node>
std::ostream& operator<<(std::ostream &s, const typename DependencyGraph<Node>::Edge &e) {
    return s << e.first << " -> " << e.second;
}

template std::ostream& operator<< <TransIdx>(std::ostream &s, const typename DependencyGraph<TransIdx>::Edge &e);
template std::ostream& operator<< <Implicant>(std::ostream &s, const typename DependencyGraph<Implicant>::Edge &e);

template <class Node>
std::ostream& operator<<(std::ostream &s, const DependencyGraph<Node> &d) {
    for (const auto &l: d.getNodes()) {
        for (const auto &r: d.getSuccessors(l)) {
            s << l << " -> " << r << std::endl;
        }
    }
    return s;
}
