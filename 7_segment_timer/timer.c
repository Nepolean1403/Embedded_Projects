#include<lpc21xx.h>
#include"timer_delay.h"
#define SEG_D 0xff<<0
#define SEG1 1<<8
#define SEG2 1<<9
#define SEG3 1<<10
#define SEG4 1<<11

void four_digit_display(int,int);
unsigned int SEG_LUT[]={
 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90
                       };
unsigned char dp2=0x80;
char m=0,s=0;
int main()
{
	
	IODIR0=SEG_D|SEG1|SEG2|SEG3|SEG4;
	while(1)
	{
		four_digit_display(m,s++);
		if(s>59)
		{
		s=0;
		m++;
		if(m>59)
		m=0;
		}
	}
}
void four_digit_display(int m,int s)
 {
 	char k;
	for(k=0;k<50;k++)
	{
	IOCLR0=SEG_D;
   	IOSET0=SEG_LUT[m/10];
   	IOCLR0=SEG1;
   	delay_milliseconds(5);
   	IOSET0=SEG1;

	IOCLR0=SEG_D;
   	IOSET0=SEG_LUT[m%10]^dp2;
   	IOCLR0=SEG2;
   	delay_milliseconds(5);
	IOSET0=SEG2;
			
	IOCLR0=SEG_D;
   	IOSET0=SEG_LUT[s/10];
   	IOCLR0=SEG3;										  
   	delay_milliseconds(5);
   	IOSET0=SEG3;
   
   	IOCLR0=SEG_D;
   	IOSET0=SEG_LUT[s%10];
   	IOCLR0=SEG4;
   	delay_milliseconds(5);
   	IOSET0=SEG4;
	}
	}
 
