#include <stdio.h>

int cis1=0, vysledok=0;

int main()
{
    printf("Vlozte cislo: ");
    scanf("%d", &cis1);
    
#ifdef __GNUC__
    asm(".intel_syntax noprefix \n"     // Prepneme z AT&T syntaxe na na Intel
        "mov eax,cis1           \n"     // EAX = Cislo1
        "shl eax                \n"     // Posun o jedno miesta dolava
        "mov vysledok,eax       \n"     // Vysledok = EAX
        ".att_syntax            \n");   // Dame vsetko do povodneho stavu
#endif
    printf("%d * 2 = %d", cis1, vysledok);
    return 0;
}