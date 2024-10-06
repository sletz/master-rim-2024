 
#include <stdio.h>
#include <math.h>

void square()
{
    float table[20];
    int i;
    
    /*
    for (i = 0; i < 10; i = i+1) {
        table[i] = -1.f;
    }
    
    for (i = 10; i < 20; i = i+1) {
        table[i] = 1.f;
    }
    */
    
    for (i = 0; i < 20; i = i+1) {
        if (i < 10) {
            table[i] = -1.f;
        } else {
            table[i] = 1.f;
        }
    }
    
    // A COMPLETER
    
    printf("Square\n");
    for (i = 0; i < 20; i = i+1) {
        printf("Sample = %f\n", table[i]);
    }
}

void sawtooth()
{
    float table[20];
    int i;

    for (i = 0; i < 20; i = i+1) {
        table[i] = 2.f*(float)i/19.f - 1.f;
    }
    
    printf("sawtooth\n");
    for (i = 0; i < 20; i = i+1) {
        printf("Sample = %f\n", table[i]);
    }
}

float PI = 3.1415;

void sinus()
{
    float table[20];
    int i;
    
    for (i = 0; i < 20; i = i+1) {
        table[i] = sin(2.f*PI*(float)i/19.f);
    }
    
    printf("sinus\n");
    for (i = 0; i < 20; i = i+1) {
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
