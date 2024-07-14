#include<lpc21xx.h>
#define LED 1<<17

void FIQint(void) __irq
{
	EXTINT=0X01;
	IOCLR0=LED;
	IOSET0=LED;
}
int main()
{
	int c=0;
	IODIR0=LED;
	
	PINSEL1=0X01;
	
	VICIntSelect=1<<14;
	VICIntEnable=1<<14;
	
	while(1)
	c++;
}
