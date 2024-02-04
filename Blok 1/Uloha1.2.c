#include <stdio.h>

// Napiste program, ktory dokaze zapisat zadane cislo (staci rozsah 1-100) rimskymi cislicami.
// Cisla v Rimskej ciselnej sustave:
//  1 = I    |   4 = IV     |    5 = V     |   9 = IX    |
//  10 = X   |   40 = XL    |   50 = L     |    90 = XC  |  100 = C  |

int rimCis();                                // Preddefinovanie funkcie rimCis ('Rimske Cisla').

int main()
{
    int cislo;                              // Premenna ulozi cislo zadane pouzivatelom.

    printf("Vlozte cislo: ");
    scanf("%d", &cislo);
    printf("Rimsky ekvivalent cisla %d je: ", cislo);

    rimCis(cislo);                          // Zavolanie funkcie rimCis ('Rimske Cisla').

    return 0;
}

int rimCis(int cislo)                       // Funkcia rimCis zisti Rimsky ekvivalent zadaneho cisla.
{
    while(cislo != 0)                       // Cyklus bude porovnavat vstupnu hodnotu (pokial sa nerovna 0) s hodnotami z rimskej ciselnej sustavy.
    {
        if (cislo >= 100)
        {
            printf("C");
            cislo -= 100;
        }

        else if (cislo >= 90)
        {
            printf("XC");
            cislo -= 90;
        }

        else if (cislo >= 50)
        {
            printf("L");
            cislo -= 50;
        }

        else if (cislo >= 40)
        {
            printf("XL");
            cislo -= 40;
        }

        else if (cislo >= 10)
        {
            printf("X");
            cislo -= 10;
        }

        else if (cislo >= 9)
        {
            printf("IX");
            cislo -= 9;
        }

        else if (cislo >= 5)
        {
            printf("V");
            cislo -= 5;
        }

        else if (cislo >= 4)
        {
            printf("IV");
            cislo -= 4;
        }

        else if (cislo >= 1)
        {
            printf("I");
            cislo -= 1;
        }

        else
        {
            return 0;
        }
    }
    return 0;
}