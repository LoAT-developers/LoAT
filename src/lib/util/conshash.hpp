#pragma once

#include <unordered_map>
#include <memory>

template<class Abstract, class Concrete, class Hash, class Eq, class... Args>
class ConsHash {

protected:

    std::unordered_map<
        std::tuple<const Args...>,
        std::weak_ptr<const Abstract>,
        Hash,
        Eq> cache;

public:

    const std::shared_ptr<const Abstract> from_cache(const Args&... args) {
        const auto ce {std::make_tuple(args...)};
        const auto it {cache.find(ce)};
        if (it == cache.end() || it->second.expired()) { // TODO how can the pointer expired without getting erased?
            const std::shared_ptr<const Abstract> res {new Concrete(args...)};
            cache.emplace(ce, res);
            return res;
        } else {
            return it->second.lock();
        }
    }

    void erase(const Args&... args) {
        cache.erase(std::make_tuple(args...));
    }

};
