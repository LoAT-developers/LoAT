#pragma once

#include "theory.hpp"
#include "boolexpr.hpp"
#include "model.hpp"

namespace smt {

extern const unsigned default_timeout;

}

enum class SmtResult {Sat, Unknown, Unsat};

std::ostream& operator<<(std::ostream &s, const SmtResult&);

enum class Logic {
    /**
     * linear arithmetic
     */
    QF_LA,
    /**
     * arrays & linear arithmetic
     */
    QF_ALA,
    /**
     * polynomial arithmetic
     */
    QF_NA,
    QF_ANA,
    /**
     * polynomial arithmetic + exponentials
     */
    QF_EA,
    QF_AEA};

struct LogicProperties {
    bool is_linear = true;
    bool is_poly = true;
    bool no_arrays = true;
};

LogicProperties get_properties(Logic);

Logic from_properties(const LogicProperties&);

Logic max(const std::initializer_list<Logic>&);

class Smt {

public:

    virtual void add(Bools::Expr e) = 0;

    void add(const Lit &e) {
        return this->add(bools::mkLit(e));
    }

    virtual void push() = 0;

    virtual void pop() = 0;

    virtual SmtResult check() = 0;
    virtual ModelPtr model() = 0;
    virtual void enableModels() = 0;
    virtual void resetSolver() = 0;

    virtual void randomize(unsigned seed) = 0;

    virtual ~Smt() = default;

    static Logic chooseLogic(const Bools::Expr &x, const std::optional<Subs> &up = std::nullopt) {
        const auto no_arrays = [](const VarSet& xs) {
            return std::ranges::all_of(xs.get<Arrays<Arith>::Var>(), [](const auto& x) {
                return x->dim() == 0;
            });
        };
        LogicProperties props {
            .is_linear = x->isLinear(),
            .is_poly = x->isPoly(),
            .no_arrays = no_arrays(x->vars())
        };
        if (up) {
            props.is_linear &= up->isLinear();
            props.is_poly &= up->isPoly();
            props.no_arrays &= no_arrays(up->vars());
        }
        return from_properties(props);
    }

    virtual std::ostream& print(std::ostream& os) const = 0;

};

using SmtPtr = std::unique_ptr<Smt>;
