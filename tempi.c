#include <wiringPi.h>
#include <stdio.h>

#define OUT
#define GND
#define VCC

int main()
{
	if(wiringPiSetup()) return 1;
}
