
#pragma once
#ifndef CDEBUG_INC_
#define CDEBUG_INC_
/*
this is bottom line everything might use this
thus no dependancies beside crt and win32
*/

#ifdef __clang__
#pragma clang system_header
#endif

#include "ccommon.h"
#include <stdarg.h>

// -----------------------------------------------------------------------------
DBJ_EXTERN_C_BEGIN

#pragma region DBJ_OUTPUT_DBG_STRNG
/// EXECUTIVE DECISION :) Only WIN code
#ifdef _DEBUG
  static inline void DBJ_OUTPUT_DBG_STRNG(const char * lpszFormat, ...);
#else
  #define DBJ_OUTPUT_DBG_STRNG __noop
#endif

#ifndef OutputDebugString
__declspec(dllimport) 
void
__stdcall
OutputDebugStringA(
    const char * const /*lpOutputString*/
    );
#endif // !OutputDebugString

#ifdef _DEBUG
static inline void DBJ_OUTPUT_DBG_STRNG(const char * format_, ...)
{
	char buffy[1024] = {0} ;
	int nBuf = 0 ;
	va_list args = 0;
	va_start(args, format_);
	nBuf = _vsnprintf(buffy, 1024, format_, args);
	// _ASSERTE(nBuf > -1,"_vsnprintf() buffer overflow");
	if (nBuf > -1)
		OutputDebugStringA(buffy);
	else
		OutputDebugStringA("DBJ_OUTPUT_DBG_STRNG buffer overflow\n");
	va_end(args);
}
#endif

#pragma endregion 
/*
	terror == terminating error
	NOTE: all the bets are of so no point of using some clever logging
	*/
static inline void dbj_capi_terror(const char *msg_, const char *file_, const int line_)
{
	DBJ_ASSERT(msg_ && file_ && line_);
	// all the bets are of sat this point
	// thus not using some fancy logging
	fputs(msg_, stderr) ;
	perror(DBJ_ERR_PROMPT("\nTerminating error!\n"));
	exit(EXIT_FAILURE);
}

/*
2020 SEP 03 -- it turns out (again) we need to initialize WIN10 terminal
to show us VT100 colours
*/
static inline bool dbj_win_vt100_initor_()
{
	// yes this is a hack and yes this works
	system(" ");
	return true;
};

// name DBG_PRINT  indicates there is NO release print from here
// -----------------------------------------------------------------------------
#undef DBG_PRINT
#ifdef _DEBUG
#define DBG_PRINT(...) DBJ_OUTPUT_DBG_STRNG(__VA_ARGS__)
#else
#define DBG_PRINT(...) __noop
#endif // ! _DEBUG
///	-----------------------------------------------------------------------------------------
// CAUTION! DBJ_VERIFY works in release builds too
#undef DBJ_VERIFY
#undef DBJ_VERIFY_

// x should be bool type here
#define DBJ_VERIFY_(x, file, line) \
	if (false == (x))                \
	dbj_capi_terror("Expression: " #x ", failed ", file, line)

#define DBJ_VERIFY(x) DBJ_VERIFY_((x), __FILE__, __LINE__)

// very often this is used in release builds on some
// "impossible" error
#undef DBJ_PERROR
#define DBJ_PERROR (perror(__FILE__ " # " _CRT_STRINGIZE(__LINE__)))

#undef DBJ_FERROR
#ifdef _DEBUG
#define DBJ_FERROR(FP_)       \
	do                        \
	{                         \
		if (ferror(FP_) != 0) \
		{                     \
			DBJ_PERROR;       \
			clearerr_s(FP_);  \
		}                     \
	} while (0)
#else
#define DBJ_FERROR(FP_)
#endif // _DEBUG

#undef DBJ_FAST_FAIL
#ifdef _DEBUG
#define DBJ_FAST_FAIL       \
	do                      \
	{                       \
		DBJ_PERROR;         \
		__debugbreak();     \
	} while (0)
#else // !_DEBUG
#define DBJ_FAST_FAIL       \
	do                      \
	{                       \
		DBJ_PERROR;         \
		exit(EXIT_FAILURE); \
	} while (0)
#endif // ! NDEBUG

#undef DBJ_PP
// pointer pretty print
// using the advice as per https://stackoverflow.com/a/9053835/10870835
// outcome: same as using '%p` but in all cappitals
// https://godbolt.org/z/eqTsYneP6
#define DBJ_PP(X_)                                  \
	DBG_PRINT("\n%16s : %4d : %8s :\t 0x%" PRIXPTR, \
			  __FILE__, __LINE__, #X_, (uintptr_t)(X_))

	// in this version F_ does not have to be string literal
#undef DBJ_SX
// Show eXpression
#define DBJ_SX(F_, x_)                                                \
	do                                                                \
	{                                                                 \
		DBG_PRINT("\n%4d | %s | %16s : ", __LINE__, __FILE__, (#x_)); \
		DBG_PRINT(F_, (x_));                                          \
	} while (0)

// boolean expression to string
#undef DBJ_TF
#define DBJ_TF(a) (a ? "true" : "false")

// make it a run-time affair
static inline void dbj_print_bool_result(const int line, const char *file, const char *expression, const bool result)
{
	DBG_PRINT("\n%4d | %s | %16s : %s", line, file, expression, (result ? "true" : "false"));
}

#undef PRINB
#define PRINB(x) dbj_print_bool_result(__LINE__, __FILE__, (#x), (x))

DBJ_EXTERN_C_END

#endif // CDEBUG_INC_
