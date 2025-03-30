#pragma once

#include <memory>
#include <vector>
#include <tuple>
#include <iostream>
#include <functional>
#include <stdexcept>
#include <boost/functional/hash.hpp>
#include "conshash.hpp"

// ============================================
// Forward declarations for class dependencies
// ============================================
class LoatExpression;
class LoatConstant;
class LoatPlus;

// ============================================
// Smart pointer aliases for convenience
// ============================================
using LoatExprPtr = std::shared_ptr<const LoatExpression>;
using LoatExprVec = std::vector<LoatExprPtr>;

// ============================================
// Enum for expression types (for runtime type-checking)
// ============================================
enum class LoatKind
{
    Constant,
    Plus
    // More kinds (e.g., Mult, Mod, Var, ...) can be added later
};

// ============================================
// Abstract Base Class for all expressions
// ============================================
class LoatExpression : public std::enable_shared_from_this<LoatExpression>
{
    LoatKind kind;

protected:
    // Protected constructor: only derived classes can call it
    LoatExpression(LoatKind kind) : kind(kind) {}

public:
    virtual ~LoatExpression() = default;

    // Kind getter: allows dynamic checks of expression type
    LoatKind getKind() const { return kind; }

    // Readable string
    virtual std::string toString() const = 0;

    // Safely returns a shared_ptr to this
    LoatExprPtr toPtr() const { return shared_from_this(); }
};

// ============================================
// LoatConstant — represents a numeric constant
// ============================================
class LoatConstant : public LoatExpression
{
    int value;

public:
    LoatConstant(int v);
    ~LoatConstant();

    int getValue() const;
    std::string toString() const override;

    // === Caching Support using ConsHash ===

    struct CacheEqual
    {
        bool operator()(const std::tuple<int> &a, const std::tuple<int> &b) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<int> &a) const noexcept;
    };

    static ConsHash<LoatExpression, LoatConstant, CacheHash, CacheEqual, int> cache;
};

// ============================================
// LoatPlus — represents a sum of expressions
// ============================================
class LoatPlus : public LoatExpression
{
    LoatExprVec args;

public:
    LoatPlus(const LoatExprVec &arguments);
    ~LoatPlus();

    const LoatExprVec &getArgs() const;
    std::string toString() const override;

    // === Caching Support using ConsHash ===

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatExprVec> &a, const std::tuple<LoatExprVec> &b) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatExprVec> &a) const noexcept;
    };

    static ConsHash<LoatExpression, LoatPlus, CacheHash, CacheEqual, LoatExprVec> cache;
};

// ============================================
// Factory Functions
// ============================================

/**
 * Creates (or reuses) a constant expression using `ConsHash`.
 * Guarantees that each constant value exists only once.
 */
LoatExprPtr makeConst(int value);

/**
 * Creates (or reuses) a sum of two expressions using `ConsHash`.
 */
LoatExprPtr makePlus(const LoatExprPtr &a, const LoatExprPtr &b);

/**
 * Creates (or reuses) a sum of a vector of expressions.
 */
LoatExprPtr makePlus(const LoatExprVec &args);