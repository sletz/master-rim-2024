
#include <stdio.h>

/*
Définition et appel de fonction avec type et prototypes plus complexes.
*/

float somme_flottant(float x, float y)
{
    return x + y;
}

float produit_flottant(float x, float y)
{
    return x * y;
}

int main()
{
    int a = 10;
    int b = 20;
    
    float c = 100.45f;
    float d = 200.678f;
    
    printf("c = %f\n", c);
    
    float res = somme_flottant(c, d);
    
    printf("res = %f\n", res);
    
    float res1 = produit_flottant(c, d);
    
    printf("res1 = %f\n", res1);
    
    return 0;
}
