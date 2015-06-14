#include "LED.h"
#include "Time.h"
#include "Button.h"

extern uint32_t counter;
extern uint32_t currentTime;

void taskRunningLED(TaskBlock *tb)
{
	static uint32_t previousTime = 0;

	startTask(tb);
	while(1)
	{
		if(readUserButton())
		{
			turnOnLED(PORTB, LED5);
			while(!isTimerExpire(FIVE_HUND_MILISEC, &previousTime))
			{
				yields(tb);
			}
			turnOffLED(PORTB, LED5);
			while(!isTimerExpire(FIVE_HUND_MILISEC, &previousTime))
			{
				yields(tb);
			}
		}
		yields(tb);
	}
	endTask(tb);
}
