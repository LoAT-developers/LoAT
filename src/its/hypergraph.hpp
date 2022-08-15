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

#ifndef HYPERGRAPH_H
#define HYPERGRAPH_H


#include <vector>
#include <map>
#include <set>
#include <algorithm>

#include "types.hpp" // for TransIdx


/**
 * A simple directed hypergraph, where each transition has a single source,
 * but (possibly) several targets. Templated over the type of Nodes.
 */
template <typename Node>
class HyperGraph {
public:
    HyperGraph() : nextIdx(0) {}

    /**
     * Add a new transition with a single target
     * @return the index of the added transition
     */
    TransIdx addTrans(Node from, Node to) {
        TransIdx currIdx = nextIdx++;
        InternalTransition trans = {from, {to}};

        transitions[currIdx] = std::move(trans);
        predecessor[to].insert(from);
        outgoing[from][to].push_back(currIdx);
        return currIdx;
    }

    /**
     * Add a new transition with several targets (there must be at least one)
     * @return the index of the added transition
     */
    TransIdx addTrans(Node from, std::set<Node> to) {
        assert(!to.empty());
        TransIdx currIdx = nextIdx++;
        InternalTransition trans = {from, to};
        transitions[currIdx] = {from, to};

        // An edge "f -> g,h" (from f to g and h) means that f is a predecessor of both g and h.
        // Moreover, when we query edges from f to g (or h), we want to include this edge
        // (this makes sense, since we can always simplify "f -> g,h" to just "f -> g").
        // (note that we only add one edge "f -> g" for the rule "f -> g,g" since we use sets).

        for (Node t : to) {
            predecessor[t].insert(from);
            outgoing[from][t].push_back(currIdx);
        }

        return currIdx;
    }

    size_t getTransCount() const {
        return transitions.size();
    }

    bool hasTransTo(Node node) const {
        return predecessor.find(node) != predecessor.end();
    }

    bool hasTransFrom(Node node) const {
        auto it = outgoing.find(node);
        return it != outgoing.end() && !it->second.empty();
    }

    bool hasTransFromTo(Node from, Node to) const {
        auto it = outgoing.find(from);
        if (it == outgoing.end()) return false;

        auto targetIt = it->second.find(to);
        if (targetIt == it->second.end()) return false;

        return !targetIt->second.empty();
    }

    // Returns list of all transitions (without duplicates)
    std::vector<TransIdx> getAllTrans() const {
        std::vector<TransIdx> res;
        res.reserve(transitions.size());
        for (const auto &it : transitions) {
            res.push_back(it.first);
        }
        return res;
    }

    // To avoid duplicates (when using hyperedges), this returns a set
    std::set<TransIdx> getTransFrom(Node from) const {
        std::set<TransIdx> res;
        auto it = outgoing.find(from);
        if (it != outgoing.end()) {
            for (auto targetIt : it->second) {
                for (TransIdx trans : targetIt.second) {
                    res.insert(trans);
                }
            }
        }
        return res;
    }

    // The returned vector does not contain any duplicates,
    // so we prefer a vector over a set for performance
    std::vector<TransIdx> getTransFromTo(Node from, Node to) const {
        auto it = outgoing.find(from);
        if (it == outgoing.end()) return {};

        auto targetIt = it->second.find(to);
        if (targetIt == it->second.end()) return {};

        return targetIt->second;
    }

    // To avoid duplicates (when using hyperedges), this returns a set
    std::set<TransIdx> getTransTo(Node to) const {
        auto pred = predecessor.find(to);
        if (pred == predecessor.end()) {
            return {};
        }

        std::set<TransIdx> res;
        for (Node from : pred->second) {
            for (TransIdx trans : getTransFromTo(from, to)) {
                res.insert(trans);
            }
        }
        return res;
    }

    std::set<Node> getSuccessors(Node node) const {
        std::set<Node> res;
        auto it = outgoing.find(node);
        if (it != outgoing.end()) {
            for (auto targetIt : it->second) {
                res.insert(targetIt.first);
            }
        }
        return res;
    }

    std::set<Node> getPredecessors(Node node) const {
        auto it = predecessor.find(node);
        return (it == predecessor.end()) ? std::set<Node>() : it->second;
    }

    inline Node getTransSource(TransIdx idx) const { return transitions.at(idx).from; }
    inline const std::set<Node>& getTransTargets(TransIdx idx) const { return transitions.at(idx).to; }


    /**
     * Changes the given transition to point to the given new target
     * (no new transition is added, data is kept)
     */
    void changeTransTargets(TransIdx trans, std::set<Node> newTargets) {
        removeTransFromGraph(trans);
        InternalTransition &t = transitions[trans];

        for (Node to : newTargets) {
            outgoing[t.from][to].push_back(trans);
            predecessor[to].insert(t.from);
        }

        t.to = newTargets;
    }

