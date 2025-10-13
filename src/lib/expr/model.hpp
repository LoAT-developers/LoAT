#pragma once

#include "subs.hpp"

class Model;

using ModelPtr = cpp::not_null<std::shared_ptr<Model>>;

class Model {

    friend std::ostream& operator<<(std::ostream&, const ModelPtr&);

public:
    virtual ~Model() = default;

    explicit Model(Subs);

    Arith::Const get(const Arith::Var&);
    Bools::Const get(const Bools::Var&);
    Arith::Const get(const Arrays<Arith>::Cell&);

    virtual void put(const Arith::Var&, const Arith::Const&) = 0;

    // virtual bool contains(const Arith::Var&) const = 0;
    // virtual bool contains(const Bools::Var&) const = 0;
    // virtual bool contains(const Arrays<Arith>::Var&) const = 0;

    bool contains(const Var&) const;

    bool eval(const Lit&);
    Bools::Const eval(const Bools::Expr&);
    Arith::Const eval(const Arith::Expr&);
    virtual Rational evalToRational(const Arith::Expr&) = 0;
    virtual ModelPtr withSubs(const Subs&) const = 0;

    Bools::Expr syntacticImplicant(const Bools::Expr&);

    ModelPtr composeBackwards(const Renaming&) const;
    ModelPtr composeBackwards(const Subs&) const;

    std::string toString(const VarSet&);

protected:

    virtual bool evalImpl(const Lit&) = 0;
    virtual Bools::Const evalImpl(const Bools::Expr&) = 0;
    Arith::Const evalImpl(const Arith::Expr&);
    virtual Arith::Const getImpl(const Arith::Var&) = 0;
    virtual Bools::Const getImpl(const Bools::Var&) = 0;
    virtual Arith::Const getImpl(const ArrayReadPtr<Arith>&) = 0;
    virtual std::string toString(const Expr&) = 0;

    Subs subs;

};
