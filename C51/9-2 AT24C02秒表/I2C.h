#ifndef __I2C_H__
#define __I2C_H__

void I2C_Start();

void I2C_Stop();

void I2C_SendByte(unsigned char Data);

unsigned char I2C_RecvByte();

void I2C_SendAns(bit answer);

bit I2C_RecvAns();

#endif