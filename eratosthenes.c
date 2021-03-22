// eratosthenes.c
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: GCC 7.5.0

#include <stdio.h>
#include <math.h>
#include "bitset.h"
#include "eratosthenes.h"

void Eratosthenes(bitset_t jmeno_pole)
{
    unsigned long podminka = sqrt(bitset_size(jmeno_pole));
    bitset_setbit(jmeno_pole, 2, 1);
    bitset_setbit(jmeno_pole, 1, 1);
    for (size_t j = 2 * 2; j < bitset_size(jmeno_pole); j += 2)
    {
        bitset_setbit(jmeno_pole, j, 1);
    }

    for (size_t i = 3; i < podminka; i += 2)
    {
        if (bitset_getbit(jmeno_pole, i) == 0)
        {
            for (unsigned long j = i * i; j < bitset_size(jmeno_pole); j += 2 * i)
            {
                bitset_setbit(jmeno_pole, j, 1);
            }
        }
    }
}