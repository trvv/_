#include "_.h"

#include <stdio.h>

Status main(Integer n, Arguments(n) arguments)
{
    Integer i;
    
    for (i = 1; i < n - 1; i++) {
        printf("%s ", arguments[i]);
    }

    if (n > 1) printf("%s\n", arguments[i]);

    return 0;
}
