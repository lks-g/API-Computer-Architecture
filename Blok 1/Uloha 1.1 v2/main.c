#include <stdio.h>

/* Zadanie:
 *  Napiste program, ktory zobrazi nasledovne dva vstupy:
 *  cislo 33777 a ASCII kod znaku X, v dvojkovej, desiatkovej a sestnastkovej sustave.
 *
 * i       = premenna do ktorej ulozime prevratenu hodnotu vysledku.
 * cislo   = premenna ktora ulozi vstupnu hodnotu od pouzivatela.
 * ASCII   = Premenna ktora ulozi charakter vlozeny pouzivatelom.
 * zaklad  = inicializuje index od nuly.
 * prevod  = polia ktore uchovaju cislo v binarnej sustave pokial je <= 20. */

char ASCII;
int  i, n;
int cislo,zaklad, prevod[20];

int bin_prevod(n)
{
    zaklad = 0;
    while ( n > 0)
    {
        prevod[zaklad] = n % 2;
        n = n / 2;
        zaklad++;
    }

    for (i = (zaklad - 1); i >= 0; i--)        /* For-cyklus vypise cislo od MSB po LSB. */
        printf("%d", prevod[i]);

     return 0;
}

int main()
{
    printf("Vlozte charakter: ");
    scanf("%c", &ASCII);

    printf("Vlozte cislo: ");
    scanf("%d", &cislo);

    printf("ASCII kod %c v decimalnej sustave je %d\n", ASCII, ASCII);
    printf("ASCII kod %c v hexadecimalnej sustave je %x\n", ASCII, ASCII);
    printf("ASCII kod %c v binarnej sustave je ", ASCII);
    printf(bin_prevod(ASCII));
    printf("\nCislo %d v decimalnej sustave je %d\n", cislo, cislo);
    printf("Cislo %d v hexadecimalnej sustave je %x", cislo, cislo);
    printf("\nCislo %d v binarnej sustave je ", cislo);
    printf(bin_prevod(cislo));

    return 0;
}

