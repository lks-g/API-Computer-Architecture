#include <stdio.h>

/* Zadanie: Napiste pomocou inline asembleru a instrukcie cpuid program, ktory zisti, aky typ procesora mate v pocitaci */

char pole[12];

int main()
{
    #ifdef __GNUC__
        asm(".intel_syntax noprefix \n"
            "mov eax, 0             \n"
            "cpuid                  \n"
            "mov pole,   ebx        \n"
            "mov pole+4, edx        \n"
            "mov pole+8, ecx        \n"
            ".att_syntax            \n");
    #endif
        for (int i = 0; i < 12; i++)
        {
            printf("%c", pole[i]);
        }
    return 0;
}