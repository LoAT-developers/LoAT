#pragma once

#include <limits>

#include "itsproblem.hpp"
#include "z3.hpp"

class ABMC {

private:

    using Run = std::vector<TransIdx>;
    using Key = std::pair<Run, LitSet>;

    static const bool log;

    ABMC(const ITSProblem &its);

    void analyze();

    ITSProblem its;
    Z3<IntTheory, BoolTheory> z3{std::numeric_limits<unsigned>::max()};
    bool approx {false};
    TransIdx last_orig_clause;
    std::vector<Subs> subs {Subs::Empty};
    std::vector<TransIdx> trace;
    VarSet vars;
    std::map<Var, Var> post_vars;
    NumVar trace_var;
    std::vector<BoolExpr> shortcuts;
    std::map<Key, std::optional<TransIdx>> cache;
    int lookback {0};

    BoolExpr encode_transition(const TransIdx idx);
    bool is_orig_clause(const TransIdx idx) const;
    std::optional<unsigned> has_looping_suffix(unsigned start);
    TransIdx add_learned_clause(const Rule &accel, const unsigned backlink);
    std::tuple<Rule, Subs, Key> build_loop(const int backlink);
    bool handle_loop(int backlink);

public:

    static void analyze(const ITSProblem &its);

};