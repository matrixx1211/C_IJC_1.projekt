// bitset.h
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: MinGW GCC 6.3.0
// ...popis příkladu - poznámky, omezení, atd

//Hlavičkové soubory
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Typ:
typedef unsigned long *bitset_t;
typedef unsigned long bitset_index_t;

//Počet bitů v unsigned long
#define ULONG_BITS (sizeof(unsigned long) * 8)

//Makra:
//#ifndef USE_INLINE
#define bitset_create(jmeno_pole, velikost)                                                  \
    _Static_assert(!(velikost <= 0), "Size of array cannot be less than or equal zero.");      \
    unsigned long jmeno_pole[(velikost / ULONG_BITS) + (velikost % ULONG_BITS) ? 1 : 0 + 1]; \
    jmeno_pole[0] = velikost;

#define bitset_alloc(jmeno_pole, velikost)
#define bitset_free(jmeno_pole)
#define bitset_size(jmeno_pole)
#define bitset_setbit(jmeno_pole, index, vyraz)
#define bitset_getbit(jmeno_pole, index)

//#else
//#endif
