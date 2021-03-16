// bitset.h
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: MinGW GCC 6.3.0
// ...popis příkladu - poznámky, omezení, atd

//Typ:
typedef unsigned long bitset_t[];
typedef unsigned long bitset_index_t;

//Makra:
//#ifndef USE_INLINE

#define bitset_create(jmeno_pole, velikost)_Static_assert(!(velikost <= 0), "Size of array cannot be less than or equal zero.")
#define bitset_alloc(jmeno_pole, velikost)
#define bitset_free(jmeno_pole)
#define bitset_size(jmeno_pole)
#define bitset_setbit(jmeno_pole, index, vyraz)
#define bitset_getbit(jmeno_pole, index)

//#else
//#endif
