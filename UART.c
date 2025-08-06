#include "UART.h"
#include "LCD.h"
#include "string.h"
#include "ADC.h"
void UARTISR() __irq
{
	int result=U0RBR;
	switch(result)
	{
		case 1:
		{
				IO0SET|=1<<2|1<<4;
		    IO0CLR|=1<<3|1<<5|1<<6;
			break;
		}
		case 2:
		{
			IO0SET|=1<<3|1<<5;
			IO0CLR|=1<<2|1<<4|1<<6;
			break;
		}
		case 3:
		{
			IO0SET|=1<<2;
			IO0CLR|=1<<4|1<<5|1<<3|1<<6;
			break;
		}
		case 4:
		{
			IO0SET|=1<<4;
			IO0CLR|=1<<2|1<<3|1<<5|1<<6;
			break;
		}
		case 5:
		{
				IO0CLR|=0x1f;
			  IO0SET|=1<<6;
			break;
		}
	}
}
void EnableInterrupt()
{
	VICIntEnable =(1<<6);
	VICVectCntl0=(1<<5)|6;
	VICVectAddr0=(unsigned int)UARTISR;
}
void initUART()
{
	initADC();
	PINSEL0=(1<<2)|1;
	U0FCR=1;
	U0LCR=3|(1<<3)|(1<<7);
	U0DLL=130;
	U0FDR=0X10;
	U0LCR&=~(1<<7);
	U0IER=1;
	U0TER=(1<<7);
	EnableInterrupt();
}
void transmit(char result)
{
	while((U0LSR&(1<<5))==0);
	U0THR=result;
}