#include"timer_delay.h"
void i2c_eeprom_write(u8 ,u8 ,u8);

void i2c_eeprom_write(u8 slaveAddr,u8 regAddr,u8 ch)
{
	i2c_start();
	i2c_write(slaveAddr<<1);//slaveAddr + w control bit
	i2c_write(regAddr);
	i2c_write(ch);
	i2c_stop();
	delay_milliseconds(10);
}
u8 i2c_eeprom_read(u8 slaveAddr,u8 regAddr)
{
	u8 data;
	i2c_start();
	i2c_write(slaveAddr<<1);//slaveAddr + w control bit
	i2c_write(regAddr);
	i2c_restart();
	i2c_write((slaveAddr<<1)|1);
	data=i2c_nack();
	return data;
}
void i2c_eeprom_page_write(u8 slaveAddr,u8 regAddr,u8 *p,u8 nbytes)
{
	u8 i;
	i2c_start();
	i2c_write(slaveAddr<<1);
	i2c_write(regAddr);
	for(i=0;i<nbytes;i++)
	{
		i2c_write(p[i]);
	}
	i2c_stop();
	delay_milliseconds(10);
}
void i2c_eeprom_sequence_read(u8 slaveAddr,u8 regAddr,u8 *p,u8 nbytes)
{
	u8 i;
	i2c_start();
	i2c_write(slaveAddr<<1);
	i2c_write(regAddr);
	i2c_restart();
	i2c_write(slaveAddr<<1|1);
	for(i=0;i<nbytes-1;i++)
	{
		p[i]=i2c_masterack();
	}
	p[i]=i2c_nack();
	i2c_stop();
}
