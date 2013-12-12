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
	modTimer(70, 40);
	moveForward();
	P1DIR |= (BIT0 | BIT6);
	for (;;) {

		if (isRightClose() == FALSE) {
			P1OUT &= ~BIT0;
			P1OUT |= BIT6;
			halfLeft();
			__delay_cycles(100000);
		} else if (isCenterClose() == FALSE) {
			halfLeft();;
			P1OUT &= ~BIT6;
			P1OUT |= BIT0;
		} else {
			P1OUT &= ~BIT0;
			P1OUT &= ~BIT6;
			moveForward();
		}

	}
	return 0;
}

