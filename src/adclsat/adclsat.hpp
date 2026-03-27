#pragma once

#include "trputil.hpp"

class ADCLSat final: public TRPUtil {

    bool backtracking {false};
    unsigned nesting = 0;
    bool deepen = false;
    DependencyGraph<Bools::Expr> dg_over_approx;
    std::unordered_map<Int, unsigned> nesting_level;

    void add_blocking_clause(const Range &range, const Int &id, Bools::Expr loop) override;
    std::optional<Range> has_looping_infix();
    void handle_loop(const Range&);

public:

    ~ADCLSat() override = default;
    explicit ADCLSat(const ITSPtr& its, const Config::TRPConfig &config);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;

};
