#include "reachability.hpp"
#include "preprocessing.hpp"
#include "rulepreprocessing.hpp"
#include "loopacceleration.hpp"
#include "result.hpp"
#include "smt.hpp"
#include "export.hpp"
#include "smtfactory.hpp"
#include "vector.hpp"
#include "asymptoticbound.hpp"
#include "vareliminator.hpp"
#include "chain.hpp"
#include "expr.hpp"
#include "cvc5.hpp"

#include <numeric>
#include <random>

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

Unroll::Unroll(unsigned max): max(max) {}

std::optional<unsigned> Unroll::get_max() {
    return max;
}

std::optional<Unroll> Unroll::unroll() {
    return *this;
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

ProofFailed::ProofFailed(const std::string &msg): std::runtime_error(msg) {}

Reachability::Reachability(ITSProblem &chcs, bool incremental_mode):
    chcs(chcs),
    drop(!Config::Analysis::safety()),
    analysis_result(LinearSolver::Result::Pending),
    incremental_mode(incremental_mode)
{
    switch (Config::Analysis::smtSolver) {
    case Config::Analysis::Z3:
        solver = std::unique_ptr<Smt<IntTheory, BoolTheory>>(new LinearizingSolver<IntTheory, BoolTheory>(smt::default_timeout));
        break;
    case Config::Analysis::CVC5:
        solver = std::unique_ptr<Smt<IntTheory, BoolTheory>>(new CVC5<IntTheory, BoolTheory>());
        break;
    }
    solver->enableModels();
    proof.majorProofStep("Initial ITS", ITSProof(), chcs);
    if (Config::Analysis::log) {
        std::cout << "Initial ITS" << std::endl;
        ITSExport::printForProof(chcs, std::cout);
    }
}

Step::Step(const TransIdx transition, const BoolExpr &sat, const Subs &var_renaming, const Rule &resolvent):
    clause_idx(transition),
    implicant(sat),
    var_renaming(var_renaming),
    resolvent(resolvent) {}

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

    // Resolvent only has to be computed in incremental mode (i.e. when the problem includes non linear CHCs) or 
    // for complexity analysis. Otherwise we can skip it.
    if (Config::Analysis::complexity() || incremental_mode) {
        auto resolvent = idx->withGuard(implicant);
        if (!trace.empty()) {
            resolvent = Chaining::chain(trace.back().resolvent, resolvent).first;
        }
        return *Preprocess::preprocessRule(resolvent);
    } else {
        return dummy;
    }
}

