#pragma once

#include <stddef.h>
#include <boost/core/ref.hpp>

template<size_t I = 0>
BOOST_FORCEINLINE decltype(auto) visit1(auto&& f, auto&& v)
{

    constexpr auto vs = std::variant_size_v<std::remove_cvref_t<decltype(v)>>;

#define _VISIT_CASE_CNT 2
#define _VISIT_CASE(Z, N, D) \
        case I + N:                                                                                 \
        {                                                                                           \
            if constexpr(I + N < vs)                                                                \
            {                                                                                       \
                return std::forward<decltype(f)>(f)(std::get<I + N>(std::forward<decltype(v)>(v)));              \
            }                                                                                       \
            else                                                                                    \
            {                                                                                       \
                BOOST_UNREACHABLE_RETURN(std::forward<decltype(f)>(f)(std::get<0>(std::forward<decltype(v)>(v))));   \
            }                                                                                       \
        }                                                                                           \
        /**/

    switch(v.index())
    {
        BOOST_PP_REPEAT(
            _VISIT_CASE_CNT,
            _VISIT_CASE, _)
    }

    constexpr auto next_idx = std::min(I + _VISIT_CASE_CNT, vs);

    // if constexpr(next_idx < vs) causes some weird msvc bug
    if constexpr(next_idx + 0 < vs)
    {
        return visit1<next_idx>(std::forward<decltype(f)>(f), std::forward<decltype(v)>(v));
    }

    BOOST_UNREACHABLE_RETURN(std::forward<decltype(f)>(f)(std::get<0>(std::forward<decltype(v)>(v))));

#undef _VISIT_CASE_CNT
#undef _VISIT_CASE
}