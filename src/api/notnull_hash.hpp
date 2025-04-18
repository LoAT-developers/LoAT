#pragma once

#include <memory>
#include <functional>
#include "notnull.hpp"

namespace std
{

    template <typename T>
    struct equal_to<cpp::not_null<std::shared_ptr<const T>>>
    {
        bool operator()(const cpp::not_null<std::shared_ptr<const T>> &lhs,
                        const cpp::not_null<std::shared_ptr<const T>> &rhs) const noexcept
        {
            return lhs.get() == rhs.get();
        }
    };

    template <typename T>
    struct hash<cpp::not_null<std::shared_ptr<const T>>>
    {
        size_t operator()(const cpp::not_null<std::shared_ptr<const T>> &ptr) const noexcept
        {
            return std::hash<const T *>()(ptr.get());
        }
    };

}