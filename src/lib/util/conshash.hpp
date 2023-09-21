#pragma once

#include <unordered_map>
#include <memory>

template<class Abstract, class Concrete, class Hash, class Eq, class... Args>
class ConsHash {

protected:

    std::unordered_map<
        std::tuple<const Args...>,
        std::shared_ptr<const Abstract>,
        Hash,
        Eq> cache;

public:

    const std::shared_ptr<const Abstract> from_cache(const Args&... args) {
        const auto ce {std::make_tuple(args...)};
        auto it {cache.find(ce)};
        if (it == cache.end()) {
            it = cache.emplace(ce, std::shared_ptr<const Abstract> {new Concrete(args...)}).first;
        }
        return it->second;
    }

};
