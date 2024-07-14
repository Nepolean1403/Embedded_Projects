#include<lpc21xx.h>
#define LED 1<<17
#define SW 14
int temp;
void uart_interrupt_isr(void)
{
	temp=U0IIR;
	if(temp==0x02)
		U0THR='A';
	VICVectAddr=0;
}
void UART0_INT_CONFIG(void)
{
	VICIntSelect=0;
	VICVectCntl0=(0x20)|6;
	VICVectAddr0=(int)uart_interrupt_isr;
	U0IER=1<<1;
	VICIntEnable=1<<6;
}
void UART0_INIT(void)
{
	PINSEL0=0X00000005;
	U0LCR=0X83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0X03;
}
int main()
{
	IODIR0=LED;
	UART0_INIT();
	UART0_INT_CONFIG();
	U0THR='A';
	while(1)
	{
		if((IOPIN0>>SW &1)==0)
			IOCLR0=LED;
		else
			IOSET0=LED;
	}
}
