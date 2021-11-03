#pragma once

#include "../../cdebug.h"

typedef char *char_star;
typedef signed char signed_char;
typedef unsigned char unsigned_char;

// beware: result of this macro is not a string literal
#undef macro_type_to_format_str
#define macro_type_to_format_str(x) _Generic((x),                     \
                                             bool                     \
                                             : "%4d",                 \
                                               char                   \
                                             : "%c",                  \
                                               signed_char            \
                                             : "%c",                  \
                                               unsigned_char          \
                                             : "%c",                  \
                                               signed short           \
                                             : "%hd",                 \
                                               unsigned short         \
                                             : "%hu",                 \
                                               signed int             \
                                             : "%d",                  \
                                               unsigned int           \
                                             : "%u",                  \
                                               long int               \
                                             : "%ld",                 \
                                               unsigned long int      \
                                             : "%lu",                 \
                                               long long int          \
                                             : "%lld",                \
                                               unsigned long long int \
                                             : "%llu",                \
                                               float                  \
                                             : "%f",                  \
                                               double                 \
                                             : "%f",                  \
                                               long double            \
                                             : "%Lf",                 \
                                               char_star              \
                                             : "%s",                  \
                                               default                \
                                             : "%p")

#undef macro_printval
/* note: this is visible only in debug mode and in the debug out stream */
#define macro_printval(v) DBG_PRINT(macro_type_to_format_str((v)), (v))

// GUSTEDT -- Modern C, Page: 237

/**
** @brief Traces a value without having to specify a format
 **
 ** This variant works correctly with pointers .
 **
 ** The formats are tunable by changing the specifiers in
 ** :: TRACE_FORMAT .
 **/
#define TRACE_ON
#define STRGY DBJ_STRINGIZE
#define TRACE_VALUE(F, X)                                          \
    do                                                             \
    {                                                              \
        if (TRACE_ON)                                              \
            fprintf(stderr,                                        \
                    TRACE_FORMAT("%s:" STRGY(__LINE__) ":␣" F, X), \
                    __func__, TRACE_CONVERT(X));                   \
    } while (false)

#define TRACE_FORMAT(F, X) _Generic((X) + 0LL,          \
                                     unsigned long long  \
                                     : "" F "␣%llu\n",   \
                                       long long         \
                                     : "" F "␣%lld\n",   \
                                       float             \
                                     : "" F "␣ %.8 f\n", \
                                       double            \
                                     : "" F "␣ %.1\n",   \
                                       long double       \
                                     : "" F "␣ %.Lf\n",  \
                                       default           \
                                     : "" F "␣%p\n")

/**
 ** @brief Returns a value that forcibly can be interpreted as
 ** pointer value
 **
 ** That is , any pointer will be returned as such , but other
 ** arithmetic values will result in a @c 0.
 **/
#define TRACE_POINTER(X) _Generic((X) + 0LL,              \
                                   unsigned long long : 0, \
                                   long long : 0,          \
                                   float : 0,              \
                                   double : 0,             \
                                   long double : 0,        \
                                   default                 \
                                   : (X))

/**
 ** @brief Returns a value that is promoted either to a wide
 ** integer , to a floating point , or to a @c void * if @a X is a
 ** pointer
 **/
#define TRACE_CONVERT (X) _Generic((X) + 0LL,         \
                                   unsigned long long \
                                   : (X) + 0LL,       \
                                     long long        \
                                   : (X) + 0LL,       \
                                     float            \
                                   : (X) + 0LL,       \
                                     double           \
                                   : (X) + 0LL,       \
                                     long double      \
                                   : (X) + 0LL,       \
                                     default          \
                                   : ((void *){0} = TRACE_POINTER(X)))
