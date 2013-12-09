#include <msp430.h> 
#include "robotLibrary/robotLibrary.h"
#include "SensorLibrary/SensorLibrary.h"
#include "clock/clock.h"
/*
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initRobot();
	setFrequency(SPEED_50KHZ);

	for (;;) {
		moveForward(35, 30);
		if (isRightClose()) {
			halfLeft();
		}
		if (isCenterClose()) {
			halfLeft();
		}
	}
	return 0;
}

