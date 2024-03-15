#pragma once

#include "notnull.hpp"

#include <unordered_map>
#include <memory>

template<class Abstract, class Concrete, class Hash, class Eq, class... Args>
class ConsHash {

protected:

    std::unordered_map<
        std::tuple<const Args...>,
        std::weak_ptr<const Abstract>,
        Hash,
        Eq> cache{};

public:

    const cpp::not_null<std::shared_ptr<const Abstract>> from_cache(const Args&... args) {
        const auto ce {std::make_tuple(args...)};
        const auto it {cache.find(ce)};
        if (it == cache.end() || it->second.expired()) {
            const auto res {std::make_shared<Concrete>(args...)};
            cache.insert_or_assign(ce, res);
            return cpp::assume_not_null(res);
        } else {
            return cpp::assume_not_null(it->second.lock());
        }
    }

};
