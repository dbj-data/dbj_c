#pragma once
// https://godbolt.org/z/WjWfEhbde
#ifndef  __GNUC__
#error GCC or clang is required
#endif

#if __STDC_VERSION__ < 201112L
#error C11 or better is required
#endif

#include <stdio.h>

// http://open-std.org/jtc1/sc22/wg14/www/docs/n2840.htm
#include <stdatomic.h>

typedef _Atomic(unsigned) once_flag;
#define ONCE_FLAG_INIT 0u
void call_once(once_flag *flag, void (*func)(void)) {
  unsigned actual = atomic_load_explicit(flag, memory_order_acquire);
  if (actual < 2u) {
    switch (actual) {
    case 0u:
      // The very first sets this to 1 and then to 2 to indicate that the function has been run.
      if (atomic_compare_exchange_strong_explicit(flag, &(unsigned){ 0 }, 1u, memory_order_relaxed, memory_order_relaxed)) {
        func();
        atomic_store_explicit(flag, 2u, memory_order_release);
        return;
      }
      // we lose and fall through
    case 1u:
      while (atomic_load_explicit(flag, memory_order_acquire) < 2u) {
        // active polling or some sleep if supported
      }
    }
  }
}
#ifndef  __GNUC__
#error GCC or clang is required
#endif

#if __STDC_VERSION__ < 201112L
#error C11 or better is required
#endif

#include <stdio.h>

// http://open-std.org/jtc1/sc22/wg14/www/docs/n2840.htm
#include <stdatomic.h>

typedef _Atomic(unsigned) once_flag;
#define ONCE_FLAG_INIT 0u
void call_once(once_flag *flag, void (*func)(void)) {
  unsigned actual = atomic_load_explicit(flag, memory_order_acquire);
  if (actual < 2u) {
    switch (actual) {
    case 0u:
      // The very first sets this to 1 and then to 2 to indicate that the function has been run.
      if (atomic_compare_exchange_strong_explicit(flag, &(unsigned){ 0 }, 1u, memory_order_relaxed, memory_order_relaxed)) {
        func();
        atomic_store_explicit(flag, 2u, memory_order_release);
        return;
      }
      // we lose and fall through
    case 1u:
      while (atomic_load_explicit(flag, memory_order_acquire) < 2u) {
        // active polling or some sleep if supported
      }
    }
  }
}

#ifdef DBJ_TESTING_CALL_ONCE

#include <stdio.h>

static void on_startup (void)
{
    printf("\nStarted!\n");
}

int main (int argc, char ** argv)
{
    once_flag flag_ ;
    call_once(&flag_, on_startup);
    return 42;
}

#endif // DBJ_TESTING_CALL_ONCE

#endif // __STDC_VERSION__ >= 201112L
#endif // __GNUC__
