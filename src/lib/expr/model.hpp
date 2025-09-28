#pragma once

#include "subs.hpp"
#include "valuation.hpp"

class Model;

using ModelPtr = std::shared_ptr<Model>;

class Model {

    friend std::ostream& operator<<(std::ostream&, const ModelPtr&);

public:
    virtual ~Model() = default;

    Model() = default;

    Arith::Const get(const Arith::Var&);
    Bools::Const get(const Bools::Var&);
    Arith::Const get(const Arrays<Arith>::Cell&);

    virtual void put(const Arith::Var&, const Arith::Const&) = 0;

    virtual bool contains(const Arith::Var&) const = 0;
    virtual bool contains(const Bools::Var&) const = 0;
    virtual bool contains(const Arrays<Arith>::Var&) const = 0;

    bool contains(const Var&) const;

    virtual bool eval(const Lit&) = 0;

    virtual Bools::Const eval(const Bools::Expr&) = 0;
    Arith::Const eval(const Arith::Expr&);
    virtual Rational evalToRational(const Arith::Expr&) = 0;
    virtual ModelPtr clone() const = 0;

    Bools::Expr syntacticImplicant(const Bools::Expr&);

    ModelPtr composeBackwards(const Renaming&) const;
    Valuation toValuation(const CellSet&) const;

    virtual void print(std::ostream&, const VarSet& = {}) const = 0;

protected:

    virtual Arith::Const getImpl(const Arith::Var&) = 0;
    virtual Bools::Const getImpl(const Bools::Var&) = 0;
    virtual Arith::Const getImpl(const ArrayReadPtr<Arith>&) = 0;

    Renaming renaming;

};

std::ostream& operator<<(std::ostream &s, const ModelPtr &e);
