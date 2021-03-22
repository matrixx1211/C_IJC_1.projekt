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
    struct ppm *pppm = ppm_read(argv[1]);
    if (pppm == NULL)
        error_exit("Nepodařilo se načíst obrázek '%s'.\n", argv[1]);    

    // Deklarace dynamického bitového pole
    unsigned long velikost = pppm->xsize * pppm->ysize * 3 * CHAR_BIT;
    bitset_alloc(pole_bitu, velikost);

    // Eratostenovo síto
    Eratosthenes(pole_bitu);

    // Procházení a hledání zprávy
    char znak = 0;
    char byte = 0;
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
                    bitset_free(pole_bitu);
                    ppm_free(pppm);
                    return 0;
                }
                znak = 0;
            }

            byte = pppm->data[i] & (char)1;
            znak += byte << posun;
            posun++;
        }
    }

    // Uvolnění paměti při nepřečtění celé zprávy
    bitset_free(pole_bitu);
    ppm_free(pppm);
    error_exit("Zprává nebyla ukončena znakem '\\0'.\n");

    return 0;
}
