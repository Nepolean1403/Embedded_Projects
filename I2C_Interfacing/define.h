#include<lpc21xx.h>

#define aa_bit 2
#define si_bit 3
#define sto_bit 4
#define sta_bit 5
#define i2c_en 6
#define cclk 60000000
#define pclk (cclk/4)
#define speed 100000
#define loadval ((pclk/speed)/2)
#define scl 0x00000010
#define sda 0x00000040
