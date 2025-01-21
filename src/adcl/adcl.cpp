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

#include <numeric>
#include <random>
#include <unordered_set>

namespace adcl {

using ::operator<<;

LearningState::LearningState() {}

std::optional<Succeeded> LearningState::succeeded() {
    return {};
}

std::optional<Covered> LearningState::covered() {
    return {};
}

std::optional<Dropped> LearningState::dropped() {
    return {};
}

Dropped::Dropped() {}

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

LearningState::~LearningState() {}

Succeeded::Succeeded(const LearnedClauses &learned): learned(learned) {}

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

Unroll::Unroll() {}

Unroll::Unroll(unsigned max, bool accel_failed): max(max), accel_failed(accel_failed) {}

std::optional<unsigned> Unroll::get_max() {
    return max;
}

std::optional<Unroll> Unroll::unroll() {
    return *this;
}

bool Unroll::acceleration_failed() {
    return accel_failed;
}

std::optional<ProvedUnsat> ProvedUnsat::unsat() {
    return *this;
}

ProvedUnsat::ProvedUnsat() {}

ADCL::ADCL(ITSPtr chcs, const std::function<void(const ITSCpxCex&)> &print_cpx_cex):
    chcs(chcs),
    drop(true),
    cex(chcs),
    cpx_cex(chcs),
    print_cpx_cex(print_cpx_cex) {
    solver->enableModels();
}

Step::Step(const RulePtr transition, const Bools::Expr sat, const Renaming &var_renaming, const Renaming &tmp_var_renaming, const RulePtr resolvent):
    clause_idx(transition),
    implicant(sat),
    var_renaming(var_renaming),
    tmp_var_renaming(tmp_var_renaming),
    resolvent(resolvent) {}

Step::Step(const Step &that):
    clause_idx(that.clause_idx),
    implicant(that.implicant),
    var_renaming(that.var_renaming),
    tmp_var_renaming(that.tmp_var_renaming),
    resolvent(that.resolvent) {}

std::ostream& operator<<(std::ostream &s, const Step &step) {
    return s << step.clause_idx << "[" << step.implicant << "]";
}

std::optional<unsigned> ADCL::has_looping_suffix(int start) {
    if (trace.empty()) {
        return {};
    }
    const auto last_clause = trace.back().clause_idx;
    std::vector<long> sequence;
    for (int pos = start; pos >= 0; --pos) {
        const Step &step = trace[pos];
        if (chcs->areAdjacent(last_clause, step.clause_idx)) {
            auto upos = static_cast<unsigned>(pos);
            bool looping = upos < trace.size() - 1 || is_orig_clause(step.clause_idx);
            if (looping) {
                return upos;
            }
        }
    }
    return {};
}

std::pair<Renaming, Renaming> ADCL::handle_update(const RulePtr idx) {
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
            new_var_renaming.insert<decltype(th)>(x, th.next());
        });
    }
    for (const auto &var: idx->vars()) {
        if (theory::isTempVar(var)) {
            theory::apply(var, [&](const auto &x) {
                const auto th {theory::theory(x)};
                const auto next {th.next()};
                new_var_renaming.insert<decltype(th)>(x, next);
                new_tmp_var_renaming.insert<decltype(th)>(x, next);
            });
        }
    }
    for (const auto &[var,_]: last_tmp_var_renaming) {
        if (!new_tmp_var_renaming.contains(var)) {
            theory::apply(var, [&](const auto &x) {
                const auto th {theory::theory(x)};
                const auto next {th.next()};
                new_var_renaming.insert<decltype(th)>(x, next);
                new_tmp_var_renaming.insert<decltype(th)>(x, next);
            });
        }
    }
    for (const auto &x: prog_vars) {
        solver->add(theory::mkEq(theory::toExpr(new_var_renaming.get(x)), last_var_renaming(up.get(x))));
    }
    return {new_var_renaming, new_tmp_var_renaming};
}

