#include<lpc21xx.h>
#include"can_fun.h"
#include"LCD_functions.h"
#define M1 1<<3
#define M2 1<<4
char flag=0;
int main()
{
	data m1;
	can_init();
	LCD_INIT();
	IODIR0=M1|M2;
	IOSET0=M1|M2;
	//LCD_STR("NODE CAN RECEIVE");
	while(1)
	{
		can_rx(&m1);
		if(m1.id==3)
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
		IOCLR0=M1;
		IOSET0=M2;
		if((C2GSR&1)==1)
		{
			IOSET0=M1|M2;
			break;
		}
		}
// 		else
// 		{
// 		LCD_COMMAND(0XC0);
// 		LCD_STR("LEFT LED OFF");
// 		}
	}	
}
