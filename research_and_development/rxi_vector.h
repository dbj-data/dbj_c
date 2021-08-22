#ifndef RXI_VECTOR_HEADER_
#define RXI_VECTOR_HEADER_

//    https://raw.githubusercontent.com/rxi/vec/master/src/vec.h
//
//
//    #define RXI_VEC_IMPLEMENTATIN before including this header
//    in EXACTLY ONE C file.
//
//    comparing with STB dynamic array: https://godbolt.org/z/Yr1oG8dv9
//

/** 
 * Copyright (c) 2014 rxi
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See LICENSE for details.
 */


#include <stdlib.h>
#include <string.h>

#define VEC_VERSION "0.2.1"


#define vec_unpack_(v)\
  (char**)&(v)->data, &(v)->length, &(v)->capacity, sizeof(*(v)->data)


#define vec_t(T)\
  struct { T *data; int length, capacity; }


#define vec_init(v)\
  memset((v), 0, sizeof(*(v)))


#define vec_deinit(v)\
  ( free((v)->data),\
    vec_init(v) ) 


#define vec_push(v, val)\
  ( rxi_vector_expand_(vec_unpack_(v)) ? -1 :\
    ((v)->data[(v)->length++] = (val), 0), 0 )


#define vec_pop(v)\
  (v)->data[--(v)->length]


#define vec_splice(v, start, count)\
  ( rxi_vector_splice_(vec_unpack_(v), start, count),\
    (v)->length -= (count) )


#define vec_swapsplice(v, start, count)\
  ( rxi_vector_swapsplice_(vec_unpack_(v), start, count),\
    (v)->length -= (count) )


#define vec_insert(v, idx, val)\
  ( rxi_vector_insert_(vec_unpack_(v), idx) ? -1 :\
    ((v)->data[idx] = (val), 0), (v)->length++, 0 )
    

#define vec_sort(v, fn)\
  qsort((v)->data, (v)->length, sizeof(*(v)->data), fn)


#define vec_swap(v, idx1, idx2)\
  rxi_vector_swap_(vec_unpack_(v), idx1, idx2)


#define vec_truncate(v, len)\
  ((v)->length = (len) < (v)->length ? (len) : (v)->length)


#define vec_clear(v)\
  ((v)->length = 0)


#define vec_first(v)\
  (v)->data[0]


#define vec_last(v)\
  (v)->data[(v)->length - 1]


#define vec_reserve(v, n)\
  rxi_vector_reserve_(vec_unpack_(v), n)

 
#define vec_compact(v)\
  rxi_vector_compact_(vec_unpack_(v))


#define vec_pusharr(v, arr, count)\
  do {\
    int i__, n__ = (count);\
    if (rxi_vector_reserve_po2_(vec_unpack_(v), (v)->length + n__) != 0) break;\
    for (i__ = 0; i__ < n__; i__++) {\
      (v)->data[(v)->length++] = (arr)[i__];\
    }\
  } while (0)


#define vec_extend(v, v2)\
  vec_pusharr((v), (v2)->data, (v2)->length)


#define vec_find(v, val, idx)\
  do {\
    for ((idx) = 0; (idx) < (v)->length; (idx)++) {\
      if ((v)->data[(idx)] == (val)) break;\
    }\
    if ((idx) == (v)->length) (idx) = -1;\
  } while (0)


#define vec_remove(v, val)\
  do {\
    int idx__;\
    vec_find(v, val, idx__);\
    if (idx__ != -1) vec_splice(v, idx__, 1);\
  } while (0)


#define vec_reverse(v)\
  do {\
    int i__ = (v)->length / 2;\
    while (i__--) {\
      vec_swap((v), i__, (v)->length - (i__ + 1));\
    }\
  } while (0)


#define vec_foreach(v, var, iter)\
  if  ( (v)->length > 0 )\
  for ( (iter) = 0;\
        (iter) < (v)->length && (((var) = (v)->data[(iter)]), 1);\
        ++(iter))


#define vec_foreach_rev(v, var, iter)\
  if  ( (v)->length > 0 )\
  for ( (iter) = (v)->length - 1;\
        (iter) >= 0 && (((var) = (v)->data[(iter)]), 1);\
        --(iter))


#define vec_foreach_ptr(v, var, iter)\
  if  ( (v)->length > 0 )\
  for ( (iter) = 0;\
        (iter) < (v)->length && (((var) = &(v)->data[(iter)]), 1);\
        ++(iter))


#define vec_foreach_ptr_rev(v, var, iter)\
  if  ( (v)->length > 0 )\
  for ( (iter) = (v)->length - 1;\
        (iter) >= 0 && (((var) = &(v)->data[(iter)]), 1);\
        --(iter))



int rxi_vector_expand_(char **data, int *length, int *capacity, int memsz);
int rxi_vector_reserve_(char **data, int *length, int *capacity, int memsz, int n);
int rxi_vector_reserve_po2_(char **data, int *length, int *capacity, int memsz,
                     int n);
int rxi_vector_compact_(char **data, int *length, int *capacity, int memsz);
int rxi_vector_insert_(char **data, int *length, int *capacity, int memsz,
                int idx);
