#pragma once

#include "itscex.hpp"
#include "model.hpp"
#include "itsrecurrentset.hpp"

class ITSSafetyCex: public ITSCex {

friend std::ostream& operator<<(std::ostream &s, const ITSSafetyCex &);

    ITSPtr m_its;
    std::vector<RulePtr> m_transitions;
    std::vector<ModelPtr> m_states;

public:

    explicit ITSSafetyCex(ITSPtr);

    size_t num_transitions() const;
    RulePtr get_transition(size_t) const;
    void do_step(const RulePtr&, const ModelPtr&);
    void set_initial_state(const ModelPtr&);
    size_t num_states() const;
    ModelPtr get_state(size_t) const;
    std::vector<std::pair<RulePtr, ProofStepKind>> get_used_rules() const;
    void complete_recurrent_set(ITSRecurrentSet&, RulePtr, ModelPtr, bool with_start) const;
    ITSRecurrentSet to_recurrent_set() const;

private:
    Bools::Expr instantiate_pre(ModelPtr) const;
    Bools::Expr instantiate_post(RulePtr, ModelPtr) const;
    Bools::Expr instantiate_tmp(Bools::Expr, ModelPtr, const CellSet& keep = CellSet()) const;

};
