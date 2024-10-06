
#include <stdio.h>

/*
Conversion entre types.
*/

int main()
{
    float a = 34.14f;
    float b = 1.83456f;
    
    printf("a = %f b = %f \n", a, b);  // Par défaut, affichage de 6 décimales
    
    // Imprimer un nombre choisi de décimales
    printf("a = %.2f b = %.3f \n", a, b);
    
    int c = (int)a;
    int d = b;
    
    printf("c = %d d = %d \n", c, d);
    
    int e = 12345;
    int f = 2575;
    
    float g = (float)e;
    float h = f;
    
    printf("g = %f h = %f \n", g, h);
    
    return 0;
}
