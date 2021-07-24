
#ifndef DBJ_COMPILE_TIME_H_
#define DBJ_COMPILE_TIME_H_

#undef DBJ_WIN
#if defined(_WIN32)
#define DBJ_WIN
#endif

#undef DBJ_CLANG_OR_GCC
#if (defined(__clang__) || defined(__GNUC__))
#define DBJ_CLANG_OR_GCC
#else
#error use clang or gnuc, please
#endif // __clang__

#define DBJ_PURE __attribute__((const))

// https://dbj.org/license_dbj

// as of today (2021-APR-27) this very likely does not compile
// this is to be traslated into C99 or better, with valstat and strong types

#define dbj_crt_api static inline 

#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#define __STDC_LIB_EXT1__
#define __STDC_WANT_LIB_EXT1__ 1

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <errno.h>

#ifdef DBJ_WIN
// https://docs.microsoft.com/en-us/cpp/build/reference/j-default-char-type-is-unsigned?view=msvc-160
// The /J option defines _CHAR_UNSIGNED, which is used with #ifndef in the 
// LIMITS.h file to define the range of the default char type.
#include <limits.h>
#ifndef _CHAR_UNSIGNED
#error  _CHAR_UNSIGNED not defined? Please use:  /J (Default char Type Is unsigned)
#endif
#endif // DBJ_WIN


dbj_crt_api bool is_empty(const char* text) 
{
	return text == 0 || *text == '\0';
}

dbj_crt_api bool wis_empty(const wchar_t* text) 
{
	return text == 0 || *text == L'\0';
}

// do not try this at home. ever.
inline void secure_reset(void *s, size_t n) 
{
	assert(s);
	volatile char *p = (char *)s;
	while (n--)
		*p++ = 0;
}

DBJ_PURE dbj_crt_api char *str_ncpy(char *, const char *, size_t) ;

DBJ_PURE dbj_crt_api char *str_ncpy(char *destination, const char *source, size_t num) 
{
	assert(!is_empty(destination));
	assert(!is_empty(source));

	// return if no memory is allocated to the destination
	if (destination == 0)
		return 0;

	// take a pointer pointing to the beginning of destination string
	char *ptr = destination;

	// copy first num characters of C-string pointed by source
	// into the array pointed by destination
	while (*source && num--)
	{
		*destination = *source;
		destination++;
		source++;
	}

	// null terminate destination string
	*destination = '\0';

	// destination is returned by standard strncpy()
	return ptr;
}

// https://docs.microsoft.com/en-us/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)?redirectedfrom=MSDN
// https://opensource.apple.com/source/sudo/sudo-83/sudo/lib/util/memset_s.c.auto.html

#ifndef RSIZE_MAX
#if defined(SIZE_MAX)
#define RSIZE_MAX (SIZE_MAX >> 1)
#elif defined(__LP64__)
#define RSIZE_MAX 0x7fffffffffffffffUL
#else
#define RSIZE_MAX 0x7fffffffU
#endif
#endif

dbj_crt_api errno_t
mem_set_s(volatile void *v, rsize_t smax, int c, rsize_t n)
{
	assert(v);

	errno_t ret = 0;
	/* Updating through a volatile pointer should not be optimized away. */
	typedef volatile unsigned char * vuc_ptr;
	vuc_ptr s = (vuc_ptr)(v);

	/* Fatal runtime-constraint violations. */
	if (s == NULL || smax > RSIZE_MAX)
	{
		return ret = errno = EINVAL;
	}
	/* Non-fatal runtime-constraint violation, n must not exceed smax. */
	if (n > smax)
	{
		n = smax;
		return ret = errno = EINVAL;
	}

	while (n--)
		*s++ = (unsigned char)c;

	return ret;
}

#undef RSIZE_MAX
// memset, memcpy, memcmp, memchr, memmove

__attribute__((const)) dbj_crt_api void *mem_set(void *s, int c, size_t n)
{
	assert(s);
	unsigned char *p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)c;
	return s;
}

__attribute__((const)) dbj_crt_api int mem_cmp(const void *s1, const void *s2, size_t n)
{
	assert(s1);
	assert(s2);

	const unsigned char *p1 = (const unsigned char *)s1, *p2 = (const unsigned char *)s2;
	while (n--)
		if (*p1 != *p2)
			return *p1 - *p2;
		else
			p1++, p2++;
	return 0;
}

__attribute__((const)) dbj_crt_api void *mem_cpy(void *dest, const void *src, size_t n)
{
	assert(dest);
	assert(src);

	char *dp = (char *)dest;
	const char *sp = (const char *)src;
	while (n--)
		*dp++ = *sp++;
	return dest;
}

__attribute__((const)) dbj_crt_api void *mem_chr(const void *s, int c, size_t n)
{
	assert(s);

	unsigned char *p = (unsigned char *)s;
	while (n--)
		if (*p != (unsigned char)c)
			p++;
		else
			return p;
	return 0;
}

// -----------------------------------------------------------------------------------------
// compile time native string handling -- C++11 or better
//
// for testing and convincing yourself this works see https://godbolt.org/z/gGL95T
//
// NOTE: C++20 char8_t is a path peppered with a shards of glass, just don't
// go there
//
// NOTE: char16_t and char32_t are ok. if need them add them bellow
//
// NOTE: WIN32 is UTF-16 aka wchar_t universe, WIN32 char API's are all
// calling wchar_t variants
//
__attribute__((const)) dbj_crt_api bool str_equal(char const *lhs, char const *rhs) 
{
	assert(!is_empty(lhs));
	assert(!is_empty(rhs));

	while (*lhs || *rhs)
		if (*lhs++ != *rhs++)
			return false;
	return true;
}

