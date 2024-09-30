#pragma once

#include "notnull.hpp"

#include <unordered_map>
#include <memory>

template<class Abstract, class Concrete, class Hash, class Eq, class... Args>
class ConsHash {

using Ptr = cpp::not_null<const Abstract*>;

private:

    std::unordered_map<
        std::tuple<const Args...>,
        const Abstract*,
        Hash,
        Eq> cache{};

public:

    ConsHash(const size_t capacity): cache(capacity) {}

    ~ConsHash() {
        for (const auto &[_,v]: cache) {
            delete v;
        }
    }

    bool contains(const Args&... args) const {
        return cache.contains(std::make_tuple(args...));
    }

    const Ptr from_cache(const Args&&... args) {
        const auto [it,b] {cache.emplace(std::make_tuple(args...), nullptr)};
        if (b) {
            const auto res {new Concrete(args...)};
            it->second = res;
            return cpp::assume_not_null(res);
        }
        return cpp::assume_not_null(it->second);
    }

    const Ptr from_cache(const Args&... args) {
        const auto [it,b] {cache.emplace(std::make_tuple(args...), nullptr)};
        if (b) {
            const auto res {new Concrete(args...)};
            it->second = res;
            return cpp::assume_not_null(res);
        }
        return cpp::assume_not_null(it->second);
    }

};