    /**
     * Splits the given node into two nodes, one for all incoming transitions (node) and one for all outgoing transitions (newOutgoing)
     * @note newOutgoing *must* be a fresh node index
     * @note afterwards, node has only incoming, newOutgoing only outgoing transitions
     */
    void splitNode(Node node, Node newOutgoing) {
        assert(outgoing.count(newOutgoing) == 0 && predecessor.count(newOutgoing) == 0);

        //move outgoing to new node
        auto it = outgoing.find(node);
        if (it != outgoing.end()) {
            outgoing[newOutgoing] = it->second;
            outgoing.erase(it);
        }

        //adjust predecessor references for all successors
        for (Node succ : getSuccessors(newOutgoing)) {
            predecessor[succ].erase(node);
            predecessor[succ].insert(newOutgoing);
        }

        //adjust transitions from new node
        for (TransIdx idx : getTransFrom(newOutgoing)) {
            transitions[idx].from = newOutgoing;
        }
    }

    /**
     * Removes the given node, returns set of transitions that were removed in the process.
     */
    std::set<TransIdx> removeNode(Node idx) {
        std::set<TransIdx> toRemove;

        //find outgoing transitions
        for (TransIdx out : getTransFrom(idx)) {
            toRemove.insert(out);
        }

        //find incoming transitions
        for (TransIdx in : getTransTo(idx)) {
            toRemove.insert(in);
        }

        //remove it all
        for (TransIdx idx : toRemove) {
            removeTrans(idx);
        }

        assert(outgoing.count(idx) == 0);
        assert(predecessor.count(idx) == 0);

        return toRemove;
    }

    void removeTrans(TransIdx idx) {
        removeTransFromGraph(idx);
        transitions.erase(idx);
    }

    enum CheckResult { Valid=0, InvalidNode, EmptyMapEntry, UnknownTrans, InvalidTrans, UnusedTrans, DuplicateTrans, InvalidPred, InvalidPredCount };

private:
    //updates outgoing, predecessor to remove given trans from it current location
    void removeTransFromGraph(TransIdx trans) {
        InternalTransition &t = transitions[trans];

        for (Node to : t.to) {
            std::vector<TransIdx> &vec = outgoing[t.from][to];
            vec.erase(std::find(vec.begin(),vec.end(),trans));
            if (vec.empty()) {
                outgoing[t.from].erase(to);
                if (outgoing[t.from].empty()) outgoing.erase(t.from);
                predecessor[to].erase(t.from);
                if (predecessor[to].empty()) predecessor.erase(to);
            }
        }
    }

    /**
     * Function to check the integrity of all datastructures (used for debugging and testing only)
     */
    int check_internal(std::set<Node> *nodes) const {
        int edgecount = 0; //counting multi-edges once only
        std::set<TransIdx> seen;
        for (auto it : outgoing) {
            if (nodes && nodes->count(it.first) == 0) return InvalidNode;
            if (it.second.empty()) return EmptyMapEntry;
            for (auto it2 : it.second) {
                for (TransIdx trans : it2.second) {
                    if (nodes && nodes->count(it2.first) == 0) return InvalidNode;
                    if (transitions.count(trans) == 0) return UnknownTrans;

                    InternalTransition t = transitions.at(trans);
                    if (t.to.empty()) return InvalidTrans;
                    if (t.from != it.first || std::find(t.to.begin(), t.to.end(), it2.first) == t.to.end()) {
                        // The transition does not originate in it.first or does not (among others) lead to it2.first
                        return InvalidTrans;
                    }

                    // Duplicate transitions may occur, since "f -> g,h" is counted as "f -> g" and "f -> h"
                    // Hence a duplicate transition is only an error for single-target edges
                    if (seen.count(trans) > 0 && t.to.size() == 1) {
                        return DuplicateTrans;
                    }

                    seen.insert(trans);
                }
                if (!it2.second.empty()) edgecount++;
            }
        }
        if (seen.size() != transitions.size()) return UnusedTrans;

        int cnt = 0;
        for (auto it : predecessor) {
            if (nodes && nodes->count(it.first) == 0) return InvalidNode;
            if (it.second.empty()) return EmptyMapEntry;
            for (Node node : it.second) {
                if (nodes && nodes->count(it.first) == 0) return InvalidNode;
                cnt++;
                //at() will throw an exception if outgoing trans does exist
                auto it1 = outgoing.find(node);
                if (it1 == outgoing.end()) {
                    return InvalidPred;
                }
                auto m = it1->second;
                auto it2 = m.find(it.first);
                if (it2 == m.end()) {
                    return InvalidPred;
                }
            }
        }
        if (cnt != edgecount) return InvalidPredCount;
        return Valid;
    }

private:
    struct InternalTransition {
        Node from;
        std::set<Node> to;
    };

    std::map<TransIdx,InternalTransition> transitions;
    std::map<Node,std::map<Node,std::vector<TransIdx>>> outgoing;
    std::map<Node,std::set<Node>> predecessor;

    TransIdx nextIdx;
};


#endif // HYPERGRAPH_H
