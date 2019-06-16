#include <wiringPi.h>
#include <stdio.h>

#define OUT
#define INTERCHANGE_FILE

int main()
{
	if(wiringPiSetup()) return 1;
	pinMode(OUT, INPUT);
	char data[9];
	int i = 0;
	while(1)
	{
		for(i = 0; i < 9; i++)
		{
			data[i] = 0;
			data[i] |= digitalRead(OUT) ? 1 : 0;
			delay(10);
			data[i] |= digitalRead(OUT) ? 2 : 0;
			delay(10);
			data[i] |= digitalRead(OUT) ? 4 : 0;
			delay(10);
			data[i] |= digitalRead(OUT) ? 8 : 0;
			delay(10);
			data[i] |= digitalRead(OUT) ? 16 : 0;
			delay(10);
			data[i] |= digitalRead(OUT) ? 32 : 0;
			delay(10);
			data[i] |= digitalRead(OUT) ? 64 : 0;
			delay(10);
			data[i] |= digitalRead(OUT) ? 128 : 0;
			delay(10);
		}
		FILE *f = fopen(INTERCHANGE_FILE, "w");
		fwrite(data, 1, 9, f);
		fclose(f);
	}
}
