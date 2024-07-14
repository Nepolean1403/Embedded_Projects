#include<lpc21xx.h>

int pen_cost,book_cost,total;
char flag,mode=0;
void remove_mode_isr(void) __irq
{ 
	
	delay_milliseconds(300);
	EXTINT=0X01;
	LCD_COMMAND(0X01);
	if(mode==0)
	{
		flag=1;
		mode=1;
		LCD_STR("REMOVE MODE");
	}
	else
	{
		flag=0;
		mode=0;
		LCD_COMMAND(0X01);
		LCD_STR("  REMOVE MODE      CANCEL");
	}
  VICVectAddr=0;
}
void total_isr(void) __irq
{
	EXTINT=0X02;
	total=pen_cost+book_cost;
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X80);
	LCD_STR("TOTAL AMT:");
	LCD_COMMAND(0X8A);
	LCD_INTEGER(total);
	delay_seconds(2);
	LCD_COMMAND(0X01);
	LCD_STR("THANK YOU VISIT    AGAIN...");
	VICVectAddr=0;
}
void INTR_CONFIG(void)
{
	PINSEL0|=0x20000000;
	PINSEL1|=0X01;
	VICIntSelect=0;
	VICVectCntl0=(0x20)|14;
	VICVectAddr0=(int)remove_mode_isr;
	VICVectCntl1=(0x20)|15;
	VICVectAddr1=(int)total_isr;
	EXTMODE=0X03;
	EXTPOLAR=0X00;
	VICIntEnable=(1<<14)|(1<<15);
}



