#pragma once

#include "itsproblem.hpp"
#include "itsmodel.hpp"
#include "itssafetycex.hpp"
#include "itstosafetyproblem.hpp"
#include "stepwise.hpp"

class BMC: public StepwiseAnalysis {

    enum class Winner {
        BMC, BKIND, KIND
    };

    ITSToSafety m_to_safety;
    SafetyProblem sp;
    Bools::Expr m_init;
    Bools::Expr m_step;
    Bools::Expr m_err;
    SmtPtr m_solver;
    SmtPtr m_kind;
    SmtPtr m_bkind;
    bool m_approx {false};
    VarSet m_vars;
    Renaming m_pre_to_post {};
    unsigned m_depth {0};
    std::vector<Renaming> m_renamings;
    bool m_do_kind;
    Winner m_winner {Winner::BMC};
    Renaming m_last_s;

public:
    explicit BMC(const ITSPtr& p_its, bool p_do_kind = true);
    void init() override;
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;
    ITSSafetyCex get_cex() override;

};
