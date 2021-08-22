#ifndef macro_begin_end_defer_inc_
#define macro_begin_end_defer_inc_

#include "ccommon.h"

/*
  first seen it here https://youtu.be/QpAhX-gsHMs
  2021-APR  dbj@dbj.org added macro defer()
*/
/*

  Two Macros:

  beginend( on_scope_begin(), on_scope_end() ) { ... inside scope ... }

  defer( on_scope_end() ) { ... inside scope ... }

  Q: What might be good about this two macros? 
  A: They work on any C/C++ version, using any compiler.
     Both macros are for(){ } that loops once

     https://godbolt.org/z/6Y8Ys4dPo
*/

#ifdef __linux__
#include <unistd.h> // readlink
#endif

// -----------------------------------------------------------------------------
DBJ_EXTERN_C_BEGIN

#define macro_concat_(a, b) a##b
#define macro_concat(a, b) macro_concat_(a, b)
#define macro_var(name) macro_concat(name, __LINE__)

#define beginend(start, end) for (int macro_var(_i_) = (start, 0); !macro_var(_i_); (macro_var(_i_) += 1, end))

static inline void do_nothing_(void) {}
// #define defer( at_scope_end ) beginend( __LINE__, at_scope_end )
#define defer(at_scope_end) for (int macro_var(_i_) = 0; !macro_var(_i_); (macro_var(_i_) += 1, at_scope_end))

/*
 Ad-hoc demo
*/
#ifdef macro_begin_end_defer_adhoc_demo
#undef B
#undef P
#undef M
// NOTE: F must be a string literal
#define B(X_) (X_) ? "true" : "false"
#define P(F, X_) fprintf(stdout, "\n%04d : %16s :\t" F, __LINE__, #X_, (X_))
#define M(S) fprintf(stdout, "\n%04d : %16s :\t%s", __LINE__, " ", S)

static void here_() { M("Begin!"); }
static void there_() { M("End!"); }

static void make_(char **ptr, size_t sze_)
{
    *ptr = calloc(sze_, sizeof(char));
    printf("\nmade  (%p) char [%zu]", *ptr, sze_);
}
static void free_(void *ptr)
{
    printf("\nfreed (%p)", ptr);
    free(ptr);
    ptr = NULL;
}

static void close_file(FILE *fp_)
{
    if (fp_ == NULL)
    {
        M("close_file(): Avoiding NULL file pointer");
        return;
    }
    if (ferror(fp_))
        perror("I/O error");
    P("closing FILE * (%p)", fp_);
    fclose(fp_);
}

int macro_begin_end_defer_ad_hoc(void)
{
    beginend(here_(), there_())
    {
        M("Work.");
    }

    char *bufy_ = 0;
    printf("\n");

    beginend(make_(&bufy_, 0xFF), free_(bufy_))
    {
        memcpy(bufy_, "DATA", 5);
        printf("\nusing (%p) : \"%s\"", bufy_, bufy_);
    }

    printf("\n");
    FILE *dummsy_ = tmpfile();

    defer(close_file(dummsy_))
    {
        P("temp FILE * (%p)", dummsy_);

#ifdef __linux__
        // Linux-specific
        char fname[FILENAME_MAX] = {0}, link[FILENAME_MAX] = {0};
        sprintf(fname, "/proc/self/fd/%d", fileno(dummsy_));
        P("temp FILE name: %s", fname);
        if (readlink(fname, link, sizeof link - 1) > 0)
            P("temp FILE link: %s", link);
#endif // __linux__
    }

    return 42;
}

#undef B
#undef P
#undef M

#endif // macro_begin_end_defer_adhoc_demo

// -----------------------------------------------------------------------------
DBJ_EXTERN_C_END

#endif macro_begin_end_defer_inc_
