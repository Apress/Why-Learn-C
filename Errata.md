# Why Learn C &mdash; Errata

This file contains corrections
and updates
to the published content.
It will be updated periodically
as issues are identified.

## Errata for the First Edition

### Chapter 1: A Tour of C

+ §1.5 Memory (p. 14)

  Where it says:

  > ... any signed integer −127 to 128, ...

  it should instead say:

  > ... any signed integer −128 to 127, ...

+ §1.7 `const` (p. 18)

  Where it says:

  > On line 5, even though `pcc` is a pointer to `const char` ...

  it should instead say:

  > On line 5, even though `ncpc` is a pointer to `const char` ...

+ §1.9 Structures (p. 24)

  Where it says:

  > Line 4 uses `strcpy` to copy `s` to the memory address
  > `str + str->len` ...

  it should instead say:

  > Line 4 uses `strcpy` to copy `s` to the memory address
  > `str->contents + str->len` ...

### Chapter 3: Operators

+ §3.14.3 Casting Pointers (p. 56)

  Where it says:

  > The `(int32_t*)` casts the address of the 4-byte char buffer `int32_buf` to
  > be a pointer to `uint32_t` instead.  The first `*` then dereferences that
  > address and the `=` writes the bytes as if they really were a `uint32_t`.

  it should instead say:

  > The `(int32_t*)` casts the address of the 4-byte char buffer `int32_buf` to
  > be a pointer to `int32_t` instead.  The first `*` then dereferences that
  > address and the `=` writes the bytes as if they really were an `int32_t`.

### Chapter 4: Declarations

+ §4.8 `alignas` (p. 69)

  Where it says:

  > so it ensures that it's aligned the same as an `int` would be.

  it should instead say:

  > so it ensures that it's aligned the same as an `int32_t` would be.

### Chapter 6: Arrays and Pointers

+ §6.13 Dynamically Allocating 2D Arrays (p. 95)

  Where it says:

  > Line 6 ...

  it should instead say:

  > Line 7 ...

  Where it says:

  > Line 7 ...

  it should instead say:

  > Line 8 ...

  Where it says:

  > Line 8-9 ...

  it should instead say:

  > Line 9-10 ...

### Chapter 12: Input, Output, and Files

+ §12.1 Output (p. 179)

  Where it says:

  ```c
  int fputc(char c, FILE *file)
  int putc(char c, FILE *file)
  int putchar(char c)
  ```

  it should instead say:

  ```c
  int fputc(int c, FILE *file)
  int putc(int c, FILE *file)
  int putchar(int c)
  ```

+ §12.4 Input (p. 196)

  In table 12.4 where it says:

  > `aAeFfFgG`

  it should instead say:

  > `aAeEfFgG`

### Chapter 14: Multithreading

+ §14.4 Mutexes (p. 223)

  Where listing 14.4, line 15, says:

  ```c
  auto *const data = head != nullptr ?
  ```

  it should instead say:

  ```c
  auto const data = head != nullptr ?
  ```

  (The `*` was erronously allowed by `clang`, but is illegal in C.)

+ §14.5 Condition Variables (p. 227)

  Where listing 14.7 says:

  ```c
  work_copy = work_avail;
  ```

  it should instead say:

  ```c
  work_copy = work_avail;
  work_avail = false;
  ```

### Chapter 17: `_Atomic`

+ §17.4 Compare and Swap (p. 296)

  Where is says:

  > ... so do nothing

  it should instead say:

  > ... so set the expected value to the actual value instead.

+ §17.6 The ``ABA Problem'' (p. 260)

  Where it says:

  > Line 5 ...

  it should instead say:

  > Line 6 ...

  Where it says:

  > Note that `head->next` has been updated to be the updated `*plist`, the
  > current head.

  it should instead say:

  > Note that `head` has been updated to be the updated `*plist`, the
  > current head.

### Chapter 18: Debugging

+ §18.7.1 Recommended Warnings (p. 273)

  Where it says:

  > ... such that when `sum` < ε ...

  it should instead say:

  > ... such that when |`sum`| < ε ...

### Chapter 19: `_Generic`

+ §19.6 Type Traits (p. 296)

  The given definition of `IS_SAME_TYPE` works fine
  for a majority of types,
  but it doesn't work
  for either incomplete types (§13.2)
  or `void`.
  A better version that does is:

  ```c
  #define IS_SAME_TYPE(T,U)               \
    _Generic( (typeof_unqual(T)*)nullptr, \
      typeof_unqual(U)* : true,           \
      default           : false           \
    )
  ```

  The two paragraphs that follow its definition should now be:

  > The `(T*)nullptr` is needed to convert `T`
  > (a type) into an expression
  > required by `_Generic`.
  > Pointers are used so either type can be
  > incomplete (§13.2)
  > or `void`.
  >
  > &nbsp;&nbsp;&nbsp;&nbsp; Both `typeof_unqual` (§4.7)
  > are necessary
  > to remove qualifiers,
  > otherwise it would never match
  > if either type had qualifiers.
  > (Reminder: `_Generic` discards only top-level qualifiers
  > from the type of the controlling expression.
  > In this case,
  > the pointer type `T *const` would become `T*`.
  > But here,
  > we need to discard qualifiers
  > from the pointed-to types `T` and `U`.)

+ §19.6 Type Traits (p. 297)

  The given definition of `UNDERLYING_TYPE` doesn't work
  in all cases.
  A better version that does is:

  ```c
  #define UNDERLYING_TYPE(ENUM_TYPE)              \
    typeof( _Generic( (ENUM_TYPE)0,               \
      bool              : (bool)              0,  \
      char              : (char)              0,  \
      signed char       : (signed char)       0,  \
      short             : (short)             0,  \
      int               : (int)               0,  \
      long              : (long)              0,  \
      long long         : (long long)         0,  \
      unsigned char     : (unsigned char)     0,  \
      unsigned short    : (unsigned short)    0,  \
      unsigned int      : (unsigned int)      0,  \
      unsigned long     : (unsigned long)     0,  \
      unsigned long long: (unsigned long long)0   \
    ) )
  ```

### Index

+ `nullptr` (p. 395)

  It should include a reference on p. 296.

+ variadic function (p. 402)

  It should _not_ include a reference on p. 296.
