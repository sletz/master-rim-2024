
#include <stdio.h>

int somme_entiere(int x, int y);

/*
Variables globales et variables locales.
*/

/* Variables globales "accessibles" partout */
float c = 100.12f;
float d = 200.34f;
 
int somme_entiere(int x, int y)
{
    return x + y;
}

float somme_flottant(float x, float y)
{
    return x + y;
}

int main()
{
    /* Variables locales "accessibles" seulement dans cette fonction */
    int a = 10;
    int b = 20;
    
    printf("a = %d b = %d somme entière = %d\n", a, b, somme_entiere(a,b));
    printf("c = %f d = %f somme flottante = %f\n", c, d, somme_flottant(c,d));
    
    return 0;
}
