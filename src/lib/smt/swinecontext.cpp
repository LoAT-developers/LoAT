#include "swinecontext.hpp"

SwineContext::SwineContext(swine::Swine &solver): Z3Context(solver.get_ctx()), solver(solver) {}

z3::expr SwineContext::pow(const z3::expr &base, const z3::expr &exp) {
    return solver.get_exp()(base, exp);
}
