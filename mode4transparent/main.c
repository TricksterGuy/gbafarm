#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "cross.h"

int main(void)
{
    REG_DISPCTL = MODE4 | BG2_ENABLE;

    for (u32 i = 0; i < CROSS_PALETTE_LENGTH; i++)
        PALETTE[i] = cross_palette[i];

    for (int y = 0; y < CROSS_HEIGHT; y++)
    {
        for (int x = 0; x < CROSS_WIDTH/2; x++)
        {
            short pix = cross[y * CROSS_WIDTH/2 + x];
            if (pix)
                videoBuffer[y * 120 + x] = pix;
        }
    }

    while(1);

    return 0;
}

