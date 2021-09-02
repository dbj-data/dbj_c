
/*
add the "machine_wide" folder to the "includePath" in c_cpp_properties.json
for this to be found by intellisense
*/
#include <dbj_capi/macro_begin_end_defer.h>

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>

#include "examples/1-simple_table.h"
#include "examples/2-custom_table.h"
#include "examples/3-complex_layout.h"
#include "examples/4-fill_table.h"
#include "examples/5-beautiful_table.h"
#include "examples/6-print_styles.h"
#include "examples/7-custom_border_style.h"
#include "examples/8-math_table.h"
#include "examples/9-non_ascii_table.h"

int main(int argc, char **argv)
{
#ifdef _WIN32
    // _setmode(_fileno(stdout), _O_U16TEXT);
    // _setmode(_fileno(stdout), _O_U8TEXT);
    /* DBJ added bellow: 
    without this cmd.exe will not behave consistently 
    in displaying unicode that is
    or it will be not utf8 capable at all
 */
    system("chcp 65001>NUL");
    system(" ");
#endif

    simple_table();
    custom_table();
    complex_layout();
    fill_table_example();
    // beautiful_table();
    // print_styles();
    // custom_table();
    // math_table();
    // non_ascii_table();
    return EXIT_SUCCESS;
}