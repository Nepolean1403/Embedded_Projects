#include<lpc21xx.h>
#include"types.h"
#include"spi_fun.h"
#include"mp3204.h"
#include"LCD_functions.h"
int main()
{	
	f32	f;
	spi_init();
	LCD_INIT();
	LCD_STR("MCP3204:");

	IOPIN0|=1<<7;
	while(1)
	{
		f=read_adc_value(0);
		LCD_COMMAND(0XC0);
		LCD_FLOAT(f);
	}

}
