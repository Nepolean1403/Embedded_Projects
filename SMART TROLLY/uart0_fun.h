#include<lpc21xx.h>
void UART0_INIT(void);
void UART0_TX(unsigned char);
char UART0_RX(void);
void UART0_STR(unsigned char *);
void UART0_INIT(void)
{
	PINSEL0|=0X05;
	U0LCR=0X83; //setting DLAB bit as one
	U0DLL=97;
	//U0DLM=0;
	U0LCR=0X03;// clearing DLAB bit
}
void UART0_TX(unsigned char c)
{
	while(((U0LSR>>5)&1)==0);
	U0THR=c;
}
char UART0_RX(void)
{
	while((U0LSR&1)==0);
	return U0RBR;
}
void UART0_STR(unsigned char *p)
{
	while(*p)
		UART0_TX(*p++);
}
