#pragma once

#include "trputil.hpp"

class ADCLSat final: public TRPUtil {

    bool backtracking {false};
    DependencyGraph<Bools::Expr> dg_over_approx;

    void add_blocking_clause(const Range &range, const Int &id, Bools::Expr loop) override;
    std::optional<unsigned> has_looping_suffix();
    void handle_loop(unsigned start);

public:

    ~ADCLSat() override = default;
    explicit ADCLSat(const ITSPtr& its, const Config::TRPConfig &config);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;

};
