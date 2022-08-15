#ifndef YICES_HPP
#define YICES_HPP

#include "smt.hpp"
#include "yicescontext.hpp"
#include "config.hpp"

#include <mutex>

class Yices : public Smt {

public:
    Yices(const VariableManager &varMan, Logic logic);

    void add(const BoolExpr e) override;
    void push() override;
    void pop() override;
    Result check() override;
    Model model() override;
    void setTimeout(unsigned int timeout) override;
    void enableModels() override;
    void resetSolver() override;
    ~Yices() override;

    static void init();
    static void exit();

    std::ostream& print(std::ostream& os) const;

    std::pair<Result, BoolExprSet> _unsatCore(const BoolExprSet &assumptions) override;

private:
    unsigned int timeout = Config::Smt::DefaultTimeout;
    YicesContext ctx;
    const VariableManager &varMan;
    ctx_config_t *config;
    context_t *solver;

    static unsigned int running;
    static std::mutex mutex;


    GiNaC::numeric getRealFromModel(model_t *model, type_t symbol);

};

#endif // YICES_HPP
