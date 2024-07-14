#include<lpc21xx.h>
#include"can_fun.h"
#include"LCD_functions.h"
#define LED 1<<17
char flag=0,c=0;
int main()
{
	data m1;
	can_init();
	LCD_INIT();
	IODIR0=LED;
	IOSET0=LED;
	//LCD_STR("NODE CAN RECEIVE");
	while(1)
	{
		can_rx(&m1);
		if(m1.id==1)
		{
		if(flag==0)
			flag=1;
		else
			flag=0;
	  }
		while(flag==1)
		{
// 		LCD_COMMAND(0XC0);
// 		LCD_STR("LEFT LED ON");
		IOCLR0=LED;
		delay_ms(500);
		IOSET0=LED;
		delay_ms(500);
			if((C2GSR&1)==1)
			break;
		}
// 		else
// 		{
// 		LCD_COMMAND(0XC0);
// 		LCD_STR("LEFT LED OFF");
// 		}
	}	
}
