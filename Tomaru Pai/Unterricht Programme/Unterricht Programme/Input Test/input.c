// Input Testprogramm

/* Copmile:
 * >>	gcc input.c -o input -llgpio -Wall
 * >>	./input 
 */

#include <stdio.h>
#include <inttypes.h>

#include <lgpio.h>

#define CHIP 0
#define GPIO 22

int counter = 0;

// Interrupt Service Routine
void afunc(int e, lgGpioAlert_p evt, void *data)
{
   // int i;
   // int userdata = *(int*)data;
   counter++;
   printf("counter value = %d\n", counter);

/*
   for (i=0; i<e; i++)
   {
      printf("u=%d t=%"PRIu64" c=%d g=%d l=%d f=%d (%d of %d)\n",
         userdata, evt[i].report.timestamp, evt[i].report.chip,
         evt[i].report.gpio, evt[i].report.level,
         evt[i].report.flags, i+1, e);
   }
*/
}

int main(int argc, char *argv[])
{
	int h;
	int e;
	static int userdata=0;
	
	h = lgGpiochipOpen(0);

	if (h < 0) { 
	   printf("ERROR: %s (%d)\n", lguErrorText(h), h); 
	   return 1; 
	}

	lgGpioSetAlertsFunc(h, GPIO, afunc, &userdata);
	// Interupts Eingeschaltet
	e = lgGpioClaimAlert(h, 0, LG_FALLING_EDGE, GPIO, -1);

	if (e < 0) { 
	   printf("ERROR: %s (%d)\n", lguErrorText(e), e); 
	   return 1; 
	}

	lguSleep(10);

	lgGpiochipClose(h);
}
