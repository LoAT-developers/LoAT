#pragma once

#include "theory.hpp"
#include "subs.hpp"

class Model;

using ModelPtr = std::shared_ptr<Model>;

class Model {

public:
    virtual ~Model() = default;

private:

    friend std::ostream& operator<<(std::ostream &s, ModelPtr e);
    virtual void print(std::ostream &s) const = 0;

public:

    Model();
    explicit Model(const TheTheory::Model &m);
    ModelPtr unite(ModelPtr m) const;

    virtual Arith::Const get(const Arith::Var &var) const = 0;
    virtual Bools::Const get(const Bools::Var &var) const = 0;
    virtual Arith::Const get(const Arrays<Arith>::Var &var, const std::vector<Int> &indices) const = 0;

    virtual void put(const Arith::Var &var, Arith::Const) const = 0;

    virtual bool contains(const Arith::Var &var) const = 0;
    virtual bool contains(const Bools::Var &var) const = 0;
    virtual bool contains(const Arrays<Arith>::Var &var) const = 0;

    bool contains(const Var &var) const;

    virtual bool eval(const Lit &lit) const = 0;

    virtual Bools::Const eval(const Bools::Expr &e) const = 0;
    virtual Bools::Expr evalPartially(const Bools::Expr &e) const = 0;
    virtual Arith::Const eval(const Arith::Expr &e) const = 0;
    virtual Arith::Expr evalPartially(const Arith::Expr &e) const = 0;
    Rational evalToRational(const Arith::Expr& t) const;

    Bools::Expr syntacticImplicant(Bools::Expr e) const;
    virtual ModelPtr project(const VarSet &vars) const = 0;
    virtual ModelPtr project(const std::function<bool(const Var)> &p) const = 0;
    virtual ModelPtr erase(const Var&) const = 0;

private:

    typename TheTheory::Model m{};

};

std::ostream& operator<<(std::ostream &s, const Model &e);
