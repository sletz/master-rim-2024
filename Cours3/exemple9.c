
#include <stdio.h>

/*
Lire des paramètres en entrée.
*/

int main()
{
    printf("Entrer un caractère\n");
    char val;
    
    label:
    
    val = getchar();
    
    if (val == 'a') {
        printf("Le caractère est 'a'\n");
    } else if (val == 'b') {
        printf("Le caractère est 'b'\n");
    } else {
        printf("Autre caractère \n");
        goto label;
    }
    
    printf("Entrer une valeur numérique\n");
     
    float freq;
    scanf("%f", &freq);
    
    printf("La valeur numérique est %f\n", freq);

    return 0;
}
