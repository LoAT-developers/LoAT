#include "Inline.hpp"
#include "theory.hpp"

#include <stack>
#include <utility>

#include "config.hpp"

Inline::Inline(CHCPtr chcs): chcs(std::move(chcs)) {
    init();
}

CHCPtr Inline::run() const {
    auto res = std::make_shared<CHCProblem>();
    std::stack<ClausePtr> todo;
    for (const auto& c: chcs->get_clauses()) {
        todo.push(c);
    }
    while (!todo.empty()) {
        const auto c = todo.top();
        if (c->is_linear()) {
            res->add_clause(c);
            todo.pop();
            continue;
        }
        auto changed = false;
        for (const auto& p: c->get_premise()) {
            if (non_recursive.contains(p->get_pred())) {
                const auto inlined = do_inline(c, p);
                todo.pop();
                for (const auto& i: inlined) {
                    todo.push(i);
                }
                changed = true;
            }
        }
        if (!changed) {
            res->add_clause(c);
            if (Config::Analysis::log) {
                std::cout << "failed to linearize\n" << c << std::endl;
            }
            todo.pop();
        }
    }
    return res;
}

void Inline::init() {
    graph.addNode("", {}, {}, false);
    graph.markSink("");
    for (const auto& c: chcs->get_clauses()) {
        const auto target = c->get_conclusion() ? c->get_conclusion()->get()->get_pred() : "";
        for (const auto& p: c->get_premise()) {
            graph.addEdge(p->get_pred(), target);
        }
    }
    std::cout << graph << std::endl;
    for (const auto& c: graph.getNodes()) {
        if (!graph.has_cycle(c)) {
            non_recursive.insert(c);
            std::cout << c << " is non-recursive" << std::endl;
        }
    }
}

std::pair<ClausePtr, std::vector<Var>> linearize_conclusion(const ClausePtr& c) {
    std::vector constraints {c->get_constraint()};
    const auto conclusion = c->get_conclusion().value();
    const auto old_args = conclusion->get_args();
    std::vector<Expr> args;
    std::vector<Var> arg_vars;
    for (const auto& arg: old_args) {
        theory::apply(
            arg,
            [&](const Bools::Expr& arg) {
                const auto var = BoolVar::next();
                const auto x = bools::mkLit(bools::mk(var));
                constraints.emplace_back(Bools::mkEq(arg, x));
                args.emplace_back(x);
                arg_vars.emplace_back(var);
            },
            [&](const Arith::Expr& arg) {
                const auto x = arrays::nextConst<Arith>();
                constraints.emplace_back(bools::mkLit(arith::mkEq(arg, x)));
                args.emplace_back(x);
                arg_vars.emplace_back(x->var());
            },
            [&](const Arrays<Arith>::Expr& arg) {
                const auto x = ArrayVar<Arith>::next(arg->dim());
                constraints.emplace_back(bools::mkLit(arrays::mkEq(arg, x)));
                args.emplace_back(x);
                arg_vars.emplace_back(x);
            });
    }
    const auto new_conclusion = FunApp::mk(conclusion->get_pred(), args);
    const auto res = Clause::mk(c->get_premise(), bools::mkAnd(constraints), new_conclusion);
    return std::pair{res, arg_vars};
}

ClausePtr rename_vars(const ClausePtr& c, const ClausePtr& other_c) {
    const auto c_vars = c->vars();
    const auto other_vars = other_c->vars();
    Renaming subs;
    for (const auto& x: other_vars) {
        if (c_vars.contains(x)) {
            theory::apply(
                x,
                [&](const auto& x) {
                    using Th = decltype(theory::theory(x));
                    subs.insert(x, Th::next(x->dim()));
                });
        }
    }
    return other_c->rename_vars(subs);
}

std::vector<ClausePtr> Inline::do_inline(const ClausePtr& c, const FunAppPtr& f) const {
    std::vector<ClausePtr> res;
    for (const auto& other_clause: chcs->get_clauses()) {
        if (const auto& conc = other_clause->get_conclusion()) {
            if (conc.value()->get_pred() == f->get_pred()) {
                const auto [linearized_clause, args] = linearize_conclusion(other_clause);
                const auto renamed_clause = rename_vars(c, linearized_clause);
                Subs matcher;
                const auto arity = args.size();
                for (size_t i = 0; i < arity; ++i) {
                    theory::apply(
                        f->get_args().at(i),
                        [&](const Arith::Expr& arg) {
                          matcher.put(std::get<ArrayVarPtr<Arith>>(args.at(i))->var(), arrays::writeConst(arg));
                        },
                        [&](const auto& arg) {
                            using Th = decltype(theory::theory(arg));
                            matcher.put(std::get<typename Th::Var>(args.at(i)), arg);
                        });
                }
                const auto matched_clause = renamed_clause->subs(matcher);
                const auto matched_premise = matched_clause->get_premise();
                auto new_premise {c->get_premise()};
                new_premise.insert(new_premise.end(), matched_premise.begin(), matched_premise.end());
                const auto new_constraint = c->get_constraint() && matched_clause->get_constraint();
                auto inlined = Clause::mk(new_premise, new_constraint, c->get_conclusion());
                res.emplace_back(inlined);
            }
        }
    }
    return res;
}
