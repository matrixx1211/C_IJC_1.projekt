// steg-decode.c
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: GCC 7.5.0

#include <stdio.h>
#include <limits.h>
#include "bitset.h"
#include "error.h"
#include "ppm.h"
#include "eratosthenes.h"

#define POCATEK 23

int main(int argc, char const *argv[])
{
    // Kontrola zadání soubouru
    if (argc != 2)
    {
        warning_msg("Nebyl zadán název souboru.\n");
        return 0;   
    }

    // Načtení souboru
    struct ppm *obrazek = ppm_read(argv[1]);
    if (obrazek == NULL)
        error_exit("Nepodařilo se načíst obrázek '%s'.\n", argv[1]);    

    // Deklarace dynamického bitového pole
    unsigned long velikost = obrazek->xsize * obrazek->ysize * 3 * CHAR_BIT;
    bitset_alloc(pole_bitu, velikost);

    // Eratostenovo síto
    Eratosthenes(pole_bitu);

    // Procházení a hledání zprávy
    char znak = 0;
    char bajt = 0;
    char posun = 0;

    for (size_t i = POCATEK; i < velikost; i++)
    {
        if (bitset_getbit(pole_bitu, i) == 0)
        {
            if (posun == 8)
            {
                posun = 0;
                printf("%c", znak);
                if (znak == '\0')
                {
                    printf("\n");
                    bitset_free(pole_bitu);
                    ppm_free(obrazek);
                    return 0;
                }
                znak = 0;
            }

            bajt = obrazek->data[i] & (char)1;
            znak += bajt << posun;
            posun++;
        }
    }

    // Uvolnění paměti při nepřečtění celé zprávy
    bitset_free(pole_bitu);
    ppm_free(obrazek);
    error_exit("Zprává nebyla ukončena znakem '\\0'.\n");

    return 0;
}
