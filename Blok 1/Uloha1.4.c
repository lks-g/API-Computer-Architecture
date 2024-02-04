#include <stdio.h>
#include <math.h>

/* Napiste program na vypocet funkcie sin(x) alebo cos(x) pomocou rozvoja do Taylorovho radu v okolí bodu 0. Inymi slovami,
 * budete programovat funkciu sínus alebo kosinus sami, bez toho, aby ste použili iné existujúce riešenie.
 * Funkcia bude mať dva argumenty:
 *                  float sinus(float radians, float epsilon);  */

int faktorial(int n)
{
    unsigned long long fakt = 1 ;

    if (n == 0)
        return 1;

    else
    {
        for (int i = 1; i <= n; ++i)
        {
            fakt *= i;
        }
        return fakt;
    }
}

float sinus(float uhol, float epsilon)
{
    float a, b, citatel, vysledok=0, sinushod= 0;
    unsigned long int menovatel;

    sinushod = sin(uhol);

    for (int n=0; epsilon <= fabs(sinushod - vysledok); n++)
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
    float x=0, uhol=0, vysledok, epsilon=0.00001;

    printf("Vlozte uhol (v stupnoch): ");
    scanf("%f", &uhol);

    x = uhol;

    vysledok = sinus(uhol * M_PI/180, epsilon);

    printf("Sinus(%.0f) = %f\n", x, vysledok);

    return 0;
}