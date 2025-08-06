#include <LPC214X.H>
#include "ADC.H"
#include "string.h"
#include "LCD.h"
#include "UART.h"
#include "pll.h"
void forward();
void backWard();
void left();
void right();
void stop();
void stepper();
int main()
{
	int Forward=0;
	int Backward=0;
	int Left=0;
	int Right=0;
	int Stop=0;
	initLCD();
  initUART();
	InitPLL();
	IO0DIR|=0xffff;
	while(1)
	{
		stepper();
		transmit(ADCRead());
	}
}

void Delay(void)
{
int s;
for(s=0;s<=100000;s++)
{};

}
void stepper()
{
	IO0SET=1<<12;
	Delay();
	IO0CLR=1<<12;
	IO0SET=1<<13;
	Delay();
	IO0CLR=1<<13;
	IO0SET=1<<11;
	Delay();
	IO0CLR=1<<11;
	IO0SET=1<<13;
	Delay();
	IO0CLR=1<<13;
}