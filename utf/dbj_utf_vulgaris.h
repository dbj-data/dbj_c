#ifndef DBJ_UTF_8_VULGARIS_INC
#define DBJ_UTF_8_VULGARIS_INC
/* ------------------------------------------------------------------------------- */
/* attempt to use the standard C almost only :)                                    */
/* (c) 2021 by dbj@dbj.org                                                         */
/* should be a stand alone header, not yet battle tested                           */
/* inspired by https://utf8everywhere.org                                          */
/* ------------------------------------------------------------------------------- */
/* CAUTION: Lowest supported os is WIN10                                           */
/* ------------------------------------------------------------------------------- */
#ifdef _MSC_VER
#define _WIN32_WINNT 0x0A00
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <crtdbg.h>
#endif // _MSC_VER

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <uchar.h>
#include <stdint.h>
#include <locale.h>
#include <limits.h>

/* good enough, clang/gcc will complain bitterly if array in here is a pointer */
#define dbj_count(array) (sizeof(array) / sizeof(array[0]))

#ifndef CP_UTF8
#define CP_UTF8 65001 // UTF-8 translation, from winnls.h
#endif                // CP_UTF8

#ifndef BUFSIZ
#define BUFSIZ 1024
#endif // BUFSIZ

/* ----------------------------------------------------------------------------------------- */
/* char16 and char32 string lengths? Wunderbar!?                                             */
/* Beware: char 16/32 arrays are almost always 0 delimited  but that is not guaranteed!      */
/* ----------------------------------------------------------------------------------------- */
inline size_t sizeof_zero_delimited_arr_16(const char16_t in[static 1])
{
    static const size_t MAX_POSSIBLE_SIZE = SHRT_MAX;
    size_t rez = 0;
    char16_t *walker = (char16_t *)in;
    while (*walker != 0)
    {
        assert(rez < MAX_POSSIBLE_SIZE);
        rez += 1;
        ++walker;
    }
    return rez + 1;
}
inline size_t sizeof_zero_delimited_arr_32(const char32_t in[static 1])
{
    static const size_t MAX_POSSIBLE_SIZE = INT_MAX;
    size_t rez = 0;
    char32_t *walker = (char32_t *)in;
    while (*walker != 0)
    {
        assert(rez < MAX_POSSIBLE_SIZE);
        rez += 1;
        ++walker;
    }
    return rez + 1;
}
/* ----------------------------------------------------------------------------------------- */
// the multibyte character encoding is specified by the currently active C locale!
// is the currently active C locale the one you wanted?
/* ----------------------------------------------------------------------------------------- */
static inline char *dbj_u16_to_mb(const char16_t in[static 1])
{
    static mbstate_t state;
    static const size_t NPOS = (size_t)-1;

    const size_t in_sz = sizeof_zero_delimited_arr_16(in);
    assert(in_sz > 0);
    assert(in[in_sz - 1] == (char16_t)0);

    const size_t out_size_ = MB_CUR_MAX * in_sz;

    assert(out_size_ < SHRT_MAX); // does this make sense?

    char *out = calloc(out_size_, sizeof(char));
    assert(out);

    char *p = out;
    for (size_t n = 0; n < in_sz; ++n)
    {
        size_t rc = c16rtomb(p, in[n], &state);
        if (rc == NPOS)
            break;
        p += rc; // move the pointer by the size returned from c16rtomb
    }

    return out;
}

static inline char *dbj_u32_to_mb(const char32_t in[static 1])
{
    static mbstate_t state;
    static const size_t NPOS = (size_t)-1;

    const size_t in_sz = sizeof_zero_delimited_arr_32(in);
    assert(in_sz > 0);
    assert(in[in_sz - 1] == (char32_t)0);

    const size_t out_size_ = MB_CUR_MAX * in_sz;

    assert(out_size_ < INT_MAX); // does this make sense?

    char *out = calloc(out_size_, sizeof(char));
    assert(out);

    char *p = out;
    for (size_t n = 0; n < in_sz; ++n)
    {
        size_t rc = c32rtomb(p, in[n], &state);
        if (rc == NPOS)
            break;
        p += rc; // move the pointer by the size returned from c32rtomb
    }

    return out;
}

/* ----------------------------------------------------------------------------------------- */
/* Beware: Strong advice is not to use wchar_t but onlyt when/if calling WIN32 API!          */
/* https://utf8everywhere.org                                                                */
/* ----------------------------------------------------------------------------------------- */
#ifdef _WIN32
static inline wchar_t *dbj_wide(const char *const narrow_str_)
{
    SetLastError(0);
    const int slength = (int)strlen(narrow_str_) + 1;
    int len = MultiByteToWideChar(CP_UTF8, 0, narrow_str_, slength, 0, 0);
    _ASSERTE(len > 0);
    wchar_t *rez = (wchar_t *)calloc(len, sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, narrow_str_, slength, rez, len);
    _ASSERTE(!GetLastError());
    return rez;
}

