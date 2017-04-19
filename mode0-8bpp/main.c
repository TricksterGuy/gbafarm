#include "myLib.h"
#include <stdio.h>
#include <stdlib.h>
#include "spiral.h"


int main(void)
{
    int i;
    int voff = 0;
    int hoff = 0;
    for(i=0; i < SPIRAL_TILES_LENGTH; i++)
    {
        CHARBLOCKBASE[0].tileimg[i] = spiral_tiles[i];
    }

    for(i=0; i < SPIRAL_MAP_LENGTH; i++)
    {
        SCREENBLOCKBASE[28].tilemap[i] = spiral[i];
    }

    for(i=0; i<SPIRAL_PALETTE_LENGTH; i++)
    {
        PALETTE[i] = spiral_palette[i];
    }

    REG_DISPCTL = MODE0 | BG0_ENABLE;
    REG_BG0CNT = SPIRAL_MAP_TYPE | SBB(28) | CBB(0) | SPIRAL_PALETTE_TYPE;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;

    while(1)
    {

        if(KEY_DOWN_NOW(BUTTON_LEFT))
        {
            hoff--;
            if(hoff<0) hoff = 0;
        }

        if(KEY_DOWN_NOW(BUTTON_RIGHT))
        {
            hoff++;
            if(hoff > 256-240) hoff = 256-240;
        }

        if(KEY_DOWN_NOW(BUTTON_UP))
        {
            voff--;
            if(voff<0) voff = 0;
        }
        if(KEY_DOWN_NOW(BUTTON_DOWN))
        {
            voff++;
            if(voff > 256-160) voff = 256 - 160;
        }
        waitForVblank();
        REG_BG0HOFS = hoff;
        REG_BG0VOFS = voff;
    }

    return 0;
}

