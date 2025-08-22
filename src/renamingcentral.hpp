#pragma once

#include <vector>

#include "renaming.hpp"

class RenamingCentral {

private:

    std::vector<std::vector<Renaming>> m_subs {};
    VarSet m_pre_vars {};
    Renaming m_post_to_pre;

public:

    RenamingCentral(const VarSet&);
    const Renaming& get_subs(const unsigned start, const unsigned steps = 1);
    const VarSet& pre_vars() const;
    const Renaming& post_to_pre() const;

};