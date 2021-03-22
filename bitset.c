// bitset.c
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: MinGW GCC 6.3.0
// ...popis příkladu - poznámky, omezení, atd

#include "bitset.h"

#ifdef USE_INLINE

extern inline unsigned long bitset_size(bitset_t jmeno_pole);
extern inline unsigned long bitset_getbit(bitset_t jmeno_pole, bitset_index_t index);
extern inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz);

#endif