void rxi_vector_splice_(char **data, int *length, int *capacity, int memsz,
                 int start, int count);
void rxi_vector_swapsplice_(char **data, int *length, int *capacity, int memsz,
                     int start, int count);
void rxi_vector_swap_(char **data, int *length, int *capacity, int memsz,
               int idx1, int idx2);


typedef vec_t(void*) vec_void_t;
typedef vec_t(char*) vec_str_t;
typedef vec_t(int) vec_int_t;
typedef vec_t(char) vec_char_t;
typedef vec_t(float) vec_float_t;
typedef vec_t(double) vec_double_t;


#ifdef RXI_VEC_IMPLEMENTATIN

/** 
 * Copyright (c) 2014 rxi
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See LICENSE for details.
 */

// https://raw.githubusercontent.com/rxi/vec/master/src/vec.c

inline int rxi_vector_expand_(char **data, int *length, int *capacity, int memsz) {
  if (*length + 1 > *capacity) {
    void *ptr;
    int n = (*capacity == 0) ? 1 : *capacity << 1;
    ptr = realloc(*data, n * memsz);
    if (ptr == NULL) return -1;
    *data = ptr;
    *capacity = n;
  }
  return 0;
}


inline int rxi_vector_reserve_(char **data, int *length, int *capacity, int memsz, int n) {
  (void) length;
  if (n > *capacity) {
    void *ptr = realloc(*data, n * memsz);
    if (ptr == NULL) return -1;
    *data = ptr;
    *capacity = n;
  }
  return 0;
}


inline int rxi_vector_reserve_po2_(
  char **data, int *length, int *capacity, int memsz, int n
) {
  int n2 = 1;
  if (n == 0) return 0;
  while (n2 < n) n2 <<= 1;
  return rxi_vector_reserve_(data, length, capacity, memsz, n2);
}


inline int rxi_vector_compact_(char **data, int *length, int *capacity, int memsz) {
  if (*length == 0) {
    free(*data);
    *data = NULL;
    *capacity = 0;
    return 0;
  } else {
    void *ptr;
    int n = *length;
    ptr = realloc(*data, n * memsz);
    if (ptr == NULL) return -1;
    *capacity = n;
    *data = ptr;
  }
  return 0;
}


inline int rxi_vector_insert_(char **data, int *length, int *capacity, int memsz,
                 int idx
) {
  int err = rxi_vector_expand_(data, length, capacity, memsz);
  if (err) return err;
  memmove(*data + (idx + 1) * memsz,
          *data + idx * memsz,
          (*length - idx) * memsz);
  return 0;
}


inline void rxi_vector_splice_(char **data, int *length, int *capacity, int memsz,
                 int start, int count
) {
  (void) capacity;
  memmove(*data + start * memsz,
          *data + (start + count) * memsz,
          (*length - start - count) * memsz);
}


inline void rxi_vector_swapsplice_(char **data, int *length, int *capacity, int memsz,
                     int start, int count
) {
  (void) capacity;
  memmove(*data + start * memsz,
          *data + (*length - count) * memsz,
          count * memsz);
}


inline void rxi_vector_swap_(char **data, int *length, int *capacity, int memsz,
               int idx1, int idx2 
) {
  unsigned char *a, *b, tmp;
  int count;
  (void) length;
  (void) capacity;
  if (idx1 == idx2) return;
  a = (unsigned char*) *data + idx1 * memsz;
  b = (unsigned char*) *data + idx2 * memsz;
  count = memsz;
  while (count--) {
    tmp = *a;
    *a = *b;
    *b = tmp;
    a++, b++;
  }
}


#endif // RXI_VEC_IMPLEMENTATION

#if 0

///////////////////////////////////////////////
///
///  README.MD
///
///////////////////////////////////////////////

// # vec
// A type-safe dynamic array implementation for C. 


// ## Installation 
// The [vec.c](src/vec.c?raw=1) and [vec.h](src/vec.h?raw=1) files can be dropped
// into an existing C project and compiled along with it.


// ## Usage
// Before using a vector it should first be initialised using the `vec_init()`
// function.
// ```c
// vec_int_t v;
// vec_init(&v);
// vec_push(&v, 123);
// vec_push(&v, 456);
// ```

// To access the elements of the vector directly the vector's `data` field can be
// used.
// ```c
// printf("%d\n", v.data[1]); /* Prints the value at index 1 */
// ```

// The current length of the vector is stored in the `length` field of the vector
// ```c
// printf("%d\n", v.length); /* Prints the length of the vector */
// ```

// When you are done with the vector the `vec_deinit()` function should be called
// on it. This will free any memory the vector allocated during use.
// ```c
// vec_deinit(&v);
// ```


// ## Types
// vec.h provides the following predefined vector types:

// | Contained Type  | Type name     |
// |-----------------|---------------|
// | void*           | vec_void_t    |
// | char*           | vec_str_t     |
// | int             | vec_int_t     |
// | char            | vec_char_t    |
// | float           | vec_float_t   |
// | double          | vec_double_t  |

