#pragma once

#include "notnull.hpp"

#include <unordered_map>
#include <memory>

template<class T, class... Args>
class ConsHash {

    static_assert(!std::is_trivially_destructible_v<T>);

    std::unordered_map<
        std::tuple<const Args...>,
        std::weak_ptr<const T>,
        typename T::CacheHash,
        typename T::CacheEqual> cache{};

public:

    void erase(const Args&... args) {
        cache.erase(std::make_tuple(args...));
    }

    bool contains(const Args&... args) const {
        return cache.contains(std::make_tuple(args...));
    }

    cpp::not_null<std::shared_ptr<const T>> from_cache(const Args&&... args) {
        const auto [it,b] {cache.emplace(std::make_tuple(args...), std::weak_ptr<const T>())};
        if (b) {
            const auto res {std::make_shared<T>(args...)};
            it->second = res;
            return cpp::assume_not_null(res);
        }
        return cpp::assume_not_null(it->second.lock());
    }

    cpp::not_null<std::shared_ptr<const T>> from_cache(const Args&... args) {
        const auto [it,b] {cache.emplace(std::make_tuple(args...), std::weak_ptr<const T>())};
        if (b) {
            const auto res {std::make_shared<T>(args...)};
            it->second = res;
            return cpp::assume_not_null(res);
        }
        return cpp::assume_not_null(it->second.lock());
    }

};
