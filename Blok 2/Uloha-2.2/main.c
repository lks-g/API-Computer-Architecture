#include <stdio.h>

int main()
{
    char pole[35]= {"architektura_pocitacov_je_super"};    // Pole znakov.
    printf("%s\n", pole);                           // Vypis retazca z pola.

    char* smernik = &pole;                                 // pointer na pole znakov.

    printf("\nAdresa na ktoru ukazuje smernik: ");

    printf("%p\n", smernik);

    printf("Adresa pola: ");
    printf("%p\n", pole);

    printf("\nAdresa na ktoru ukazuje smernik po pripocitani 1-tky: ");

    smernik++;                                              // Pripocitame 1-tku k pointru.
    printf("%p\n", smernik);

    printf("Retazec po pridani znaku '0': ");

    *(smernik) = '0';
    printf("%s\n", pole);

    printf("\nAdresa na ktoru ukazuje smernik po uprave hodnoty: ");

    smernik = 251451555;                                    // Pripocitanie nahodnej hodnoty k pointru.

    printf("%p\n", smernik);

    *(smernik) = '0';
    printf("%s\n", pole);

    return 0;
}

