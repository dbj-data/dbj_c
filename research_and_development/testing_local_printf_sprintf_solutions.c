#include <float.h>

#ifndef BUFSIZ
#define BUFSIZ 512
#endif

#include "D:\MACHINE_WIDE\ubut\utest.h"
// 2021 MAY 24 -- dbj at dbj dot org
// https://godbolt.org/z/8K49Po5xs

#if (__clang__ || __GNUC__ )
#define _const_ __attribute__((__const__))
#define _pure_ __attribute__((__pure__))
#define _unused_ __attribute__((__unused__))
#define _cleanup_(x) __attribute__((__cleanup__(x)))
#define _destructor_ __attribute__((__destructor__))
#define _constructor_ __attribute__((__constructor__))
#else
#define _const_ 
#define _pure_ 
#define _unused_ 
#define _cleanup_(x) ((void)x)
#define _destructor_ 
#define _constructor_ 
#endif

// required in one compilation unit aka "C file"
#define STB_SPRINTF_IMPLEMENTATION

#ifdef DBJ_GODBOLT
#include <https: //raw.githubusercontent.com/nothings/stb/master/stb_sprintf.h>
#include <https: //raw.githubusercontent.com/dbj-data/dbj_c/master/nonstd/nano_printf.h>
#else
#include "D:\MACHINE_WIDE\dbj_c\nonstd\nano_printf.h"
#include "D:\MACHINE_WIDE\stb\stb_sprintf.h"
#endif // ! DBJ_GODBOLT


static inline void my_putc(void *p, char c)
{
#ifdef _MSC_VER

#ifdef _DEBUG
    int rez =
#endif
        _write(1, &c, 1);
#ifdef _DEBUG
    if (rez == -1)
        switch (errno)
        {
        case EBADF:
            perror("Bad file descriptor!");
            break;
        case ENOSPC:
            perror("No space left on device!");
            break;
        case EINVAL:
            perror("Invalid parameter: buffer was NULL!");
            break;
        default:
            // An unrelated error occurred
            perror("Unexpected error!");
        }
#endif

#else
    // make sure putc is a function, not a macro
    (putc)(c, stdout);
#endif // ! _MSC_VER
}

_constructor_ static inline void nano_print_init(void)
{
    nano_init_printf(NULL, my_putc);
}

#define FASTPRINT_SHOW(F_, V_)                                          \
    do                                                       \
    {                                                        \
        char bufy[BUFSIZ] = {0};                             \
        int rez = stbsp_snprintf(bufy, BUFSIZ, F_, V_);      \
        nano_printf("rez: %d, buffer: %s\n", rez, bufy); \
    } while (0)


// #include <stdio.h>

#define STDPRINT_SHOW(F_, V_)                                          \
    do                                                       \
    {                                                        \
        char bufy[BUFSIZ] = {0};                             \
        int rez = _snprintf(bufy, BUFSIZ, F_, V_);      \
        printf("rez: %d, buffer: %s\n", rez, bufy); \
    } while (0)


UTEST(dbj_fast_pint_bench, std_c_lib)
{
   fprintf( stderr, UBUT_VT_RESET) ;
    fprintf( stdout, UBUT_VT_RESET "\n\n") ;

    STDPRINT_SHOW("%$$$.2d", 253600000); // stb extension format char
    STDPRINT_SHOW("FLT_RADIX       = %d", FLT_RADIX);
    STDPRINT_SHOW("DECIMAL_DIG     = %d", DECIMAL_DIG);
    STDPRINT_SHOW("FLT_MIN         = %e", FLT_MIN);
    STDPRINT_SHOW("FLT_MAX         = %e", FLT_MAX);
    STDPRINT_SHOW("FLT_EPSILON     = %e", FLT_EPSILON);
    STDPRINT_SHOW("FLT_DIG         = %d", FLT_DIG);
    STDPRINT_SHOW("FLT_MANT_DIG    = %d", FLT_MANT_DIG);
    STDPRINT_SHOW("FLT_MIN_EXP     = %d", FLT_MIN_EXP);
    STDPRINT_SHOW("FLT_MIN_10_EXP  = %d", FLT_MIN_10_EXP);
    STDPRINT_SHOW("FLT_MAX_EXP     = %d", FLT_MAX_EXP);
    STDPRINT_SHOW("FLT_MAX_10_EXP  = %d", FLT_MAX_10_EXP);
    STDPRINT_SHOW("FLT_ROUNDS      = %d", FLT_ROUNDS);
    STDPRINT_SHOW("FLT_EVAL_METHOD = %d", FLT_EVAL_METHOD);
    STDPRINT_SHOW("FLT_HAS_SUBNORM = %d", FLT_HAS_SUBNORM);
}

  UTEST_STATE; // note there is no ()!  
  int main(int argc, const char *const argv[]) { 

    #if ! (__clang__ || __GNUC__ )
    nano_print_init();
    #endif

    utest_main(argc, argv);      

    fprintf( stderr, UBUT_VT_RESET) ;
    fprintf( stdout, UBUT_VT_RESET) ;

    return 0;
  }