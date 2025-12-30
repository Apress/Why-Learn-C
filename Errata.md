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
