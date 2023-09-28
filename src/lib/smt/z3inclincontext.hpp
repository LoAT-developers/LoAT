#pragma once

#include "z3context.hpp"

class Z3IncLinContext: public Z3Context {

    z3::func_decl exp;
    std::vector<z3::expr> exps;

    static z3::func_decl mkExp(z3::context& ctx);

public:

    Z3IncLinContext(z3::context& ctx);

    z3::expr pow(const z3::expr &base, const z3::expr &exp) override;
    z3::func_decl getExp() const;
    std::vector<z3::expr> clearExps();

};
