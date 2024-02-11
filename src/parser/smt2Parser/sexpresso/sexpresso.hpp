/* This file is part of LoAT.
 *
 * adapted version of https://github.com/BitPuffin/sexpresso
 *
 * Author: Isak Andersson 2016 bitpuffin dot com
 *
 * adapted by: Florian Frohn, 2019
 */

#ifndef LOAT_SEXPRESSO_H
#define LOAT_SEXPRESSO_H

#include <vector>
#include <string>
#include <cstdint>

namespace sexpresso {
	enum class SexpValueKind : uint8_t { SEXP, STRING };

	struct SexpArgumentIterator;

	struct Sexp {
		Sexp();
		explicit Sexp(std::string const& strval);
		explicit Sexp(std::vector<Sexp> const& sexpval);
        SexpValueKind kind {};
        struct { std::vector<Sexp> sexp {}; std::string str {}; } value {};
		auto addChild(Sexp sexp) -> void;
		auto addChild(std::string str) -> void;
		auto addChildUnescaped(std::string str) -> void;
		auto addExpression(std::string const& str) -> void;
		auto childCount() const -> size_t;
		auto operator[](size_t idx) -> Sexp&;
		auto getChild(size_t idx) -> Sexp&; // Call only if Sexp is a Sexp
		auto str() -> std::string&;
		auto getChildByPath(std::string const& path) -> Sexp*; // unsafe! careful to not have the result pointer outlive the scope of the Sexp object
		auto createPath(std::vector<std::string> const& path) -> Sexp&;
		auto createPath(std::string const& path) -> Sexp&;
		auto toString() const -> std::string;
		auto isString() const -> bool;
		auto isSexp() const -> bool;
		auto isNil() const -> bool;
		auto equal(Sexp const& other) const -> bool;
		auto arguments() -> SexpArgumentIterator;
		static auto unescaped(std::string strval) -> Sexp;
	};

	auto parse(std::string const& str, std::string& err) -> Sexp;
	auto parse(std::string const& str) -> Sexp;
	auto escape(std::string const& str) -> std::string;

	struct SexpArgumentIterator {
		explicit SexpArgumentIterator(Sexp& sexp);
        Sexp& sexp;

		using iterator = std::vector<Sexp>::iterator;
		using const_iterator = std::vector<Sexp>::const_iterator;

		auto begin() -> iterator;
		auto end() -> iterator;
		auto begin() const -> const_iterator;
		auto end() const -> const_iterator;
		auto size() const -> size_t;
		auto empty() const -> bool;
	};
}

#endif //LOAT_SEXPRESSO_H
