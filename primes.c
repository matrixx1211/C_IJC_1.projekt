// primes.c
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: MinGW GCC 6.3.0
// ...popis příkladu - poznámky, omezení, atd

#include <stdio.h>
#include "bitset.h"
#include "eratosthenes.h"

#define VEL_POLE (200000000)

int main()
{
    // Vytvoření pole
    bitset_create(pole_bitu, VEL_POLE);
    unsigned long vysledky[10];
    int tisknout = 0;

    Eratosthenes(pole_bitu);

    for (size_t i = VEL_POLE - 1; i > VEL_POLE / 2; i--)
        if ((bitset_getbit(pole_bitu, i) == 0))
        {
            vysledky[9 - tisknout] = i;
            tisknout++;
            if (tisknout == 10)
                break;
        }

    // Výpis výsledků
    for (int i = 0; i < 10; i++)
    {
        printf("%lu\n", vysledky[i]);
    }

    return 0;
}
