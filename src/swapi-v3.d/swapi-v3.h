void swapi( int *pa, int *pb ) {  // v3 -- with const
  const int temp = *pa;           // temp won't change
  *pa = *pb;
  *pb = temp;
}
