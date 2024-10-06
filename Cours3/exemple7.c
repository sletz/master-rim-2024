
#include <stdio.h>

/*
Structure de contrôle : choix avec le IF
*/

int main()
{
    int a = 20;
  
    if (a < 20) {
        printf("La variable 'a' est inférieure à 20\n");
    } else {
        printf("La variable 'a' est supérieure ou égale à 20\n");
    }

    if (a < 20) {
        printf("La variable 'a' est inférieure à 20\n");
    } else if (a == 20) {
        printf("La variable 'a' est égale à 20\n");
    } else {
        printf("La variable 'a' est supérieure à 20\n");
    }
    
    return 0;
}
