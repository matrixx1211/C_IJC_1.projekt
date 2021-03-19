// bitset.h
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: MinGW GCC 6.3.0
// ...popis příkladu - poznámky, omezení, atd

#ifndef BITSET_H
#define BITSET_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "error.h"

/* Použití maker */
typedef unsigned long *bitset_t;
typedef unsigned long bitset_index_t;

#define ULONG_BITS (sizeof(unsigned long) * 8) //Počet bitů v unsigned long

#define bitset_create(jmeno_pole, velikost)                                                          \
    static_assert(velikost > 0, "Size of array cannot be less than or equal zero.");                 \
    unsigned long jmeno_pole[(velikost / ULONG_BITS) + ((velikost % ULONG_BITS) ? 1 : 0) + 1] = {0}; \
    jmeno_pole[0] = velikost;

#define bitset_alloc(jmeno_pole, velikost) \
    assert(velikost > 0);                  \
    error_exit("string", "bitset_alloc: Chyba alokace paměti");

#define bitset_free(jmeno_pole)
#define bitset_size(jmeno_pole)
#define bitset_setbit(jmeno_pole, index, vyraz)
#define bitset_getbit(jmeno_pole, index)

/* Použití inline funkcí */
//#ifndef USE_INLINE
//#else
//#endif
#endif
