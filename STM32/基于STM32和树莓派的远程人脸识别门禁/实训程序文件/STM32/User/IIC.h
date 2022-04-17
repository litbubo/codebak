#ifndef __IIC_H__
#define __IIC_H__
#include "stm32f10x.h"

#define OLED_SCLK_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_5)
#define OLED_SCLK_Set() GPIO_SetBits(GPIOA,GPIO_Pin_5)

#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_6)
#define OLED_SDIN_Set() GPIO_SetBits(GPIOA,GPIO_Pin_6)

void IIC_IO_Init(void);

void IIC_Start(void);
void IIC_Stop(void);

void Write_IIC_Command(unsigned char IIC_Command);
void Write_IIC_Data(unsigned char IIC_Data);
void Write_IIC_Byte(unsigned char IIC_Byte);

void IIC_Wait_Ack(void);

#endif




