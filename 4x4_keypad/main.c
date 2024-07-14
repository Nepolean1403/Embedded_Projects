#include<lpc21xx.h>
#include"LCD_functions.h"
#include"keypad_fun.h"
int main()
{
	int num=0;
	LCD_INIT();
	LCD_STR("PRESS KEY");
	while(1)
	{
		LCD_COMMAND(0XC0);
		num=key_scan();
		LCD_INTEGER(num);
	}
}
