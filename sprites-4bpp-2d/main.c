#include "myLib.h"
#include <stdio.h>
#include <stdlib.h>
#include "sprites.h"

OamEntry shadow[128];

int main(void)
{
    DMA[3].src = sprites_palette;
    DMA[3].dst = SPRITEPAL;
    DMA[3].cnt = SPRITES_PALETTE_LENGTH | DMA_ON;

    DMA[3].src = sprites;
    DMA[3].dst = SPRITEDATA;
    DMA[3].cnt = SPRITES_LENGTH | DMA_ON;

    REG_DISPCTL = MODE0 | OBJ_ENABLE | SPRITES_DIMENSION_TYPE;

    for(int i = 0; i < 128; i++)
        shadow[i].attr0 = ATTR0_HIDE;

    OamEntry* blue = shadow;
    blue->attr0 = 32 | SPRITES_PALETTE_TYPE | BLUE8X8_SPRITE_SHAPE;
    blue->attr1 = 64 | BLUE8X8_SPRITE_SIZE;
    blue->attr2 = BLUE8X8_PALETTE_ID | BLUE8X8_ID;

    OamEntry* bowser = shadow + 1;
    bowser->attr0 = 19 | SPRITES_PALETTE_TYPE | BOWSER4X4_SPRITE_SHAPE;
    bowser->attr1 = 12 | BOWSER4X4_SPRITE_SIZE;
    bowser->attr2 = BOWSER4X4_PALETTE_ID | BOWSER4X4_ID;

    OamEntry* tiny = shadow + 2;
    tiny->attr0 = 100 | SPRITES_PALETTE_TYPE | TINY1X1_SPRITE_SHAPE;
    tiny->attr1 = 0 | TINY1X1_SPRITE_SIZE;
    tiny->attr2 = TINY1X1_PALETTE_ID | TINY1X1_ID;

    while(1)
    {
        waitForVblank();
		DMA[3].src = shadow;
		DMA[3].dst = SPRITEMEM;
		DMA[3].cnt = 128 * 4 | DMA_ON;
    }

    return 0;
}

