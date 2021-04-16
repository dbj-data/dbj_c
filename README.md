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


# This is CLANG-CL specific code.

By that we mean 

- compile with 64 bit clang-cl compiler. 
- builds and runs on Windows, using Visual Studio. 
- Same as MS STL is based on WIN32 we are based on WIN32. And WIN32 is C API.