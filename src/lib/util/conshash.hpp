#pragma once

#include "notnull.hpp"

#include <unordered_map>
#include <memory>

template<class Abstract, class Concrete, class Hash, class Eq, class... Args>
class ConsHash {

private:

    std::unordered_map<
        std::tuple<const Args...>,
        std::weak_ptr<const Abstract>,
        Hash,
        Eq> cache{};

public:

    void erase(const Args&... args) {
#ifdef LOAT_GC
        cache.erase(std::make_tuple(args...));
#endif
    }

    bool contains(const Args&... args) const {
        return cache.contains(std::make_tuple(args...));
    }

    const cpp::not_null<std::shared_ptr<const Abstract>> from_cache(const Args&&... args) {
        const auto [it,b] {cache.emplace(std::make_tuple(args...), std::weak_ptr<const Abstract>())};
        if (b) {
            const auto res {std::make_shared<Concrete>(args...)};
            it->second = res;
            return cpp::assume_not_null(res);
        }
        return cpp::assume_not_null(it->second.lock());
    }

    const cpp::not_null<std::shared_ptr<const Abstract>> from_cache(const Args&... args) {
        const auto [it,b] {cache.emplace(std::make_tuple(args...), std::weak_ptr<const Abstract>())};
        if (b) {
            const auto res {std::make_shared<Concrete>(args...)};
            it->second = res;
            return cpp::assume_not_null(res);
        }
        return cpp::assume_not_null(it->second.lock());
    }

};
