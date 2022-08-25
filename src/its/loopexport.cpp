#include "loopexport.hpp"
#include "result.hpp"
#include "preprocess.hpp"
#include "chainstrategy.hpp"
#include "export.hpp"
#include "yices.hpp"

namespace LoopExport {

void do_export(ITSProblem &its) {
    Yices::init();
    for (TransIdx idx : its.getAllTransitions()) {
        const Rule rule = its.getRule(idx);
        const Result<Rule> newRule = Preprocess::preprocessRule(its, rule);
        if (newRule) {
            its.replaceRules({idx}, {*newRule});
        }
    }
    Chaining::chainLinearPaths(its);
    for (TransIdx idx : its.getAllTransitions()) {
        const Rule rule = its.getRule(idx);
        if (!rule.isSimpleLoop() || !rule.isLinear() || rule.toLinear().isOctagon()) {
            its.removeRule(idx);
        } else {
            bool nondet = false;
            for (const auto &e: rule.getUpdate(0)) {
                for (const auto &x: e.second.vars()) {
                    if (its.isTempVar(x)) {
                        nondet = true;
                        goto DONE;
                    }
                }
            }
            DONE: if (!nondet) its.removeRule(idx);
        }
    }
    if (!its.getAllTransitions().empty()) {
        ITSExport::printKoAT(its, std::cout);
    }
    Yices::exit();
}

}