void ADCL::block(const Step &step) {
    if (Config::Analysis::log) std::cout << "blocking " << step.clause_idx << ", " << step.implicant << std::endl;
    if (step.clause_idx->getGuard()->isConjunction()) {
        blocked_clauses.back()[step.clause_idx] = {};
    } else {
        auto block = blocked_clauses.back().find(step.clause_idx);
        if (block == blocked_clauses.back().end()) {
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

void ADCL::set_cpx_witness(const RulePtr witness, const ArithSubs &subs, const Arith::Var &param) {
    if (trace.size() > 1) {
        std::vector<RulePtr> rules;
        for (const auto &t: trace) {
            rules.emplace_back(t.clause_idx->withGuard(t.implicant));
        }
        cpx_cex.add_resolvent(rules, witness);
    } else {
        const auto &t {trace.back()};
        if (t.implicant != t.clause_idx->getGuard()) {
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
    const auto max_cpx = toComplexity(cost);
    if (max_cpx <= cpx && !cost->hasVarWith([](const auto &x){return theory::isTempVar(x);})) {
        return;
    }
    const auto witness {LimitSmtEncoding::applyEncoding(resolvent->getGuard(), cost, cpx)};
    if (witness.cpx > cpx) {
        cpx = witness.cpx;
        std::cout << cpx.toWstString() << std::endl;
        if (Config::Analysis::model) {
            set_cpx_witness(resolvent, witness.subs, witness.param);
        }
        if (Config::Analysis::log) {
            std::cout << cpx.toString() << std::endl;
        }
    }
}

RulePtr ADCL::compute_resolvent(const RulePtr idx, const Bools::Expr implicant) const {
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

bool ADCL::store_step(const RulePtr idx, const RulePtr implicant) {
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
    } else {
        solver->pop();
        return false;
    }
}

void ADCL::print_trace(std::ostream &s) {
    const auto model {solver->model()};
    s << "(";
    bool first {true};
    for (const auto &x: prog_vars) {
        if (!model.contains(x)) continue;
        const auto &y {model.get(x)};
        if (first) {
            first = false;
        } else {
            s << ", ";
        }
        s << x << "=" << y;
    }
    s << ")" << std::endl;
    for (const auto &step: trace) {
        s << "-" << step.clause_idx << "-> " << "(";
        first = true;
        if (!chcs->isSinkTransition(step.clause_idx)) {
            for (const auto &x: prog_vars) {
                const auto y {model.eval(theory::toExpr(step.var_renaming.get(x)))};
                if (first) {
                    first = false;
                } else {
                    s << ", ";
                }
                s << x << "=" << y;
            }
        }
        s << ")" << std::endl;
    }
    s << std::endl;
}

void ADCL::print_state() {
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

void ADCL::unsat() {
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

std::optional<RulePtr> ADCL::resolve(const RulePtr idx) {
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
            solver->add(var_renaming(!b));
        }
    }
    const auto vars {idx->getGuard()->vars()};
    const auto projected_var_renaming {var_renaming.project(vars)};
    const auto guard {projected_var_renaming(idx->getGuard())};
    solver->add(guard);
    switch (solver->check()) {
    case SmtResult::Sat: {
        if (Config::Analysis::log) std::cout << "found model for " << idx << std::endl;
        const auto model {solver->model(guard->vars()).composeBackwards(projected_var_renaming)};
        const auto implicant {model.syntacticImplicant(idx->getGuard())};
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

Automaton ADCL::get_language(const Step &step) {
    if (is_orig_clause(step.clause_idx)) {
        return redundancy->get_singleton_language(step.clause_idx, Conjunction::fromBoolExpr(step.implicant));
    } else {
        return *redundancy->get_language(step.clause_idx);
    }
}

Automaton ADCL::build_language(const int backlink) {
    auto lang = get_language(trace[backlink]);
    for (size_t i = backlink + 1; i < trace.size(); ++i) {
        redundancy->concat(lang, get_language(trace[i]));
    }
    return lang;
}

std::pair<RulePtr, Model> ADCL::build_loop(const int backlink) {
    std::vector<RulePtr> rules;
    for (size_t i = backlink; i < trace.size(); ++i) {
        rules.emplace_back(trace[i].clause_idx->withGuard(trace[i].implicant)->renameVars(trace[i].tmp_var_renaming));
    }
    const auto loop {Preprocess::chain(rules)};
    const auto s {trace[backlink].var_renaming};
    auto vars {loop->vars()};
    s.collectCoDomainVars(vars);
    const auto m {solver->model(vars)};
    const auto model {m.composeBackwards(s)};
    if (Config::Analysis::log) {
        std::cout << "found loop of length " << (trace.size() - backlink) << ":\n" << *loop << std::endl;
    }
    return {loop, model};
}

void ADCL::add_learned_clause(const RulePtr accel, const unsigned backlink) {
    const auto fst = trace.at(backlink).clause_idx;
    const auto last = trace.back().clause_idx;
    chcs->addLearnedRule(accel, fst, last);
}

bool ADCL::is_learned_clause(const RulePtr idx) const {
    return idx->getId() > last_orig_clause;
}

bool ADCL::is_orig_clause(const RulePtr idx) const {
    return idx->getId() <= last_orig_clause;
}

std::optional<RulePtr> ADCL::instantiate(const Arith::Var n, const RulePtr rule) const {
    std::optional<RulePtr> res{};
    VarEliminator ve(rule->getGuard(), n, theory::isProgVar);
    for (const auto &s : ve.getRes()) {
        if (s.get(n)->isRational()) continue;
        if (res) {
            return {};
        }
        res = rule->subs(Subs::build<Arith>(s));
    }
    return res;
}

ITSCex* ADCL::the_cex() {
    if (Config::Analysis::mode == Config::Analysis::Complexity) {
        return &cpx_cex;
    } else {
        return &cex;
    }
}

std::unique_ptr<LearningState> ADCL::learn_clause(const RulePtr rule, const Model &model, const unsigned backlink) {
    const auto simp {Preprocess::preprocessRule(rule)};
    if (Config::Analysis::safety() && simp->getUpdate() == simp->getUpdate().concat(simp->getUpdate())) {
        // The learned clause would be trivially redundant w.r.t. the looping suffix (but not necessarily w.r.t. a single clause).
        // Such clauses are pretty useless, so we do not store them.
        if (Config::Analysis::log) std::cout << "acceleration would yield equivalent rule" << std::endl;
        return std::make_unique<Unroll>(1);
    }
    if (Config::Analysis::log && simp->getId() != rule->getId()) {
        std::cout << "simplified loop:\n" << *simp << std::endl;
    }
    if (Config::Analysis::safety()) {
        if (simp->getUpdate().empty()) {
            if (Config::Analysis::log) std::cout << "trivial looping suffix" << std::endl;
            return std::make_unique<Covered>();
        }
    }
    const auto n {ArithVar::next()};
    const AccelConfig config {
        .tryNonterm = Config::Analysis::tryNonterm(),
        .n = n};
    const auto accel_res {LoopAcceleration::accelerate(simp, config)};
    if (accel_res.status == acceleration::PseudoLoop) {
        return std::make_unique<Unroll>();
    }
    LearnedClauses res{.res = {}, .prefix = accel_res.prefix, .period = accel_res.period};
    if (Config::Analysis::tryNonterm() && accel_res.nonterm != bot()) {
        const auto query {chcs->addQuery(accel_res.nonterm, trace.at(backlink).clause_idx)};
        res.res.emplace_back(query);
        if (Config::Analysis::model) {
            the_cex()->add_recurrent_set(rule, query);
        }
        if (Config::Analysis::log) {
            std::cout << "found certificate of non-termination: " << query << std::endl;
        }
    }
    if (accel_res.accel) {
        // acceleration succeeded, simplify the result
        auto simplified {Preprocess::preprocessRule(accel_res.accel->rule)};
        if (simplified->getUpdate() != simp->getUpdate()) {
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
                std::cout << "accelerated rule: " << simplified << std::endl;
            }
        }
    }
    if (res.res.empty()) {
        if (Config::Analysis::log) {
            std::cout << "acceleration failed, status: " << accel_res.status << std::endl;
        }
        return std::make_unique<Unroll>(1, true);
    } else {
        if (Config::Analysis::model) {
            std::vector<RulePtr> rules;
            for (unsigned i = backlink; i < trace.size(); ++i) {
                const auto e{trace.at(i)};
                if (is_orig_clause(e.clause_idx) && e.implicant != e.clause_idx->getGuard()) {
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
}

bool ADCL::check_consistency() {
    // make sure that a model is available
    bool res {true};
    switch (solver->check()) {
    case SmtResult::Unsat:
    case SmtResult::Unknown:
        throw std::logic_error("trace is contradictory");
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
    auto state {learn_clause(loop, model, backlink)};
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
    const auto learned_clauses {*accel_state};
    bool do_drop {drop || (backlink == trace.size() - 1  && learned_clauses.prefix <= 1 && learned_clauses.period == 1)};
    if (do_drop) {
        drop_until(backlink);
    }
    bool done {!do_drop};
    if (Config::Analysis::log) {
        std::cout << "prefix: " << learned_clauses.prefix << ", period: " << learned_clauses.period << std::endl;
    }
    for (const auto &idx: learned_clauses.res) {
        redundancy->set_language(idx, closure);
        if (!done && store_step(idx, idx)) {
            if (chcs->isSinkTransition(idx)) {
                if (Config::Analysis::complexity() && Config::Analysis::model) {
                    set_cpx_witness(trace.back().resolvent, solver->model().toSubs().get<Arith>(), Arith::next());
                }
                return std::make_unique<ProvedUnsat>();
            } else {
                update_cpx();
                done = true;
            }
        }
    }
    if (done) {
        redundancy->mark_as_redundant(closure);
        return state;
    } else {
        // unroll once if we dropped the loop
        redundancy->concat(closure, closure);
        redundancy->mark_as_redundant(closure);
        if (Config::Analysis::log) std::cout << "applying accelerated rule failed" << std::endl;
        return std::make_unique<Dropped>();
    }
}

bool ADCL::try_to_finish() {
    const auto clauses = trace.empty() ? chcs->getInitialTransitions() : chcs->getSuccessors(trace.back().clause_idx);
    for (const auto &q: clauses) {
        if (chcs->isSinkTransition(q)) {
            solver->push();
            const auto implicant {resolve(q)};
            if (implicant) {
                if (Config::Analysis::complexity() && Config::Analysis::model) {
                    const auto resolvent {compute_resolvent(q, (*implicant)->getGuard())};
                    set_cpx_witness(resolvent, solver->model().toSubs().get<Arith>(), Arith::next());
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
        if (!cex.try_step(t.clause_idx->withGuard(t.implicant), model.composeBackwards(t.var_renaming))) {
            throw std::logic_error("get_cex failed");
        }
    }
    const auto &last {trace.back()};
    if (!cex.try_final_transition(last.clause_idx->withGuard(last.implicant))) {
        throw std::logic_error("get_cex failed");
    }
    return cex;
}

unsigned ADCL::get_penalty(const RulePtr idx) const {
    const auto it {penalty.find(idx)};
    if (it != penalty.end()) {
        return it->second;
    } else {
        return 0;
    }
}

void ADCL::bump_penalty(const RulePtr idx) {
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
        size_t next_restart = luby_unit * luby.second;
        std::unique_ptr<LearningState> state;
        if (!trace.empty()) {
            for (auto backlink = has_looping_suffix(trace.size() - 1);
                 backlink;
                 backlink = has_looping_suffix(*backlink - 1)) {
                auto step {trace[*backlink]};
                auto simple_loop {*backlink == trace.size() - 1};
                state = handle_loop(*backlink);
                if (state->restart()) {
                    break;
                } else if (state->covered()) {
                    backtrack();
                    print_state();
                    break;
                } else if (state->succeeded()) {
                    if (simple_loop) {
                        block(step);
                    }
                    print_state();
                    if ((drop || simple_loop) && try_to_finish()) {
                        return SmtResult::Unsat;
                    }
                } else if (state->dropped()) {
                    if (simple_loop) {
                        block(step);
                    }
                    print_state();
                    break;
                } else if (state->unsat()) {
                    print_state();
                    unsat();
                    return SmtResult::Unsat;
                } else if (state->unroll() && state->unroll()->acceleration_failed()) {
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
        std::vector<RulePtr> to_try(try_set.begin(), try_set.end());
        std::sort(to_try.begin(), to_try.end(), [this](const RulePtr x, const RulePtr y){
            const auto p1 {get_penalty(x)};
            const auto p2 {get_penalty(y)};
            if (p1 != p2) {
                return p1 < p2;
            } else {
                return x->getId() < y->getId();
            }
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
            } else {
                bump_penalty(idx);
            }
        }
        if (trace.empty()) {
            break;
        } else if (all_failed) {
            backtrack();
            print_state();
        } else if (try_to_finish()) { // check whether a query is applicable after every step and, importantly, before acceleration (which might approximate)
            return SmtResult::Unsat;
        }
    } while (true);
    return SmtResult::Unknown;
}

}
