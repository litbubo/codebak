#include <STC89C5xRC.H>

#include "delay.h"
#include "IIC.h"

sbit SCL = P1 ^ 0;
sbit SDA = P1 ^ 1;


//开始信号
void IIC_Start()
{
    SDA = 1;
    SCL = 1; 
    //Delayus(5);
    SDA = 0;
    //Delayus(5);
    SCL = 0;
}



//停止信号
void IIC_Stop()
{
    SDA = 0;
    SCL = 1;
    //Delayus(5);
    SDA = 1;
    //Delayus(5);
}



//发送应答信号
void IIC_SendACK(bit ack)
{
    SDA = ack;
    SCL = 1;
    //Delayus(5);
    SCL = 0;
    //Delayus(5);
}



//接收应答信号
bit IIC_RecvACK()
{
    SCL = 1;
    //Delayus(5);
    CY = SDA;
    SCL = 0;
    //Delayus(5);

    return CY;
}



//向IIC总线发送一个字节数据
void IIC_SendByte(uchar dat)
{
    uchar i;

    for (i = 0; i < 8; i++)
    {
        dat <<= 1;
        SDA = CY;
        SCL = 1;
        //Delayus(5);
        SCL = 0;
        //Delayus(5);
    }
    IIC_RecvACK();
}



//从IIC总线接收一个字节数据
uchar IIC_RecvByte()
{
    uchar i;
    uchar dat = 0;

    SDA = 1; 
    for (i = 0; i < 8; i++)
    {
        dat <<= 1;
        SCL = 1;
        //Delayus(5);
        dat |= SDA;
        SCL = 0;
        //Delayus(5);
    }
    return dat;
}


void IIC_Write_Data(uchar DevAddress, uchar Address, uchar iic_data)
{
    IIC_Start();
    IIC_SendByte(DevAddress);
    IIC_SendByte(Address);  
    IIC_SendByte(iic_data); 
    IIC_Stop();
}


uchar IIC_Read_Data(uchar DevAddress, uchar Address)
{
    uchar iic_data;
    IIC_Start();
    IIC_SendByte(DevAddress); 
    IIC_SendByte(Address);  
    IIC_Start();
    IIC_SendByte(DevAddress + 1);
    iic_data = IIC_RecvByte();
    IIC_SendACK(1);
    IIC_Stop();
    return iic_data;
}

void IIC_Wait_Ack()
{
    SCL = 1;
    SCL = 0;
}
