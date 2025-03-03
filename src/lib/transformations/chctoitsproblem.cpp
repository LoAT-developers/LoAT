#include "chctoitsproblem.hpp"
#include "config.hpp"
#include "itsproblem.hpp"
#include "chcproblem.hpp"
#include "itsmodel.hpp"
#include "chcmodel.hpp"
#include "itssafetycex.hpp"
#include "chccex.hpp"

CHCToITS::CHCToITS(CHCPtr chcs): chcs(chcs) {}

CHCModel CHCToITS::transform_model(const ITSModel& its_m) const {
    CHCModel chc_m;
    const auto signature {chcs->get_signature()};
    for (const auto loc : its->getLocations()) {
        if (its->getInitialLocation() == loc || its->getSink() == loc) {
            continue;
        }
        const auto inv{its_m.get_invariant(loc)};
        const auto pred{its->getPrintableLocationName(loc)};
        const auto sig{signature.at(pred)};
        std::unordered_map<ArrayType, unsigned> next_by_type;
        std::vector<Var> args;
        for (const auto &x : sig) {
            auto vec {vars.at(x)};
            auto &next {next_by_type.emplace(x, 0).first->second};
            args.emplace_back(vec.at(next));
            ++next;
        }
        chc_m.set_interpretation(pred, args, inv);
    }
    return chc_m;
}

ClausePtr CHCToITS::rule_to_clause(const RulePtr rule, const ClausePtr prototype) const {
    std::optional<FunAppPtr> premise;
    std::optional<FunAppPtr> conclusion;
    if (const auto prem {prototype->get_premise()}) {
        std::vector<Expr> args;
        std::unordered_map<ArrayType, unsigned> next_by_type;
        for (const auto &x: (*prem)->get_args()) {
            const auto type {theory::to_type(x)};
            auto vec {vars.at(type)};
            auto &next {next_by_type.emplace(type, 0).first->second};
            args.emplace_back(theory::toExpr(vec.at(next)));
            ++next;
        }
        premise = FunApp::mk((*prem)->get_pred(), args);
    }
    if (const auto conc {prototype->get_conclusion()}) {
        std::vector<Expr> args;
        std::unordered_map<ArrayType, unsigned> next_by_type;
        const auto &up {rule->getUpdate()};
        for (const auto &x: (*conc)->get_args()) {
            const auto type {theory::to_type(x)};
            auto vec {vars.at(type)};
            auto &next {next_by_type.emplace(type, 0).first->second};
            args.emplace_back(up.get(vec.at(next)));
            ++next;
        }
        conclusion = FunApp::mk((*conc)->get_pred(), args);
    }
    return Clause::mk(premise, rule->getGuard(), conclusion);
}

CHCCex CHCToITS::transform_cex(const ITSSafetyCex &cex) {
    CHCCex res {chcs};
    for (const auto &[rule, kind]: cex.get_used_rules()) {
        switch (kind) {
            case ProofStepKind::IMPLICANT: {
                const auto orig {cex.get_implicants().at(rule)};
                const auto it{clause_map.find(orig)};
                assert(it != clause_map.end());
                const auto orig_clause{it->second};
                const auto imp_clause{rule_to_clause(rule, orig_clause)};
                clause_map.emplace(rule, imp_clause);
                res.add_implicant(orig_clause, imp_clause);
                break;
            }
            case ProofStepKind::ACCEL: {
                const auto orig {cex.get_accel().at(rule)};
                const auto it{clause_map.find(orig)};
                assert(it != clause_map.end());
                const auto orig_clause{it->second};
                const auto accel_clause{rule_to_clause(rule, orig_clause)};
                clause_map.emplace(rule, accel_clause);
                res.add_accel(orig_clause, accel_clause);
                break;
            }
            case ProofStepKind::RESOLVENT: {
                const auto origs {cex.get_resolvents().at(rule)};
                std::vector<ClausePtr> orig_clauses;
                for (const auto &o: origs) {
                    orig_clauses.emplace_back(clause_map.at(o));
                }
                const auto prototype {Clause::mk(orig_clauses.front()->get_premise(), top(), orig_clauses.back()->get_conclusion())};
                const auto resolvent{rule_to_clause(rule, prototype)};
                clause_map.emplace(rule, resolvent);
                res.add_resolvent(orig_clauses, resolvent);
                break;
            }
            case ProofStepKind::ORIG: {
                break;
            }
            case ProofStepKind::RECURRENT_SET: {
                throw std::logic_error("recurrent sets are not supported for CHCs");
            }
        }
    }
    for (size_t i = 0; i < cex.num_transitions(); ++i) {
        const auto trans {cex.get_transition(i)};
        auto state {cex.get_state(i)};
        if (const auto it {renamings.find(trans)}; it != renamings.end()) {
            state = state.composeBackwards(it->second);
        }
        const auto clause {clause_map.at(trans)};
        if (!res.try_step(state, clause)) {
            throw std::logic_error("transform_cex failed");
        }
    }
    return res;
}

