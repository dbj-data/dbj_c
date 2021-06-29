#pragma once
// (c) 2021 dbj at dbj dot org
// https://dbj.org/license_dbj

/*
once and for all ... what is matrix in C

note: going beyond this means repeating what is already done elsewhere
for example here:

- https://github.com/nothings/stb
- https://github.com/troydhanson/uthash
- https://github.com/mattiasgustavsson/libs

etc...
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// underlying C memory model has only 1D arrays
// in C matrix is "array of arrays"
// NOTE: it does not have to be "square", this is just an example
enum
{
    // max rows
    dbj_c_matrix_sampler_R = 0xFF,
    // max columns
    dbj_c_matrix_sampler_C = R
};

// this is a callback
// we know there is 0 ... R-1 of int[C] arrays
void dbj_c_matrix_sampler_filler_function(const int C, int (*matrix)[C])
{
    matrix[dbj_c_matrix_sampler_R / 2][C / 2] = 42;
}

// now focus and pay attention
int dbj_c_matrix_sampler(void)
{

    // in C matrix is "array of arrays"
    // thus: int[C] repeated R times
    // here we declare AND define a pointer to the matrix of ints
    int(*matrix_ap)[dbj_c_matrix_sampler_R][dbj_c_matrix_sampler_C] = malloc(sizeof(int[dbj_c_matrix_sampler_R][dbj_c_matrix_sampler_C]));

    // matrix[][] is the approach humans know and love
    // we will cast to it
    // matrix is the array pointer  to the first "array of arrays"
    int(*matrix)[dbj_c_matrix_sampler_C] = (int(*)[dbj_c_matrix_sampler_C])matrix_ap;

    // notice how inside we can use the [][] indexing
    dbj_c_matrix_sampler_filler_function(dbj_c_matrix_sampler_C, matrix);
    
    // and here too
    assert(matrix[dbj_c_matrix_sampler_R / 2][dbj_c_matrix_sampler_C / 2] == 42);

    // only one simple free
    free(matrix_ap);
}

//////////////////////////////////////////////////
///
///  And this is how one does VMT matrix AND encapsulated VMT matrix
///
///  VMT: Variably Modified Type
///       https://gustedt.wordpress.com/2011/01/09/dont-be-afraid-of-variably-modified-types/
///
//////////////////////////////////////////////////
/// dbj at dbj dot org
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#undef P
#define P(F, X) printf("\n%4d: %32s: " F, __LINE__, #X, (X))
//////////////////////////////////////////////////
void print_arr(const unsigned sze, char arr[sze])
{

    const int rowlen = 80;
    int counter = 0;
    printf("\n");
    for (int j = 0; j < sze; j++)
    {
        printf("[%5d:%2c]%s", j, arr[j], (++counter % rowlen ? "" : "\n"));
    }
}

//////////////////////////////////////////////////
//  VMT = Variably Modified Types
// the actual matrix type is hidden from the callers
#undef MATRIXHANDLE
#define MATRIXHANDLE void *
// anonymous struct made of two members
#undef MATRIXTYPE
#define MATRIXTYPE(T, R, C) \
    struct                  \
    {                       \
        T(*a)               \
        [R * C];            \
        T(*b)               \
        [C];                \
    }

// here we will code the matrix of chars, API
// this one should really be a macros so we can make it "generic"
// super-duper generic solution will be macros
// here we teach  so we will not do that
MATRIXHANDLE make_matrix_vmt(unsigned R, unsigned C)
{
    // note how we MUST repeat the actuall matrix
    // declaration definition in each function
    // this actually give the named struct
    typedef MATRIXTYPE(char, R, C)  matrix;
    matrix *new_mx = malloc(sizeof(matrix));
    new_mx->a = malloc(sizeof(char[R * C]));
    new_mx->b = new_mx->a;
    return new_mx;
}
//////////////////////////////////////////////////
// instead of passing the matrix arround we pas the MATRIXHANDLE
static void matrix_vmt_print(MATRIXHANDLE mx, unsigned R, unsigned C)
{
    // we deal only with char matrix in here
    typedef MATRIXTYPE(char, R, C)  matrix;
    // we cast from the handle to the actual matrix
    matrix *new_mx = (matrix *)mx;
    matrix mx1 = *new_mx;
    char *cp = *mx1.a;
    const int len = R * C;
    print_arr(len, cp);
}
//////////////////////////////////////////////////
//
typedef void (*array_user)(void *, const int);

static void *matrix_vmt_foreach(MATRIXHANDLE mx, unsigned R, unsigned C, array_user cback)
{
    typedef MATRIXTYPE(char, R, C) matrix;
    matrix *new_mx = (matrix *)mx;
    matrix mx1 = *new_mx;
    char *cp = *mx1.a;
    const int len = R * C;

    for (int j = 0; j < len; j++)
        cback(cp, j);

    return new_mx;
}

void free_matrix_vmt(MATRIXHANDLE vptr, unsigned R, unsigned C)
{
    typedef MATRIXTYPE(char, R, C) matrix;
    matrix *mx = (matrix *)vptr;
    free(mx->a);
    free(mx);
    mx = NULL;
}
//////////////////////////////////////////////////
// above is the "framework" bellow is using it
enum
{
    R = 150,
    C = 150,
    DATALEN = R * C
};

// this is a callback for matrix_vmt_foreach()
// required footprint: typedef void (*array_user)(void * , const int );
void my_user(void *arr, const int idx)
{
    assert(DATALEN > idx);
    static int counter = 0;
    static char letter = 'A';

    counter = counter % 26;
    counter++; // re-starts from 1

    letter = '@' + (char)counter;

    char *chararr = (char *)arr;
    *(chararr + idx) = letter;
}

//////////////////////////////////////////////////
///
int dbj_matrix_vma_sampler(void)
{
    P("%d", DATALEN);
    // MATRIXHANDLE is "typeless"
    MATRIXHANDLE mxvmt = make_matrix_vmt(R, C);
    mxvmt = matrix_vmt_foreach(mxvmt, R, C, my_user);
    /// matrix_vmt_print( mxvmt, R,C ) ;
    free_matrix_vmt(mxvmt, R, C);

    return EXIT_SUCCESS;
}