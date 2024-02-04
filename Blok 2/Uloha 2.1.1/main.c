#include <stdio.h>

static int Cis0=0, Cis1=0,  Vysledok=0;

int main()
{
    printf("Vlozte dve cisla: ");
    scanf("%d%d", &Cis0, &Cis1);

#ifdef __GNUC__
    asm(".intel_syntax noprefix \n"     // Prepneme z AT&T syntaxe na Intel
        "mov eax, Cis0          \n"     // iCislo -> EAX
        "add eax, Cis1          \n"     // EAX ++
        "mov Vysledok,eax       \n"     // EAX  -> iVysledok
        ".att_syntax            \n");   // Dame vsetko do povodneho stavu
#endif
    printf("%d + %d = %d", Cis0, Cis1, Vysledok);
    return 0;
}