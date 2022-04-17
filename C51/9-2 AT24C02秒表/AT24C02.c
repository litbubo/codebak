#include <STC89C5xRC.H>
#include "I2C.h"

#define AT24C02_ADDRESS		0xA0

void AT24C02_WriteByte(unsigned char WORDADDRESS, unsigned char Data)
{
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS);
	I2C_RecvAns();
	I2C_SendByte(WORDADDRESS);
	I2C_RecvAns();
	I2C_SendByte(Data);
	I2C_RecvAns();
	I2C_Stop();
}

unsigned char AT24C02_ReadByte(unsigned char WORDADDRESS)
{
	unsigned char Data = 0x00;
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS);
	I2C_RecvAns();
	I2C_SendByte(WORDADDRESS);
	I2C_RecvAns();
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS|0x01);
	I2C_RecvAns();
	Data = I2C_RecvByte();
	I2C_SendAns(1);
	I2C_Stop();
	return Data;
}