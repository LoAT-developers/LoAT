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
    std::unordered_map<Int, std::map<Int, Bools::Expr>> blocked_per_step {};
    std::vector<Subs> forgotten;
    bool aimc;

public:

    IMC(const ITSPtr, const bool aimc, const Config::TRPConfig&);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;
    ITSSafetyCex get_cex() override;

protected:

    void add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) override;

private:

    void build_trace(unsigned depth);
    bool has_looping_infix(unsigned start, unsigned length);
    bool handle_loop(const Range&);
    void add_blocking_clauses();
    void forget(const Subs subs, const Int id);
    std::pair<Bools::Expr, Model> get_implicant(const Model model, const unsigned depth);

};