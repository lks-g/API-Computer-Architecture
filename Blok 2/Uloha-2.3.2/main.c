#include <stdio.h>

/* Zadanie */
/* Napíšte program, ktorý prečíta text zo súboru a každý znak pred výpisom dešifruje. */

int main()
{
    char desifPis;          // Pismeno ktore musime desifrovat.
    FILE *Vstup, *Vystup;

    Vstup = fopen(".\\koniec_poviedky.html", "rb");
    Vystup = fopen(".\\Vystup_2.html", "w");

    desifPis = fgetc(Vstup);
    while (desifPis != EOF)
    {
        desifPis = desifPis ^ 27;
        fprintf (Vystup, "%c", desifPis);
        desifPis = fgetc(Vstup);
    }

    fclose(Vstup);
    fclose(Vystup);

    return 0;
}
