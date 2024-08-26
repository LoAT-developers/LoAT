#include "chcmodel.hpp"

sexpresso::Sexp CHCModel::to_smtlib() const {
    sexpresso::Sexp res;
    for (const auto &[sig, interp]: interpretations) {
        sexpresso::Sexp fun {"define-fun"};
        fun.addChild(sig.get_pred());
        const auto &args {sig.get_args()};
        { // bound variables
            sexpresso::Sexp decls;
            for (const auto &arg: args) {
                sexpresso::Sexp decl;
                decl.addChild(theory::getName(arg));
                decl.addChild(toString(theory::to_type(arg)));
                decls.addChild(decl);
            }
            fun.addChild(decls);
        }
        fun.addChild("Bool");
        sexpresso::Sexp body {interp->to_smtlib(theory::getName)};
        { // free variables
            sexpresso::Sexp decls;
            for (const auto &x: interp->vars()) {
                if (std::find(args.begin(), args.end(), x) == args.end()) {
                    sexpresso::Sexp decl;
                    decl.addChild(theory::getName(x));
                    decl.addChild(toString(theory::to_type(x)));
                    decls.addChild(decl);
                }
            }
            if (!decls.isNil()) {
                sexpresso::Sexp exists {"exists"};
                exists.addChild(decls);
                exists.addChild(body);
                body = exists;
            }
        }
        fun.addChild(body);
        res.addChild(fun);
    }
    return res;
}

std::ostream& operator<<(std::ostream &s, const CHCModel &m) {
    for (const auto &[sig,interp]: m.interpretations) {
        s << sig.get_pred();
        for (const auto &x: sig.get_args()) {
            s << " " << x;
        }
        s << " := " << interp << "\n";
    }
    return s;
}

void CHCModel::set_interpretation(const Lhs &f, const Bools::Expr interp) {
    interpretations.emplace(f, interp);
}
