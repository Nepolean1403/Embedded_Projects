#include<lpc21xx.h>
void spi_init()
{
	PINSEL0=0x00001500;
	S0SPCCR=150;//PCLK/4
	S0SPCR=mod_0|mstr_bit;
	IODIR0=1<<7;//PO.7 SSEL 
}
u8 spi0(u8 data)
{
	u8 stat;
	stat=S0SPSR;
	S0SPDR=data;
	while(((S0SPSR>>spif_bit)&1)==0);
	return S0SPDR;
}


