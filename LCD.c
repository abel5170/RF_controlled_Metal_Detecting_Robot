#include "LCD.h"
int command[]= {0X38,0XE,0x6,0X80};
void initLCD(void)
{
	IO1DIR=0Xffffffff;
	for (int i=0;i<4;i++)
	{
		LCDWriteCommand(command[i]);
		delay(10000);
	}
}
 void LCDWriteCommand(int data)
 {
	 IO1CLR=(1<<25);
	 IO1PIN=(IO1PIN&0Xff00ffff)|(data<<16);
	 IO1SET=(1<<24);
	 delay(12000);
	 IO1CLR=(1<<24);
 }
 void LCDWriteData(char *msg)
 {
	 int i=0;
	 while(msg[i]!=0)
	 {
	  IO1SET=(1<<25);
		IO1PIN=(IO1PIN&0Xff00ffff)|(msg[i]<<16);
	  IO1SET=(1<<24);
	  delay(12000);
		 i++;
	 IO1CLR=(1<<24);
	 }

 }
 void delay(int ms)
 {
	 for(int i=0;i<ms;i++);
 }