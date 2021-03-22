// ppm.c
// Řešení IJC-DU1, příklad a), 23. 3. 2021
// Autor: Marek Bitomský, FIT
// Přeloženo: GCC 7.5.0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ppm.h"
#include "error.h"

struct ppm *ppm_read(const char *jmeno_souboru)
{
    // Otevření souboru
    FILE *soubor;
    soubor = fopen(jmeno_souboru, "r");
    if (soubor == NULL)
    {
        warning_msg("Soubor '%s' nelze otevřít.\n", jmeno_souboru);
        return NULL;
    }

    // Získání potřebných údajů z hlavičky souboru
    unsigned char barva;
    unsigned long vel_x;
    unsigned long vel_y;
    char typ_souboru[3] = {0};

    if (fscanf(soubor, "%2s\n%lu %lu\n%hhu\n", typ_souboru, &vel_x, &vel_y, &barva) != 4)
    {
        fclose(soubor);
        warning_msg("Nešlo načíst hlavičku souboru '%s'.\n", jmeno_souboru);
        return NULL;
    }

    // Testování formátu
    if (strcmp(typ_souboru, "P6"))
    {
        fclose(soubor);
        warning_msg("Špatný formát souboru: '%s'.\n", jmeno_souboru);
        return NULL;
    }

    // Testování barvy
    if (barva != 255)
    {
        fclose(soubor);
        warning_msg("Hloubka barvy je rozdílná od '255'.\n");
        return NULL;
    }

    // Testování rozlišení
    if (vel_x <= 0 || vel_y <= 0)
    {
        fclose(soubor);
        warning_msg("Rozlišení je menší nebo rovno 0.\n");
        return NULL;
    }

    // Kontrola velikosti
    unsigned long velikost = (3 * vel_x * vel_y);

    if (velikost > (LIMIT))
    {
        fclose(soubor);
        warning_msg("Velikost souboru '%s' je přílis velká.\n", jmeno_souboru);
        return NULL;
    }

    // Alokace paměti
    struct ppm *obrazek = (struct ppm *)malloc(sizeof(struct ppm) + velikost);
    if (obrazek == NULL)
    {
        fclose(soubor);
        warning_msg("Alokace paměti selhala.\n");
        return NULL;
    }

    // Uložení velikosti do struktury
    obrazek->xsize = vel_x;
    obrazek->ysize = vel_y;

    // Uložení dat do souboru
    if ((fread(obrazek->data, 1, velikost, soubor)) != velikost)
    {
        fclose(soubor);
        free(obrazek);
        warning_msg("Nepodařilo se načíst data ze souboru '%s'.\n", jmeno_souboru);
        return NULL;
    }

    // Uzavření souboru a vrácení struktury
    fclose(soubor);
    return obrazek;
}

void ppm_free(struct ppm *p)
{
    free(p);
}
