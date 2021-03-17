// bitset.c
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: MinGW GCC 6.3.0
// ...popis příkladu - poznámky, omezení, atd

#include "bitset.h"

int x()
{

    static bitset_create(p, 100); // p = pole 100 bitů, nulováno
    bitset_create(q, 100000L); // q = pole 100000 bitů, nulováno
    //bitset_create(q, -100);       // chyba při překladu
    (void)q;
    (void)p;
    return 0;
}