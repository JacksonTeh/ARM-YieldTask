#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "Time.h"
#include "LED.h"
#include "Button.h"
#include "State.h"

int main(void)
{
	TaskBlock tb1;
	TaskBlock tb2;
	initUserButton();
	CLK_EN();
	configureLED(LED3, PORTG);
	configureLED(LED4, PORTG);
	configureLED(LED5, PORTB);
	configureLED(LED6, PORTC);

	initTaskBlock(&tb1);
	initTaskBlock(&tb2);

    while(1)
    {
    	updateTime();
    	//testingSwitchCase(&tb);
    	taskLED1(&tb1);
    	taskLED3(&tb2);
    }
}
