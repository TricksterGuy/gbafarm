#include "myLib.h"
#include <stdio.h>
#include <stdlib.h>
#include "gamemap.h"


int main(void)
{
    int i;
    int voff = 0;
    int hoff = 0;
    for(i=0; i < GAMEMAP_TILES_LENGTH; i++)
    {
        CHARBLOCKBASE[0].tileimg[i] = gamemap_tiles[i];
    }

    for(i=0; i < MAPLAYER0_MAP_LENGTH; i++)
    {
        SCREENBLOCKBASE[28].tilemap[i] = maplayer0[i];
    }

    for(i=0; i < MAPLAYER1_MAP_LENGTH; i++)
    {
        SCREENBLOCKBASE[29].tilemap[i] = maplayer1[i];
    }

    for(i=0; i < GAMEMAP_PALETTE_LENGTH; i++)
    {
        PALETTE[i] = gamemap_palette[i];
    }

    REG_DISPCTL = MODE0 | BG0_ENABLE | BG1_ENABLE;
    REG_BG1CNT = MAPLAYER0_MAP_TYPE | SBB(28) | CBB(0) | GAMEMAP_PALETTE_TYPE;
    REG_BG0CNT = MAPLAYER1_MAP_TYPE | SBB(29) | CBB(0) | GAMEMAP_PALETTE_TYPE;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;

    while(1)
    {
        waitForVblank();
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

        REG_BG0HOFS = hoff;
        REG_BG0VOFS = voff;
        REG_BG1HOFS = hoff;
        REG_BG1VOFS = voff;
    }

    return 0;
}
