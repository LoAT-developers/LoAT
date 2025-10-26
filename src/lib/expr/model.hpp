#pragma once

#include "subs.hpp"

class Model;

using ModelPtr = cpp::not_null<std::shared_ptr<Model>>;

class Model {

public:
    virtual ~Model() = default;

    explicit Model(Subs);

    Arith::Const get(const ArithVarPtr&);
    Bools::Const get(const Bools::Var&);

    void put(const ArithVarPtr&, const Arith::Const&);

    bool eval(const Lit&);
    Bools::Const eval(const Bools::Expr&);
    Arith::Const eval(const Arith::Expr&);
    Arith::Const eval(const ArrayReadPtr<Arith>&);
    Rational evalToRational(const Arith::Expr&);
    virtual ModelPtr withSubs(const Subs&) const = 0;

    Bools::Expr syntacticImplicant(const Bools::Expr&);

    ModelPtr composeBackwards(const Renaming&) const;
    ModelPtr composeBackwards(const Subs&) const;

    std::string toString(const VarSet&);

private:

    bool eval(const Lit&, const Subs&);
    Bools::Const eval(const Bools::Expr&, const Subs&);
    Arith::Const eval(const Arith::Expr&, const Subs&);
    Rational evalToRational(const Arith::Expr&, const Subs&);
    Arith::Const eval(const ArrayReadPtr<Arith>&, const Subs&);

protected:

    virtual bool evalImpl(const Lit&) = 0;
    virtual Bools::Const evalImpl(const Bools::Expr&) = 0;
    Arith::Const evalImpl(const Arith::Expr&);
    virtual Rational evalToRationalImpl(const Arith::Expr&) = 0;
    virtual Bools::Const getImpl(const Bools::Var&) = 0;
    virtual std::string toString(const Expr&) = 0;

    Subs subs;

};
