#pragma once

#include "smt.hpp"
#include "config.hpp"
#include "chctoitsproblem.hpp"
#include "itstosafetyproblem.hpp"
#include "trputil.hpp"

#include <map>

class TRL final : public TRPUtil {

    Bools::Expr step {bot()};
    unsigned depth {0};

    bool handle_loop(const Range &range);
    void build_trace();
    void pop();
    void build_step();

public:
    ~TRL() override = default;
    explicit TRL(const ITSPtr& its, const Config::TRPConfig &config);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;

};
