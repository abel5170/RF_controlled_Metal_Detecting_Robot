#include "ADC.h"
void initADC(void)
{
	PINSEL1|=(1<<22);
  AD0CR=(0X15<<8)|1|(1<<21);
	VPBDIV=1;
}
int ADCRead(void)
{
	AD0CR|=(1<<24);
	while(1)
	{
		
		int done=AD0GDR>>31;
		if(done==1)
		{
			break;
		}
	}
	return (AD0GDR>>6)&0x3ff;
}