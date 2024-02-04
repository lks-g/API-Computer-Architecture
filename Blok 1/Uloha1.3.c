#include <stdio.h>
#include <float.h>

/*  Napiste program, ktory zisti a vypise na obrazovku strojove epsilon pre datove typy float a double.
    Zaroven vypiste aj hodnoty __FLT_EPSILON__ a __DBL_EPSILON__ zadefinovane vo float.h. */

int my_flt_Epsilon();   // Preddefinovanie funkcii pouzitich v main().
int my_dbl_Epsilon();

int main()              //Funkcia vypise hodnoty strojoveho epsilonu pre datove premenne float a double z funkcii a modulu float.h.
{
    float  f_eps = FLT_EPSILON;
    double d_eps = DBL_EPSILON;

    printf("\nFLT_EPSILON: \t\t%.30lf = %e\n",f_eps, f_eps); //Vypise Strojove Epsilon pre dany pocitac (float).
    my_flt_Epsilon();

    printf("\nDBL_EPSILON: \t\t%.30lf = %e\n",d_eps, d_eps); //Vypise Strojove Epsilon pre dany pocitac (double).
    my_dbl_Epsilon();

    return 0;
}

int my_flt_Epsilon()                    //Funkcia zisti a vypise strojovy epsilon pre datovy typ float.
{
    float Epsilon_f = 1;
    while (1 == 1)
    {
        float noveEpsilon = Epsilon_f/2;        //Do premennej ulozime hodnotu epsilonu po deleni 2.

        if (1 + noveEpsilon == 1)               //Ak je podmienka splnena cyklus sa ukonci.
            break;
        Epsilon_f = noveEpsilon;
    }
    printf( "MOJE FLT_EPSILON:\t%.30lf = %e\n", Epsilon_f, Epsilon_f);
    return 0;
}

int my_dbl_Epsilon()                    //Funkcia zisti a vypise strojovy epsilon pre datovy typ double.
{
    double Epsilon_d = 1;
    while(1 == 1)
    {
        double noveEpsilon = Epsilon_d/2;       //Do premennej ulozime hodnotu epsilonu po deleni 2.

        if (1 + noveEpsilon == 1)               //Ak je podmienka splnena cyklus sa ukonci.
            break;
        Epsilon_d = noveEpsilon;
    }
    printf ("MOJE DBL_EPSILON:\t%.30lf = %e\n", Epsilon_d, Epsilon_d);
    return 0;
}
