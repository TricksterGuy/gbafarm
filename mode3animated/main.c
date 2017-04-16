#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "dog.h"

int main(void)
{
    REG_DISPCTL = MODE3 | BG2_ENABLE;

    int delay = 0;
    int frame_delay = 5;
    int frame = 0;

    for (unsigned int i = 0; i < 38400; i++)
        videoBuffer[i] = 0x7FFF;

    while(1)
    {
        waitForVblank();
        if (delay > frame_delay)
        {
            delay = 0;
            frame = (frame + 1) % DOG_FRAMES;
        }
        
        cu16* frame_ptr = dog_frames[frame];

        cu32 startx = (240 - DOG_WIDTH) / 2;
        cu32 starty = (160 - DOG_HEIGHT) / 2;
        for (int y = 0; y < DOG_HEIGHT; y++)
        {
            for (int x = 0; x < DOG_WIDTH; x++)
            {
                videoBuffer[(starty+y) * 240 + startx + x] = frame_ptr[y * DOG_WIDTH + x];
            }
        }

        if (KEY_DOWN_NOW(BUTTON_UP)) frame_delay = max(frame_delay - 1, 1);
        if (KEY_DOWN_NOW(BUTTON_DOWN)) frame_delay = min(frame_delay + 1, 60);
        delay++;
    }

    return 0;
}

