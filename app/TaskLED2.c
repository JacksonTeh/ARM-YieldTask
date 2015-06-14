#include "LED.h"
#include "Time.h"
#include "Button.h"

extern uint32_t counter;
extern uint32_t currentTime;

void taskLED2(TaskBlock *tb)
{
	static uint32_t previousTime = 0;

	startTask(tb);
	while(1)
	{
		turnOnLED(PORTG, LED3);
		while(!isTimerExpire(FIVE_HUND_MILISEC, &previousTime))
		{
			yields(tb);
		}
		turnOffLED(PORTG, LED3);
		while(!isTimerExpire(FIVE_HUND_MILISEC, &previousTime))
		{
			yields(tb);
		}
	}
	endTask(tb);
}