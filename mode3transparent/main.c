#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "background.h"

int main(void)
{
    REG_DISPCTL = MODE3 | BG2_ENABLE;

	for (unsigned int i = 0; i < BACKGROUND_LENGTH; i++)
		if (background[i] != BACKGROUND_TRANSPARENT)
			videoBuffer[i] = background[i];

    while(1);

    return 0;
}

