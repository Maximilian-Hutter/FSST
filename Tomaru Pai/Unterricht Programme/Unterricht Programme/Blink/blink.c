// Blink with lgpio
// build: gcc blink.c -o blink -Wall -llgpio

#include <stdio.h>
#include <lgpio.h>

#define OUT 18      // 18 = LED1, 23 = LED2, 24 = LED3, 25 = LED4
#define TSLEEP 0.5 // seconds

int main(int argc, char *argv[])
{
    int h;
    int lFlags = 0; /* default line flags */

    h = lgGpiochipOpen(0); /* get a handle to the GPIO */
    lgGpioClaimOutput(h, lFlags, OUT, 0); /* initial level 0 */

    while (1)
    {
        lgGpioWrite(h, OUT, 1);
        lguSleep(TSLEEP); /* sleep for 0.1 seconds */
        lgGpioWrite(h, OUT, 0);
        lguSleep(TSLEEP); /* sleep for 0.1 seconds */
    }
}
