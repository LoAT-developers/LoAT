#include "cintegerexport.hpp"
#include "boolexpr.hpp"
#include <boost/algorithm/string.hpp>

namespace c_integer_export {

void doExport(ITSProblem its) {
    std::stringstream res;
    res << "typedef enum {false, true} bool;\n";
    res << "extern int __VERIFIER_nondet_int(void);\n";
    res << "int main() {\n";
    Subs pre_vars;
    VarMap<Var> post_vars;
    for (const auto &x: its.getVars()) {
        if (its.isTempVar(x)) throw std::invalid_argument("temp var");
        std::string name = x.get_name();
        boost::replace_all(name, "_", "");
        Var var = its.addFreshTemporaryVariable(name);
        pre_vars = pre_vars.compose(Subs(x, var));
        post_vars[x] = Var(var.get_name() + "post");
        res << "    int " << var << ";\n";
        res << "    int " << post_vars[x] << ";\n";
    }
    for (const auto &p: post_vars) {
        res << "    " << pre_vars.get(p.first) << " = __VERIFIER_nondet_int();\n";
    }
    bool found_loop = false;
    bool found_init = false;
    for (auto idx: its.getAllTransitions()) {
        const auto& rule = its.getRule(idx);
        if (rule.getLhsLoc() == its.getInitialLocation()) {
            if (rule.getGuard() != True) throw std::invalid_argument("guard != True");
            for (const auto& p: rule.getUpdate(0)) {
                if (!p.second.equals(p.first)) throw std::invalid_argument("non-trivial update");
            }
            if (found_init) throw std::invalid_argument("found_init");
            found_init = true;
        } else {
            if (!rule.isSimpleLoop()) throw std::invalid_argument("not a simple loop");
            if (found_loop) throw std::invalid_argument("found_loop");
            found_loop = true;
            std::stringstream cond;
            cond << rule.getGuard()->subs(pre_vars);
            std::string cond_str = cond.str();
            boost::replace_all(cond_str, "/\\", "&&");
            boost::replace_all(cond_str, "\\/", "||");
            res << "    while (" << cond_str << ") {\n";
            for (const auto& p: rule.getUpdate(0)) {
                res << "        " << post_vars[p.first] << " = " << p.second.subs(pre_vars) << ";\n";
            }
            for (const auto& p: rule.getUpdate(0)) {
                res << "        " << pre_vars.get(p.first) << " = " << post_vars[p.first] << ";\n";
            }
            res << "    }\n";
        }
    }
    res << "    return 0;\n";
    res << "}\n";
    std::cout << res.str() << std::endl;
}

}
