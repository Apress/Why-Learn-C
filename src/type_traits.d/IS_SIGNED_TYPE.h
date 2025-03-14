#define IS_SIGNED_TYPE(T)     !IS_UNSIGNED_TYPE(T)
#define IS_UNSIGNED_TYPE(T)   ((T)-1 > 0)
