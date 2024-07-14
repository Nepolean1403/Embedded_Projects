DEFINE BUTTON "SW-DATA-FRAME","SendMessage(1)"
DEFINE BUTTON "SW-REMOTE-FRAME","SendMessage(2)"

func void SendMessage(unsigned char i)
{
	switch(i)
	{
		case 1: 
					CAN2ID=0x001;
					CAN2L =4;
					CAN2B0=0x11;
					CAN2B1=0x22;
					CAN2B2=0x33;
					CAN2B3=0x44;
					CAN2IN=1;//send data frame of 11bit id
					break;
		case 2: 
					CAN2ID=0x002;
					CAN2L =7;
					CAN2IN=3;//send remote frame of 11bit id
					break;
	}
}
