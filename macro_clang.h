#pragma once
/*
clang macros made slightly more confortable 
taken from github systemd repo
*/

#define _const_ __attribute__((__const__))
#define _pure_ __attribute__((__pure__))
#define _unused_ __attribute__((__unused__))
#define _cleanup_(x) __attribute__((__cleanup__(x)))
#define _printf_(a, b) __attribute__((__format__(printf, a, b)))
#ifdef __clang__
#  define _alloc_(...)
#else
#  define _alloc_(...) __attribute__((__alloc_size__(__VA_ARGS__)))
#endif
#define _sentinel_ __attribute__((__sentinel__))
#define _section_(x) __attribute__((__section__(x)))
#define _used_ __attribute__((__used__))
#define _destructor_ __attribute__((__destructor__))
#define _deprecated_ __attribute__((__deprecated__))
#define _packed_ __attribute__((__packed__))
#define _malloc_ __attribute__((__malloc__))
#define _weak_ __attribute__((__weak__))
#define _likely_(x) (__builtin_expect(!!(x), 1))
#define _unlikely_(x) (__builtin_expect(!!(x), 0))
#define _public_ __attribute__((__visibility__("default")))
#define _hidden_ __attribute__((__visibility__("hidden")))
#define _weakref_(x) __attribute__((__weakref__(#x)))
#define _align_(x) __attribute__((__aligned__(x)))
#define _alignas_(x) __attribute__((__aligned__(__alignof(x))))
#define _alignptr_ __attribute__((__aligned__(sizeof(void*))))
#if __GNUC__ >= 7
#define _fallthrough_ __attribute__((__fallthrough__))
#else
#define _fallthrough_
#endif
/* Define C11 noreturn without <stdnoreturn.h> and even on older gcc
 * compiler versions */
#ifndef _noreturn_
#if __STDC_VERSION__ >= 201112L
#define _noreturn_ _Noreturn
#else
#define _noreturn_ __attribute__((__noreturn__))
#endif
#endif

/*
 * STRLEN - returns the length of a string literal, minus the trailing NUL byte.
 *          Contrary to strlen(), this is a constant expression.
 * @x: a string literal.
 */
#define STRLEN(x) (sizeof(""x"") - 1)

/* Define C11 thread_local attribute even on older gcc compiler
 * version */
#ifndef thread_local
/*
 * Don't break on glibc < 2.16 that doesn't define __STDC_NO_THREADS__
 * see http://gcc.gnu.org/bugzilla/show_bug.cgi?id=53769
 */
#if __STDC_VERSION__ >= 201112L && !(defined(__STDC_NO_THREADS__) || (defined(__GNU_LIBRARY__) && __GLIBC__ == 2 && __GLIBC_MINOR__ < 16))
#define thread_local _Thread_local
#else
#define thread_local __thread
#endif
#endif // ! thread_local

/*
-------------------------------------------------------------------------------------
 from https://news.ycombinator.com/item?id=11305190

 usage:

 _autofree_ char *s1 = strdup("foo");

 */
#include <assert.h>

extern void free (void*); // maybe ...

#define _autofree_ __attribute((cleanup(dbjcapi_autofree_func_)))

static inline void dbjcapi_autofree_func_(void *ptr_ptr) 
{
    assert(ptr_ptr);             // dbj@dbj.org
    if (! ptr_ptr)  return ;     // added

    void *ptr = * (void **) ptr_ptr;
    free(ptr);
}