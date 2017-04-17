#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "dog.h"

int main(void)
{
    REG_DISPCTL = MODE4 | BG2_ENABLE;

    for (u32 i = 0; i < DOG_PALETTE_LENGTH; i++)
        PALETTE[i] = dog_palette[i];

    int delay = 0;
    int frame_delay = 5;
    int frame = 0;

    while(1)
    {
        waitForVblank();
        flipPage()
        ;
        if (delay > frame_delay)
        {
            delay = 0;
            frame = (frame + 1) % DOG_FRAMES;
        }

        cu16* frame_ptr = dog_frames[frame];

        for (u32 i = 0; i < DOG_HEIGHT; i++)
        {
            for (u32 j = 0; j < DOG_WIDTH / 2; j++)
            {
                videoBuffer[i * 120 + j] = frame_ptr[i * DOG_WIDTH / 2 + j];
            }
        }

        if (KEY_DOWN_NOW(BUTTON_UP)) frame_delay = max(frame_delay - 1, 1);
        if (KEY_DOWN_NOW(BUTTON_DOWN)) frame_delay = min(frame_delay + 1, 60);
        delay++;
    }

    return 0;
}

