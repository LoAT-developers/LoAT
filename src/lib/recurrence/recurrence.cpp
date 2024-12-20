#include "recurrence.hpp"
#include "dependencyorder.hpp"
#include "arith.hpp"
#include "purrsutil.hpp"
#include "theory.hpp"

#include <purrs.hh>
#include <boost/algorithm/string.hpp>

Recurrence::Recurrence(const Subs &equations, const Arith::Var n):
    equations(equations), n(n) {}

bool Recurrence::solve(const Arith::Var lhs, const Arith::Expr rhs) {
    auto [updated, map] {arith::toPurrs(closed_form_pre.get<Arith>()(rhs), this->n)};
    updated = updated.substitute(map.left.at(this->n), Purrs::Recurrence::n);
    const auto vars {rhs->vars()};
    auto prefix {0u};
    Purrs::Expr closed_form;
    for (const auto &x: vars) {
        const auto it {prefixes.find(x)};
        if (it != prefixes.end()) {
            prefix = std::max(it->second, prefix);
        }
    }
    if (!vars.contains(lhs)) {
        ++prefix;
        closed_form = updated;
    } else {
        if (prefix > 0) {
            ++prefix;
        }
        auto last {Purrs::x(Purrs::Recurrence::n - 1)};
        Purrs::Recurrence rec {updated.substitute(map.left.at(lhs), last)};
        auto status {Purrs::Recurrence::Solver_Status::TOO_COMPLEX};
        try {
            status = rec.compute_exact_solution();
        } catch (...) {
            //purrs throws a runtime exception if the recurrence is too difficult
            return false;
        }
        if (status == Purrs::Recurrence::SUCCESS) {
            rec.exact_solution(closed_form);
            closed_form = closed_form.substitute(Purrs::x(0), map.left.at(lhs));
        } else {
            return false;
        }
    }
    prefixes.emplace(lhs, prefix);
    result.prefix = std::max(result.prefix, prefix);
    closed_form_pre.put<Arith>(lhs, arith::fromPurrs(closed_form.substitute(Purrs::Recurrence::n, map.left.at(this->n)-1), map));
    result.closed_form.put<Arith>(lhs, arith::fromPurrs(closed_form.substitute(Purrs::Recurrence::n, map.left.at(this->n)), map));
    return true;
}

bool Recurrence::solve(const Bools::Var &lhs, const Bools::Expr rhs) {
    const auto updated {closed_form_pre(rhs)};
    if (updated->lits().contains(bools::mk(lhs, true))) {
        return false;
    }
    const auto &vars {updated->vars()};
    if (vars.contains(lhs) && vars.size() != vars.get<Bools::Var>().size()) {
        return false;
    }
    unsigned prefix {1};
    for (const auto &x: vars) {
        const auto it {prefixes.find(x)};
        if (it != prefixes.end() && it->second >= prefix) {
            prefix = it->second + 1;
        }
    }
    prefixes.emplace(lhs, prefix);
    result.prefix = std::max(result.prefix, prefix);
    closed_form_pre.put<Bools>(lhs, updated);
    result.closed_form.put<Bools>(lhs, updated);
    return true;
}

bool Recurrence::solve() {
    const auto order {DependencyOrder::findOrder(equations)};
    if (!order) {
        return false;
    }
    for (const auto &lhs : *order) {
        const auto success {std::visit(
                [&](const auto lhs) {
                    const auto th {theory::theory(lhs)};
                    return solve(lhs, equations.get<decltype(th)>(lhs));
                }, lhs)
        };
        if (!success) {
            return false;
        }
    }
    return true;
}


std::optional<Recurrence::Result> Recurrence::solve(const Subs &update, const Arith::Var n) {
    Recurrence rec {update, n};
    if (rec.solve()) {
        return rec.result;
    } else {
        return {};
    }
}

void Recurrence::solve(const std::string &eq) {
    std::vector<std::string> strs;
    boost::split(strs, eq, boost::is_any_of("="));
    if (strs.size() != 2) {
        throw std::logic_error("equation must have the form lhs=rhs, where lhs is a variable");
    }
    const auto n {Purrs::Expr(Purrs::Recurrence::n).toGiNaC()};
    GiNaC::symtab table;
    table["n"] = n;
    GiNaC::parser parser{table};
    const GiNaC::ex lhs {parser(strs[0])};
    const GiNaC::ex rhs {parser(strs[1])};
    auto last {Purrs::x(Purrs::Recurrence::n - 1).toGiNaC()};
    Purrs::Recurrence rec {Purrs::Expr::fromGiNaC(rhs.subs({{lhs, last}}))};
    auto status {Purrs::Recurrence::Solver_Status::TOO_COMPLEX};
    try {
        status = rec.compute_exact_solution();
    } catch (...) {
    }
    if (status == Purrs::Recurrence::SUCCESS) {
        Purrs::Expr exact;
        rec.exact_solution(exact);
        std::cout << exact.toGiNaC() << std::endl;
    } else {
        std::cout << "failed  to solve recurrence" << std::endl;
    }
}
