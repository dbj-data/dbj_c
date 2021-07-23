// https://godbolt.org/z/1565sYvGa
// ----------------------------------------------
// clang-cl /Zi main.c for debugging
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VERIFY(X) do { if (!(X)) { perror(__FILE__ ", Internal fatal error: " #X "\nsystem error: "); exit(0); } } while(0)

#define B(X_) (X_) ? "true" : "false"
#define P(F,X_) fprintf( stdout, "\n%4d : %16s : " F, __LINE__, #X_, (X_))

// https://stackoverflow.com/a/19453814/10870835
#define IS_INDEXABLE(arg) (sizeof(arg[0]))
#define IS_ARRAY(arg) (IS_INDEXABLE(arg) && (((void *) &arg) == ((void *) arg)))
#define ARRAYSIZE(arr) (IS_ARRAY(arr) ? (sizeof(arr) / sizeof(arr[0])) : 0)

// the legend says this is from some GOOGLE project
#undef COUNT_OF
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

// safer strcmp
static int char_arr_compare_ (
    const size_t N, const size_t M, 
    const char (*L)[N], 
    const char (*R)[M])
{
     VERIFY( L && R );
     // are lengths > 0
     VERIFY( N > 0 && M > 0 );
     // are zeroes where they are supposed to be
     // VERIFY( 0 == ((*L)[N]) );
     // VERIFY( 0 == ((*R)[M]) );

    // return strcmp(*L, *R ) ;

    const char * str1 = &(*L)[0] ;
    const char * str2 = &(*R)[0] ;
    // https://codereview.stackexchange.com/a/31954/179062
    // while (*str1 && *str1 == *str2) {
    // dbj changed to:
    size_t k = 0 ;
    while ((k++ < N) && *str1 == *str2) {
            str1++;
            str2++;
    }
    return *str1 - *str2;
}

#undef  COMPARR
// macro front is OK for string literals
// and char arrays
// COUNT_OF includes the EOS char, hence the -1
// #define COMPARE(A,B) safer_strcmp_( COUNT_OF(A) - 1 ,COUNT_OF(B) - 1, &A, &B )
#define COMPARR(A,B) char_arr_compare_( COUNT_OF(A), COUNT_OF(B), &A, &B )

int main(void) {

  // does not compile P("%d", COMPARE( NULL,"")) ;
  // does not copile  P("%d", COMPARE("","")) ;
  P("%d", COMPARR("A","B")) ;
  P("%d", COMPARR("B","A")) ;
  P("%d", COMPARR("A","A")) ;
  P("%d", COMPARR("AA","A")) ;
  P("%d", COMPARR("A","AA")) ;

  const char nozero[] = {'N', 'O', 'Z', 'E', 'R', 'O'};
  const char nzA[] = {'A'};
  const char nzB[] = {'B'};
  P("%d", COMPARR( nozero,nozero)) ;
  P("%d", COMPARR( nzA,nzB)) ;

  return 0 ;
}
