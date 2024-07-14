#include<string.h>
#define LCD 0x0f<<20
#define RS 1<<17
#define RW 1<<18
#define E 1<<19

void LCD_COMMAND(unsigned char);
void LCD_INTEGER(int);
void LCD_ROTATE(char*);

void LCD_INIT(void)
{
	IODIR1=LCD|RS|E|RW;
	IOCLR1=RW;
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X02);
	LCD_COMMAND(0X0C);
	LCD_COMMAND(0X28);
	LCD_COMMAND(0X80);
}
void LCD_COMMAND(unsigned char cmd)
{
	IOCLR1=LCD;
	IOSET1=(cmd & 0Xf0)<<16;
	IOCLR1=RS;
	IOSET1=E;
	delay_milliseconds(2);
	IOCLR1=E;
	
	IOCLR1=LCD;
	IOSET1=(cmd & 0X0f)<<20;
	IOCLR1=RS;
	IOSET1=E;
	delay_milliseconds(2);
	IOCLR1=E;
}
void LCD_DATA(unsigned char d)
{	IOCLR1=LCD;
	IOSET1=(d & 0Xf0)<<16;
	IOSET1=RS;
	IOSET1=E;
	delay_milliseconds(2);
	IOCLR1=E;
	
	IOCLR1=LCD;
	IOSET1=(d & 0X0f)<<20;
	IOSET1=RS;
	IOSET1=E;
	delay_milliseconds(2);
	IOCLR1=E;
	}
void LCD_STR(char *s)
{
	unsigned char p=0;
	while(*s)
	{
		LCD_DATA(*s++);
		p++;
	 if(p==16)
	  LCD_COMMAND(0XC0);
	}
}
void LCD_FLOAT(float f)
{
	int temp=f;
	LCD_INTEGER(temp);
	LCD_DATA('.');
	temp=(f-temp)*100;
	LCD_INTEGER(temp);
}
void LCD_INTEGER(int n)
{
	unsigned char a[10];
	signed char i=0;
	if(n==0)
		LCD_DATA('0');
	else
	{
		if(n<0)
		{
			LCD_DATA('-');
			n=-n;
		}
		while(n>0)
		{
			a[i++]=n%10;
			n/=10;
		}
		for(--i;i>=0;i--)
		LCD_DATA(a[i]+48);
	}
}

void LCD_ROTATE(char *s)
{
	int l,i=0,j;
	l=strlen(s);
	j=l+1;
	while(1)
	{
		LCD_COMMAND(0X80+i);
		LCD_STR(s);
		delay_milliseconds(500);
		LCD_COMMAND(0X01);
		i++;
		if(i >=16-l)
		{
			LCD_COMMAND(0X80);
			LCD_STR(&s[l--]);
			j--;
		}
		if(j==0)
		{
			i=0;
			l=strlen(s);
			j=l+1;
		}	
	}
}

