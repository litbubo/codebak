#ifndef __IIC_H__
#define __IIC_H__

#define uchar unsigned char
#define uint unsigned int

void IIC_Start();
void IIC_Stop();

void IIC_SendACK(bit ack);
bit IIC_RecvACK();

void IIC_SendByte(uchar dat);
uchar IIC_RecvByte();

void IIC_Write_Data(uchar DevAddress, uchar Address, uchar iic_data);
uchar IIC_Read_Data(uchar DevAddress, uchar Address);

void IIC_Wait_Ack();

#endif