struct strbuf {
  char     *contents; // pointer to actual contents
  uint32_t  len;      // length (not including null at end)
  uint32_t  cap;      // capacity
};
