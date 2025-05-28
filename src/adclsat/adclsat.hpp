#pragma once

#include "trputil.hpp"

class ADCLSat: public TRPUtil {

private:

    bool backtracking {false};
    DependencyGraph<Bools::Expr> dg_over_approx;

    void add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) override;
    std::optional<unsigned> has_looping_suffix();
    bool handle_loop(const unsigned start);

public:

    explicit ADCLSat(const ITSPtr its, const Config::TRPConfig &config);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;

};
