// primes.c
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: GCC 7.5.0

#include <stdio.h>
#include <time.h>
#include "bitset.h"
#include "eratosthenes.h"

#define VEL_POLE (200000000)

#ifdef USE_INLINE
// Použití inline funkcí místo maker
extern inline void bitset_free(bitset_t jmeno_pole);
extern inline unsigned long bitset_size(bitset_t jmeno_pole);
extern inline unsigned long bitset_getbit(bitset_t jmeno_pole, bitset_index_t index);
extern inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz);

#endif

int main()
{
    // Čas spuštění
    clock_t start = clock();

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

    // Výpis času
    fprintf(stderr, "Time=%.3g\n", (double)(clock() - start) / CLOCKS_PER_SEC);

    return 0;
}
