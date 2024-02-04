#include <stdio.h>
#include <windows.h>                          // potrebne pre pracu s WinAPI

const unsigned char RohVlavoHore = 218;
const unsigned char RohVpravoHore = 191;
const unsigned char RohVpravoDole = 217;
const unsigned char RohVlavoDole = 192;
const unsigned char ciaraX = 196;
const unsigned char ciaraY = 179;
const unsigned char tvarT = 194;
const unsigned char tvarTotc = 193;
const unsigned char ciaraYX = 180;
const unsigned char ciaraXY = 195;
const unsigned char kriz = 197;

int main(int argc, char* argv[])
{
    int X=0, Y=0;

    scanf("%d%d", X,Y);

    /* X = 39 - Y = 12 */

    HANDLE  hConsole;                           // ziskanie handle konzoly
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD point = {X,Y};                        // Suradnice: X:stlpec, Y:riadok

    SetConsoleCursorPosition(hConsole, point);  // nastavi sa na [39,12]

    putchar(RohVlavoHore);                     // vytlaci tam znak '_|'
    for(int i = 0; i < X; i++)
    {
        putchar(ciaraX);
    }
    putchar(RohVpravoHore);
    for(int i = 0; i < Y; i++)
    {
        putchar(ciaraY);
    }
    putchar(RohVpravoDole);

    printf("Stlac ENTER a skoncime...\n");      // tento vypis je od [0,22] dalej
    scanf("?");
    return(0);
}