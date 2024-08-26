#pragma once

#include "itsproblem.hpp"
#include "sexpresso.hpp"

namespace sexpressionparser {

    class Parser {

    public:
        static ITSPtr loadFromFile(const std::string &filename);

    private:
        void run(const std::string &filename);

        void parseCond(sexpresso::Sexp &sexp, std::vector<Bools::Expr> &guard);

        Bools::Expr parseConstraint(sexpresso::Sexp &sexp, bool negate);

        Arith::Expr parseExpression(sexpresso::Sexp &sexp);

        std::vector<std::string> preVars {};
        std::vector<std::string> postVars {};
        std::unordered_map<std::string, LocationIdx> locations {};
        std::unordered_map<std::string, Arith::Var> vars {};
        ITSPtr res {std::make_shared<ITSProblem>()};

    };

}

