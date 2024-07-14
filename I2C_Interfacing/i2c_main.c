#include<lpc21xx.h>
#include"types.h"
#include"define.h"
#include"i2c_fun.h"
#include"i2c_eeprom.h"
#include"LCD_functions.h"
#define led1 1<<17
#define led2 1<<18
int main()
{
	u8 ch;
	i2c_init();
	LCD_INIT();
	IODIR0=led1|led2;
  IOSET0=led1|led2;
	i2c_eeprom_write(0x50,0x00,'A');
	ch=i2c_eeprom_read(0x50,0x00);
	
	if(ch=='A')
	{
	//	LCD_COMMAND(0X01);
		LCD_DATA(ch);
		IOCLR0=led1;
	}
	else
	{
		LCD_COMMAND(0X01);
		LCD_STR("NOT MATCH");
	}
}
