#include "myLib.h"

double timefactors[] = {0.059604, 3.811, 15.259, 59.382};

u16 *videoBuffer = BUFFER0;

void waitForVblank(void)
{
	while(SCANLINECOUNTER >= 160);
	while(SCANLINECOUNTER < 160);
}

void flipPage(void)
{
	if(REG_DISPCTL & BUFFERFLAG)
	{
		REG_DISPCTL &= ~BUFFERFLAG;
		videoBuffer = BUFFER1;
	}
	else
	{
		REG_DISPCTL |= BUFFERFLAG;
		videoBuffer = BUFFER0;
	}
}
