// ppm.c
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: MinGW GCC 6.3.0
// ...popis příkladu - poznámky, omezení, atd
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppm.h"
#include "error.h"

struct ppm *ppm_read(const char *jmeno_souboru)
{
    FILE *pf;

    // Otevření souboru
    if ((pf = fopen(jmeno_souboru, "r")) == NULL)
    {
        warning_msg("Soubor '%s' nelze otevřít.\n", jmeno_souboru);
        return NULL;
    }

    // Získání potřebných údajů z hlavičky souboru
    unsigned int barva;
    unsigned int vel_x;
    unsigned int vel_y;
    char typ_souboru[3];

    if (fscanf(pf, "%2s %u %u %u", typ_souboru, &vel_x, &vel_y, &barva) < 4)
    {
        warning_msg("Nešlo načíst hlavičku souboru '%s'.\n", jmeno_souboru);
        fclose(pf);
        return NULL;
    }

    // Testování formátu
    if (strcmp(typ_souboru, "P6"))
    {
        warning_msg("Špatný formát souboru: '%s'.\n", jmeno_souboru);
        fclose(pf);
        return NULL;
    }

    // Kontrola velikosti
    size_t velikost = (3 * vel_x * vel_y);

    if (velikost > LIMIT)
    {
        warning_msg("Velikost souboru '%s' je přílis velká.\n", jmeno_souboru);
        fclose(pf);
        return NULL;
    }

    // Alokace paměti
    struct ppm *pppm = malloc(sizeof(struct ppm) + velikost);
    if (pppm == NULL)
    {
        warning_msg("Alokace paměti selhala.\n");
        fclose(pf);
        return NULL;
    }

    // Uložení velikosti do struktury
    pppm->xsize = vel_x;
    pppm->ysize = vel_y;

    // Uložení dat do souboru
    if (fread(pppm->data, sizeof(char), velikost, pf) != velikost)
    {
        warning_msg("Nepodařilo se načíst data ze souboru '%s'.\n", jmeno_souboru);
        fclose(pf);
        free(pppm);
        return NULL;
    }

    // Uzavření souboru a vrácení struktury
    fclose(pf);
    return pppm;
}

void ppm_free(struct ppm *p)
{
    free(p);
}
