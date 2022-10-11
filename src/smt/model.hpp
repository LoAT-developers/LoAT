#pragma once

#include "theory.hpp"
#include "subs.hpp"

class Model
{
public:

    Model();
    Model(const TheTheory::Model &m);

    template <ITheory Th>
    typename Th::Val get(const typename Th::Var &var) const {
        return std::get<std::map<typename Th::Var, typename Th::Val>>(m).at(var);
    }

    template <ITheory Th>
    bool contains(const typename Th::Var &var) const {
        const auto &map = std::get<std::map<typename Th::Var, typename Th::Val>>(m);
        return map.find(var) != map.end();
    }

private:

    template<std::size_t I = 0>
    void _toSubs(Subs &subs) const {
        if constexpr (I < std::tuple_size_v<Theories>) {
            const auto map = std::get<I>(m);
            for (const auto &p: map) {
                if constexpr (std::is_same_v<std::tuple_element_t<I, Theories>, BoolTheory>) {
                    subs.put(p.first, p.second ? True : False);
                } else {
                    subs.put<std::tuple_element_t<I, Theories>>(p.first, p.second);
                }
            }
            _toSubs<I+1>(subs);
        }
    }

public:

    Subs toSubs() const {
        Subs res;
        _toSubs(res);
        return res;
    }

    friend std::ostream& operator<<(std::ostream &s, const Model &e);

private:

    const TheTheory::Model m;

};
