struct slink {
  struct slink *next;
  alignas(max_align_t) char data[];
};

struct slist {
  struct slink *head, *tail;
};
