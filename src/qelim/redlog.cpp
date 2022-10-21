#include <future>

#include "redlog.hpp"
#include "redlogparsevisitor.h"
#include "config.hpp"
#include "boolexpr.hpp"

RedProc initRedproc() {
    std::string path = std::getenv("PATH");
    std::replace(path.begin(), path.end(), ':', ' ');
    std::vector<std::string> array;
    std::stringstream ss(path);
    std::string temp;
    while (ss >> temp) array.push_back(temp);
    for (const std::string &p: array) {
        std::string redcsl = p + "/redcsl";
        std::ifstream file(redcsl);
        if (file.is_open()) {
            return RedProc_new(redcsl.c_str());
        }
    }
    throw std::invalid_argument("couldn't find redcsl binary");
}

RedProc Redlog::process() {
    static RedProc process = initRedproc();
    return process;
}

void Redlog::init() {
    if (Config::Qelim::useRedlog) {
        const char* cmd = "rlset r;";
        RedAns output = RedAns_new(process(), cmd);
        if (output->error) {
            RedProc_error(process(), cmd, output);
        }
        RedAns_delete(output);
    }
}

void Redlog::exit() {
    if (Config::Qelim::useRedlog) {
        RedProc_delete(process());
    }
}

option<Qelim::Result> Redlog::qe(const QuantifiedFormula<IntTheory> &qf) {
    Proof proof;
    const auto e = qf.simplify();
    const auto p = varMan.normalizeVariables(e);
    const auto normalized = p.first;
    const auto denormalization = p.second;
    if (normalized.isTiviallyTrue()) {
        proof.append("trivial");
        return Result(BoolExpression<IntTheory>::True, proof, true);
    } else if (normalized.isTiviallyFalse()) {
        proof.append("trivial");
        return Result(BoolExpression<IntTheory>::False, proof, true);
    }
    std::string command = "rlqe(" + normalized.toRedlog() + ");";
    auto qe = std::async([command]{return RedAns_new(process(), command.c_str());});
    if (qe.wait_for(std::chrono::milliseconds(1000)) != std::future_status::timeout) {
        RedAns output = qe.get();
        if (output->error) {
            RedProc_error(process(), command.c_str(), output);
            RedAns_delete(output);
        } else {
            std::string str = output->result;
            try {
                BExpr<IntTheory> res = RedlogParseVisitor::parse(str);
                RedAns_delete(output);
                proof.append("QE via Redlog");
                const auto e = res->simplify();
                return Result(e->subs(denormalization), proof, false);
            } catch (const std::invalid_argument &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }
    return {};
}
