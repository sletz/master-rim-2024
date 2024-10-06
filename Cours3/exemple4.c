
#include <stdio.h>

/*
Definition et appel de fonction.
*/

float somme(float x, float y)
{
    float res = x + y;
    return res;
}

int soustraction_entiere(int x, int y)
{
    return x - y;
}

void fonction1()
{
    printf("===========\n");
    printf("Example4\n");
    printf("Example4\n");
    printf("Example4\n");
}

int main()
{
    fonction1();
    
    printf("soustraction entière = %d\n", 30-5);
    
    printf("soustraction entière de %d et de %d est %d\n", 10, 20,
           soustraction_entiere(10, 20));
    
    int a = 100;
    int b = 23;
    
    printf("soustraction entière de %d et de %d est %d\n", a, b,
           soustraction_entiere(a, b));
    
    int res2 = soustraction_entiere(50, 14);
    printf("res2 = %d\n", res2);
    
    float res1 = somme(10, 20);
    printf("res1 = %.1f\n", res1);
    return 0;
}
