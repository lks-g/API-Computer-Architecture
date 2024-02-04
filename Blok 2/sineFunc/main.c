#include <stdio.h>
#include <math.h>

int faktorial(int n)
{
    unsigned long long fact = 1 ;

    if (n == 0)
        return 1;

    else
    {
        for (int i = 1; i <= n; ++i)
        {
            fact *= i;
        }
        return fact;
    }
}

float sinus(float uhol, float epsilon)
{
    float a, b, citatel, vysledok=0;
    unsigned long int menovatel;

    for (int n=0; n < 8; n++)
    {
        a  = pow(-1,n);
        b  = pow(uhol,2*n+1);
        citatel = a*b;
        menovatel  = faktorial(2*n+1);
        vysledok  += citatel/menovatel;
    }
    return vysledok;
}

int main()
{
    float x, uhol=0, vysledok, epsilon=0;

    printf("Vlozte uhol (v stupnoch): ");
    scanf("%f", &uhol);

    printf("Vlozte epsilon: ");
    scanf("%f", &epsilon);

    x = uhol;

    vysledok = sinus(uhol * M_PI/180, epsilon);

    printf("Sinus(%.0f) = %f\n", x, vysledok);

    return 0;
}