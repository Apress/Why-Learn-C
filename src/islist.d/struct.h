struct islist {
  struct islist *next;
  alignas(max_align_t) char data[];
};
