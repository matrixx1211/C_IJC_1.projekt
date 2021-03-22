// error.h
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: GCC 7.5.0

#ifndef ERROR_H
#define ERROR_H

/*  
    Tiskne text "CHYBA: " a chyby podle formátu fmt,
    vše se tiskne do stderr pomocí vfprintf.
*/
void warning_msg(const char *fmt, ...);

/*  
    Tiskne text "CHYBA: " a chyby podle formátu fmt,
    vše se tiskne do stderr pomocí vfprintf
    a ještě navíc ukončí program voláním exit(1).
*/
void error_exit(const char *fmt, ...);

#endif