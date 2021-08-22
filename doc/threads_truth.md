
# The issue with threads

> (c) 2021 by dbj at dbj dot org

In C/C++ "threads" are NOT part of the programming language, they do belong to the OS. That's really what's wrong with MT while using programming languages like Java, C or C++. 

C/C++ "threads" aren't in the programming language, C/C++ "threads" are something in the OS – and they inherit all the design decisions of the OS. 

Central theme with OS threads, is the granularity of the OS memory management system. The memory management in the OS protects whole pages of memory, so the smallest size that a thread can be is the smallest size of a page. 

> A HW page on x64 is always 4K, that's the hardware page size on x86.

Threads memory footprint are precisely related to: memory page size

```
call GetSystemInfo or better GetNativeSystemInfo and look for dwPageSize member of SYSTEM_INFO structure. however now under windows in both x86 and x64 page size is 0x1000 or 4Kb
```

- this be checked as a claim?
  - When you add more RAM to your machine – you have the same number of bits that protects the memory so the granularity of the page tables goes up – you end up using (as an example) 64kB (aka 0xFFFF) for a thread you think is running in a few hundred bytes.