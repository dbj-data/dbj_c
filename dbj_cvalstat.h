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

#include "dbj_ccommon.h"
#include <errno.h>

static errno_t OK = {};


#endif // DJB_VALSTAT_INC_