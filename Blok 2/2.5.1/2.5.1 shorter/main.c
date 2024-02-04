#include <stdio.h>
#include <windows.h>

void colorChange(int n)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, n);
}

int main()
{
    int n=1;
    for (int i=0; i <= 50; i++)
    {
        Sleep(1000);
        if (i == 10 || i == 20 && i > 10 || i == 30 && i > 20 || i == 40 && i > 30)
            n++;
        colorChange(n);
        if (i < 10)
            printf("%03d\n", i);
        else
           printf("%03d\n", i);
    }
    return 0;
}
