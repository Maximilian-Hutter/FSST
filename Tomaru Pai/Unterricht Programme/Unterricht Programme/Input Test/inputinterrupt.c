// Input Testprogramm
// mit Interrupts (Polling)

/* Copmile:
 * >>	gcc inputinterrupt.c -o inputinterrupt -llgpio -Wall
 * >>	./input 
 * 
 * >>   htop // Taskmanager
 * >>	mit "f3" kann man Programm finden
 */

#include <stdio.h>
#include <inttypes.h>
#include <lgpio.h>
#include <signal.h>

#include <lgpio.h>

#define CHIP 0
#define GPIO 22
#define FLAG 0

int h;
int running = 1; 
// Aufruf bei Signal "Strg-C"
void handler(int sig)
{
	printf("\nChip closed!\n");
	lgGpiochipClose(h);
	running = 0;
}

int main(int argc, char *argv[])
{
	int e;
	
	// Verbindung Signal (Strg-C) mit funktion handler
	signal(SIGINT, handler);
	signal(SIGTERM, handler); // Das selbe mit Kill
	
	h = lgGpiochipOpen(CHIP);

	if (h < 0) { 
	   printf("ERROR: %s (%d)\n", lguErrorText(h), h); 
	   return 1; 
	}

	e = lgGpioClaimInput(h, FLAG, GPIO);	// GPIO auf Eingang 

	if (e < 0) { 
	   printf("ERROR: %s (%d)\n", lguErrorText(e), e); 
	   return 1; 
	}
	
	int state = 1;
	int oldstate = 0;
	while (running) {
	   state = lgGpioRead(h, GPIO);
	   if (state != oldstate) {
		printf("Status: %d\n", state);
		oldstate = state; 
	   }
	   lguSleep(0.01);
	}
	return 0;
}
