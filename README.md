<h1 style="font-size:64px;"> W.I.P. </h1>

<h1> dbj_capi </h1>

dbj specific C top level

The collection of top level C headers. Meaning they are or should be used in all of C and possibly C++ code. 

## How to use

- put the folder above on the path
- eg f:/machine_wide
- Include (for example) `#include <dbj_capi/ccommon.h> `

## CAVEAT EMPTOR

### This code is [standard C](http://www.open-std.org/jtc1/sc22/wg14/www/standards.html#9899) code.

By that we mean 

- Compile on Windows 10
- Use the 64 bit clang-cl compiler (comes with Visual Studio 2019)
  - cl.exe (aka MSVC) can not be used
  - this is because MSVC is not [standard C](http://www.open-std.org/jtc1/sc22/wg14/www/standards.html#9899) compiler.
- Why WIN32?
  - Windows is built on WIN32
  - MS STL is based on WIN32 we are based on WIN32. And 
  - WIN32 is ANSI C API.
    - with some extensions but not the level of [standard C](http://www.open-std.org/jtc1/sc22/wg14/www/standards.html#9899)

## Which C?

  **[standard C](http://www.open-std.org/jtc1/sc22/wg14/www/standards.html#9899)** with available clang/gcc extensions. 
  
  For an quick overview [please see here](https://stackoverflow.com/a/14737642/10870835).

### What about GCC?

  From the clang standard C programs point of view, is it clang or GCC most of the time is irrelevant. clang tries to be compatible with gcc as much as possible, but some gcc extensions are not implemented yet.

  - [GCC online documentation](http://gcc.gnu.org/onlinedocs/).
  - clang compiler [user's manual](https://clang.llvm.org/docs/UsersManual.html)
    - [clang C Language Features](https://clang.llvm.org/docs/UsersManual.html#c-language-features)
    - top level of the [Clang 12 documentation](https://clang.llvm.org/docs/index.html).

### Feature checking macros

Whenever and wherever possible we use them. Here is clang [Feature Checking Macros](https://clang.llvm.org/docs/LanguageExtensions.html#feature-checking-macros) section.

We think this is probably the key feature of clang compiler. Please make sure you know and use them.