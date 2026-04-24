#include "chcmodel.hpp"
#include "theory.hpp"

sexpresso::Sexp CHCModel::to_smtlib() const {
    sexpresso::Sexp res;
    for (const auto &[f, p]: interpretations) {
        const auto &[args, interp] {p};
        sexpresso::Sexp fun {"define-fun"};
        fun.addChild(f);
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
        sexpresso::Sexp body {interp->to_smtlib()};
        { // free variables
            sexpresso::Sexp decls;
            for (const auto &x: interp->vars()) {
                if (std::ranges::find(args, x) == args.end()) {
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
    for (const auto &[f,p]: m.interpretations) {
        const auto &[args, interp] {p};
        s << f;
        for (const auto &x: args) {
            s << " " << x;
        }
        s << " := " << interp << "\n";
    }
    return s;
}

void CHCModel::set_interpretation(const std::string &f, const std::vector<Var> &args, const Bools::Expr& interp) {
    interpretations.emplace(f, std::pair(args, interp));
}

linked_hash_map<std::string, std::pair<std::vector<Var>, Bools::Expr>> CHCModel::get_interpretations() const {
    return interpretations;
}
