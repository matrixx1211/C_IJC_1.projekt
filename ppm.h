// ppm.h
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: MinGW GCC 6.3.0
// ...popis příkladu - poznámky, omezení, atd

#ifndef PPM_H
#define PPM_H
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
struct ppm *ppm_read(const char *filename);

/* 
    Uvolní paměť dynamicky alokovanou v ppm_read. 
*/
void ppm_free(struct ppm *p);

#endif