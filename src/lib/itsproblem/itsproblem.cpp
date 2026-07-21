#include "itsproblem.hpp"
#include "config.hpp"

ArithVarPtr ITSProblem::loc_var() {
    const auto static res = arrays::nextProgConst<Arith>();
    return res;
}

ArithVarPtr ITSProblem::cost_var() {
    const auto static res = arrays::nextProgConst<Arith>();
    return res;
}

ITSProblem::ITSProblem() {}

ITSProblem::ITSProblem(const DG &p_graph): graph(p_graph) {}

bool ITSProblem::isEmpty() const {
    return graph.empty();
}

const linked_hash_set<RulePtr>& ITSProblem::getAllTransitions() const {
    return graph.getNodes();
}

linked_hash_set<RulePtr> ITSProblem::getSuccessors(const RulePtr& p_rule) const {
    return graph.getSuccessors(p_rule);
}

linked_hash_set<RulePtr> ITSProblem::getPredecessors(const RulePtr& p_rule) const {
    return graph.getPredecessors(p_rule);
}

bool ITSProblem::areAdjacent(const RulePtr& p_first, const RulePtr& p_second) const {
    return graph.hasEdge(p_first, p_second);
}

ITSPtr ITSProblem::removeRule(const RulePtr& p_transition) const {
    auto new_graph = graph;
    new_graph.removeNode(p_transition);
    return std::make_shared<ITSProblem>(new_graph);
}

ITSPtr ITSProblem::addRule(const RulePtr p_rule, const RuleProperties& p_props, const linked_hash_set<RulePtr> &p_preds, const linked_hash_set<RulePtr> &p_succs) const {
    auto new_graph = graph;
    new_graph.addNode(p_rule, p_preds, p_succs, p_props.is_loop);
    if (p_props.is_initial) {
        new_graph.markRoot(p_rule);
    }
    if (p_props.is_sink) {
        new_graph.markSink(p_rule);
    }
    return std::make_shared<ITSProblem>(new_graph);
}

ITSPtr ITSProblem::addRule(const RulePtr p_rule, const RulePtr p_same_preds, const RulePtr p_same_succs) const {
    const auto preds = graph.getPredecessors(p_same_preds);
    const auto succs = graph.getSuccessors(p_same_succs);
    RuleProperties props {.is_loop = succs.contains(p_same_preds), .is_initial = graph.isRoot(p_same_preds), .is_sink = graph.isSink(p_same_succs)};
    return addRule(p_rule, props, preds, succs);
}

ITSPtr ITSProblem::addLearnedRule(const RulePtr p_rule, const RulePtr p_same_preds, const RulePtr p_same_succs) const {
    const auto preds = graph.getPredecessors(p_same_preds);
    const auto succs = graph.getSuccessors(p_same_succs);
    RuleProperties props {.is_loop = false, .is_initial = graph.isRoot(p_same_preds), .is_sink = graph.isSink(p_same_succs)};
    return addRule(p_rule, props, preds, succs);
}

ITSPtr ITSProblem::addQuery(const RulePtr p_err, const RulePtr p_same_preds) const {
    const auto preds = graph.getPredecessors(p_same_preds);
    RuleProperties props {.is_loop = false, .is_initial = graph.isRoot(p_same_preds), .is_sink = true};
    return addRule(p_err, props, preds, {});
}

ITSPtr ITSProblem::replaceRule(const RulePtr p_to_replace, const RulePtr p_replacement) const {
    if (p_to_replace == p_replacement) {
        return shared_from_this();
    }
    auto new_graph = graph;
    new_graph.replaceNode(p_to_replace, p_replacement);
    return std::make_shared<ITSProblem>(new_graph);
}

VarSet ITSProblem::getVars() const {
    VarSet res;
    for (const auto &r: graph.getNodes()) {
        r->collectVars(res);
    }
    return res;
}

CellSet ITSProblem::getCells() const {
    CellSet res;
    for (const auto &r: graph.getNodes()) {
        r->collectCells(res);
    }
    return res;
}

Arith::Expr ITSProblem::getCost(const RulePtr& rule) {
    return rule->getUpdate().getConst(cost_var()) - cost_var();
}

const linked_hash_set<RulePtr>& ITSProblem::getInitialTransitions() const {
    return graph.getRoots();
}

const linked_hash_set<RulePtr>& ITSProblem::getSinkTransitions() const {
    return graph.getSinks();
}

bool ITSProblem::isSimpleLoop(const RulePtr& idx) const {
    return graph.hasEdge(idx, idx);
}

bool ITSProblem::isSinkTransition(const RulePtr& idx) const {
    return graph.getSinks().contains(idx);
}

bool ITSProblem::isInitialTransition(const RulePtr& idx) const {
    return graph.getRoots().contains(idx);
}

const ITSProblem::DG& ITSProblem::getDependencyGraph() const {
    return graph;
}

std::pair<ITSPtr, linked_hash_set<ITSProblem::DG::Edge>> ITSProblem::refineDependencyGraph(const std::function<bool(const RulePtr&, const RulePtr&)> &is_edge) const {
    auto new_graph = graph;
    const auto deleted = new_graph.refine(is_edge);
    const auto new_its = std::make_shared<ITSProblem>(new_graph);
    return {new_its, deleted};
}

size_t ITSProblem::size() const {
    return graph.size();
}

bool ITSProblem::hasArrays() const {
    for (const auto &x: getVars()) {
        if (theory::apply(x, [&](const auto &x) {
            return x->dim() > 0;
        })) {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream &s, const ITSPtr& its) {
    s << "Initial Rules:\n";
    if (its->getInitialTransitions().empty()) {
        s << "  <empty>\n";
    } else {
        for (const auto &idx : its->getInitialTransitions()) {
            s << std::setw(4);
            s << *idx;
            s << std::endl;
        }
    }
    s << "\n\nRules:\n";
    if (its->isEmpty()) {
        s << "  <empty>\n";
    } else {
        for (const auto &idx : its->getAllTransitions()) {
            if (!its->isInitialTransition(idx) && !its->isSinkTransition(idx)) {
                s << std::setw(4);
                s << *idx;
                s << std::endl;
            }
        }
    }
    s << "Sink Rules:\n";
    if (its->getSinkTransitions().empty()) {
        s << "  <empty>\n";
    } else {
        for (const auto &idx : its->getSinkTransitions()) {
            s << std::setw(4);
            s << *idx;
            s << std::endl;
        }
    }
    if (Config::Output::print_dependency_graph) {
        s << "\nDependency graph:\n";
        s << its->getDependencyGraph() << std::endl;
    }
    return s;
}
