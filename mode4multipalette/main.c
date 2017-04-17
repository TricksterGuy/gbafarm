#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "image1.h"
#include "background.h"

int main(void)
{
    REG_DISPCTL = MODE4 | BG2_ENABLE;

    u32 i = 0;
    for (i = 0; i < IMAGE1_PALETTE_LENGTH; i++)
        PALETTE[i] = image1_palette[i];
    for (i = 0; i < BACKGROUND_PALETTE_LENGTH; i++)
        PALETTE[i + BACKGROUND_PALETTE_OFFSET] = background_palette[i];

    for (u32 i = 0; i < BACKGROUND_LENGTH; i++)
        videoBuffer[i] = background[i];

    for (int y = 0; y < IMAGE1_WIDTH; y++)
        for (int x = 0; x < IMAGE1_WIDTH/2; x++)
            videoBuffer[y * 120 + x] = image1[y * IMAGE1_WIDTH/2 + x];

    while(1);

    return 0;
}