bool Reachability::store_step(const TransIdx idx, const Rule &implicant, bool force) {
    solver->push();
    const auto imp {trace.empty() ? implicant : implicant.subs(trace.back().var_renaming)};
    solver->add(imp.getGuard());
    if (solver->check() == Sat || force) {
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
            s << idx << "[" << BExpression::buildAnd(blocked) << "]";
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
    const auto [u,v] {luby};
    luby = (u & -u) == v ? std::pair<unsigned, unsigned>(u+1, 1) : std::pair<unsigned, unsigned>(u, 2 * v);
    solver->setSeed(rand());
    solver->resetSolver();
    luby_loop_count = 0;
}

void Reachability::unsat() {
    const auto res = Config::Analysis::safety() ? "unknown" : (Config::Analysis::reachability() ? "unsat" : "NO");
    analysis_result = analysis_result_from(res);
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

void Reachability::sat() {
    const auto res = Config::Analysis::safety() ? "sat" : "unknown";
    analysis_result = analysis_result_from(res);
    if (!Config::Analysis::log && Proof::disabled()) {
        return;
    }
    proof.headline("Prove");
    proof.result(res);
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
        const auto implicant {idx->getGuard()->implicant(expr::compose(projected_var_renaming, model))};
        if (implicant) {
            return {idx->withGuard(*implicant)};
        } else {
            throw std::logic_error("model, but no implicant");
        }
    }
    case Unknown: {
        if (Config::Analysis::safety()) {
            throw ProofFailed("SMT returned UNKNOWN during resolution");
        }
    } // fall through intended
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

Rule Reachability::build_loop(const int backlink) {
    std::optional<Rule> loop;
    for (int i = trace.size() - 1; i >= backlink; --i) {
        const auto &step {trace[i]};
        const auto rule {step.clause_idx->withGuard(step.implicant)};
        loop = loop ? Chaining::chain(rule, *loop).first : rule;
    }
    if (Config::Analysis::log) {
        std::cout << "found loop of length " << (trace.size() - backlink) << ":" << std::endl;
        ITSExport::printRule(*loop, std::cout);
        std::cout << std::endl;
    }
    return {*loop};
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

Result<Rule> Reachability::instantiate(const NumVar &n, const Rule &rule) const {
    Result<Rule> res(rule);
    VarEliminator ve(rule.getGuard(), n, expr::isProgVar);
    if (ve.getRes().empty() || ve.getRes().size() > 1) {
        return res;
    }
    for (const auto &s : ve.getRes()) {
        if (s.get(n).isRationalConstant()) continue;
        if (res) {
            return Result<Rule>(rule);
        }
        res = rule.subs(Subs::build<IntTheory>(s));
        res.ruleTransformationProof(rule, "Instantiation", *res);
    }
    return res;
}

std::unique_ptr<LearningState> Reachability::learn_clause(const Rule &rule, const unsigned backlink) {
    Result<Rule> simp = Preprocess::preprocessRule(rule);
    if (Config::Analysis::reachability() && simp->getUpdate() == expr::concat(simp->getUpdate(), simp->getUpdate())) {
        // The learned clause would be trivially redundant w.r.t. the looping suffix (but not necessarily w.r.t. a single clause).
        // Such clauses are pretty useless, so we do not store them.
        if (Config::Analysis::log) std::cout << "acceleration would yield equivalent rule" << std::endl;
        return std::make_unique<Unroll>(1);
    }
    if (Config::Analysis::log && simp) {
        std::cout << "simplified loop:" << std::endl;
        ITSExport::printRule(*simp, std::cout);
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
        .approx = Config::Analysis::safety() ? OverApprox : UnderApprox,
        .tryNonterm = Config::Analysis::tryNonterm(),
        .n = n};
    const auto accel_res {LoopAcceleration::accelerate(*simp, config)};
    if (accel_res.status == acceleration::PseudoLoop) {
        return std::make_unique<Unroll>();
    }
    if (Config::Analysis::safety() && accel_res.status != acceleration::Success) {
        std::stringstream s;
        s << "acceleration failed, status: " << accel_res.status;
        if (Config::Analysis::log) {
            std::cout << s.str() << std::endl;
            std::cout << "rule:" << std::endl;
            ITSExport::printRule(*simp, std::cout);
            std::cout << std::endl;
        }
        throw ProofFailed(s.str());
    }
    Result<LearnedClauses> res{{.res = {}, .prefix = accel_res.prefix, .period = accel_res.period}};
    if (accel_res.nonterm) {
        res.succeed();
        const auto idx = chcs.addQuery(accel_res.nonterm->certificate, trace.at(backlink).clause_idx);
        res->res.emplace_back(idx);
        ITSProof nonterm_proof;
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
            ITSProof acceleration_proof;
            acceleration_proof.storeSubProof(simp.getProof());
            acceleration_proof.ruleTransformationProof(*simp, "Loop Acceleration", accel_res.accel->rule);
            acceleration_proof.storeSubProof(accel_res.accel->proof);
            res.concat(acceleration_proof);
            res.concat(simplified.getProof());
            if (Config::Analysis::log) {
                std::cout << "accelerated rule, idx " << loop_idx << std::endl;
                ITSExport::printRule(*simplified, std::cout);
                std::cout << std::endl;
            }
        }
    }
    if (!res) {
        if (Config::Analysis::log) {
            std::cout << "acceleration failed, status: " << accel_res.status << std::endl;
        }
        return std::make_unique<Unroll>(1);
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
    const auto loop {build_loop(backlink)};
    luby_loop_count++;
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
    const auto learned_clauses {**accel_state};
    bool do_drop {drop || (backlink == trace.size() - 1  && learned_clauses.prefix == 0 && learned_clauses.period == 1)};
    if (do_drop) {
        drop_until(backlink);
    }
    bool done {!do_drop};
    if (Config::Analysis::log) {
        std::cout << "prefix: " << learned_clauses.prefix << ", period: " << learned_clauses.period << std::endl;
    }
    auto learned_lang {lang};
    if (Config::Analysis::safety()) {
        for (unsigned i = 1; i < learned_clauses.period; ++i) {
            redundancy->concat(learned_lang, lang);
        }
    }
    redundancy->transitive_closure(learned_lang);
    if (Config::Analysis::safety()) {
        for (unsigned i = 0; i < learned_clauses.prefix; ++i) {
            redundancy->prepend(lang, learned_lang);
        }
    }
    for (const auto idx: learned_clauses.res) {
        redundancy->set_language(idx, learned_lang);
        if (!done && store_step(idx, *idx, false)) {
            update_cpx();
            if (chcs.isSinkTransition(idx)) {
                return std::make_unique<ProvedUnsat>(accel_state->getProof());
            } else {
                done = true;
            }
        }
    }
    if (done) {
        redundancy->mark_as_redundant(learned_lang);
        return state;
    } else {
        // unroll once if we dropped the loop
        redundancy->concat(learned_lang, learned_lang);
        redundancy->mark_as_redundant(learned_lang);
        if (Config::Analysis::log) std::cout << "applying accelerated rule failed" << std::endl;
        return std::make_unique<Dropped>(accel_state->getProof());
    }
}

bool Reachability::try_to_finish() {
    std::set<TransIdx> clauses = trace.empty() ? chcs.getInitialTransitions() : chcs.getSuccessors(trace.back().clause_idx);
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

LinearSolver::Result Reachability::analysis_result_from(std::string res) const {
    if (res == "sat") {
        return LinearSolver::Result::Sat;
    } else if (res == "unsat") {
        return LinearSolver::Result::Unsat;
    } else if (res == "unknown") {
        return LinearSolver::Result::Unknown;
    } else if (res == "pending") {
        return LinearSolver::Result::Pending;           
    } else {
        throw std::logic_error("undefined analysis result");
    }       
}

LinearSolver::Result Reachability::get_analysis_result() const {
    return analysis_result;
}

void Reachability::analyze() {
    // TODO: are other preprocessing steps also unsound when in non-linear context? 
    const auto res {Preprocess::preprocess(chcs)};
    if (res) {
        proof.concat(res.getProof());
        if (Config::Analysis::log) {
            std::cout << "Simplified ITS" << std::endl;
            ITSExport::printForProof(chcs, std::cout);
        }
    }
    init();

    if (!try_to_finish()) {
        blocked_clauses[0].clear();
        derive_new_facts();
    }

    switch (get_analysis_result()) {
        case LinearSolver::Result::Sat:
            std::cout << "sat";
            break;
        case LinearSolver::Result::Unsat:
            std::cout << "unsat";
            break;
        case LinearSolver::Result::Unknown:
            std::cout << "unknown";
            break;
        case LinearSolver::Result::Pending:
            throw std::logic_error("exited main loop although analysis result is pending");
    }

    std::cout << std::endl << std::endl << std::endl;
}

/**
 * The resolvent of the entire current trace represents a fact,
 * that can be converted into a `Clause`. If the trace is empty,
 * this function returns nullopt.
 */
const std::optional<Clause> Reachability::trace_as_fact() {
    if (!incremental_mode) {
        // In non-incremental mode the trace resolvent is not really computed and only a dummy expression.
        // See `compute_resolvent` above. So `trace_as_fact` will silently return nonsense.
        throw std::logic_error("Calling `trace_as_fact` in non-incremental mode doesn't make sense.");
    }

    if (trace.empty()) {
        return {};
    } else {
        const Step step = trace.back();

        std::vector<BoolExpr> guard_conj = { step.resolvent.getGuard() };
        std::vector<Var> args_renamed;
        const auto subs = step.resolvent.getUpdate();

        for (const Var &var : chcs.getProgVars()) {
            auto it = subs.find(var);

            if (it == subs.end()) {
                args_renamed.push_back(var);
            } else {
                const auto optional_var = expr::toVar(expr::second(*it));

                if (optional_var.has_value()) {
                    args_renamed.push_back(optional_var.value());
                } else {
                    const auto new_var = expr::next(var);
                    args_renamed.push_back(new_var);
                    guard_conj.push_back(expr::mkEq(expr::toExpr(new_var), subs.get(var)));
                }
            }                   
        }

        const auto guard = BExpression::buildAnd(guard_conj);
        const auto rhs = FunApp(chcs.getRhsLoc(step.clause_idx), args_renamed);
        return Clause({}, rhs, guard);
    }
}

const std::list<Clause> Reachability::derive_new_facts() {
    static std::default_random_engine rnd {};

    std::list<Clause> derived_facts;

    while (true) {
        size_t next_restart = luby_unit * luby.second;
        std::unique_ptr<LearningState> state;
        if (Config::Analysis::log) std::cout << "trace: " << trace << std::endl;
        if (!trace.empty()) {
            // true by default, because if no case in the following for-loop applies, then we still want to add a new fact,
            // because we have a non-empty unseen trace.
            bool should_add_fact = true;

            // QUESTION: why not exit loop after frist matching case?
            for (auto backlink = has_looping_suffix(trace.size() - 1);
                 backlink && luby_loop_count < next_restart;
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
                    // if we run into `covered` we don't add a new fact, because backtrack to previously seen facts.
                    should_add_fact = false;
                } else if (state->succeeded()) {
                    if (simple_loop) {
                        block(step);
                    }
                    proof.majorProofStep("Accelerate", (*state->succeeded())->getProof(), chcs);
                    print_state();
                    if ((drop || simple_loop) && try_to_finish()) {
                        return derived_facts;
                    }

                    // if we just applied acceleration successfully, then the trace contains a new (more general) fact.
                    should_add_fact = true;
                } else if (state->dropped()) {
                    if (simple_loop && !Config::Analysis::safety()) {
                        block(step);
                    }
                    proof.majorProofStep("Accelerate and Drop", state->dropped()->get_proof(), chcs);
                    print_state();
                    // QUESTION: why shouldn't we add a fact in this case again?
                    should_add_fact = false;
                } else if (state->unsat()) {
                    proof.majorProofStep("Nonterm", **state->unsat(), chcs);
                    proof.headline("Step with " + std::to_string(trace.back().clause_idx->getId()));
                    print_state();
                    unsat();
                    return derived_facts;
                }
            }

            ////////////////////////////////////// TODO: refactor this ///////////////////////////////////////////////////////////
            if (incremental_mode && should_add_fact) {
                // Using a crude (additional) redundancy criterion for facts here. We identify facts by the trace that lead to them.
                // This is only sufficient because equivalent facts can have multiple traces. We don't need to memoize the entire                    
                // trace structure. It's enough to store clause_idx/implicant for each trace step.
                std::vector<std::pair<TransIdx, BoolExpr>> trace_id;
                for (const auto &step: trace) {
                    trace_id.push_back(std::make_pair(
                        step.clause_idx, 
                        step.implicant
                    ));
                }

                if (!seen_traces.contains(trace_id)) {
                    derived_facts.push_back(trace_as_fact().value());
                    seen_traces.insert(trace_id);
                }
            }

        }
        if (luby_loop_count == next_restart || (state && state->restart()) || !check_consistency()) {
            if (Config::Analysis::log) std::cout << "restarting after " << luby_loop_count << " loops" << std::endl;
            restart();
        }
        const auto try_set = trace.empty() ? chcs.getInitialTransitions() : chcs.getSuccessors(trace.back().clause_idx);
        std::vector<TransIdx> to_try(try_set.begin(), try_set.end());
        std::shuffle(to_try.begin(), to_try.end(), rnd);
        bool all_failed {true};
        for (const auto idx: to_try) {
            solver->push();
            const auto implicant {resolve(idx)};
            solver->pop();
            if (implicant && store_step(idx, *implicant, Config::Analysis::safety())) {
                proof.headline("Step with " + std::to_string(idx->getId()));
                print_state();
                update_cpx();
                all_failed = false;
                break;
            }
        }
        if (trace.empty()) {
            // TODO: is this the only place where we break out of the main loop with SAT?
            proof.headline("Accept");
            if (Config::Analysis::complexity()) {
                proof.result(cpx.toString());
                proof.print();
            } else {
                sat();
            }

            return derived_facts;
        } else if (all_failed) {
            backtrack();
            proof.headline("Backtrack");
            print_state();
        } else if (try_to_finish()) { // check whether a query is applicable after every step and, importantly, before acceleration (which might approximate)
            return derived_facts;
        }
    }
}

void Reachability::restart() {
    while (!trace.empty()) {
        pop();
    }
    luby_next();
    proof.headline("Restart");

    analysis_result = LinearSolver::Result::Pending;
}

void Reachability::add_clauses(const std::list<Clause> &clauses) {
    bool any_linear_clauses = false;
    for (const auto &chc : clauses) {
        chcs.addClause(chc);
        if (chc.isLinear()) {
            any_linear_clauses = true;
        }
    }

    if (any_linear_clauses) {
        chcs.refineDependencyGraph();
        // TODO: are other preprocessing steps also unsound when in non-linear context? 
        const auto res {Preprocess::preprocess(chcs)};
        if (res) {
            proof.concat(res.getProof());
            if (Config::Analysis::log) {
                std::cout << "Simplified ITS" << std::endl;
                ITSExport::printForProof(chcs, std::cout);
            }
        }
        init();

        // When we add a new linear clause we have to restart the solver,
        // i.e. reset the trace, otherwise we might block a potential reachability path.
        restart();
    }
}

const std::list<Clause> Reachability::get_initial_facts() const {     
    std::list<Clause> facts;    
    for (const auto trans_idx : chcs.getInitialTransitions()) {
        const Clause fact = chcs.clauseFrom(trans_idx);
        facts.push_back(fact);
    }
    return facts;
}

const std::list<Clause> Reachability::get_non_linear_chcs() const {
    return chcs.nonLinearCHCs;
}

void Reachability::analyze(ITSProblem &its) {
    Reachability(its, false).analyze();
}

}
