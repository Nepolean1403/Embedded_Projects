#include<lpc21xx.h>
#define C0 (IOPIN0 & (1<<4))
#define C1 (IOPIN0 & (1<<5))
#define C2 (IOPIN0 & (1<<6))
#define C3 (IOPIN0 & (1<<7))

#define R0 1<<8
#define R1 1<<9
#define R2 1<<10
#define R3 1<<11

int keypad_lut[4][4]={
{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}
                     };
int key_scan(void)
{
	char row_val,col_val;
	IODIR0|=R0|R1|R2|R3;
	while(1)
	{
	IOCLR0=R0|R1|R2|R3;
	IOSET0=C0|C1|C2|C3;
	
	while((C0&&C1&&C2&&C3)==1);
	
	IOCLR0=R0;
	IOSET0=R1|R2|R3;
	if((C0&&C1&&C2&&C3)==0)
	{
		row_val=0;
		break;
	}
	IOCLR0=R1;
	IOSET0=R0|R2|R3;
	if((C0&&C1&&C2&&C3)==0)
	{
		row_val=1;
		break;
	}
	IOCLR0=R2;
	IOSET0=R1|R0|R3;
	if((C0&&C1&&C2&&C3)==0)
	{
		row_val=2;
		break;
	}
	IOCLR0=R3;
	IOSET0=R1|R2|R0;
	if((C0&&C1&&C2&&C3)==0)
	{
		row_val=3;
		break;
	}
}
if(C0==0)
	col_val=0;
else if(C1==0)
	col_val=1;
else if(C2==0)
	col_val=2;
else
	col_val=3;
		
	delay_milliseconds(700);
	while((C0&&C1&&C2&&C3)==0);
return keypad_lut[row_val][col_val];
}
