#ifndef DJB_VALSTAT_INC_
#define DJB_VALSTAT_INC_

// (c) 2021 https://dbj.org/license_dbj

/*
C valstat is EXTREMELY simple

typedef struct {
  T * val ;
  errno_t stat;
} valstat__##T ;

Empty val is 0
Empty stat is 0

*/

#include "ccommon.h"
#include <errno.h>

DBJ_EXTERN_C_BEGIN

static errno_t OK = {};

#define DBJ_DECLARE_VALSTAT(T) \
  typedef struct               \
  {                            \
    T *val;                    \
    errno_t stat;              \
  } 

// val is a pointer
#define DBJ_EMPTY_VAL( VAL_ )  (VAL_ == 0)
// stat type is errno_t
#define DBJ_EMPTY_STAT( STAT_ )  (STAT_ == 0)

// here we declare valstat for fundamental types we might need

DBJ_DECLARE_VALSTAT(bool) valstat_bool ;
DBJ_DECLARE_VALSTAT(char) valstat_char ;
DBJ_DECLARE_VALSTAT(int) valstat_int ;
DBJ_DECLARE_VALSTAT(long) valstat_long ;
DBJ_DECLARE_VALSTAT(float) valstat_float ;
DBJ_DECLARE_VALSTAT(double) valstat_double ;


DBJ_EXTERN_C_END

#endif // DJB_VALSTAT_INC_