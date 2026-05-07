#pragma once

#include "notnull.hpp"

#include <unordered_map>

template<class T, class... Args>
class ConsHash {

    std::unordered_map<
        std::tuple<const Args...>,
        const T*,
        typename T::CacheHash,
        typename T::CacheEqual> cache{};

public:

    bool contains(const Args&... args) const {
        return cache.contains(std::make_tuple(args...));
    }

    cpp::not_null<const T*> from_cache(const Args&&... args) {
        const auto [it,b] {cache.emplace(std::make_tuple(args...), nullptr)};
        if (b) {
            const auto res = new T(args...);
            it->second = res;
        }
        return cpp::assume_not_null(it->second);
    }

    cpp::not_null<const T*> from_cache(const Args&... args) {
        const auto [it,b] {cache.emplace(std::make_tuple(args...), nullptr)};
        if (b) {
            const auto res = new T(args...);
            it->second = res;
        }
        return cpp::assume_not_null(it->second);
    }

};
