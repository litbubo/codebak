#include "IIC.h"
#include "delay.h"
#include "ADXL345.h"

#define SlaveAddress 0xA6

uchar BUF[8];
uchar ge, shi, bai, qian, wan;
int dis_data;

//连续读出ADXL345内部加速度数据，地址范围0x32~0x37
void Multiple_read_ADXL345(void)
{
    uchar i;
    IIC_Start();                    //起始信号
    IIC_SendByte(SlaveAddress);     //发送设备地址+写信号
    IIC_SendByte(0x32);             //发送存储单元地址，从0x32开始
    IIC_Start();                    //起始信号
    IIC_SendByte(SlaveAddress + 1); //发送设备地址+读信号
    for (i = 0; i < 6; i++)         //连续读取6个地址数据，存储中BUF
    {
        BUF[i] = IIC_RecvByte(); //BUF[0]存储0x32地址中的数据
        if (i == 5)
        {
            IIC_SendACK(1); //最后一个数据需要回NOACK
        }
        else
        {
            IIC_SendACK(0); //回应ACK
        }
    }
    IIC_Stop(); //停止信号
    Delayms(5);
}

void Init_ADXL345()
{
    IIC_Write_Data(SlaveAddress, 0x31, 0x0B); //测量范围,正负16g，13位模式
    IIC_Write_Data(SlaveAddress, 0x2C, 0x08); //速率设定为12.5 参考pdf13页
    IIC_Write_Data(SlaveAddress, 0x2D, 0x08); //选择电源模式   参考pdf24页
    IIC_Write_Data(SlaveAddress, 0x2E, 0x80); //使能 DATA_READY 中断
    IIC_Write_Data(SlaveAddress, 0x1E, 0x00); //X 偏移量 根据测试传感器的状态写入pdf29页
    IIC_Write_Data(SlaveAddress, 0x1F, 0x00); //Y 偏移量 根据测试传感器的状态写入pdf29页
    IIC_Write_Data(SlaveAddress, 0x20, 0x05); //Z 偏移量 根据测试传感器的状态写入pdf29页
}
