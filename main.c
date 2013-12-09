#include <msp430.h> 
#include "robotLibrary/robotLibrary.h"
#include "SensorLibrary/SensorLibrary.h"
#include "clock/clock.h"
#define FALSE 0
#define TRUE 1
/*
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initRobot();
	P1DIR |= (BIT0 | BIT6);
	setFrequency(SPEED_1MHZ);

	for (;;) {
		moveForward(15, 10);
		if (isRightClose() == FALSE) {
			stop();
			halfLeft();
			P1OUT |= BIT0;
		} else {
			P1OUT &= ~BIT0;
		}

		if (isCenterClose() == FALSE) {
			stop();
			halfLeft();
			P1OUT |= BIT6;
		} else {
			P1OUT &= ~BIT6;
		}
	}
	return 0;
}

