 
#include <stdio.h>
#include <math.h>

void square()
{
    float table[100];
    int i;
    
    // 1° version avec 2 boucles pour remplir les 2 parties du signal
    /*
    for (i = 0; i < 50; i = i+1) {
        table[i] = -1.f;
    }
    
    for (i = 50; i < 100; i = i+1) {
        table[i] = 1.f;
    }
    */
    
    // 2° version avec 1 boucle et un 'if'
    for (i = 0; i < 100; i = i+1) {
        if (i < 50) {
            table[i] = -1.f;
        } else {
            table[i] = 1.f;
        }
    }
    
    printf("Square\n");
    for (i = 0; i < 100; i = i+1) {
        printf("Sample = %f\n", table[i]);
    }
}

void sawtooth()
{
    float table[100];
    int i;

    for (i = 0; i < 100; i = i+1) {
        table[i] = 2.f*(float)i/99.f - 1.f;
    }
    
    printf("sawtooth\n");
    for (i = 0; i < 100; i = i+1) {
        printf("Sample = %f\n", table[i]);
    }
}

float PI = 3.141592653;

void sinus()
{
    float table[100];
    int i;
    
    for (i = 0; i < 100; i = i+1) {
        table[i] = sin(2.f*PI*(float)i/99.f);
    }
    
    printf("sinus\n");
    for (i = 0; i < 100; i = i+1) {
        printf("Sample = %f\n", table[i]);
    }
}

int main()
{
    square();
    sawtooth();
    sinus();
    
    return 0;
}
