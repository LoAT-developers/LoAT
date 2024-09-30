#pragma once

#include "notnull.hpp"

#include <unordered_map>
#include <vector>
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

    size_t capacity;
    std::vector<Concrete*> pool;
    Concrete* next;

public:

    ConsHash(const size_t capacity): cache(capacity), capacity(capacity) {
        next = pool.emplace_back((Concrete*) malloc(capacity * sizeof(Concrete)));
    }

    ~ConsHash() {
        for (const auto &p: pool) {
            free(p);
        }
    }

    bool contains(const Args&... args) const {
        return cache.contains(std::make_tuple(args...));
    }

    const Ptr from_cache(const Args&&... args) {
        const auto [it,b] {cache.emplace(std::make_tuple(args...), nullptr)};
        if (b) {
            if (next == pool.back() + capacity) {
                next = pool.emplace_back((Concrete*) malloc(capacity * sizeof(Concrete)));
            }
            const auto *res {new (next) Concrete(args...)};
            it->second = res;
            ++next;
            return cpp::assume_not_null(res);
        }
        return cpp::assume_not_null(it->second);
    }

    const Ptr from_cache(const Args&... args) {
        const auto [it,b] {cache.emplace(std::make_tuple(args...), nullptr)};
        if (b) {
            if (next == pool.back() + capacity) {
                next = pool.emplace_back((Concrete*) malloc(capacity * sizeof(Concrete)));
            }
            const auto *res {new (next) Concrete(args...)};
            it->second = res;
            ++next;
            return cpp::assume_not_null(res);
        }
        return cpp::assume_not_null(it->second);
    }

};
