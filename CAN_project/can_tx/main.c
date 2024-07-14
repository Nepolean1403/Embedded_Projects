#include<lpc21xx.h>
#include"can_fun.h"
#include"LCD_functions.h"
#define SW1 14
#define SW2 15
#define SW3 16
unsigned char c=0,c1=0,c2=0;
int main()
{
	data m1;
	can_init();
	LCD_INIT();
	m1.rtr=0;
	m1.dlc=2;
	m1.byteA=0;
	m1.byteB=0;
	LCD_STR("  BODY CONTROL  MDLE IN VEHICLE");
	while(1)
	{	
		if(((IOPIN0>>SW1)&1)==0)
		{
			if(c==0)
			{
			LCD_COMMAND(0X01);
			LCD_COMMAND(0X80);
			delay_milliseconds(2);
			LCD_STR("LEFT INDICATOR      ON");
			c=1;
			}
			else
			{
			LCD_COMMAND(0X01);
			LCD_COMMAND(0X80);
			delay_milliseconds(2);
			LCD_STR("LEFT INDICATOR      OFF");
			c=0;
			}
			m1.id=1;
			can_tx(m1);
			while(((IOPIN0>>SW1)&1)==0);
			}
		
		if(((IOPIN0>>SW2)&1)==0)
		 {
			if(c1==0)
			{
			LCD_COMMAND(0X01);
			LCD_COMMAND(0X80);
			delay_milliseconds(2);
			LCD_STR("RIGHT INDICATOR      ON");
			c1=1;
			}
			else
			{
			LCD_COMMAND(0X01);
			LCD_COMMAND(0X80);
			delay_milliseconds(2);
			LCD_STR("RIGHT INDICATOR      OFF");
			c1=0;
			}
			m1.id=2;
			can_tx(m1);
			while(((IOPIN0>>SW2)&1)==0);
		}
		if(((IOPIN0>>SW3)&1)==0)
		{
			if(c2==0)
			{
			LCD_COMMAND(0X01);
			LCD_COMMAND(0X80);
			delay_milliseconds(2);
			LCD_STR("VIBER ON");
			c2=1;
			}
			else
			{
			LCD_COMMAND(0X01);
			LCD_COMMAND(0X80);
			delay_milliseconds(2);
			LCD_STR("VIBER OFF");
			c2=0;
			}
			m1.id=3;
			can_tx(m1);
			while(((IOPIN0>>SW3)&1)==0);
		}
	}		
}4
