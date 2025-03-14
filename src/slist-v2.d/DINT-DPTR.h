#define SLIST_DINT(DATA)  ( (void*)(DATA) )
#define SLIST_DPTR(DATA)  ( *(void**)SLIST_DINT( (DATA) ) )
