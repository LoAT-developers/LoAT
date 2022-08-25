#include "recurrence.hpp"
#include "accelerationviaqe.hpp"
#include "accel.hpp"
#include "nondetupdate.hpp"
#include "yices.hpp"
#include "export.hpp"

void Accel::do_accel(ITSProblem &its) {
    Yices::init();
    for (const auto &idx: its.getAllTransitions()) {
        const auto rule = its.getRule(idx);
        if (rule.isSimpleLoop()) {
            ITSExport::printRule(rule, its, std::cout, false);
            std::cout << std::endl;
            option<Recurrence::Result<NondetUpdate>> rec = Recurrence::iterateRule(its, rule.toLinear());
            if (!rec) {
                std::cout << "failed (closed form)" << std::endl;
                continue;
            }
            const auto res = AccelerationViaQE(rule.toLinear(), *rec, its).computeRes();
            if (res.empty()) {
                std::cout << "failed (QE)" << std::endl;
                continue;
            }
            if (rec->inexact) {
                std::cout << "inexact (" << *rec->inexact << ")" << std::endl;
                continue;
            }
            bool exact = false;
            for (const auto &r: res) {
                if (r.exact) {
                    std::cout << "exact" << std::endl;
                    exact = true;
                    break;
                }
            }
            if (!exact) {
                std::cout << "inexact (QE) " << idx << std::endl;
            }
        }
    }
    Yices::exit();
}
