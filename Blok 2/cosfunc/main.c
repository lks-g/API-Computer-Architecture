#include <stdio.h>
#include <math.h>

float kosinus(float radians)
{
    float podmienka = 1, vysledok = 1, x = radians;

    for (int i=1; i<10; i++)
    {
        podmienka = podmienka * pow (-1,(2*i-1))*x*x/(2*i*(2*i-1));
        vysledok  = vysledok + podmienka;
    }
}

int main()
{
    float x, vysledok;
    int uhol;

    printf ("Vlozte uhol v stupnoch: ");
    scanf ("%f", &x);

    uhol=x;
    x = x*(M_PI/180);
    vysledok = kosinus(x);

    printf ("cos(%d)= %f", uhol, vysledok);
    return 0;
}