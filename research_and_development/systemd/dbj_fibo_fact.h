/* 
  https://godbolt.org/z/7vqTbo6sT
  
   (c) by dbj at dbj dot org -- CC BY SA 3.0

   ps: concept is of course not mine, just the code

   To build, in exactly one C or CPP file do:

   #define DBJ_FIBO_FACT_IMPLEMENT
   #include <dbj_fibo_fact.h>

   Elsewehre in the same project just include and use
*/
#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef int errno_t;
#ifdef __clang__
#define _const_ __attribute__((__const__))
#else
#define _const_
#endif  // ! __clang__

#define _pure_ __attribute__((__pure__))
#define _unused_ __attribute__((__unused__))
#define _cleanup_(x) __attribute__((__cleanup__(x)))

typedef int64_t fibo_type;

/*
int64_t fibo(int64_t n)
{
    int64_t c = 0, a = 1, b = 1;
    for (int64_t i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int64 can hold fibonacci(N) up to N = 64
we store the output into the table 0 .. 93 long = 94 elements
*/

// declare the valstat type
// status is POSIX error code
// we declare status == 0 as "empty" i.e. no status
// if no status all is ok
typedef struct {
  fibo_type value;
  errno_t status;
} valstat_fibo;

#ifdef DBJ_FIBO_FACT_IMPLEMENT

static _const_ int64_t fibo_table_64[] = {1,
                                                         1,
                                                         1,
                                                         2,
                                                         3,
                                                         5,
                                                         8,
                                                         13,
                                                         21,
                                                         34,
                                                         55,
                                                         89,
                                                         144,
                                                         233,
                                                         377,
                                                         610,
                                                         987,
                                                         1597,
                                                         2584,
                                                         4181,
                                                         6765,
                                                         10946,
                                                         17711,
                                                         28657,
                                                         46368,
                                                         75025,
                                                         121393,
                                                         196418,
                                                         317811,
                                                         514229,
                                                         832040,
                                                         1346269,
                                                         2178309,
                                                         3524578,
                                                         5702887,
                                                         9227465,
                                                         14930352,
                                                         24157817,
                                                         39088169,
                                                         63245986,
                                                         102334155,
                                                         165580141,
                                                         267914296,
                                                         433494437,
                                                         701408733,
                                                         1134903170,
                                                         1836311903,
                                                         2971215073,
                                                         4807526976,
                                                         7778742049,
                                                         12586269025,
                                                         20365011074,
                                                         32951280099,
                                                         53316291173,
                                                         86267571272,
                                                         139583862445,
                                                         225851433717,
                                                         365435296162,
                                                         591286729879,
                                                         956722026041,
                                                         1548008755920,
                                                         2504730781961,
                                                         4052739537881,
                                                         6557470319842,
                                                         10610209857723,
                                                         17167680177565,
                                                         27777890035288,
                                                         44945570212853,
                                                         72723460248141,
                                                         117669030460994,
                                                         190392490709135,
                                                         308061521170129,
                                                         498454011879264,
                                                         806515533049393,
                                                         1304969544928657,
                                                         2111485077978050,
                                                         3416454622906707,
                                                         5527939700884757,
                                                         8944394323791464,
                                                         14472334024676221,
                                                         23416728348467685,
                                                         37889062373143906,
                                                         61305790721611591,
                                                         99194853094755497,
                                                         160500643816367088,
                                                         259695496911122585,
                                                         420196140727489673,
                                                         679891637638612258,
                                                         1100087778366101931,
                                                         1779979416004714189,
                                                         2880067194370816120,
                                                         4660046610375530309,
                                                         754011380474634642};

// 94
#define fibo_table_size (sizeof(fibo_table_64) / sizeof(fibo_table_64[0]))
#define fibo_min_n 0
#define fibo_max_n fibo_table_size - 1

// the outcome is very safe and simple fibonacci
_const_ valstat_fibo fibo(fibo_type n) {
  if ((n < 0) || (n > fibo_max_n) ) return (valstat_fibo){.status = EINVAL};

  return (valstat_fibo){.value = fibo_table_64[n]};  // OK
}
#else // ! DBJ_FIBO_FACT_IMPLEMENT
_const_ valstat_fibo fibo(fibo_type n) ;
#endif // ! DBJ_FIBO_FACT_IMPLEMENT

#ifdef __cplusplus
// not a compile time constant
// thus only C++ instant compile time test
_const_ valstat_fibo vstat_ = fibo(93);
static_assert(vstat_.status == 0, "OK: fibo(N), max N == 93 ");
#endif  // __cplusplus

/*
the "clever" factorial is just a lookup,
since for 32bit int overflow happens for 13!

fact values source: http://www.tsm-resources.com/alists/fact.html

reminder:
#define INT32_MAX        2147483647i32
#define INT64_MAX        9223372036854775807i64
*/

// declare the valstat type
// status is POSIX error code
typedef struct {
  int32_t value;
  errno_t status;
} valstat_fact;

#ifdef DBJ_FIBO_FACT_IMPLEMENT

_const_ static int32_t factorials32[] = {
    1,    1,     2,      6,       24,       120,      720,
    5040, 40320, 362880, 3628800, 39916800, 479001600};

#define DBJ_FACT32_MAX_N (sizeof(factorials32) / sizeof(factorials32[0])) - 1

_const_ valstat_fact fact32( int32_t n) {
  if ((n < 0U) || (n > DBJ_FACT32_MAX_N ) ) {
    return (valstat_fact){.status = EINVAL};
  }
  return (valstat_fact){.value = factorials32[n]};
}
#else // ! DBJ_FIBO_FACT_IMPLEMENT
_const_ valstat_fact fact32( int32_t ) ;
#endif // ! DBJ_FIBO_FACT_IMPLEMENT

// declare the valstat type
// status is POSIX error code
typedef struct {
  int64_t value;
  errno_t status;
} valstat_fact64;

#ifdef DBJ_FIBO_FACT_IMPLEMENT
_const_ static int64_t factorials64[] = {
    1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880,
    3628800,
    39916800,
    479001600, /* 12! */
    6227020800, /*13!*/
    87178291200,
    1307674368000,
    20922789888000,
    355687428096000,
    6402373705728000,
    121645100408832000,
    2432902008176640000 /*20!*/
};

#define DBJ_FACT64_MAX_N (sizeof(factorials64) / sizeof(factorials64[0])) - 1


_const_ valstat_fact64 fact64(int64_t i) {
  if ((i < 0U) || (i > DBJ_FACT64_MAX_N) ) {
    return (valstat_fact64){.status = EINVAL};
  }
  return (valstat_fact64){.value = factorials64[i]};
}
#else // ! DBJ_FIBO_FACT_IMPLEMENT
_const_ valstat_fact64 fact64(int64_t ) ;
#endif // ! DBJ_FIBO_FACT_IMPLEMENT



