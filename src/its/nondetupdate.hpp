#pragma once

#include "expression.hpp"

class NondetUpdate {

    class LowerUpper {

    public:

        option<Expr> lower;
        option<Expr> upper;

        LowerUpper(const option<Expr> &lower, const option<Expr> upper);

        VarSet vars() const;

        void subs(const Subs &subs);

    };

public:

    class Entry {

        std::variant<Expr, LowerUpper> e;

    public:

        Entry(const Expr &e);

        Entry(const option<Expr> &lower, const option<Expr> &upper);

        VarSet vars() const;

        option<Expr> getLower() const;

        option<Expr> getUpper() const;

        bool isDeterministic() const;

        bool isLinear() const;

        bool isPoly() const;

        void subs(const Subs &subs);

    };

private:

    VarMap<Entry> map;

public:

    NondetUpdate();

    NondetUpdate(const Subs &subs);

    void put(const Var &x, const option<Expr> &l, const option<Expr> &u);

    void put(const Var &x, const Expr &e);

    option<Expr> getLower(const Var &x) const;

    option<Expr> getUpper(const Var &x) const;

    bool isDeterministic(const Var &x) const;

    bool isDeterministic() const;

    bool isLinear() const;

    bool isPoly() const;

    size_t size() const;

    bool contains(const Var &x) const;

    void compose(const Subs &subs);

    option<Subs> toSubs() const;

    VarMap<Entry>::iterator begin();

    VarMap<Entry>::iterator end();

    VarMap<Entry>::const_iterator begin() const;

    VarMap<Entry>::const_iterator end() const;

};
