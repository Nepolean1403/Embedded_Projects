
f32 read_adc_value(u8 channel_no)
{
	u8 hBytes,lBytes;
	u32 adc_value=0;
	
	spi0(0x06);
	hBytes=spi0(channel_no<<6);
	lBytes=spi0(0x00);
	
	IOSET0=1<<7;
	adc_value=((hBytes&(0x0f)<<8)|(lBytes));
	return ((adc_value*3.3)/4096);
}
