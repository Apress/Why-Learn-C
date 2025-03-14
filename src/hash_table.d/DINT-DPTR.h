#define HT_DINT(ENTRY)  ( (void*)(ENTRY)->data )
#define HT_DPTR(ENTRY)  ( *(void**)HT_DINT( (ENTRY) ) )
