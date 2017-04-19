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

    for(i=0; i < GAMEMAP_PALETTE_LENGTH; i++)
    {
        PALETTE[i] = gamemap_palette[i];
    }

    for(i=0; i < GAMEMAP_MAP_LENGTH; i++)
    {
        SCREENBLOCKBASE[28].tilemap[i] = gamemap0[i];
    }

    REG_DISPCTL = MODE0 | BG0_ENABLE;
    REG_BG0CNT = GAMEMAP_MAP_TYPE | SBB(28) | CBB(0) | GAMEMAP_PALETTE_TYPE;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;

    int map_index = 0;
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
        if(KEY_DOWN_NOW(BUTTON_L))
        {
            while(KEY_DOWN_NOW(BUTTON_L));
            map_index = (map_index + 1) % GAMEMAP_FRAMES;
            const unsigned short* map = gamemap_frames[map_index];
            for(i=0; i < 1024; i++)
            {
                SCREENBLOCKBASE[28].tilemap[i] = map[i];
            }
        }

        REG_BG0HOFS = hoff;
        REG_BG0VOFS = voff;
    }

    return 0;
}


