// ppm.h
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: GCC 7.5.0

#ifndef PPM_H
#define PPM_H

#define LIMIT (3 * 8000 * 8000)
/* 
    Struktura pro data ze souboru .PPM
*/
struct ppm
{
    unsigned xsize;
    unsigned ysize;
    char data[]; // RGB bajty, celkem 3*xsize*ysize
};

/* 
    Načte obsah PPM souboru do dynamicky alokované struktury. 
    Při chybě formátu použije funkci warning_msg a vrátí NULL. 
*/
struct ppm *ppm_read(const char *jmeno_souboru);

/* 
    Uvolní paměť dynamicky alokovanou v ppm_read. 
*/
void ppm_free(struct ppm *p);

#endif