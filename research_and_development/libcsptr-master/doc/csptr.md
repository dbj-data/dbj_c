# csptr 
#### "smart" pointers for the C programming language
## SYNOPSIS
```c
#include <csptr/smart_ptr.h>
#include <csptr/smalloc.h> 

void *unique_ptr(Type,Value, ... ); 
void *shared_ptr(Type,Value, ... );

void *smalloc(size_tsize, size_tnmemb, intkind); 

void *smalloc(size_tsize, size_tnmemb, intkind, void (*dtor)(void *, void *)); 

void *smalloc(size_tsize, size_tnmemb, intkind, void (*dtor)(void *, void *), struct { void *, size_t }meta); 

void sfree(void*ptr); void *sref(void*ptr);
```
## DESCRIPTION
The `smalloc()` function calls an allocator by default, such that the returned pointer is a smart pointer. The memory is not initialized, and great care should be taken to initialize it before destruction, if a destructor has been specified. 

If size is 0, then `smalloc()` returns NULL. If `nmemb` is 0, then smalloc shall return a smart pointer to a memory block of at least size bytes, and the smart pointer is a scalar. Otherwise, it shall return a memory block to at least `size * nmemb` bytes, and the smart pointer is an array.

The `sfree()` function calls the deallocator associated to the `smalloc()` allocator by default) on ptr if the smart pointer is either unique or shared with a reference count of 0. 

If the smart pointer is shared, it shall decrement the reference counter by 1 before checking if the deallocator needs to be called.

The `sref()` function creates a new reference to ptr, incrementing the internal reference counter of the smart shared pointer by 1. It shall only be called on a shared pointer.

The `unique_ptr()` and `shared_ptr()` macros expand to a call to the `smalloc()` function with either `UNIQUE` or `SHARED` for the kind parameter, then sets the newly returned memory with Value. 

Additional parameters are passed as-is to the function. 

If Type is an array type, then size shall contain the size of the compound type, and `nmemb` shall contain the length of the array. Otherwise, if Type is a scalar or complex type, then size shall contain the size of the type, and `nmemb` shall be 0.
## RETURN VALUE
The `smalloc()` function return a pointer to the newly allocated memory. On error, it returns NULL. NULL may also be returned by a successful call to `smalloc()` with a size of zero.

The `sfree()` function returns no value.

The `sref()` function returns ptr.

