
void i2c_init()
{
	PINSEL0=scl|sda;//pin func p0.2 and  p0.3 
	I2SCLH=loadval;//set speed 
	I2SCLL=loadval;
	I2CONSET=1<<i2c_en;//enable i2c interface
}
void i2c_start()
{
	I2CONSET=1<<sta_bit;
	while(((I2CONSET>>si_bit)&1)==0);
	I2CONCLR=1<<sta_bit;
}
void i2c_restart()
{
	I2CONSET=1<<sta_bit;
	I2CONCLR=1<<si_bit;
	while(((I2CONSET>>si_bit)&1)==0);
	I2CONCLR=1<<sta_bit;
}
void i2c_write(u8 data)
{
	I2DAT=data;
	I2CONCLR=1<<si_bit;
	while(((I2CONSET>>si_bit)&1)==0);
}
void i2c_stop()
{
	I2CONSET=1<<sto_bit;
	I2CONCLR=1<<si_bit;
}
u8 i2c_nack()
{
	I2CONSET=0X00;
	I2CONCLR=1<<si_bit;
	while(((I2CONSET>>si_bit)&1)==0);
	return I2DAT;
}
u8 i2c_masterack()
{
	I2CONSET=1<<aa_bit;
	I2CONCLR=1<<si_bit;
	while(((I2CONSET>>si_bit)&1)==0);
	I2CONCLR=1<<aa_bit;
	return I2DAT;
}
