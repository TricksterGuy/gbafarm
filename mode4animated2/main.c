#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "animation.h"

int main(void)
{
    REG_DISPCTL = MODE4 | BG2_ENABLE;

    int frame_delay = 5;
    int delay = frame_delay;
    int frame = ANIMATION_FRAMES - 1;

    while(1)
    {
        waitForVblank();

        if (delay > frame_delay)
        {

            delay = 0;
            frame = (frame + 1) % ANIMATION_FRAMES;
        }
        else
        {
            delay++;
            continue;
        }

        cu16* frame_ptr = animation_frames[frame];
        cu16* pal_ptr = animation_palette_frames[frame];


        DMA[3].src = frame_ptr;
        DMA[3].dst = videoBuffer;
        DMA[3].cnt = ANIMATION_LENGTH | DMA_ON;

        DMA[3].src = pal_ptr;
        DMA[3].dst = PALETTE;
        DMA[3].cnt = 256 | DMA_ON;

        if (KEY_DOWN_NOW(BUTTON_UP)) frame_delay = max(frame_delay - 1, 1);
        if (KEY_DOWN_NOW(BUTTON_DOWN)) frame_delay = min(frame_delay + 1, 60);
        flipPage();
        delay++;
    }

    return 0;
}