static inline char *dbj_narrow(wchar_t *wide_str_)
{
    SetLastError(0);
    const int slength = (int)wcslen(wide_str_) + 1;
    int len = WideCharToMultiByte(CP_UTF8, 0, wide_str_, slength, 0, 0, 0, 0);
    _ASSERTE(len > 0);
    char *rez = (char *)calloc(len, sizeof(char));
    WideCharToMultiByte(CP_UTF8, 0, wide_str_, slength, rez, len, 0, 0);
    _ASSERTE(!GetLastError());
    return rez;
}
#endif // _WIN32
/* ----------------------------------------------------------------------------------------- */
#ifdef TESTING_DBJ_UTF_8_VULGARIS
/* ----------------------------------------------------------------------------------------- */

#if defined(__linux__) || (_WIN32_WINNT == 0x0A00)
#define UBUT_VT_ESC "\x1b["
#define UBUT_VT_RESET UBUT_VT_ESC "0m"
#define UBUT_VT_GRAY UBUT_VT_ESC "90m"
#define UBUT_VT_BLUE UBUT_VT_ESC "94m"
#define UBUT_VT_CYAN UBUT_VT_ESC "36m"
#define UBUT_VT_YELLOW UBUT_VT_ESC "33m"
#define UBUT_VT_GREEN UBUT_VT_ESC "32m"
#define UBUT_VT_RED UBUT_VT_ESC "31m"
#define UBUT_VT_MAGENTA UBUT_VT_ESC "35m"
#else // ! WIN10
#define UBUT_VT_ESC ""
#define UBUT_VT_RESET UBUT_VT_ESC ""
#define UBUT_VT_GRAY UBUT_VT_ESC ""
#define UBUT_VT_BLUE UBUT_VT_ESC ""
#define UBUT_VT_CYAN UBUT_VT_ESC ""
#define UBUT_VT_YELLOW UBUT_VT_ESC ""
#define UBUT_VT_GREEN UBUT_VT_ESC ""
#define UBUT_VT_RED UBUT_VT_ESC ""
#define UBUT_VT_MAGENTA UBUT_VT_ESC ""
#endif

#define WHITE(...)                  \
    fprintf(stdout, UBUT_VT_RESET); \
    fprintf(stdout, __VA_ARGS__);

#define RED(...)                  \
    fprintf(stdout, UBUT_VT_RED); \
    fprintf(stdout, __VA_ARGS__); \
    fprintf(stdout, UBUT_VT_RESET)

#define CYAN(...)                  \
    fprintf(stdout, UBUT_VT_CYAN); \
    fprintf(stdout, __VA_ARGS__);  \
    fprintf(stdout, UBUT_VT_RESET)

/*
For this to work on WIN10

1. use the /utf-8 cl switch (/DUNICODE you use of course?)
2. in code execute on the very start:
    system("chcp 65001");
    system(" ");
3. Set the cmd exe to use font that can display these glyphs  
   I use "MS Gothic"  
 */
int testing_dbj_utf8_vulgaris (void)
{
#ifdef _MSC_VER
    // windows cmd shenanigans
    // set the code page to utf-8, manually
    system("chcp 65001>NUL");
    // kick-start cmd.exe VT100 interpretation
    system(" ");
#endif
    // the multibyte character encoding is specified by the currently active C locale!
    // is the currently active C locale the one you wanted?
    const char *new_locale = setlocale(LC_ALL, "en_US.utf8");

    // UTF-8 is easy.. always use UTF-8
    {
        CYAN("\n\nUTF-8\n");
        const char K1[] = u8"片仮名";
        const char K2[] = u8"カタカナ";
        printf("\n%s", K1);
        printf("\n%s", K2);
    }

    // UTF-16
    {
        CYAN("\n\nUTF-16\n");
#define K3 u"片仮名"
#define K4 u"カタカナ"
        char *k3 = dbj_u16_to_mb(K3);
        char *k4 = dbj_u16_to_mb(K4);
        printf("\n%s", k3);
        printf("\n%s", k4);
        free(k3);
        free(k4);
    }

    // UTF-32
    {
        CYAN("\n\nUTF-32\n");
#define K5 U"片仮名"
#define K6 U"カタカナ"
        char *k3 = dbj_u32_to_mb(K5);
        char *k4 = dbj_u32_to_mb(K6);
        printf("\n%s", k3);
        printf("\n%s", k4);
        free(k3);
        free(k4);
    }

    // below should work with Consolas, Lucida etc ...
    // char * utf8 = u8"Löwen, Bären, Vögel und Käfer sind Tiere.";
    // printf("\n\n%s\n\n", utf8);
    // return 42;

    printf("\n\n");
    return 42;
}

/* ----------------------------------------------------------------------------------------- */
# endif //TESTING_DBJ_UTF_8_VULGARIS
/* ----------------------------------------------------------------------------------------- */
#endif // DBJ_UTF_8_VULGARIS_INC
