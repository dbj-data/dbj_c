#ifndef DBJ_CAPI_DEFAULT_LOG
#define DBJ_CAPI_DEFAULT_LOG
// (c) 2021 by dbj@dbj.org https://dbj.org/license_dbj
#include "ccommon.h"
#include "cdebug.h"
#include "dbj_windows_include.h"
#include <io.h>
#include <stdarg.h>
// --------------------------------------------------------------
DBJ_EXTERN_C_BEGIN

typedef struct dbj_redirector_state
{
    bool redirected;
    int fd;
    fpos_t pos;
    FILE *stream;
} dbj_redirector_state;

static inline dbj_redirector_state *dbj_redirector_state_(void);
static inline void dbjcapi_redirector_on(const char [static 1]);
static inline void dbjcapi_redirector_off(void);

/// --------------------------------------------------------------
/// user can provide the actual log function
/// the required signature is
///
/// extern "C" void (*user_log_FP) (const char* file, long line, const char* , ...);
///
/// the simplest way to use this from windows app
/// might be to redirect stderr to a file
/// https://stackoverflow.com/questions/14543443/in-c-how-do-you-redirect-stdin-stdout-stderr-to-files-when-making-an-execvp-or

static inline void dbj_default_log_function(const char *filename, long lineno, const char *format, ...)
{
    assert(filename && lineno && format);
    va_list args;
    char buffer[BUFSIZ] = {0};

    va_start(args, format);
    vsnprintf(buffer, sizeof buffer, format, args);
    va_end(args);

    fprintf(stderr, "\n%s(%lu) : %s", filename, lineno, buffer);
    fflush(stderr);
}

/// -----------------------------------------------------
/// redirect stderr to file
/// warning: not enough error checking

static inline dbj_redirector_state *dbj_redirector_state_(void)
{
    static dbj_redirector_state
        dbj_redirector_state_instance = {false};
    return &dbj_redirector_state_instance;
}

static inline void dbjcapi_redirector_on(const char filename[static 1])
{
    dbj_redirector_state *state = dbj_redirector_state_();

    if (state->redirected)
        return;

    fflush(stderr);
    fgetpos(stderr, &state->pos);
    state->fd = _dup(_fileno(stderr));
    errno_t err = freopen_s(&state->stream, filename, "w", stderr);

    if (err != 0)  DBJ_FAST_FAIL ;

    SYSTEMTIME lt;
    GetLocalTime(&lt);

    fprintf(stderr, "\n\n");
    fprintf(stderr, "\n*****                                                                     *****");
    fprintf(stderr, "\n*****  LOG BEGIN                                                          *****");
    fprintf(stderr, "\n*****                                                                     *****");
    fprintf(stderr, "\n\nLocal time:%4d-%02d-%02d %02d:%02d:%02d\n\n", lt.wYear, lt.wMonth, lt.wDay, lt.wHour, lt.wMinute, lt.wSecond);
}

/// if you do this too soon printing to redirected
/// stderr might not outpout to file but to
/// non existent console
/// best just leave it to the OS to reset the stderr
static inline void dbjcapi_redirector_off(void)
{
#if 0
		fflush(stderr);
		int dup2_rezult_ = _dup2(fd, _fileno(stderr));
		_close(fd);
		clearerr(stderr);
		fsetpos(stderr, &pos);
#endif
}

// -----------------------------------------------------------------------------
DBJ_EXTERN_C_END
#endif DBJ_CAPI_DEFAULT_LOG