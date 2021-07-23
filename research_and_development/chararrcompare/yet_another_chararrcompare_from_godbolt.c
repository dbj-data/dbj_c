// https://godbolt.org/z/d3xKjzx6s
// https://dbj.org/license_dbj
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#undef MIN
#define MIN(a,b) (((b) < (a)) ? (b) : (a))

// in this version F_ does not have to be string literal
 #undef PRINT
// Show eXpression 
#define PRINT(F_, x_) do { \
printf("\n%4d | %s | %16s : ", __LINE__, __FILE__, (#x_));\
printf( F_, (x_));\
} while(0)

// make it a run-time affair
inline static void dbj_print_bool_result 
( const int line, const char * file, const char *  expression, const bool result ) { 
    printf("\n%4d | %s | %-24s : %s", line, file, expression, (result ? "true" : "false") );
}

#undef  PRINB
#define PRINB(x) dbj_print_bool_result( __LINE__, __FILE__, (#x),(x))

// The legend says this is from some GOOGLE project, perhaps called "Chromium"?
// basically use any macro you fancy, as long as it works 
// like this one 
#undef COUNT_OF
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

// macros are working for string literals
// and arrays, but not for pointers
// in any case COUNT_OF will  not compile
// id A and B are not arrays
#define COMPSTR(A,B) (0 == strncmp( A, B, MIN( COUNT_OF(A), COUNT_OF(B) )))
// above I keep but the bellow works ok so far
// if lengths are different arrays are different
#define COMPARR(A,B) ( COUNT_OF(A) == COUNT_OF(B) ? (0 == memcmp( A, B, COUNT_OF(A))) : false  )

int main (void)
{
    // arrays, not string literals
  const char nz[] = {'N', 'O', 'Z', 'E', 'R', 'O'};
  const char nzA[] = {'A'};
  const char nzB[] = {'B'};

// proper string literal is const char []
// not pointer!
  const char slit_1 [] = "LITERAL 1";
  const char slit_2 [] = "LITERAL 2";

  const char * bad_slit_1 = "LITERAL 2";
  PRINB( COMPSTR(slit_1,slit_1) );


  printf("\n\nIt appears one can use memcmp only:\n");

  PRINB( COMPARR(slit_1,slit_1) );
  PRINB( COMPARR(slit_1,slit_2) );
  PRINB( COMPARR("A",slit_1) );

  PRINB( COMPARR("A","A") );
  PRINB( COMPARR("A","B") );
  PRINB( COMPARR("A","a") );
  PRINB( COMPARR("A",nzA) );
  PRINB( COMPARR(nzA,nzA) );
  PRINB( COMPARR(nzA,nz ) );

    printf("\n\n use memcmp and non char arrays\n");
  const int arrA[] = {0,1,2};
  const float arrB[] = {3.1,4.2,5.3};
  const int arrC[] = {3,4,5};

  PRINB( COMPARR(arrA, arrA ) );
  PRINB( COMPARR(arrA, arrB ) );
  PRINB( COMPARR(arrC, arrB ) );
}