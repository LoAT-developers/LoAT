#pragma once

#include "smt.hpp"
#include "swinecontext.hpp"

class Swine final : public Smt {

public:
    explicit Swine(const swine::Config& config = swine::Config());
    void add(Bools::Expr e) override;
    void push() override;
    void pop() override;
    SmtResult check() override;
    ModelPtr model() override;
    void enableModels() override;
    void resetSolver() override;
    ~Swine() override = default;
    std::ostream& print(std::ostream& os) const override;
    void randomize(unsigned seed) override;
    Lit abstract(const Lit& e);
    Expr abstract(const Expr& e);

private:

    z3::context z3ctx{};
    swine::Swine solver;
    SwineContext ctx;
    std::optional<ModelPtr> m;

    struct Frame {
        std::unordered_map<ArrayWritePtr<Arith>, Arrays<Arith>::Var> abstractions;
        Subs concretization;
        BoolExprSet assertions;
        linked_hash_set<std::vector<Arith::Expr>> indices;
    };

    std::vector<Frame> frames {{}};

    static Rational getRealFromModel(const z3::model &model, const z3::expr &symbol);

};
