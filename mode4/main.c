#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "background.h"

int main(void)
{
    REG_DISPCTL = MODE4 | BG2_ENABLE;

    for (u32 i = 0; i < BACKGROUND_PALETTE_LENGTH; i++)
        PALETTE[i] = background_palette[i];

    for (u32 i = 0; i < BACKGROUND_LENGTH; i++)
        videoBuffer[i] = background[i];

    while(1);

    return 0;
}

