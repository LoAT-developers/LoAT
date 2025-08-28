#pragma once

#include "stepwise.hpp"
#include "itsproblem.hpp"
#include "itstosafetyproblem.hpp"
#include "opensmt.hpp"
#include "trputil.hpp"

class IMC: public TRPUtil {

private:

    unsigned depth {0};
    Bools::Expr step {bot()};
    Bools::Expr itp {bot()};
    OpenSmt solver {true};
    std::unordered_map<Int, std::map<Int, Bools::Expr>> blocked_per_step {};
    unsigned assertions {0};

public:

    IMC(const ITSPtr, const Config::TRPConfig&);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;
    ITSSafetyCex get_cex() override;

protected:

    void add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) override;

private:

    void add(const Bools::Expr);
    void build_trace();
    std::optional<Range> has_looping_infix();
    bool handle_loop(const Range&);
    void add_blocking_clauses();

};