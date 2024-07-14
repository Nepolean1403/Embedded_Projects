#include<lpc21xx.h>
#include<string.h>
#include<stdlib.h>
#include"delay.h"
#include"LCD_functions.h"
#include"uart0_fun.h"
#include"interrupt.h"
#define SW1 14
#define SW2 16
char id[9];
char def_id1[]="03108458";
char def_id2[]="00307572";
char i,j,flag=0,pen_count=0,book_count=0;
int pen_cost=0,book_cost=0;
int main()
{
	LCD_INIT();
	UART0_INIT();
	INTR_CONFIG();
	LCD_STR("SMART TROLLY     USING RFID");
	delay_seconds(1);
	LCD_COMMAND(0X01);
	LCD_STR("WELCOME TO STORE");
	while(1)
	{
	for(i=0,j=0;i<9;i++)
	{
		if(j==0)
		{
			UART0_RX();
			j++;
		}
		id[i]=UART0_RX();
	}
	
	id[--i]='\0';
	LCD_COMMAND(0X01);
 // LCD_STR(id);
  
	if(strcmp(id,def_id1)!=0)
	{
		if(flag==1)
			pen_count--;
		else
			pen_count++;
		pen_cost=pen_count*10;
		LCD_COMMAND(0X80);
		LCD_STR("PEN");
		LCD_COMMAND(0XC0);
		LCD_STR("RS:");
		LCD_COMMAND(0XC3);
		LCD_INTEGER(10);
		LCD_COMMAND(0X85);
		LCD_STR("COUNT");
		LCD_COMMAND(0XC6);
		LCD_INTEGER(pen_count);
		LCD_COMMAND(0X8b);
		LCD_STR("TOTAL");
		LCD_COMMAND(0XCb);
		LCD_INTEGER(pen_cost);
	}
		if(strcmp(id,def_id2)!=0)
		{
			if(flag==1)
			book_count--;
		else
			book_count++;
		book_cost=book_count*20;
		LCD_COMMAND(0X80);
		LCD_STR("BOOK");
		LCD_COMMAND(0XC0);
		LCD_STR("RS:");
		LCD_COMMAND(0XC3);
		LCD_INTEGER(20);
		LCD_COMMAND(0X85);
		LCD_STR("COUNT");
		LCD_COMMAND(0XC6);
		LCD_INTEGER(book_count);
		LCD_COMMAND(0X8b);
		LCD_STR("TOTAL");
		LCD_COMMAND(0XCb);
		LCD_INTEGER(book_cost);
		}		
	}
}


