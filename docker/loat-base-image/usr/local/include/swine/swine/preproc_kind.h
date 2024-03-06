#pragma once

#include <string>
#include <optional>
#include <unordered_set>

namespace swine {

enum class PreprocKind {
    ConstantFolding, Rewriting
};


namespace preproc_kind {

static const std::unordered_set<PreprocKind> values {PreprocKind::ConstantFolding, PreprocKind::Rewriting};

std::string str(const PreprocKind k);

}

std::ostream& operator<<(std::ostream &s, const PreprocKind kind);

}
