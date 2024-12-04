#pragma once

#include "trputil.hpp"

class ADCLSat: public TRPUtil {

private:

    bool backtracking {false};

    void add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) override;
    std::optional<unsigned> has_looping_suffix();
    bool handle_loop(const unsigned start);

public:

    explicit ADCLSat(const ITSPtr its, const Config::TRPConfig &config);
    std::optional<SmtResult> do_step() override;

};
