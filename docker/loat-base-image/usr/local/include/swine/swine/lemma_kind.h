#pragma once

#include <string>
#include <optional>
#include <unordered_set>

namespace swine {

enum class LemmaKind {
    Symmetry, Bounding, Interpolation, Monotonicity, Modulo
};


namespace lemma_kind {

static const std::unordered_set<LemmaKind> values {LemmaKind::Symmetry,
                                                  LemmaKind::Bounding,
                                                  LemmaKind::Interpolation,
                                                  LemmaKind::Monotonicity,
                                                  LemmaKind::Modulo};

std::string str(const LemmaKind k);

}

std::ostream& operator<<(std::ostream &s, const LemmaKind kind);

}
