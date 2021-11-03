#pragma once
// https://godbolt.org/z/fsc3d5T9d
// ----------------------------------------------
#include "common.h"

// undef this to use memcmp
#define DBJ_USING_STRNCMP 1

// two pointer to char arrays comparison
// return true if char arrays are equal
// one can use it or abuse it
// 
// Caveat Emptor
// 
//	argument const char(*L)[N],  compiler rewrites to: const char(*L)[*] 
// 
//  also
// 
//	argument const char L [N],  compiler rewrites to: const char(*L)[*] 
//  with the difference of being invisible/unusable by the code
//
static inline bool char_arr_compare_(
	const size_t N,
	const size_t M,
	const char L[static N],
	const char R[static M]
)
{
	DBJ_VERIFY(L && R);
	DBJ_VERIFY(N > 0 && M > 0);

#ifdef DBJ_USING_STRNCMP

	// str(n)cmp checks zeroes too
	// not just the length
	// AND does the lexi compare
	return 0 == strncmp(L, R, MIN(N, M));

#else // ! DBJ_USING_STRNCMP

	// mem alignment and padding might be the issue
	// and this is not lexi compare
	return 0 == memcmp(L, R, MIN(N, M));

#endif // ! DBJ_USING_STRNCMP
}

// this is very clever but works only on string literals
#undef  COMPARR
#define COMPARR(A,B) ( DBJ_COUNT_OF(A) == DBJ_COUNT_OF(B) ? (0 == memcmp( A, B, DBJ_COUNT_OF(A))) : false  )

// this is not so clever but works at runtime too, 
// hint: not just on string literals
inline int compare_char_arrays(
	const char a[static 1],
	const char b[static 1]
)
{
	const size_t a_len = strnlen(a, 0xFFFF);
	const size_t b_len = strnlen(b, 0xFFFF);

	return char_arr_compare_(a_len, b_len, a, b);
}

// see: https://godbolt.org/z/frqbs6Eje

/////////////////////////////////////////////////////////////////////////
/// simple testing
///
inline int test_charr_arr_compare(void)
{

	// abuse kicks the bucket
	// char_arr_compare_(13,42,NULL,NULL);

	printf("\n\nUsing memcmp() to compare char arrays\n\n");


	/// const char naughty = '\0';
	const char naughtyarr[] = { '\0' };
	// correct result is indeed: true
	PRINB(COMPARR(naughtyarr, naughtyarr));

	// does not compile P( COMPARE( NULL,"")) ;
	// does not copile  P( COMPARE("","")) ;
	PRINB(COMPARR("A", "B"));
	PRINB(COMPARR("B", "A"));
	PRINB(COMPARR("A", "A"));
	PRINB(COMPARR("AA", "A"));
	PRINB(COMPARR("A", "AA"));

	const char nz[] = { 'N', 'O', 'Z', 'E', 'R', 'O' };
	const char nzA[] = { 'A' };
	const char nzB[] = { 'B' };
	PRINB(COMPARR(nz, nz));
	PRINB(COMPARR(nzA, nzB));
	PRINB(COMPARR(nzA, "A"));

	{
#undef COMPARR
#define COMPARR compare_char_arrays
#if DBJ_USING_STRNCMP
		printf("\n\nUsing strncmp() to compare char arrays\n\n");
#endif
		PRINB(COMPARR(naughtyarr, naughtyarr));
		PRINB(COMPARR("A", "B"));
		PRINB(COMPARR("B", "A"));
		PRINB(COMPARR("A", "A"));
		PRINB(COMPARR("AA", "A"));
		PRINB(COMPARR("A", "AA"));
		PRINB(COMPARR(nz, nz));
		PRINB(COMPARR(nzA, nzB));
		PRINB(COMPARR(nzA, "A"));
	}

	return 0;
}
