#include<lpc21xx.h>
void UART0_INIT(void);
void UART0_TX(unsigned char);
int main()
{
	UART0_INIT();
	while(1)
		UART0_TX('A');
}
void UART0_INIT(void)
{
	PINSEL0=0X05;
	U0LCR=0X83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0X03;
}
void UART0_TX(unsigned char c)
{
	while((U0LSR>>14&1)==0)
		U0THR=c;
}
