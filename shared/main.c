#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"

int main(void)
{
    REG_DISPCTL = MODE3 | BG2_ENABLE;

    while(1);

    return 0;
}

