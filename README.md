<h1 style="font-size:64px;"> W.I.P. </h1>

<h1> dbj_c_top </h1>

dbj specific C top level

*"In IT systems in general, the programming language is not of primary importance. Architecture is.*

*IT system (not your desktop experiments) is made of components. Each component has a well-defined interface and set of operational requirements. E.g. size, speed, security, and such. If your component does meet operational requirements I really do not care if you have written it in Quick Basic, Julia, Rust, Elm, Awk, Bash Script or C++.*

*Just after that, it will be rigorously tested for meeting the functional requirements.*

*Also please do not (ever) forget the economy of IT systems: how much money will it take to develop it and more importantly how much money will it take to maintain what you did, and for the next 10+ years."* -- DBJ 2020 Dec.

This is the collection of my top level C headers. Meaning they are or should be used in all of my C and possibly C++ code. 


NOTE: Generally C headers  can be used in C++ code too.

## How to use

- `dbj_c_top` and `dbj_c_top` are two top level libraries.
- have one or the other on the path 

<br/>

> CAVEAT EMPTOR

<br/>


# This code is C code.

By that we mean 

- compile with 64 bit clang-cl compiler. 
- builds and runs on Windows, using Visual Studio. 
- Why WIN32?
  - Same as MS STL is based on WIN32 we are based on WIN32. And WIN32 is C API.

## Which C?

  **C17** with available clang/gcc extensions. 
  
  C17 standard, latest freely available draft is [c17_updated_proposed_fdis.pdf](https://web.archive.org/web/20181230041359if_/http://www.open-std.org/jtc1/sc22/wg14/www/abq/c17_updated_proposed_fdis.pdf).

  C11 draft is [N1570](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf) is quite sufficient as a document describing the standard C we use. C17 is "just" C11 error rectifications.

  For an quick overview [please see here](https://stackoverflow.com/a/14737642/10870835).

  From the C programs point of view, is it clang or GCC most of the time is irrelevant. clang tries to be compatible with gcc as much as possible, but some gcc extensions are not implemented yet.

  - [GCC online documentation](http://gcc.gnu.org/onlinedocs/).
  - clang compiler [user's manual](https://clang.llvm.org/docs/UsersManual.html)
    - [clang C Language Features](https://clang.llvm.org/docs/UsersManual.html#c-language-features)
    - top level of the [Clang 12 documentation](https://clang.llvm.org/docs/index.html).

### Feature checking macros

Whenever and wherever possible we use them. Here is clang [Feature Checking Macros](https://clang.llvm.org/docs/LanguageExtensions.html#feature-checking-macros) section.

We think this is probably the key feature of clang compiler.