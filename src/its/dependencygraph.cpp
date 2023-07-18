#include "dependencygraph.hpp"

DependencyGraph::DependencyGraph() {}

void DependencyGraph::addNode(const Node node, std::set<Node> preds, std::set<Node> succs, bool self_loop) {
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

void DependencyGraph::replaceNode(Node to_replace, Node replacement) {
    nodes.insert(replacement);
    nodes.erase(to_replace);
    for (const auto &pred: predecessors.at(to_replace)) {
        successors.at(pred).erase(to_replace);
        successors.at(pred).insert(replacement);
    }
    for (const auto &pred: successors.at(to_replace)) {
        if (pred == replacement) {
            predecessors.at(to_replace).erase(to_replace);
            predecessors.at(to_replace).insert(replacement);
        } else {
            predecessors.at(pred).erase(to_replace);
            predecessors.at(pred).insert(replacement);
        }
    }
    predecessors.emplace(replacement, predecessors.at(to_replace));
    successors.emplace(replacement, successors.at(to_replace));
    predecessors.erase(to_replace);
    successors.erase(to_replace);
}

void DependencyGraph::removeEdge(Node from, Node to) {
    successors.at(from).erase(to);
    predecessors.at(to).erase(from);
    --edgecount;
}

void DependencyGraph::removeEdges(const std::set<Edge> &remove) {
    for (const auto &p: remove) {
        removeEdge(p.first, p.second);
    }
}

std::set<Edge> DependencyGraph::refine(Node node, std::function<bool(const Node&, const Node&)> is_edge) {
    std::set<Edge> remove;
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

std::set<Edge> DependencyGraph::refine(std::function<bool(const Node&, const Node&)> is_edge) {
    std::set<Edge> remove;
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

bool DependencyGraph::hasEdge(Node from, Node to) const {
    const auto &succ = successors.at(from);
    return succ.find(to) != succ.end();
}

const std::set<Node>& DependencyGraph::getNodes() const {
    return nodes;
}

std::set<Node> DependencyGraph::getSuccessors(Node node) const {
    const auto it = successors.find(node);
    if (it == successors.end()) {
        return {};
    } else {
        return it->second;
    }
}

std::set<Node> DependencyGraph::getPredecessors(Node node) const {
    const auto it = predecessors.find(node);
    if (it == predecessors.end()) {
        return {};
    } else {
        return it->second;
    }
}

void DependencyGraph::removeNode(Node node) {
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

std::ostream& operator<<(std::ostream &s, const Edge &e) {
    return s << e.first << " -> " << e.second;
}

std::ostream& operator<<(std::ostream &s, const DependencyGraph &d) {
    for (const auto &l: d.getNodes()) {
        bool first {true};
        for (const auto &r: d.getSuccessors(l)) {
            if (first) {
                first = false;
            } else {
                s << ", ";
            }
            s << l << " -> " << r;
        }
        if (!first) {
            s << std::endl;
        }
    }
    return s;
}

size_t DependencyGraph::size() const {
    return edgecount;
}
