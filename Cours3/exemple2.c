
#include <stdio.h>

/*
Déclaration de variables avec un type.
*/

int main()
{
    /* Entiers sur 4 octets */
    
    /*  Déclaration d'une variable */
    int a;
    a = 10;
    
    /*  Déclaration d'une variable avec affectation */
    int b = 20;
    
    printf("a = %d b = %d somme = %d\n", a, b, a+b);
    
    /* Flottants sur 4 octets */
    float c = 3.14;
    float d = 1.23456f;
    
    printf("c = %f d = %f somme = %f\n", c, d, c+d);
    
    /* Tableau de flottants */
    float table[100];
    
    table[0] = 23.0f; 
    table[99] = 1.25765f; 
    
    table[0] = table[0] + 10.f;
     
    printf("table[0] = %.2f table[99] = %f somme = %.2f\n", table[0], table[99], table[0]+table[99]);
    
    float table1[10];
    
    table1[0] = 1.f;
    table1[1] = 23.f;
    
    float table2[10] = { 1.f, 23.f, 67.f, 100.f, 56.f, 29.f, 0.f, 7.f, 234.f, 10.f };
    
    printf("table1[0] = %.2f table1[7] = %f somme = %f\n", table1[0], table1[7], table1[0]+table1[7]);
     
    printf("Une chaine = %s_%s%d\n", "Toto", "Titi", 89);
    
    return 0;
}
