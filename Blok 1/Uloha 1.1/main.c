#include <stdio.h>

/* Zadanie:
 * Napiste program, ktory zobrazi nasledovne dva vstupy:
 * cislo 33777 a ASCII kod znaku X, v dvojkovej, desiatkovej a sestnastkovej sustave.
 *
 * i                = premenna do ktorej ulozime prevratenu hodnotu vysledku.
 * cislo            = premenna ktora ulozi vstupnu hodnotu od pouzivatela.
 * ASCII            = Premenna ktora ulozi charakter vlozeny pouzivatelom.
 * zaklad a zakladA = inicializuje index od nuly.
 * prevod a prevodA = polia ktore uchovaju cislo v binarnej sustave pokial je <= 20. */

int main()
{
    char ASCII;
    int  i, cislo, zaklad = 0, zakladA = 0, prevod[20], prevodA[20];

    printf("Vlozte charakter: ");
    scanf("%c", &ASCII);

    printf("Vlozte cislo: ");
    scanf("%d", &cislo);

    printf("ASCII kod %c v decimalnej sustave je %d\n", ASCII, ASCII);
    printf("ASCII kod %c v hexadecimalnej sustave je %x\n", ASCII, ASCII);
    printf("ASCII kod %c v binarnej sustave je ", ASCII);

    while ( ASCII > 0)
    {
        prevodA[zakladA] = ASCII % 2;
        ASCII = ASCII / 2;
        zakladA++;
    }

    for (i = (zakladA - 1); i >= 0; i--)        /* For-cyklus vypise cislo od MSB po LSB. */
        printf("%d", prevodA[i]);

    printf("\nCislo %d v decimalnej sustave je %d\n", cislo, cislo);
    printf("Cislo %d v hexadecimalnej sustave je %x", cislo, cislo);
    printf("\nCislo %d v binarnej sustave je ", cislo);

    while (cislo > 0)
    {
        prevod[zaklad] = cislo % 2;
        cislo = cislo / 2;
        zaklad++;
    }

    for (i = (zaklad - 1); i >= 0; i--)         /* For-cyklus vypise cislo od MSB po LSB. */
        printf("%d", prevod[i]);

    return 0;
}


