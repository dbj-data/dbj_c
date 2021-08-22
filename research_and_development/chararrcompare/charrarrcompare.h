#pragma once
// https://godbolt.org/z/fsc3d5T9d
// ----------------------------------------------
#include "cdebug.h"

// https://en.cppreference.com/w/c/preprocessor/replace
// #if __STDC_VERSION__ < 199901L
// #error At least C99 conformant compiler is required
// #endif

// undef this to use memcmp
#define DBJ_USING_STRNCMP 1

// two pointer to char arrays comparison
// return true if char arrays are equal
// one can use it or abuse it
inline bool char_arr_compare_ (
    const size_t N, const size_t M, 
    const char (*L)[N], 
    const char (*R)[M])
{
     DBJ_VERIFY( L && R );
     DBJ_VERIFY( N > 0 && M > 0 );

#ifdef DBJ_USING_STRNCMP

// str(n)cmp checks zeroes too
// not just the length
// AND does the lexi compare
    return 0 == strncmp( *L, *R, MIN(N,M) );

#else // ! DBJ_USING_STRNCMP

// mem alignment and padding might be the issue
// and this is not lexi compare
   return 0 == memcmp( *L, *R, MIN(N,M) );

#endif // ! DBJ_USING_STRNCMP
}

#undef  COMPARR
// macros are working for string literals
// and arrays, but not for pointers
// #define COMPSTR(A,B) (0 == strncmp( A, B, MIN( COUNT_OF(A), COUNT_OF(B) )))
// above I keep but the bellow works ok so far
// if lengths are different arrays are different
#define COMPARR(A,B) ( COUNT_OF(A) == COUNT_OF(B) ? (0 == memcmp( A, B, COUNT_OF(A))) : false  )

// see: https://godbolt.org/z/frqbs6Eje

/////////////////////////////////////////////////////////////////////////
/// simple testing
///
inline int adhoc_charr_arr_compare(void) 
{

#if DBJ_USING_STRNCMP
DBG_PRINT("\nUsing strncmp() to compare char arrays\n");
#endif

// abuse kicks the bucket
// char_arr_compare_(13,42,NULL,NULL);

const char naughty = '\0';
const char naughtyarr[] = {'\0' };
// correct result is indeed: true
PRINB(COMPARR( naughtyarr , naughtyarr )) ;

  // does not compile P( COMPARE( NULL,"")) ;
  // does not copile  P( COMPARE("","")) ;
  PRINB( COMPARR("A","B")) ;
  PRINB( COMPARR("B","A")) ;
  PRINB( COMPARR("A","A")) ;
  PRINB( COMPARR("AA","A")) ;
  PRINB( COMPARR("A","AA")) ;

  const char nz[] = {'N', 'O', 'Z', 'E', 'R', 'O'};
  const char nzA[] = {'A'};
  const char nzB[] = {'B'};
  PRINB( COMPARR( nz,nz)) ;
  PRINB( COMPARR( nzA,nzB)) ;
  PRINB( COMPARR( nzA, "A")) ;

  return 0 ;
}
