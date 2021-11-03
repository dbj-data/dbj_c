// ----------------------------------------------
#include "qsort_macro.h"
#include "common.h"

#ifndef __clang__
#define DBJ_DO_PRAGMA(x) _Pragma (#x)
#define DBJ_TODO(x) DBJ_DO_PRAGMA(message ("TODO - " #x))
// usage: DBJ_TODO(Remember to fix this);
#endif // ! __clang__

static void test_pint()
{
	DBG_PRINT("\nmacro_printval((unsigned char)'A') : ");
	 macro_printval((unsigned char)'A');
	DBG_PRINT("\nmacro_printval((signed char)'A') : ");
	 macro_printval((signed char)'A');
	DBG_PRINT("\nmacro_printval((char)'A') : ");
	 macro_printval((char)'A');

	 DBG_PRINT("\nmacro_printval(42) : ");
	 macro_printval(42);
	 DBG_PRINT("\nmacro_printval(13.00) : ");
	 macro_printval(13.00);
	 DBG_PRINT("\nmacro_printval(true) : ");
	 macro_printval(true);
	 DBG_PRINT("\nmacro_printval(\"A\") : ");
	 macro_printval("A");
}

// forget all but struct to achieve type/data encapsulation

// int test_square_matrix(void);
#include <windows.h>    

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	// test_square_matrix();

	DBJ_SX("%s", DBJ_CAPI_VERSION());
	test_pint();
	test_qsort_macro();

	return 0;
}

