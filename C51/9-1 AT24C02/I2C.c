#include <STC89C5xRC.H>

sbit I2C_SDA = P2^0;
sbit I2C_SCL = P2^1;

void I2C_Start()
{
    I2C_SCL = 1;
    I2C_SDA = 1;
    I2C_SDA = 0;
    I2C_SCL = 0;
}

void I2C_Stop()
{
    I2C_SDA = 0;
    I2C_SCL = 1;
    I2C_SDA = 1;
}

void I2C_SendByte(unsigned char Data)
{
    unsigned char i;
    for(i = 0; i < 8; i++)
    {
        I2C_SDA = Data & (0x80>>i);
        I2C_SCL = 1;
        I2C_SCL = 0;
    }
}

unsigned char I2C_RecvByte()
{
    unsigned char i;
    unsigned char Data = 0x00;
    for(i = 0; i < 8; i++)
    {
        I2C_SCL = 1;
        if(I2C_SDA == 1)
            Data |= (0x80>>i);
        I2C_SCL = 0;
    }
    return Data;
}

void I2C_SendAns(bit answer)
{
    I2C_SDA = answer;
    I2C_SCL = 1;
    I2C_SCL = 0;
}

bit I2C_RecvAns()
{
    bit answer;
	I2C_SDA = 1;
    I2C_SCL = 1;
    answer = I2C_SDA;
    I2C_SCL = 0;
    return answer;
}