#pragma once

#include "lemma_kind.h"
#include "preproc_kind.h"

#include <unordered_set>

namespace swine {

class Config {

private:

    std::unordered_set<LemmaKind> active_lemma_kinds {lemma_kind::values};
    std::unordered_set<PreprocKind> active_preprocessings{preproc_kind::values};

public:

    bool validate_sat {false};
    std::optional<unsigned int> validate_unsat {};
    bool log {false};
    bool statistics {false};
    bool get_lemmas {false};
    bool debug {false};
    unsigned rlimit {0};

    void deactivate(const LemmaKind k);

    bool is_active(const LemmaKind k) const;

    void deactivate(const PreprocKind k);

    bool is_active(const PreprocKind k) const;

    void set_rlimit(unsigned rlimit);

};

}
