// error.c
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: GCC 7.5.0

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "error.h"

void warning_msg(const char *fmt, ...)
{
    va_list pal;
    va_start(pal, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, pal);
    va_end(pal);
}

void error_exit(const char *fmt, ...)
{
    va_list pal;
    va_start(pal, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, pal);
    va_end(pal);
    exit(1);
}