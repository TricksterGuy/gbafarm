#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "background.h"
#include "custom.h"

int main(void)
{
    REG_DISPCTL = MODE4 | BG2_ENABLE;

    for (u32 i = 0; i < CUSTOM_PALETTE_LENGTH; i++)
        PALETTE[i] = custom_palette[i];

    for (u32 i = 0; i < BACKGROUND_LENGTH; i++)
        videoBuffer[i] = background[i];

    while(1);

    return 0;
}

