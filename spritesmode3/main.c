#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "background.h"
#include "dog.h"

OamEntry shadow[128];

int main(void)
{
    REG_DISPCTL = MODE3 | BG2_ENABLE | OBJ_ENABLE | DOG_DIMENSION_TYPE;

    DMA[3].src = dog_palette;
    DMA[3].dst = SPRITEPAL;
    DMA[3].cnt = DOG_PALETTE_LENGTH | DMA_ON;

    DMA[3].src = dog;
    DMA[3].dst = &CHARBLOCKBASE[5];
    DMA[3].cnt = DOG_LENGTH | DMA_ON;

    for(int i = 0; i < 128; i++)
        shadow[i].attr0 = ATTR0_HIDE;

    int delay = 0;
    int frame_delay = 5;
    int frame = 0;

    for (unsigned int i = 0; i < BACKGROUND_LENGTH; i++)
        videoBuffer[i] = background[i];

    OamEntry* dog = shadow;
	dog->attr0 = 48 | DOG_PALETTE_TYPE | DOG_SPRITE_SHAPE;
	dog->attr1 = 88 | DOG_SPRITE_SIZE;
	// Bug, well not for this image, but if the frames get matched to separate palettes this could be a problem.
	// Currently we don't have an array of palette_ids here.
	dog->attr2 = DOG0_PALETTE_ID | dog_frames[0];

    while(1)
    {
        waitForVblank();
        if (delay > frame_delay)
        {
            delay = 0;
            frame = (frame + 1) % DOG_FRAMES;
        }

        int frame_ptr = dog_frames[frame];
		dog->attr2 = DOG0_PALETTE_ID | frame_ptr;

        if (KEY_DOWN_NOW(BUTTON_UP)) frame_delay = max(frame_delay - 1, 1);
        if (KEY_DOWN_NOW(BUTTON_DOWN)) frame_delay = min(frame_delay + 1, 60);
        delay++;
		DMA[3].src = shadow;
		DMA[3].dst = SPRITEMEM;
		DMA[3].cnt = 128 * 4 | DMA_ON;
    }

    return 0;
}

