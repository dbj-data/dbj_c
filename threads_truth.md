
In C/C++ "threads" are NOT part of the programming language, they do belong to the OS. That's really what's wrong with MT while using programming languages like Java and C/C++. 

C/C++ "threads" aren't in the programming language, C/C++ "threads" are something in the OS – and they inherit all the design decisions of the OS. 

Central theme with OS threads, is the granularity of the OS memory management system. The memory management in the OS protects whole pages of memory, so the smallest size that a thread can be is the smallest size of a page. 

When you add more RAM to your machine – you have the same number of bits that protects the memory so the granularity of the page tables goes up – you end up using (as an example) 64kB (aka 0xFFFF) for a thread you think is running in a few hundred bytes.