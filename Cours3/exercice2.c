 
#include <stdio.h>

/*
Structure de contrôle : boucle avec le FOR pour traiter des tableaux
*/
    
int main()
{
    /* Definir un tableau avec des valeurs explicites */
    float table1[10] = { 1.f, 23.f, 67.f, 100.f, 56.f, 29.f, 0.f, 7.f, 234.f, 10.f };
    
    int i = 0;
    
    // Calcul de la somme des éléments du tableau
    float somme = 0.f;
    for (i = 0; i < 10; i = i+1) {
        somme = somme + table1[i];
    }
    
    printf("Somme = %f\n", somme);
    
    /* Definir un tableau avec des valeurs explicites */
    float somme2 = 0.f;
    float table2[10] = { 1.f, 23.f, 67.f, 100.f, 56.f, 29.f, 0.f, 7.f, 234.f, 10.f };
    for (i = 0; i < 10; i = i+1) {
        somme2 = somme2 + table2[i];
    }
    printf("Moyenne = %f\n", somme2/10.f);
    printf("Moyenne = %f\n", somme2/(float)i);
  
    float table3[10] = { 1.f, 23.f, 67.f, 100.f, 56.f, 29.f, 0.f, 7.f, 234.f, 10.f };
    
    float minimum = table3[0];
    float maximum = table3[0];
    for (i = 0; i < 10; i = i+1) {
        // Mettre à jour le minimum
        if (table3[i] < minimum) {
            minimum = table3[i];
        }
        // Mettre à jour le maximum
        if (table3[i] > maximum) {
            maximum = table3[i];
        }
    }
    
    printf("Minimum = %f\n", minimum);
    printf("Maximum = %f\n", maximum);
    
    return 0;
}
