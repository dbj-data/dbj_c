#pragma once
#ifndef DBJ_WINDOWS_INCLUDE_INC_
#define DBJ_WINDOWS_INCLUDE_INC_
/* 
(c) 2019-2021 by dbj.org   -- LICENSE DBJ -- https://dbj.org/license_dbj/ 
*/
#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#define NOMINMAX
#define STRICT 1
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#undef  min
#define min(x, y) ((x) < (y) ? (x) : (y))

#undef MIN
#define MIN min

#undef  max
#define max(x, y) ((x) > (y) ? (x) : (y))

#undef MAX
#define MAX max

#endif // DBJ_WINDOWS_INCLUDE_INC_
