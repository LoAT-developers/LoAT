#pragma once

#include <ostream>
#include <optional>
#include <functional>

template<class S>
std::ostream& operator<<(std::ostream &s, const std::optional<S> &o) {
    if (o) {
        return s << *o;
    } else {
        return s << "{}";
    }
}

template<class S, class T>
std::optional<T> map(const std::optional<S> &opt, const std::function<T(const S&)> f) {
    return opt ? f(*opt) : std::optional<T>();
}

template<class T>
std::optional<T> apply(const std::optional<T> &opt, const std::function<void(const T&)> f) {
    if (opt) f(*opt);
    return opt;
}

template<class S, class T>
std::optional<T> flat_map(const std::optional<S> &opt, const std::function<std::optional<T>(const S&)> f) {
    return opt ? f(*opt) : std::optional<T>();
}

template<class T>
std::optional<T> or_else(const std::optional<T> &opt, const std::function<std::optional<T>()> f) {
    return opt ? opt : f();
}
