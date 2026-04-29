#pragma once

#include "trputil.hpp"

class ADCLSat final: public TRPUtil {

    bool backtracking {false};
    DependencyGraph<Int> dg_over_approx;

    void handle_loop(const Range&);

public:

    ~ADCLSat() override = default;
    explicit ADCLSat(const ITSPtr& its, const Config::TRPConfig &config);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;

};
