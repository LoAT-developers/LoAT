#include "recurrentset.hpp"

#include "formulapreprocessing.hpp"

Bools::Expr simplify(const FunAppPtr& p, const Bools::Expr& e) {
    const auto keep = p->vars();
    return Preprocess::preprocessFormula(e, [&](const auto& x) {
        return !keep.contains(x);
    });
}

FunAppPtr mk_template(const FunAppPtr& f) {
    std::vector<Expr> args;
    for (const auto &x: f->get_args()) {
        theory::apply(
            x, [&](const Arrays<Arith>::Expr &x) {
                args.emplace_back(Arrays<Arith>::next(x->dim()));
            },
            [&](const Bools::Expr &) {
                args.emplace_back(bools::mkLit(bools::mk(Bools::next(0))));
            },
            [&](const Arith::Expr &) {
                args.emplace_back(arrays::nextConst<Arith>());
            });
    }
    return FunApp::mk(f->get_pred(), args);
}

void RecurrentSet::add(const FunAppPtr &f, const BoolExprSet &b) {
    auto& [sig, rs] = get(f);
    const auto unif = FunApp::unify(f, sig);
    rs.insert(::simplify(sig, bools::mkAnd(b) && unif));
}

void RecurrentSet::add(const FunAppPtr &f, const Bools::Expr &b) {
    add(f, BoolExprSet{b});
}

void RecurrentSet::add(const ClausePtr &c) {
    clauses.insert(c);
}

std::pair<FunAppPtr, BoolExprSet>& RecurrentSet::get(const FunAppPtr &f) {
    return map.emplace(f->get_pred(), std::pair{mk_template(f), BoolExprSet()}).first->second;
}

void RecurrentSet::simplify() {
    for (auto &bs: map | std::views::values | std::views::values) {
        const auto b = Preprocess::simplifyOr(bools::mkOr(bs));
        bs.clear();
        bs.insert(b);
    }
}

sexpresso::Sexp RecurrentSet::to_certificate() const {
    sexpresso::Sexp res, recurrent_set;
    recurrent_set.addChild("recurrent-set");
    sexpresso::Sexp fun_defs;
    for (const auto &[f,b]: map | std::views::values) {
        sexpresso::Sexp fun_def;
        fun_def.addChild("define-fun");
        fun_def.addChild(f->get_pred());
        sexpresso::Sexp args;
        for (const auto& x: f->get_args()) {
            sexpresso::Sexp arg;
            arg.addChild(toString(x));
            arg.addChild(toString(theory::to_type(x)));
            args.addChild(arg);
        }
        fun_def.addChild(args);
        fun_def.addChild("Bool");
        fun_def.addChild(bools::mkOr(b)->to_smtlib());
        fun_defs.addChild(fun_def);
    }
    recurrent_set.addChild(fun_defs);
    res.addChild(recurrent_set);
    sexpresso::Sexp suc;
    suc.addChild("successor");
    sexpresso::Sexp successors;
    for (const auto& c: clauses) {
        assert(c->is_linear());
        if (c->is_fact()) {
            continue;
        }
        sexpresso::Sexp successor;
        successor.addChild("rule");
        successor.addChild(c->get_premise().front()->to_smtlib());
        successor.addChild(c->get_conclusion().value()->to_smtlib());
        if (c->get_constraint() != top()) {
            successor.addChild(":guard");
            successor.addChild(c->get_constraint()->to_smtlib());
        }
        successors.addChild(successor);
    }
    suc.addChild(successors);
    res.addChild(suc);
    return res;
}


std::ostream& operator<<(std::ostream & s, const RecurrentSet & res) {
    return s << res.to_certificate().toString();
};
