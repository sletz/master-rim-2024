
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "misc.h"

int main(int argc, char* argv[])
{
    int val = lopt(argv, "-a", 1);
    char* str = lopts(argv, "-s", "toto");
     
    printf("Valeur passée après -a = %d\n", val);
    printf("Valeur passée après -s = %s\n", str);
   
    return 0;
}
