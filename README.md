![ ](media/work_in_progres_raw.jpg)
>Work in progress

<h3>dbj c api aka</h3>
<h1>dbj_capi&trade;</h1>

## dbj re-usable C

The collection of top level standard C. 

Meaning: this is or should be used in all of C; and possibly all of the C++ code. 

## How to use

- put the folder above this folder, on the path
- eg  `f:/machine_wide` goes to  path
  - were this is in `f:/machine_wide/dbj_capi`
- Include as (for example) `#include <dbj_capi/ccommon.h> `
- How to "wrangle" with VS Code and clang to make this work, you are qualified for :wink:

## Notes on Style

- This code is [standard C](http://www.open-std.org/jtc1/sc22/wg14/www/standards.html#9899) code.
- This code is only Windows (10) code
  - Using the 64 bit clang-cl compiler (comes with Visual Studio 2019)
      - Support for [TDM GCC 64](https://jmeubank.github.io/tdm-gcc/) is "in the pipeline"
- Let us be clear: cl.exe (aka MSVC) can not be used (gasp!)
    - this is because MSVC is not [standard C](http://www.open-std.org/jtc1/sc22/wg14/www/standards.html#9899) compiler.
- Why WIN32?
  - Windows is built on WIN32
    - MS STL is based on WIN32, thus all is based on WIN32 
  - WIN32 is ANSI C API.
    - with some extensions but not on the level of [standard C](http://www.open-std.org/jtc1/sc22/wg14/www/standards.html#9899)

### Which C exactly, are we talking about?

  **[standard C](http://www.open-std.org/jtc1/sc22/wg14/www/standards.html#9899)** with **all** the available clang/gcc extensions. 
  
For standard conformance, use any of the following:
```c
-std=c90 -pedantic
-std=c99 -pedantic
-std=c11 -pedantic
```
One can use `C17`,`c18`,`c2x` or whatever. `c11` is still the standard 2021 Q4.

C11 was issued by ISO in 2011. There has been one Technical Corrigendum, fixing the definitions of `__STDC_VERSION__` and `__STDC_LIB_EXT1__`.

> ANSI did not issue its own versions of the 1999 or 2011 standards, adopting the ISO standards instead.

  For an deeper view [please see here](https://stackoverflow.com/a/14737642/10870835).

  From the [Gandalf](https://stackoverflow.com/users/827263/keith-thompson), himself.

## What about GCC?

  From the clang standard C programs point of view, is it clang or GCC most of the time is irrelevant. clang tries to be compatible with gcc as much as possible, but some gcc extensions are not implemented yet.

  - [GCC online documentation](http://gcc.gnu.org/onlinedocs/).
  - clang compiler [user's manual](https://clang.llvm.org/docs/UsersManual.html)
    - [clang C Language Features](https://clang.llvm.org/docs/UsersManual.html#c-language-features)
    - top level of the [Clang 12 documentation](https://clang.llvm.org/docs/index.html).

### Feature checking macros in standard C

Whenever and wherever possible we use them. Here is clang [Feature Checking Macros](https://clang.llvm.org/docs/LanguageExtensions.html#feature-checking-macros) section.

We think this is probably the key feature of clang compiler. Please make sure you know and use them.

---

&copy; 2021 by dbj at dbj dot org  htpps://dbj.org/license_dbj