__attribute__((const)) dbj_crt_api bool wstr_equal(wchar_t const *lhs, wchar_t const *rhs) 
{
	assert(!wis_empty(lhs));
	assert(!wis_empty(rhs));

	while (*lhs || *rhs)
		if (*lhs++ != *rhs++)
			return false;
	return true;
}

__attribute__((const)) dbj_crt_api size_t str_len(const char *ch) 
{
	assert(!is_empty(ch));

	size_t len = 0;
	while (ch[len])
		++len;
	return len;
}

__attribute__((const)) dbj_crt_api size_t wstr_len(const wchar_t *ch) 
{
	assert(!wis_empty(ch));

	size_t len = 0;
	while (ch[len])
		++len;
	return len;
}

__attribute__((const)) dbj_crt_api size_t str_nlen(const char *str, size_t max)
{
	assert(!is_empty(str));
	const char *end = (const char *)mem_chr(str, 0, max);
	return end ? (size_t)(end - str) : max;
}

// the FreeBSD implementation
__attribute__((const)) dbj_crt_api int
str_cmp(register const char *s1, register const char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	// casting stops compile time
	// return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
	return (*s1 - *(s2 - 1));
}

#ifdef __cplusplus 

// portable memmove is tricky in C
// in C++ we have the luxury of template value arguments which are compile time
// instead of
// memmove( dest, src, 32 );
// you will do
// mem_move<32>( dest, src) ;


template <size_t n>
extern inline void *mem_move(void *dest, const void *src)
{
	assert(dest);
	assert(src);
	// without n as template argument this will
	// require C99 VLA feature
	unsigned char tmp[n]{0};
	dbj::compiletime::mem_cpy(tmp, src, n);
	dbj::compiletime::mem_cpy(dest, tmp, n);
	return dest;
}

// non macro count of is easy in  C++
#ifdef DBJ_CLANG_OR_GCC

template <typename T, size_t N>
inline __attribute__((const)) size_t countof(T const (&)[N]) { return N; };
template <typename T>
inline __attribute__((const)) size_t countof(T *) = delete;

#endif //  DBJ_CLANG_OR_GCC

/*

	Return string literal copy with white spaces removed.

		1. This is compile time function.
		   It uses stack space, thus be carefull of going happy-go-lucky and overdosing on the "happy"

		What is returned is std::array, thus:

		2. result size equals the input size
		3. result strlen is less than it's size
		4. on all white spaces use-case strlen is 0

	Synopsis:

		using namespace dbj::compiletime ;
		__attribute__((const)) auto clean_ = remove_ws("A \t\v\rB\n C");
		printf("\n%s\n", clean_.data());

	*/
__attribute__((const)) dbj_crt_api  auto remove_ws_max_input_size{1024U};

template <typename C, size_t N>
__attribute__((const)) dbj_crt_api auto remove_ws(const C (&literal_)[N])
{

	static_assert(
		N < remove_ws_max_input_size,
		"remove_ws(), argument char array must be shorter than dbj::compiletime::remove_ws_max_input_size");

	std::array<C, N> rezult_{{}}; // zero it
	size_t rezult_idx_{};

	for (size_t j{}; j < N; ++j)
	{
		switch (literal_[j])
		{
		case ' ':
		case '\f':
		case '\n':
		case '\r':
		case '\t':
		case '\v':
			continue;
			break;
		default:
			rezult_[rezult_idx_++] = literal_[j];
		};
	}
	return rezult_;
}

/*
	This is peculiarly useful.

	Basically copy string to static std::array
	which instance can be moved, as we know
	But. This is compile tame.
	why have I not thought of this before?

	__attribute__((const)) auto arr_literal = to_array ("Whatever");

	https://godbolt.org/z/sTEceK
	*/
template <size_t N>
__attribute__((const)) dbj_crt_api  std::array<char, N> to_array(const char (&sl_)[N]) 
{
	std::array<char, N> arr_{{0}};
	for (auto k = 0U; k < N; ++k)
	{
		arr_[k] = sl_[k];
	}
	return arr_;
}

// this can not be compile time as it will require strlen?
template <size_t N>
__attribute__((const)) dbj_crt_api  std::array<char, N> to_array(const char *)  = delete;

/*
	----------------------------------------------------------------------------------------------------------------
	*/
// are all 3 things equal?
template <typename... T>
__attribute__((const)) dbj_crt_api  bool equal3(const T &...args_)
{
	if ((sizeof...(args_)) < 2)
		return true;
	// non recursive version
	const auto il_ = {args_...};
	// compare them all to the first
	auto first_ = *(il_.begin());
	// assumption
	bool rezult_{true};
	for (auto &&elem_ : il_)
	{
		// yes I know, first cycle compares first_ to itself ...
		rezult_ = rezult_ && (first_ == elem_);
		// short circuit-ing
		if (!rezult_)
			break;
	}
	return rezult_;
};

// simpler ?
dbj_crt_api auto eq3 = [](auto v1, auto v2, auto v3) __attribute__((const)) -> bool
{
	return (v1 == v2) && (v2 == v3);
};

#endif // __cplusplus 

#endif // !DBJ_COMPILE_TIME_H_
