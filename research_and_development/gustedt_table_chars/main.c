// #include <errno.h>
// #include <limits.h>
// #include <locale.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <wchar.h>

#include <io.h>
#include <fcntl.h>

#define SX(F,X) wprintf(L"\n%24S : " F , (#X), (X))

/*
Table border drawing symbols have "protrusions".
There can be max 4 protrusions, as on the "cross" symbol:

            UP
             |
    LEFT ----+---- RIGHT
             |
            DOWN 

Protrusion codes are enum values. By commbining protrusion codes
you select the symbol from the table of drawing chars
*/
enum PROTRUSION_CODE
{
  g_l = 1, // LEFT
  g_r = 2, // RIGHT
  g_u = 4, // UP 
  g_d = 8, // DOWN
};
/* table of symbols is organized by OR-ing the protrusion codes */
static wchar_t const *g_table[] = {
    [0] = L" ",
    [g_l] = L"\u2574", // JUSTLEFT
    [g_r] = L"\u2576", // JUSTRIGHT
    [g_l | g_r] = L"\u2500",
    [g_u] = L"\u2575", // JUSTUP
    [g_l | g_u] = L"\u2518",
    [g_r | g_u] = L"\u2514",
    [g_l | g_r | g_u] = L"\u2534",
    [g_d] = L"\u2577", // JUSTDOWN
    [g_l | g_d] = L"\u2510",
    [g_r | g_d] = L"\u250c",
    [g_l | g_r | g_d] = L"\u252c",
    [g_u | g_d] = L"\u2502",
    [g_l | g_u | g_d] = L"\u2524",
    [g_r | g_u | g_d] = L"\u251c",
    [g_l | g_r | g_u | g_d] = L"\u253c" // CROSS
    };

/* symbolical names */

#define VBAR g_table[ g_u | g_d ]     /**< a vertical bar character   */
#define HBAR g_table[ g_l | g_r ]     /**< a horizontal bar character */
#define RIGHTT g_table[ g_u | g_d | g_r ] /* right T*/
#define LEFTT g_table[ g_u | g_d  | g_l ] /* left  T*/

#define TOPLEFT g_table[ g_d | g_r ]  /**< topleft corner character   */
#define TOPRIGHT g_table[ g_d | g_l ] /**< topright corner character  */

#define BOTTOMLEFT g_table[ g_u | g_r ]  /**< bottom left corner character   */
#define BOTTOMRIGHT g_table[ g_u | g_l ] /**< bottom right corner character  */

static const unsigned WSZ = sizeof(wchar_t);

#define WCHAR_LINE(CHAR_,LEN_) ( assert( LEN_ <= 0xFF), \
  (wchar_t const * const)wmemset(wmemset(alloca((WSZ * LEN_) + WSZ ), L'\0', LEN_+1), CHAR_, LEN_)) 

static void draw_sep(wchar_t const start[static 1],
                    wchar_t const mid[static 1],
                     wchar_t const end[static 1])
                     
{
  wprintf(L"%s%-45s%s\n", start, mid, end);
}


/* ------------------------------------------------------------------------------------------------- */

int main(int argc, char *argv[])
{
#ifdef _WIN32
   _setmode(_fileno(stdout), _O_U16TEXT);
  /* DBJ added bellow: 
     stupid trick that works 
    without it cmd.exe will not behave consistently 
    in displaying unicode that is
 */
  system(" ");
#endif

    SX("%s", g_table[g_l] ); // L"\u2574",
    SX("%s", g_table[g_r] ); // L"\u2576",
    SX("%s", g_table[g_l | g_r] ); // L"\u2500",
    SX("%s", g_table[g_u] ); // L"\u2575",
    SX("%s", g_table[g_l | g_u] ); // L"\u2518",
    SX("%s", g_table[g_r | g_u] ); // L"\u2514",
    SX("%s", g_table[g_l | g_r | g_u] ); // L"\u2534",
    SX("%s", g_table[g_d] ); // L"\u2577",
    SX("%s", g_table[g_l | g_d] ); // L"\u2510",
    SX("%s", g_table[g_r | g_d] ); // L"\u250c",
    SX("%s", g_table[g_l | g_r | g_d] ); // L"\u252c",
    SX("%s", g_table[g_u | g_d] ); // L"\u2502",
    SX("%s", g_table[g_l | g_u | g_d] ); // L"\u2524",
    SX("%s", g_table[g_r | g_u | g_d] ); // L"\u251c",
    SX("%s", g_table[g_l | g_r | g_u | g_d] ); // L"\u253c"

  const unsigned g_table_count = sizeof(g_table) / sizeof(g_table[0]) ;

  wprintf(L"\n\n\n");
  wchar_t const * const line45 = WCHAR_LINE(HBAR[0], 45 ) ;
  assert(line45);

  draw_sep( TOPLEFT , line45, TOPRIGHT);
  draw_sep(VBAR, L" © 2014 jɛnz ˈgʊzˌtɛt ", VBAR);
  draw_sep( RIGHTT, line45, LEFTT );
  draw_sep(VBAR, L" DUKI ", VBAR);
  draw_sep( RIGHTT, line45, LEFTT );
  draw_sep(VBAR, L" CEKI ", VBAR);
  draw_sep( BOTTOMLEFT , line45, BOTTOMRIGHT);

  return 42;
}
