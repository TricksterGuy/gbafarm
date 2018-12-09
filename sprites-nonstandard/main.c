#include "myLib.h"
#include <stdio.h>
#include <stdlib.h>
#include "sprites.h"

OamEntry shadow[128];

// Copy a tile from data into the sprite graphics memory.
// data = pointer to tiled data.
// tile_id = tile offset to copy data to.
// sx, sy = location of the tile to copy in the data in tile coordinates.
// pitch = width of the original sprite in tiles.
// This assumes 8 bpp tiles.
void copyTile(const u16* data, int tile_id, int sx, int sy, int pitch)
{
    for (int i = 0; i < 32; i++)
    {
        SPRITEDATA[tile_id * 32 + i] = data[(sy * pitch + sx) * 32 + i];
    }  
}

int main(void)
{
    DMA[3].src = sprites_palette;
    DMA[3].dst = SPRITEPAL;
    DMA[3].cnt = SPRITES_PALETTE_LENGTH | DMA_ON;

    //DMA[3].src = sprites;
    //DMA[3].dst = SPRITEDATA;
    //DMA[3].cnt = SPRITES_LENGTH | DMA_ON;

    // This was a 48x64 image so we need 3 sprites
    // The layout in memory for the tile data is as follows:
    // 111122
    // 111122
    // 111122
    // 111122
    // 111133
    // 111133
    // 111133
    // 111133
    
    // This data is stored row by row however since we have 1D sprite mapping we must
    // Shuffle this such that 1's tiles are all sequentially in memory then 2's tiles then 3's
    // This code does that shuffling.
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 4; j++)
            copyTile(sprites, i * 4 + j, j, i, 6);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 2; j++)
            copyTile(sprites, i * 2 + j + 32, j + 4, i, 6);

    REG_DISPCTL = MODE0 | OBJ_ENABLE | SPRITES_DIMENSION_TYPE;

    for(int i = 0; i < 128; i++)
        shadow[i].attr0 = ATTR0_HIDE;

    // 4x8 sprite.
    OamEntry* part1 = shadow;
    part1->attr0 = 32 | SPRITES_PALETTE_TYPE | (2 << 14);
    part1->attr1 = 64 | (3 << 14);
    part1->attr2 = 0 | 0;

    // 2 2x4 sprites.
    OamEntry* part2 = shadow + 1;
    part2->attr0 = 32 | SPRITES_PALETTE_TYPE | (2 << 14);
    part2->attr1 = 96 | (2 << 14);
    part2->attr2 = 0 | 64;

    OamEntry* part3 = shadow + 2;
    part3->attr0 = 64 | SPRITES_PALETTE_TYPE | (2 << 14);
    part3->attr1 = 96 | (2 << 14);
    part3->attr2 = 0 | 80;


    while(1)
    {
        waitForVblank();
		DMA[3].src = shadow;
		DMA[3].dst = SPRITEMEM;
		DMA[3].cnt = 128 * 4 | DMA_ON;
    }

    return 0;
}

