#include <stdio.h>

/* Zadanie */
/* Zmente kodovanie z ISO-8859-2 na Windows-1250 */

int main()
{
    char text;

    FILE *vstup, *vystup;

    vstup = fopen(".\\FEI STU . Architektura Pocitacov (2201).html", "rb");
    vystup = fopen(".\\Vystup.html", "w");

    text = fgetc(vstup);

    while(text != EOF)
    {
        if (text == (char)165)
            text = (char)188;

        else if (text == (char) 169)
            text = (char)138;

        else if (text == (char) 171)
            text = (char)141;

        else if (text == (char) 174)
            text = (char)142;

        else if (text == (char) 181)
            text = (char)190;

        else if (text == (char) 185)
            text = (char)154;

        else if (text == (char) 187)
            text = (char)157;

        else if (text == (char) 190)
            text = (char)158;

        fprintf(vystup, "%c", text);
        text = fgetc(vstup);
    }

    fclose(vstup);
    fclose(vystup);

    return 0;
}
