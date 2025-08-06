#include "string.h"
char Tarray[]={43,0,0,46,0,0xdf,0x43,0};
char PHarray[]={0,0};
char *formTarray(float value)
{
	value=value*10;
	if(value<0)
	{
		value*=-1;
		Tarray[0]=45;
}
		
	 Tarray[1]=(value/100);
   Tarray[2]=((value-(Tarray[1]*100))/10);
	Tarray[4]=(value-(Tarray[1]*100+Tarray[2]*10));
	
	Tarray[1]+=48;
	Tarray[2]+=48;
	Tarray[4]+=48;
	return  Tarray;
}
char *formArrayph(float value)
{
	value=round(value)*10;
	PHarray[0]=(value/100);
  PHarray[1]=((value-(PHarray[0]*100))/10);
	PHarray[0]+=48;
	PHarray[1]+=48;
	return  PHarray;
}