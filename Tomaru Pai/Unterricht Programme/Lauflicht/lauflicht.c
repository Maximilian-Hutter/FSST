// Blink with lgpio
// build: gcc lauflicht.c -o lauflicht -Wall -llgpio
// Thomas Pail

#include <stdio.h>
#include <lgpio.h>

#define TSLEEP 0.25 // seconds

int main(int argc, char *argv[])
{
    int h;
    int lFlags = 0; /* default line flags */
    
    int LEDS[] = {18, 23, 24, 25};   // 18 = LED1, 23 = LED2, 24 = LED3, 25 = LED4

    h = lgGpiochipOpen(0); /* get a handle to the GPIO */
    
    for (int i = 0; i < 4; i++)	
		lgGpioClaimOutput(h, lFlags, LEDS[i], 0); /* initial level 0 */

    while (1)
    {
		for (int i = 0; i < 4; i++)	{
			lgGpioWrite(h, LEDS[i], 1);
			lguSleep(TSLEEP);
			lgGpioWrite(h, LEDS[i], 0);
		}
    }
}
