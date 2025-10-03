#pragma once

#include "smt.hpp"
#include "config.hpp"
#include "chctoitsproblem.hpp"
#include "itstosafetyproblem.hpp"
#include "trputil.hpp"

#include <map>

class TRL final : public TRPUtil {

    Bools::Expr step {bot()};
    // step -> ID of corresponding transition formula -> blocked transition
    std::unordered_map<Int, std::map<Int, Bools::Expr>> blocked_per_step {};
    unsigned depth {0};

    void add_blocking_clause(const Range &range, const Int &id, Bools::Expr loop) override;
    void add_blocking_clauses();
    std::optional<Range> has_looping_infix();

    bool handle_loop(const Range &range);
    void build_trace();
    void pop();

public:
    ~TRL() override = default;
    explicit TRL(const ITSPtr& its, const Config::TRPConfig &config);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;

};
