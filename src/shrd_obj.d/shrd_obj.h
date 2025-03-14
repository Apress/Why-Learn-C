struct shrd_obj;
typedef void (*shrd_free_fn)( struct shrd_obj* );

struct shrd_obj {
  size_t _Atomic            ref_cnt;
  shrd_free_fn              free_fn;
  alignas(max_align_t) char data[];
};
