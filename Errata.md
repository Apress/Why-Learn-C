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

### Chapter 25: Maps

+ §25.2 Hash Table Types (p. 336)

  The declaration of `ht_entry` should instead be:

  ```c
  struct ht_entry {
    struct ht_entry  *next;
    struct ht_entry  *prev;
    ht_hash_val       hash;
    alignas(max_align_t) char data[];
  };
  ```

  Specifically, the `union` should be removed.

+ §25.2 Hash Table Types (p. 337)

  The paragraph that reads:

  > Why is `prev` in a union with `hash`? Since the head entry doesn’t need
  > `prev`, we might as well make use of the otherwise wasted space by storing
  > _h_(_k_) there since all keys in the same bucket have the same value. As
  > we’ll see, this eliminates recalculating _h_(_k_) when growing (§25.5) the
  > hash table.

  should be deleted.

  While it's true that the head entry doesn't need `prev`, it's _not_ true that
  all keys in the same bucket have the same _h_(_k_).  Instead, they all have
  the same _remainder_, i.e., _h_(_k_) `%` _m_ or _i_ (the index into _B_).
  Hence, it's necessary to store `hash` per entry.

+ §25.4 Insert (p. 340)

  Since `ht_entry` now uses `hash` per entry, the `ht_insert` function needs to
  change slightly.  It should now be:

  ```c
  struct ht_insert_rv ht_insert( struct hash_table *ht,
                                 void const *key,
                                 size_t data_size ) {
    auto const hash = (*ht->hash_fn)( key );
    auto const n_buckets = HT_PRIME[ ht->prime_idx ];
    auto const b = hash % n_buckets;
    struct ht_entry *const head = &ht->buckets[b], *entry;

    for ( entry = head->next; entry != nullptr; entry = entry->next ) {
      if ( (*ht->cmp_fn)( key, entry->data ) == 0 )
        return (struct ht_insert_rv){ entry, .inserted = false };
    }

    entry = malloc( sizeof(struct ht_entry) + data_size );
    *entry = (struct ht_entry){
      .next = head->next, .prev = head, .hash = hash
    };
    if ( head->next != nullptr )
      head->next->prev = entry;
    head->next = entry;

    auto const lf = ++ht->size / (double)n_buckets;
    if ( lf >= ht->max_lf )
      ht_grow( ht );

    return (struct ht_insert_rv){ entry, .inserted = true };
  }
  ```

  Specifically, the initialization of `.hash` moved from `head` to `entry`.

+ §25.5 Growing (p. 341)

  Since `ht_entry` now uses `hash` per entry, the `ht_grow` function needs to
  change slightly.  It should now be:

  ```c
  static void ht_grow( struct hash_table *ht ) {
    auto const new_n_buckets = HT_PRIME[ ++ht->prime_idx ];
    struct ht_entry *const new_buckets =
      calloc( new_n_buckets, sizeof(struct ht_entry) );

    for ( unsigned b = 0; b < new_n_buckets; ++b ) {
      for ( struct ht_entry *entry = ht->buckets[b].next, *next;
            entry != nullptr; entry = next ) {
        auto const new_head = &new_buckets[ entry->hash % new_n_buckets ];

        next = entry->next;
        entry->next = new_head->next;
        entry->prev = new_head;

        if ( new_head->next != nullptr )
          new_head->next->prev = entry;
        new_head->next = entry;
      }
    }

    free( ht->buckets );
    ht->buckets = new_buckets;
  }
  ```

  Specifically, the local variable `hash` has been deleted and `entry->hash` is
  now used instead.

### Index

+ `nullptr` (p. 395)

  It should include a reference on p. 296.

+ variadic function (p. 402)

  It should _not_ include a reference on p. 296.
