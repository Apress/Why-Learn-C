struct key_val kv = { "hello", "world" };
auto rv = ht_insert( ht, &kv, sizeof kv );
if ( rv.inserted )
  *(struct key_val*)HT_DINT( rv.entry ) = kv;
