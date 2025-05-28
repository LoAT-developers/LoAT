#pragma once

#include <limits>
#include <boost/bimap.hpp>
#include <boost/bimap/set_of.hpp>

#include "safetyproblem.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "dependencygraph.hpp"
#include "linkedhashmap.hpp"
#include "config.hpp"
#include "chctoitsproblem.hpp"
#include "itstosafetyproblem.hpp"
#include "itssafetycex.hpp"
#include "trp.hpp"
#include "trputil.hpp"

#include <map>

class TRL: public TRPUtil {

private:

    Bools::Expr step {bot()};
    // step -> ID of corresponding transition formula -> blocked transition
    std::unordered_map<Int, std::map<Int, Bools::Expr>> blocked_per_step {};
    unsigned depth {0};

    void add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) override;
    void add_blocking_clauses();
    std::optional<Range> has_looping_infix();

    bool handle_loop(const Range &range);
    void build_trace();
    void pop();

public:

    explicit TRL(const ITSPtr its, const Config::TRPConfig &config);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;

};
