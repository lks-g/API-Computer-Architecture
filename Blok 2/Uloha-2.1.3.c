#include <stdio.h>

int Cislo=0, Vysledok=0;

int main()
{
    for (Cislo=0; Cislo <= 9; Cislo++)
    {
    #ifdef __GNUC__
            asm(".intel_syntax noprefix \n"     // Prepneme z AT&T syntaxe na na Intel
                "mov eax, Cislo         \n"     // EAX = Cislo
                "add eax, '0'           \n"     // EAX + '0'
                "cmp eax, Cislo         \n"     // Porovnanie hodnot EAX s Cislom
                "jmp a2                 \n"     // Skok na a2
                "a2: mov Vysledok, eax  \n"     // Vysledok = eax
                ".att_syntax            \n");   // Dame vsetko do povodneho stavu
    #endif
        printf("Cislo (%d) v hexadec (%c)\n", Cislo, Vysledok);
    }
    for (Cislo=10; Cislo <= 15; Cislo++)
    {
    #ifdef __GNUC__
            asm(".intel_syntax noprefix \n"     // Prepneme z AT&T syntaxe na na Intel
                "mov ebx, Cislo         \n"     // EAX = Cislo
                "add ebx, 55            \n"     // EAX + 55
                "cmp ebx, Cislo         \n"     // Porovnanie hodnot EAX s Cislom
                "jmp a1                 \n"     // Skok na a2
                "a1: mov Vysledok, ebx  \n"     // Vysledok = eax
                ".att_syntax            \n");   // Dame vsetko do povodneho stavu
    #endif
            printf("Cislo (%d) v hexadec (%c)\n", Cislo, Vysledok);
    }
    return 0;
}
