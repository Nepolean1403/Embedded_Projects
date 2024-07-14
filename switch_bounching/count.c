#include<lpc21xx.h>
#include"lcd_functions.h"
#define SW 14
int main()
{
	int c=0;
	LCD_INIT();
	LCD_STR("SWITCH COUNT");
	while(1)
	{
		if(((IOPIN0>>SW)&1)==0)
	  {
		delay_milliseconds(400);
		c++;
		LCD_COMMAND(0XC0);
		LCD_INTEGER(c);
		while(((IOPIN0>>SW)&1)==0);
		}
		
	}
}
