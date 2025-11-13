#include "smt.hpp"

LogicProperties get_properties(const Logic l) {
    LogicProperties res{};
    switch (l) {
    case Logic::QF_EA:
        res.is_poly = false;
        [[fallthrough]];
    case Logic::QF_NA:
        res.is_linear = false;
        [[fallthrough]];
    case Logic::QF_LA:
        break;
    case Logic::QF_AEA:
        res.is_poly = false;
        [[fallthrough]];
    case Logic::QF_ANA:
        res.is_linear = false;
        [[fallthrough]];
    case Logic::QF_ALA:
        res.no_arrays = false;
        break;
    }
    return res;
}

Logic from_properties(const LogicProperties& props) {
    if (props.is_linear) {
        return props.no_arrays ? Logic::QF_LA : Logic::QF_ALA;
    }
    if (props.is_poly) {
        return props.no_arrays ? Logic::QF_NA : Logic::QF_ANA;
    }
    return props.no_arrays ? Logic::QF_EA : Logic::QF_AEA;
}

Logic max(const std::initializer_list<Logic>& ls) {
    LogicProperties props {};
    for (const auto& l: ls) {
        if (!props.is_poly && !props.no_arrays) {
            break;
        }
        const auto [is_linear, is_poly, no_arrays] {get_properties(l)};
        props.is_linear &= is_linear;
        props.is_poly &= is_poly;
        props.no_arrays &= no_arrays;
    }
    return from_properties(props);
}

std::ostream& operator<<(std::ostream &s, const SmtResult &res) {
    switch (res) {
        case SmtResult::Sat: s << "sat";
        break;
        case SmtResult::Unsat: s << "unsat";
        break;
        case SmtResult::Unknown: s << "unknown";
        break;
    }
    return s;
}