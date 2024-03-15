/*****************************************************************************
 * \file not_null.hpp
 *
 * \brief This header defines a utility for asserting semantic correctness
 *        of non-nullable pointer types
 *****************************************************************************/

/*
  The MIT License (MIT)

  Copyright (c) 2019 Matthew Rodusek All rights reserved.

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/
#ifndef CPP_BITWIZESHIFT_NOT_NULL_HPP
#define CPP_BITWIZESHIFT_NOT_NULL_HPP

#include <cstddef>     // std::nullptr_t
#include <utility>     // std::forward, std::move
#include <type_traits> // std::decay_t
#include <memory>      // std::pointer_traits
#if !defined(NOT_NULL_DISABLE_EXCEPTIONS)
# include <stdexcept> // std::logic_error
#else
# include <cstdio>  // std::printf
# include <cstdlib> // std::abort
#endif

#if __cplusplus >= 201402L
# define NOT_NULL_CPP14_CONSTEXPR constexpr
#else
# define NOT_NULL_CPP14_CONSTEXPR
#endif

#if defined(__clang__) || defined(__GNUC__)
# define NOT_NULL_INLINE_VISIBILITY __attribute__((visibility("hidden"), always_inline))
#elif defined(_MSC_VER)
# define NOT_NULL_INLINE_VISIBILITY __forceinline
#else
# define NOT_NULL_INLINE_VISIBILITY
#endif

#if defined(NOT_NULL_NAMESPACE)
# define NOT_NULL_NAMESPACE_INTERNAL NOT_NULL_NAMESPACE
#else
# define NOT_NULL_NAMESPACE_INTERNAL cpp
#endif
#define NOT_NULL_NS_IMPL NOT_NULL_NAMESPACE_INTERNAL::bitwizeshift

namespace NOT_NULL_NAMESPACE_INTERNAL {
inline namespace bitwizeshift {

  template <typename T>
  class not_null;

  //===========================================================================
  // trait : is_not_null
  //===========================================================================

  template <typename T>
  struct is_not_null : std::false_type{};
  template <typename T>
  struct is_not_null<not_null<T>> : std::true_type{};

#if !defined(NOT_NULL_DISABLE_EXCEPTIONS)

  //===========================================================================
  // class : null_pointer_error
  //===========================================================================

  /////////////////////////////////////////////////////////////////////////////
  /// \brief An exception thrown on null contract violations as part of
  ///        check_not_null
  /////////////////////////////////////////////////////////////////////////////
  class not_null_contract_violation : public std::logic_error
  {
    using this_type = not_null_contract_violation;
  public:

    not_null_contract_violation();
    not_null_contract_violation(const this_type& other) = default;
    not_null_contract_violation(this_type&& other) = default;

    auto operator=(const this_type& other) -> this_type& = default;
    auto operator=(this_type&& other) -> this_type& = default;
  };

#endif


  //===========================================================================
  // utilities : constexpr forward
  //===========================================================================

  // std::forward is not constexpr until C++14
  namespace detail {
    template <typename T>
    inline NOT_NULL_INLINE_VISIBILITY constexpr
    auto not_null_forward(typename std::remove_reference<T>::type& t)
      noexcept -> T&&
    {
      return static_cast<T&&>(t);
    }

    template <typename T>
    inline NOT_NULL_INLINE_VISIBILITY constexpr
    auto not_null_forward(typename std::remove_reference<T>::type&& t)
      noexcept -> T&&
    {
      return static_cast<T&&>(t);
    }
  } // namespace detail

  //===========================================================================
  // detail utilities : not_null
  //===========================================================================

  namespace detail {
    /// \{
    /// \brief Recursively calls `operator->()` on `p` until a raw pointer is
    ///        retrieved
    ///
    /// \param p the pointer-like type
    /// \return the underlying raw pointer
    template <typename U>
    constexpr auto not_null_to_address(U* p)
      noexcept -> U*;

    // MSVC does not accept an out-of-line definition of a recursive
    // trailing-return-type definition like this, but it accepts it when
    // inline.
    template <typename Ptr>
    constexpr auto not_null_to_address(const Ptr& p)
      noexcept -> decltype(not_null_to_address(p.operator->()))
    {
#if __cplusplus >= 202002L
      return std::to_address(p);
#else
      return not_null_to_address(p.operator->());
#endif
    }
    /// \}

    /// \brief Throws a not_null_contract_violation in exception mode
    [[noreturn]] auto throw_null_pointer_error() -> void;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief A private type that exists to construct no_null's using the
    ///        private constructor (through friendship)
    ///////////////////////////////////////////////////////////////////////////
    struct not_null_factory
    {
      template <typename T>
      static constexpr auto make(T&& p) -> not_null<typename std::decay<T>::type>;
    };

    /// \brief Hint to the compiler that the pointer \p p can never be null
    ///
    /// \param p the pointer that can never be null
    /// \return \p p
    template <typename T>
#if defined(__GNUC__) || defined(__clang__)
      [[gnu::returns_nonnull]]
#endif
    constexpr auto mark_nonnull(T* p) noexcept -> T*;

    template <typename T, typename U>
    struct not_null_is_explicit_convertible : std::integral_constant<bool,(
      std::is_constructible<T,U>::value &&
      !std::is_convertible<U,T>::value
    )>{};

    template <typename T, typename U>
    struct not_null_is_implicit_convertible : std::integral_constant<bool,(
      std::is_constructible<T,U>::value &&
      std::is_convertible<U,T>::value
    )>{};

  } // namespace detail

  //===========================================================================
  // class : not_null
  //===========================================================================

  /////////////////////////////////////////////////////////////////////////////
  /// \brief A wrapper type around a pointer to disallow null assignments
  ///
  /// This type can only be used with pointers that may be understood by
  /// std::pointer_traits. This requires a type to either define 'element_type'
  /// or specialize pointer_traits for their respective needs.
  ///
  /// This type is a type-wrapper, so that APIs can semantically indicate their
  /// nullability requirement in a concise and coherent way.
  ///
  /// ### Examples
  ///
  /// Basic Usage:
  ///
  /// ```cpp
  /// auto post(not_null<std::unique_ptr<Task>> task) -> void
  /// {
  ///   // pass to internal API that uses 'unique_ptr' directly
  ///   post_internal(std::move(task).as_nullable());
  /// }
  ///
  /// ...
  ///
  /// post(assume_not_null(std::move(p)));
  /// ````
  ///
  /// \tparam T the underlying pointer type
  /////////////////////////////////////////////////////////////////////////////
  template <typename T>
  class not_null
  {
    static_assert(
      !std::is_reference<T>::value,
      "not_null<T&> is ill-formed. "
      "not_null may only work with non-CV qualified value types."
    );
    static_assert(
      !std::is_void<T>::value,
      "not_null<void> is ill-formed. "
      "not_null may only work with non-CV qualified value types."
    );
    static_assert(
      std::is_assignable<T&, std::nullptr_t>::value &&
      std::is_constructible<T, std::nullptr_t>::value,
      "T must satisfy NullablePointer, otherwise not_null<T> is ill-formed."
    );
    static_assert(
      !std::is_same<T,std::nullptr_t>::value,
      "not_null<std::nullptr_t> is ill-formed. I mean, really, come on."
    );
    static_assert(
      !is_not_null<T>::value,
      "not_null<not_null<T>> is ill-formed."
    );
    static_assert(
      !std::is_const<T>::value && !std::is_volatile<T>::value,
      "not_null<[const] [volatile] T> is ill-formed. "
      "not_null may only work with non-CV qualified value types."
    );

    //-------------------------------------------------------------------------
    // Public Member Types
    //-------------------------------------------------------------------------
  public:

    using element_type = typename std::pointer_traits<T>::element_type;
    using pointer      = element_type*;
    using reference    = typename std::add_lvalue_reference<element_type>::type;

    //-------------------------------------------------------------------------
    // Constructors / Assignment
    //-------------------------------------------------------------------------
  public:

    // not_null is not default-constructible, since this would result in a null
    // value
    not_null() = delete;

    /// \{
    /// \brief Constructs a not_null by converting a not_null from a different
    ///        underlying source
    ///
    /// This constructor allows for conversions between different underlying
    /// pointer types
    ///
    /// \note This constructor only participates in overload resolution if
    ///       `std::is_constructible<T,const U&>::value` is `true`
    ///
    /// \note This constructor is explicit if and only if
    ///       `std::is_convertible<const U&, T>::value` is `false`
    ///
    /// ### Examples
    ///
    /// Implicit use:
    ///
    /// ```cpp
    /// auto p = assume_not_null(
    ///     std::make_shared<Derived>(42)
    /// );
    /// not_null<std::shared_ptr<Base>> q = p;
    ///
    /// assert(p == q);
    /// ```
    ///
    /// Explicit Use:
    ///
    /// ```cpp
    /// // Uses 'p' to construct the underlying unique_ptr
    /// auto p = assume_not_null(
    ///     new int{42}
    /// );
    /// auto q = not_null<std::unique_ptr<int>>{p};
    ///
    /// assert(p == q);
    /// ```
    ///
    /// \param other the other not_null to convert
    template <typename U,
              typename std::enable_if<detail::not_null_is_implicit_convertible<T,const U&>::value,int>::type = 0>
    not_null(const not_null<U>& other)
      noexcept(std::is_nothrow_constructible<T,const U&>::value);
    template <typename U,
              typename std::enable_if<detail::not_null_is_explicit_convertible<T,const U&>::value,int>::type = 0>
    explicit not_null(const not_null<U>& other)
      noexcept(std::is_nothrow_constructible<T,const U&>::value);
    /// \}

    /// \{
    /// \brief Constructs a not_null by converting a not_null from a different
    ///        underlying source
    ///
    /// This constructor allows for conversions between different underlying
    /// pointer types
    ///
    /// \note This constructor only participates in overload resolution if
    ///       `std::is_constructible<T,U&&>::value` is `true`
    ///
    /// \note This constructor is explicit if and only if
    ///       `std::is_convertible<U&&, T>::value` is `false`
    ///
    /// ### Examples
    ///
    /// Implicit Use:
    ///
    /// ```cpp
    /// auto p = assume_not_null(
    ///     std::make_shared<Derived>(42)
    /// );
    /// not_null<std::shared_ptr<Base>> q = std::move(p);
    /// ```
    ///
    /// Explicit Use:
    ///
    /// ```cpp
    /// auto p = assume_not_null(
    ///     std::make_unique<int>(42)
    /// );
    /// auto q = not_null<std::shared_ptr<int>>{
    ///     std::move(p)
    /// };
    /// ```
    ///
    /// \param other the other not_null to convert
    template <typename U,
              typename std::enable_if<detail::not_null_is_implicit_convertible<T,U&&>::value,int>::type = 0>
    not_null(not_null<U>&& other)
      noexcept(std::is_nothrow_constructible<T,U&&>::value);
    template <typename U,
              typename std::enable_if<detail::not_null_is_explicit_convertible<T,U&&>::value,int>::type = 0>
    explicit not_null(not_null<U>&& other)
      noexcept(std::is_nothrow_constructible<T,U&&>::value);
    /// \}

    /// \brief Constructs this not_null by copying the contents of \p other
    ///
    /// \note This constructor does not paticipate in overload resolution
    ///       unless `std::is_copy_constructible<T>::value` is `true`
    ///
    /// \note This constructor is trivial if the underlying type `T`'s
    ///       copy constructor is trivial.
    ///
    /// \param other the other not_null to copy from
    not_null(const not_null& other) = default;

    /// \brief Constructs this not_null by moving the contents of \p other
    ///
    /// \note This constructor does not paticipate in overload resolution
    ///       unless `std::is_move_constructible<T>::value` is `true`
    ///
    /// \note This constructor is trivial if the underlying type `T`'s
    ///       copy constructor is trivial.
    ///
    /// \param other the other not_null to move from
    not_null(not_null&& other) = default;

    //-------------------------------------------------------------------------

    template <typename U,
              typename = typename std::enable_if<std::is_assignable<T&,const U&>::value>::type>
    NOT_NULL_CPP14_CONSTEXPR
    auto operator=(const not_null<U>& other)
      noexcept(std::is_nothrow_assignable<T&,const U&>::value) -> not_null&;

    template <typename U,
              typename = typename std::enable_if<std::is_assignable<T&,U&&>::value>::type>
    NOT_NULL_CPP14_CONSTEXPR
    auto operator=(not_null<U>&& other)
      noexcept(std::is_nothrow_assignable<T&,U&&>::value) -> not_null&;

    auto operator=(const not_null& other) -> not_null& = default;

    auto operator=(not_null&& other) -> not_null& = default;

    //-------------------------------------------------------------------------
    // Observers
    //-------------------------------------------------------------------------
  public:

    /// \brief Gets the underlying pointer
    ///
    /// \return the underlying pointer
    constexpr auto get() const noexcept -> pointer;

    /// \brief Contextually convertible to bool
    ///
    /// This is always true
    constexpr explicit operator bool() const noexcept;

    //-------------------------------------------------------------------------

    /// \{
    /// \brief Extracts the underlying nullable pointer from not_null
    ///
    /// \note The r-value overload allows for stealing the underlying nullable
    ///       pointer. In doing so, the invariant of this class may
    ///       intentionally be violated (subject to the underlying pointer).
    ///       Care needs to be taken to avoid potentially reusing this not_null
    ///       after moving. Realistically, using a pointer after moving is
    ///       already a bad idea anyway since it may result in use-after-move.
    ///
    /// \return the underlying nullable pointer
    constexpr auto as_nullable() const & noexcept -> const T&;
    NOT_NULL_CPP14_CONSTEXPR auto as_nullable() && noexcept -> T&&;
    /// \}

    //-------------------------------------------------------------------------

    /// \brief Dereferences the underlying pointer
    ///
    /// \return the underlying pointer
    constexpr auto operator->() const noexcept -> pointer;

    /// \brief Dereferences the underlying pointer
    ///
    /// \return reference to the underlying pointer
    constexpr auto operator*() const noexcept -> reference;

    //-------------------------------------------------------------------------
    // Deleted Operators
    //-------------------------------------------------------------------------

    // If you get an error here, it's because you're doing something you
    // shouldn't be with `not_null`. Don't do that thing.
    auto operator++() -> void = delete;
    auto operator--() -> void = delete;
    auto operator++(int) -> void = delete;
    auto operator--(int) -> void = delete;
    auto operator+=(std::ptrdiff_t) -> void = delete;
    auto operator-=(std::ptrdiff_t) -> void= delete;
    auto operator[](std::ptrdiff_t) const -> void = delete;

    //-------------------------------------------------------------------------
    // Private Members
    //-------------------------------------------------------------------------
  private:

    T m_pointer;

    //-------------------------------------------------------------------------
    // Private Constructors
    //-------------------------------------------------------------------------
  private:

    struct ctor_tag{};

    template <typename P>
    constexpr not_null(ctor_tag, P&& ptr)
      noexcept(std::is_nothrow_constructible<typename std::decay<P>::type,P>::value);

    friend detail::not_null_factory;
  };

  //===========================================================================
  // non-member functions : class : not_null
  //===========================================================================

  //---------------------------------------------------------------------------
  // Utilities
  //---------------------------------------------------------------------------

  /// \brief Creates a `not_null` object by checking that `ptr` is not null
  ///        first
  ///
  /// If `NOT_NULL_DISABLE_EXCEPTIONS` is defined, this function will print to
  /// `stderr` and trigger a `SIGABRT`; otherwise this function throws an
  /// exception. The `not_null_contract_violation` exception thrown is not
  /// intended to be caught and handled in most workflows; rather this is meant
  /// as a simple way to tear-down an application placed into an undesirable
  /// state through the use of stack-unwinding.
  ///
  /// `check_not_null` contains the overhead of checking for null first, but
  /// is opt-in. If a type is known to never be null, consider `assume_not_null`
  /// below.
  ///
  /// ### Examples
  ///
  /// Basic use:
  ///
  /// ```cpp
  /// // Adapting legacy API
  /// auto consume_impl(not_null<std::unique_ptr<Widget>>) -> void;
  ///
  /// auto consume(std::unique_ptr<Widget> p) -> void
  /// {
  ///     // Expect this invariant in our code; crash if not.
  ///     consume_impl(check_not_null(std::move(p));
  /// }
  ///
  /// ```
  ///
  /// \throw not_null_contract_violation if `ptr == nullptr`
  /// \param ptr the pointer to check for nullability first
  /// \return a `not_null` object containing `ptr`
  template <typename T>
  constexpr auto check_not_null(T&& ptr)
    -> not_null<typename std::decay<T>::type>;

  /// \brief Creates a `not_null` object by *assuming* that `ptr` is not null
  ///
  /// Since this function does no proper checking, it is up to the user to
  /// guarantee that `ptr` does not violate the invariant. If the invariant is
  /// *not* upheld, the user may experience **undefined behavior** due to
  /// potential null pointer dereferences, and due to other code assuming nulls
  /// can never happen.
  ///
  /// This function should only be used in cases where it can be guaranteed that
  /// `ptr` can never be null, such as for an object's invariant, or when
  /// using `not_null` with already known non-null objects.
  ///
  /// ### Examples
  ///
  /// Basic use:
  ///
  /// ```cpp
  /// auto x = 5;
  /// auto nn = assume_not_null(&x); // we know 'x' cannot be null
  ///
  /// assert(nn == &x);
  /// ```
  ///
  /// or
  ///
  /// ```cpp
  /// // 'make_shared' never returns null
  /// auto p = assume_not_null(
  ///   std::make_shared<int>(42)
  /// );
  ///
  /// consume_not_null(std::move(p));
  /// ```
  ///
  /// \param ptr the pointer that cannot be null
  /// \return a not_null containing the pointer
  template <typename T>
  constexpr auto assume_not_null(T&& ptr)
    noexcept(std::is_nothrow_constructible<typename std::decay<T>::type,T>::value)
    -> not_null<typename std::decay<T>::type>;

  //---------------------------------------------------------------------------
  // Comparisons
  //---------------------------------------------------------------------------

  template <typename T>
  constexpr auto operator==(const not_null<T>& lhs, std::nullptr_t) noexcept -> bool;
  template <typename T>
  constexpr auto operator==(std::nullptr_t, const not_null<T>& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() == std::declval<const U&>())>
  constexpr auto operator==(const not_null<T>& lhs, const not_null<U>& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() == std::declval<const U&>())>
  constexpr auto operator==(const not_null<T>& lhs, const U& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() == std::declval<const U&>())>
  constexpr auto operator==(const T& lhs, const not_null<U>& rhs) noexcept -> bool;

  template <typename T>
  constexpr auto operator!=(const not_null<T>& lhs, std::nullptr_t) noexcept -> bool;
  template <typename T>
  constexpr auto operator!=(std::nullptr_t, const not_null<T>& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() != std::declval<const U&>())>
  constexpr auto operator!=(const not_null<T>& lhs, const not_null<U>& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() != std::declval<const U&>())>
  constexpr auto operator!=(const not_null<T>& lhs, const U& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() != std::declval<const U&>())>
  constexpr auto operator!=(const T& lhs, const not_null<U>& rhs) noexcept -> bool;

  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() < std::declval<const U&>())>
  constexpr auto operator<(const not_null<T>& lhs, const not_null<U>& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() < std::declval<const U&>())>
  constexpr auto operator<(const not_null<T>& lhs, const U& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() < std::declval<const U&>())>
  constexpr auto operator<(const T& lhs, const not_null<U>& rhs) noexcept -> bool;

  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() > std::declval<const U&>())>
  constexpr auto operator>(const not_null<T>& lhs, const not_null<U>& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() > std::declval<const U&>())>
  constexpr auto operator>(const not_null<T>& lhs, const U& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() > std::declval<const U&>())>
  constexpr auto operator>(const T& lhs, const not_null<U>& rhs) noexcept -> bool;

  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() <= std::declval<const U&>())>
  constexpr auto operator<=(const not_null<T>& lhs, const not_null<U>& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() <= std::declval<const U&>())>
  constexpr auto operator<=(const not_null<T>& lhs, const U& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() <= std::declval<const U&>())>
  constexpr auto operator<=(const T& lhs, const not_null<U>& rhs) noexcept -> bool;

  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() >= std::declval<const U&>())>
  constexpr auto operator>=(const not_null<T>& lhs, const not_null<U>& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() >= std::declval<const U&>())>
  constexpr auto operator>=(const not_null<T>& lhs, const U& rhs) noexcept -> bool;
  template <typename T, typename U,
            typename = decltype(std::declval<const T&>() >= std::declval<const U&>())>
  constexpr auto operator>=(const T& lhs, const not_null<U>& rhs) noexcept -> bool;

} // inline namespace bitwizeshift
} // namespace cpp

#if !defined(NOT_NULL_DISABLE_EXCEPTIONS)

inline
NOT_NULL_NS_IMPL::not_null_contract_violation::not_null_contract_violation()
  : logic_error{
      "check_not_null invoked with null pointer; "
      "not_null's contruct has been violated"
    }
{

}

#endif // !defined(NOT_NULL_DISABLE_EXCEPTIONS)

//=============================================================================
// detail utilities : not_null
//=============================================================================

template <typename U>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::detail::not_null_to_address(U* p)
  noexcept -> U*
{
  return p;
}

inline NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::detail::throw_null_pointer_error()
  -> void
{
#if defined(NOT_NULL_DISABLE_EXCEPTIONS)
  std::fprintf(
    stderr,
    "check_not_null invoked with null pointer; "
    "not_null's contruct has been violated"
  );
  std::abort();
#else
  throw not_null_contract_violation{};
#endif
}

template <typename T>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::detail::mark_nonnull(T* p) noexcept -> T*
{
#if defined(_MSC_VER)
  // use Microsoft's builtin '__assume' to hint to the compiler that p
  // cannot be null
  return (__assume(p != nullptr), p);
#else
  return p; // nullability is confirmed with gnu::returns_nonnull
#endif
}

template <typename T>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::detail::not_null_factory::make(T&& p)
  -> not_null<typename std::decay<T>::type>
{
  using value_type = typename std::decay<T>::type;

  return not_null<value_type>{
    typename not_null<value_type>::ctor_tag{},
    not_null_forward<T>(p)
  };
}

//=============================================================================
// class : not_null
//=============================================================================

//-----------------------------------------------------------------------------
// Constructors / Assignment
//-----------------------------------------------------------------------------

template <typename T>
template <typename U,
          typename std::enable_if<NOT_NULL_NS_IMPL::detail::not_null_is_implicit_convertible<T,const U&>::value,int>::type>
NOT_NULL_NS_IMPL::not_null<T>::not_null(const not_null<U>& other)
  noexcept(std::is_nothrow_constructible<T,const U&>::value)
  : m_pointer(other.as_nullable())
{

}

template <typename T>
template <typename U,
          typename std::enable_if<NOT_NULL_NS_IMPL::detail::not_null_is_explicit_convertible<T,const U&>::value,int>::type>
NOT_NULL_NS_IMPL::not_null<T>::not_null(const not_null<U>& other)
  noexcept(std::is_nothrow_constructible<T,const U&>::value)
  : m_pointer(other.as_nullable())
{

}

template <typename T>
template <typename U,
          typename std::enable_if<NOT_NULL_NS_IMPL::detail::not_null_is_implicit_convertible<T,U&&>::value,int>::type>
NOT_NULL_NS_IMPL::not_null<T>::not_null(not_null<U>&& other)
  noexcept(std::is_nothrow_constructible<T,U&&>::value)
  : m_pointer(static_cast<not_null<U>&&>(other).as_nullable())
{

}

template <typename T>
template <typename U,
          typename std::enable_if<NOT_NULL_NS_IMPL::detail::not_null_is_explicit_convertible<T,U&&>::value,int>::type>
NOT_NULL_NS_IMPL::not_null<T>::not_null(not_null<U>&& other)
  noexcept(std::is_nothrow_constructible<T,U&&>::value)
  : m_pointer(static_cast<not_null<U>&&>(other).as_nullable())
{

}

//-----------------------------------------------------------------------------

template <typename T>
template <typename U, typename>
inline NOT_NULL_CPP14_CONSTEXPR NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::not_null<T>::operator=(const not_null<U>& other)
  noexcept(std::is_nothrow_assignable<T&,const U&>::value) -> not_null&
{
  m_pointer = other.as_nullable();
  return (*this);
}

template <typename T>
template <typename U, typename>
inline NOT_NULL_CPP14_CONSTEXPR NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::not_null<T>::operator=(not_null<U>&& other)
  noexcept(std::is_nothrow_assignable<T&,U&&>::value) -> not_null&
{
  m_pointer = static_cast<not_null<U>&&>(other).as_nullable();
  return (*this);
}

//-----------------------------------------------------------------------------
// Observers
//-----------------------------------------------------------------------------

template<typename T>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::not_null<T>::get()
  const noexcept -> pointer
{
  return detail::mark_nonnull(detail::not_null_to_address(m_pointer));
}

template <typename T>
inline constexpr NOT_NULL_INLINE_VISIBILITY
NOT_NULL_NS_IMPL::not_null<T>::operator bool()
  const noexcept
{
  return true;
}

//-----------------------------------------------------------------------------

template<typename T>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::not_null<T>::as_nullable()
  const & noexcept -> const T&
{
  return m_pointer;
}

template<typename T>
inline NOT_NULL_CPP14_CONSTEXPR NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::not_null<T>::as_nullable()
  && noexcept -> T&&
{
  return static_cast<T&&>(m_pointer);
}

//-----------------------------------------------------------------------------

template<typename T>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::not_null<T>::operator->()
  const noexcept -> pointer
{
  return get();
}

template<typename T>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::not_null<T>::operator*()
  const noexcept -> reference
{
  return *get();
}

//-----------------------------------------------------------------------------
// Private Constructor
//-----------------------------------------------------------------------------

template <typename T>
template <typename P>
inline constexpr NOT_NULL_INLINE_VISIBILITY
NOT_NULL_NS_IMPL::not_null<T>::not_null(ctor_tag, P&& ptr)
  noexcept(std::is_nothrow_constructible<typename std::decay<P>::type, P>::value)
  : m_pointer(detail::not_null_forward<P>(ptr))
{

}

//=============================================================================
// non-member functions : class : not_null
//=============================================================================

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------

// The implementation of `check_not_null` below triggers `-Wunused-value`
// warnings due to the intentional use of the comma-operator. Suppress this,
// since this is intentional to get around some limitations of calling
// non-constexpr functions in a constexpr context
#if defined(__clang__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunused-value"
// clang 3.9 introduces -Wcomma, which incorrectly warns that the comma
// operator may be misused below. This diagnostic has been disabled.
# if (__clang_major__ >= 4) || ((__clang_major__ == 3) && (__clang_minor__ >= 9))
#   pragma clang diagnostic ignored "-Wcomma"
# endif
#elif defined(__GNUC__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-value"
#endif // defined(__GNUC__)

template <typename T>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::check_not_null(T&& ptr)
  -> not_null<typename std::decay<T>::type>
{
  return (ptr != nullptr || (detail::throw_null_pointer_error(), true)),
    assume_not_null(detail::not_null_forward<T>(ptr));
}

#if defined(__clang__)
# pragma clang diagnostic pop
#elif defined(__GNUC__)
# pragma GCC diagnostic pop
#endif // defined(__GNUC__)

template <typename T>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::assume_not_null(T&& ptr)
  noexcept(std::is_nothrow_constructible<typename std::decay<T>::type,T>::value)
  -> not_null<typename std::decay<T>::type>
{
  return detail::not_null_factory::make(detail::not_null_forward<T>(ptr));
}

//-----------------------------------------------------------------------------
// Comparisons
//-----------------------------------------------------------------------------

template <typename T>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator==(const not_null<T>&, std::nullptr_t)
  noexcept -> bool
{
  return false;
}

template <typename T>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator==(std::nullptr_t, const not_null<T>&)
  noexcept -> bool
{
  return false;
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator==(const not_null<T>& lhs, const not_null<U>& rhs)
  noexcept -> bool
{
  return lhs.as_nullable() == rhs.as_nullable();
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator==(const not_null<T>& lhs, const U& rhs)
  noexcept -> bool
{
  return lhs.as_nullable() == rhs;
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator==(const T& lhs, const not_null<U>& rhs)
  noexcept -> bool
{
  return lhs == rhs.as_nullable();
}

template <typename T>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator!=(const not_null<T>&, std::nullptr_t)
  noexcept -> bool
{
  return true;
}

template <typename T>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator!=(std::nullptr_t, const not_null<T>&)
  noexcept -> bool
{
  return true;
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator!=(const not_null<T>& lhs, const not_null<U>& rhs)
  noexcept -> bool
{
  return lhs.as_nullable() != rhs.as_nullable();
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator!=(const not_null<T>& lhs, const U& rhs)
  noexcept -> bool
{
  return lhs.as_nullable() != rhs;
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator!=(const T& lhs, const not_null<U>& rhs)
  noexcept -> bool
{
  return lhs != rhs.as_nullable();
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator<(const not_null<T>& lhs, const not_null<U>& rhs)
  noexcept -> bool
{
  return lhs.as_nullable() < rhs.as_nullable();
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator<(const not_null<T>& lhs, const U& rhs)
  noexcept -> bool
{
  return lhs.as_nullable() < rhs;
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator<(const T& lhs, const not_null<U>& rhs)
  noexcept -> bool
{
  return lhs < rhs.as_nullable();
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator>(const not_null<T>& lhs, const not_null<U>& rhs)
  noexcept -> bool
{
  return lhs.as_nullable() > rhs.as_nullable();
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator>(const not_null<T>& lhs, const U& rhs)
  noexcept -> bool
{
  return lhs.as_nullable() > rhs;
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator>(const T& lhs, const not_null<U>& rhs)
  noexcept -> bool
{
  return lhs > rhs.as_nullable();
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator<=(const not_null<T>& lhs, const not_null<U>& rhs)
  noexcept -> bool
{
  return lhs.as_nullable() <= rhs.as_nullable();
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator<=(const not_null<T>& lhs, const U& rhs)
  noexcept -> bool
{
  return lhs.as_nullable() <= rhs;
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator<=(const T& lhs, const not_null<U>& rhs)
  noexcept -> bool
{
  return lhs <= rhs.as_nullable();
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator>=(const not_null<T>& lhs, const not_null<U>& rhs)
  noexcept -> bool
{
  return lhs.as_nullable() >= rhs.as_nullable();
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator>=(const not_null<T>& lhs, const U& rhs)
  noexcept -> bool
{
  return lhs.as_nullable() >= rhs;
}

template <typename T, typename U, typename>
inline constexpr NOT_NULL_INLINE_VISIBILITY
auto NOT_NULL_NS_IMPL::operator>=(const T& lhs, const not_null<U>& rhs)
  noexcept -> bool
{
  return lhs >= rhs.as_nullable();
}

template<class T>
struct std::hash<cpp::not_null<T>> {
    size_t operator()(const cpp::not_null<T> &x) const {
        return std::hash<T>{}(x.as_nullable());
    }
};

template<class T>
std::size_t hash_value(const cpp::not_null<T> &x) {
    return std::hash<T>{}(x.as_nullable());
}

#endif /* CPP_BITWIZESHIFT_NOT_NULL_HPP */
