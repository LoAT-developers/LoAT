#include "reachability.hpp"
#include "preprocessing.hpp"
#include "rulepreprocessing.hpp"
#include "loopacceleration.hpp"
#include "result.hpp"
#include "smt.hpp"
#include "export.hpp"
#include "vector.hpp"
#include "asymptoticbound.hpp"
#include "vareliminator.hpp"
#include "chain.hpp"
#include "expr.hpp"
#include "config.hpp"
#include "ruleexport.hpp"

#include <numeric>
#include <random>
#include <unordered_set>

namespace reachability {

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

Dropped::Dropped(const ITSProof &proof): proof(proof) {}

const ITSProof& Dropped::get_proof() const {
    return proof;
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

LearningState::~LearningState() {}

Succeeded::Succeeded(const Result<LearnedClauses> &learned): learned(learned) {}

std::optional<Succeeded> Succeeded::succeeded() {
    return *this;
}

const Result<LearnedClauses>& Succeeded::operator*() const {
    return learned;
}

const Result<LearnedClauses>* Succeeded::operator->() const {
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

ProvedUnsat::ProvedUnsat(const ITSProof &proof): proof(proof) {}

ITSProof& ProvedUnsat::operator*() {
    return proof;
}

ITSProof* ProvedUnsat::operator->() {
    return &proof;
}

Reachability::Reachability(ITSProblem &chcs):
    chcs(chcs),
    drop(true) {
    solver->enableModels();
}

Step::Step(const TransIdx transition, const BoolExpr &sat, const Subs &var_renaming, const Rule &resolvent):
    clause_idx(transition),
    implicant(sat),
    var_renaming(var_renaming),
    resolvent(resolvent) {}

Step::Step(const Step &that):
    clause_idx(that.clause_idx),
    implicant(that.implicant),
    var_renaming(that.var_renaming),
    resolvent(that.resolvent) {}

std::ostream& operator<<(std::ostream &s, const Step &step) {
    return s << step.clause_idx << "[" << step.implicant << "]";
}

std::optional<unsigned> Reachability::has_looping_suffix(int start) {
    if (trace.empty()) {
        return {};
    }
    const auto last_clause = trace.back().clause_idx;
    std::vector<long> sequence;
    for (int pos = start; pos >= 0; --pos) {
        const Step &step = trace[pos];
        if (chcs.areAdjacent(last_clause, step.clause_idx)) {
            auto upos = static_cast<unsigned>(pos);
            bool looping = upos < trace.size() - 1 || is_orig_clause(step.clause_idx);
            if (looping) {
                return upos;
            }
        }
    }
    return {};
}

Subs Reachability::handle_update(const TransIdx idx) {
    if (chcs.isSinkTransition(idx)) {
        // no need to compute a new variable renaming if we just applied a query
        return {};
    }
    const auto &last_var_renaming = trace.empty() ? Subs::Empty : trace.back().var_renaming;
    Subs new_var_renaming {last_var_renaming};
    const Subs up = idx->getUpdate();
    for (const auto &x: prog_vars) {
        new_var_renaming.put(x, TheTheory::varToExpr(expr::next(x)));
    }
    for (const auto &var: idx->vars()) {
        if (expr::isTempVar(var)) {
            new_var_renaming.put(var, TheTheory::varToExpr(expr::next(var)));
        }
    }
    for (const auto &x: prog_vars) {
        solver->add(expr::mkEq(new_var_renaming.get(x), expr::subs(up.get(x), last_var_renaming)));
    }
    return new_var_renaming;
}

void Reachability::block(const Step &step) {
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

void Reachability::pop() {
    bump_penalty(trace.back().clause_idx);
    blocked_clauses.pop_back();
    trace.pop_back();
    solver->pop();
}

void Reachability::backtrack() {
    if (Config::Analysis::log) std::cout << "backtracking" << std::endl;
    // copy the last step before popping it
    const Step step = trace.back();
    pop();
    block(step);
}

void Reachability::add_to_trace(const Step &step) {
    trace.emplace_back(step);
    blocked_clauses.emplace_back();
}

void Reachability::update_cpx() {
    if (!Config::Analysis::complexity()) {
        return;
    }
    const auto &resolvent = trace.back().resolvent;
    const auto &cost = chcs.getCost(resolvent);
    const auto max_cpx = toComplexity(cost);
    if (max_cpx <= cpx && !cost.hasVarWith([](const auto &x){return expr::isTempVar(x);})) {
        return;
    }
    const auto res = AsymptoticBound::determineComplexity(resolvent.getGuard()->conjunctionToGuard(), cost, false, cpx);
    if (res.cpx > cpx) {
        cpx = res.cpx;
        std::cout << cpx.toWstString() << std::endl;
        proof.result(cpx.toString());
    }
}

Rule Reachability::compute_resolvent(const TransIdx idx, const BoolExpr &implicant) const {
    static Rule dummy(top(), Subs());
    if (!Config::Analysis::complexity()) {
        return dummy;
    }
    auto resolvent = idx->withGuard(implicant);
    if (!trace.empty()) {
        resolvent = Chaining::chain(trace.back().resolvent, resolvent).first;
    }
    return *Preprocess::preprocessRule(resolvent);
}

bool Reachability::store_step(const TransIdx idx, const Rule &implicant) {
    solver->push();
    const auto imp {trace.empty() ? implicant : implicant.subs(trace.back().var_renaming)};
    solver->add(imp.getGuard());
    if (solver->check() == Sat) {
        const auto new_var_renaming {handle_update(idx)};
        const Step step(idx, implicant.getGuard(), new_var_renaming, compute_resolvent(idx, implicant.getGuard()));
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

void Reachability::print_trace(std::ostream &s) {
    const auto model {solver->model().toSubs()};
    s << "(";
    bool first {true};
    for (const auto &x: prog_vars) {
        const auto &y {model.get(x)};
        if (TheTheory::varToExpr(x) == y) continue;
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
        if (!chcs.isSinkTransition(step.clause_idx)) {
            for (const auto &x: prog_vars) {
                const auto y {expr::subs(step.var_renaming.get(x), model)};
                if (TheTheory::varToExpr(x) == y) continue;
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

void Reachability::print_state() {
    if (Proof::disabled()) {
        return;
    }
    Proof state_p;
    state_p.section("Trace");
    std::stringstream s;
    for (const auto &x: trace) {
        s << x << std::endl;
    }
    state_p.append(s);
    s.clear();
    state_p.section("Blocked");
    for (const auto &e: blocked_clauses) {
        s << "{";
        bool first_trans = true;
        for (const auto &[idx,blocked]: e) {
            if (first_trans) {
                first_trans = false;
            } else {
                s << ", ";
            }
            s << idx << "[" << BExpression::buildOr(blocked) << "]";
        }
        s << "}" << std::endl;
    }
    state_p.append(s);
    proof.storeSubProof(state_p);
}

void Reachability::init() {
    srand(42);
    for (const auto &x: chcs.getVars()) {
        if (!expr::isTempVar(x)) {
            prog_vars.insert(x);
        }
    }
    for (const auto &r: chcs.getAllTransitions()) {
        last_orig_clause = std::max(last_orig_clause, r.getId());
    }
}

void Reachability::luby_next() {
    for (const auto &x: chcs.getAllTransitions()) {
        if (is_learned_clause(&x) && !x.isPoly()) {
            locked.insert(*redundancy->get_language(&x));
        }
    }
    const auto [u,v] {luby};
    luby = (u & -u) == v ? std::pair<unsigned, unsigned>(u+1, 1) : std::pair<unsigned, unsigned>(u, 2 * v);
    solver->resetSolver();
    solver->randomize(rand());
    luby_count = 0;
}

void Reachability::unsat() {
    const auto res = Config::Analysis::reachability() ? "unsat" : "NO";
    std::cout << res << std::endl << std::endl;
    if (!Config::Analysis::log && Proof::disabled()) {
        return;
    }
    std::stringstream counterexample;
    print_trace(counterexample);
    if (Config::Analysis::log) {
        std::stringstream trace_stream;
        trace_stream << trace;
        std::cout << "final ITS:" << std::endl;
        ITSExport::printForProof(chcs, std::cout);
        std::cout << std::endl << "final trace:" << trace_stream.str() << std::endl << std::endl;
        std::cout << "counterexample: " << counterexample.str();
    }
    proof.headline("Refute");
    Proof subProof;
    subProof.section("Counterexample");
    subProof.append(counterexample);
    proof.storeSubProof(subProof);
    proof.result(res);
    proof.print();
}

void Reachability::unknown() {
    std::cout << "unknown" << std::endl << std::endl;
    if (!Config::Analysis::log && Proof::disabled()) {
        return;
    }
    proof.headline("Prove");
    proof.result("unknown");
    proof.print();
}

std::optional<Rule> Reachability::resolve(const TransIdx idx) {
    const auto &var_renaming = trace.empty() ? Subs::Empty : trace.back().var_renaming;
    const auto block = blocked_clauses.back().find(idx);
    if (block != blocked_clauses.back().end()) {
        // empty means all variants are blocked --> fail
        if (block->second.empty()) {
            return {};
        }
        // a non-conjunctive clause where some variants are blocked
        // --> make sure that we use a non-blocked variant, if any
        for (const auto &b: block->second) {
            solver->add(!b->subs(var_renaming));
        }
    }
    const auto vars {idx->getGuard()->vars()};
    const auto projected_var_renaming {var_renaming.project(vars)};
    const auto guard {idx->getGuard()->subs(projected_var_renaming)};
    solver->add(guard);
    switch (solver->check()) {
    case Sat: {
        if (Config::Analysis::log) std::cout << "found model for " << idx << std::endl;
        const auto model {solver->model(guard->vars()).toSubs()};
        const auto implicant {idx->getGuard()->syntacticImplicant(expr::compose(projected_var_renaming, model))};
        return {idx->withGuard(implicant)};
    }
    case Unknown: {}
    [[fallthrough]];
    case Unsat: {
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

Automaton Reachability::get_language(const Step &step) {
    if (is_orig_clause(step.clause_idx)) {
        return redundancy->get_singleton_language(step.clause_idx, step.implicant->conjunctionToGuard());
    } else {
        return *redundancy->get_language(step.clause_idx);
    }
}

Automaton Reachability::build_language(const int backlink) {
    auto lang = get_language(trace[backlink]);
    for (size_t i = backlink + 1; i < trace.size(); ++i) {
        redundancy->concat(lang, get_language(trace[i]));
    }
    return lang;
}

std::pair<Rule, Subs> Reachability::build_loop(const int backlink) {
    std::optional<Rule> loop;
    Subs var_renaming;
    for (int i = trace.size() - 1; i >= backlink; --i) {
        const auto &step {trace[i]};
        const auto rule {step.clause_idx->withGuard(step.implicant)};
        if (loop) {
            const auto [chained, sigma] {Chaining::chain(rule, *loop)};
            loop = chained;
            var_renaming = expr::compose(sigma, var_renaming);
        } else {
            loop = rule;
        }
        if (i > 0) {
            var_renaming = expr::compose(trace[i-1].var_renaming.project(rule.vars()), var_renaming);
        }
    }
    auto vars {loop->vars()};
    var_renaming = var_renaming.project(vars);
    expr::collectCoDomainVars(var_renaming, vars);
    const auto model {expr::compose(var_renaming, solver->model(vars).toSubs())};
    if (Config::Analysis::log) {
        std::cout << "found loop of length " << (trace.size() - backlink) << ":" << std::endl;
        RuleExport::printRule(*loop, std::cout);
        std::cout << std::endl;
    }
    return {*loop, model};
}

TransIdx Reachability::add_learned_clause(const Rule &accel, const unsigned backlink) {
    const auto fst = trace.at(backlink).clause_idx;
    const auto last = trace.back().clause_idx;
    const auto loop_idx = chcs.addLearnedRule(accel, fst, last);
    return loop_idx;
}

bool Reachability::is_learned_clause(const TransIdx idx) const {
    return idx->getId() > last_orig_clause;
}

bool Reachability::is_orig_clause(const TransIdx idx) const {
    return idx->getId() <= last_orig_clause;
}

RuleResult Reachability::instantiate(const NumVar &n, const Rule &rule) const {
    RuleResult res(rule);
    VarEliminator ve(rule.getGuard(), n, expr::isProgVar);
    if (ve.getRes().empty() || ve.getRes().size() > 1) {
        return res;
    }
    for (const auto &s : ve.getRes()) {
        if (s.get(n).isRationalConstant()) continue;
        if (res) {
            return RuleResult(rule);
        }
        res = rule.subs(Subs::build<IntTheory>(s));
        res.ruleTransformationProof(rule, "Instantiation", *res);
    }
    return res;
}

std::unique_ptr<LearningState> Reachability::learn_clause(const Rule &rule, const Subs &model, const unsigned backlink) {
    RuleResult simp = Preprocess::preprocessRule(rule);
    if (Config::Analysis::reachability() && simp->getUpdate() == expr::concat(simp->getUpdate(), simp->getUpdate())) {
        // The learned clause would be trivially redundant w.r.t. the looping suffix (but not necessarily w.r.t. a single clause).
        // Such clauses are pretty useless, so we do not store them.
        if (Config::Analysis::log) std::cout << "acceleration would yield equivalent rule" << std::endl;
        return std::make_unique<Unroll>(1);
    }
    if (Config::Analysis::log && simp) {
        std::cout << "simplified loop:" << std::endl;
        RuleExport::printRule(*simp, std::cout);
        std::cout << std::endl;
    }
    if (Config::Analysis::reachability()) {
        if (simp->getUpdate().empty()) {
            if (Config::Analysis::log) std::cout << "trivial looping suffix" << std::endl;
            return std::make_unique<Covered>();
        }
    }
    const NumVar n {NumVar::next()};
    AccelConfig config {
        .tryNonterm = Config::Analysis::tryNonterm(),
        .n = n};
    const auto accel_res {LoopAcceleration::accelerate(*simp, {}, config)};
    if (accel_res.status == acceleration::PseudoLoop) {
        return std::make_unique<Unroll>();
    }
    Result<LearnedClauses> res{{.res = {}, .prefix = accel_res.prefix, .period = accel_res.period}};
    if (Config::Analysis::tryNonterm() && accel_res.nonterm) {
        res.succeed();
        const auto idx = chcs.addQuery(accel_res.nonterm->certificate, trace.at(backlink).clause_idx);
        res->res.emplace_back(idx);
        RuleProof nonterm_proof;
        nonterm_proof.ruleTransformationProof(*simp, "Certificate of Non-Termination", *idx);
        nonterm_proof.storeSubProof(accel_res.nonterm->proof);
        res.concat(nonterm_proof);
        if (Config::Analysis::log) {
            std::cout << "found certificate of non-termination, idx " << idx << std::endl;
            std::cout << accel_res.nonterm->certificate << std::endl;
        }
    }
    if (accel_res.accel) {
        // acceleration succeeded, simplify the result
        auto simplified = Preprocess::preprocessRule(accel_res.accel->rule);
        if (simplified->getUpdate() != simp->getUpdate()) {
            // accelerated rule differs from the original one, update the result
            if (Config::Analysis::complexity()) {
                simplified.concat(instantiate(n, *simplified));
            }
            res.succeed();
            const auto loop_idx {add_learned_clause(*simplified, backlink)};
            res->res.emplace_back(loop_idx);
            RuleProof acceleration_proof;
            acceleration_proof.storeSubProof(simp.getProof());
            acceleration_proof.ruleTransformationProof(*simp, "Loop Acceleration", accel_res.accel->rule);
            acceleration_proof.storeSubProof(accel_res.accel->proof);
            res.concat(acceleration_proof);
            res.concat(simplified.getProof());
            if (Config::Analysis::log) {
                std::cout << "accelerated rule, idx " << loop_idx << std::endl;
                RuleExport::printRule(*simplified, std::cout);
                std::cout << std::endl;
            }
        }
    }
    if (!res) {
        if (Config::Analysis::log) {
            std::cout << "acceleration failed, status: " << accel_res.status << std::endl;
        }
        return std::make_unique<Unroll>(1, true);
    }
    return std::make_unique<Succeeded>(res);
}

bool Reachability::check_consistency() {
    // make sure that a model is available
    bool res {true};
    switch (solver->check()) {
    case Unsat:
        throw std::logic_error("trace is contradictory");
    case Unknown:
        std::cerr << "consistency of trace cannot be proven" << std::endl;
        res = false;
        break;
    case Sat:
        break;
    }
    return res;
}

void Reachability::drop_until(const int new_size) {
    while (trace.size() > static_cast<unsigned>(new_size)) {
        pop();
    }
}

std::unique_ptr<LearningState> Reachability::handle_loop(const unsigned backlink) {
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
    const auto learned_clauses {**accel_state};
    bool do_drop {drop || (backlink == trace.size() - 1  && learned_clauses.prefix <= 1 && learned_clauses.period == 1)};
    if (do_drop) {
        drop_until(backlink);
    }
    bool done {!do_drop};
    if (Config::Analysis::log) {
        std::cout << "prefix: " << learned_clauses.prefix << ", period: " << learned_clauses.period << std::endl;
    }
    for (const auto idx: learned_clauses.res) {
        redundancy->set_language(idx, closure);
        if (!done && store_step(idx, *idx)) {
            update_cpx();
            if (chcs.isSinkTransition(idx)) {
                return std::make_unique<ProvedUnsat>(accel_state->getProof());
            } else {
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
        return std::make_unique<Dropped>(accel_state->getProof());
    }
}

bool Reachability::try_to_finish() {
    const auto clauses = trace.empty() ? chcs.getInitialTransitions() : chcs.getSuccessors(trace.back().clause_idx);
    for (const auto &q: clauses) {
        if (chcs.isSinkTransition(q)) {
            solver->push();
            const auto implicant {resolve(q)};
            if (implicant) {
                // no need to compute a variable renaming for the next step, as we are done
                add_to_trace(Step(q, implicant->getGuard(), Subs(), compute_resolvent(q, implicant->getGuard())));
                proof.headline("Step with " + std::to_string(q->getId()));
                print_state();
                unsat();
                return true;
            }
            solver->pop();
        }
    }
    return false;
}

unsigned Reachability::get_penalty(const TransIdx idx) const {
    const auto it {penalty.find(idx)};
    if (it != penalty.end()) {
        return it->second;
    } else {
        return 0;
    }
}

void Reachability::bump_penalty(const TransIdx idx) {
    penalty.emplace(idx, 0).first->second++;
}

void Reachability::analyze() {
    proof.majorProofStep("Initial ITS", ITSProof(), chcs);
    if (Config::Analysis::log) {
        std::cout << "Initial ITS" << std::endl;
        ITSExport::printForProof(chcs, std::cout);
    }
    const auto res {Preprocess::preprocess(chcs)};
    if (res) {
        proof.concat(res.getProof());
        if (Config::Analysis::log) {
            std::cout << "Simplified ITS" << std::endl;
            ITSExport::printForProof(chcs, std::cout);
        }
    }
    init();
    if (try_to_finish()) {
        return;
    }
    blocked_clauses[0].clear();
    do {
        ++luby_count;
        size_t next_restart = luby_unit * luby.second;
        std::unique_ptr<LearningState> state;
        if (Config::Analysis::log) std::cout << "trace: " << trace << std::endl;
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
                    proof.headline("Covered");
                    print_state();
                    break;
                } else if (state->succeeded()) {
                    if (simple_loop) {
                        block(step);
                    }
                    proof.majorProofStep("Accelerate", (*state->succeeded())->getProof(), chcs);
                    print_state();
                    if ((drop || simple_loop) && try_to_finish()) {
                        return;
                    }
                } else if (state->dropped()) {
                    if (simple_loop) {
                        block(step);
                    }
                    proof.majorProofStep("Accelerate and Drop", state->dropped()->get_proof(), chcs);
                    print_state();
                    break;
                } else if (state->unsat()) {
                    proof.majorProofStep("Nonterm", **state->unsat(), chcs);
                    proof.headline("Step with " + std::to_string(trace.back().clause_idx->getId()));
                    print_state();
                    unsat();
                    return;
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
            proof.headline("Restart");
        }
        auto try_set = trace.empty() ? chcs.getInitialTransitions() : chcs.getSuccessors(trace.back().clause_idx);
        for (auto it = try_set.begin(); it != try_set.end();) {
            if (is_learned_clause(*it) && locked.contains(*redundancy->get_language(*it))) {
                it = try_set.erase(it);
            } else {
                ++it;
            }
        }
        std::vector<TransIdx> to_try(try_set.begin(), try_set.end());
        std::sort(to_try.begin(), to_try.end(), [this](const TransIdx x, const TransIdx y){
            const auto p1 {get_penalty(x)};
            const auto p2 {get_penalty(y)};
            if (p1 != p2) {
                return p1 < p2;
            } else {
                return x->getId() < y->getId();
            }
        });
        bool all_failed {true};
        for (const auto idx: to_try) {
            solver->push();
            const auto implicant {resolve(idx)};
            solver->pop();
            if (implicant && store_step(idx, *implicant)) {
                proof.headline("Step with " + std::to_string(idx->getId()));
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
            proof.headline("Backtrack");
            print_state();
        } else if (try_to_finish()) { // check whether a query is applicable after every step and, importantly, before acceleration (which might approximate)
            return;
        }
    } while (true);
    proof.headline("Accept");
    if (Config::Analysis::complexity()) {
        proof.result(cpx.toString());
        proof.print();
    } else {
        unknown();
    }
    std::cout << std::endl;
}

void Reachability::analyze(ITSProblem &its) {
    Reachability(its).analyze();
}

}
