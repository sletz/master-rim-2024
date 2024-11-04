#include <stdio.h>

int somme(int x, int y)
{
    return x+y;
}

int difference(int x, int y)
{
    return x-y;
}

int main()
{
    int a = 20;
    int b = 10;
    
    printf("addition entière de %d et de %d : %d\n", a, b, a+b);
    printf("soustraction entière de %d et de %d : %d\n", a, b, a-b);
    printf("multiplication entière de %d et de %d : %d\n", a, b, a*b);
    printf("division entière de %d et de %d : %d\n", a, b, a/b);
    
    printf("addition entière de %d et de %d : %d\n", a, b, somme(a,b));
    printf("soustraction entière de %d et de %d : %d\n", a, b, difference(a,b));
    
    return 0;
}
