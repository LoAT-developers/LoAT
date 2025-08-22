#include "renamingcentral.hpp"

RenamingCentral::RenamingCentral(const VarSet &vars) {
    for (const auto &x : vars) {
        theory::apply(
            x,
            [&](const auto x) {
                using T = decltype(theory::theory(x));
                auto pre {x};
                auto post {x};
                if (x->isPostVar()) {
                    pre = decltype(x)::element_type::progVar(x);
                } else {
                    post = decltype(x)::element_type::postVar(x);
                }
                m_pre_vars.insert(pre);
                m_post_to_pre.insert<T>(post, pre);
            }
        );
    }
}

const Renaming& RenamingCentral::get_subs(const unsigned start, const unsigned steps) {
    if (m_subs.empty()) {
        m_subs.push_back({Renaming()});
    }
    while (m_subs.size() < start + steps) {
        Renaming s;
        for (const auto &var : m_pre_vars) {
            if (theory::isProgVar(var)) {
                const auto post_var{theory::postVar(var)};
                s.insert(var, m_subs.back()[0].get(post_var));
                s.insert(post_var, theory::next(post_var));
            } else {
                s.insert(var, theory::next(var));
            }
        }
        m_subs.push_back({s});
    }
    auto &pre_vec{m_subs.at(start)};
    while (pre_vec.size() < steps) {
        auto &post{m_subs.at(start + pre_vec.size()).front()};
        Renaming s;
        for (const auto &var : m_pre_vars) {
            s.insert(var, pre_vec.front().get(var));
            if (theory::isProgVar(var)) {
                const auto post_var{theory::postVar(var)};
                s.insert(post_var, post.get(post_var));
            }
        }
        pre_vec.push_back(s);
    }
    return pre_vec.at(steps - 1);
}

const VarSet& RenamingCentral::pre_vars() const {
    return m_pre_vars;
}

const Renaming& RenamingCentral::post_to_pre() const {
    return m_post_to_pre;
}
