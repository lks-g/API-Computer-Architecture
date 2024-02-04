#include <stdio.h>
#include <windows.h>

int colorPalette()
{
    int n=0;
    for (int i=0; i <= 255; i++)
    {
        HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(consolehwnd, n);
        printf("%d", i);
        n++;
    }
}

int colorChange(int n)
{
    HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consolehwnd, n);
    return 0;
}

int main()
{
    colorPalette();
    printf("\n\n");
   for (int i=0; i <= 50; i++)
    {
        if (i <= 9)
        {
            colorChange(9);
            Sleep(1000);
            printf("00%d\n", i);
        }
        else if (i > 9 && i < 18)
        {
            colorChange(10);
            Sleep(1000);
            printf("0%d\n", i);
        }
        else if (i > 18 && i < 25)
        {
            colorChange(12);
            Sleep(1000);
            printf("0%d\n", i);
        }
        else if (i > 25 && i < 33)
        {
            colorChange(11);
            Sleep(1000);
            printf("0%d\n", i);
        }
        else if (i > 33 && i < 43)
        {
            colorChange(14);
            Sleep(1000);
            printf("0%d\n", i);
        }
        else if (i > 43 && i <= 50)
        {
            colorChange(5);
            Sleep(1000);
            printf("0%d\n", i);
        }
    }
    return 0;
}