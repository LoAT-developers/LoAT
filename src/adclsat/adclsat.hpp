#pragma once

#include "trputil.hpp"

class ADCLSat: public TRPUtil {

private:

    bool backtracking {false};
    DependencyGraph<Bools::Expr> dg_over_approx;
    Renaming pre_to_post;
    Renaming post_to_pre;
    Bools::Expr step {top()};
    Bools::Expr unreached {top()};

    bool handle_loop(const Range range);

public:

    explicit ADCLSat(const ITSPtr its, const Config::TRPConfig &config);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;

};
