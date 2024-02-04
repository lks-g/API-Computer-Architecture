#include <stdio.h>

int Cis0=0, Cis1=0, Vysledok=0;

int main()
{
    printf("Vlozte dve cisla: ");
    scanf("%d%d", &Cis0, &Cis1);

#ifdef __GNUC__
    asm(".intel_syntax noprefix \n"     // Prepneme z AT&T syntaxe na Intel
        "mov eax, Cis0          \n"     // Cislo0 -> EAX
        "add eax, Cis1          \n"     // EAX + Cislo1
        "mov Vysledok,eax       \n"     // EAX  -> Vysledok
        ".att_syntax            \n");   // Dame vsetko do povodneho stavu
#endif
    printf("%d + %d = %d", Cis0, Cis1, Vysledok);
    return 0;
}