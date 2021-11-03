
#pragma once
#include "common.h"



// carefull! ARR has to be array literal for the DBJ_COUNT_OF macro to work
// #undef DBJ_COUNT_OF
// #define DBJ_COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

// #undef DBJ_GULP
// #define DBJ_GULP(...) (void)(0)

#undef REVEAL_COMPARATOR

// #define REVEAL_COMPARATOR(name , arg1,arg2,rez) \
//     printf("\n%s (", name);  macro_printval(arg1); printf(","); macro_printval(arg2); printf(")"); printf(" --> %2d", rez) 

#define REVEAL_COMPARATOR(name, arg1,arg2,rez) DBJ_GULP(name, arg1,arg2,rez) 

#undef COMPARATOR
#define COMPARATOR( NME, T) \
int NME (const void* a, const void* b) { \
	T arg1 = *(const T*)a; T arg2 = *(const T*)b; \
	int rez = 0; \
	if (arg1 < arg2) rez = -1 ;\
	if (arg1 > arg2) rez =  1 ; \
	REVEAL_COMPARATOR(#NME, arg1,arg2,rez) ; \
	return rez; \
}

COMPARATOR(qsort_double_comparator_, double);
COMPARATOR(qsort_int_comparator_, int);
COMPARATOR(qsort_char_comparator_, char);
COMPARATOR(qsort_bool_comparator_, bool);
COMPARATOR(qsort_float_comparator_, float);
COMPARATOR(qsort_long_comparator_, long);

#undef CHOOSE_COMPARATOR
#define CHOOSE_COMPARATOR(V) \
_Generic((V), char: qsort_char_comparator_ , long: qsort_long_comparator_, double: qsort_double_comparator_, \
bool: qsort_bool_comparator_, float: qsort_float_comparator_, default:  qsort_int_comparator_ )

// carefull! ARR has to be array literal for the DBJ_COUNT_OF macro to work
#undef QSORT
#define QSORT(ARR, comparator ) qsort( ARR, DBJ_COUNT_OF(ARR), sizeof(ARR[0]), comparator ) 

// note: FMT does not have to be string literal
#undef DISPARR
#define DISPARR(FMT, ARR) for(int j = 0; j < DBJ_COUNT_OF(ARR); ++j ) { DBG_PRINT(" ") ;DBG_PRINT(FMT, ARR[j]); }

#undef QSORT_TEST_DRIVER
#define QSORT_TEST_DRIVER(lst, comparator )\
do {\
  DBG_PRINT("\nBefore:\t"); DISPARR( macro_type_to_format_str(lst[0]), lst);\
  QSORT( lst,  comparator ) ;\
  DBG_PRINT("\nAfter:\t"); DISPARR(macro_type_to_format_str(lst[0]), lst);\
} while(0)

static inline int test_qsort_macro(void)
{
	int arr0[] = { 1,2,3,2,1 };
	QSORT_TEST_DRIVER(arr0, qsort_int_comparator_);

	double arr1[] = { 1,2,3,2,1 };
	QSORT_TEST_DRIVER(arr1, qsort_double_comparator_);

	bool arr2[] = { 1,0,0,0,1 };
	QSORT_TEST_DRIVER(arr2, qsort_bool_comparator_);

	char arr3[] = "BUMBELENDUNDU";
	QSORT_TEST_DRIVER(arr3, qsort_char_comparator_);

	return 42;
}

#undef QSORT_TEST_DRIVER
#undef DISPARR
#undef QSORT
#undef CHOOSE_COMPARATOR
#undef COMPARATOR

