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
#include <limits.h>
#include <string.h>
#include "error.h"

typedef unsigned long *bitset_t;
typedef unsigned long bitset_index_t;
#define ULONG_BITS (sizeof(unsigned long) * CHAR_BIT)

/* 
    Vytvoří pole o velikosti velikost a nastaví na 0-tý index jeho velikost. 
*/
#define bitset_create(jmeno_pole, velikost)                                                          \
    _Static_assert(velikost > 0, "bitset_create: neplatná velikost!");                               \
    unsigned long jmeno_pole[(velikost / ULONG_BITS) + ((velikost % ULONG_BITS) ? 1 : 0) + 1] = {0}; \
    jmeno_pole[0] = velikost;
/*
    Vytvoří dynamicky alokované pole o velikosti velikost a nastaví na 0-tý index jeho velikost. 
*/
#define bitset_alloc(jmeno_pole, velikost)                                                                                \
    assert(velikost > 0);                                                                                                 \
    bitset_t jmeno_pole = calloc((velikost / ULONG_BITS) + ((velikost % ULONG_BITS) ? 1 : 0) + 1, sizeof(unsigned long)); \
    if (jmeno_pole == NULL)                                                                                               \
        error_exit("bitset_alloc: Chyba alokace paměti");                                                                 \
    jmeno_pole[0] = velikost;
/* 
    Uvolní paměť použitou pro dynamicky alokované pole.
*/
#define bitset_free(jmeno_pole) \
    free(jmeno_pole)

#ifndef USE_INLINE
/* 
    Vrátí velikost pole. 
*/
#define bitset_size(jmeno_pole) \
    jmeno_pole[0]

/* 
    Nastaví bit v poli na konkrétním indexu.
*/
#define bitset_setbit(jmeno_pole, index, vyraz)                                                                  \
    if ((unsigned long)(index) >= bitset_size(jmeno_pole))                                                       \
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", index, jmeno_pole[0] - 1);                     \
    if (vyraz != 0)                                                                                              \
        jmeno_pole[((unsigned long)(index) / ULONG_BITS) + 1] |= (1UL << ((unsigned long)(index) % ULONG_BITS)); \
    else                                                                                                         \
        jmeno_pole[((unsigned long)(index) / ULONG_BITS) + 1] &= ~(1UL << ((unsigned long)(index) % ULONG_BITS));

/* 
    Vrátí bit na konkrétním indexu. 
*/
#define bitset_getbit(jmeno_pole, index) \
    ((unsigned long)(index) >= bitset_size(jmeno_pole)) ? (error_exit("bit_array_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)(index), (jmeno_pole[0] - 1)), -1) : ((jmeno_pole[((unsigned long)(index) / ULONG_BITS) + 1] & (1UL << ((unsigned long)(index) % ULONG_BITS))) != 0)

#else
/*
    Inline funkce, která dělá to stejné jako makro bitset_size.
*/
inline unsigned long bitset_size(bitset_t jmeno_pole)
{
    return jmeno_pole[0];
}

/*
    Inline funkce, která dělá to stejné jako makro bitset_setbit.
*/
inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz)
{
    if (index >= bitset_size(jmeno_pole))
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", index, jmeno_pole[0] - 1);
    if (vyraz != 0)
        jmeno_pole[(index / ULONG_BITS) + 1] |= (1UL << (index % ULONG_BITS));
    else
        jmeno_pole[(index / ULONG_BITS) + 1] &= ~(1UL << (index % ULONG_BITS));
}

/*
    Inline funkce, která dělá to stejné jako makro bitset_getbit.
*/
inline unsigned long bitset_getbit(bitset_t jmeno_pole, bitset_index_t index)
{
    if (index >= bitset_size(jmeno_pole))
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", index, jmeno_pole[0] - 1);
    return (jmeno_pole[(index / ULONG_BITS) + 1] & (1UL << (index % ULONG_BITS))) != 0;
}
#endif
#endif