// To define a new vector type the `vec_t()` macro should be used:
// ```c
// /* Creates the type uint_vec_t for storing unsigned ints */
// typedef vec_t(unsigned int) uint_vec_t;
// ```


// ## Functions
// All vector functions are macro functions. The parameter `v` in each function
// should be a pointer to the vec struct which the operation is to be performed
// on.

// ### vec\_t(T)
// Creates a vec struct for containing values of type `T`.
// ```c
// /* Typedefs the struct `fp_vec_t` as a container for type FILE* */
// typedef vec_t(FILE*) fp_vec_t;
// ```

// ### vec\_init(v)
// Initialises the vector, this must be called before the vector can be used. 

// ### vec\_deinit(v)
// Deinitialises the vector, freeing the memory the vector allocated during use;
// this should be called when we're finished with a vector.

// ### vec\_push(v, val)
// Pushes a value to the end of the vector. Returns 0 if the operation was
// successful, otherwise -1 is returned and the vector remains unchanged.

// ### vec\_pop(v)
// Removes and returns the value at the end of the vector.

// ### vec\_splice(v, start, count)
// Removes the number of values specified by `count`, starting at the index
// `start`.
// ```c
// vec_splice(&v, 2, 4); /* Removes the values at indices 2, 3, 4 and 5 */
// ```

// ### vec\_swapsplice(v, start, count)
// Removes the number of values specified by `count`, starting at the index
// `start`; the removed values are replaced with the last `count` values of the
// vector. This does not preserve ordering but is O(1).

// ### vec\_insert(v, idx, val)
// Inserts the value `val` at index `idx` shifting the elements after the index
// to make room for the new value.
// ```c
// /* Inserts the value 123 at the beginning of the vec */
// vec_insert(&v, 0, 123);
// ```
// Returns 0 if the operation was successful, otherwise -1 is returned and the
// vector remains unchanged.

// ### vec\_sort(v, fn)
// Sorts the values of the vector; `fn` should be a qsort-compatible compare
// function.

// ### vec\_swap(v, idx1, idx2)
// Swaps the values at the indices `idx1` and `idx2` with one another.

// ### vec\_truncate(v, len)
// Truncates the vector's length to `len`. If `len` is greater than the vector's
// current length then no change is made.

// ### vec\_clear(v)
// Clears all values from the vector reducing the vector's length to 0.

// ### vec\_first(v)
// Returns the first value in the vector. This should not be used on an empty
// vector.

// ### vec\_last(v)
// Returns the last value in the vector. This should not be used on an empty
// vector.

// ### vec\_reserve(v, n)
// Reserves capacity for at least `n` elements in the given vector;  if `n` is
// less than the current capacity then `vec_reserve()` does nothing. Returns 0 if
// the operation was successful, otherwise -1 is returned and the vector remains
// unchanged.

// ### vec\_compact(v)
// Reduces the vector's capacity to the smallest size required to store its
// current number of values. Returns 0 if the operation is successful, otherwise
// -1 is returned and the vector remains unchanged.

// ### vec\_pusharr(v, arr, count)
// Pushes the contents of the array `arr` to the end of the vector. `count` should
// be the number of elements in the array.

// ### vec\_extend(v, v2)
// Appends the contents of the `v2` vector to the `v` vector.

// ### vec\_find(v, val, idx)
// Finds the first occurrence of the value `val` in the vector. `idx` should be an
// int where the value's index will be written; `idx` is set to -1 if `val` could
// not be found in the vector.

// ### vec\_remove(v, val)
// Removes the first occurrence of the value `val` from the vector. If the `val`
// is not contained in the vector then `vec_remove()` does nothing.

// ### vec\_reverse(v)
// Reverses the order of the vector's values in place. For example, a vector
// containing `4, 5, 6` would contain `6, 5, 4` after reversing.

// ### vec\_foreach(v, var, iter)
// Iterates the values of the vector from the first to the last. `var` should be a
// variable of the vector's contained type where the value will be stored with
// each iteration. `iter` should be an int used to store the index during
// iteration.
// ```c
// /* Iterates and prints the value and index of each value in the float vec */
// int i; float val;
// vec_foreach(&v, val, i) {
//   printf("%d : %f\n", i, val);
// }
// ```

// ### vec\_foreach\_rev(v, var, iter)
// Iterates the values of the vector from the last to the first. See
// `vec_foreach()`

// ### vec\_foreach\_ptr(v, var, iter)
// Iterates the value pointers of the vector from first to last. `var` should be a
// variable of the vector's contained type's pointer. See `vec_foreach()`.
// ```c
// /* Iterates and prints the value and index of each value in the float vector */
// int i; float *val;
// vec_foreach_ptr(&v, val, i) {
//   printf("%d : %f\n", i, *val);
// }
// ```

// ### vec\_foreach\_ptr\_rev(v, var, iter)
// Iterates the value pointers of the vector from last to first. See
// `vec_foreach_ptr()`


// ## License
// This library is free software; you can redistribute it and/or modify it under
// the terms of the MIT license. See [LICENSE](LICENSE) for details.
#endif // 0


#endif // RXI_VECTOR_HEADER_
