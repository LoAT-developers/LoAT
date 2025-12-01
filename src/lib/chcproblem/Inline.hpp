#pragma once

#include "chcproblem.hpp"
#include "dependencygraph.hpp"

class Inline {

    public:

    explicit Inline(CHCPtr);

    CHCPtr run() const;

private:

    void init();
    std::vector<ClausePtr> do_inline(const ClausePtr&, const FunAppPtr&) const;

    DependencyGraph<std::string> graph;
    linked_hash_set<std::string> non_recursive;
    CHCPtr chcs;

};
