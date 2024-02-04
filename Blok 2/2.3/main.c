#include <stdio.h>

int iCislo=0, iVysledok=0;

int main()
{
    printf("Zadaj cislo: ");
    scanf("%d", &iCislo);

    if (iCislo <= 9)
    {
    #ifdef __GNUC__
            asm(".intel_syntax noprefix  \n"     // Prepneme z AT&T syntaxe na na Intel
                "mov eax, iCislo         \n"     // EAX = Cislo
                "add eax, '0'            \n"     // EAX + znak '0'
                "mov iVysledok, eax      \n"     // Vysledok = EAX
                ".att_syntax             \n");   // Dame vsetko do povodneho stavu
    #endif
            printf("Cislo %d v hexadecimalnej sustave %c \n", iCislo, iVysledok);
    }
    else if ( iCislo <= 15)
    {
    #ifdef __GNUC__
            asm(".intel_syntax noprefix  \n"     // Prepneme z AT&T syntaxe na na Intel
                "mov eax, iCislo         \n"     // EAX = Cislo
                "add eax, 55             \n"     // EAX + 55
                "mov iVysledok, eax      \n"     // Vysledok = EAX
                ".att_syntax             \n");   // Dame vsetko do povodneho stavu
    #endif
            printf("Cislo %d v hexadecimalnej sustave %c \n", iCislo, iVysledok);
    }

    return 0;
}