ITSPtr CHCToITS::transform() {
    const auto max_arity {chcs->max_arity()};
    for (const auto &[array_type, arity]: max_arity) {
        auto &vec {vars.emplace(array_type, std::vector<Var>{}).first->second};
        const auto t {array_type.get_type()};
        const auto d {array_type.get_dimension()};
        for (unsigned i = 0; i < arity; ++i) {
            switch (t) {
                case theory::Type::Int:
                    vec.emplace_back(ArithVar::nextProgVar(d));
                    break;
                case theory::Type::Bool:
                    vec.emplace_back(BoolVar::nextProgVar(d));
                    break;
            }
        }
    }
    for (const auto &c: chcs->get_clauses()) {
        Renaming renaming;
        std::vector<Bools::Expr> constraints{c->get_constraint()};
        const auto lhs_loc = c->get_premise() ? its->getOrAddLocation((*c->get_premise())->get_pred()) : its->getInitialLocation();
        constraints.emplace_back(theory::mkEq(its->getLocVar(), arith::mkConst(lhs_loc)));
        // replace the arguments of the body predicate with the corresponding program variables
        std::unordered_map<ArrayType, unsigned> next_by_type;
        if (const auto prem{c->get_premise()}) {
            for (const auto &ex : (*prem)->get_args()) {
                const auto type {theory::to_type(ex)};
                const auto &vec {vars.at(type)};
                auto &next {next_by_type.emplace(type, 0).first->second};
                if (const auto var{theory::is_var(ex)}; var && !renaming.contains(*var)) {
                    renaming.insert(*var, vec[next]);
                } else {
                    constraints.emplace_back(theory::mkEq(ex, theory::toExpr(vec[next])));
                }
                ++next;
            }
        }
        next_by_type.clear();
        Subs up;
        if (const auto conc{c->get_conclusion()}) {
            for (const auto &arg : (*conc)->get_args()) {
                const auto type {theory::to_type(arg)};
                const auto &vec {vars.at(type)};
                auto &next {next_by_type.emplace(type, 0).first->second};
                up.put(vec[next], arg);
                ++next;
            }
            for (const auto &[array_type, arity] : max_arity) {
                const auto &vec{vars.at(array_type)};
                auto next{next_by_type.emplace(array_type, 0).first->second};
                const auto d{array_type.get_dimension()};
                const auto t{array_type.get_type()};
                for (; next < arity; ++next) {
                    switch (t) {
                        case theory::Type::Int:
                            up.put(vec[next], ArithVar::next(d));
                            break;
                        case theory::Type::Bool:
                            up.put(vec[next], Bools::varToExpr(BoolVar::next(d)));
                            break;
                    }
                }
            }
        }
        const auto rhs_loc = c->get_conclusion() ? its->getOrAddLocation((*c->get_conclusion())->get_pred()) : its->getSink();
        up.put<Arith>(its->getLocVar(), arith::mkConst(rhs_loc));
        const auto rule{Rule::mk(bools::mkAnd(constraints), up)->renameVars(renaming)};
        if (Config::Analysis::model) {
            clause_map.emplace(rule, c);
            renamings.emplace(rule, renaming);
        }
        its->addRule(rule, lhs_loc);
    }
    return its;
}
