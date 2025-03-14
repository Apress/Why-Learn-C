#define slist_find(LIST,PRED_FN,PRED_DATA)    \
  _Generic( (LIST),                           \
    struct slist*      : nonconst_slist_find, \
    struct slist const*: const_slist_find     \
  )( (LIST), (PRED_FN), (PRED_DATA) )
