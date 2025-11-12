#include "adcl.hpp"
#include "rulepreprocessing.hpp"
#include "loopacceleration.hpp"
#include "smt.hpp"
#include "vector.hpp"
#include "limitsmt.hpp"
#include "vareliminator.hpp"
#include "theory.hpp"
#include "config.hpp"
#include "variant.hpp"

#include <random>
#include <unordered_set>
#include <utility>

namespace adcl {

using ::operator<<;

std::optional<Succeeded> LearningState::succeeded() {
    return {};
}

std::optional<Covered> LearningState::covered() {
    return {};
}

std::optional<Dropped> LearningState::dropped() {
    return {};
}

std::optional<Dropped> Dropped::dropped() {
    return *this;
}

std::optional<Unroll> LearningState::unroll() {
    return {};
}

std::optional<Restart> LearningState::restart() {
    return {};
}

std::optional<ProvedUnsat> LearningState::unsat() {
    return {};
}

Succeeded::Succeeded(LearnedClauses learned): learned(std::move(learned)) {}

std::optional<Succeeded> Succeeded::succeeded() {
    return *this;
}

const LearnedClauses& Succeeded::operator*() const {
    return learned;
}

const LearnedClauses* Succeeded::operator->() const {
    return &learned;
}

std::optional<Covered> Covered::covered() {
    return *this;
}

std::optional<Restart> Restart::restart() {
    return *this;
}

Unroll::Unroll(unsigned max, const bool accel_failed): max(max), accel_failed(accel_failed) {}

std::optional<unsigned> Unroll::get_max() const {
    return max;
}

std::optional<Unroll> Unroll::unroll() {
    return *this;
}

bool Unroll::acceleration_failed() const {
    return accel_failed;
}

std::optional<ProvedUnsat> ProvedUnsat::unsat() {
    return *this;
}

ADCL::ADCL(const ITSPtr& chcs, const std::function<void(const ITSCpxCex&)> &print_cpx_cex):
    chcs(chcs),
    drop(true),
    cex(chcs),
    cpx_cex(chcs),
    print_cpx_cex(print_cpx_cex) {
    solver->enableModels();
}

Step::Step(RulePtr transition, Bools::Expr sat, Renaming var_renaming,
           Renaming tmp_var_renaming, RulePtr resolvent) :
    clause_idx(std::move(transition)),
    implicant(std::move(sat)),
    var_renaming(std::move(var_renaming)),
    tmp_var_renaming(std::move(tmp_var_renaming)),
    resolvent(std::move(resolvent)) {}

std::ostream& operator<<(std::ostream &s, const Step &step) {
    return s << step.clause_idx << "[" << step.implicant << "]";
}

std::optional<unsigned> ADCL::has_looping_suffix(const int start) const {
    if (trace.empty()) {
        return {};
    }
    const auto last_clause = trace.back().clause_idx;
    std::vector<long> sequence;
    for (int pos = start; pos >= 0; --pos) {
        if (const Step &step = trace[pos]; chcs->areAdjacent(last_clause, step.clause_idx)) {
            if (auto upos = static_cast<unsigned>(pos); upos < trace.size() - 1 || is_orig_clause(step.clause_idx)) {
                return upos;
            }
        }
    }
    return {};
}

std::pair<Renaming, Renaming> ADCL::handle_update(const RulePtr& idx) {
    const auto &last_var_renaming = trace.empty() ? Renaming::Empty : trace.back().var_renaming;
    const auto &last_tmp_var_renaming = trace.empty() ? Renaming::Empty : trace.back().tmp_var_renaming;
    Renaming new_var_renaming;
    Renaming new_tmp_var_renaming;
    if (chcs->isSinkTransition(idx)) {
        // no need to compute a new variable renaming if we just applied a query
        return {new_var_renaming, new_tmp_var_renaming};
    }
    const auto up {idx->getUpdate()};
    for (const auto &x: prog_vars) {
        theory::apply(x, [&](const auto &x) {
            const auto th {theory::theory(x)};
            new_var_renaming.insert(x, th.next(x->dim()));
        });
    }
    for (const auto &var: idx->vars()) {
        if (theory::isTempVar(var)) {
            theory::apply(var, [&](const auto &x) {
                const auto th {theory::theory(x)};
                const auto next {th.next(x->dim())};
                new_var_renaming.insert(x, next);
                new_tmp_var_renaming.insert(x, next);
            });
        }
    }
    for (const auto &[var,_]: last_tmp_var_renaming) {
        if (!new_tmp_var_renaming.contains(var)) {
            theory::apply(var, [&](const auto &x) {
                const auto th {theory::theory(x)};
                const auto next {th.next(x->dim())};
                new_var_renaming.insert(x, next);
                new_tmp_var_renaming.insert(x, next);
            });
        }
    }
    for (const auto &x: prog_vars) {
        theory::apply(
            x,
            [&](const auto& x) {
                solver->add(theory::mkEq(theory::toExpr(new_var_renaming.get(x)), last_var_renaming(up.get(x))));
            });
    }
    return {new_var_renaming, new_tmp_var_renaming};
}

void ADCL::block(const Step &step) {
    if (Config::Analysis::log) std::cout << "blocking " << step.clause_idx << ", " << step.implicant << std::endl;
    if (step.clause_idx->getGuard()->isConjunction()) {
        blocked_clauses.back()[step.clause_idx] = {};
    } else {
        if (const auto block = blocked_clauses.back().find(step.clause_idx); block == blocked_clauses.back().end()) {
            blocked_clauses.back()[step.clause_idx] = {step.implicant};
        } else {
            block->second.insert(step.implicant);
        }
    }
}

void ADCL::pop() {
    bump_penalty(trace.back().clause_idx);
    blocked_clauses.pop_back();
    trace.pop_back();
    solver->pop();
}

void ADCL::backtrack() {
    if (Config::Analysis::log) std::cout << "backtracking" << std::endl;
    // copy the last step before popping it
    const Step step = trace.back();
    pop();
    block(step);
}

void ADCL::add_to_trace(const Step &step) {
    trace.emplace_back(step);
    blocked_clauses.emplace_back();
}

void ADCL::set_cpx_witness(const RulePtr& witness, const ModelPtr &subs, const ArithVarPtr &param) {
    if (trace.size() > 1) {
        std::vector<RulePtr> rules;
        for (const auto &t: trace) {
            rules.emplace_back(t.clause_idx->withGuard(t.implicant));
        }
        cpx_cex.add_resolvent(rules, witness);
    } else {
        if (const auto &t {trace.back()}; t.implicant != t.clause_idx->getGuard()) {
            cpx_cex.add_implicant(t.clause_idx, t.clause_idx->withGuard(t.implicant));
        }
    }
    cpx_cex.set_witness(witness, subs, param);
    std::cout << std::endl;
    print_cpx_cex(cpx_cex);
    std::cout << std::endl;
}

void ADCL::update_cpx() {
    if (!Config::Analysis::complexity()) {
        return;
    }
    const auto resolvent = trace.back().resolvent;
    const auto &cost = chcs->getCost(resolvent);
    if (toComplexity(cost) <= cpx && !cost->hasVarWith([](const auto &x){return x->isTempVar();})) {
        return;
    }
    if (const auto [cpx, subs, param] {LimitSmtEncoding::applyEncoding(resolvent->getGuard(), cost, this->cpx)}; cpx > this->cpx) {
        this->cpx = cpx;
        std::cout << this->cpx.toWstString() << std::endl;
        if (Config::Analysis::model) {
            set_cpx_witness(resolvent, *subs, param);
        }
        if (Config::Analysis::log) {
            std::cout << this->cpx.toString() << std::endl;
        }
    }
}

RulePtr ADCL::compute_resolvent(const RulePtr& idx, const Bools::Expr& implicant) const {
    static auto dummy {Rule::mk(top(), Subs())};
    if (!Config::Analysis::complexity()) {
        return dummy;
    }
    const auto tmp_var_renaming = trace.empty() ? Renaming() : trace.back().tmp_var_renaming;
    auto resolvent = idx->withGuard(implicant)->renameVars(tmp_var_renaming);
    if (!trace.empty()) {
        resolvent = Preprocess::chain({trace.back().resolvent, resolvent});
    }
    return Preprocess::preprocessRule(resolvent);
}

bool ADCL::store_step(const RulePtr& idx, const RulePtr& implicant) {
    solver->push();
    const auto imp {trace.empty() ? implicant : implicant->renameVars(trace.back().var_renaming)};
    solver->add(imp->getGuard());
    if (solver->check() == SmtResult::Sat) {
        const auto [new_var_renaming, new_tmp_var_renaming] {handle_update(idx)};
        const Step step(idx, implicant->getGuard(), new_var_renaming, new_tmp_var_renaming, compute_resolvent(idx, implicant->getGuard()));
        add_to_trace(step);
        // block learned clauses after adding them to the trace
        if (is_learned_clause(idx)) {
            block(step);
        }
        return true;
    }
    solver->pop();
    return false;
}

void ADCL::print_trace(std::ostream &s) const {
    const auto model {solver->model()};
    s << model->toString(prog_vars) << std::endl;
    for (const auto &step: trace) {
        s << " -" << step.clause_idx << "-> ";
        if (!chcs->isSinkTransition(step.clause_idx)) {
            s << model->composeBackwards(step.var_renaming)->toString(prog_vars);
        }
        s << std::endl;
    }
    s << std::endl;
}

void ADCL::print_state() const {
    if (Config::Analysis::log) {
        std::cout << "trace";
        for (const auto &x: trace) {
            std::cout << "\n\t" << x;
        }
        std::cout << "\n";
        std::cout << "blocked";
        for (const auto &e: blocked_clauses) {
            std::cout << "\n\t{";
            bool first_trans = true;
            for (const auto &[idx,blocked]: e) {
                if (first_trans) {
                    first_trans = false;
                } else {
                    std::cout << ", ";
                }
                std::cout << idx << "[" << bools::mkAnd(blocked) << "]";
            }
            std::cout << "}";
        }
        std::cout << std::endl;
    }
}

void ADCL::init() {
    srand(42);
    for (const auto &x: chcs->getVars()) {
        if (!theory::isTempVar(x)) {
            prog_vars.insert(x);
        }
    }
    for (const auto &r: chcs->getAllTransitions()) {
        last_orig_clause = std::max(last_orig_clause, r->getId());
    }
}

void ADCL::luby_next() {
    for (const auto &x: chcs->getAllTransitions()) {
        if (is_learned_clause(x) && !x->isPoly()) {
            locked.insert(*redundancy->get_language(x));
        }
    }
    const auto [u,v] {luby};
    luby = (u & -u) == v ? std::pair<unsigned, unsigned>(u+1, 1) : std::pair<unsigned, unsigned>(u, 2 * v);
    solver->resetSolver();
    solver->randomize(rand());
    luby_count = 0;
}

void ADCL::unsat() const {
    if (Config::Analysis::complexity()) {
        std::cout << "NO" << std::endl;
    }
    if (Config::Analysis::log) {
        std::stringstream counterexample;
        print_trace(counterexample);
        std::stringstream trace_stream;
        trace_stream << trace;
        std::cout << "final ITS:\n" << chcs << std::endl;
        std::cout << std::endl << "final trace:" << trace_stream.str() << std::endl << std::endl;
        std::cout << "counterexample: " << counterexample.str();
    }
}

std::optional<RulePtr> ADCL::resolve(const RulePtr& idx) {
    const auto &var_renaming = trace.empty() ? Renaming::Empty : trace.back().var_renaming;
    const auto block = blocked_clauses.back().find(idx);
    if (block != blocked_clauses.back().end()) {
        // empty means all variants are blocked --> fail
        if (block->second.empty()) {
            return {};
        }
        // a non-conjunctive clause where some variants are blocked
        // --> make sure that we use a non-blocked variant, if any
        for (const auto &b: block->second) {
            solver->add(!b->renameVars(var_renaming));
        }
    }
    const auto vars {idx->getGuard()->vars()};
    const auto projected_var_renaming {var_renaming.project(vars)};
    const auto guard {idx->getGuard()->renameVars(projected_var_renaming)};
    solver->add(guard);
    switch (solver->check()) {
    case SmtResult::Sat: {
        if (Config::Analysis::log) std::cout << "found model for " << idx << std::endl;
        const auto model {solver->model()->composeBackwards(projected_var_renaming)};
        const auto implicant {model->syntacticImplicant(idx->getGuard())};
        return {idx->withGuard(implicant)};
    }
    case SmtResult::Unknown: {}
    [[fallthrough]];
    case SmtResult::Unsat: {
        if (block == blocked_clauses.back().end()) {
            blocked_clauses.back()[idx] = {};
        } else {
            block->second.clear();
        }
        if (Config::Analysis::log) std::cout << "could not find a model for " << idx << std::endl;
    }
    }
    return {};
}

Automaton ADCL::get_language(const Step &step) const {
    if (is_orig_clause(step.clause_idx)) {
        return redundancy->get_singleton_language(step.clause_idx, step.implicant);
    }
    return *redundancy->get_language(step.clause_idx);
}

Automaton ADCL::build_language(const int backlink) const {
    auto lang = get_language(trace[backlink]);
    for (size_t i = backlink + 1; i < trace.size(); ++i) {
        redundancy->concat(lang, get_language(trace[i]));
    }
    return lang;
}

std::pair<RulePtr, ModelPtr> ADCL::build_loop(const int backlink) const {
    std::vector<RulePtr> rules;
    for (size_t i = backlink; i < trace.size(); ++i) {
        rules.emplace_back(trace[i].clause_idx->withGuard(trace[i].implicant)->renameVars(trace[i].tmp_var_renaming));
    }
    const auto loop {Preprocess::chain(rules)};
    const auto s {trace[backlink].var_renaming};
    auto vars {loop->vars()};
    s.collectCoDomainVars(vars);
    auto model {solver->model()->composeBackwards(s)};
    if (Config::Analysis::log) {
        std::cout << "found loop of length " << (trace.size() - backlink) << ":\n" << loop << std::endl;
    }
    return {loop, model};
}

void ADCL::add_learned_clause(const RulePtr& accel, const unsigned backlink) const {
    const auto fst = trace.at(backlink).clause_idx;
    const auto last = trace.back().clause_idx;
    chcs->addLearnedRule(accel, fst, last);
}

bool ADCL::is_learned_clause(const RulePtr& idx) const {
    return idx->getId() > last_orig_clause;
}

bool ADCL::is_orig_clause(const RulePtr& idx) const {
    return idx->getId() <= last_orig_clause;
}

std::optional<RulePtr> ADCL::instantiate(const ArithVarPtr& n, const RulePtr& rule) {
    std::optional<RulePtr> res{};
    for (const auto &s : VarEliminator(rule->getGuard(), n, [](const auto &x) {return x->isProgVar();}).getRes()) {
        if (n->subs(s)->isRational()) continue;
        if (res) {
            return {};
        }
        res = rule->subs(s);
    }
    return res;
}

ITSCex* ADCL::the_cex() {
    if (Config::Analysis::mode == Config::Analysis::Complexity) {
        return &cpx_cex;
    }
    return &cex;
}

std::unique_ptr<LearningState> ADCL::learn_clause(const RulePtr& rule, const unsigned backlink) {
    const auto simp {Preprocess::preprocessRule(rule)};
    if (Config::Analysis::safety() && simp->getUpdate().isIdempotent()) {
        // The learned clause would be trivially redundant w.r.t. the looping suffix (but not necessarily w.r.t. a single clause).
        // Such clauses are pretty useless, so we do not store them.
        if (Config::Analysis::log) std::cout << "acceleration would yield equivalent rule" << std::endl;
        return std::make_unique<Unroll>(1);
    }
    if (Config::Analysis::log && simp->getId() != rule->getId()) {
        std::cout << "simplified loop:\n" << simp << std::endl;
    }
    if (Config::Analysis::safety()) {
        if (simp->getUpdate().empty()) {
            if (Config::Analysis::log) std::cout << "trivial looping suffix" << std::endl;
            return std::make_unique<Covered>();
        }
    }
    const auto n {arrays::nextConst<Arith>()};
    const AccelConfig config {
        Config::Analysis::tryNonterm(),
        true,
        Config::Accel::non_linear,
        n,
        chcs->getCost(simp)};
    const auto [status, accel, nonterm, prefix, period] {LoopAcceleration::accelerate(simp, config)};
    if (status == acceleration::PseudoLoop) {
        return std::make_unique<Unroll>();
    }
    LearnedClauses res{.res = {}, .prefix = prefix, .period = period};
    if (Config::Analysis::tryNonterm() && nonterm != bot()) {
        const auto query {chcs->addQuery(nonterm, trace.at(backlink).clause_idx)};
        res.res.emplace_back(query);
        if (Config::Analysis::model) {
            the_cex()->add_recurrent_set(rule, query);
        }
        if (Config::Analysis::log) {
            std::cout << "found certificate of non-termination: " << query << std::endl;
        }
    }
    if (accel) {
        // acceleration succeeded, simplify the result
        if (auto simplified {Preprocess::preprocessRule(accel->rule)}; simplified->getUpdate() != simp->getUpdate()) {
            // accelerated rule differs from the original one, update the result
            if (Config::Analysis::complexity()) {
                if (const auto inst {instantiate(n, simplified)}) {
                    simplified = *inst;
                }
            }
            add_learned_clause(simplified, backlink);
            res.res.emplace_back(simplified);
            if (Config::Analysis::model) {
                the_cex()->add_accel(rule, simplified);
            }
            if (Config::Analysis::log) {
                std::cout << "accelerated rule: " << *simplified << std::endl;
            }
        }
    }
    if (res.res.empty()) {
        if (Config::Analysis::log) {
            std::cout << "acceleration failed, status: " << status << std::endl;
        }
        return std::make_unique<Unroll>(1, true);
    }
    if (Config::Analysis::model) {
        std::vector<RulePtr> rules;
        for (unsigned i = backlink; i < trace.size(); ++i) {
            if (const auto e{trace.at(i)}; is_orig_clause(e.clause_idx) && e.implicant != e.clause_idx->getGuard()) {
                const auto imp{e.clause_idx->withGuard(e.implicant)->renameVars(e.tmp_var_renaming)};
                the_cex()->add_implicant(e.clause_idx, imp);
                rules.emplace_back(imp);
            } else {
                rules.emplace_back(e.clause_idx);
            }
        }
        if (rules.size() > 1) {
            the_cex()->add_resolvent(rules, rule);
        }
    }
    return std::make_unique<Succeeded>(res);
}

bool ADCL::check_consistency() const {
    // make sure that a model is available
    bool res {true};
    switch (solver->check()) {
    case SmtResult::Unsat:
        throw std::logic_error("trace is contradictory");
    case SmtResult::Unknown:
        std::cerr << "consistency of trace cannot be proven" << std::endl;
        res = false;
        break;
    case SmtResult::Sat:
        break;
    }
    return res;
}

void ADCL::drop_until(const int new_size) {
    while (trace.size() > static_cast<unsigned>(new_size)) {
        pop();
    }
}

std::unique_ptr<LearningState> ADCL::handle_loop(const unsigned backlink) {
    const auto lang {build_language(backlink)};
    auto closure {lang};
    redundancy->transitive_closure(closure);
    locked.erase(closure);
    if (redundancy->is_redundant(closure)) {
        if (Config::Analysis::log) std::cout << "loop already covered" << std::endl;
        return std::make_unique<Covered>();
    }
    if (redundancy->is_accelerated(lang)) {
        if (Config::Analysis::log) std::cout << "loop must be unrolled" << std::endl;
        return std::make_unique<Unroll>();
    }
    if (!check_consistency()) {
        return std::make_unique<Restart>();
    }
    if (Config::Analysis::log) {
        std::cout << "learning clause for the following language:" << std::endl;
        std::cout << closure << std::endl;
    }
    const auto [loop, model] {build_loop(backlink)};
    auto state {learn_clause(loop, backlink)};
    redundancy->mark_as_accelerated(closure);
    if (!state->succeeded()) {
        if (state->unroll()) {
            if (state->unroll()->get_max()) {
                const auto max {*state->unroll()->get_max()};
                auto redundant_lang {lang};
                for (unsigned i = 1; i < max; ++i) {
                    redundancy->concat(redundant_lang, lang);
                }
                redundancy->concat(redundant_lang, closure);
                redundancy->mark_as_redundant(redundant_lang);
            }
        } else {
            redundancy->mark_as_redundant(closure);
        }
        return state;
    }
    const auto accel_state {*state->succeeded()};
    const auto& [res, prefix, period] {*accel_state};
    const bool do_drop {drop || (backlink == trace.size() - 1  && prefix <= 1 && period == 1)};
    if (do_drop) {
        drop_until(backlink);
    }
    bool done {!do_drop};
    if (Config::Analysis::log) {
        std::cout << "prefix: " << prefix << ", period: " << period << std::endl;
    }
    for (const auto &idx: res) {
        redundancy->set_language(idx, closure);
        if (!done && store_step(idx, idx)) {
            if (chcs->isSinkTransition(idx)) {
                if (Config::Analysis::complexity() && Config::Analysis::model) {
                    set_cpx_witness(trace.back().resolvent, solver->model(), arrays::nextConst<Arith>());
                }
                return std::make_unique<ProvedUnsat>();
            }
            update_cpx();
            done = true;
        }
    }
    if (done) {
        redundancy->mark_as_redundant(closure);
        return state;
    }
    // unroll once if we dropped the loop
    redundancy->concat(closure, closure);
    redundancy->mark_as_redundant(closure);
    if (Config::Analysis::log) std::cout << "applying accelerated rule failed" << std::endl;
    return std::make_unique<Dropped>();
}

bool ADCL::try_to_finish() {
    for (const auto clauses =
             trace.empty()
                 ? chcs->getInitialTransitions()
                 : chcs->getSuccessors(trace.back().clause_idx);
         const auto& q : clauses) {
        if (chcs->isSinkTransition(q)) {
            solver->push();
            if (const auto implicant {resolve(q)}) {
                if (Config::Analysis::complexity() && Config::Analysis::model) {
                    const auto resolvent {compute_resolvent(q, (*implicant)->getGuard())};
                    set_cpx_witness(resolvent, solver->model(), arrays::nextConst<Arith>());
                }
                add_to_trace(Step(q, (*implicant)->getGuard(), Renaming(), Renaming(), Rule::mk(top(), Subs())));
                print_state();
                unsat();
                return true;
            }
            solver->pop();
        }
    }
    return false;
}

ITSSafetyCex ADCL::get_cex() {
    const auto model {solver->model()};
    cex.set_initial_state(model);
    for (size_t i = 0; i + 1 < trace.size(); ++i) {
        const auto &t {trace.at(i)};
        cex.do_step(t.clause_idx->withGuard(t.implicant), model->composeBackwards(t.var_renaming));
    }
    const auto &last {trace.back()};
    cex.add_final_transition(last.clause_idx->withGuard(last.implicant));
    return cex;
}

unsigned ADCL::get_penalty(const RulePtr& idx) const {
    if (const auto it {penalty.find(idx)}; it != penalty.end()) {
        return it->second;
    }
    return 0;
}

void ADCL::bump_penalty(const RulePtr& idx) {
    penalty.emplace(idx, 0).first->second++;
}

SmtResult ADCL::analyze() {
    init();
    if (try_to_finish()) {
        return SmtResult::Unsat;
    }
    blocked_clauses[0].clear();
    do {
        ++luby_count;
        const size_t next_restart = luby_unit * luby.second;
        std::unique_ptr<LearningState> state;
        if (!trace.empty()) {
            for (auto backlink = has_looping_suffix(trace.size() - 1);
                 backlink;
                 backlink = has_looping_suffix(*backlink - 1)) {
                auto step {trace[*backlink]};
                const auto simple_loop {*backlink == trace.size() - 1};
                state = handle_loop(*backlink);
                if (state->restart()) {
                    break;
                }
                if (state->covered()) {
                    backtrack();
                    print_state();
                    break;
                }
                if (state->succeeded()) {
                    if (simple_loop) {
                        block(step);
                    }
                    print_state();
                    if ((drop || simple_loop) && try_to_finish()) {
                        return SmtResult::Unsat;
                    }
                    continue;
                }
                if (state->dropped()) {
                    if (simple_loop) {
                        block(step);
                    }
                    print_state();
                    break;
                }
                if (state->unsat()) {
                    print_state();
                    unsat();
                    return SmtResult::Unsat;
                }
                if (state->unroll() && state->unroll()->acceleration_failed()) {
                    // stop searching for longer loops if the current one was already too complicated
                    break;
                }
            }
        }
        if (luby_count >= next_restart || (state && state->restart()) || !check_consistency()) {
            if (Config::Analysis::log) std::cout << "restarting after " << luby_count << " iterations" << std::endl;
            // restart
            while (!trace.empty()) {
                pop();
            }
            luby_next();
        }
        auto try_set = trace.empty() ? chcs->getInitialTransitions() : chcs->getSuccessors(trace.back().clause_idx);
        for (auto it = try_set.begin(); it != try_set.end();) {
            if (is_learned_clause(*it) && locked.contains(*redundancy->get_language(*it))) {
                it = try_set.erase(it);
            } else {
                ++it;
            }
        }
        std::vector to_try(try_set.begin(), try_set.end());
        std::ranges::sort(to_try, [this](const RulePtr& x, const RulePtr& y){
            if (const auto p1 {get_penalty(x)}, p2 {get_penalty(y)}; p1 != p2) {
                return p1 < p2;
            }
            if (const auto xdet {x->isDeterministic()}; xdet != y->isDeterministic()) {
                return xdet;
            }
            if (const auto xlin {x->isLinear()}; xlin != y->isLinear()) {
                return xlin;
            }
            return x->getId() > y->getId();
        });
        bool all_failed {true};
        for (const auto &idx: to_try) {
            solver->push();
            const auto implicant {resolve(idx)};
            solver->pop();
            if (implicant && store_step(idx, *implicant)) {
                print_state();
                update_cpx();
                all_failed = false;
                break;
            }
            bump_penalty(idx);
        }
        if (trace.empty()) {
            break;
        }
        if (all_failed) {
            backtrack();
            print_state();
            continue;
        }
        if (try_to_finish()) { // check whether a query is applicable after every step and, importantly, before acceleration (which might approximate)
            return SmtResult::Unsat;
        }
    } while (true);
    return SmtResult::Unknown;
}

}
